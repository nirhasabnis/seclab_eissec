
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

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dlfcn.h>
#include <stdlib.h>

#include "measure.h"

unsigned int forkcnt = 0;
unsigned int waitcnt = 0;

pid_t (*forkaddr)(void);
pid_t (*waitaddr)(int*);
pid_t (*waitpidaddr)(pid_t, int*, int);
pid_t (*wait3addr)(int*, int, struct rusage*);
pid_t (*wait4addr)(pid_t, int*, int, struct rusage*);
void (*exitaddr)(int);

//int init(void) __attribute__((constructor));
//int fini(void) __attribute__((destructor));
int proccnt_init(void) __attribute((constructor));
int proccnt_fini(void) __attribute((destructor));


int proccnt_init(void)
{
    fprintf(stderr, "\ninit called");

    void* handle = dlopen("libc.so.6", RTLD_LAZY);
    if (handle == NULL) {
        handle = dlopen("libc.so.6", 0);
        if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(0);
        }
    }

    forkaddr = dlsym(handle, "fork");
    if (!forkaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    waitaddr = dlsym(handle, "wait");
    if (!waitaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    waitpidaddr = dlsym(handle, "waitpid");
    if (!waitpidaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    wait3addr = dlsym(handle, "wait3");
    if (!waitaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    wait4addr = dlsym(handle, "wait4");
    if (!waitaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    exitaddr = dlsym(handle, "exit");
    if (!exitaddr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(0);
    }

    return 0;
}

int fini(void)
{
    fprintf(stderr, "\nfini called");
    fprintf(stderr, "\nfork called: %u times", forkcnt);
    fprintf(stderr, "\nwait called: %u time", waitcnt);
    return 0;
}

measure_t total_proc_time;

pid_t fork(void)
{
    forkcnt++;
    pid_t pid = (forkaddr)();
    if (pid != 0)
        fprintf(stderr, "\nForked: %d", pid);
    else
        start_measurement(START_TIMER_S, &total_proc_time);
    return pid;
}

pid_t wait(int* status)
{
    waitcnt++;
    pid_t pid = (waitaddr)(status);
    fprintf(stderr, "\nWait: %d", pid);
    return pid;
}


pid_t waitpid(pid_t pid, int* status, int options)
{
    waitcnt++;
    pid_t pid1 = (waitpidaddr)(pid, status, options);
    fprintf(stderr, "\nWaitpid: %d", pid1);
    return pid1;
}

pid_t wait3(int* status, int option, struct rusage *rusage)
{
    waitcnt++;
    pid_t pid = (wait3addr)(status, option, rusage);
    fprintf(stderr, "\nWait3: %d", pid);
    return pid;
}

pid_t wait4(pid_t pid, int* status, int option, struct rusage *rusage)
{
    waitcnt++;
    pid_t pid1 = (wait4addr)(pid, status, option, rusage);
    fprintf(stderr, "\nWait4: %d", pid1);
    return pid1;
}

void exit(int status)
{
    log_measurement(end_measurement(&total_proc_time), "[Measurement] Total Proc time");
    (exitaddr)(status);
}
