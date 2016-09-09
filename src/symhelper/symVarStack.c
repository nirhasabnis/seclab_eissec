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

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "symVarStack.h"
#include "symVarList.h"

varstack_t stack;

/************************************
 *      Helper functions            *
 ************************************/

/* Debugging purpose only */
static void print (void)
{
    stack_element_t* currtop = stack.top;

    DEBUG_PRINTF ("Stack top | .. | .. | .. | Stack bottom");

    while (currtop != NULL) {
        uint64_t gcount = getGenCount(_symVarList, currtop->address);
        struct sval_t* sval = getSymValType (_symVarList, currtop->address);
        const char* c = svalTypeToString(sval);
        char* functor = (sval && (sval->svalType_ == SVAL_TERM)) ? sval->functor_ : "<NULL>";
        DEBUG_PRINTF (" | %p (gc=%llu, term type=%s, functor = %s) ", 
                currtop->address, gcount, c, functor);
        currtop = currtop->down;
    }
}

static stack_element_t* getNewElement (uintptr_t address) 
{
    stack_element_t* newnode = (stack_element_t*) 
        malloc (sizeof (stack_element_t));
    assert (newnode != NULL);

    newnode->address = address;
    newnode->down = NULL;

    return newnode;
}

static void deleteElement (stack_element_t* element)
{
    if (element != NULL)
        free (element);
}

/***********************************
 *    Accessor functions           *
 ***********************************/

uintptr_t pop (void)
{
    if (stack.top == NULL)
        return 0;
    
    uintptr_t address = stack.top->address;
    stack_element_t* currtop = stack.top;

    /* Decrement the stack top */
    stack.top = stack.top->down;

    deleteElement (currtop);
    return address;
}

void push (uintptr_t address)
{
    stack_element_t* newnode = getNewElement (address);

    /* If stack is empty */
    if (stack.top == NULL)
        stack.top = newnode;
    else { /* If stack is not empty */
        newnode->down = stack.top;
        stack.top = newnode;
    }
}

void printSymbolicStack (void) { print(); }

static void addNewRecord_ (bool logForUndo)
{
#ifdef USE_OBJCOW
    if (logForUndo)
        AddEntryToSymMetadataAccessRecord (ADD_RECORD, 0, 0, 0);
#endif
    push (0);    
}

static void deleteRecord_ (bool logForUndo)
{
    if (stack.top == NULL)
        return;

    while (stack.top->address != 0) {
        uintptr_t address = pop ();
        int ret;
#ifdef USE_OBJCOW
        ret = logForUndo ? remVarSymbolic (&_symVarList, address) : 
            undoMakeVarSymbolic (&_symVarList, address);
#else
        ret = remVarSymbolic (&_symVarList, address);
#endif
        assert (ret == 0);
    }

    /* The ordering of statements matter for undo: undo action for DEL_RECORD is
     * addNewRecord(), and that function pushes 0 on the stack. Now since
     * deleteRecord_ pops 0 from the stack at the end, we must push 0 on the
     * stack first.
     */
#ifdef USE_OBJCOW
    if (logForUndo)
        AddEntryToSymMetadataAccessRecord (DEL_RECORD, 0, 0, 0);
#endif

    /* Delete the element with address 0 */
    pop ();
}

void addNewRecord(void) { addNewRecord_(true); }
void deleteRecord(void) { deleteRecord_(true); }
void undoDeleteRecord(void) { addNewRecord_(false); }
void undoAddNewRecord (void) { deleteRecord_(false); }


