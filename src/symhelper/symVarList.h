
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
#ifndef SYMVARLIST_H
#define SYMVARLIST_H

#include <stdint.h>
#include <stdbool.h>
#include "cons_solve.h"

/*
 * Type of access for symbolic metadata
 */
typedef enum { 
    MAKE_SYMVAR, REM_SYMVAR, MODIFY_SYMVAR,
    ADD_RECORD, DEL_RECORD
} SymMetaDataEntryType;

/*
 * Type of a value a symbolic variable can have.
 * This is used to determine run-time type of a 
 * symbolic variable. The type information is 
 * propogated using data-flow rules.
 */
typedef enum symvar_val {
    SVAL_INT,
    SVAL_CHAR,
    SVAL_FLOAT,
    SVAL_STRING,
    SVAL_TERM,
    SVAL_LIST,
    SVAL_OTHER
} symvar_val_t;

static const char* const symval_type_string[] = {"SVAL_INT",
    "SVAL_CHAR", "SVAL_FLOAT", "SVAL_STRING", "SVAL_TERM",
    "SVAL_LIST", "SVAL_OTHER"};

#define RTL_FUNCTOR "rtl"
#define RTVEC_FUNCTOR "rtvec"
#define INSN_FUNCTOR "insn"
#define UNIONU_FUNCTOR "union_u"
#define INT_FUNCTOR "int"
#define UINT_FUNCTOR "uint"
#define WINT_FUNCTOR "wint"

/*
 * Type of symbolic value 
 */
struct sval_t {
    symvar_val_t svalType_;
    /* In case svalType is TERM */
    char* functor_;
};

/*
 * Type of element of Symbolic variables list.
 *
 * We maintain the list of symbolic variables of a given function.
 * The list is maintained on per-function basis per call.
 *
 * IMP: DO NOT change the structure below unless you change the .ml
 *      file.
 */

typedef struct element {
	/*
	 * The address of symbolic variable.
	 * We use runtime address as a unique identifier for the variable.
	 */
	uintptr_t address_;

	/*
	 * boolean to indicate if the variable is symbolic.
	 */
	bool isSymbolic_;

	/*
	 * The generation count of the variable.
	 * This is needed because we want to perform
	 * dynamic single assignment to symbolic 
	 * variable. So the count helps us distinguish
	 * between 2 different assignments to the same 
	 * variable. The count is incremented whenever
	 * an assignment is made to the symbolic variable.
	 */
	uint64_t genCount_;

    /* Type of symbolic value */
    struct sval_t sval_;

	/*
	 * pointer to next element in list
	 */
	struct element* next_;
} element_t;

/*
 * Global symbolic variable list
 */
extern element_t* _symVarList;


/* ===========================================================
 * 					Public Interface	
 * =========================================================== 
 */

/*
 * Make given variable symbolic.
 *
 * @param [in] : head : the address of head of the list.
 * 											If list is empty, then allocates new head. 
 * @param[in] : address : the address of the variable to be added
 *                        to the list
 *
 * @param[in]: a pointer pointing to sval_t in case sval needs to be set. Otherwise, NULL.
 *
 * @return : 0 : in case of success
 * 			 1 : in case of failure
 */
uint32_t makeVarSymbolic (element_t** head, const uintptr_t address, const struct sval_t*);

/*
 * Check if given variable is symbolic.
 *
 * @param [in] : head : the head of the list
 * @param [in] : address : the address to the variable to be 
 * 												 looked up
 *
 * @return: true : if variable is symbolic,
 *          false : otherwise
 */
bool isVarSymbolic (const element_t* head, const uintptr_t address);

/*
 * Returns the generation count for this variable.
 * The variable is identified by its runtime address.
 *
 * @param [in] : head : the head of the list
 * @param [in] : address : the address of the variabled whose
 * 												generation count is needed.
 *
 * @return : ULLONG_MAX : in case the generation count for this varible
 * 					      is not found, otherwise genereation count
 * 						  is returned.
 */
uint64_t getGenCount (const element_t* head, const uintptr_t address);

/*
 * Set the generation count of given variable
 * The variable is identified by its runtime address.
 *
 * @param[in]: head : the head of the list
 * @param[in]: address: the address of the variable whose generation
 *                      count is to be set
 * @param[in]: the generation count
 * @return: 0: in case of success, 1 in case of failure
 */

int setGenCount (element_t** head, const uintptr_t address, 
        uint64_t gencount);

/*
 * Get the symval structure for given symbolic variable
 */
struct sval_t* getSymValType (const element_t* head, const uintptr_t address);

/*
 * Set the symval structure for given symbolic variable
 */
int setSymValType (element_t** head, const uintptr_t address,
        struct sval_t* sval);

/*
 * Checks if the symbolic value associated with the
 * symbolic variable is rtl
 */
bool isRTLSymVal (element_t* head, const uintptr_t address);

/*
 * Deletes symbolic variable from the list
 *
 * @param [in] : head : head of the list
 * @param [in] : address : address of the variable to be deleted
 *
 * @return : 0 : in case of success
 * 				   1 : in case of failure
 */
uint32_t remVarSymbolic (element_t** head, const uintptr_t address);

/*
 * Delete the list
 *
 * @param [in] : head : the head of the list
 *
 * @return : 0 : in case of success
 * 					 1 : in case of failure
 */
uint32_t remList (element_t** head);

/*
 * Print the list. For debugging purpose only.
 */
void printList (const element_t* head);

/*
 * Get string corresponding to the sval
 */
const char* svalTypeToString (const struct sval_t* sval);

/*
 * Some undo functions: needed to support object-level COW
 */
uint32_t undoMakeVarSymbolic (element_t** head, const uintptr_t address);
int undoSetGenCount (element_t** head, const uintptr_t address, uint64_t gencount);
int undoSetSymValType (element_t** head, const uintptr_t address, struct sval_t* sval);
uint32_t undoRemVarSymbolic (element_t** head, const uintptr_t address, 
        const struct sval_t* sval);

/*
 * Get the next generation count
 */

uint64_t nv (void);

/*
 * Get the next variable term
 */
Term* ntv (void);

/*===============================================
 *          Externs
 *===============================================*/

void AddEntryToSymMetadataAccessRecord (SymMetaDataEntryType etype,
                    void* address, uint64_t gcount, void*);

#endif /* SYMVARLIST_H */
