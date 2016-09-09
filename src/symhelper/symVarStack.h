
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
#ifndef SYMVARSTACK_H
#define SYMVARSTACK_H

#include "symVarList.h"

/*
 * We use stack to represent the symbolic variables for
 * one function. So similar to an activation record of a
 * function, we maintain a record on the stack.
 *
 * For one function, the stack contains the list of all
 * symbolic variables of the stack.
 *
 * We use stack push to register creation of symbolic
 * values in a function. At return, we do pop and delete
 * those symbolic values. 
 *
 * We need to take this approach because we maintain
 * a global table of symbolic values as opposed to local.
 * In case of local table, once we return from a function,
 * local table is not accessible. But this is not true for
 * global table. That is why we need to delete all 
 * symbolic values for current function, when we return
 * from a function.
 *
 * One activation record on the stack is separated from
 * another by 
 *
 * NOTE: Currently we maintain only 1 stack. So this strictly
 * works in case of single-threaded program. For multi-threaded
 * program, we need more than 1 stack. To be precise, we will
 * need number of stacks same as that of number of threads.
 */

typedef struct stack_element {
    /* address of symbolic variable. 
     * address 0 is spacial as it designates special 
     * value (an end of activation record) 
     */
    uintptr_t address;

    /* we implement stack using link list */
    struct stack_element* down;
} stack_element_t;

typedef struct {
    
    /* Top of the stack */
    stack_element_t* top;
} varstack_t;

/*******************************************
 *       Public interface                  *
 *******************************************/

/*
 * Push new activation record to the stack.
 */
void addNewRecord (void);

/*
 * Pop new activation record off the stack,
 * and call delete for all the corresponding
 * symbolic variables from symbolic variables
 * table.
 */
void deleteRecord (void);

/*
 * Undo functions: needed to support object-level COW
 */
void undoAddNewRecord(void);
void undoDeleteRecord(void);

/*
 * Push new address on the stack.
 */
void push (uintptr_t address);

/*
 * Pop the topmost element.
 */
uintptr_t pop(void);

/*
 * Print symbolic stack
 */
void printSymbolicStack(void);

#endif /* SYMVARSTACK_H */
