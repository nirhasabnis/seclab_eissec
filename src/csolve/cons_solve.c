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

/* To allow opening more than 2GB log file on 32-bit machine.
 * We want to disable logging eventually. But since we are
 * still in development phase, we want to track errors that
 * we might get in longer runs of our system. This flag
 * must be included before any header files are included.
 */
#define _FILE_OFFSET_BITS 64

#define _GNU_SOURCE

#include "cons_solve.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <strings.h>
#include <errno.h>
#include <string.h>
#include <execinfo.h>
#include <time.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sched.h>
#include <inttypes.h>

#ifdef MEASURE
#include "measure.h"
#endif

int SetupBranchPoint ();
void GotoNextBranchPoint();
void printRetList();

/******************** Printing and logging **********************/

FILE *logcsfp, *csifp, *csofp, *replayfp;
int logcs=0, csifd, csofd, cspid;
log_level_t loglevel = DEBUG;
extern uint64_t bpStackDepth;
/* global buffer which holds location of most recent branch point.
 * In case of parallel exploration of multiple paths, using it is
 * fine if we are using multi-processing. But if we use multi-threading
 * then this needs to be changed. */
char gLoc[128];
const char* csolver_cmd = "./cons_solve";
const char* csolver_args[] = {"cons_solve", NULL};
//const char* logcsf = "/tmp/logcs";
const char* logcsf = "/tmp/logcs";
//const char* logcsf = "/mnt/hgfs/shared/x86/logcs.x86";
//const char* logcsf = "/mnt/hgfs/shared/spim/logcs.spim";
const char* log_replay = NULL;

static char* myprinttime(void) {
   struct timeval tv;
   gettimeofday(&tv, NULL);   
   struct tm* tm = localtime(&tv.tv_sec);
#define SIZE 32
   char buf[SIZE], buf1[2*SIZE];
   memset(buf, 0, SIZE);
   memset(buf1, 0, 2*SIZE);
   strftime(buf, SIZE-1, "%D %T", tm);
   snprintf(buf1, 2*SIZE, "%s.%06lu", buf, tv.tv_usec);
   fprintf(logcsfp, "%s: ", buf1);
}

static void printheader(log_level_t ll)
{
    if (logcs && ll >= loglevel) {
      fprintf(logcsfp, "\n");
      switch(ll) {
          case DEBUG: fprintf(logcsfp, "[DEBUG]\t"); break;
          case INFO: fprintf(logcsfp, "[INFO]\t"); break;
          case WARN: fprintf(logcsfp, "[WARN]\t"); break;
          case ERROR: fprintf(logcsfp, "[ERROR]\t"); break;
      }
#ifndef COMPACT_PRINT_LOGCS
      myprinttime();
#endif
    }
}

/* Most basic print function. */
void mybaseprintf(bool prthdr, log_level_t ll, const char* format, ...) {
   if (logcs && ll >= loglevel) {
      va_list args;
      va_start(args, format);
      if (prthdr) printheader(ll);
      vfprintf(logcsfp, format, args);
      va_end(args);
      fflush(logcsfp);
   }
}

void mybasevprintf(bool prthdr, log_level_t ll, const char* format, 
        va_list args) {
   if (logcs && ll >= loglevel) {
      if (prthdr) printheader(ll);
      vfprintf(logcsfp, format, args);
      fflush(logcsfp);
   }
}

void mywrite(const char* buf, int len) {
   INFO_PRINTF("%s", buf);
   if (log_replay) {
      fprintf(replayfp, "%s\n", buf);
      fflush(replayfp);
   }
   if (write(csofd, buf, len) < len)
      fatal("Error in write() within mywrite");
}

void myprintf(const char* format, ...) {
   va_list args;
   va_start(args, format);
   INFO_VPRINTF_WOHDR(format, args);
   vfprintf(csofp, format, args);
   if (log_replay)
      vfprintf(replayfp, format, args);
   va_end(args);
}

void myputc(char c) {
   INFO_PRINTF_WOHDR("%c", c);
   fputc(c, csofp);
   if (log_replay)
      fputc(c, replayfp);
}

void myflush() {
   if (logcs) { 
      fflush(logcsfp); 
      fflush(csofp);
   } else 
      fflush(csofp);
   if (log_replay) {
      fputc('\n', replayfp); // %%%% Will this extra new line mess up things?
      fflush(replayfp);
   }
}

static void print_backtrace(void) {
   int j, nptrs;
#define BT_SIZE 100
   void *buffer[BT_SIZE];
   char **strings;

   nptrs = backtrace(buffer, BT_SIZE);
   fprintf(stderr, "\nbacktrace() returned %d addresses\n", nptrs);
   ERROR_PRINTF("backtrace() returned %d addresses", nptrs);

   strings = backtrace_symbols(buffer, nptrs);
   if (strings == NULL) {
      perror("backtrace_symbols");
      exit(1);
   }

   for (j = 0; j < nptrs; j++) {
      fprintf(stderr,"%s\n", strings[j]);
      ERROR_PRINTF("%s", strings[j]);
   }
}

void fatal(const char* msg) {
   fprintf(stderr, "Fatal: %d:%s:%d:%s:", getpid(), __FILE__, __LINE__, msg);
   ERROR_PRINTF("Fatal: %d:%s:%d:%s:", getpid(), __FILE__, __LINE__, msg);
   perror("");
   print_backtrace();
   exit(1);
}

void myassert(int test) {
   if(!test) 
      fatal("myassert failed");
}

/******************** Term generation APIs **********************/

Term*
vt(symvar_t v) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->type_ = VAR;
   rv->var_ = v;
   return rv;
}

Term* 
it(int64_t i) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->type_ = ICONST;
   rv->iconst_ = i;
   return rv;
}

Term* 
ct(char c) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->type_ = CCONST;
   rv->cconst_ = c;
   return rv;
}

Term* 
st(const char* s) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->type_ = SCONST;
   rv->sconst_ = s;
   return rv;
}

Term* 
ft(float f) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->type_ = FCONST;
   rv->fconst_ = f;
   return rv;
}

Term* 
xtv(const char* fn, TermList *child) {
   Term *rv = (Term *)malloc(sizeof(Term));
   myassert ((fn != NULL) && ((unsigned)fn > (unsigned)MAX_TTYPE));
   rv->functor_ = fn;
   rv->child_ = child;
   return rv;
}

Term* xtlst1(TermList *elems, TermType listType) {
   Term *rv = (Term *)malloc(sizeof(Term));
   rv->functor_ = (const char*)listType;
   rv->child_ = elems;
   return rv;
}

Term* xtlst(TermList *elems) {
   return xtlst1(elems, LIST);
}

Term* xtlsttl(TermList *elems) {
   return xtlst1(elems, LISTT);
}

Term* xtl(const char* fn, Term* t1, ...) {
   va_list ts;
   Term *t; size_t i;

   va_start(ts, t1);
   for (t = t1, i=0; t != NULL; t = va_arg(ts, Term*), i++);

   TermList *tl = NULL;
   if (i > 0) {
      tl = (TermList *)malloc(sizeof(TermList)+i*sizeof(Term));
      tl->nchild_ = i;

      va_start(ts, t1);
      for (t = t1, i=0; t != NULL; t = va_arg(ts, Term*), i++)
         tl->child_[i] = t;
   }

   return xtv(fn, tl);
}

Term* sett(Term* t1, ...) {
   va_list ts;
   Term *t; size_t i;

   va_start(ts, t1);
   for (t = t1, i=0; t != NULL; t = va_arg(ts, Term*), i++);

   TermList *tl = NULL;
   if (i > 0) {
      tl = (TermList *)malloc(sizeof(TermList)+i*sizeof(Term));
      tl->nchild_ = i;

      va_start(ts, t1);
      for (t = t1, i=0; t != NULL; t = va_arg(ts, Term*), i++)
         tl->child_[i] = t;
   }

   Term *set = (Term *)malloc(sizeof(Term));
   set->type_ = SETT;
   set->child_ = tl;
	 return set;
}

void
printTL0(char lb, char rb, char sep, char lsep, const TermList *tl) {
   int i;
   myputc(lb);
   if (tl != NULL) {
      int nc = tl->nchild_;
      for (i = 0; i < nc; i++) {
         printTerm(tl->child_[i]);
         if (i < nc-2)
            myputc(sep);
         else if (i < nc-1)
            myputc(lsep);
      }
   }
   myputc(rb);
}

void
printTL(char lb, char rb, const TermList *tl) {
   printTL0(lb, rb, ',', ',', tl);
}

void
printSet(const TermList *tl) {
	 printTL0(' ', ' ', ',', ',', tl);
}

void
printTerm(const Term* t) {
   switch (t->type_) {
   case ICONST: myprintf("%" PRId64, t->iconst_); break;
   case CCONST: myprintf("'%c'", t->cconst_); break;
   case SCONST: myprintf("'%s'", t->sconst_); break;
   case FCONST: myprintf("%g", t->fconst_); break;
   case VAR: myprintf("v(%" PRIsymvar_t ")", t->var_); break;
   case LIST: printTL('[', ']', t->child_); break;
   case LISTT: printTL0('[', ']', ',', '|', t->child_); break;
	 case SETT: printSet(t->child_); break;
   default:
      myassert (t->type_ > MAX_TTYPE);
      myprintf("%s", t->functor_);
      if (t->child_ != NULL)
         printTL('(', ')', t->child_); 
      break;
   }
}

inline static void 
freeTerm (Term* t) {
   if (t == NULL) return;
   if (t->type_ == LIST ||
       t->type_ == LISTT ||
       t->type_ > MAX_TTYPE) {
       TermList* tl = t->child_;
       if (tl == NULL) goto out;
       int i = 0;
       for (; i < tl->nchild_; ++i) {
           freeTerm(tl->child_[i]); tl->child_[i] = NULL;
       }
       free(tl); t->child_ = NULL;
   }
out: free(t);
}

/************************ Integer Constraints ******************************/

#define ARG_NONE 0
#define ARG_CONST 1
#define ARG_VAR 2
#define ARG_TERM 3

#define mkArgFlags(r,a1f,a2f) (((a1f)<<4)|((a2f)<<1)|(r))
#define getArgFlag1(x)  ((x)>>4)
#define getArgFlag2(x)  (((x)>>1)&0x7)
#define isReified(x) ((x)&0x1)

Constr* ic1c(symvar_t lhsVar, ConstrOp icop, int64_t rhsConst) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((icop >= ILT) && (icop < ICMAX));
   rv->op_ = NONE;
   rv->cop_ = icop;
   rv->argFlags_ = mkArgFlags(0, ARG_CONST, ARG_NONE);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsConst;
   return rv;
}

Constr* ic1v(symvar_t lhsVar, ConstrOp icop, symvar_t rhsVar) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((icop >= ILT) && (icop < ICMAX));
   rv->op_ = NONE;
   rv->cop_ = icop;
   rv->argFlags_ = mkArgFlags(0, ARG_VAR, ARG_NONE);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar;
   return rv;
}

Constr* ic1r(symvar_t lhsVar, ConstrOp icop, int64_t lwr, int64_t upr) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert (icop == CSEQ_RANGE);
   rv->op_ = NONE;
   rv->cop_ = icop;
   rv->argFlags_ = mkArgFlags(0, ARG_CONST, ARG_CONST);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = lwr;
   rv->rhs_[1] = upr;
   return rv;
}

Constr* ic1s(symvar_t lhsVar, ConstrOp icop, Term* set) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert (icop == CSEQ_SET2 || icop == CSEQ_SET3 || icop == CSEQ_SET4 ||
						 icop == CSEQ_SET5 || icop == CSEQ_SET6 || icop == CSEQ_SET7 || 
						 icop == CSEQ_SET8 || icop == CSEQ_SET9 || icop == CSEQ_SET10 ||
						 icop == CSEQ_SET11 || icop == CSEQ_SET12 || icop == CSEQ_SET13 ||
						 icop == CSEQ_SET14 || icop == CSEQ_SET16);
   rv->op_ = NONE;
   rv->cop_ = icop;
   rv->argFlags_ = mkArgFlags(0, ARG_TERM, ARG_NONE);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = (int64_t) ((uintptr_t) set);
   return rv;
}

Constr* ie1v1c(symvar_t lhsVar, IOp iop, symvar_t rhsVar, int64_t rhsConst) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((iop > NONE) && (iop < MAXIOP));
   rv->op_ = iop;
   rv->cop_ = IEQ;
   rv->argFlags_ = mkArgFlags(0, ARG_VAR, ARG_CONST);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar;
   rv->rhs_[1] = rhsConst;
   return rv;
}

Constr* ie2v(symvar_t lhsVar, IOp iop, symvar_t rhsVar1, symvar_t rhsVar2) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((iop > NONE) && (iop < MAXIOP));
   rv->op_ = iop;
   rv->cop_ = IEQ;
   rv->argFlags_ = mkArgFlags(0, ARG_VAR, ARG_VAR);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar1;
   rv->rhs_[1] = rhsVar2;
   return rv;
}

Constr* tc1t(symvar_t lhsVar, ConstrOp cop, Term* t1) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((cop == CSEQ) || cop == TNE);
   rv->op_ = NONE;
   rv->cop_ = cop;
   rv->argFlags_ = mkArgFlags(0, ARG_TERM, ARG_NONE);
   rv->lhs_ = lhsVar;
   rv->t_[0] = t1;
   return rv;
}


Constr* rc1v1c(symvar_t lhsVar, ConstrOp cop, symvar_t rhsVar, int64_t rhsConst) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert (((cop >= ILT) && (cop < ICMAX)) || (cop == CSEQ));
   rv->op_ = NONE;
   rv->cop_ = cop;
   rv->argFlags_ = mkArgFlags(1, ARG_VAR, ARG_CONST);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar;
   rv->rhs_[1] = rhsConst;
   return rv;
}

Constr* rc2v(symvar_t lhsVar,   ConstrOp cop, symvar_t rhsVar1, symvar_t rhsVar2) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert (((cop >= ILT) && (cop < ICMAX)) || (cop == CSEQ));
   rv->op_ = NONE;
   rv->cop_ = cop;
   rv->argFlags_ = mkArgFlags(1, ARG_VAR, ARG_VAR);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar1;
   rv->rhs_[1] = rhsVar2;
   return rv;
}


Constr* rc1v1t(symvar_t lhsVar, ConstrOp cop, symvar_t rhsVar, Term *t) {
   Constr *rv = (Constr*)malloc(sizeof(Constr));
   myassert ((cop == CSEQ));
   rv->op_ = NONE;
   rv->cop_ = cop;
   rv->argFlags_ = mkArgFlags(1, ARG_VAR, ARG_TERM);
   rv->lhs_ = lhsVar;
   rv->rhs_[0] = rhsVar;
# if __WORDSIZE == 64
   rv->t_[1] = t; // %%%% Assumes t[1] will exactly overlap rhs_[1] 
# else
   rv->t_[2] = t; // %%%% Assumes t[3] does not coincide with rhs_[0]
# endif
   return rv;
}

Constr* orandConstrs(ConstrOp cop, Constr* c1, Constr* c2, ...) {
   va_list cs;
   Constr *c; size_t i;

   myassert(cop == CSOR || cop == CSAND);

   va_start(cs, c2);
   for (c = c2, i=1; c != NULL; c = va_arg(cs, Constr*), i++);

   ConstrList *cl = NULL;
   myassert (i > 0);
   cl = (ConstrList *)malloc(sizeof(ConstrList)+i*sizeof(Constr));
   cl->nconstrs_ = i;

   cl->constrs_[0] = c1;
   va_start(cs, c2);
   for (c = c2, i=1; c != NULL; c = va_arg(cs, Constr*), i++)
     cl->constrs_[i] = c;
   
   c = (Constr *)malloc(sizeof(Constr));
   c->cop_ = cop;
   c->argFlags_ = 0;
   c->clist_ = cl;
   return c;
}

inline static void 
argprt(int64_t arg, int flag) {
   if (flag == ARG_VAR)
      myprintf(", v(%" PRIsymvar_t ")", (symvar_t)arg);
   else if (flag == ARG_CONST)
      myprintf(", %" PRId64, arg);
   else if (flag == ARG_TERM) {
      myprintf(", ");
      printTerm((Term*)arg); /* We know this is truncation, but it
                                will work because t_2[2] coincides
                                with lower 4 bytes of rhs_[1]. */
   }
}

void 
printConstr(const Constr *c) {
   const char* nm;
   myassert(c != NULL);

   if (isReified(c->argFlags_)) {
      fatal("Reified constraints not supported");
      switch (c->cop_) {
      case IEQ: nm = "eqvieq"; break;
      case CSEQ: nm = "eqveq"; break;
      case ILT: nm = "eqvilt"; break;
      case ILE: nm = "eqvile"; break;
      case IGT: nm = "eqvigt"; break;
      case IGE: nm = "eqvige"; break;
      case INE: nm = "eqvine"; break;
      default: myassert (1==0);
      }
   }
   else {
      switch (c->cop_) {
      case IEQ:
         switch (c->op_) {
         case NONE: nm = "eq"; break;
         case UMINUS: fatal("Uminus not supported");
            //nm = "um"; nargs=1; break; 
         case IOP_ABS: fatal("IOP_ABS not supported");
            //ABS: nm = "abs"; nargs=1; break;
         case CSPLUS: nm = "add"; break;
         case CSMINUS: nm = "sub"; break;
         case CSMULT: nm = "mul"; break;
         case CSDIV: nm = "div"; break;
         case CSMOD: //fatal("MOD not supported");
            nm = "mod"; break;
         case CSREM: //fatal("REM not supported");
            nm = "rem"; break;
         case CSMIN: fatal("MIN not supported"); 
            // nm = "min"; break;
         case CSMAX: fatal("MAX not supported");
            // nm = "max"; break;
         case BOR: nm = "bor"; break;
         case BAND: nm = "band"; break;
         case BLSHL: nm = "shl"; break;
         case BLSHR: nm = "shr"; break;
         case EXP: fatal("EXP not supported");
            // nm = "exp"; break;
         default: myassert(1==0);
         }
         break;
      
      case CSEQ: nm = "eq"; break;
      case CSEQ_RANGE: nm = "eq_range"; break;
      case CSEQ_SET2: nm = "eq_set2"; break;
      case CSEQ_SET3: nm = "eq_set3"; break;
      case CSEQ_SET4: nm = "eq_set4"; break;
      case CSEQ_SET5: nm = "eq_set5"; break;
      case CSEQ_SET6: nm = "eq_set6"; break;
      case CSEQ_SET7: nm = "eq_set7"; break;
      case CSEQ_SET8: nm = "eq_set8"; break;
      case CSEQ_SET9: nm = "eq_set9"; break;
      case CSEQ_SET10: nm = "eq_set10"; break;
      case CSEQ_SET11: nm = "eq_set11"; break;
      case CSEQ_SET12: nm = "eq_set12"; break;
      case CSEQ_SET13: nm = "eq_set13"; break;
      case CSEQ_SET14: nm = "eq_set14"; break;
      case CSEQ_SET16: nm = "eq_set16"; break;
      case CSOR: nm = "csor"; break;
      case CSAND: nm = "csand"; break;
      case ILT: nm = "ilt"; break;
      case ILE: nm = "ile"; break;
      case IGT: nm = "igt"; break;
      case IGE: nm = "ige"; break;
      case INE: nm = "ine"; break;
      case TNE: nm = "tne"; break;
      default: myassert (1==0);
      }
   }
   if (c->cop_ == CSOR || c->cop_ == CSAND) {
      myprintf("%s(", nm);
      int i = 0;
      while(i < c->clist_->nconstrs_) {
         myputc('(');
         printConstr(c->clist_->constrs_[i]);
         myputc(')');
         if (i != c->clist_->nconstrs_-1)
          myputc(',');
          ++i;
      }
      myputc(')');
   } else {
      myprintf("%s(v(%" PRIsymvar_t ")", nm, c->lhs_); 
      argprt(c->rhs_[0], getArgFlag1(c->argFlags_));
      argprt(c->rhs_[1], getArgFlag2(c->argFlags_));
      myputc(')'); 
   }
}

inline static void freeConstr(Constr* c)
{
    if (c == NULL) return;
    if (getArgFlag1(c->argFlags_) == ARG_TERM) {
        freeTerm(c->t_[0]); c->t_[0] = NULL;
    }
    if (getArgFlag2(c->argFlags_) == ARG_TERM) {
# if __WORDSIZE == 64
        freeTerm(c->t_[1]); c->t_[1] = NULL;
# else        
        freeTerm(c->t_[2]); c->t_[2] = NULL;
# endif
    }
    if (c->cop_ == CSOR) {
      int i = 0;
      for(; i < c->clist_->nconstrs_; i++)
        free(c->clist_->constrs_[i]);
    }
    free(c);
}

#ifdef MEASURE
/************************ Measurement related operations *********************/

#define MEASURE_TOTAL_TIME (unsigned) 1
measure_t* total_time = 0;
measure_t* total_time1 = 0;

#define MEASURE_TOTAL_BPS (unsigned) (1<<1)
measure_t* total_bps = 0;

#define MEASURE_NUM_CONS (unsigned) (1<<3)
measure_t* num_cons = 0;

#define MEASURE_NUM_PATHS (unsigned) (1<<4)
measure_t* num_paths = 0;

#define MEASURE_CONS_ADDITION_TIME (unsigned) (1<<5)
// cons_addition_time need not be accessible across
// processes. It is only measuring time for adding
// a constraint in the system for one process.
//measure_t* cons_addition_time = 0;

#define MEASURE_TRY_TIME (unsigned) (1<<6)
// For measure_t, same comment as above

#define MEASURE_DUMPALL_TIME (unsigned) (1<<7)
#define MEASURE_SEQFORK_TIME (unsigned) (1<<8)
#define MEASURE_FORK_TIME (unsigned) (1<<9)
#define MEASURE_TOTAL_PATHS_W_OP (unsigned) (1<<10)
measure_t* total_paths_w_op = 0;

#define MEASURE_TOTAL_MEMORY ((unsigned) (1<<11))
measure_t* total_memory = 0;

#define MEASURE_TOTAL_DISTINCT_RETS ((unsigned) (1<<12))
measure_t* distinct_rets = 0;

unsigned int* active_procs = 0;

unsigned measure_what = (MEASURE_TOTAL_TIME |
                         MEASURE_TOTAL_BPS | 
												 MEASURE_TOTAL_PATHS_W_OP |
                         MEASURE_NUM_PATHS |
                         MEASURE_NUM_CONS  |
												 MEASURE_TOTAL_MEMORY |
												 MEASURE_TOTAL_DISTINCT_RETS
                         );

static void init_measurements()
{
    measure_t* addr = (measure_t*) mmap(NULL, 4096, PROT_READ | PROT_WRITE, 
            MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    if (addr == MAP_FAILED)
        fatal("mmap failed: ");

    total_time = &addr[0];
    total_time = start_measurement(START_TIMER_SC, total_time);

    total_bps = &addr[1];
    total_bps = start_measurement(START_COUNTER, total_bps);

    num_cons = &addr[2];
    num_cons = start_measurement(START_COUNTER, num_cons);

    num_paths = &addr[3];
    num_paths = start_measurement(START_COUNTER, num_paths);

    active_procs = (unsigned int*) &addr[4];

    total_time1 = &addr[5];
    total_time1 = start_measurement(START_TIMER_S, total_time1);

    total_paths_w_op = &addr[6];
    total_paths_w_op = start_measurement(START_COUNTER, total_paths_w_op);

    total_memory = &addr[7];
    total_memory = start_measurement(START_MEMORY_SC, total_memory);
    //cons_addition_time = &addr[3];

	  distinct_rets = &addr[8];
	  distinct_rets = start_measurement(START_COUNTER, distinct_rets);
}

void print_measurements()
{
    if (measure_what & MEASURE_TOTAL_TIME)
        log_measurement(end_measurement(total_time1),
                "[Measurement] Total execution time");
    if (measure_what & MEASURE_TOTAL_BPS)
        log_measurement(end_measurement(total_bps), 
                "[Measurement] Total num of branch points: ");
    if (measure_what & MEASURE_NUM_PATHS)
        log_measurement(end_measurement(num_paths), 
                "[Measurement] Total num of paths: ");
    if (measure_what & MEASURE_TOTAL_PATHS_W_OP)
        log_measurement(end_measurement(total_paths_w_op), 
                "[Measurement] Num of paths with output (not failed): ");
    if (measure_what & MEASURE_NUM_CONS)
        log_measurement(end_measurement(num_cons), 
                "[Measurement] Num of constraints: ");
		if (measure_what & MEASURE_TOTAL_MEMORY)
        log_measurement(end_measurement(total_memory), 
                "[Measurement] Amount of memory: ");
	  if (measure_what & MEASURE_TOTAL_DISTINCT_RETS) {
			  log_measurement(end_measurement(distinct_rets), "[Measurement] Total distinct rets: ");
				printRetList();
		}
		ERROR_PRINTF("[Measurement] BP stack depth: %llu\n", bpStackDepth);
}
#endif

/************************ Top-level operations *******************************/

int myrrv;

static int read_rc2(char *s, const char fmtflag, const char *f, int l, int ack) {
   int rc;
  if (fmtflag == 's') {
      rc = fscanf(csifp, "%s", s);
   	if (log_replay) {
    	fprintf(replayfp, "replay_read_string %s\n", s);
			fflush(replayfp);	
   	} 
	} 
	else if (fmtflag == 'l') {
    rc = fscanf(csifp, " %[^\n]", s);
    if (log_replay) {
    	fprintf(replayfp, "replay_read_line %s\n", s);
			fflush(replayfp);
		}
  }

	/* Not sure about this change. If things are unstable, then comment it out. */
	/** */
	if (log_replay) {
		if (rc == 1)
			fprintf(replayfp, "%s\n", s);
		else fprintf(replayfp, "error\n");
		fflush(replayfp);
	}
	/** */

  if (ack)
    mywrite("c. ", 3);

  if (rc == 1) {
    INFO_PRINTF("%d:%s:%d: READ: \"%s\"\n", getpid(), f, l, s);
  }
  else { 
  	if (logcs) { 
    	if (ferror(csifp))
      	ERROR_PRINTF("%d:%s:%d: READ error: return value=%d,"
          "error string=%s\n", getpid(), f, l, rc, strerror(errno));
      else if (rc == EOF)
      	ERROR_PRINTF("%d:%s:%d: READ: EOF reached\n", 
          getpid(), f, l, rc);
     	else
      	ERROR_PRINTF("%d:%s:%d: READ error: return value=%d\n", 
        	getpid(), f, l, rc);
      }
  }
  return rc;
}

int read_rc1(char *s, const char *f, int l, int ack) {
   int rv = read_rc2(s, 's', f, l, ack);
   return rv;
}

int read_rcln1(char *s, const char *f, int l, int ack) {
   int rv = read_rc2(s, 'l', f, l, ack);
   return rv;
}

int read_rc(char *s, const char *f, int l) {
   int rv = read_rc1(s, f, l, 1);
   return rv;
}

int read_rcln(char *s, const char *f, int l) {
   int rv = read_rcln1(s, f, l, 0);
   return rv;
}

void
initSym1(int flag) {
   int pipe1[2], pipe2[2];

#ifdef MEASURE
   init_measurements();
#endif

   if ((pipe(pipe1) < 0) || (pipe(pipe2) < 0))
      fatal("pipe");
   else if ((cspid=fork()) < 0)
      fatal("fork");
   else if(cspid==0) {
      close(pipe1[1]);
      close(pipe2[0]);
      if ((dup2(pipe2[1],1) < 0) || (dup2(pipe1[0],0) < 0))
         fatal("Child: dup2");
      else if (execvp(csolver_cmd, (char* const*) csolver_args) < 0)
         fatal("Child: execve");
   }
   else { /* Parent */
      close(pipe1[0]);
      close(pipe2[1]);
      csifd = pipe2[0];
      if ((csifp=fdopen(csifd, "r")) == NULL)
         fatal("fdopen");
      csofd = pipe1[1];
      if ((csofp=fdopen(csofd, "a")) == NULL)
         fatal("fdopen");
      if (logcsf != NULL && logcs) {
         char buf[256];
				 memset(buf, 0, 256);
         snprintf(buf, 128, "%s.%u", logcsf, getpid());
         unlink(logcsf);
         int ret = symlink(buf, logcsf);
         //snprintf(buf, 128, "%s", logcsf);
         if ((logcsfp = fopen(buf, "w")) == NULL)
            perror("Unable to open log file");
      }
      if (log_replay != NULL) {
         char buf1[256];
				 memset(buf1, 0, 256);
         snprintf(buf1, 128, "%s.%u", log_replay, getpid());
         if ((replayfp = fopen(buf1, "w")) == NULL)
            fatal("Unable to create replay file");
      }
      //char buf[10000]; int n;
      //myread(buf, sizeof(buf), n);
      //if (n <= 0) fatal("Unexpected error reading from constraint solver");
      if (flag) {
        INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
        myprintf("mystart. ");
      }
   }
}

void
initSym() {
   initSym1(1);
}

void begin() {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
   myprintf("begin. ");
   myflush();
   return;
}

	typedef struct {
		int64_t v_;
		int64_t c_;
	} rec_t;

rec_t list[100];
size_t idx = 0;

void printRetList() {
	size_t i = 0;
	char buf[512]; memset(buf, 0, 512);
	char* p = buf;
	sprintf(buf, "%s", "[");
	p = buf+strlen(buf);
	for(i = 0; i < idx; i++) {
		sprintf(p, "(%llu, %llu),", list[i].v_, list[i].c_);
		p = buf+strlen(buf);
	}
	sprintf(p, "%s", "]");
	ERROR_PRINTF("[Measurement] Ret classification: %s", buf);
}

static bool isInList(int64_t val) {
	size_t i = 0;
	myassert(idx < 100);

	for(i = 0; i < idx; i++) 
		if (list[i].v_ == val) {
			list[i].c_++;
			return true;
		}

	list[idx].v_ = val;
	list[idx].c_ = 1;
	idx++;
	return false;
}

void addOutput(Term* t) {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
   myprintf("addo(");
   //myassert((t->type_ == VAR) || (t->type_ == SCONST) || (t->type_ == ICONST));
	 myassert(t->type_  >= ICONST && t->type_ < MAX_TTYPE);
   printTerm(t);
   myprintf("). ");
   myflush();

	 if(t->type_ == ICONST && !isInList(t->iconst_))
		distinct_rets = update_measurement(distinct_rets, 1);
			 
   freeTerm(t);
}

void gotoNextBranchPointHook() {
#ifdef MEASURE
   if (measure_what & MEASURE_NUM_PATHS)
       num_paths = update_measurement(num_paths, 1);
#endif
   GotoNextBranchPoint();
}

void backTrack() {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
   static uint64_t pathno = 0;
   myprintf("storeres("); printTerm(it(pathno++)); myprintf("). ");
   myflush();
#ifdef MEASURE
   if (measure_what & MEASURE_TOTAL_PATHS_W_OP)
       total_paths_w_op = update_measurement(total_paths_w_op, 1);
#endif
	 GOTO_NEXT_BRANCH_IN_USER;
}

void fail() {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);	 
   myprintf("fail. ");
   myflush();
	 GOTO_NEXT_BRANCH_IN_USER;
}

void failres() {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
	 myprintf("failres. ");
   myflush();
	 GOTO_NEXT_BRANCH_IN_USER;
}

void addCons(Constr* c) { 
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
#ifdef MEASURE
   measure_t cons_addition_time;
   if (measure_what & MEASURE_NUM_CONS)
       num_cons = update_measurement(num_cons, 1);
   if (measure_what & MEASURE_CONS_ADDITION_TIME)
       start_measurement(START_TIMER_S, &cons_addition_time);
#endif

   myprintf("add(");
   printConstr(c);
   myprintf("). ");
   myflush();

#ifdef MEASURE
   if (measure_what & MEASURE_CONS_ADDITION_TIME)
      log_measurement(end_measurement(&cons_addition_time), 
                      "[Measurement]: AddCons time");
#endif
   freeConstr(c);
}

int markConsVar(symvar_t var) {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
   myprintf("markconsvar(");
   Term* t = vt(var);
   printTerm(t);
   myprintf("). ");
   myflush();
   freeTerm(t);
   return 0;   
}

int64_t doAll() {
   char b[100]; int n; int64_t v;
   int pid, pid1, stat;
   while (1) {
      //mylogprintf("getnext waiting for solver to return an answer\n");
      n = read_rc(b, __FILE__, __LINE__);
      //mylogprintf("getnext: solver returned an answer\n");
      if (n <= 0) fatal("Unexpected error reading from constraint solver");
      if (sscanf(b, "%" PRId64, &v) == 1) {
         if (seqFork() == 0)
            return v;
      }
      else if ((index(b, 'f') != NULL) || (index(b, 'F') != NULL)) {
				GOTO_NEXT_BRANCH_IN_USER;
      }
      else fatal("Unexpected data read from constraint solver");
   }
}

int64_t getNext(symvar_t var) {
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);
   myprintf("getnext(");
   Term* t = vt(var);
   printTerm(t);
   myprintf("). ");
   myflush();
   freeTerm(t);
   return doAll();
}

void mywait(int pid) {
   int stat;
   int pid1 = wait(&stat);
   if (pid1 != pid)
      fatal("Unexpected error in wait");
   if (!WIFEXITED(stat))
      fatal("Unexpected exit by child");
}

int use_clone = 0;
int myfork() {
  /* fork() leads to invocation of clone() as:
   *
   * clone(child_stack=0, flags=CLONE_CHILD_CLEARTID|CLONE_CHILD_SETTID|SIGCHLD,
   * child_tidptr=0xb75af968)
   *
   * pthread_create() leads to invocation of clone as
   * clone(child_stack=0xb755a464,
   * flags=CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD | 
   * CLONE_SYSVSEM | CLONE_SETTLS | CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, 
   * parent_tidptr=0xb755aba8, {entry_number:6, base_addr:0xb755ab40,
   * limit:1048575, seg_32bit:1, contents:0, read_exec_only:0, limit_in_pages:1,
   * seg_not_present:0, useable:1}, 
   * child_tidptr=0xb755aba8)
   *
   * The flags and parameters below are chosen from the above 2 invocations
   * and man page of clone.
   */
   if (!use_clone)
      return fork();
   else // Macro measurements don't seem to show any difference due to
        // the use of different flags, or for that matter, on fork vs clone
      return syscall(SYS_clone, /*CLONE_CHILD_CLEARTID | */
                             CLONE_FS |
                             CLONE_FILES | CLONE_IO |
                     /*CLONE_SYSVSEM | */
                             SIGCHLD, 
                             /* child_stack = 0 to allow COW */
                             0, 
                             /* parent tid, 0 as it is useful
                              * for pthread_create and not for
                              * fork()
                              */
                             0, 
                             /* child tid, 0 as we dont need to
                              * save it. glibc, however, saves it.
                              * man page says it is for caching of
                              * tid. */
                     0);
}

int seqFork() {
   int pid;
   myflush();
#ifdef MEASURE
   measure_t fork_time;
   if (measure_what & MEASURE_FORK_TIME)
      start_measurement(START_TIMER_S, &fork_time);
#endif
#ifndef USE_OBJCOW
   if ((pid = myfork()) == 0)
      return pid;
   else if (pid > 0) {
#else
   if (SetupBranchPoint() == 0)
       return 0;
   else {
#endif
#ifdef MEASURE
      if (measure_what & MEASURE_FORK_TIME)
         log_measurement(end_measurement(&fork_time), "[Measurement] Fork time");
      measure_t seqfork_time;
      if (measure_what & MEASURE_SEQFORK_TIME)
         start_measurement(START_TIMER_SC, &seqfork_time);
#endif
#ifndef USE_OBJCOW
      INFO_PRINTF("%d: pid %d spawned\n", getpid(), pid);
      mywait(pid);
      INFO_PRINTF("%d: pid %d returned\n", getpid(), pid);
#else
      DEBUG_PRINTF("Returned from branchpoint");
#endif
#ifdef MEASURE
      if (measure_what & MEASURE_SEQFORK_TIME)
         log_measurement(end_measurement(&seqfork_time), 
              /*"[Measurement] Parent(%d) measuring Seqfork time of child(%d)", 
              getpid(), pid);*/
              "[Measurement] Seqfork time");
#endif
#ifndef USE_OBJCOW
      return pid;
#else
      return 3;
#endif
   }
#ifndef USE_OBJCOW
   else fatal("Unknown error in fork");
#endif
}   

static int try(Constr* c, bool tryboth) {
   char b[1000]; int n, v, pid;
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);

#ifdef MEASURE
   measure_t try_time;
   if (measure_what & MEASURE_NUM_CONS)
      num_cons = update_measurement(num_cons, 1);
   if (measure_what & MEASURE_TRY_TIME)
      start_measurement(START_TIMER_S, &try_time);
#endif

   if (tryboth)
      myprintf("tryboth(");
   else myprintf("tryone(");
   printConstr(c);
   myprintf("). ");
   myflush();

   n = read_rc(b, __FILE__, __LINE__);
#ifdef MEASURE
   if (measure_what & MEASURE_TRY_TIME)
      log_measurement(end_measurement(&try_time), 
               "[Measurement]: Try time");
#endif
   freeConstr(c);

   if (n <= 0) fatal("Unexpected error reading from constraint solver");
   if (sscanf(b, "%d", &v) == 1)
      if (tryboth) {
#ifdef MEASURE
            if (measure_what & MEASURE_TOTAL_BPS) {
              update_measurement(total_bps, 1);
              if (total_bps->data_.counter_ % 500000 == 0)
                print_measurements();
             }
#endif
         return seqFork();
       }
      else return 0;
   else if ((index(b, 'f') != NULL) || (index(b, 'F') != NULL)) 
      return 1; // Unsatisfiable constraint
   else {
      char d[1500];
      memset(d, 0, 1500);
      snprintf(d, 1500, "Unexpected data read from constraint solver: %s", b);
      fatal(d);
   }
}

int tryboth(Constr* c) {
   return try(c, 1);
}

int tryone(Constr* c) {
   return try(c, 0);
}

static char buf[1000000]; 
void finish() {
   int n; int pid, stat;
   INFO_PRINTF("%d:%s:%d:", getpid(), __FILE__, __LINE__);

#ifdef MEASURE
   measure_t dumpall_time;
   if (measure_what & MEASURE_DUMPALL_TIME)
       start_measurement(START_TIMER_S, &dumpall_time);
#endif

   myprintf("dumpall. ");
   myflush();
   fclose(csofp);
   while (read_rcln(buf, __FILE__, __LINE__) == 1);

#ifdef MEASURE
   struct rusage ru;
   pid = wait4(cspid, &stat, 0, &ru);
   INFO_PRINTF("%d: constraint Solver [Measurements]: User: %lu.%06lu "
               "Sys: %lu.%06lu\n", getpid(), 
               ru.ru_utime.tv_sec, ru.ru_utime.tv_usec, 
               ru.ru_stime.tv_sec, ru.ru_stime.tv_usec);

   while (read_rcln(buf, __FILE__, __LINE__) == 1);

   if (measure_what & MEASURE_DUMPALL_TIME)
      log_measurement(end_measurement(&dumpall_time), 
                      "[Measurement]: Dumpall time");

   print_measurements();
#else
   pid = wait(&stat);
#endif

   if (pid != cspid)
      fatal("Unexpected process returned");
   if (!WIFEXITED(stat))
      fatal("Unexpected exit by child");
}

