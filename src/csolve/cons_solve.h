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

#ifndef CONS_SOLVE_H
#define CONS_SOLVE_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
//#include <stdio.h>

/************************* configurations macro ************************/
/*
 * Use tryone instead of tryboth to implement semantics of addCons.
 * Using tryone instead of tryboth is faster and more efficient as
 * tryone does not fork and fail in parent. This should be default.
 * We found that it reduces runtime of the system to atleast 1/3 that
 * of tryboth.
 */
#define USE_TRYONE
#define USE_OBJCOW
#define MEASURE
#define COMPACT_PRINT_LOGCS

#ifdef USE_TRYONE
  #ifdef USE_OBJCOW
    #define GOTO_NEXT_BRANCH_IN_USER (gotoNextBranchPointHook())
    #define GOTO_NEXT_BRANCH_IN_BOTH (fail())
  #else
    #define GOTO_NEXT_BRANCH_IN_USER (exit(0))
    #define GOTO_NEXT_BRANCH_IN_BOTH (fail())
  #endif
#else
    #define GOTO_NEXT_BRANCH_IN_USER (exit(0))
    #define GOTO_NEXT_BRANCH_IN_BOTH (fail())
#endif

/************************** Branch point information *******************/
extern char gLoc[128];
#define SET_GLOC \
	(snprintf(gLoc, 128, "%s:%d:%s", __FILE__, __LINE__, __FUNCTION__))

/************************** Logging interface **************************/

extern int logcs, cspid;
extern const char* log_replay;
typedef enum { DEBUG=1, INFO=2, WARN=3, ERROR=4 } log_level_t;
extern log_level_t loglevel;
void mybaseprintf(bool prthdr, log_level_t, const char* format, ...);
void mybasevprintf(bool prthdr, log_level_t ll, const char* format, va_list args);
#define DEBUG_PRINTF(...) (mybaseprintf(true, DEBUG, __VA_ARGS__))
#define INFO_PRINTF(...)  (mybaseprintf(true, INFO,  __VA_ARGS__))
#define INFO_PRINTF_WOHDR(...)  (mybaseprintf(false, INFO,  __VA_ARGS__))
#define WARN_PRINTF(...)  (mybaseprintf(true, WARN,  __VA_ARGS__))
#define ERROR_PRINTF(...) (mybaseprintf(true, ERROR, __VA_ARGS__))
#define DEBUG_VPRINTF(format, args) (mybasevprintf(true, DEBUG, format, args))
#define INFO_VPRINTF(format, args)  (mybasevprintf(true, INFO,  format, args))
#define INFO_VPRINTF_WOHDR(format, args)  (mybasevprintf(false, INFO,  format, args))
#define WARN_VPRINTF(format, args)  (mybasevprintf(true, WARN,  format, args))
#define ERROR_VPRINTF(format, args) (mybasevprintf(true, ERROR, format, args))
void myprintf(const char* format, ...);
void myputc(char c);
void myflush();
void fatal(const char* msg);
void myassert(int);

/**************************** Terms ************************************/
/* Symbolic var ID is unsigned 64-bit integer. */
typedef uint64_t symvar_t;
/* Format specifier to symvar_t */
#define PRIsymvar_t PRIu64

struct TermList;

typedef enum TermType {
   ICONST, CCONST, SCONST, FCONST, VAR, LIST, LISTT, SETT, MAX_TTYPE
} TermType;

typedef struct Term {
   union {
      TermType type_; // Assumption: valid pointer > MAX_TTYPE
      const char* functor_;
   };
   union {
      symvar_t var_;
      int64_t iconst_;
      char cconst_;
      float fconst_;
      const char* sconst_;
      struct TermList* child_; // Used only for lists and functors
   };
} Term;

typedef struct TermList {
   int nchild_;
   Term *child_[];
} TermList;

Term* vt(symvar_t v);
Term* it(int64_t i);
Term* ct(char c);
Term* st(const char* s);
Term* ft(float f);
Term* xtv(const char* fn, TermList *child);
Term* xtl(const char* fn, Term* t1, ...); 
Term* xtlst(TermList *elems); // assumes list tail = nil
Term* xtlsttl(TermList *elems); // last elem is made the tail of list
Term* sett(Term* t1, ...); // set creation

void printTerm(const Term *t);
void printTL(char lb, char rb, const TermList *tl);

/************************ Constraints ******************************/
typedef enum IOp {
   NONE, 
   UMINUS, IOP_ABS, EXP, // No need, defer for now.
   CSPLUS, CSMINUS, CSMULT, CSDIV, CSMOD, CSREM, CSMIN, CSMAX,
   BOR, BAND, BLSHL, BLSHR, MAXIOP} IOp;

typedef enum ConstrOp {
   ILT, ILE, IGT, IGE, IEQ, INE, ICMAX,
   CSEQ, TNE, CSEQ_RANGE, 
	 CSEQ_SET2, CSEQ_SET3, CSEQ_SET4, 
	 CSEQ_SET5, CSEQ_SET6, CSEQ_SET7, 
	 CSEQ_SET8, CSEQ_SET9, CSEQ_SET10,
	 CSEQ_SET11, CSEQ_SET12, CSEQ_SET13, 
   CSEQ_SET14, CSEQ_SET16, 
   CSOR, CSAND, 
   CMAX
} ConstrOp;

struct ConstrList;

typedef struct Constr {
   char op_;
   char cop_;
   char argFlags_;
   symvar_t lhs_;
   union {
      int64_t rhs_[2];
# if __WORDSIZE == 64
      Term *t_[2];
# else
      Term *t_[4];
# endif
      struct ConstrList* clist_;
   };
} Constr;

typedef struct ConstrList {
  int nconstrs_;
  Constr *constrs_[];
} ConstrList;

// The following two functions support all integer constraints,
// but limit it to be of the form <var> <constraint> (<var>|<const>)
Constr* ic1c(symvar_t lhsVar, ConstrOp icop, int64_t rhsConst);
Constr* ic1v(symvar_t lhsVar, ConstrOp icop, symvar_t rhsVar);
// Way to define range constraint over a variable. Only accepts
// assignment of variable to range.
Constr* ic1r(symvar_t lhsVar, ConstrOp icop, int64_t lwr, int64_t upr);
// Way to add set constraint on a variable. Var in Domain1 \/ Domain2
Constr* ic1s(symvar_t lhsVar, ConstrOp icop, Term* t1);

// The following functions support integer expressions on rhs, but constraint
// is implicitly assumed to be equality. 
Constr* ie1v1c(symvar_t lhsVar, IOp iop, symvar_t rhsVar, int64_t rhsConst);
Constr* ie2v(symvar_t lhsVar, IOp iop, symvar_t rhsVar1, symvar_t rhsVar2);

// The following support non-integer constraints (just equality for now)
Constr* tc1t(symvar_t lhsVar, ConstrOp cop, Term* t1);

// The following functions support reification constraints, i.e., lhs is a
// (boolean) variable, and rhs is a constraint. 
Constr* rc1v1c(symvar_t lhsVar, ConstrOp cop, symvar_t rhsVar, int64_t rhsConst);
Constr* rc2v(symvar_t lhsVar,   ConstrOp cop, symvar_t rhsVar1, symvar_t rhsVar2);
Constr* rc1v1t(symvar_t lhsVar, ConstrOp cop, symvar_t rhsVar, Term *t2);

/// Allows creation of disjunction of constraints
Constr* orandConstrs(ConstrOp cop, Constr* c1, Constr* c2, ...);
#define orConstrs(...)  (orandConstrs(CSOR, __VA_ARGS__))
#define andConstrs(...) (orandConstrs(CSAND, __VA_ARGS__))

void  printConstr(const Constr *c);

// ********************* Top-level functions ***************

void initSym();
// Start the execution of the constraint solver.

void begin(); // Must be called to (re)initialize the constraint solver. Sets
// up 0 as input and 1 as output variable. Note that variables are represented
// using integer indices. Thus, the call vt(n) will construct a term that
// represents the variable corresponding to index n.

void addOutput(Term *t); // Appends to the output. t can be an arbitrary term,
// but usually, it is either a string or a variable.

void addCons(Constr* c); // send a constraint to the constraint solver
// Note that there is no return value, so no way to indicate if c turns
// out to be unsatisfiable. So, when in doubt, use only try. Otherwise,
// the constraint solver will lose sync, and terrible things will happen

int64_t getNext(symvar_t var); // Will fork and return once for each possible 
// instantiation of integer-valued variable var. Each return is in a new child
// process. The parent will never return.

int markConsVar(symvar_t var); // Mark that the variable var is under constraints
// which should be printed while printing the rule. This is used to handle
// printing of symbolic operands such as registers and immediates.

int tryboth(Constr* c);
// Constraint solver will try two paths: one in which
// c is true, and another in which nothing is known (i.e., c may or may not 
// hold). The calling process will fork, with the child following the
// first branch, and the parent following the second. Return value same as fork.
//
// If c is unsatisfiable, then there will be no fork, and the
// return value will be 1. Otherwise, the return value is the same as the
// return from fork. When constraint is unsatisfiable, then constraint
// solver has already fail()ed on that path. To maintain sync, only user
// process needs to go to next choice point.

int tryone(Constr* c);
// Similar to tryboth(), but explores only one path, namely,
// the one in which c holds. Consequently, there will be no forking.
// Return value is 0 if c is satisfiable, and 1 if it is not.
// When constraint is unsatisfiable, then constraint
// solver has already fail()ed on that path. To maintain sync, only user
// process needs to go to next choice point.

void backTrack(); // End of an execution path: tells
// constraint solver to store the input-output mapping, and stop exploring
// this path. Calling process will exit. The constraint solver will backtrack
// to produce the next solution for the innermost getNext, and
// the corresponding child process will return.

void fail(); // Fails the current execution path in the constraint solver.
// Calling process exits.

void failres(); // Operates like fail, but explicitly records an 
// invalid mapping

void finish();
// Call when all execution paths have been explored. Outputs the translation
// mapping computed so far.
// MUST BE CALLED BY SAME PROCESS THAT CALLED initSym(). Waits for that process
// to terminate. 

int seqFork(); /* Forks, child returns immediately, parent waits for
child to finish and then returns. Thus, their execution becomes sequential.
Like fork(), returns 0 to child process, and child pid to parent process. */

#endif /* CONS_SOLVE_H */
