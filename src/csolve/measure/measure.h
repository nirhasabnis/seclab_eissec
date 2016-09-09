
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


#ifndef MEASURE_H
#define MEASURE_H

#include <sys/time.h>
#include <sys/resource.h>
#include <stdint.h>

/*
 * Structure to represent what we are measuring.
 * Currently we are measuring number of times something
 * is called and time of executing something. If anything else
 * is needed, then update this structure. The interface exposed
 * to user is generic enough that you need not change it when
 * this structure is updated.
 */
typedef struct {
    enum measure_tag_t {
        M_CNT,
        M_TIME_S,
        M_TIME_SC,
				M_MEMORY_SC
    } tag_;

    union measure_data_t {
        uint64_t counter_;
        struct {
            //struct timeval tv_;
            /* resource usage for self */
            struct rusage sru_;
            /* resource usage for children if needed */
            struct rusage cru_;
            /* Per-process time in nanosecs */
            struct timespec ts1_;
            struct timespec ts2_;
        } time_;
				struct {
					struct rusage sru_;
					struct rusage cru_;
				} memory_;
    } data_;
} measure_t;

typedef enum {
    START_COUNTER,
    END_COUNTER,
    /* Timer for self and children */
    START_TIMER_SC,
		START_MEMORY_SC,
    /* Timer for self */
    START_TIMER_S,
    END_TIMER
} measure_event_t;


/*
 * Start measurement. Returns the filled
 * measure_t structure or NULL in case of error.
 */
measure_t* start_measurement (measure_event_t, measure_t*);

/*
 * Increment measurement. This is mostly to be
 * used by counter-based measurements.
 */
measure_t* update_measurement (measure_t*, int offset);

/*
 * End measurement. The measure is specified
 * by input measure_t. Returns the updated measure_t
 * to represent measurement end.
 */
measure_t* end_measurement (measure_t*);

/*
 * Prints measurement to log
 */
void log_measurement (measure_t* m, const char* format, ...);

#endif /* MEASURE_H */
