
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

#ifndef OBJCOW_H
#define OBJCOW_H

#include <iostream>
#include <iterator>
#include <vector>
#include <stack>

#include <assert.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "cons_solve.h"
#include "symVarList.h"
#include "symVarStack.h"

extern char* gv_file_path;
extern uint64_t bpStackDepth;
}

using namespace std;

#undef DEBUG_PRINTF
#define DEBUG_PRINTF(...)

class UndoRecordEntry {
    public:
        virtual ~UndoRecordEntry() {}
        virtual void PerformUndo() = 0;
};

typedef vector<UndoRecordEntry*> UndoRecord;

class MemAccessRecordEntry: public UndoRecordEntry {
    private:
        /// Address being updated
        void* mare_address_;
        /// the access size
        uint32_t    mare_size_;
        /// pointer to the location where contents before updation are stored
        void* mare_contents_;

    public:
        /// Constructor
        MemAccessRecordEntry (void* address, uint32_t size, void* contents) 
            : mare_address_(address), mare_size_(size), mare_contents_(contents) {}
        ~MemAccessRecordEntry ()
        { 
            if (mare_contents_) 
                free(mare_contents_);
            mare_contents_ = NULL;
        }

        /// Accessor functions
        inline void* GetAddress()  const { return mare_address_;  }
        inline uint32_t    GetSize() const { return mare_size_;     }
        inline void* GetContents() const { return mare_contents_; }
        void PerformUndo()
        { 
            assert(mare_address_ != NULL);
            assert(mare_contents_ != NULL);
            char* p = (char*) mare_contents_;
            for(int i = 0; i < mare_size_; i++)
                DEBUG_PRINTF("%2x:", *p++);
            memcpy(mare_address_, mare_contents_, mare_size_);
        }
};

#if 0
extern "C" {
typedef enum { MAKE_SYMVAR, REM_SYMVAR, MODIFY_SYMVAR,
            ADD_RECORD, DEL_RECORD} SymMetaDataEntryType;
}
#endif

class SymMetadataRecordEntry: public UndoRecordEntry {
    private:
        SymMetaDataEntryType smre_type_;
        void* smre_address_;
        uint64_t smre_gencount_;
        struct sval_t* smre_sval_;

    public:
        SymMetadataRecordEntry (SymMetaDataEntryType etype, 
            void* address, uint64_t gcount, struct sval_t* sval) :
            smre_type_(etype), smre_address_(address), smre_gencount_(gcount)
        {
            smre_sval_ = NULL;
            if (sval != 0) {
                smre_sval_ = (struct sval_t*) malloc (sizeof(struct sval_t));
                smre_sval_->svalType_ = sval->svalType_;
                if (sval->svalType_ == SVAL_TERM && sval->functor_ != NULL)
                    smre_sval_->functor_ = strdup(sval->functor_);
                else
                    smre_sval_->functor_ = NULL;
            }
        }

        ~SymMetadataRecordEntry()
        {
            if (smre_sval_ != NULL) {
                if (smre_sval_->svalType_ == SVAL_TERM && 
                    smre_sval_->functor_ != NULL) {
                    free(smre_sval_->functor_);
                    smre_sval_->functor_ = NULL;
                }
                free(smre_sval_); smre_sval_ = NULL;
            }
        }

        void PerformUndo()
        {
            switch (smre_type_) {
                case MAKE_SYMVAR:
                    {
                        assert(smre_address_ != 0);
                        /// Because makeVarSymbolic pushes the element on the stack
                        //by default. The undo action for makeVarSymbolic would be
                        // to pop that element and then remove it from symbolic vars
                        // list.
                        void* tos = (void*) pop();
                        assert(tos == smre_address_);
                        undoMakeVarSymbolic (&_symVarList, (uintptr_t) smre_address_);
                    }
                    break;
                case REM_SYMVAR:
                    assert(smre_address_ != 0);
                    undoRemVarSymbolic (&_symVarList, (uintptr_t) smre_address_, (sval_t*) smre_sval_);
                    undoSetGenCount(&_symVarList, (uintptr_t) smre_address_, smre_gencount_);
                    break;
                case MODIFY_SYMVAR:
                    undoSetGenCount (&_symVarList, (uintptr_t) smre_address_, smre_gencount_);
                    undoSetSymValType (&_symVarList, (uintptr_t) smre_address_, (sval_t*) smre_sval_);
                    break;
                case ADD_RECORD:
                    undoAddNewRecord();
                    break;
                case DEL_RECORD:
                    undoDeleteRecord();
                    break;
            }
        }
};

class BranchPoint {
public: 
        /// Unique branch ID
        uint64_t br_bid_;

        /// Jumpbuf used by setjmp and longjmp
        jmp_buf br_jmpbuf_;

        /// Undo record. We can keep only one per branch point
        /// because we will be exploring only one branch of it
        /// at any time.
        /// Undo record maintains the previous value of
        /// the address range between [address, address+size]
        /// E.g., for a statement such as "x = 10", if the value
        /// of x before execution of this statement was 5, then
        /// UndoRecord will maintain [&x, &x + size] = 5
        /// Undo record is used to undo the effect of execution of
        /// a branch when we want to go to other branch of the same
        /// parent.
        UndoRecord br_urec_;

        /// Execution record. 
        /// Execution record maintains the current value
        /// being assigned to address range between [address, address+size]
        /// For the example above, ExecRecord will maintain
        /// [&x, &x+size] = 10
        ///
        /// Exec record is used to setup the correct activation record
        /// of the function when we want to go to some branch point.
        //MARecord br_erec_;
        
        UndoRecord br_symmetarec_;

        /// Pointer to the location where the activation
        /// record of the current function is stored.
        void* br_arp_;
        /// The higher end address of activation record
        void* br_ar_higher_;
        /// The lower end address of activation record
        void* br_ar_lower_;

        /// Pointer to function invocation entry. The link basically
        /// tells us under which function this branch point comes.
        //FuncInvEntry *br_fie_;

        /// Stores the global generation count value at the branch
        /// point so that we can restore it when we return to that
        /// branch point.
        uint64_t br_gcount_;

        /// Pointer to the parent branch point
        /// Mostly used for printing the branch point stack
        BranchPoint* br_parent_;

				/// String to store some information about branch point
				/// Currently we use to store source code file name and line number
				/// for debugging purpose.
				string br_notes_;

        BranchPoint();
        ~BranchPoint();
        void SnapshotStack(void* ar_lower, void* ar_higher);
};

extern uint64_t g_bid;
extern stack<BranchPoint*> g_bpstack;
extern void* stack_bottom;

extern "C" {
    void AddEntryToMemAccessRecord(void* address, uint32_t size, void* contents);
    void AddEntryToSymMetadataAccessRecord (SymMetaDataEntryType etype, 
            void* address, uint64_t gcount, void*);
    int SetupBranchPoint ();
    void GotoNextBranchPoint();
}

#endif /* OBJCOW_H */
