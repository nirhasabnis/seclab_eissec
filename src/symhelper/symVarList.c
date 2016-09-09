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
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "symVarList.h"
#include "symVarStack.h"
#include "common.h"
#include "cons_solve.h"

/* variable that defines gen count for representing
 * concrete variables */
const uint64_t gConcreteVarGcount = ULLONG_MAX;

/* Initialize global generation count variable. Its
 * starting value is 10 because values 0 and 1 are assigned
 * for input and ouput and hence are reserved. 3 is reserved for
 * conditions on the output variables. Rest are reserved for future
 * use. */
uint64_t gGenCount = 10;

pthread_mutex_t genCountMutex;

/* =============================================== */
/*				Internal support functions							 */
/* =============================================== */

static element_t* getNewElement (const uintptr_t address)
{
    element_t* newelement = (element_t*) malloc (sizeof(element_t));

    assert (newelement != NULL);

    newelement->address_ = address;
    newelement->isSymbolic_ = false;
    newelement->sval_.svalType_ = SVAL_OTHER;
    newelement->sval_.functor_ = NULL;
    newelement->next_ = NULL;
        
    return newelement;
}

static void freeSval (struct sval_t* sval)
{
    if (sval == NULL) return;
    if (sval->svalType_ == SVAL_TERM &&
        sval->functor_ != NULL) 
        free(sval->functor_);
    sval->svalType_ = SVAL_OTHER;
    sval->functor_ = NULL;
}

static void remElement (element_t* element)
{
    if (element == NULL)
        return;

    element->next_ = NULL;
    if (element->sval_.svalType_ == SVAL_TERM &&
        element->sval_.functor_ != NULL)
        free(element->sval_.functor_);
    free (element);
}

void printList (const element_t* head)
{
    if (head == NULL)
        return;

    DEBUG_PRINTF ("Printing the list .. ");

    const element_t* ptr = head;
    while (ptr != NULL) {
        DEBUG_PRINTF ("address = %x, isSymbolic = %s, genCount = %llu,\
                {svalType = %d, functor = %s}", ptr->address_, 
                ptr->isSymbolic_ ? "true" : "false", ptr->genCount_, 
                ptr->sval_.svalType_, ptr->sval_.functor_ ? 
                ptr->sval_.functor_ : "<NULL>"); 
        ptr = ptr->next_;
    }

    DEBUG_PRINTF("End of printing .. ");
}


static element_t* lookupElement (const element_t* head, const uintptr_t address)
{
    if (head == NULL)
        return NULL;

    const element_t* ptr = head;

    while (ptr != NULL) {
        if (ptr->address_ == address)
            return (element_t*) ptr;

        ptr = ptr->next_;
    }

    return NULL;
}

static void increaseGenCount (element_t* head, const uintptr_t address)
{
    if (head == NULL)
        return;

    element_t* ptr = head;

    while (ptr != NULL) {
        if (ptr->address_ == address)
            break;
        else		    
            ptr = ptr->next_;
    }

    if (ptr == NULL)
        return;

    GRAB_LOCK();
    /* This is the maximum value gen count can have */
    assert(gGenCount < gConcreteVarGcount);
    ptr->genCount_ = gGenCount++;
    RELEASE_LOCK();
}

/* =============================================== */
/*				Public interface functions		   */
/* =============================================== */

static uint32_t makeVarSymbolic_ (element_t** head, const uintptr_t address, 
        const struct sval_t* sval, bool logForUndo)
{
    if (head == NULL || (void*) address == NULL)
        return 1;

    /* Let's check if the variable is already in our list */
    if (isVarSymbolic (*head, address)) {
        /* If it is already symbolic, then that means it is
         * already assigned, this is another assignment to
         * same variable. So for dynamic single assignment,
         * inrease the global generation count and then assign
         * global count to the variable pointed by address.
         */
        const element_t* ptr = lookupElement (*head, address);
#ifdef USE_OBJCOW
        if (logForUndo) {
            /* Save the current generation count before incrementing to the log */
            AddEntryToSymMetadataAccessRecord (MODIFY_SYMVAR, (void*) ptr->address_, 
                    ptr->genCount_, (void*) &ptr->sval_);
        }
#endif
        increaseGenCount (*head, address);
        return 0;
    }

    element_t* newnode = getNewElement (address);
    if (!newnode)
        return 1;

    newnode->isSymbolic_ = true;
    if (sval != NULL) {
        newnode->sval_.svalType_ = sval->svalType_;
        if (newnode->sval_.svalType_ == SVAL_TERM) {
            assert(sval->functor_ != NULL);
            newnode->sval_.functor_ = strdup(sval->functor_);
        }
    }

#ifdef USE_OBJCOW
    if (logForUndo)
        AddEntryToSymMetadataAccessRecord (MAKE_SYMVAR, (void*) newnode->address_,
            newnode->genCount_, &newnode->sval_);
#endif

    /* Add this variable to symbolic variable stack */
    push (address);

    if (*head == NULL)
        *head = newnode;
    else {
        element_t* ptr = *head;
        while(ptr->next_ != NULL)
            ptr = ptr->next_;

        ptr->next_ = newnode;
    }

    /* Even though this particular variable might have been
     * assigned for the first time, this might be second
     * invocation of the same function, so to generate
     * unique name for this symbolic variable, increase
     * its generation count.
     */
    increaseGenCount (*head, address);
    return 0;
}


bool isVarSymbolic (const element_t* head, const uintptr_t address)
{
    if (head == NULL || (void*) address == NULL)
        return false;

    const element_t* ptr = lookupElement (head, address);
    if (ptr != NULL)
        return ptr->isSymbolic_;

    return false;
}

uint64_t getGenCount (const element_t* head, const uintptr_t address)
{
    if (head == NULL || (void*) address == NULL)
        return gConcreteVarGcount;

    const element_t* ptr = lookupElement (head, address);
    if (ptr != NULL)
        return ptr->genCount_;

    return gConcreteVarGcount;
}

static int setGenCount_ (element_t** head, const uintptr_t address,
        uint64_t gencount, bool logForUndo)
{
    if (head == NULL || (void*) address == NULL || 
            gencount == gConcreteVarGcount)
        return 1;

    element_t* ptr = NULL;

check_again:
    ptr = lookupElement (*head, address);
    if (ptr != NULL) {
#ifdef USE_OBJCOW
        if (logForUndo)
            AddEntryToSymMetadataAccessRecord (MODIFY_SYMVAR, (void*) ptr->address_, 
                ptr->genCount_, &ptr->sval_);
#endif
        ptr->genCount_ = gencount;
        return 0;
    } else {
        if (logForUndo) 
            makeVarSymbolic (head, address, NULL);
        else
            undoRemVarSymbolic (head, address, NULL);
        goto check_again;
    }

    return 1;
}

struct sval_t* getSymValType (const element_t* head, const uintptr_t address)
{
    if (head == NULL || (void*) address == NULL)
        return NULL;

    const element_t* ptr = lookupElement (head, address);
    if (ptr != NULL)
        return &ptr->sval_;

    return NULL;
}

static int setSymValType_ (element_t** head, const uintptr_t address,
        struct sval_t* sval, bool logForUndo)
{
    if (head == NULL || (void*) address == NULL|| sval == NULL)
        return 1;

    element_t* ptr = NULL;

check_again:
    ptr = lookupElement (*head, address);
    if (ptr != NULL) {
#ifdef USE_OBJCOW
        if (logForUndo)
            AddEntryToSymMetadataAccessRecord (MODIFY_SYMVAR, (void*) ptr->address_, 
                ptr->genCount_, &ptr->sval_);
#endif
        // If term sval is already assigned, then free it first
        // otherwise there will be a memory leak.
        if (ptr->sval_.svalType_ == SVAL_TERM)
            freeSval(&ptr->sval_);
        ptr->sval_.svalType_ = sval->svalType_;
        if (ptr->sval_.svalType_ == SVAL_TERM) {
            assert(sval->functor_ != NULL);
            ptr->sval_.functor_ = strdup(sval->functor_);
         }
        return 0;
    } else {
        if (logForUndo) 
            makeVarSymbolic (head, address, NULL);
        else
            undoRemVarSymbolic (head, address, NULL);
        goto check_again;
    }

    return 1;
}

bool isRTLSymVal (element_t* head, const uintptr_t address)
{
    struct sval_t* sval = getSymValType (head, address);
    return (sval != NULL &&
            sval->svalType_ == SVAL_TERM &&
            (strcmp(sval->functor_, RTL_FUNCTOR) == 0));
}

static uint32_t remVarSymbolic_ (element_t** head, const uintptr_t address, bool logForUndo)
{
    if (head == NULL || *head == NULL || (void*) address == NULL)
        return 1;

    element_t* ptr = *head;

    // stores the pointer to the previous element in the list
    element_t* prev = NULL;

    while (ptr != NULL &&
           ptr->address_ != address) {
        prev = ptr;
        ptr = ptr->next_;
    }

    if (ptr == NULL)
        return 1;

#ifdef USE_OBJCOW
    if (logForUndo)
        AddEntryToSymMetadataAccessRecord (REM_SYMVAR, (void*) ptr->address_, 
            ptr->genCount_, &ptr->sval_);
#endif

    // we are removing the first element in the list
    if (prev == NULL) {
        *head = ptr->next_;
        remElement (ptr);
    } else {
        prev->next_ = ptr->next_;
        remElement (ptr);
    }

    return 0;
}

uint32_t remList (element_t** head)
{
    if (head == NULL ||
        *head == NULL)
        return 1;

    element_t* ptr = *head;
    element_t* next = NULL;

    while (ptr != NULL) {
        next = ptr->next_;
        remElement (ptr);
        ptr = next;
    }

    *head = NULL;
    return 0;
}

const char* svalTypeToString (const struct sval_t* sval)
{
    return sval ? symval_type_string[sval->svalType_] : "<NULL>";
}

uint32_t makeVarSymbolic (element_t** head, const uintptr_t address, 
        const struct sval_t* sval)
{
			
    int ret = makeVarSymbolic_ (head, address, sval, true);
		if (address == 0xbfffba64) {	
			DEBUG_PRINTF("0xbfffba64 was made symbolic");
			printList(*head);
		}
		return ret;
}

int setGenCount (element_t** head, const uintptr_t address,  
        uint64_t gencount)
{
    return setGenCount_ (head, address, gencount, true);
}

int setSymValType (element_t** head, const uintptr_t address,
        struct sval_t* sval)
{
    return setSymValType_ (head, address, sval, true);
}

uint32_t remVarSymbolic (element_t** head, const uintptr_t address)
{
    return remVarSymbolic_ (head, address, true);
}

uint32_t undoMakeVarSymbolic (element_t** head, const uintptr_t address)
{
    return remVarSymbolic_ (head, address, false);
}

int undoSetGenCount (element_t** head, const uintptr_t address,  
        uint64_t gencount)
{
    return setGenCount_ (head, address, gencount, false);
}

int undoSetSymValType (element_t** head, const uintptr_t address,
        struct sval_t* sval)
{
    return setSymValType_ (head, address, sval, false);
}

uint32_t undoRemVarSymbolic (element_t** head, const uintptr_t address, 
        const struct sval_t* sval)
{
    return makeVarSymbolic_ (head, address, sval, false);
}

uint64_t nv (void)
{
    uint64_t ret;
    GRAB_LOCK();
    assert(gGenCount < gConcreteVarGcount);
    ret = gGenCount++;
    RELEASE_LOCK();
    return ret;
}

Term* ntv (void)
{ 
    return vt(nv());
}
