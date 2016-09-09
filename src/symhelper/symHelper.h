
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

#ifndef SYM_HELPER_H
#define SYM_HELPER_H

#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include "symVarList.h"
#include "cons_solve.h"
#include "symTypes.h"

//int rtx_not_equal_trans (rtx x, rtx y, void* xaddr, void* yaddr, 
//        unsigned long long* gcret);

/****************************************
       Print unary and binary operators
 ****************************************/

#define EXECUTE_UNARY(V, op, O1)                               \
do {                                                           \
    if (strcmp (op, "-") == 0)                                 \
        (V) = -1 * (O1);                                       \
    else if (strcmp (op, "~") == 0)                            \
        (V) = ~(O1);                                           \
    else if (strcmp (op, "!") == 0)                            \
        (V) = !(O1);                                           \
    else                                                       \
        ERROR_PRINTF("Unsupported unary operator: %s", op);    \
} while (0)                                                    \


#define EXECUTE_BINARY(V, O1, op, O2)                          \
do {                                                           \
    if (strcmp (op, "+") == 0)                                 \
        (V) = (O1) + (O2);                                     \
    else if (strcmp (op, "-") == 0)                            \
        (V) = (O1) - (O2);                                     \
    else if (strcmp (op, "*") == 0)                            \
        (V) = (O1) * (O2);                                     \
    else if (strcmp (op, "/") == 0)                            \
        (V) = (O1) / (O2);                                     \
    else if (strcmp (op, "%") == 0)                            \
        (V) = (O1) % (O2);                                     \
    else if (strcmp (op, "<<") == 0)                           \
        (V) = (O1) << (O2);                                    \
    else if (strcmp (op, ">>") == 0)                           \
        (V) = (O1) >> (O2);                                    \
    else if (strcmp (op, "<") == 0)                            \
        (V) = (O1) < (O2);                                     \
    else if (strcmp (op, ">") == 0)                            \
        (V) = (O1) > (O2);                                     \
    else if (strcmp (op, "<=") == 0)                           \
        (V) = (O1) <= (O2);                                    \
    else if (strcmp (op, ">=") == 0)                           \
        (V) = (O1) >= (O2);                                    \
    else if (strcmp (op, "==") == 0)                           \
        (V) = (O1) == (O2);                                    \
    else if (strcmp (op, "!=") == 0)                           \
        (V) = (O1) != (O2);                                    \
    else if (strcmp (op, "&") == 0)                            \
        (V) = (O1) & (O2);                                     \
    else if (strcmp (op, "^") == 0)                            \
        (V) = (O1) ^ (O2);                                     \
    else if (strcmp (op, "&&") == 0)                           \
        (V) = (O1) && (O2);                                    \
    else if (strcmp (op, "||") == 0)                           \
        (V) = (O1) || (O2);                                    \
    else                                                       \
        ERROR_PRINTF("Unsupported binary operator: %s", op);   \
} while (0)                                                    \


/****************************************
   Macros to process symbolic variables
 ****************************************/

//#define DEBUG_PRINTF(...)

/* Name of the global symbol variable list */
#define SYMVARLIST _symVarList

/* Since genCount is uint64_t, we assign the
 * highest possible value to concrete vars. This
 * value must not be used by symbolic vars. */
extern const uint64_t gConcreteVarGcount;

/*
 * Is given variable symbolic?
 * Check if the runtime address of the variable is present in the
 * table, and if yes, check if it is symbolic.
 */
#define IS_SYMBOLIC(address) (isVarSymbolic(SYMVARLIST, (uintptr_t) address))

/*
 * Is given variable symbolic and it has rtl as it's symbolic value?
 */
#define IS_RTL_SYMVAL(address) (isRTLSymVal(SYMVARLIST, (uintptr_t) address))

/*
 * Make given variable symbolic.
 * The runtime address of the variable is added to the table.
 */
#define SET_SYMBOLIC(address) (makeVarSymbolic(&SYMVARLIST, (uintptr_t) address, 0))

/*
 * Make given variable symbolic.
 * The runtime address of the variable is added to the table.
 */
#define SET_SYMBOLIC_WITH_SYMVAL(address,sval) (makeVarSymbolic(&SYMVARLIST, \
            (uintptr_t) address, sval))

/*
 * Macro to get type of symbolic value
 */
#define GET_SYMVAL_TYPE(address) (getSymValType(SYMVARLIST, (uintptr_t) address))

/*
 * Macro to set type of symbolic value
 */
#define SET_SYMVAL_TYPE(address, sval) (setSymValType(&SYMVARLIST,          \
                                        (uintptr_t) address, sval))

/*
 * Get generation count for the variable
 */
#define GET_GENCOUNT(address) (getGenCount(SYMVARLIST, (uintptr_t) address))

#define SET_GENCOUNT(address, gcount) do {                                   \
    if ((gcount) != gConcreteVarGcount)                                      \
        (setGenCount(&SYMVARLIST, (uintptr_t) address, gcount));             \
} while(0)

#define UNDO_SET_GENCOUNT(address, gcount) do {                              \
    if ((gcount) != gConcreteVarGcount)                                      \
        (undoSetGenCount(&SYMVARLIST, (uintptr_t) address, gcount));         \
} while(0)


/* TODO: currently true */
#define IS_SUPPORTED_OP(op) (true)

/* Construct a term corresponding to given variable */
#define VT(addr) (vt(GET_GENCOUNT(addr)))

/* Negate the condition of if-else, and negated condition is
 * added to else part */
#ifdef USE_TRYONE
#define NEGATE_NOP_CONDITION(O1, O1Addr) do {                        \
    /* We need to add negated condition only if                      
     * V is symbolic.
     *
     * If tryone fails (returns 1, then we must fail as that 
     * represents an infeasible constraint and a path                \
     * that won't be taken in actual run.                            \
     */                                                              \
    DEBUG_PRINTF("NEGATE_NOP_CONDITION %s:%d:\t", __FILE__,__LINE__);\
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        unsigned long long rg;                                       \
      /* Since we are negating NOP, we equate O1 to NULL_RTX_CODE */\
      enum rtx_code code; GET_CODE_CONS(O1Addr, &code);	     \
      if (tryone(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) == 1)\
        GOTO_NEXT_BRANCH_IN_USER;				     \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
      if (tryone(ic1c(GET_GENCOUNT(O1Addr), IEQ, 0)) == 1)         \
        GOTO_NEXT_BRANCH_IN_USER;				     \
    }                                                                \
} while(0)                                                           
#else                                                               
#define NEGATE_NOP_CONDITION(O1, O1Addr) do {                        \
    /* We need to add negated condition only if                      
     * V is symbolic.
     *
     * Why are you using addCons here? It should also be a tryboth,
     * right? The only place where I see a need for addCons is
     * at assert(). Even there, you can convert into a tryboth --
     * on one of the branches of tryboth, you will immediately call
     * fail(), while on the other one, you will continue. 
     *
     * If tryboth fails (returns either 1 or greater than 1, then we must\
     * fail as that represents an infeasible constraint and a path   \
     * that won't be taken in actual run.                            \
     */                                                              \
    DEBUG_PRINTF("NEGATE_NOP_CONDITION %s:%d:\t", __FILE__,__LINE__);\
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
      unsigned long long rg;                                       \
      /* Since we are negating NOP, we equate O1 to 0 */	     \
      enum rtx_code code; GET_CODE_CONS(O1Addr, &code);	     \
      if (tryboth(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) >= 1)\
        GOTO_NEXT_BRANCH_IN_USER;				     \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
      if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IEQ, 0)) >= 1)        \
        GOTO_NEXT_BRANCH_IN_USER;                                  \
    }
} while(0)
#endif

/* Negate unary condition in if such as if (!x) */
#ifdef USE_TRYONE
#define NEGATE_UNARY_CONDITION(cons, O1, O1Addr) do {                \
    DEBUG_PRINTF("NEGATE_UNARY_CONDITION %s:%d:\t", __FILE__,__LINE__);\
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        unsigned long long rg;                                       \
        if (strcmp (cons, "!") == 0) {                               \
            /* If CONTRAST_RTX returns 0 then it means we cannot
             * contrast such rtx, and we fail in that case as
             * that path is infeasible.
	     * Since we want to negate !p == true i.e. produce
	     * !p == false, we add that p != 0 */		     \
	    enum rtx_code code; GET_CODE_CONS(O1Addr, &code);	     \
	    if (tryone(ic1c(GET_GENCOUNT(&code), INE, 		     \
			NULL_RTX_CODE)) == 1)	         	     \
	     /* We use GOTO_NEXT_BRANCH_IN_USER because when tryone
		      return 1, constraint solver has already failed. So
		      if we call fail() again, then that would be incorrect.
	      */						     \
	        GOTO_NEXT_BRANCH_IN_USER;			     \
	} else {						     \
	    ERROR_PRINTF("Unsupported unary operator %s in Negation",\
			cons);					     \
	    fatal("\nUnsupported unary operator");	             \
	}							     \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
    /*                                                               \
     * If tryone fails (returns 1 , then we must                     \
     * fail as that represents an infeasible constraint and a path   \
     * that won't be taken in actual run.                            \
     */                                                              \
        /* if (-x) == if (-x != 0)                                   \
         * neg cond: if (-x == 0) */                                 \
        if (strcmp (cons, "-") == 0) {                               \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IEQ, 0)) == 1)     \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        /* if (!x) == if (!x != 0)                                   \
         * neg cond: if (!x == 0) == if (x == !0) */                 \
        } else if (strcmp (cons, "!") == 0) {                        \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IEQ, !0)) == 1)    \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        /* if (~x) == if (~x != 0)                                   \
         * neg cond: if (~x == 0) == if (x == ~0) */                 \
        } else if (strcmp (cons, "~") == 0) {                        \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IEQ, ~0)) == 1)    \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else {                                                     \
            ERROR_PRINTF("Unsupported unary operator %s", cons);     \
            fatal ("\nUnsupported unary operator");                  \
        }                                                            \
    }                                                                \
} while(0)
#else
#define NEGATE_UNARY_CONDITION(cons, O1, O1Addr) do {                \
    DEBUG_PRINTF("NEGATE_UNARY_CONDITION %s:%d:\t",                  \
            __FILE__,__LINE__);                                      \
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        unsigned long long rg;                                       \
        if (strcmp (cons, "!") == 0) {                               \
            /* If CONTRAST_RTX returns 0 then it means we cannot
             * contrast such rtx, and we fail in that case as
             * that path is infeasible.
	     * Since we want to negate !p == true i.e. produce
	     * !p == false, we add that p != 0 */		     \
	    enum rtx_code code; GET_CODE_CONS(O1Addr, &code);	     \
	    if (tryone(ic1c(GET_GENCOUNT(&code), INE, 		     \
				NULL_RTX_CODE)) == 1)	      	     \
	        GOTO_NEXT_BRANCH_IN_USER;				     \
	} else {						     \
	    ERROR_PRINTF("Unsupported unary operator %s in Negation",\
			cons);					     \
	    fatal("\nUnsupported unary operator");	             \
	}							     \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
     /* If tryboth fails (returns either 1 or greater than 1, then we must\
     * fail as that represents an infeasible constraint and a path   \
     * that won't be taken in actual run.                            \
     */                                                              \
        /* if (-x) == if (-x != 0)                                   \
         * neg cond: if (-x == 0) */                                 \
        if (strcmp (cons, "-") == 0) {                               \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IEQ, 0)) >= 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        /* if (!x) == if (!x != 0)                                   \
         * neg cond: if (!x == 0) == if (x == !0) */                 \
        } else if (strcmp (cons, "!") == 0) {                        \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IEQ, !0)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        /* if (~x) == if (~x != 0)                                   \
         * neg cond: if (~x == 0) == if (x == ~0) */                 \
        } else if (strcmp (cons, "~") == 0) {                        \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IEQ, ~0)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported unary operator %s", cons);     \
            fatal ("\nUnsupported unary operator");                  \
        }                                                            \
    }                                                                \
} while(0)
#endif

/* Negate binary condition in if such as if (a > b) */
#ifdef USE_TRYONE
#define NEGATE_BINARY_CONDITION(cons, O1, O2, O1Addr, O2Addr) do {   \
    if (IS_RTL_SYMVAL(O1Addr) || IS_RTL_SYMVAL(O2Addr)) {            \
        unsigned long long rg;                                       \
        if (strcmp (cons, "==") == 0) {                              \
            DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",          \
                        __FILE__,__LINE__);                          \
            /* If CONTRAST_RTX returns 0 then it means we cannot
             * contrast such rtx, and we fail in that case as
             * that path is infeasible. */                           \
            /*if (CONTRAST_RTX((rtx) O1, (rtx) O2,                     \
                        (void*) O1Addr, (void*) O2Addr,              \
                        &rg) == 0)                                  */ \   
		        /* we use GOTO_NEXT_BRANCH_IN_USER because since 
             * contrasting RTX has failed, constraint solver has 
             * already failed. So we need to fail in user process 
             *  only. */						                                 \
		          /*GOTO_NEXT_BRANCH_IN_USER;*/			                         \
        } else if (strcmp (cons, "!=") == 0) {                       \
            DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",        \
                        __FILE__,__LINE__);                          \
            /* If EQUATE_RTX returns 0 then it means we cannot
             * equate such rtx, and we fail in that case as
             * that path is infeasible. */                           \
            /*if (EQUATE_RTX((rtx) O1, (rtx) O2,                       \
                        (void*) O1Addr, (void*) O2Addr,              \
                        &rg) == 0)*/                                   \   
		        /* Same comment as above for why to use BRANCH_IN_USER */ \  
              /*GOTO_NEXT_BRANCH_IN_USER;*/			                         \
        } else {                                                     \
            ERROR_PRINTF("NEGATE_BINARY_CONDITION: "                 \
                "Unsupported comparison operator %s", cons);         \
            fatal("\nNEGATE_BINARY_CONDITION:"                       \
                "Unsupported comparison operator");                  \
        }                                                            \
    } else {                                                         \
    /*                                                               \
     * If tryone fails (returns 1, then we must                      \
     * fail as that represents an infeasible constraint and a path   \
     * that won't be taken in actual run.                            \
     */                                                              \
      if (IS_SYMBOLIC(O1Addr) && IS_SYMBOLIC(O2Addr)) {              \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",              \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); neg: if (a >= b) */                       \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), IGE,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); neg: if (a <= b) */                       \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), ILE,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (a != b) */                      \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), INE,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (a == b) */                      \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), IEQ,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); neg: if (a > b) */                       \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), IGT,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); neg: if (a < b) */                       \
            if (tryone(ic1v(GET_GENCOUNT(O1Addr), ILT,               \
                            GET_GENCOUNT(O2Addr))) == 1)             \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);    \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",             \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); neg: if (a >= b) */                       \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IGE, O2)) == 1)    \
		GOTO_NEXT_BRANCH_IN_USER;			     \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); neg: if (a <= b) */                       \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), ILE, O2)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (a != b) */                      \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), INE, O2)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (a == b) */                      \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IEQ, O2)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); neg: if (a > b) */                       \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), IGT, O2)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); neg: if (a < b) */                       \
            if (tryone(ic1c(GET_GENCOUNT(O1Addr), ILT, O2)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);    \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
    } else if (IS_SYMBOLIC(O2Addr)) {                                \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",              \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); == if (b > a) neg: if (b <= a) */         \
            /* Here condition is O1 cond O2, but since               \
             * in ic1v condition is from perspectie of O2,           \
             * it's not straight-forward negation */                 \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), ILE, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); == if (b < a) neg: if (b >= b) */         \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), IGE, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (b != a) */                      \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), INE, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (b == a) */                      \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), IEQ, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); == if (b >= a); neg: if (b < a) */       \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), ILT, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); == if (b <= a) neg: if (b > a) */        \
            if (tryone(ic1c(GET_GENCOUNT(O2Addr), IGT, O1)) == 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);    \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
      }                                                              \
    }                                                                \
} while(0)                                                            
#else
#define NEGATE_BINARY_CONDITION(cons, O1, O2, O1Addr, O2Addr) do {   \
    if (IS_RTL_SYMVAL(O1Addr) || IS_RTL_SYMVAL(O2Addr)) {            \
        unsigned long long rg;                                       \
        if (strcmp (cons, "==") == 0) {                              \
            DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",        \
                        __FILE__,__LINE__);                          \
            /* If CONTRAST_RTX returns 0 then it means we cannot
             * contrast such rtx, and we fail in that case as
             * that path is infeasible. */                           \
            if (CONTRAST_RTX((rtx) O1, (rtx) O2,                     \
                        (void*) O1Addr, (void*) O2Addr,              \
                        &rg) == 0)                                   \   
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",        \
                        __FILE__,__LINE__);                          \
            /* If EQUATE_RTX returns 0 then it means we cannot
             * equate such rtx, and we fail in that case as
             * that path is infeasible. */                           \
            if (EQUATE_RTX((rtx) O1, (rtx) O2,                       \
                        (void*) O1Addr, (void*) O2Addr,              \
                        &rg) == 0)                                   \   
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("NEGATE_BINARY_CONDITION: "                \  
                "Unsupported comparison operator %s", cons);         \
            fatal("\nNEGATE_BINARY_CONDITION:"                       \  
                "Unsupported comparison operator");                  \
        }                                                            \
    } else {                                                         \
    /*                                                               \
     * If tryboth fails (returns either 1 or greater than 1, then we must\
     * fail as that represents an infeasible constraint and a path   \
     * that won't be taken in actual run.                            \
     */                                                              \
      if (IS_SYMBOLIC(O1Addr) && IS_SYMBOLIC(O2Addr)) {              \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",              \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); neg: if (a >= b) */                       \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), IGE,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); neg: if (a <= b) */                       \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), ILE,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (a != b) */                      \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), INE,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (a == b) */                      \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), IEQ,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); neg: if (a > b) */                       \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), IGT,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); neg: if (a < b) */                       \
            if (tryboth(ic1v(GET_GENCOUNT(O1Addr), ILT,              \
                            GET_GENCOUNT(O2Addr))) >= 1)             \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);     \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
    } else if (IS_SYMBOLIC(O1Addr)) {                                \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",              \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); neg: if (a >= b) */                       \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IGE, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); neg: if (a <= b) */                       \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), ILE, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (a != b) */                      \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), INE, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (a == b) */                      \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IEQ, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); neg: if (a > b) */                       \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), IGT, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); neg: if (a < b) */                       \
            if (tryboth(ic1c(GET_GENCOUNT(O1Addr), ILT, O2)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);    \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
    } else if (IS_SYMBOLIC(O2Addr)) {                                \
        DEBUG_PRINTF("NEGATE_BINARY_CONDITION %s:%d:\t",              \
                        __FILE__,__LINE__);                          \
        if (strcmp (cons, "<") == 0) {                               \
            /* if (a < b); == if (b > a) neg: if (b <= a) */         \
            /* Here condition is O1 cond O2, but since               \
             * in ic1v condition is from perspective of O2,          \
             * it's not straight-forward negation */                 \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), ILE, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">") == 0) {                        \
            /* if (a > b); == if (b < a) neg: if (b >= b) */         \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), IGE, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "==") == 0) {                       \
            /* if (a == b); neg: if (b != a) */                      \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), INE, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "!=") == 0) {                       \
            /* if (a != b); neg: if (b == a) */                      \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), IEQ, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, "<=") == 0) {                       \
            /* if (a <= b); == if (b >= a); neg: if (b < a) */       \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), ILT, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp (cons, ">=") == 0) {                       \
            /* if (a >= b); == if (b <= a) neg: if (b > a) */        \
            if (tryboth(ic1c(GET_GENCOUNT(O2Addr), IGT, O1)) >= 1)   \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
            ERROR_PRINTF("Unsupported binary operator %s", cons);    \
            fatal("\nUnsupported binary operator");                  \
        }                                                            \
      }                                                              \
    }                                                                \
} while(0)                                                           
#endif

#define PROC_RETURN(V) do {                \
    uint64_t gcount = GET_GENCOUNT(&(V));  \
    if (gcount != gConcreteVarGcount)      \
        addOutput(VT(&(V)));               \
    else                                   \
        addOutput(it(V));                  \
    deleteRecord();                        \
    backTrack();                           \
} while(0)
/**************************************
             Handle constraints
 **************************************/

/*
 * How do we determine when to generate which kind of constraints (int vs
 * non-int) and which functions to use (ic1c vs ic1v vs .. )
 *
 * int x, y;
 * x = 5;   ic1c(x, IEQ, 5)
 * x = y;   ic1v(x, IEQ, y)
 *
 * above: x has syntactic type of VAR, 5 has syntactic type of INT, 
 * y has syntactic type of VAR.
 * x,y,5 all have ContentType of INT.. Additionally, contentType cannot be VAR.
 *
 * So we will use ic1c when:
 * syntacticType(t1)=VAR, syntacticType(t2)=INT & (This requirement comes from
 * the prototype of ic1c)
 * contentType(t1)=INT, contentType(t2)=INT
 *
 * So we will use ic1v when:
 * syntacticType(t1)=VAR, syntacticType(t2)=VAR & (This requirement comes from
 * the prototype of ic1c)
 * contentType(t1)=INT, contentType(t2)=INT
 *
 * But for ic1v we will not use contentType to determine if we want to generate
 * integer constraints or not. Refer to comment about ic1v near ADDOPCONS_NOP.
 *
 * float x, y;
 * x = 5.5  tc1t(x, EQ, ft(5.5))
 * x = y;   tc1t(x, EQ, vt(&y))
 */

static enum IOp MAP_IOP(const char* iop)                                              
{                                                                
    if (strcmp (iop, "+") == 0)       return CSPLUS;                         
    else if (strcmp (iop, "-") == 0)  return CSMINUS;                          
    else if (strcmp (iop, "*") == 0)  return CSMULT;                          
    else if (strcmp (iop, "/") == 0)  return CSDIV;                          
    else if (strcmp (iop, "%") == 0)  return CSMOD;                         
    /*
    else if (strcmp (iop, "<<") == 0)  return CSBLSHIFT;                         
    else if (strcmp (iop, ">>") == 0)  return CSBRSHIFT;                         
    else if (strcmp (iop, "^") == 0)  return CSBXOR;                         
    else if (strcmp (iop, "|") == 0)  return CSBOR;                         
    else if (strcmp (iop, "&") == 0)  return CSBAND;                         
    else if (strcmp (cons, "&&") == 0)                           \
    else if (strcmp (cons, "||") == 0)*/                           
    else {                                                      
      /* Because constrop such as >, < can be used as iop,
         we should not fail here and instead check if iop
         that we received is actually constrop. But since
         our return type is IOp, we cannot do that and we
         let user to handle this case. */
         return CSMAX;
    }
}

static enum ConstrOp MAP_CONSTROP(const char* cons, TermType tt) 
{                                                             
    if (strcmp (cons, "<") == 0 && tt == ICONST)  return ILT;                          
    else if (strcmp (cons, ">") == 0 && tt == ICONST)  return IGT;                          
    else if (strcmp (cons, "<=") == 0 && tt == ICONST) return ILE;                         
    else if (strcmp (cons, ">=") == 0 && tt == ICONST) return IGE;
    /* Constant integers and symbolic variables of type integer use IEQ */
    else if ((strcmp (cons, "==") == 0 || strcmp(cons, "=") == 0) 
              && tt == ICONST) 
      return IEQ;
    /* All non-integer types use CSEQ */             
    else if ((strcmp (cons, "==") == 0 || strcmp(cons, "=") == 0) 
              && tt != ICONST) 
      return CSEQ;
    else if (strcmp (cons, "!=") == 0 && tt == ICONST) return INE;                          
    else  {                                                     
        ERROR_PRINTF("Illegal constraint operator: %s at %s:%d",  
              cons,__FILE__,__LINE__);
        char buf[128]; memset(buf, 0, 128); 
        sprintf(buf, "Illegal constraint operator: %s at %s:%d", 
              cons,__FILE__,__LINE__);
        fatal(buf);
    }
}

#ifdef USE_TRYONE
#define ADDCONS_NOP(cons, V, O1, VAddr, O1Addr, VType, O1Type, O1ContentType)\
do {                                                          \
    assert(VType >= ICONST && VType < MAX_TTYPE);            \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);          \
    assert(VType == VAR);                                     \
    DEBUG_PRINTF("CONS_NOP:%d:%s:%d:%s\t", getpid(), __FILE__,__LINE__,__FUNCTION__); \
    TermType o1Type = O1Type;                                 \
                                                              \
    /* If O1 is not symbolic, then we need to look at it's
     * content type for because even though O1 is variable,
     * if it is not symbolic, then we need to generate term   
     * such as it(O1) or similar below. */                    \
    if (!IS_SYMBOLIC(O1Addr))                                 \
        o1Type = O1ContentType;                               \
    else {                                                    \
      /* For symbolic variables, we also look at their
       * content type because choice of constraint (integer
       * vs non-integer) is based on content type only. */    \
      assert (o1Type == VAR || o1Type == LIST);               \
    }                                                         \
                                                              \
    ConstrOp cop = MAP_CONSTROP(cons, O1ContentType);         \
    assert(cop != CMAX);                                      \
                                                              \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                   \
    void* o1SVal = GET_SYMVAL_TYPE(O1Addr);                   \
    SET_SYMBOLIC(VAddr);                                      \
    SET_SYMVAL_TYPE(VAddr, o1SVal);                           \
                                                              \
    switch(o1Type)                                            \
    {                                                         \
        case ICONST:                                          \
            if(tryone(ic1c(GET_GENCOUNT(VAddr), cop, O1)) == 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case VAR:                                             \
            /* Here ideally we can use ic1v to generate integer constraint.
             * But we found that CIL introduces some unnecessary type-casts thus
             * converting statements like rtx p = q; into rtx p = (unsigned int)
             * q; So if we rely on O1ContentType being ICONST and generate a 
             * integer constraint using ic1v, constraint solver will throw
             * error because term (rtx p) is involved in integer constraint. We
             * we will rather use tc1t instead of ic1v. 
            if (O1ContentType == ICONST) {                    \
              if(tryone(ic1v(GET_GENCOUNT(VAddr), cop, o1Gcnt)) == 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            } else {                                          \*/\
              cop = (cop == IEQ) ? CSEQ : CSEQ;                   \
              if(tryone(tc1t(GET_GENCOUNT(VAddr), cop, vt(o1Gcnt))) == 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            /*}*/                                                 \
            break;                                            \
        case CCONST:                                          \
            if(tryone(tc1t(GET_GENCOUNT(VAddr), cop, ct(O1))) == 1)       \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        /* TODO: Fix this: we are getting an error that pointer value used
              where floating point is expected.
        case FCONST:                                          \
            if(tryone(tc1t(GET_GENCOUNT(VAddr), cop, ft((float)O1))) == 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case SCONST:                                          \
            if(tryone(tc1t(GET_GENCOUNT(VAddr), cop, st(O1))) == 1)       \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        */ \
        case LIST:                                            \
            if(tryone(tc1t(GET_GENCOUNT(VAddr), cop, vt(o1Gcnt))) == 1) \
              GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case LISTT:                                           \
            ERROR_PRINTF("Unhandled constraint at %s:%d",     \
                    __FILE__,__LINE__);                       \
        default:                                              \
            /* Unreachable code */                            \
            fatal("\nUnhandled constraint");                  \
    }                                                         \
} while(0)                                                    
#else
#define ADDCONS_NOP(cons, V, O1, VAddr, O1Addr, VType, O1Type, O1ContentType)\
do {                                                          \
    assert(VType >= ICONST && VType < MAX_TTYPE);            \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);          \
    assert(VType == VAR);                                     \
    DEBUG_PRINTF("CONS_NOP:%d:%s:%d:\t", getpid(), __FILE__,__LINE__); \
    TermType o1Type = O1Type;                                 \
                                                              \
    /* If O1 is not symbolic, then we need to look at it's
     * content type for because even though O1 is variable,
     * if it is not symbolic, then we need to generate term   
     * such as it(O1) or similar below. */                    \
    if (!IS_SYMBOLIC(O1Addr))                                 \
        o1Type = O1ContentType;                               \
    else                                                      \
       assert(o1Type == VAR || o1Type == LIST);               \
                                                              \
    ConstrOp cop = MAP_CONSTROP(cons, O1ContentType);         \
    assert(cop != CMAX);                                      \
                                                              \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                   \
    void* o1SVal = GET_SYMVAL_TYPE(O1Addr);                   \
    SET_SYMBOLIC(VAddr);                                      \
    SET_SYMVAL_TYPE(VAddr, o1SVal);                           \
                                                              \
    switch(o1Type)                                            \
    {                                                         \
        case ICONST:                                          \
            if(tryboth(ic1c(GET_GENCOUNT(VAddr), cop, O1)) >= 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case VAR:                                             \
            if(O1ContentType == ICONST) {                      \
              if(tryboth(ic1v(GET_GENCOUNT(VAddr), cop, o1Gcnt)) >= 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            } else {                                            \
              if(tryboth(tc1t(GET_GENCOUNT(VAddr), cop, vt(o1Gcnt))) >= 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            }
            break;                                            \
        case CCONST:                                          \
            if(tryboth(tc1t(GET_GENCOUNT(VAddr), cop, ct(O1))) >= 1)       \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        /* TODO: Fix this
        case FCONST:                                          \
            if(tryboth(tc1t(GET_GENCOUNT(VAddr), cop, ft((float)O1))) >= 1) \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case SCONST:                                          \
            if(tryboth(tc1t(GET_GENCOUNT(VAddr), cop, st(O1))) >= 1)       \
                GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        */
        case LIST:                                            \
            if(tryboth(tc1t(GET_GENCOUNT(VAddr), cop, vt(o1Gcnt))) >= 1) \
              GOTO_NEXT_BRANCH_IN_USER;                       \
            break;                                            \
        case LISTT:                                           \
            ERROR_PRINTF("Unhandled constraint at %s:%d",     \
                    __FILE__,__LINE__);                       \
        default:                                              \
            /* Unreachable code */                            \
            fatal("\nUnhandled constraint");                  \
    }                                                         \
} while(0)
#endif

/* Constraint solver currently does not have support for unary
operations. So we represent unary operations in their semantically
equivalent binary operations.

E.g., (!p) is represented as (p == 0) and
      (-p) is represented as (p * -1)

We dont support ~ yet. */
#ifdef USE_TRYONE
#define ADDCONS_UNOP(cons, iop, V, O1, VAddr, O1Addr, VType, O1Type, O1ContentType)                \
do{   	    							     \    
    assert(VType >= ICONST && VType < MAX_TTYPE);                   \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                 \
    assert(VType == VAR);                                            \
    TermType o1Type = O1Type;                                        \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                          \
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        DEBUG_PRINTF("CONS_UNOP_RTL_SYMVAL:%d:%s:%d:\t", getpid(),   \
            __FILE__,__LINE__);                                      \
        if (strcmp(iop, "!") == 0) {                                 \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                0, O1Addr, 0, &resgcount);                           \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryone(ic1c(GET_GENCOUNT(VAddr), IEQ, result)) == 1)  \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
    	     ERROR_PRINTF("Unhandled constraint: unsupported"          \
             "unary operator at %s:%d",                       \
            __FILE__,__LINE__);                               \
        }                                                            \
    } else {                                                         \
       /* If O1 is not symbolic, then we need to
        * use the value of O1, and in that case,          
        * even though O1 is variable, we need to know    
        * its content type. */                                    \
        DEBUG_PRINTF("CONS_UNOP:%d:%s:%d:\t", getpid(),        \
            __FILE__,__LINE__);                                  \
        if (!IS_SYMBOLIC(O1Addr))                                \
          o1Type = O1ContentType;                              \
        else                                                    \
          assert(o1Type == VAR);                                \
                                                                \
        SET_SYMBOLIC(VAddr);                                     \
                                                                  \
        if (o1Type == VAR && iop == "!") {  \
          /* (!p) is represented as (p == 0) */			\
          if (tryone(rc1v1c(GET_GENCOUNT(VAddr), IEQ, o1Gcnt, 0)) == 1)  \
            GOTO_NEXT_BRANCH_IN_USER;                          \
        } else if (o1Type == ICONST && iop == "!") { \
          /* If O1 is constant then we can simply generate !O1 as a constraint */\
          if (tryone(ic1c(GET_GENCOUNT(VAddr), IEQ, (!O1))) == 1)  \
            GOTO_NEXT_BRANCH_IN_USER;                          \
        } else if (O1Type == VAR && iop == "-") {\
         /* (-p) is represented as (p * -1) */\
          if (tryone(ie1v1c(GET_GENCOUNT(VAddr), CSMULT, o1Gcnt, -1)) == 1) \
            GOTO_NEXT_BRANCH_IN_USER; \
        } else if (O1Type == ICONST && iop == "-") {\
        /* If O1 is constant then we can simply generate -O1 as a constraint */\
          if (tryone(ic1c(GET_GENCOUNT(VAddr), CSEQ, (O1*-1))) == 1) \
            GOTO_NEXT_BRANCH_IN_USER; \
        } else {\
            ERROR_PRINTF("Unhandled constraint: unsupported"          \
                  "unary operator (%s) at %s:%d", iop,  __FILE__,__LINE__);   \
            char buf[128]; memset(buf, 0, 128);   \
            sprintf(buf, "Unhandled constraint: unsupported"          \
                  "unary operator (%s) at %s:%d", iop,  __FILE__,__LINE__);   \ 
            fatal(buf); \
	      } \
   } \
} while (0)                                                   
#else
#define ADDCONS_UNOP(cons, iop, V, O1, VType, O1Type) 		     \
do { 	     							     \
    assert(VType >= ICONST && VType < MAX_TTYPE);                   \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                 \
    assert(VType == VAR);                                            \
    TermType o1Type = O1Type;                                        \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                          \
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        DEBUG_PRINTF("CONS_UNOP_RTL_SYMVAL:%d:%s:%d:\t", getpid(),   \
            __FILE__,__LINE__);                                      \
        if (strcmp(iop, "!") == 0) {                                 \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                0, O1Addr, 0, &resgcount);                           \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryboth(ic1c(GET_GENCOUNT(VAddr), IEQ, result)) >= 1)  \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
    	     ERROR_PRINTF("Unhandled constraint: unsupported"          \
             "unary operator at %s:%d",                       \
            __FILE__,__LINE__);                               \
        }                                                            \
    } else {                                                         \
       /* If O1 is not symbolic, then we need to
        * use the value of O1, and in that case,          
        * even though O1 is variable, we need to know    
        * its content type. */                                    \
        DEBUG_PRINTF("CONS_UNOP:%d:%s:%d:\t", getpid(),           \
            __FILE__,__LINE__);                                  \
        if (!IS_SYMBOLIC(O1Addr))                                \
          o1Type = O1ContentType;                                \
        else                                                     \
          assert(o1Type == VAR);                                 \
        SET_SYMBOLIC(VAddr);                                     \
                                                                 \
        if (o1Type == VAR && iop == "!") {  \
          /* (!p) is represented as (p == 0) */\
          if (tryboth(rc1v1c(GET_GENCOUNT(VAddr), IEQ, o1Gcnt, 0)) >= 1)  \
            GOTO_NEXT_BRANCH_IN_USER;                          \
        } else if (o1Type == ICONST && iop == "!") { \
          /* If O1 is constant then we can simply generate !O1 as a constraint */\
          if (tryboth(ic1c(GET_GENCOUNT(VAddr), CSEQ, (!O1))) >= 1)  \
            GOTO_NEXT_BRANCH_IN_USER;                          \
        } else if (O1Type == VAR && iop == "-") {\
         /* (-p) is represented as (p * -1) */\
          if (tryboth(ie1v1c(GET_GENCOUNT(VAddr), CSMULT, o1Gcnt, -1)) >= 1) \
            GOTO_NEXT_BRANCH_IN_USER; \
        } else if (O1Type == ICONST && iop == "-") {\
        /* If O1 is constant then we can simply generate -O1 as a constraint */\
          if (tryboth(ic1c(GET_GENCOUNT(VAddr), CSEQ, (O1*-1))) >= 1) \
            GOTO_NEXT_BRANCH_IN_USER; \
        } else {\
            ERROR_PRINTF("Unhandled constraint: unsupported"          \
                   "unary operator (%s) at %s:%d", iop,  __FILE__,__LINE__);   \
        } \
   } \
} while (0)                                                   
#endif

#ifdef USE_TRYONE
#define ADDCONS_BINOP(cons, iop, V, O1, O2,                          \
        VAddr, O1Addr, O2Addr,                                       \
        VType, O1Type, O2Type,                                       \
        O1ContentType, O2ContentType)                                \
do {                                                                 \
    assert(VType >= ICONST && VType < MAX_TTYPE);                   \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                 \
    assert(O2Type >= ICONST && O2Type < MAX_TTYPE);                 \
    assert(VType == VAR);                                            \
    TermType o1Type = O1Type;                                        \
    TermType o2Type = O2Type;                                        \
                                                                     \
    /* Lets first save the generation counts of O1 and O2, and
     * then we can make V symbolic. */                               \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                          \
    uint64_t o2Gcnt = GET_GENCOUNT(O2Addr);                          \
                                                                     \
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        DEBUG_PRINTF("CONS_BINOP_RTL_SYMVAL:%d:%s:%d:\t", getpid(),   \
            __FILE__,__LINE__);                                      \
        if (strcmp(iop, "==") == 0) {                                \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                O2, O1Addr, O2Addr, &resgcount);                     \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryone(ic1c(GET_GENCOUNT(VAddr), IEQ, result)) == 1)  \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp(iop, "!=") == 0) {                         \
            /* For rtx inequality, we just check for equality,
             * if two are equal, we set V to 0. Otherwise,
             * we set V to 1. */                                     \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                O2, O1Addr, O2Addr, &resgcount);                     \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryone(ic1c(GET_GENCOUNT(VAddr), IEQ,                 \
                            (result ? 0 : 1))) == 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
             ERROR_PRINTF("[ADDCONS_BINOP] "                         \
                          "Unsupported binary operator at %s:%d",    \
                                __FILE__,__LINE__);                  \
             fatal("[ADDCONS_BINOP] Unsupported binary operator"     \
                   " for rtx comparison");                           \
        }                                                            \
    } else {                                                         \
    /* If either O1 or O2 is not symbolic, then we need to
     * use the value of O1 and O2, and in that case,          
     * even though O1 or O2 are variables, we need to know    
     * their content type. */                                    \
        DEBUG_PRINTF("CONS_BINOP:%d:%s:%d:%s\t", getpid(),        \
            __FILE__,__LINE__,__FUNCTION__);                    \
        if (!IS_SYMBOLIC(O1Addr))                                \
            o1Type = O1ContentType;                              \
        else                                                     \
            assert(o1Type == VAR);                               \
        if(!IS_SYMBOLIC(O2Addr))                                 \
            o2Type = O2ContentType;                              \
        else                                                     \
            assert(o2Type == VAR);                               \
                                                                 \
        IOp op = MAP_IOP(iop);                                   \
        ConstrOp cop;                                            \
        if (op == CSMAX && strcmp(iop, "&") == 0) {           \
            unsigned long long retgcnt;                      \
            unsigned res = band_trans(O1,O2,O1Addr,          \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            if(retgcnt != gConcreteVarGcount)                 \
                SET_GENCOUNT(VAddr, retgcnt);                 \
            else                                               \
                if(tryone(tc1t(GET_GENCOUNT(VAddr), CSEQ, it(res))) == 1) \
                    GOTO_NEXT_BRANCH_IN_USER;                     \
        } else if (op == CSMAX && strcmp(iop, "|") == 0) {    \
            unsigned long long retgcnt;                      \
            unsigned res = bor_trans(O1,O2,O1Addr,           \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, "^") == 0) {    \
            unsigned long long retgcnt;                      \
            unsigned res = bxor_trans(O1,O2,O1Addr,          \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, "<<") == 0) {   \
            unsigned long long retgcnt;                      \
            unsigned res = shleft_trans(O1,O2,O1Addr,        \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, ">>") == 0) {   \
            unsigned long long retgcnt;                      \
            unsigned res = shright_trans(O1,O2,O1Addr,       \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else {                                             \
            if (op == CSMAX) {                               \
                cop = MAP_CONSTROP(iop,                      \
                o1Type == VAR ? O2ContentType : O1ContentType);\
            } else {                                         \
                cop = MAP_CONSTROP(cons,                     \
                o1Type == VAR ? O2ContentType : O1ContentType);\
            }                                                \
            assert(cop != CMAX);                                     \
                                                                     \
            SET_SYMBOLIC(VAddr);                                     \
            /* TODO: Handle the case of O1Type, O2Type = ICONST */   \
            if (o1Type == VAR && o2Type == ICONST && op != CSMAX) {  \
              if (tryone(ie1v1c(GET_GENCOUNT(VAddr), op, o1Gcnt, O2)) == 1)  \
                GOTO_NEXT_BRANCH_IN_USER;                          \
            } else if (o1Type == VAR && o2Type == ICONST && op == CSMAX) {                                \
              if (tryone(rc1v1c(GET_GENCOUNT(VAddr), cop, o1Gcnt, O2)) == 1)                   \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else if (o1Type == VAR && o2Type == VAR && op != CSMAX)  { \
              if (tryone(ie2v(GET_GENCOUNT(VAddr), op, o1Gcnt, o2Gcnt)) == 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else if (o1Type == VAR && o2Type == VAR && op == CSMAX)  { \
              if (tryone(rc2v(GET_GENCOUNT(VAddr), cop, o1Gcnt, o2Gcnt)) == 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else                                                     \
              ERROR_PRINTF("Unhandled constraint: unsupported" \
                           "binary operator at %s:%d",     \
                           __FILE__,__LINE__);                   \
        }                                                             \
    /* \
    switch(O1Type)                                            \
    {                                                         \
        case VAR:                                             \
            if (op != CSMAX) {                               \
                switch(O2Type)                                \
                {                                             \
                  case ICONST:                                \
                    (addCons(ie1v1c(GET_GENCOUNT(VAddr), op,         \
                                    GET_GENCOUNT(O1Addr), O2)));     \
                    break;                                    \
                  case VAR:                                   \
                    (addCons(ie2v(GET_GENCOUNT(VAddr), op,           \
                               GET_GENCOUNT(O1Addr), GET_GENCOUNT(O2Addr))));\
                    break;                                    \
                  default:                                    \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
                }                                             \
            }  else  if (cop != CMAX) {                       \
                switch(O2Type)                                \
                {                                             \
                  case ICONST:                                \
                    (addCons(rc1v1c(GET_GENCOUNT(VAddr), cop,        \
                                    GET_GENCOUNT(O1Addr), O2)));     \
                    break;                                    \
                  case VAR:                                   \
                   (addCons(rc2v(GET_GENCOUNT(VAddr), cop,           \
                        GET_GENCOUNT(O1Addr), GET_GENCOUNT(O2Addr))));      \
                    break;                                    \
                  case FCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, ft(O2))));            \
                    break;                                    \
                  case CCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, ct(O2))));            \
                    break;                                    \
                  case SCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, st(O2))));            \
                    break;                                    \
                  default:                                    \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
                }                                             \
            } else {                                          \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
            }                                                 \
            break;                                            \
        case ICONST:                                          \
        case CCONST:                                          \
        case FCONST:                                          \
        case SCONST:                                          \
        case LIST:                                            \
        case LISTT:                                           \
            DEBUG_PRINTF("Unhandled constraint at %s:%d", \
                    __FILE__,__LINE__);                       \
        default:                                              \
            / * Unreachable code * /                            \
            assert(0);                                        \
    }                             */                            \
   }                                                            \
} while (0) 
#else
#define ADDCONS_BINOP(cons, iop, V, O1, O2,                          \
        VAddr, O1Addr, O2Addr,                                       \
        VType, O1Type, O2Type,                                       \
        O1ContentType, O2ContentType)                                \
do {                                                                 \
    assert(VType >= ICONST && VType < MAX_TTYPE);                   \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                 \
    assert(O2Type >= ICONST && O2Type < MAX_TTYPE);                 \
    assert(VType == VAR);                                            \
    TermType o1Type = O1Type;                                        \
    TermType o2Type = O2Type;                                        \
                                                                     \
    /* Lets first save the generation counts of O1 and O2, and
     * then we can make V symbolic. */                               \
    uint64_t o1Gcnt = GET_GENCOUNT(O1Addr);                          \
    uint64_t o2Gcnt = GET_GENCOUNT(O2Addr);                          \
                                                                     \
    if (IS_RTL_SYMVAL(O1Addr)) {                                     \
        DEBUG_PRINTF("CONS_BINOP_RTL_SYMVAL:%d:%s:%d:\t", getpid(),   \
            __FILE__,__LINE__);                                      \
        if (strcmp(iop, "==") == 0) {                                \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                O2, O1Addr, O2Addr, &resgcount);                     \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryboth(ic1c(GET_GENCOUNT(VAddr), IEQ, result)) >= 1)    \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else if (strcmp(iop, "!=") == 0) {                        \
            /* For rtx inequality, we just check for equality,
             * if two are equal, we set V to 0. Otherwise,
             * we set V to 1. */                                     \
            unsigned long long resgcount;                            \
            int result = rtx_structurally_equal_p_trans (O1,         \
                O2, O1Addr, O2Addr, &resgcount);                     \
            if (resgcount != gConcreteVarGcount)                     \
                SET_GENCOUNT(VAddr, resgcount);                      \
            else                                                     \
                SET_SYMBOLIC(VAddr);                                 \
            if(tryboth(ic1c(GET_GENCOUNT(VAddr), IEQ,                   \
                            (result ? 0 : 1))) >= 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                              \
        } else {                                                     \
             ERROR_PRINTF("[ADDCONS_BINOP] "                        \
                          "Unsupported binary operator at %s:%d",    \
                                __FILE__,__LINE__);                  \
             fatal("[ADDCONS_BINOP] Unsupported binary operator"     \
                   " for rtx comparison");                           \
        }                                                            \
    } else {                                                         \
    /* If either O1 or O2 is not symbolic, then we need to
     * use the value of O1 and O2, and in that case,          
     * even though O1 or O2 are variables, we need to know    
     * their content type. */                                    \
        DEBUG_PRINTF("CONS_BINOP:%d:%s:%d:\t", getpid(),        \
            __FILE__,__LINE__);                                  \
        if (!IS_SYMBOLIC(O1Addr))                                \
            o1Type = O1ContentType;                              \
        else                                                     \
            assert(o1Type == VAR);                               \
        if(!IS_SYMBOLIC(O2Addr))                                 \
            o2Type = O2ContentType;                              \
        else                                                     \
            assert(o2Type == VAR);                               \
                                                                 \
        IOp op = MAP_IOP(iop);                                   \
        ConstrOp cop;                                            \
        if (op == CSMAX && strcmp(iop, "&") == 0) {           \
            unsigned long long retgcnt;                      \
            unsigned res = band_trans(O1,O2,O1Addr,          \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            if(retgcnt != gConcreteVarGcount)                 \
                SET_GENCOUNT(VAddr, retgcnt);                 \
            else                                               \
                if(tryboth(tc1t(GET_GENCOUNT(VAddr), CSEQ, it(res))) >= 1) \
                    GOTO_NEXT_BRANCH_IN_USER;                     \
        } else if (op == CSMAX && strcmp(iop, "|") == 0) {    \
            unsigned long long retgcnt;                      \
            unsigned res = bor_trans(O1,O2,O1Addr,           \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, "^") == 0) {    \
            unsigned long long retgcnt;                      \
            unsigned res = bxor_trans(O1,O2,O1Addr,          \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, "<<") == 0) {   \
            unsigned long long retgcnt;                      \
            unsigned res = shleft_trans(O1,O2,O1Addr,        \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else if (op == CSMAX && strcmp(iop, ">>") == 0) {   \
            unsigned long long retgcnt;                      \
            unsigned res = shright_trans(O1,O2,O1Addr,       \
                           O2Addr,&retgcnt);                 \
            SET_SYMBOLIC(VAddr);                             \
            SET_GENCOUNT(VAddr, retgcnt);                    \
        } else {                                             \
            if (op == CSMAX) {                               \
                cop = MAP_CONSTROP(iop,                      \
                o1Type == VAR ? O2ContentType : O1ContentType);\
            } else {                                         \
                cop = MAP_CONSTROP(cons,                     \
                o1Type == VAR ? O2ContentType : O1ContentType);\
            }                                                \
            assert(cop != CMAX);                                     \
                                                                     \
            SET_SYMBOLIC(VAddr);                                     \
            /* TODO: Handle the case of O1Type, O2Type = ICONST */   \
            if (o1Type == VAR && o2Type == ICONST && op != CSMAX) {  \
              if (tryboth(ie1v1c(GET_GENCOUNT(VAddr), op, o1Gcnt, O2)) >= 1)  \
                GOTO_NEXT_BRANCH_IN_USER;                          \
            } else if (o1Type == VAR && o2Type == ICONST && op == CSMAX) {                                \
              if (tryboth(rc1v1c(GET_GENCOUNT(VAddr), cop, o1Gcnt, O2)) >= 1)                   \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else if (o1Type == VAR && o2Type == VAR && op != CSMAX)  { \
              if (tryboth(ie2v(GET_GENCOUNT(VAddr), op, o1Gcnt, o2Gcnt)) >= 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else if (o1Type == VAR && o2Type == VAR && op == CSMAX)  { \
              if (tryboth(rc2v(GET_GENCOUNT(VAddr), cop, o1Gcnt, o2Gcnt)) >= 1)                 \
                GOTO_NEXT_BRANCH_IN_USER;                          \
           } else                                                     \
              ERROR_PRINTF("Unhandled constraint: unsupported"   \
                           "binary operator at %s:%d",        \
                           __FILE__,__LINE__);              \
        }                                                            \
    /* \
    switch(O1Type)                                            \
    {                                                         \
        case VAR:                                             \
            if (op != CSMAX) {                               \
                switch(O2Type)                                \
                {                                             \
                  case ICONST:                                \
                    (addCons(ie1v1c(GET_GENCOUNT(VAddr), op,         \
                                    GET_GENCOUNT(O1Addr), O2)));     \
                    break;                                    \
                  case VAR:                                   \
                    (addCons(ie2v(GET_GENCOUNT(VAddr), op,           \
                               GET_GENCOUNT(O1Addr), GET_GENCOUNT(O2Addr))));\
                    break;                                    \
                  default:                                    \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
                }                                             \
            }  else  if (cop != CMAX) {                       \
                switch(O2Type)                                \
                {                                             \
                  case ICONST:                                \
                    (addCons(rc1v1c(GET_GENCOUNT(VAddr), cop,        \
                                    GET_GENCOUNT(O1Addr), O2)));     \
                    break;                                    \
                  case VAR:                                   \
                   (addCons(rc2v(GET_GENCOUNT(VAddr), cop,           \
                        GET_GENCOUNT(O1Addr), GET_GENCOUNT(O2Addr))));      \
                    break;                                    \
                  case FCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, ft(O2))));            \
                    break;                                    \
                  case CCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, ct(O2))));            \
                    break;                                    \
                  case SCONST:                                \
                    (addCons(rc1v1t(GET_GENCOUNT(VAddr), cop,        \
                                    O1, st(O2))));            \
                    break;                                    \
                  default:                                    \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
                }                                             \
            } else {                                          \
                    DEBUG_PRINTF("Unhandled constraint: unsupported" \
                            "binary operator at %s:%d",       \
                            __FILE__,__LINE__);               \
            }                                                 \
            break;                                            \
        case ICONST:                                          \
        case CCONST:                                          \
        case FCONST:                                          \
        case SCONST:                                          \
        case LIST:                                            \
        case LISTT:                                           \
            DEBUG_PRINTF("Unhandled constraint at %s:%d", \
                    __FILE__,__LINE__);                       \
        default:                                              \
            / * Unreachable code * /                            \
            assert(0);                                        \
    }                             */                            \
   }                                                            \
} while (0) 
#endif

/********************************************************
             Helper functions for no operator, unary operator
            and binary operator case
 ********************************************************/

/* No operator */
/* This macro supports 3 kinds of statements:
 * (1) i = j 
 * (2) i = foo_cons () where foo_cons is manually defined 
 *         version of foo() that accepts symbolic arguments
 *     i = foo_trans () where foo_trans is transformed version
 *         of foo().
 * (3) x = actualx where x is formal parameter of a function,
 *         actualx is actual argument. So the assignment
 *         designates assignment of formal parameter with
 *         actual argument.
 *
 *  In case (1), O1String will be NULL. isAssignmentToFormalOrFCall 
 *               is false.
 *  In case (2), O1String must not be NULL; O1Addr will be 0;
 *               isAssignmentToFormalOrFCall is true.
 *  In case (3), isAssignmentToFormalOrFCall is true; O1String is 
 *               non-NULL. O1Addr will be 0.
 */
#define ADDOPCONS_NOP(cons, V, O1, VAddr, O1Addr, VType, O1Type,   \
        O1ContentType, isAssignmentToFormalOrFCall)                \
do {                                                               \
    /* Is this an assignment to formal parameter?                  \
     * or assignment to a variable based on function call?         \
     * If yes, make V symbolic first. We need to do this           \
     * because formal parameters are non-symbolic before           \
     * invoking this macro.                                        \
     */                                                            \
    if (!isAssignmentToFormalOrFCall) {                            \
        bool atleastOneSym = false;                                \
                                                                   \
        if (VAddr)                                                 \
            atleastOneSym = IS_SYMBOLIC(VAddr);                    \
                                                                   \
        /* This is the case of explosion and it must not arise as  \
         * it should hav been handled in the OCaml transformation. \
         */                                                        \
        if (!atleastOneSym && O1Addr)                              \
            atleastOneSym = IS_SYMBOLIC(O1Addr);                   \
                                                                   \
        if (atleastOneSym) {                                       \
            ADDCONS_NOP(cons, V, O1, VAddr, O1Addr, VType,         \
                    O1Type, O1ContentType);                        \
        } else                                                     \
            (V) = (O1);                                            \
    } else {                                                       \
        ADDCONS_NOP(cons, V, O1, VAddr, O1Addr, VType,             \
                O1Type, O1ContentType);                            \
    }                                                              \
} while (0)                                                        \


/* Unary operators */
#define ADDOPCONS_UNOP(cons, op, V, O1, VAddr, O1Addr, VType, O1Type, O1ContentType)     \
do {                                                               \
    bool atleastOneSym = false;                                    \
                                                                   \
    if (VAddr)                                                     \
        atleastOneSym = IS_SYMBOLIC(VAddr);                        \
                                                                   \
    if (!atleastOneSym && (O1Addr))                                \
        atleastOneSym = IS_SYMBOLIC(O1Addr);                       \
                                                                   \
    if (atleastOneSym) {                                           \
        if (IS_SUPPORTED_OP(op)) {                                 \
            ADDCONS_UNOP(cons, op, V, O1, VAddr, O1Addr, VType,    \
		O1Type, O1ContentType);                            \
        } else {                                                   \
            /* TODO: Add else part about concrete execution */     \
        }                                                          \
    } else                                                         \
        EXECUTE_UNARY(V, op, O1);                   \
} while (0)                                                        \


/* Binary operators */
#define ADDOPCONS_BINOP(cons, op, V, O1, O2, VAddr, O1Addr,        \
        O2Addr, VType, O1Type, O2Type, O1ContentType,              \
        O2ContentType)                                             \
do {                                                               \
    bool atleastOneSym = false;                                    \
                                                                   \
    if (VAddr)                                                     \
        atleastOneSym = IS_SYMBOLIC(VAddr);                        \
    if (O1Addr && !atleastOneSym)                                  \
        atleastOneSym = IS_SYMBOLIC(O1Addr);                       \
    if (O2Addr && !atleastOneSym)                                  \
        atleastOneSym = IS_SYMBOLIC(O2Addr);                       \
    if (atleastOneSym) {                                           \
        if (IS_SUPPORTED_OP(op)) {                                 \
            /* We cannot make VAddr symbolic at this point.
             * Because if O1Addr or O2Addr is same as
             * VAddr then by making VAddr symbolic,
             * we are changing generation count of O1Addr or
             * O2Addr which is incorrect. So we will make
             * VAddr symbolic only at the point where it is
             * needed.
             */                                                    \
            ADDCONS_BINOP(cons, op, V, O1, O2,                     \
                             VAddr, O1Addr, O2Addr,                \
                             VType, O1Type, O2Type,                \
                             O1ContentType, O2ContentType);        \
        } else {                                                   \
            /* TODO: Add else part about concrete execution */     \
        }                                                          \
    } else                                                         \
        EXECUTE_BINARY(V, (int) O1, op, (int) O2); \
} while (0)                                                        \

/* MACROS to handle Try() */

#define TRY_BINCONS(cons, lhs, O1, O2, O1Addr, O2Addr, O1Type,     \
        O2Type, O1ContentType, O2ContentType)                      \
do {                                                               \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);               \
    assert(O2Type >= ICONST && O2Type < MAX_TTYPE);               \
    assert(O1Type == VAR || O2Type == VAR);                        \
    TermType o1Type = O1Type;                                      \
    TermType o2Type = O2Type;                                      \
                                                                   \
    if (IS_RTL_SYMVAL(O1Addr)) {                                   \
        if (strcmp(cons, "==") == 0) {                             \
            unsigned long long rg;                                 \
            int result = rtx_structurally_equal_p_trans ((rtx) O1, \
                    (rtx) O2, O1Addr, O2Addr, &rg);                \
            (lhs) = result;                                        \
        } else if(strcmp(cons, "!=") == 0) {                       \
            /* For rtx inequality, we test for equality.
             * If equality returns true, then we return false.
             * We return true, if equality returns false.
             */                                                    \
            unsigned long long rg;                                 \
            int result = rtx_structurally_equal_p_trans ((rtx) O1, \
                    (rtx) O2, O1Addr, O2Addr, &rg);                \
            (lhs) = (result ? 0 : 1);                              \
        } else {                                                   \
            ERROR_PRINTF("[TRY_BINCONS] Unsupported binary "       \
                    "operator %s for rtx comparison", cons);       \
            fatal("\n[TRY_BINCONS] Unsupported binary operator"    \
                    "for rtx comparison");                         \
        }                                                              \
    } else {                                                           \
        if (!IS_SYMBOLIC(O1Addr))                                      \
            o1Type = O1ContentType;                                    \
        else                                                           \
            assert(o1Type == VAR);                                     \
        if (!IS_SYMBOLIC(O2Addr))                                      \
            o2Type = O2ContentType;                                    \
        else                                                           \
            assert(o2Type == VAR);                                     \
                                                                       \
        ConstrOp cop = MAP_CONSTROP(cons,                              \
                o1Type == VAR ? O2ContentType : O1ContentType);        \
        assert(cop != CMAX);                                           \
                                                                       \
				SET_GLOC;																											 \
        if (o1Type == VAR && o2Type == ICONST)                         \
        /* The comparison of tryboth result with == 0 is correct here
         * because in both of the following cases it is correct:
         * 1) when constraint addition succeds: child gets return value 
         * of tryboth as 0 and hence == 0 leads child into if branch
         * and parent into else branch.
         * 2) when constraint addition fails: there is no child and the
         * return value is 1. So == 0 fails, and the parent process goes
         * into else branch. Going into else branch when constraint
         * addition fails is the correct method.
         *
         * In addition we cannot use tryone here as we actually want
         * to explore both branches.
         */                                                          \
            (lhs) = (tryboth(ic1c(GET_GENCOUNT(O1Addr), cop, O2)) == 0);   \
        else if (o1Type == VAR && o2Type == VAR)                       \
            (lhs) = (tryboth(ic1v(GET_GENCOUNT(O1Addr), cop,               \
                        GET_GENCOUNT(O2Addr))) == 0);                  \
        else if (o1Type == ICONST && o2Type == ICONST)                 \
            EXECUTE_BINARY(lhs, (int) O1, cons, (int) O2);   \
        else if (o1Type == ICONST && o2Type == VAR);                   \
        else                                                           \
            ERROR_PRINTF("Unsupported case for the"                   \
                    " moment in TRY_BINCONS at %s:%d:%s:%d:%d\n",      \
                    __FILE__,                                          \
                __LINE__, __FUNCTION__, o1Type, o2Type);               \
    }                                                                  \
} while(0)
   
/*
 * This represents conditions of if statement such as
 *
 * if (i)
 * if (5)
 *
 * This does not include unary operators such as
 *  * if (!i)
 *
 * We will just convert this condition into binary
 * one such as
 *
 * if (i) --> if (i != 0)
 */
#define TRY_NOPCONS_OP(lhs, O1, O1Addr, O1Type, O1ContentType) \
do {                                                                \
    bool atleastOneSym = false;                                     \
                                                                    \
    if (O1Addr)                                                     \
        atleastOneSym = IS_SYMBOLIC(O1Addr);                        \
    if (atleastOneSym) {                                            \
        DEBUG_PRINTF("Symbolic Try:%d:%s:%d:%s\t", getpid(),        \
                __FILE__?__FILE__:"null", __LINE__,__FUNCTION__);   \
        TRY_BINCONS("!=", lhs, O1, 0, O1Addr, 0, O1Type, ICONST,    \
                O1ContentType, ICONST);                             \
    } else                                                          \
        EXECUTE_BINARY(lhs, (int) O1, "!=", 0);                \
} while(0)                                                          \

/* TODO: */
#define TRY_UNOPCONS(cons, lhs, O1, O1Addr, O1Type, O1ContentType)  \
do {                                                                \
    ERROR_PRINTF("\n[TRY_UNOPCONS] Not supported at the moment at %s:%d", __FILE__,__LINE__);          \
} while(0)                                                          \
/*
 * This represents the case of condition such as
 *
 * if (!x) which is converted to if (x==0)
 * if (-x) which is converted into t=-x; if (t != 0)
 * We do not yet support ~.
 */
#define TRY_UNOPCONS_OP(cons, lhs, O1, O1Addr, O1Type, O1ContentType)  \
do {                                                                 \
    bool atleastOneSym = false;                                      \
                                                                     \
    if (O1Addr)                                                      \
        atleastOneSym = IS_SYMBOLIC(O1Addr);                         \
    if (atleastOneSym)  {                                            \
        DEBUG_PRINTF("Symbolic Try:%d:%s:%d:%s\t", getpid(),          \
                __FILE__?__FILE__:"null", __LINE__,__FUNCTION__);    \
      if (cons == "!") {					\
        TRY_BINCONS("==", lhs, O1, 0, O1Addr, 0, O1Type, ICONST,    \
                    O1ContentType, ICONST);                             \
      } else if (cons == "-") {				    \
         int tmp; SET_SYMBOLIC(&tmp);				    \
         ADDOPCONS_BINOP("=", "*", tmp, O1, -1, &tmp, O1Addr, 0, \
            VAR, O1Type, ICONST, O1ContentType, ICONST);	\
         TRY_BINCONS("!=", lhs, tmp, 0, &tmp, 0, VAR, ICONST, ICONST, ICONST); \
      } else {						   \
         ERROR_PRINTF("\n[TRY_UNOPCONS_OP] Not supported at the \
          moment at %s:%d", __FILE__,__LINE__);          \
	    }						\
    } else                                                           \
        EXECUTE_UNARY(lhs, cons, (int) O1);                 \
} while(0)                                                           \

/*
 * This represents conditions of if statement such as
 *
 * i > 0
 * i != 10
 * i > j
 * i <= k
 *
 * For cases such as i < j + k, we plan to it into
 * tmp = j + k;
 * i < tmp
 */
#define TRY_BINCONS_OP(cons, lhs, O1, O2, O1Addr, O2Addr, O1Type,    \
        O2Type, O1ContentType, O2ContentType)                        \
do {                                                                 \
    bool atleastOneSym = false;                                      \
                                                                     \
    if (O1Addr)                                                      \
        atleastOneSym = IS_SYMBOLIC(O1Addr);                         \
    if (O2Addr && !atleastOneSym)                                    \
        atleastOneSym = IS_SYMBOLIC(O2Addr);                         \
    if (atleastOneSym)  {                                            \
        DEBUG_PRINTF("Symbolic Try:%d:%s:%d:%s\t", getpid(),         \
                __FILE__?__FILE__:"null", __LINE__,__FUNCTION__);    \
        TRY_BINCONS(cons, lhs, O1, O2, O1Addr, O2Addr, O1Type,       \
                O2Type, O1ContentType, O2ContentType);               \
    } else {                                                         \
        DEBUG_PRINTF("Concrete Try:%d:%s:%d:\t", getpid(),           \
                __FILE__?__FILE__:"null", __LINE__);                 \
        EXECUTE_BINARY(lhs, (int) O1, cons, (int) O2);     			     \
    }                                                                \
} while(0)                                                           \

/********************************************************************
        Helper functions for array and structure access case
 *******************************************************************/
#define PUT_ELEM_CONS_HELPER(arrAddr, len, idx, O1, O1Addr, O1Type,  \
                             O1ContentType)                          \
do {                                                                 \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                  \
    TermType o1Type = (!IS_SYMBOLIC(O1Addr)) ? O1ContentType : O1Type;\
    Term* o1Term;                                                    \
    switch(o1Type)                                                   \
    {                                                                \
        case ICONST: o1Term = it((unsigned) O1); break;              \
        case CCONST: o1Term = ct((char) O1); break;                  \
        /*case FCONST: o1Term = ft((float) (void*) O1); break;       */\
        case SCONST: o1Term = st((char*) O1); break;                 \
        case VAR:    o1Term = vt(GET_GENCOUNT(O1Addr)); break;       \
        default: fatal("\nUnhandled term type in PUT_ELEM_CONS_HELPER"); \
    }                                                                \
    PUT_ELEM_CONS(arrAddr, len, idx, o1Term);                        \
}while(0)

#define PUT_FIELD_CONS_HELPER(strAddr, numfld, fldno, fn, O1, O1Addr,\
                             O1Type, O1ContentType)                  \
do {                                                                 \
    assert(O1Type >= ICONST && O1Type < MAX_TTYPE);                 \
    TermType o1Type = (!IS_SYMBOLIC(O1Addr)) ? O1ContentType : O1Type;\
    Term* o1Term;                                                    \
    switch(o1Type)                                                   \
    {                                                                \
        case ICONST: o1Term = it((unsigned) O1); break;              \
        case CCONST: o1Term = ct((char) O1); break;                  \
        /*case FCONST: o1Term = ft((float) O1); break;               */\
        case SCONST: o1Term = st((char*) O1); break;                 \
        case VAR:    o1Term = vt(GET_GENCOUNT(O1Addr)); break;       \
        default: fatal("\nUnhandled term type in PUT_FIELD_CONS_HELPER"); \
    }                                                                \
    PUT_FIELD_CONS(strAddr, numfld, fldno, fn, o1Term);              \
}while(0)

#undef fprintf
#endif /* SYM_HELPER_H */
