
/* 
 * EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
 * Generators) is a symbolic execution based system for automatically extracting
 * assembly to IR translators from code generators of modern compilers.
 * 
 * Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
 * Lab, Stony Brook University, Stony Brook, NY 11794.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

#define __USE_GNU
#define _GNU_SOURCE
#include "cons_solve.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

char tpfn[] = "tperfXXXXXX";

int myfork();
int mytry(char buf[], int len, void (*f)(void *a), void *b);
int myfinish(int exitcode);
int do_work();

int local_cs=0; // Set if constraint solver local; 0 if in a separate process
extern int use_clone; // Set to use clone rather than forks within a task
int use_threads=0; // Set to use threads (rather than processes) within a task
int onethread=0; // Set for single threaded execution within task (no fork/clone)

int iter = 5; /* whole cycle is repeated iter times */

int par = 1; /* # of parallel worker processes used per cycle */

unsigned stksize=128; /* in KB, change using -s option */
double heapfac = 1; /* # stksize * heapfac will be heap memory */

int constrsize = 10;  /* size of request sent to constraint solver */

double mean_try_depth = 100; /* exponential distribution with this as mean */
double mean_else_depth = 2;  /* exponential distribution with this as mean */

double tryprob;
/* We decide whether to make a try call based on a random boolean variable 
   that has a value "true" with probability tryprob -- abbreviated t. 
   To compute the prob that a try chain has >= l elems, note that 
   this requires the first l try calls to be made, i.e., the random variable
   should return "true" in the first l attempts. This probability is t^l.
   To find the median value of l, we set t^l = 0.5, i.e., half the try chains
   have a value of l or less. This yields l = log(0.5)/log(t). If you want to
   compute 99-percentile of length, it is given by log(0.01)/log(t).
   
   Mean length is calculated as follows:
      P(l=0):  1-t
      P(l=1):  t(1-t)
      P(l=k):  t^k(1-t)

      mean = (1-t) * sum_{n=1}^infty n*t^(n-1) 
           = [(1-t)/t] * sum_{n=1}^infty n*t^n 
           = [(1-t)/t] * [t/(1-t)^2] = 1/(1-t)

*/

double elseprob;
extern int errno;

int *buf;
unsigned bufsize;
int maxdepth;
int logfd;

extern const char* csolver_cmd;
extern const char* csolver_args[];

struct Stat {
   unsigned short depth;
   unsigned short contrib;
   double tryprob;
   double elseprob;
   struct random_data *rd;
};

int rootpid, errlogfd;

static void errprintf(const char* format, ...) {
   unsigned buflen = 10000;
   char *buf = malloc(buflen);
   int tt = 0; int pid = getpid();
   if (pid != rootpid) {
      sprintf(buf, "%d: ", pid);
      tt = strlen(buf);
   }
   char* buf1 = buf + tt;

   va_list args;
   va_start(args, format);
   vsnprintf(buf1, buflen-tt, format, args);
   va_end(args);

   write(errlogfd, buf, strnlen(buf, buflen));
   free(buf);
}



void prtusage(const char* s) {
  errprintf(
    "Usage: %s [-l] [-f|-t|-1] [-r randomseed] [-p par] [-i iter] [-s stksize]\n"
    "\t[-h heapfac] [-c csize] [-d trydepth] [-e elsedepth] [-m maxdepth]\n", s);
  errprintf("\t -l: Simulate a local solver "
          "(by default, it is in a different process)\n");
  errprintf("\t -f: Use fork instead of clone within try()\n");
  errprintf("\t -t: Use threads instead of clone within try()\n");
  errprintf("\t -1: Use single thread in try() (no fork/thread/clone)\n");
  errprintf("\t -r: Specify seed for random number generator\n");
  errprintf("\t -p: number of parallel top-level tasks\n");
  errprintf("\t -i: number iterations run by each top-level task\n");
  errprintf("\t -s: amount of stack memory (in KB) given to each task\n");
  errprintf("\t -h: make heap size to be heapfac times the size of\n"
          "\t\tstack memory. Note this heap will be COW'd across forks\n");
  errprintf("\t -c: size of constraint sent to solver.\n");
  errprintf("\t -d: mean depth of try chains. Actual depth is a random\n"
          "\t\treal-valued variable following an exponential distribution\n");
  errprintf("\t -e: mean depth of else chains. Exponential distributn\n");
  errprintf("\t -m: max depth, don't use unless it becomes necessary\n");
}

static int mysrandom_r(unsigned int seed, struct random_data *buf) {
   char *b = malloc(256);
   bzero(buf, sizeof(struct random_data));
   return initstate_r(seed, b, 256, buf);
}

static inline int myrandom(struct random_data *rd) {
   int32_t res;
   if (random_r(rd, &res)) {
      perror("random_r"); exit(1);
   }
   return res;
}

struct random_data rdbuf, rdglob;

int main(int argc, char *argv[]) {

   int opt;
   int seed = 0;
   rootpid = getpid();

   mysrandom_r(0, &rdbuf);

   csolver_cmd = "./cons_dummy";
   csolver_args[0] = "cons_dummy";
   use_clone=1;

   errlogfd = 2;//open("/tmp/mytplog", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

   while ((opt = getopt(argc, argv, "p:i:h:c:s:d:e:m:r:lf1t")) != -1) {
      switch (opt) {
      case 'p': par = atoi(optarg); break;
      case 'i': iter = atoi(optarg); break;
      case 's': stksize = atoi(optarg); break;
      case 'h': heapfac = atof(optarg); break;
      case 'c': constrsize = atoi(optarg); break;
      case 'd': mean_try_depth = atof(optarg); break;
      case 'e': mean_else_depth = atof(optarg); break;
      case 'm': maxdepth = atoi(optarg); break;
      case 'r': seed = atoi(optarg); break;
      case 'l': local_cs = 1; break;
      case 'f': use_clone=0; break;
      case '1': onethread=1; break;
      case 't': use_threads=1; break;
      default: prtusage(argv[0]); exit(1);
      }
   }
 
   tryprob = 1.0 - 1.0/mean_try_depth; 
   elseprob = 1.0 - 1.0/mean_else_depth;
   stksize *= 1024;
   bufsize = heapfac * stksize;
   if ((maxdepth == 0) || (maxdepth > (stksize/256)))
      maxdepth=stksize/256;

   buf = (int *)malloc(bufsize);
   for (int i=0; i < bufsize/sizeof(int); i++)
      buf[i] = myrandom(&rdbuf);

   if ((logfd = mkostemp(tpfn, O_EXCL|O_CREAT|O_WRONLY|O_APPEND)) < 0) {
      perror("mkstemp");
      exit(1);
   }

   if (unlink(tpfn) < 0)
      perror("Unable to remove temp file");

   errprintf("Par=%d Loop=%d Heap=%.1fM Stk=%.2fM ReqSize=%d "
           "Try=%g Else=%g maxdepth=%d\n", par, iter, bufsize/(1024*1.024e3), 
           stksize/(1024*1.024e3), constrsize, tryprob, elseprob, maxdepth);

   mysrandom_r(seed, &rdglob);
   errprintf("Seed=%d ", seed);

   errprintf("local solver=%c, ", (local_cs) ? 'y' : 'n');
   if (onethread)
      errprintf("single threaded try\n");
   else errprintf("using %s within try()\n",
                onethread ? "single thread" : 
                (use_threads? "threads" : (use_clone ? "clone" : "fork"))); 

   struct random_data rdtask[par*iter];

   int ntasks = 0;
   int stat, s;

   for (int k=0; k < iter*par; k++) {
      int n = myrandom(&rdglob);
      mysrandom_r(n, &rdtask[k]);
   }

   for (int k=0; k < iter*par;) {
      if (ntasks < par) {
         int pid;
         if ((pid = fork()) == 0)
            exit(do_work(&rdtask[k]));
         else if (pid < 0)
            perror("Fork");
         //errprintf("launched %d\n", pid);
         ntasks++; k++;
      }
      else if ((s = wait(&stat)) >= 0) {
         ntasks--;
         if (!WIFEXITED(stat))
            perror("Wait returned unexpected result");
      }
      else perror("Wait failed unexpectedly, continuing any way");
   }

   while ((s = wait(&stat)) >= 0) {
      ntasks--;
      if (!WIFEXITED(stat))
         perror("Wait returned unexpected result");
   }
   if (errno != ECHILD)
      perror("Wait failed unexpectedly");

   if (ntasks != 0)
      errprintf("%d tasks still running!\n", ntasks);

   unsigned nleaves=0, maxd=0, nprocs=0, sumd=0;
   struct Stat st;

   lseek(logfd, 0, SEEK_SET);
   while (read(logfd, &st, 2*sizeof(short)) == 2*sizeof(short)) {
      nleaves++;
      if ((st.depth > maxdepth) || (st.contrib > maxdepth+1)) {
         errprintf("depth or contrib (%u) > maxdepth in log file\n", 
                 (st.depth > st.contrib) ? st.depth : st.contrib);
         continue;
      }
      //errprintf("depth (%u)\n", depth);
      if (st.depth > maxd)
         maxd = st.depth;
      nprocs += st.contrib;
      sumd += st.depth;
   }

   errprintf("Leaves=%d, Procs=%d, Avg depth=%.1f, Max depth=%d\n", 
           nleaves, nprocs, sumd/(1e-10+nleaves), maxd);

   return 0;
}

void work(struct Stat *st) { // Never returns
   //errprintf("work(%u, %u) called\n", st->depth,st->contrib);
   //fprintf(stderr, "\ndepth: %d, contrib: %d, tryprob: %lf, elseprob: %lf",
   //        st->depth, st->contrib, st->tryprob, st->elseprob);
   if (st->depth < maxdepth) {
      char *b = (char*)buf;
      int r = myrandom(st->rd);
      if ((((double)r)/RAND_MAX) < st->tryprob) {
         st->depth++; st->contrib++;
         //errprintf("work: try succeeded at depth %d\n", st->depth);
         // Modify some random offset in heap memory
         int offset = myrandom(&rdbuf) % (bufsize-constrsize-10);
         for (int i=offset; i < offset+constrsize; i++) {
            int n = myrandom(&rdbuf);
            if (n < 0) 
               b[i] = 'a' + (n % 26);
            else b[i] = 'A' + (n % 26);
         }
         b[offset+constrsize] = '\0';
         //errprintf("trying\n");
#if 0
         struct Stat stat;
         stat.depth = st->depth; stat.contrib = st->contrib; stat.rd = st->rd;
         stat.tryprob = st->tryprob; stat.elseprob = st->elseprob;
         mytry(&b[offset], constrsize, &work, (void *)&stat);
#endif
         mytry(&b[offset], constrsize, &work, (void *)st);
           // Executes work() in a child process if constraint is satisfiable.
           // Parent process will continue below, but the child does not
           // return. Moreover, parent does not resume until child is done. 
           // (This is why it is OK to pass stat, a stack reference, to mytry.)
           // However, if the underlying implementation uses just a single 
           // process, try simply calls work() if the constraint is satisfiable
           // and then control returns here. Thus, in this case, the work of
           // the "child" process is done first, and then "parent" is "resumed."

         if (st->depth < mean_try_depth) {
            srandom_r(r, st->rd);
            r = myrandom(st->rd);
            if ((((double)r)/RAND_MAX) < st->elseprob) {
               //errprintf("work: else succeeds at depth %d\n",st->depth);
               st->contrib = 0;
               st->tryprob = pow((1 - 1.0/mean_try_depth), 
                             mean_try_depth/(double)(mean_try_depth-st->depth));
               st->elseprob = st->elseprob*(1 - 1.0/mean_else_depth);
               work(st);
            }
            //errprintf("work: else failed at depth %d\n", st->depth);
            myfinish(0);
            return;
         }
         myfinish(0);
         return;
      }
      /*else errprintf("work: try failed at depth %d\n", st->depth)*/;
   }

   //errprintf("work(%u, %u) logged\n", st->depth,st->contrib);
   if (write(logfd, st, 2*sizeof(short)) <= 0)
      fatal("Unexpected error while writing results");
   myfinish(0);
   return;
}

int do_work(struct random_data *rd) {
   logcs=0;
   if (!local_cs)
      initSym();

   struct Stat *wstat = (struct Stat*)malloc(sizeof(struct Stat));
   wstat->depth = 0;
   wstat->contrib = 1;
   wstat->tryprob = tryprob;
   wstat->elseprob = elseprob;
   wstat->rd = rd;
   mytry("dc", 2, &work, (void *)wstat);

   int stat; 
   extern int csifd, csofd;

   if (!local_cs) {
      close(csifd);
      close(csofd);
      //errprintf("do_work: going to wait\n");
      // Waiting for constraint solver to return
      int s = wait(&stat);
      if (!WIFEXITED(stat))
         perror("do_work: Wait returned unexpected result");
   }
   return 0;
}

#define STORE_STATE(to_store) do {                    \
   stat_storage.depth = to_store->depth;                   \
   stat_storage.contrib = to_store->contrib;               \
   memcpy(&rd_storage, to_store->rd, sizeof(*to_store->rd));  \
   stat_storage.tryprob = to_store->tryprob;               \
   stat_storage.elseprob = to_store->elseprob;             \
} while(0)

#define RESTORE_STATE(restore_to) do {                      \
   restore_to->depth = stat_storage.depth;                  \
   restore_to->contrib = stat_storage.contrib;              \
   memcpy(restore_to->rd, &rd_storage, sizeof(rd_storage)); \
   restore_to->tryprob = stat_storage.tryprob;              \
   restore_to->elseprob = stat_storage.elseprob;            \
} while(0)

int myClone(void (*f)(void *a), void *b, int *rc, char **stk) {
   if (onethread) {
       struct Stat stat_storage;
       struct random_data rd_storage;
       STORE_STATE(((struct Stat*) b));
       (*f)(b);
       RESTORE_STATE(((struct Stat*) b));
       *rc = 1;

      return *rc;
   }
   else if (use_threads) {
      *stk = malloc(stksize);
      struct Stat stat_storage;
      struct random_data rd_storage;
      STORE_STATE(((struct Stat*) b));
      *rc = clone(f, *stk+stksize-16, 
                  CLONE_IO | CLONE_FS | CLONE_VM | CLONE_FILES | SIGCHLD,
                         b, NULL);
       RESTORE_STATE(((struct Stat*) b));
      return *rc;
   }
   else {
      if ((*rc = myfork()) == 0) {
         (*f)(b);
         exit(0);
      }
      else return *rc;
   }
}

int myfinish(int rc) {
   if (onethread)
      return 1; // We shd probably return 1 to recognize resumption of "parent" 
   else exit(rc);   
}

void myWait(int pid) {
   if (onethread)
      return;

   int stat;
   int pid1 = wait(&stat);
   if (pid1 != pid)
      fatal("Unexpected error in wait");
   if (!WIFEXITED(stat))
      fatal("Unexpected exit by child");
   return;
}

int mySeqfork(void (*f)(void *a), void *b) {
   int pid;
   char *stk=NULL;
   int rc = myClone(f, b, &pid, &stk);
   if (rc > 0) {
      myWait(pid);
      if (stk != NULL) free(stk);
      mylogprintf("%d: pid %d returned\n", getpid(), pid);
      return pid;
   }
   else fatal("Unknown error in mySeqfork");
}

extern int csofd, csifd;

const int CSOLVER_CONST = 10; // Assume solver takes CSOLVER_CONST*buflen time
const int BUFPREP_CONST = 5;  // Assume BUFPREP_CONST*buflen is the time needed
int mytry(char buf[], int buflen, void (*f)(void* a), void* b) {
   int k=BUFPREP_CONST, rv=0;  // to prepare and send constraint to solver.

   //errprintf("mytry called\n");
   if (local_cs) 
      k += CSOLVER_CONST;

   for (int i = 0; i < k; i++) {
      for (int j = 0; j < buflen; j++) {
         rv += buf[j];
         if (i < buflen)
            rv += buf[i];
      }
   }

   if (!local_cs) {
      char rb[16];
      if (write(csofd, buf, buflen) > 0) {
         int n = read(csifd, rb, 15);
         if (n > 0) {
            rb[n] = '\0';
            if (sscanf(rb, "%d", &rv) != 1)
               rv = 0;
         }
         else rv = 0;
      }
      else rv = 0;
   }
   if (rv != 0) 
      return mySeqfork(f, b);
   fatal("Unexpected value of rv in mytry");
   return 0;
}


/*
      int avgd = sumd/nodes;
      errprintf("Child %d[%d]: nodes=%d, maxdepth=%d, avgdepth=%d\n",
              n, i, nodes, maxd, sumd);
      rv += nodes;
   }
   // exit code can be only 8 bits, so take log to fit 32-bit into 8 bits.
   rv = round(7*(log2((double)rv)));
   return rv;

   // Return depth to parent. Need to encode into 8 bits, as that
   if (depth < 128) // is the width that can be passed via exit/wait
      exit(depth);
   else exit(128 | (depth >> shiftamt));
}
*/
