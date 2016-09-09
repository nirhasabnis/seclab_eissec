
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
#include <sys/time.h>
#include <sys/resource.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>

#include "measure.h"
#include "cons_solve.h"

extern FILE* logcsfp;

#define UNREACHABLE_CODE (assert(0))

static void subtract_ru (struct rusage* start, struct rusage* end, 
                    struct rusage* res)
{
    assert(start != NULL && end != NULL && res != NULL);
    timersub(&end->ru_utime, &start->ru_utime, &res->ru_utime);
    timersub(&end->ru_stime, &start->ru_stime, &res->ru_stime);
}

static void  subtract_ts (struct  timespec*  time1,
        struct  timespec*  time2,
        struct timespec* result)
{
/* Subtract the second time from the first. */
    if ((time1->tv_sec < time2->tv_sec) ||
        ((time1->tv_sec == time2->tv_sec) &&
         (time1->tv_nsec <= time2->tv_nsec))) {		/* TIME1 <= TIME2? */
        result->tv_sec = result->tv_nsec = 0 ;
    } else {						/* TIME1 > TIME2 */
        result->tv_sec = time1->tv_sec - time2->tv_sec ;
        if (time1->tv_nsec < time2->tv_nsec) {
            result->tv_nsec = time1->tv_nsec + 1000000000L - time2->tv_nsec ;
            result->tv_sec-- ;				/* Borrow a second. */
        } else {
            result->tv_nsec = time1->tv_nsec - time2->tv_nsec ;
        }
    }
}

measure_t* start_measurement (measure_event_t me, measure_t* nm)
{
    assert(nm != NULL);
    switch (me)
    {
        case START_COUNTER: 
            nm->tag_ = M_CNT; nm->data_.counter_ = 0;
            break;
        case START_TIMER_SC:
            {
                nm->tag_ = M_TIME_SC; 
                int ret = getrusage(RUSAGE_SELF, &nm->data_.time_.sru_);
                if (ret != 0)
                    fatal("Error in getrusage:");
                ret = getrusage(RUSAGE_CHILDREN, &nm->data_.time_.cru_);
                if (ret != 0)
                    fatal("Error in getrusage:");
            }
            break;
        case START_MEMORY_SC:
            {
                nm->tag_ = M_MEMORY_SC; 
                int ret = getrusage(RUSAGE_SELF, &nm->data_.memory_.sru_);
                if (ret != 0)
                    fatal("Error in getrusage:");
                ret = getrusage(RUSAGE_CHILDREN, &nm->data_.memory_.cru_);
                if (ret != 0)
                    fatal("Error in getrusage:");
            }
						break;
        case START_TIMER_S:
            {
                nm->tag_ = M_TIME_S; 
                /*
                int ret = getrusage(RUSAGE_SELF, &nm->data_.time_.sru_);
                if (ret != 0)
                    fatal("Error in getrusage:");
                */
                int ret = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &nm->data_.time_.ts1_);
                if (ret != 0)
                    fatal("Error in clock_gettime");
            }
            break;
        default:
            UNREACHABLE_CODE;
    }
    return nm;
}

measure_t* update_measurement (measure_t* m, int offset)
{
    assert (m != NULL && m->tag_ == M_CNT);
    m->data_.counter_ += offset;
    return m;
}

measure_t* end_measurement (measure_t* sm)
{
    assert(sm != NULL);
    switch (sm->tag_)
    {
        case M_CNT:
            return sm;
        case M_TIME_SC:
          {
            //struct timeval tv;
            //int ret = gettimeofday(&tv, NULL);

            struct rusage sru, cru;
            int ret = getrusage(RUSAGE_SELF, &sru);
            if (ret != 0)
                fatal("Error in getrusage:");
            ret = getrusage(RUSAGE_CHILDREN, &cru);
            if (ret != 0)
                fatal("Error in getrusage:");

            subtract_ru(&sm->data_.time_.sru_, &sru, &sm->data_.time_.sru_);
            subtract_ru(&sm->data_.time_.cru_, &cru, &sm->data_.time_.cru_);

            //subtract_tv (&sm->data_.time_.tv_, &tv, &sm->data_.time_.tv_);
            return sm;
          }
        case M_TIME_S:
          {
            struct timespec ts;
            int ret = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &sm->data_.time_.ts2_);
            if (ret != 0)
                fatal("Error in clock_gettime");

            /*
            struct rusage sru;
            int ret = getrusage(RUSAGE_SELF, &sru);
            if (ret != 0)
                fatal("Error in getrusage:");
            */

            //subtract_ru(&sm->data_.time_.sru_, &sru, &sm->data_.time_.sru_);
            return sm;
          }
        case M_MEMORY_SC:
          {
            struct rusage sru, cru;
            int ret = getrusage(RUSAGE_SELF, &sru);
            if (ret != 0)
                fatal("Error in getrusage:");
            ret = getrusage(RUSAGE_CHILDREN, &cru);
            if (ret != 0)
                fatal("Error in getrusage:");

						sm->data_.memory_.sru_.ru_maxrss = sru.ru_maxrss -
																		sm->data_.memory_.sru_.ru_maxrss;
						sm->data_.memory_.sru_.ru_ixrss = sru.ru_ixrss -
																		sm->data_.memory_.sru_.ru_ixrss;
						sm->data_.memory_.sru_.ru_idrss = sru.ru_idrss -
																		sm->data_.memory_.sru_.ru_idrss;
						sm->data_.memory_.sru_.ru_isrss = sru.ru_isrss -
																		sm->data_.memory_.sru_.ru_isrss;
						
						sm->data_.memory_.cru_.ru_maxrss = sru.ru_maxrss -
																		sm->data_.memory_.cru_.ru_maxrss;
						sm->data_.memory_.cru_.ru_ixrss = sru.ru_ixrss -
																		sm->data_.memory_.cru_.ru_ixrss;
						sm->data_.memory_.cru_.ru_idrss = sru.ru_idrss -
																		sm->data_.memory_.cru_.ru_idrss;
						sm->data_.memory_.cru_.ru_isrss = sru.ru_isrss -
																		sm->data_.memory_.cru_.ru_isrss;

            return sm;
          }
        default:
            UNREACHABLE_CODE;
    }
}

void log_measurement (measure_t* m, const char* format, ...)
{
    assert(m != NULL);
    char buf1[1024], buf2[1024];
    memset(buf1, 0, 1024);
    memset(buf2, 0, 1024);
    switch (m->tag_)
    {
        case M_CNT:
            sprintf(buf1, "%llu", m->data_.counter_);
            break;
        case M_TIME_SC:
            {
                struct timeval self_tv, children_tv;
                timeradd(&m->data_.time_.sru_.ru_utime, &m->data_.time_.sru_.ru_stime, &self_tv);
                timeradd(&m->data_.time_.cru_.ru_utime, &m->data_.time_.cru_.ru_stime, &children_tv);
                sprintf(buf1, "%d: self: %lu.%06lus, children: %lu.%06lus ", 
                             getpid(),
                             self_tv.tv_sec, self_tv.tv_usec,
                             children_tv.tv_sec, children_tv.tv_usec);
            }
            break;
        case M_TIME_S:
            {
                /*struct timeval self_tv;
                timeradd (&m->data_.time_.sru_.ru_utime, &m->data_.time_.sru_.ru_stime, &self_tv);
                INFO_PRINTF("%d: self: %lu.%06lus ", getpid(), self_tv.tv_sec, self_tv.tv_usec);
                */
                struct timespec ts;
                subtract_ts(&m->data_.time_.ts2_, &m->data_.time_.ts1_, &ts);
                sprintf(buf1, "%d: self: %lu.%09lus - %lu.%09lus = %lu.%09lus", getpid(), 
                        m->data_.time_.ts2_.tv_sec, m->data_.time_.ts2_.tv_nsec, 
                        m->data_.time_.ts1_.tv_sec, m->data_.time_.ts1_.tv_nsec,
                        ts.tv_sec, ts.tv_nsec);

            }
            break;
				case M_MEMORY_SC:
						{
							/*sprintf(buf1, "%d: self: maxrss: %ld, ixrss: %ld, idrss: %ld, isrss: %ld,  child: maxrss: %ld, ixrss: %ld, idrss: %ld, isrss: %ld", getpid(),
							m->data_.memory_.sru_.ru_maxrss, m->data_.memory_.sru_.ru_ixrss,
							m->data_.memory_.sru_.ru_idrss, m->data_.memory_.sru_.ru_isrss, 
							m->data_.memory_.cru_.ru_maxrss, m->data_.memory_.cru_.ru_ixrss,
							m->data_.memory_.cru_.ru_idrss, m->data_.memory_.cru_.ru_isrss);
*/
							long cs_rss = 0, self_rss = 0;
							FILE* fp = NULL;
							char fpath[32]; 

							memset(fpath, 0, 32);
							sprintf(fpath, "/proc/%d/statm", cspid);
							if ((fp = fopen(fpath, "r")) != NULL)
								fscanf(fp, "%*s%ld", &cs_rss);
							fclose(fp);

							memset(fpath, 0, 32);
							sprintf(fpath, "/proc/self/statm");
							if ((fp = fopen(fpath, "r")) != NULL)
								fscanf(fp, "%*s%ld", &self_rss);
							fclose(fp);

							sprintf(buf1, "self: %u KB, %.2lf MB; csolve: %u KB, %.2lf MB", 
														(size_t) self_rss * 4, 
														((float) self_rss * 4) / (float) 1024,
														(size_t) cs_rss * 4, 
														((float) cs_rss * 4) / (float) 1024);
						}
						break;
        default:
            UNREACHABLE_CODE;
    }

    va_list args;
    va_start(args, format);
    vsprintf(buf2, format, args);
    ERROR_PRINTF("%s: %s", buf2, buf1);
    va_end(args);
}


