
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
#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <pthread.h>

/* The global variable for generation count 
 *
 * NOTE: We hope that 64-bits will be sufficient
 * for the whole-program.
 */
extern uint64_t gGenCount;

// Lock to update genCount in multi-threaded
// environment
extern pthread_mutex_t genCountMutex;

#define GRAB_LOCK()
#define RELEASE_LOCK()

#define GRAB_LOCK1() {\
	if(pthread_mutex_lock(&genCountMutex)) \
		(perror("\n Error: Grabbing a lock failed:")); \
}

#define RELEASE_LOCK1() {\
	if(pthread_mutex_unlock(&genCountMutex)) \
		(perror("\n Error: Releasing a lock failed:")); \
}



#endif /* COMMON_H */
