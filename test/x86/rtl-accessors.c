
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

#include "rtl-accessors.h"
#include "cons_solve.h"
#include "symVarStack.h"
#include "symVarList.h"
#include "symTypes.h"
#include <stdarg.h>

/* Place to restrict symbolic-to-concrete conversion */
#define RESTRICT_S2C_CONVERSION_TO_SUBSET

#ifdef RESTRICT_S2C_CONVERSION_TO_SUBSET
/* Specify how many modes we want to consider */
  #define MAX_MODE DImode
  #define MAX_REGISTER 17
#else
  #define MAX_MODE MAX_MACHINE_MODE
  /* FIRST_PSEUDO_REGISTER is 53 for x86 */
  #define MAX_REGISTER FIRST_PSEUDO_REGISTER
#endif

/****************************************************
           RTL checking functions
****************************************************/
// The logic of the check is derived from RTL_CHECKC1 from rtl.h
static void RTL_CHECKC1_CONS(const rtx* rtxAddr, unsigned int n, 
    enum rtx_code c) {
    if (IS_SYMBOLIC(rtxAddr)) {
      enum rtx_code code;
      GET_CODE_CONS(rtxAddr, &code);
#ifdef USE_TRYONE
      if(tryone(ic1c(GET_GENCOUNT(&code), IEQ, (int) c)) == 1)
#else
      int ret;
      if((ret = tryboth(ic1c(GET_GENCOUNT(&code), IEQ, (int) c))) > 1)
        fail();
      else if(ret == 1)
#endif
        GOTO_NEXT_BRANCH_IN_USER;
    } else 
      assert((*rtxAddr)->code == c);
}


/****************************************************
           RTL Accessor helper functions
 ***************************************************/

/*
 * This is one of the optimization that we plan to
 * implement in the future. Currently, we have disabled
 * it.
 */
//#define EXPLODE_SYMBOLIC_TO_CONCRETE

static void SET_UNION_U_OF_RTL(uint64_t rtxgc, const Term* ut)
{
    /* Actually we should be using addCons, since this
     * constraint addition must not fail. But to debug
     * failures, we are using assert here. It's fine even
     * if asserts are left here forever. */
#ifdef USE_TRYONE
    if(tryone(tc1t(rtxgc, CSEQ, 
                xtl(RTL_FUNCTOR, ntv(), ntv(), ut, ntv(), 0)))==1)
#else
      int ret;
      if((ret = tryboth(tc1t(rtxgc, CSEQ, 
                xtl(RTL_FUNCTOR, ntv(), ntv(), ut, ntv(), 0)))) > 1)
        fail();
      // If tryboth fails then we must use GOTO_NEXT_BRANCH_IN_USER
      // and should not fail because when tryboth fails, constraint
      // solver has already failed on that path.
      else if(ret == 1)
#endif
        GOTO_NEXT_BRANCH_IN_USER;
}

static void SET_NTH_ELEM_OF_FLD(uint64_t rtxgc, int n, const Term* chlt)
{
    int num = n+2;
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + 
                                        num * sizeof(Term));
    tl->nchild_ = num;
    tl->child_[n] = chlt; tl->child_[n+1] = ntv();
                                       
    int i;                             
    for (i = 0; i < num-2; i++)           
        tl->child_[i] = ntv();          

    SET_UNION_U_OF_RTL(rtxgc, xtl(UNIONU_FUNCTOR, xtlsttl(tl), ntv(), 
          ntv(), ntv(), ntv(), 0));
} 

static void SET_NTH_ELEM_OF_VEC(const rtvec* vecAddr, int n, const Term* elemt)
{
    int num = n+2;
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + 
            num * sizeof(Term));
    tl->nchild_ = num;
    tl->child_[n] = elemt; tl->child_[n+1] = ntv();
    
    int i;               
    for (i = 0; i < num-2; i++)           
        tl->child_[i] = ntv();          
    
#ifdef USE_TRYONE
    if(tryone(tc1t(GET_GENCOUNT(vecAddr), CSEQ, xtlsttl(tl)))==1)
#else
    int ret;
    if((ret = tryboth(tc1t(GET_GENCOUNT(vecAddr), CSEQ, xtlsttl(tl)))) > 1)
      fail();
    else if(ret == 1)
#endif
        GOTO_NEXT_BRANCH_IN_USER;
}

static void SET_NTH_ELEM_OF_HWINT(uint64_t rtxgc, int n, const Term* chlt)
{
    int num = n+2;
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + 
                                        num * sizeof(Term));
    tl->nchild_ = num;
    tl->child_[n] = chlt; tl->child_[n+1] = ntv();
                                       
    int i;                             
    for (i = 0; i < num-2; i++)           
        tl->child_[i] = ntv();          

    SET_UNION_U_OF_RTL(rtxgc, xtl(UNIONU_FUNCTOR, ntv(), xtlsttl(tl), ntv(), 
                                    ntv(), ntv(), 0));
}

static void ENFORCE_ENUM_RANGE_CHECK(uint64_t vargc, int lower, int upper)
{
#ifdef USE_TRYONE
    //if (tryone(ic1c(vargc, IGE, lower)) == 1)
    //  GOTO_NEXT_BRANCH_IN_USER;
    //if (tryone(ic1c(vargc, ILT, upper)) == 1)
    //  GOTO_NEXT_BRANCH_IN_USER;
		if (tryone(ic1r(vargc, CSEQ_RANGE, lower, upper-1)) == 1)
			GOTO_NEXT_BRANCH_IN_USER;
#else
    int ret;
    if ((ret = tryboth(ic1c(vargc, IGE, lower))) > 1)
      fail();
    else if(ret == 1)
      GOTO_NEXT_BRANCH_IN_USER;

    if ((ret = tryboth(ic1c(vargc, ILT, upper))) > 1)
      fail();
    else if (ret == 1)
      GOTO_NEXT_BRANCH_IN_USER;
#endif
}

/****************************************************
           RTL Accessor functions
 ***************************************************/

enum rtx_code GET_CODE (const rtx r) { return 0; }
void GET_CODE_CONS(const rtx* rtxAddr, enum rtx_code* codeAddr)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        SET_SYMBOLIC(codeAddr);
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(rtxAddr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(GET_GENCOUNT(codeAddr)), 
                ntv(), ntv(), ntv(), 0)))==1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(rtxAddr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(GET_GENCOUNT(codeAddr)), 
                ntv(), ntv(), ntv(), 0)))) > 1)
          fail();
        else if(ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
        /* UNKNOWN-1 because UNKNOWN is 0. But we also want our
         * representation of NULL RTX to be valid. NULL RTX code
         * is -1. So valid code values are [-1, LAST_RTX] */
        ENFORCE_ENUM_RANGE_CHECK(GET_GENCOUNT(codeAddr), UNKNOWN-1,
                                 LAST_AND_UNUSED_RTX_CODE);
    } else {
        if (codeAddr && rtxAddr && *rtxAddr)
          *(enum rtx_code*) codeAddr = (*rtxAddr)->code;
				else
					ERROR_PRINTF("[GET_CODE_CONS] rtxAddr or codeAddr is NULL.");
    }
}

enum machine_mode GET_MODE (const rtx r) { return 0; }
void GET_MODE_CONS(const rtx* rtxAddr, enum machine_mode* modeAddr)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        SET_SYMBOLIC(modeAddr); 
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(rtxAddr), CSEQ, 
                xtl(RTL_FUNCTOR, ntv(), vt(GET_GENCOUNT(modeAddr)), 
                 ntv(), ntv(), 0)))==1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(rtxAddr), CSEQ, 
                xtl(RTL_FUNCTOR, ntv(), vt(GET_GENCOUNT(modeAddr)), 
                 ntv(), ntv(), 0)))) > 1)
          fail();
        else if(ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
        ENFORCE_ENUM_RANGE_CHECK(GET_GENCOUNT(modeAddr), VOIDmode,
                                 MAX_MODE);
    } else {
        if (modeAddr)
          *(enum machine_mode*) modeAddr = (*rtxAddr)->mode;
    }
}

rtx XEXP (const rtx r, int n) { return 0; }
void XEXP_CONS(const rtx* rtxAddr, int idx, rtx* xAddr)
{  
    if (IS_SYMBOLIC(rtxAddr)) {
        /* if xaddr is same as rtxAddr then we need to increment
         * generation count of RHS. But before that we need to
         * store generation count of LHS otherwise we will get
         * same value on both LHS and RHS. 
         * E.g., for rtx op = XEXP(op, 0);
         * we want to generate V(10) = rtx(_,_,_,[V(9),_]..) instead of
         * V(9) = rtx(_,_,_,[V(9)],..)
         */
        // So let's first save the current generation count associated with 
        // rtxAddr before SET_SYMBOLIC_.. may increment it.
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        // Now let us make xAddr symbolic.
        struct sval_t sv = {SVAL_TERM, RTL_FUNCTOR};
        SET_SYMBOLIC_WITH_SYMVAL(xAddr, &sv);
        SET_NTH_ELEM_OF_FLD(rtxgc, idx, vt(GET_GENCOUNT(xAddr)));
    } else {
	      if (xAddr)
          *xAddr = (*rtxAddr)->u.fld[idx].rt_rtx;
    }
}

rtx XCEXP (rtx r, int n, enum rtx_code c) { return 0; }
void XCEXP_CONS (const rtx* rtxAddr, int idx, enum rtx_code c, rtx* xAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, idx, c);
    XEXP_CONS(rtxAddr, idx, xAddr);
}

rtx XC2EXP (rtx r, int n, enum rtx_code c1, enum rtx_code c2) { return 0; }
void XC2EXP_CONS (const rtx* rtxAddr, int idx, enum rtx_code c1, enum rtx_code c2, rtx* xAddr)
{
    XEXP_CONS(rtxAddr, idx, xAddr);
}

char* XSTR (rtx r, int n) { return 0; }
void XSTR_CONS(const rtx* rtxAddr, int idx, char** xAddr)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(xAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, idx, vt(GET_GENCOUNT(xAddr)));
    } else {
        if (xAddr) 
          *xAddr = (*rtxAddr)->u.fld[idx].rt_str;
    }
}

char* XCSTR (rtx r, int n, enum rtx_code c) { return 0; }
void XCSTR_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, char** xAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, 0, c);
    XSTR_CONS(rtxAddr, idx, xAddr);
}

int XINT (rtx r, int n) { return 0; }
void XINT_CONS(const rtx* rtxAddr, int idx, int* intAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(intAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, idx, 
            xtl(INT_FUNCTOR, vt(GET_GENCOUNT(intAddr)), 0));
    } else {
        if (intAddr)
          *(int*) intAddr = (*rtxAddr)->u.fld[idx].rt_int;
    }
}

int X0INT (rtx r, int n) { return 0; }
void X0INT_CONS(const rtx* rtxAddr, int idx, int* intAddr) 
{
  XINT_CONS(rtxAddr, idx, intAddr);
}

int XCINT (rtx r, int n, enum rtx_code c) { return 0; }
void XCINT_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, int* intAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, 0, c);
    XINT_CONS(rtxAddr, idx, intAddr);
}

unsigned int XCUINT (const_rtx r, int n, enum rtx_code c) { return 0; }
void XCUINT_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, unsigned int* uintAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        RTL_CHECKC1_CONS(rtxAddr, 0, c);
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(uintAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, idx, 
            xtl(UINT_FUNCTOR, vt(GET_GENCOUNT(uintAddr)), 0));
    } else {
        if (uintAddr)
          *(unsigned int*) uintAddr = (*rtxAddr)->u.fld[idx].rt_uint;
    }
}

unsigned int X0UINT (const_rtx r, int n) { return 0; }
void X0UINT_CONS(const rtx* rtxAddr, int idx, unsigned int* uintAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(uintAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, idx, 
            xtl(UINT_FUNCTOR, vt(GET_GENCOUNT(uintAddr)), 0));
    } else {
        if (uintAddr)
          *(unsigned int*) uintAddr = (*rtxAddr)->u.fld[idx].rt_uint;
    }
}

int REGNO (rtx r) { return 0; }
void REGNO_CONS(const rtx* rtxAddr, unsigned int* regAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        RTL_CHECKC1_CONS(rtxAddr, 0, REG);
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(regAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, 0, 
						xtl(UINT_FUNCTOR, vt(GET_GENCOUNT(regAddr))));
    } else {
        if (regAddr)
          *(unsigned int*) regAddr = (*rtxAddr)->u.fld[0].rt_uint;
    }
}

#if 0
int SUBREG_REG(rtx r) { return 0; }
void SUBREG_REG_CONS(const rtx* rtxAddr, rtx* regAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        struct sval_t sv = {SVAL_TERM, RTL_FUNCTOR};
        SET_SYMBOLIC_WITH_SYMVAL(regAddr, &sv);
        SET_NTH_ELEM_OF_FLD(rtxgc, 0, vt(GET_GENCOUNT(regAddr)));
    } else {
        if (regAddr)
          *(rtx*) regAddr = (*rtxAddr)->u.fld[0].rt_rtx;
    }
}

int SUBREG_BYTE(rtx r) { return 0; }
void SUBREG_BYTE_CONS(const rtx* rtxAddr, unsigned int* byteAddr) 
{
    if(IS_SYMBOLIC(rtxAddr)) {
        SET_SYMBOLIC(byteAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, 1, vt(GET_GENCOUNT(byteAddr)));
    } else {
        if (byteAddr)
          *(unsigned int*) byteAddr = (*rtxAddr)->u.fld[1].rt_uint;
    }
}
#endif

rtvec XVEC(rtx r, int n) { return 0; }
void XVEC_CONS(const rtx* rtxAddr, int n, rtvec* vecAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(vecAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, n, 
            xtl(RTVEC_FUNCTOR, ntv(), vt(GET_GENCOUNT(vecAddr)), 0));
    } else {
        if (vecAddr)
          *(rtvec*) vecAddr = (*rtxAddr)->u.fld[n].rt_rtvec;
    }
}

rtvec XCVEC(rtx r, int n, enum rtx_code c) { return 0; }
void XCVEC_CONS(const rtx* rtxAddr, int n, enum rtx_code c, rtvec* vecAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, n, c);
    XVEC_CONS(rtxAddr, n, vecAddr);
}

rtx XVECEXP(rtx r, int n, int m) { return 0; }
void XVECEXP_CONS(const rtx* rtxAddr, int n, int m, rtx* expAddr) 
{ 
    rtvec vec;
    XVEC_CONS(rtxAddr, n, &vec);
    if (IS_SYMBOLIC(&vec)) {
        SET_SYMBOLIC(expAddr);
        SET_NTH_ELEM_OF_VEC(&vec, m, vt(GET_GENCOUNT(expAddr))); 
    } else {
        if (expAddr)
          *(rtx*) expAddr = vec->elem[m];
    }
}

rtx XCVECEXP(rtx r, int n, int m, enum rtx_code c) { return 0; }
void XCVECEXP_CONS(const rtx* rtxAddr, int n, int m, enum rtx_code c, rtx* expAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, n, c);
    XVECEXP_CONS(rtxAddr, n, m, expAddr);
}

int XVECLEN(rtx r, int n ) { return 0; }
void XVECLEN_CONS(const rtx* rtxAddr, int n, int* lenAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(lenAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, n, 
            xtl(RTVEC_FUNCTOR, vt(GET_GENCOUNT(lenAddr)), ntv(), 0));
    } else {
        if (lenAddr) 
          *(int*) lenAddr = (*rtxAddr)->u.fld[n].rt_rtvec->num_elem;
    }
}

int XCVECLEN(rtx r, int n, enum rtx_code c) { return 0; }
void XCVECLEN_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* lenAddr)
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, n, c);
    XVECLEN_CONS(rtxAddr, n, lenAddr);
}

int XWINT(rtx r, int n) { return 0; }
void XWINT_CONS(const rtx* rtxAddr, int n, int* intAddr)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_SYMBOLIC(intAddr);
        SET_NTH_ELEM_OF_HWINT(rtxgc, n, vt(GET_GENCOUNT(intAddr)));
    } else {
	      if (intAddr)
          *(int*) intAddr = (*rtxAddr)->u.hwint[n];
    }
}

int XCWINT(rtx r, int n, enum rtx_code c) { return 0; }
void XCWINT_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* intAddr) 
{
    if (IS_SYMBOLIC(rtxAddr))
        RTL_CHECKC1_CONS(rtxAddr, n, c);
    XWINT_CONS(rtxAddr, n, intAddr);
}

void XCWINT_S2C_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* intAddr) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        RTL_CHECKC1_CONS(rtxAddr, n, c);
        uint64_t gcount = nv();
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_NTH_ELEM_OF_HWINT(rtxgc, n, vt(gcount));

				if(tryone(ic1c(gcount, IGE, 0)) == 1)
					GOTO_NEXT_BRANCH_IN_USER;
				if(tryone(ic1c(gcount, ILE, INT32_MAX)) == 1)
					GOTO_NEXT_BRANCH_IN_USER;
						
				*intAddr = getNext(gcount);
		} else
	      if (intAddr)
          *(int*) intAddr = (*rtxAddr)->u.hwint[n];
}


//void* X0INT(const rtx, N)      (RTL_CHECK1 (RTX, N, '0').rt_int)
//void* X0UINT(const rtx, N)     (RTL_CHECK1 (RTX, N, '0').rt_uint)

/* Not sure why I wrote CONS functions for _P functions.
 * _P functions are simply predicates built on top of
 * GET_MODE, GET_CODE kind of accessors functions. So
 * we dont need _CONS for _P kind of functions.
 */
//int MEM_P(void* r) { return 0; }
void MEM_P_CONS(const rtx* rtxAddr, int* ret) 
{
    if (IS_SYMBOLIC(rtxAddr)) {
        int code;
        GET_CODE_CONS(rtxAddr, &code);
        if(tryboth(ic1c(GET_GENCOUNT(&code), IEQ, MEM)) == 0)
            *ret = 1;
        else  {
            addCons(ic1c(GET_GENCOUNT(&code), INE, MEM));
            *ret = 0;
        }
    } else
        *ret = ((*rtxAddr)->code == MEM);
}

//int CONST_INT_P(void* r) { return 0; }
void CONST_INT_P_CONS(const rtx* rtxAddr, int* ret)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        int code;
        GET_CODE_CONS(rtxAddr, &code); 
        if(tryboth(ic1c(GET_GENCOUNT(&code), IEQ, CONST_INT)) == 0) 
            *ret = 1;
        else {           
            addCons(ic1c(GET_GENCOUNT(&code), INE, CONST_INT));
            *ret = 0;
        }
    } else
        *ret = ((*rtxAddr)->code == CONST_INT);
}

//int REG_P(void* r) { return 0; }
void REG_P_CONS(const rtx* rtxAddr, int* ret)
{
    if (IS_SYMBOLIC(rtxAddr)) {
        int code;
        GET_CODE_CONS(rtxAddr, &code);
        if(tryboth(ic1c(GET_GENCOUNT(&code), IEQ, REG)) == 0) 
            *ret = 1;
        else {
            addCons(ic1c(GET_GENCOUNT(&code), INE, REG));
            *ret = 0; 
        }
    } else
        *ret = ((*rtxAddr)->code == REG);
}

/*
void* PUT_CODE_CONS(const rtx, Code) (GET_CODE_CONS(rtx, Code))
void* PUT_MODE_CONS(const rtx, Mode) (GET_MODE_CONS(rtx, Mode))
void* GET_NUM_ELEM_CONS(rtvec)
void* RTVEC_ELT_CONS(rtvec, i)
void* RTL_CHECK1_CONS(const rtx, n, c1) (addCons(tc1t(rtx, EQ, xtl("rtl", ntv(), ntv(), xtn("list", n+1, 0), ntv(), 0))))
void* RTL_CHECK2_CONS(const rtx, n, c1, c2) (RTL_CHECK1_CONS(rtx, n, c1))
void* RTL_CHECKC1_CONS(const rtx, n, c1) (RTL_CHECK1_CONS(rtx, n, c1))
void* RTL_CHECKC2_CONS(const rtx, n, c1, c2) (RTL_CHECK2_CONS(rtx, n, c1, c2))
void* XWINT_CONS(const rtx, n, Wint) (addCons(tc1t(rtx, EQ, xtl("rtl", ntv(), ntv(), xtn("list", n+1, Wint, 0), ntv(), 0))))
void* XCWINT_CONS(const rtx, n, c, Wint) (XWINT_CONS(rtx, n, Wint))
void* XCMWINT_CONS(const rtx, n, c, m, Wint) (XWINT_CONS(rtx, n, Wint))
void* XCNMWINT_CONS(const rtx, n, c, m, Wint) (XWINT_CONS(rtx, n, Wint))
*/

#define MATCH_EQV_CLASS(gc, lwr, upr, lhs, class) do {\
				if (tryboth(ic1c(gc, IGE, lwr)) == 0) { \
					if (tryboth(ic1c(gc, ILE, upr)) == 0) { \
						lhs = class; \
						goto out; \
					} else { \
						if (tryone(ic1c(gc, IGT, upr)) == 1) \
							GOTO_NEXT_BRANCH_IN_USER; \
					} \
				} else {  \
					if (tryone(ic1c(gc, ILT, lwr)) == 1) \
						GOTO_NEXT_BRANCH_IN_USER; \
				} \
} while(0) 

#define EQCLASS_BASED_SYMBOLIC_TO_CONCRETE 1
//#define EXPLODE_SYMBOLIC_TO_CONCRETE
//#define ONETOONE_SYMBOLIC_TO_CONCRETE 1

void GET_MODE_CLASS_CONS(const void* modeAddr, enum mode_class* mclass)
{  
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If mode is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */                            
    if (IS_SYMBOLIC(modeAddr)) { 
#ifdef EXPLODE_SYMBOLIC_TO_CONCRETE
        /* Let us first add constraint on mode.
         * Since value of mode is used as an
         * index in mode_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(modeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,
                     MAX_MODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1)
          fail();
        else if(ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,
                     MAX_MODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *mclass = mode_class[getNext(gcount)];
#elif ONETOONE_SYMBOLIC_TO_CONCRETE == 1
        SET_SYMBOLIC(mclass);
#elif EQCLASS_BASED_SYMBOLIC_TO_CONCRETE == 1
        uint64_t gcount = GET_GENCOUNT(modeAddr);
				SET_GLOC;
				int ret = 0;

			MATCH_EQV_CLASS(gcount, VOIDmode, BLKmode,  *mclass, MODE_RANDOM);
			MATCH_EQV_CLASS(gcount, CCmode,   CCFPUmode,*mclass, MODE_CC);
			MATCH_EQV_CLASS(gcount, BImode,   OImode,   *mclass, MODE_INT);

#ifndef RESTRICT_S2C_CONVERSION_TO_SUBSET
			MATCH_EQV_CLASS(gcount, QQmode,   TQmode,   *mclass, MODE_FRACT);
			MATCH_EQV_CLASS(gcount, UQQmode,  UTQmode,  *mclass, MODE_UFRACT);
			MATCH_EQV_CLASS(gcount, HAmode,   TAmode,   *mclass, MODE_ACCUM);
			MATCH_EQV_CLASS(gcount, UHAmode,  UTAmode,  *mclass, MODE_UACCUM);
			MATCH_EQV_CLASS(gcount, SFmode,   TFmode,   *mclass, MODE_FLOAT);
			MATCH_EQV_CLASS(gcount, SDmode,   TDmode,   *mclass, MODE_DECIMAL_FLOAT);
			MATCH_EQV_CLASS(gcount, CQImode,  COImode,  *mclass, MODE_COMPLEX_INT);
			MATCH_EQV_CLASS(gcount, SCmode,   TCmode,   *mclass, MODE_COMPLEX_FLOAT);
			MATCH_EQV_CLASS(gcount, V2QImode, V4TImode, *mclass, MODE_VECTOR_INT);
			MATCH_EQV_CLASS(gcount, V2SFmode, V4TFmode, *mclass, MODE_VECTOR_FLOAT);
#endif
	
			// we have matched all possible values for modes. So fail() now.
			fail();
#endif
    } else                                      
        *mclass = mode_class[*(enum machine_mode*) modeAddr];
out:
		return;
}



/*
 * This is a wrapper written on top of GET_MODE_CLASS to
 * optimize symbolic-to-concrete execution.
 */
#if 0
void GET_MODE_CLASS_NOT_MODE(const void* modeAddr, const enum mode_class* mclass, 
		int* res)
{
		assert(!IS_SYMBOLIC(mclass));
		if (IS_SYMBOLIC(modeAddr)) {
			switch (*mclass) {
				case MODE_INT:
				case MODE_PARTIAL_INT:
				case MODE_COMPLEX_FLOAT:
				case MODE_COMPLEX_INT:
			}
		} else {
			return (*mclass == mode_class[*(enum machine_mode*) modeAddr);
		}
}
#endif

void GET_MODE_SIZE_CONS(const void* modeAddr, unsigned char* msize)
{
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If mode is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */                            
    if (IS_SYMBOLIC(modeAddr)) {
#ifdef EXPLODE_SYMBOLIC_TO_CONCRETE
        /* Let us first add constraint on mode.
         * Since value of mode is used as an
         * index in mode_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(modeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, VOIDmode)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,               
                     MAX_MODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, VOIDmode))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,               
                     MAX_MODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *msize = mode_size[getNext(gcount)];
#elif ONETOONE_SYMBOLIC_TO_CONCRETE == 1
        SET_SYMBOLIC(msize);
#elif EQCLASS_BASED_SYMBOLIC_TO_CONCRETE == 1
        uint64_t gcount = GET_GENCOUNT(modeAddr);
				SET_GLOC;

        if (tryone(ic1c(gcount, IGE, VOIDmode)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT, MAX_MODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;

			MATCH_EQV_CLASS(gcount, VOIDmode,  BLKmode,   *msize, 0);
			MATCH_EQV_CLASS(gcount, CCmode,    CCFPUmode, *msize, 4);
			//MATCH_EQV_CLASS(gcount, V4QImode,  V1SImode,  *msize, 4);
			//MATCH_EQV_CLASS(gcount, V8QImode,  V1DImode,  *msize, 8);
			//MATCH_EQV_CLASS(gcount, V16QImode, V1TImode,  *msize, 16);
			//MATCH_EQV_CLASS(gcount, V32QImode, V2TImode,  *msize, 32);
			//MATCH_EQV_CLASS(gcount, V64QImode, V4TImode,  *msize, 64);
			//MATCH_EQV_CLASS(gcount, V8SFmode,  V2TFmode,  *msize, 32);
			//MATCH_EQV_CLASS(gcount, V16SFmode, V4TFmode,  *msize, 64);

    #ifndef RESTRICT_S2C_CONVERSION_TO_SUBSET

    			// Introduce set constraints.
    			Term* msize1 = sett(it(BImode), it(QImode), it(QQmode), it(UQQmode), 0);
    			if (tryboth(ic1s(gcount, CSEQ_SET4, msize1)) == 0) {
    				*msize = 1;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, BImode)) == 1 ||
    						tryone(ic1c(gcount, INE, QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, QQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UQQmode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize2 = sett(it(HImode), it(HQmode), it(UHQmode), 
    												  it(HAmode), it(UHAmode), it(CQImode), 
    													it(V2QImode), 0);
    			if (tryboth(ic1s(gcount, CSEQ_SET7, msize2)) == 0) {
    				*msize = 2;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, HQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UHQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, HAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UHAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, CQImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2QImode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize4 = sett(it(SImode), it(SQmode), it(USQmode), 
    													it(SAmode), it(USAmode), it(SFmode),
    												  it(SDmode), it(CHImode), it(V4QImode),
    													it(V2HImode), it(V1SImode), 
    													0);
    			if (tryboth(ic1s(gcount, CSEQ_SET11, msize4)) == 0) {
    				*msize = 4;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, SImode)) == 1 ||
    						tryone(ic1c(gcount, INE, SQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, USQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, SAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, USAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, SFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, SDmode)) == 1 ||
    						tryone(ic1c(gcount, INE, CHImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V1SImode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize8 = sett(it(DImode), it(DQmode), it(UDQmode), 
    													it(DAmode), it(UDAmode), it(DFmode),
    													it(DDmode), it(CSImode), it(SCmode),
    													it(V8QImode), it(V4HImode), it(V2SImode),
    													it(V1DImode), it(V2SFmode),
    													0);
    			if (tryboth(ic1s(gcount, CSEQ_SET14, msize8)) == 0) {
    				*msize = 8;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, DImode)) == 1 ||
    						tryone(ic1c(gcount, INE, DQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UDQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, DAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UDAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, DFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, DDmode)) == 1 ||
    						tryone(ic1c(gcount, INE, CSImode)) == 1 ||
    						tryone(ic1c(gcount, INE, SCmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V8QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2SImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V1DImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2SFmode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize16 = sett(it(TImode), it(TQmode), it(UTQmode), 
    													it(TAmode), it(UTAmode), it(TFmode),
    													it(TDmode), it(CDImode), it(DCmode),
    													it(V16QImode), it(V8HImode), it(V4SImode),
    													it(V2DImode), it(V1TImode), it(V4SFmode),
    													it(V2DFmode),
    													0);
    			if (tryboth(ic1s(gcount, CSEQ_SET16, msize16)) == 0) {
    				*msize = 16;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, TImode)) == 1 ||
    						tryone(ic1c(gcount, INE, TQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UTQmode)) == 1 ||
    						tryone(ic1c(gcount, INE, TAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, UTAmode)) == 1 ||
    						tryone(ic1c(gcount, INE, TFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, TDmode)) == 1 ||
    						tryone(ic1c(gcount, INE, CDImode)) == 1 ||
    						tryone(ic1c(gcount, INE, DCmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V16QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V8HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4SImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2DImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V1TImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4SFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2DFmode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize32 = sett(it(OImode), it(CTImode), it(TCmode), 
    													 it(V8SFmode), it(V4DFmode), it(V2TFmode),
    													 it(V32QImode), it(V16HImode), it(V8SImode),
    													 it(V4DImode), it(V2TImode),
    													 0);
    			if (tryboth(ic1s(gcount, CSEQ_SET11, msize32)) == 0) {
    				*msize = 32;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, OImode)) == 1 ||
    						tryone(ic1c(gcount, INE, CTImode)) == 1 ||
    						tryone(ic1c(gcount, INE, TCmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V8SFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4DFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2TFmode)) == 1 ||
    						tryone(ic1c(gcount, INE, V32QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V16HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V8SImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4DImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V2TImode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}

    			Term* msize64 = sett(it(COImode), it(V64QImode), it(V32HImode), 
    													 it(V16SImode), it(V8DImode), it(V4TImode),
    													 it(V16SFmode), it(V8DFmode), it(V4TFmode),
    													 0);
    			if (tryboth(ic1s(gcount, CSEQ_SET9, msize64)) == 0) {
    				*msize = 64;
    				goto out;
    			} else {
    				if (tryone(ic1c(gcount, INE, COImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V64QImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V32HImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V16SImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V8DImode)) == 1 ||
    						tryone(ic1c(gcount, INE, V4TImode)) == 1 || 
    						tryone(ic1c(gcount, INE, V16SFmode)) == 1 || 
    						tryone(ic1c(gcount, INE, V8DFmode)) == 1 || 
    						tryone(ic1c(gcount, INE, V4TFmode)) == 1)
    					GOTO_NEXT_BRANCH_IN_USER;
    			}
    #endif
      // we CONSIDER_ALL_MODES is not defined, we rely on getNext
      // because we have few modes in such case.

			// otherwise, enumerate
      *msize = mode_size[getNext(gcount)];
#endif
    } else                                      
        *msize = mode_size[*(enum machine_mode*) modeAddr];
out:
		return;
}

//#define EQCLASS_BASED_SYMBOLIC_TO_CONCRETE 1
//#define EXPLODE_SYMBOLIC_TO_CONCRETE

void GET_MODE_NUNITS_CONS(const void* modeAddr, unsigned char* mnunits)
{  
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If mode is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */                            
    if (IS_SYMBOLIC(modeAddr)) { 
#ifdef EXPLODE_SYMBOLIC_TO_CONCRETE
        /* Let us first add constraint on mode.
         * Since value of mode is used as an
         * index in mode_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(modeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,
                     MAX_MODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, VOIDmode))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,
                     MAX_MODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *mnunits = mode_nunits[getNext(gcount)];
#elif ONETOONE_SYMBOLIC_TO_CONCRETE == 1
        SET_SYMBOLIC(mnunits);
#elif EQCLASS_BASED_SYMBOLIC_TO_CONCRETE == 1
        uint64_t gcount = GET_GENCOUNT(modeAddr);
				SET_GLOC;

        if (tryone(ic1c(gcount, IGE, VOIDmode)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,
                     MAX_MODE)) == 1)

				MATCH_EQV_CLASS(gcount, VOIDmode, BLKmode,  *mnunits, 0);
#ifdef RESTRICT_S2C_CONVERSION_TO_SUBSET
        MATCH_EQV_CLASS(gcount, CCmode,   OImode,   *mnunits, 1);
#else
				MATCH_EQV_CLASS(gcount, CCmode,   TDmode,   *mnunits, 1);
				MATCH_EQV_CLASS(gcount, CQImode,  V2QImode, *mnunits, 2);

			  Term* munit1tl = sett(it(V1SImode), it(V1DImode), it(V1TImode), 
													 0);
				if (tryboth(ic1s(gcount, CSEQ_SET3, munit1tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V1SImode)) == 1 ||
							tryone(ic1c(gcount, INE, V1DImode)) == 1 ||
							tryone(ic1c(gcount, INE, V1TImode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}
			  
				Term* munit2tl = sett(it(V2HImode), it(V2SImode), it(V2DImode), 
															it(V2TImode), it(V2SFmode), it(V2TFmode),
													 0);
				if (tryboth(ic1s(gcount, CSEQ_SET6, munit2tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V2HImode)) == 1 ||
							tryone(ic1c(gcount, INE, V2SImode)) == 1 ||
							tryone(ic1c(gcount, INE, V2DImode)) == 1 ||
							tryone(ic1c(gcount, INE, V2TImode)) == 1 ||
							tryone(ic1c(gcount, INE, V2SFmode)) == 1 ||
							tryone(ic1c(gcount, INE, V2TFmode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}

				Term* munit4tl = sett(it(V4QImode), it(V4HImode), it(V4SImode), 
															it(V4DImode), it(V4TImode), it(V4SFmode),
															it(V4DFmode), it(V4TFmode),
													 0);
				if (tryboth(ic1s(gcount, CSEQ_SET8, munit4tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V4QImode)) == 1 ||
							tryone(ic1c(gcount, INE, V4HImode)) == 1 ||
							tryone(ic1c(gcount, INE, V4SImode)) == 1 ||
							tryone(ic1c(gcount, INE, V4DImode)) == 1 ||
							tryone(ic1c(gcount, INE, V4TImode)) == 1 ||
							tryone(ic1c(gcount, INE, V4SFmode)) == 1 ||
							tryone(ic1c(gcount, INE, V4DFmode)) == 1 ||
							tryone(ic1c(gcount, INE, V4TFmode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}
				
				Term* munit8tl = sett(it(V8QImode), it(V8HImode), it(V8SImode), 
															it(V8DImode), it(V8SFmode), it(V8DFmode), 
													 0);
				if (tryboth(ic1s(gcount, CSEQ_SET6, munit8tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V8QImode)) == 1 ||
							tryone(ic1c(gcount, INE, V8HImode)) == 1 ||
							tryone(ic1c(gcount, INE, V8SImode)) == 1 ||
							tryone(ic1c(gcount, INE, V8DImode)) == 1 ||
							tryone(ic1c(gcount, INE, V8SFmode)) == 1 ||
							tryone(ic1c(gcount, INE, V8DFmode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}

				Term* munit16tl = sett(it(V16QImode), it(V16HImode), it(V16SImode), 
															it(V16SFmode), 0);
				if (tryboth(ic1s(gcount, CSEQ_SET4, munit16tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V16QImode)) == 1 ||
							tryone(ic1c(gcount, INE, V16HImode)) == 1 ||
							tryone(ic1c(gcount, INE, V16SImode)) == 1 ||
							tryone(ic1c(gcount, INE, V16SFmode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}

				Term* munit32tl = sett(it(V32QImode), it(V32HImode), 0);
				if (tryboth(ic1s(gcount, CSEQ_SET2, munit32tl)) == 0) {
					*mnunits = 1;
					goto out;
				} else {
					if (tryone(ic1c(gcount, INE, V32QImode)) == 1 ||
							tryone(ic1c(gcount, INE, V32HImode)) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				}
#endif
				// otherwise enumerate		
        *mnunits = mode_nunits[getNext(gcount)];
#endif
    } else                                      
        *mnunits = mode_nunits[*(enum machine_mode*) modeAddr];
out:
		return;
}

void CONST0_RTX_CONS(const void* modeAddr, rtx* rtxAddr)
{  
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If mode is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */                            
    if (IS_SYMBOLIC(modeAddr)) { 
        /* Let us first add constraint on mode.
         * Since value of mode is used as an
         * index in mode_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(modeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,
                     MAX_MODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else 
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,
                     MAX_MODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *rtxAddr = const_tiny_rtx[0][getNext(gcount)];
    } else                                      
        *rtxAddr = const_tiny_rtx[0][*(enum machine_mode*) modeAddr];
}

int REGNO_S2C (rtx r) { return 0; }
void REGNO_S2C_CONS(const rtx* rtxAddr, unsigned int* regAddr) 
#if 0
void REGNO_TO_INT_CONS(const rtx* rtxAddr, unsigned int* regAddr) 
#endif
{
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If regno is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */
    DEBUG_PRINTF("%d:%s:%s:%d", getpid(), __FILE__, __func__, __LINE__);
    if (IS_SYMBOLIC(rtxAddr)) {
        uint64_t gcount = nv();
        /* Refer to comment at XEXP_CONS */
        uint64_t rtxgc = GET_GENCOUNT(rtxAddr);
        SET_NTH_ELEM_OF_FLD(rtxgc, 0,
            xtl(UINT_FUNCTOR, vt(gcount), 0));
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)        
          GOTO_NEXT_BRANCH_IN_USER;
        /* FIRST_PSEUDO_REGISTER is 53 for i386 */ 
        //if (tryone(ic1c(gcount, ILT, MAX_REGISTER)) == 1)        
        //  GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT, 8)) == 1)        
          GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1)        
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        /* FIRST_PSEUDO_REGISTER is 53 for i386 */ 
        if ((ret = tryboth(ic1c(gcount, ILT, MAX_REGISTER))) > 1)
          fail();
        else if (ret == 1);
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *(unsigned int*) regAddr = (unsigned int) getNext(gcount); 
    } else                                        
        *(unsigned int*) regAddr = (*rtxAddr)->u.fld[0].rt_uint;
}

void REGNO_REG_CLASS_CONS(const void* regnoAddr, enum reg_class* regclass) 
{
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If regno is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */
    if (IS_SYMBOLIC(regnoAddr)) {
#ifdef EXPLODE_SYMBOLIC_TO_CONCRETE
        /* Let us first add constraint on regno.
         * Since value of regno is used as an
         * index in regclass_map array, that index
         * must be within the range of 0 and
         * max possible index. */
        uint64_t gcount = GET_GENCOUNT(regnoAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)        
            GOTO_NEXT_BRANCH_IN_USER;
        /* FIRST_PSEUDO_REGISTER is 53 for i386 */ 
        if (tryone(ic1c(gcount, ILT, MAX_REGISTER)) == 1)        
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        /* FIRST_PSEUDO_REGISTER is 53 for i386 */ 
        if ((ret = tryboth(ic1c(gcount, ILT, MAX_REGISTER))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
#ifdef x86
				SET_GLOC;
        *regclass = regclass_map[getNext(gcount)]; 
#elif spim
				*regclass = regno_reg_class(*(int*)regnoAddr);
#endif
#elif EQCLASS_BASED_SYMBOLIC_TO_CONCRETE == 1
        uint64_t gcount = GET_GENCOUNT(regnoAddr);
				SET_GLOC;
        
				if (tryone(ic1c(gcount, IGE, 0)) == 1)        
            GOTO_NEXT_BRANCH_IN_USER;
        /* FIRST_PSEUDO_REGISTER is 53 for i386 */ 
        if (tryone(ic1c(gcount, ILT, MAX_REGISTER)) == 1)        
            GOTO_NEXT_BRANCH_IN_USER;

#ifndef RESTRICT_S2C_CONVERSION_TO_SUBSET
				MATCH_EQV_CLASS(gcount, 22, 28,  *regclass, SSE_REGS);
				MATCH_EQV_CLASS(gcount, 29, 36,  *regclass, MMX_REGS);
				MATCH_EQV_CLASS(gcount, 37, 44,  *regclass, NON_Q_REGS);
				MATCH_EQV_CLASS(gcount, 45, 52,  *regclass, SSE_REGS);
#endif

				// else enumerate	
        *regclass = regclass_map[getNext(gcount)]; 
#elif ONETOONE_SYMBOLIC_TO_CONCRETE == 1
        SET_SYMBOLIC(regclass);
#endif
    } else {
#ifdef x86
        *regclass = regclass_map[*(int*) regnoAddr];
#elif spim
				/* TODO: */
				*regclass = regno_reg_class(*(int*)regnoAddr);
#endif
		}
out:
		return;
}  

void GET_RTX_CLASS_CONS(const void* codeAddr, enum rtx_class* rclass)
{
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If code is symbolic, then we have a case of
     * explosion, otherwise we just do concrete
     * execution. */
    if (IS_SYMBOLIC(codeAddr)) {                 
#ifdef EXPLODE_SYMBOLIC_TO_CONCRETE
        /* Let us first add constraint on code.
         * Since value of code is used as an
         * index in rtx_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(codeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1) 
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,               
                     LAST_AND_UNUSED_RTX_CODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1) 
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,               
                     LAST_AND_UNUSED_RTX_CODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *rclass = rtx_class[getNext(gcount)];
#elif EQCLASS_BASED_SYMBOLIC_TO_CONCRETE == 1
        uint64_t gcount = GET_GENCOUNT(codeAddr);
				SET_GLOC;

        if (tryone(ic1c(gcount, IGE, 0)) == 1) 
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,               
                     LAST_AND_UNUSED_RTX_CODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;

				MATCH_EQV_CLASS(gcount, DEBUG_INSN,    CALL_INSN,   *rclass, RTX_INSN);
				MATCH_EQV_CLASS(gcount, BARRIER,       TRAP_IF,     *rclass, RTX_EXTRA);
				MATCH_EQV_CLASS(gcount, CONST_INT,     CONST_VECTOR,*rclass, RTX_CONST_OBJ);
				MATCH_EQV_CLASS(gcount, MULT,          US_MULT,     *rclass, RTX_COMM_ARITH);
				MATCH_EQV_CLASS(gcount, DIV,           UMOD,        *rclass, RTX_BIN_ARITH);
				MATCH_EQV_CLASS(gcount, AND,           XOR,         *rclass, RTX_COMM_ARITH);
				MATCH_EQV_CLASS(gcount, ASHIFT,        ROTATERT,    *rclass, RTX_BIN_ARITH);
				MATCH_EQV_CLASS(gcount, SMIN,          UMAX,        *rclass, RTX_COMM_ARITH);
				MATCH_EQV_CLASS(gcount, PRE_DEC,       POST_MODIFY, *rclass, RTX_AUTOINC);
				MATCH_EQV_CLASS(gcount, UNORDERED,     UNEQ,        *rclass, RTX_COMM_COMPARE);
				MATCH_EQV_CLASS(gcount, GE,            LTU,         *rclass, RTX_COMPARE);
				MATCH_EQV_CLASS(gcount, UNGE,          UNLT,        *rclass, RTX_COMPARE);
				MATCH_EQV_CLASS(gcount, SS_NEG,        SS_ABS,      *rclass, RTX_UNARY);
				MATCH_EQV_CLASS(gcount, SIGN_EXTEND,   PARITY,      *rclass, RTX_UNARY);
				MATCH_EQV_CLASS(gcount, SS_ASHIFT,      US_MINUS,    *rclass, RTX_BIN_ARITH);
				//MATCH_EQV_CLASS(gcount, MATCH_OPERAND, MATCH_TEST,  *rclass, RTX_MATCH);
				//MATCH_EQV_CLASS(gcount, DEFINE_INSN,   COND,        *rclass, RTX_EXTRA);
				/*MATCH_EQV_CLASS(gcount, , ,  *rclass, RTX_);
				MATCH_EQV_CLASS(gcount, , ,  *rclass, RTX_);*/
				
				// otherwise enumerate
        *rclass = rtx_class[getNext(gcount)];

#elif ONETOONE_SYMBOLIC_TO_CONCRETE == 1
        SET_SYMBOLIC(rclass);
#endif
    } else    
        *rclass = rtx_class[*(int*) codeAddr];

out: return;
}

void GET_RTX_FORMAT_CONS(const void* codeAddr, char** rformat) 
{
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If code is symbolic, then we have a case of  
     * explosion, otherwise we just do concrete
     * execution. */                            
    if (IS_SYMBOLIC(codeAddr)) {
        /* Let us first add constraint on code.
         * Since value of code is used as an
         * index in rtx_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(codeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,      
                     LAST_AND_UNUSED_RTX_CODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,      
                     LAST_AND_UNUSED_RTX_CODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *rformat = (char*) rtx_format[getNext(gcount)];   
    } else { 
        *rformat = (char*) rtx_format[*(enum rtx_code*) codeAddr]; 
        DEBUG_PRINTF("In GET_RTX_FORMAT_CONS: %d %s", *(enum rtx_code*) codeAddr, *rformat);
    }
}  

void GET_RTX_LENGTH_CONS(const void* codeAddr, int* rlength)
{  
     DEBUG_PRINTF("In %s: ", __FUNCTION__);
    /* If code is symbolic, then we have a case of
     * explosion, otherwise we just do concrete
     * execution. */
    if (IS_SYMBOLIC(codeAddr)) {                 
        /* Let us first add constraint on code.
         * Since value of code is used as an
         * index in rtx_class array, that index
         * must be within the range of 0 and
         * max possible index. */               
        uint64_t gcount = GET_GENCOUNT(codeAddr);
#ifdef USE_TRYONE
        if (tryone(ic1c(gcount, IGE, 0)) == 1) 
            GOTO_NEXT_BRANCH_IN_USER;
        if (tryone(ic1c(gcount, ILT,
                     LAST_AND_UNUSED_RTX_CODE)) == 1)
            GOTO_NEXT_BRANCH_IN_USER;
#else
        int ret;
        if ((ret = tryboth(ic1c(gcount, IGE, 0))) > 1) 
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;

        if ((ret = tryboth(ic1c(gcount, ILT,
                     LAST_AND_UNUSED_RTX_CODE))) > 1)
          fail();
        else if (ret == 1)
          GOTO_NEXT_BRANCH_IN_USER;
#endif
				SET_GLOC;
        *rlength = (int) rtx_length[getNext(gcount)];
    } else  
        *rlength = (int) rtx_length[*(enum machine_mode*) codeAddr];
}

/******************************************
 * Accessor functions for rtl instruction
 ******************************************/
void SET_NTH_FIELD_OF_INSN(const rtx* insnAddr, int n, const Term* fldt)
{
    /* Though rtl insn has 7 fields: uid, prev_insn, next_insn,
     * insn_locator, pat, code, notes, we only need pattern and codefield. So
     * instead of using 7, we will only consider 2 field.
     */ 
    // int num = 7;
    int num = 2;
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + 
            num * sizeof(Term));                             
    tl->nchild_ = num;  tl->child_[n] = fldt;  

    int i;                                   
    for (i = 0; i < num; i++) {
        if (i == n)
            tl->child_[n] = fldt;
        else
            tl->child_[i] = ntv();
    }
                                                           
#ifdef USE_TRYONE
    if(tryone(tc1t(GET_GENCOUNT(insnAddr),                      
                CSEQ, xtv(INSN_FUNCTOR, tl))) == 1)
#else
    int ret;
    if((ret = tryboth(tc1t(GET_GENCOUNT(insnAddr),                      
                CSEQ, xtv(INSN_FUNCTOR, tl)))) > 1)
      fail();
    else if (ret == 1)
#endif
        GOTO_NEXT_BRANCH_IN_USER;
} 

//void* PATTERN(INSN)   XEXP (INSN, 5)
void PATTERN_CONS(const rtx* insnAddr, void* patAddr)
{
    if (IS_SYMBOLIC(insnAddr)) {
        struct sval_t sv = {SVAL_TERM, INSN_FUNCTOR};
        SET_SYMBOLIC_WITH_SYMVAL(patAddr, &sv);
        //SET_NTH_FIELD_OF_INSN(insnAddr, 5, vt(GET_GENCOUNT(patAddr)));
        SET_NTH_FIELD_OF_INSN(insnAddr, 1, vt(GET_GENCOUNT(patAddr)));
    } else 
        *(rtx*) patAddr = (*insnAddr)->u.fld[5].rt_rtx;
}

//void* INSN_CODE(INSN) XINT(INSN, 6)
void INSN_CODE_CONS(const rtx* insnAddr, void* codeAddr)
{
    if (IS_SYMBOLIC(insnAddr)) {
        SET_SYMBOLIC(codeAddr);
        //SET_NTH_FIELD_OF_INSN(insnAddr, 6, vt(GET_GENCOUNT(codeAddr)));
        SET_NTH_FIELD_OF_INSN(insnAddr, 2, vt(GET_GENCOUNT(codeAddr)));
    } else 
        *(int*) codeAddr = (*insnAddr)->u.fld[6].rt_int;
}


void PUT_INSN_CODE_CONS(rtx* insnAddr, void* codeAddr)
{
    if (IS_SYMBOLIC(insnAddr)) {
        if (IS_SYMBOLIC(codeAddr))
            // SET_NTH_FIELD_OF_INSN(insnAddr, 6, vt(GET_GENCOUNT(codeAddr)));
            SET_NTH_FIELD_OF_INSN(insnAddr, 2, vt(GET_GENCOUNT(codeAddr)));
        else
            // SET_NTH_FIELD_OF_INSN(insnAddr, 6, it(*(int*)codeAddr));
            SET_NTH_FIELD_OF_INSN(insnAddr, 2, it(*(int*)codeAddr));

    } else 
        (*insnAddr)->u.fld[6].rt_int = *(int*) codeAddr;
}

int MARK_CONSTRAINT_VAR(const rtx x) {return 0;}
int MARK_CONSTRAINT_VAR_CONS(const rtx* rtxAddr) {
  static char buf[64];
  if (IS_SYMBOLIC(rtxAddr)) {
    memset(buf, 0, 64);
    //snprintf(buf, 64, "Q_%d", GET_GENCOUNT(rtxAddr));
    //addOutput(st(buf));
    addOutput(vt(GET_GENCOUNT(rtxAddr)));
    markConsVar(GET_GENCOUNT(rtxAddr));
  }
}
/******************************************************
       Accessor functions for arrays and structures
 *****************************************************/

/*
 * Array accessor:
 *
 * For statement like,
 * x = a[i];
 *
 * We convert it into 
 * GET_ELEM(A, N, i, X);
 *
 * where N is number of elements in 'a'.
 * If 'N' is 0, then it means the number of elements are
 * not known. The assumption here is that 'i' is concrete, 
 * and X is a term.
 */
void GET_ELEM_CONS (const void* arrAddr, unsigned int n, unsigned int i, const void* xAddr)
{
    SET_SYMBOLIC(xAddr);
    struct sval_t sv = {SVAL_TERM, RTL_FUNCTOR};
    SET_SYMVAL_TYPE(xAddr, &sv);

    /* Array length is not known */
    if(n == 0) {                                        
        TermList* tl = (TermList*) xmalloc (sizeof(TermList)+ ((i + 2) *
               sizeof(Term)));
        tl->nchild_ = i+2; tl->child_[i] = vt(GET_GENCOUNT(xAddr));
        tl->child_[i+1] = ntv();
                     
        int j;
        for (j = 0; j < i; j++)
            tl->child_[j] = ntv();
                                           
        /* List with variable tail */                                        
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlsttl(tl))) == 1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlsttl(tl)))) > 1)
          fail();
        else if (ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
    } else {
      /* Array length is known */
        assert(i <= n);                                        
        TermList* tl = (TermList*) xmalloc (sizeof(TermList) + (n *
              sizeof(Term)));
        tl->nchild_ = n; tl->child_[i] = vt(GET_GENCOUNT(xAddr));
                                                                             
        int j;                                                               
        for (j = 0; j < n; j++)                                            
            if (j != i)                                                    
                tl->child_[j] = ntv();                                       
                                                                             
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlst(tl))) == 1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlst(tl)))) > 1)
          fail();
        else if (ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
    }                                                        
}

/*
 * For statement like,
 //* a[i] = x;
 *
 * We convert it into 
 * PUT_ELEM(A, N, i, X);
 *
 * where N is number of elements in 'a'.
 * If 'N' is 0, then it means the number of elements are
 * not known. The assumption here is that 'i' is concrete, 
 * and X is a term.
 */
void PUT_ELEM_CONS (const void* arrAddr, unsigned int n, unsigned int i, const Term* x)
{
    /* We dont need to do SET_SYMBOLIC(arrAddr), as we are not changing
     * the base value of array. We are just updating some element of array.
     * So as per dynamic single assignment, we just need to increase
     * generation count associated with that element. And we are
     * doing that below anyway. Same comment also applies to PUT_FIELD_CONS
     * below. For more details, refer to online notes.
     */
    /* Array length is not known */
    if(n == 0) {                                        
        TermList* tl = (TermList*) xmalloc (sizeof(TermList)+ ((i + 2) *
               sizeof(Term)));
        tl->nchild_ = i+2; tl->child_[i] = x;
        tl->child_[i+1] = ntv();
                     
        int j;
        for (j = 0; j < i; j++)
            tl->child_[j] = ntv();
                                           
        /* List with variable tail */                                        
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlsttl(tl))) == 1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlsttl(tl)))) > 1)
          fail();
        else if (ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
    } else {
      /* Array length is known */
        assert(i <= n);                                        
        TermList* tl = (TermList*) xmalloc (sizeof(TermList) + (n *
              sizeof(Term)));
        tl->nchild_ = n; tl->child_[i] = x;
                                                                             
        int j;                                                               
        for (j = 0; j < n; j++)                                            
            if (j != i)                                                    
                tl->child_[j] = ntv();                                       
                 
#ifdef USE_TRYONE
        if(tryone(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlst(tl))) == 1)
#else
        int ret;
        if((ret = tryboth(tc1t(GET_GENCOUNT(arrAddr), CSEQ, xtlst(tl)))) > 1)
          fail();
        else if (ret == 1)
#endif
          GOTO_NEXT_BRANCH_IN_USER;
    }                                                        
}

/*
 * Structure accessor
 *
 * For a statement like,
 * x = a.b;
 *
 * We convert it into 
 * GET_FIELD(A, numfld, fldno, Fn, X);
 *
 * where:
 * A: symbolic value of a
 * numfld: Number of fields inside struct of type A
 * fldno: the field number of b inside a
 * Fn: function name of struct of type A; mostly it is name of struct type
 * X: symbolic value of x
 *
 * NOTE: x = a.b; does not mean that the macro below handles accesses
 * for 2-levels only. a.b can actually be last 2 components in access
 * w = x.y.z.a.b; and the macro below still works. What we want is
 * actually precisely defined by the macro, and unification will take
 * care of unifying term in constraints generated from it.
 */
void GET_FIELD_CONS (const void* strAddr, unsigned int numfld, unsigned int fldno, 
                     const char* fn, const void* xAddr)
{
    assert(numfld != 0);
    assert(fldno <= numfld);
    assert(fn != NULL);                        
    SET_SYMBOLIC(xAddr);
                                                   
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + (numfld) *
          sizeof(Term));       
    tl->nchild_ = numfld; tl->child_[fldno] = vt(GET_GENCOUNT(xAddr));
     
    int j;
    for (j = 0; j < numfld; j++)
        if (j != fldno)                                         
            tl->child_[j] = ntv();
    
#ifdef USE_TRYONE
    if(tryone(tc1t(GET_GENCOUNT(strAddr), CSEQ, xtv(fn, tl))) == 1)
#else
    int ret;
    if((ret = tryboth(tc1t(GET_GENCOUNT(strAddr), CSEQ, xtv(fn, tl)))) > 1)
      fail();
    else if (ret == 1)
#endif
      GOTO_NEXT_BRANCH_IN_USER;
}

/*
 * For a statement like,
 * a.b = x;
 *
 * We convert it into 
 * PUT_FIELD(A, numfld, fldno, Fn, x);
 *
 * where:
 * A: symbolic value of a
 * numfld: Number of fields inside struct of type A
 * fldno: the field number of b inside a
 * Fn: function name of struct of type A; mostly it is name of struct type
 * x: symbolic value of x if it is variable,
 *
 * NOTE: a.b = x does not mean that the macro below handles accesses
 * for 2-levels only. a.b can actually be last 2 components in access
 * x.y.z.a.b = w; and the macro below still works.
 */
void PUT_FIELD_CONS (const void* strAddr, unsigned int numfld, unsigned int fldno, 
                     const char* fn, const Term* x)
{
    assert(numfld != 0);
    assert(fldno <= numfld);
    assert(fn != NULL);
                                                   
    TermList* tl = (TermList*) xmalloc (sizeof(TermList) + (numfld) *
          sizeof(Term));       
    tl->nchild_ = numfld; tl->child_[fldno] = x;
     
    int j;
    for (j = 0; j < numfld; j++)
        if (j != fldno) 
            tl->child_[j] = ntv();
    
#ifdef USE_TRYONE
    if(tryone(tc1t(GET_GENCOUNT(strAddr), CSEQ, xtv(fn, tl))) == 1)
#else
    int ret;
    if((ret = tryboth(tc1t(GET_GENCOUNT(strAddr), CSEQ, xtv(fn, tl)))) > 1)
      fail();
    else if (ret == 1)
#endif
      GOTO_NEXT_BRANCH_IN_USER;
}

/*
 * This function must be called only if we are comparing
 * 2 symbolic rtx (X == Y) or (X != Y) case. We need to
 * handle this comparison specially because if both X and Y
 * are symbolic, then set of rtxes that satisfy this constraint
 * are infinite, and our constraint solver will generate
 * infinite such rtxes, running forever. We do not want
 * this. So what we do instead is add equality constraints
 * on the field of such rtxes.
 *
 * E.g., rtx X == rtx Y only if
 *       C_X == C_Y &&
 *       M_X == M_Y &&
 *       L_X == L_Y ..
 *
 *       where X = (C_X, M_X, L_X, ..)
 *        and  Y = (C_Y, M_Y, L_Y, ..)
 *
 * But introducing comparisons on symbolic field of rtxes
 * we are representing infinite space of rtx concretely.
 */
int are_sym_rtx_equal (rtx x, rtx y, void *x_addr, void* y_addr)
{
  int __cil_tmp93, __cil_tmp94, __cil_tmp96, __cil_tmp97; 
  DEBUG_PRINTF("%d:%s:%s:%d", getpid(), __FILE__, __func__, __LINE__);

  addNewRecord();

  if (x_addr != 0) {
    __cil_tmp93 = (unsigned long long )GET_GENCOUNT(x_addr);
    __cil_tmp94 = (void *)GET_SYMVAL_TYPE(x_addr);
    SET_GENCOUNT(& x, __cil_tmp93);
    SET_SYMVAL_TYPE(& x, __cil_tmp94);
  }

  if (y_addr != 0) {
    __cil_tmp96 = (unsigned long long )GET_GENCOUNT(y_addr);
    __cil_tmp97 = (void *)GET_SYMVAL_TYPE(y_addr);
    SET_GENCOUNT(& y, __cil_tmp96);
    SET_SYMVAL_TYPE(& y, __cil_tmp97);
  }

  myassert(IS_SYMBOLIC(x_addr) && IS_SYMBOLIC(y_addr));
  int ret = 0, ret1 = 0, ret2 = 0, ret3 = 0;

#if 1
	if ((ret1 = tryboth(tc1t(GET_GENCOUNT(x_addr), CSEQ, 
								vt(GET_GENCOUNT(y_addr))))) == 0) {
		ret = 1;
		goto out;
	} else if (ret1 > 1) {
		if (tryone(tc1t(GET_GENCOUNT(x_addr), TNE,
								vt(GET_GENCOUNT(y_addr)))) == 1)
			GOTO_NEXT_BRANCH_IN_USER;
		ret = 0;	
		goto out;
	} else {
		//GOTO_NEXT_BRANCH_IN_USER;
		ret = 0;
		goto out;
	}
#endif

#if 0

	/* Next part of code should not be executed. */
	//assert(1==0);
  uint64_t x_code_id = nv();
  uint64_t x_mode_id = nv();
  uint64_t x_unionu_id = nv();
  uint64_t x_other_id = nv();

  uint64_t y_code_id = nv();
  uint64_t y_mode_id = nv();
  uint64_t y_unionu_id = nv();
  uint64_t y_other_id = nv();

//#define NEW

	SET_GLOC;
#ifdef OLD
  if(tryboth(tc1t(GET_GENCOUNT(x_addr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(x_code_id), vt(x_mode_id), 
                    vt(x_unionu_id), vt(x_other_id), 0)))>=1) {
      ret = 0;
      goto out;
  }

	SET_GLOC;
  if(tryboth(tc1t(GET_GENCOUNT(y_addr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(y_code_id), vt(y_mode_id), 
                    vt(y_unionu_id), vt(y_other_id), 0)))>=1) {
      ret = 0;
      goto out;
  }
#endif

#ifdef NEW
  if(tryone(tc1t(GET_GENCOUNT(x_addr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(x_code_id), vt(x_mode_id), 
                    vt(x_unionu_id), vt(x_other_id), 0))) == 1) {
      //GOTO_NEXT_BRANCH_IN_USER;
			ret = 0;
			goto out;
	}

  if(tryone(tc1t(GET_GENCOUNT(y_addr), CSEQ, 
                xtl(RTL_FUNCTOR, vt(y_code_id), vt(y_mode_id), 
                    vt(y_unionu_id), vt(y_other_id), 0))) == 1) {
			//GOTO_NEXT_BRANCH_IN_USER;
			ret = 0;
			goto out;
  }

	SET_GLOC;
  if ((ret1 = tryboth(ic1v(x_code_id, IEQ, y_code_id))) == 0) {
			if ((ret2 = tryboth(ic1v(x_mode_id, IEQ, y_mode_id))) == 0) {
				if ((ret3 = tryboth(tc1t(x_other_id, CSEQ, vt(y_other_id)))) == 0) {
					ret = 1;
					goto out;
				} else if (ret3 > 1) {
					if (tryone(tc1t(x_other_id, TNE, vt(y_other_id))) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
				} else {
					//GOTO_NEXT_BRANCH_IN_USER;
					
				}
			} else if (ret2 > 1) {
					if (tryone(tc1t(x_mode_id, TNE, vt(y_mode_id))) == 1)
						GOTO_NEXT_BRANCH_IN_USER;
			} else {
					//GOTO_NEXT_BRANCH_IN_USER;
			}
  } else if (ret1 > 1) {
			SET_GLOC;
			if (tryone(tc1t(x_code_id, TNE, vt(y_code_id))) == 1)
				GOTO_NEXT_BRANCH_IN_USER;
	} else {
			//GOTO_NEXT_BRANCH_IN_USER;
	}
#endif

#ifdef OLD
	SET_GLOC;
  if(tryboth(tc1t(x_code_id, CSEQ, vt(y_code_id))) >= 1) {
      ret = 0;
      goto out;
  }

	SET_GLOC;
  if(tryboth(tc1t(x_mode_id, CSEQ, vt(y_mode_id))) >= 1) {
      ret = 0;
      goto out;
  }

  /*if(tryboth(tc1t(x_unionu_id, CSEQ, vt(y_unionu_id))) >= 1) {
      ret = 0;
      goto out;
  }*/

	SET_GLOC;
  if(tryboth(tc1t(x_other_id, CSEQ, vt(y_other_id))) >= 1) {
      ret = 0;
      goto out;
  }
#endif
#endif

#ifdef NEW
  ret = 0;
#else
	ret = 1;
#endif
out:
  deleteRecord();
  return ret;
}

/*
 * This function is used to compare rtx with NULL. This will be called
 * by rtx structurally_equal_p_trans. We represent NULL pointer using
 * rtx with code -1 in our symbolic system.
 */
int is_rtx_null_trans (rtx x , rtx y , void *x_addr , void *y_addr)
{
  int __cil_tmp93, __cil_tmp94, __cil_tmp96, __cil_tmp97; 
  DEBUG_PRINTF("%d:%s:%s:%d", getpid(), __FILE__, __func__, __LINE__);
  addNewRecord();
  if (x_addr != 0) {
    __cil_tmp93 = (unsigned long long )GET_GENCOUNT(x_addr);
    __cil_tmp94 = (void *)GET_SYMVAL_TYPE(x_addr);
    SET_GENCOUNT(& x, __cil_tmp93);
    SET_SYMVAL_TYPE(& x, __cil_tmp94);
  }

  if (y_addr != 0) {
    __cil_tmp96 = (unsigned long long )GET_GENCOUNT(y_addr);
    __cil_tmp97 = (void *)GET_SYMVAL_TYPE(y_addr);
    SET_GENCOUNT(& y, __cil_tmp96);
    SET_SYMVAL_TYPE(& y, __cil_tmp97);
  }

  // 2 represents the case that we let rtx_structurally_equal_p
  // handle it.
  int ret = 2;

  /* We are not changing the NULL_RTX macro in gcc
   * code. So that means we can have a case where
   * some rtx might be assigned NULL and some might
   * be assigned rtx(-1) to represent that they are
   * NULL. */
  if(!IS_SYMBOLIC(x_addr) &&
     !IS_SYMBOLIC(y_addr)) {
      if (x == NULL && y == NULL)
          ret = 1;
      else if (x == NULL && y != NULL && y->code == NULL_RTX_CODE)
          ret = 1;
      else if (x != NULL && x->code == NULL_RTX_CODE && y == NULL)
          ret = 1;
      else if (x != NULL && y != NULL &&
               x->code == NULL_RTX_CODE &&
               y->code == NULL_RTX_CODE)
          ret = 1;
      else
          ret = rtx_equal_p(x, y);
  } else if (IS_SYMBOLIC(x_addr) && IS_SYMBOLIC(y_addr)) {
      // When both are symbolic, we let rtx_structurally_p
      // handle it.
      ret = 2;
  } else if (IS_SYMBOLIC(x_addr)) {
      enum rtx_code code;
      GET_CODE_CONS(x_addr, &code);
      // Here we assume that x is treated as rtx in original code
      // if x is treated as integer (can be done in C) then symbolic
      // executor will throw an unification error.
			SET_GLOC;
      if (tryboth(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) == 0) {
          if (y == NULL || y->code == NULL_RTX_CODE)
            // If x is NULL and y is null, return 1
            ret = 1;
          else
            // If x is NULL but y is non-null, return 0
            ret = 0;
      } else {
          // This represents the case when x is non-NULL
#ifdef USE_TRYONE
          if(tryone(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE)) == 1)
#else
          int ret;
          if((ret = tryboth(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE))) > 1)
            fail();
          else if (ret == 1)
#endif
            GOTO_NEXT_BRANCH_IN_USER;
          if (y == NULL || y->code == NULL_RTX_CODE)
              // If y is null, then we return 0 as x is non-null
              ret = 0;
          else 
              // If y is non-null also, then we let rtx_structurally_equal_p
              // handle it as it represents legitimate case of x being compared
              // with some concrete rtx like stack_pointer_rtx
              ret = 2;
      }
  } else if (IS_SYMBOLIC(y_addr)) {
      enum rtx_code code;
      GET_CODE_CONS(y_addr, &code);
      // Here we assume that x is treated as rtx in original code
      // if x is treated as integer (can be done in C) then symbolic
      // executor will throw an unification error.
			SET_GLOC;
      if (tryboth(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) == 0) {
          if (x == NULL || x->code == NULL_RTX_CODE)
            // If x is null and y is NULL, return 1
            ret = 1;
          else
            // if y is NULL, but x is non-null, return 0
            ret = 0;
      } else {
          // This represents the case when y is non-NULL
#ifdef USE_TRYONE
          if(tryone(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE)) == 1)
#else
          int ret;
          if((ret = tryboth(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE))) > 1)
            fail();
          else if (ret == 1)
#endif
            GOTO_NEXT_BRANCH_IN_USER;
          if (x == NULL || x->code == NULL_RTX_CODE)
              // If x is null, then we return 0 as y is non-null
              ret = 0;
          else 
              // If x is non-null also, then we let rtx_structurally_equal_p
              // handle it as it represents legitimate case of y being compared
              // with some concrete rtx like stack_pointer_rtx
              ret = 2;
      }
  }

  deleteRecord();
  return ret;

#if 0
  if(IS_SYMBOLIC(x_addr)) {
      if(IS_SYMBOLIC(y_addr)) {
          // symbolic comparison: we will let
          // rtx_structurally_equal_p handle it
          return -1;
      } else if (y == NULL) {
          enum rtx_code code;
          GET_CODE_CONS(x, &code);
          if(tryboth(ic1c(IEQ, GET_GENCOUNT(&code), NULL_RTX_CODE)) == 0)
              return 1;
          else
              return 0;
     } else { 
          if (y->code == NULL_RTX_CODE) {
            GET_CODE_CONS(x, &code);
            if(tryboth(ic1c(IEQ, GET_GENCOUNT(&code), NULL_RTX_CODE)) == 0)
              return 1;
            else
              return 0;
          } else
            return 0;
     }
  } else {
      if(IS_SYMBOLIC(y_addr)) {
          // symbolic comparison: we will let
          // rtx_structurally_equal_p handle it
          return -1;
      } else if (y == NULL) {
          enum rtx_code code;
          GET_CODE_CONS(x, &code);
          if(tryboth(ic1c(IEQ, GET_GENCOUNT(&code), NULL_RTX_CODE)) == 0)
              return 1;
          else
              return 0;
     } else { 
          if (y->code == NULL_RTX_CODE) {
            GET_CODE_CONS(x, &code);
            if(tryboth(ic1c(IEQ, GET_GENCOUNT(&code), NULL_RTX_CODE)) == 0)
              return 1;
            else
              return 0;
          } else
            return 0;
     }
  }
#endif
}

int rtx_structurally_equal_p_trans (rtx x , rtx y , void *__cil_tmp92 , void *__cil_tmp95 ,
                                   unsigned long long *ret_gencount ) 
{ 
  int i ;
  int j ;
  enum rtx_code code ;
  enum rtx_code ycode ;
  char const   *fmt ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  int tmp___28 ;
  int tmp___29 ;
  unsigned int __cil_tmp36 ;
  unsigned int __cil_tmp37 ;
  char const   *__cil_tmp38 ;
  int __cil_tmp39 ;
  int __cil_tmp40 ;
  int __cil_tmp41 ;
  int __cil_tmp42 ;
  int __cil_tmp43 ;
  int __cil_tmp44 ;
  int __cil_tmp45 ;
  int __cil_tmp46 ;
  int __cil_tmp47 ;
  int __cil_tmp48 ;
  int __cil_tmp49 ;
  int __cil_tmp50 ;
  int __cil_tmp51 ;
  int __cil_tmp52 ;
  int __cil_tmp53 ;
  int __cil_tmp54 ;
  int __cil_tmp55 ;
  int __cil_tmp56 ;
  int __cil_tmp57 ;
  int __cil_tmp58 ;
  int __cil_tmp59 ;
  int __cil_tmp60 ;
  int __cil_tmp61 ;
  int __cil_tmp62 ;
  int __cil_tmp63 ;
  int __cil_tmp64 ;
  int __cil_tmp65 ;
  int __cil_tmp66 ;
  int __cil_tmp67 ;
  int __cil_tmp68 ;
  int __cil_tmp69 ;
  int __cil_tmp70 ;
  int __cil_tmp71 ;
  int __cil_tmp72 ;
  int __cil_tmp73 ;
  int __cil_tmp74 ;
  int __cil_tmp75 ;
  int __cil_tmp76 ;
  int __cil_tmp77 ;
  int __cil_tmp78 ;
  int __cil_tmp79 ;
  void *__cil_tmp80 ;
  void *__cil_tmp81 ;
  unsigned long long __cil_tmp82 ;
  int __cil_tmp83 ;
  void *__cil_tmp84 ;
  void *__cil_tmp85 ;
  unsigned long long __cil_tmp86 ;
  int __cil_tmp87 ;
  int __cil_tmp88 ;
  int __cil_tmp89 ;
  int __cil_tmp90 ;
  int __cil_tmp91 ;
  unsigned long long __cil_tmp93 ;
  void *__cil_tmp94 ;
  unsigned long long __cil_tmp96 ;
  void *__cil_tmp97 ;
	int __cil_tmp98;
	void* __cil_tmp99;

  addNewRecord();
  DEBUG_PRINTF("%d:%s:%s:%d", getpid(), __FILE__, __func__, __LINE__);
  if (__cil_tmp92 != 0) {
    __cil_tmp93 = (unsigned long long )GET_GENCOUNT(__cil_tmp92);
    __cil_tmp94 = (void *)GET_SYMVAL_TYPE(__cil_tmp92);
    SET_GENCOUNT(& x, __cil_tmp93);
    SET_SYMVAL_TYPE(& x, __cil_tmp94);
  }

  if (__cil_tmp95 != 0) {
    __cil_tmp96 = (unsigned long long )GET_GENCOUNT(__cil_tmp95);
    __cil_tmp97 = (void *)GET_SYMVAL_TYPE(__cil_tmp95);
    SET_GENCOUNT(& y, __cil_tmp96);
    SET_SYMVAL_TYPE(& y, __cil_tmp97);
  }

  int null_ret = is_rtx_null_trans(x, y, __cil_tmp92, __cil_tmp95);
  if (null_ret == 0 || null_ret == 1) {
    ADDOPCONS_NOP("=", __cil_tmp39, null_ret, & __cil_tmp39, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp39);
    deleteRecord();
    return (__cil_tmp39);
  }

  if (IS_SYMBOLIC(__cil_tmp92) && IS_SYMBOLIC(__cil_tmp95)) {
      int ret = are_sym_rtx_equal(x, y, __cil_tmp92, __cil_tmp95);
      ADDOPCONS_NOP("=", __cil_tmp39, ret, & __cil_tmp39, 0, VAR, ICONST, ICONST, 0);
      *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp39);
      deleteRecord();
      return (__cil_tmp39);
  }

	// compare code
  GET_CODE_CONS(& x, & tmp);
  ADDOPCONS_NOP("=", code, tmp, & code, & tmp, VAR, VAR, ICONST, 0);
  GET_CODE_CONS(& y, & tmp___0);
  ADDOPCONS_NOP("=", ycode, tmp___0, & ycode, & tmp___0, VAR, VAR, ICONST, 0);
  ADDOPCONS_NOP("=", __cil_tmp36, (unsigned int )tmp___0, & __cil_tmp36, & tmp___0,
                VAR, VAR, ICONST, 0);
  ADDOPCONS_NOP("=", __cil_tmp37, (unsigned int )code, & __cil_tmp37, & code, VAR,
                VAR, ICONST, 0);
  TRY_BINCONS_OP("!=", __cil_tmp53, __cil_tmp37, __cil_tmp36, & __cil_tmp37, & __cil_tmp36,
                 VAR, VAR, ICONST, ICONST);
  if (__cil_tmp53 != 0) {
    ADDOPCONS_NOP("=", __cil_tmp39, 0, & __cil_tmp39, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp39);
    deleteRecord();
    return (__cil_tmp39);
  } else {
    NEGATE_BINARY_CONDITION("!=", __cil_tmp37, __cil_tmp36, & __cil_tmp37, & __cil_tmp36);
  }

	// Code are same. now compare mode.
  GET_MODE_CONS(& x, & tmp___1);
  GET_MODE_CONS(& y, & tmp___2);
  TRY_BINCONS_OP("!=", __cil_tmp54, tmp___1, tmp___2, & tmp___1, & tmp___2, VAR, VAR,
                 ICONST, ICONST);
  if (__cil_tmp54 != 0) {
    ADDOPCONS_NOP("=", __cil_tmp40, 0, & __cil_tmp40, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp40);
    deleteRecord();
    return (__cil_tmp40);
  } else {
    NEGATE_BINARY_CONDITION("!=", tmp___1, tmp___2, & tmp___1, & tmp___2);
  }

	// code and mode are same. So now case by case comparison based on code.
  TRY_BINCONS_OP("==", __cil_tmp55, ycode, 37, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp55 != 0) {
    goto case_37;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 37, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp56, ycode, 44, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp56 != 0) {
    goto case_44;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 44, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp57, ycode, 45, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp57 != 0) {
    goto case_45;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 45, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp58, ycode, 2, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp58 != 0) {
    goto case_2;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 2, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp59, ycode, 1, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp59 != 0) {
    goto case_2;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 1, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp60, ycode, 38, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp60 != 0) {
    goto case_2;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 38, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp61, ycode, 32, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp61 != 0) {
    goto case_2;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 32, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp62, ycode, 30, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp62 != 0) {
    goto case_30;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 30, & ycode, 0);
  }

  TRY_BINCONS_OP("==", __cil_tmp63, ycode, 31, & ycode, 0, ICONST, ICONST, ICONST, ICONST);
  if (__cil_tmp63 != 0) {
    goto case_2;
  } else {
    NEGATE_BINARY_CONDITION("==", ycode, 31, & ycode, 0);
  }

  goto switch_default;

  case_37: /* CIL Label */ 
  REGNO_CONS(& x, & tmp___3);
  REGNO_CONS(& y, & tmp___4);

  TRY_BINCONS_OP("!=", __cil_tmp54, tmp___3, tmp___4, & tmp___3, & tmp___4, VAR, VAR,
                 ICONST, ICONST);
  if (__cil_tmp54 != 0) {
    ADDOPCONS_NOP("=", __cil_tmp40, 0, & __cil_tmp40, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp40);
    deleteRecord();
    return (__cil_tmp40);
  } else {
    NEGATE_BINARY_CONDITION("!=", tmp___3, tmp___4, & tmp___3, & tmp___4);
    ADDOPCONS_NOP("=", __cil_tmp40, 1, & __cil_tmp40, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp40);
    deleteRecord();
    return (__cil_tmp40);
  }

  case_44: /* CIL Label */ 
  XEXP_CONS(& x, 0, & tmp___5);
  XEXP_CONS(& y, 0, & tmp___6);
  ADDOPCONS_BINOP("=", "==", __cil_tmp42, tmp___5, tmp___6, & __cil_tmp42, & tmp___5,
                  & tmp___6, VAR, VAR, VAR, ICONST, ICONST);
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp42);
  deleteRecord();
 	return (__cil_tmp42);

  case_45: /* CIL Label */ 
  XSTR_CONS(& x, 0, & tmp___7);
  XSTR_CONS(& y, 0, & tmp___8);
  ADDOPCONS_BINOP("=", "==", __cil_tmp43, tmp___7, tmp___8, & __cil_tmp43, & tmp___7,
                  & tmp___8, VAR, VAR, VAR, ICONST, ICONST);
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp43);
  deleteRecord();
  return (__cil_tmp43);

  case_2: /* CIL Label */ 
  case_1: /* CIL Label */ 
  case_38: /* CIL Label */ 
  case_32: /* CIL Label */ 
  ADDOPCONS_NOP("=", __cil_tmp44, 1, & __cil_tmp44, 0, VAR, ICONST, ICONST, 0);
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp44);
  deleteRecord();
  return (__cil_tmp44);

  case_30: /* CIL Label */ 
  XCWINT_CONS(& x, 0, 30, & tmp___28);
  XCWINT_CONS(& y, 0, 30, & tmp___29);
  TRY_BINCONS_OP("!=", __cil_tmp98, tmp___28, tmp___29, & tmp___28, & tmp___29, VAR, VAR,
                 ICONST, ICONST);
	if (__cil_tmp98 != 0) {
    ADDOPCONS_NOP("=", __cil_tmp99, 0, & __cil_tmp99, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp99);
    deleteRecord();
    return (__cil_tmp99);
	} else {
    NEGATE_BINARY_CONDITION("!=", tmp___28, tmp___29, & tmp___28, & tmp___29);
    ADDOPCONS_NOP("=", __cil_tmp99, 1, & __cil_tmp99, 0, VAR, ICONST, ICONST, 0);
    *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp99);
    deleteRecord();
    return (__cil_tmp99);
	}

  case_31: /* CIL Label */ 
  ADDOPCONS_NOP("=", __cil_tmp44, 1, & __cil_tmp44, 0, VAR, ICONST, ICONST, 0);
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp44);
  deleteRecord();
  return (__cil_tmp44);

  switch_default: /* CIL Label */ 
  goto switch_break;
  switch_break: /* CIL Label */ 
  // We use ycode here to avoid unnecessary explosion and to exploit
  // the fact that y is concrete most of the times whereas x is 
  // symbolic.
  GET_RTX_FORMAT_CONS(& ycode, & tmp___9);
  ADDOPCONS_NOP("=", fmt, tmp___9, & fmt, & tmp___9, VAR, VAR, ICONST, 0);
  GET_RTX_LENGTH_CONS(& ycode, & tmp___10);
  ADDOPCONS_BINOP("=", "-", i, tmp___10, 1, & i, & tmp___10, 0, VAR, VAR, ICONST,
                  ICONST, ICONST);
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    TRY_BINCONS_OP(">=", __cil_tmp64, i, 0, & i, 0, VAR, ICONST, ICONST, ICONST);
    if (! (__cil_tmp64 != 0)) {
      NEGATE_BINARY_CONDITION(">=", i, 0, & i, 0);
      goto while_break;
    }
    }
    {
    ADDOPCONS_BINOP("=", "+", __cil_tmp38, fmt, i, & __cil_tmp38, & fmt, & i, VAR,
                    VAR, VAR, VAR, ICONST);
    {
    {
    TRY_BINCONS_OP("==", __cil_tmp65, *__cil_tmp38, 119, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp65 != 0) {
      goto case_119;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 119, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp66, *__cil_tmp38, 110, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp66 != 0) {
      goto case_110;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 110, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp67, *__cil_tmp38, 105, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp67 != 0) {
      goto case_110;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 105, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp68, *__cil_tmp38, 86, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp68 != 0) {
      goto case_86;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 86, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp69, *__cil_tmp38, 69, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp69 != 0) {
      goto case_86;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 69, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp70, *__cil_tmp38, 101, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp70 != 0) {
      goto case_101;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 101, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp71, *__cil_tmp38, 83, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp71 != 0) {
      goto case_83;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 83, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp72, *__cil_tmp38, 115, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp72 != 0) {
      goto case_83;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 115, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp73, *__cil_tmp38, 117, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp73 != 0) {
      goto case_117;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 117, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp74, *__cil_tmp38, 48, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp74 != 0) {
      goto case_48;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 48, 0, 0);
    }
    }
    {
    TRY_BINCONS_OP("==", __cil_tmp75, *__cil_tmp38, 116, 0, 0, VAR, ICONST, CCONST,
                   ICONST);
    if (__cil_tmp75 != 0) {
      goto case_48;
    } else {
      NEGATE_BINARY_CONDITION("==", *__cil_tmp38, 116, 0, 0);
    }
    }
    goto switch_default___0;
    case_119: /* CIL Label */ 
    XWINT_CONS(& x, i, & tmp___11);
    XWINT_CONS(& y, i, & tmp___12);
    {
    TRY_BINCONS_OP("!=", __cil_tmp76, tmp___11, tmp___12, & tmp___11, & tmp___12,
                   VAR, VAR, ICONST, ICONST);
    if (__cil_tmp76 != 0) {
      {
      ADDOPCONS_NOP("=", __cil_tmp45, 0, & __cil_tmp45, 0, VAR, ICONST, ICONST, 0);
      {
      *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp45);
      deleteRecord();
      return (__cil_tmp45);
      }
      }
    } else {
      NEGATE_BINARY_CONDITION("!=", tmp___11, tmp___12, & tmp___11, & tmp___12);
    }
    }
    goto switch_break___0;
    case_110: /* CIL Label */ 
    case_105: /* CIL Label */ 
    XINT_CONS(& x, i, & tmp___13);
    XINT_CONS(& y, i, & tmp___14);
    {
    TRY_BINCONS_OP("!=", __cil_tmp77, tmp___13, tmp___14, & tmp___13, & tmp___14,
                   VAR, VAR, ICONST, ICONST);
    if (__cil_tmp77 != 0) {
      {
      ADDOPCONS_NOP("=", __cil_tmp46, 0, & __cil_tmp46, 0, VAR, ICONST, ICONST, 0);
      {
      *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp46);
      deleteRecord();
      return (__cil_tmp46);
      }
      }
    } else {
      NEGATE_BINARY_CONDITION("!=", tmp___13, tmp___14, & tmp___13, & tmp___14);
    }
    }
    goto switch_break___0;
    case_86: /* CIL Label */ 
    case_69: /* CIL Label */ 
    XVECLEN_CONS(& x, i, & tmp___15);
    XVECLEN_CONS(& y, i, & tmp___16);
    {
    TRY_BINCONS_OP("!=", __cil_tmp78, tmp___15, tmp___16, & tmp___15, & tmp___16,
                   VAR, VAR, ICONST, ICONST);
    if (__cil_tmp78 != 0) {
      {
      ADDOPCONS_NOP("=", __cil_tmp47, 0, & __cil_tmp47, 0, VAR, ICONST, ICONST, 0);
      {
      *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp47);
      deleteRecord();
      return (__cil_tmp47);
      }
      }
    } else {
      NEGATE_BINARY_CONDITION("!=", tmp___15, tmp___16, & tmp___15, & tmp___16);
    }
    }
    ADDOPCONS_NOP("=", j, 0, & j, 0, VAR, ICONST, ICONST, 0);
    {
    while (1) {
      while_continue___0: /* CIL Label */ ;
      XVECLEN_CONS(& y, i, & tmp___20);
      {
      TRY_BINCONS_OP("<", __cil_tmp79, j, tmp___20, & j, & tmp___20, VAR, VAR, ICONST,
                     ICONST);
      if (! (__cil_tmp79 != 0)) {
        NEGATE_BINARY_CONDITION("<", j, tmp___20, & j, & tmp___20);
        goto while_break___0;
      }
      }
      XVECEXP_CONS(& y, i, j, & tmp___17);
      XVECEXP_CONS(& x, i, j, & tmp___18);
      __cil_tmp80 = & tmp___18;
      __cil_tmp81 = & tmp___17;
      tmp___19 = rtx_equal_p_trans(tmp___18, tmp___17, __cil_tmp80, __cil_tmp81, & __cil_tmp82);
      SET_GENCOUNT(& tmp___19, __cil_tmp82);
      {
      TRY_BINCONS_OP("==", __cil_tmp83, tmp___19, 0, & tmp___19, 0, VAR, ICONST, ICONST,
                     ICONST);
      if (__cil_tmp83 != 0) {
        {
        ADDOPCONS_NOP("=", __cil_tmp48, 0, & __cil_tmp48, 0, VAR, ICONST, ICONST,
                      0);
        {
        *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp48);
        deleteRecord();
        return (__cil_tmp48);
        }
        }
      } else {
        NEGATE_BINARY_CONDITION("==", tmp___19, 0, & tmp___19, 0);
      }
      }
      ADDOPCONS_BINOP("=", "+", j, j, 1, & j, & j, 0, VAR, VAR, ICONST, ICONST, ICONST);
    }
    while_break___0: /* CIL Label */ ;
    }
    goto switch_break___0;
    case_101: /* CIL Label */ 
    XEXP_CONS(& y, i, & tmp___21);
    XEXP_CONS(& x, i, & tmp___22);
    __cil_tmp84 = & tmp___22;
    __cil_tmp85 = & tmp___21;
    tmp___23 = rtx_equal_p_trans(tmp___22, tmp___21, __cil_tmp84, __cil_tmp85, & __cil_tmp86);
    SET_GENCOUNT(& tmp___23, __cil_tmp86);
    {
    TRY_BINCONS_OP("==", __cil_tmp87, tmp___23, 0, & tmp___23, 0, VAR, ICONST, ICONST,
                   ICONST);
    if (__cil_tmp87 != 0) {
      {
      ADDOPCONS_NOP("=", __cil_tmp49, 0, & __cil_tmp49, 0, VAR, ICONST, ICONST, 0);
      {
      *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp49);
      deleteRecord();
      return (__cil_tmp49);
      }
      }
    } else {
      NEGATE_BINARY_CONDITION("==", tmp___23, 0, & tmp___23, 0);
    }
    }
    goto switch_break___0;
    case_83: /* CIL Label */ 
    case_115: /* CIL Label */ 
    XSTR_CONS(& x, i, & tmp___24);
    {
    TRY_NOPCONS_OP(__cil_tmp91, tmp___24, & tmp___24, VAR, ICONST);
    if (__cil_tmp91 != 0) {
      goto _L;
    } else {
      NEGATE_NOP_CONDITION(tmp___24, & tmp___24);
      XSTR_CONS(& y, i, & tmp___25);
      {
      TRY_NOPCONS_OP(__cil_tmp90, tmp___25, & tmp___25, VAR, ICONST);
      if (__cil_tmp90 != 0) {
        _L: /* CIL Label */ 
        XSTR_CONS(& x, i, & tmp___26);
        {
        TRY_NOPCONS_OP(__cil_tmp89, tmp___26, & tmp___26, VAR, ICONST);
        if (__cil_tmp89 != 0) {
          XSTR_CONS(& y, i, & tmp___27);
          {
          TRY_NOPCONS_OP(__cil_tmp88, tmp___27, & tmp___27, VAR, ICONST);
          if (! (__cil_tmp88 != 0)) {
            NEGATE_NOP_CONDITION(tmp___27, & tmp___27);
            {
            ADDOPCONS_NOP("=", __cil_tmp50, 0, & __cil_tmp50, 0, VAR, ICONST, ICONST,
                          0);
            {
            *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp50);
            deleteRecord();
            return (__cil_tmp50);
            }
            }
          }
          }
        } else {
          NEGATE_NOP_CONDITION(tmp___26, & tmp___26);
          {
          ADDOPCONS_NOP("=", __cil_tmp51, 0, & __cil_tmp51, 0, VAR, ICONST, ICONST,
                        0);
          {
          *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp51);
          deleteRecord();
          return (__cil_tmp51);
          }
          }
        }
        }
      } else {
        NEGATE_NOP_CONDITION(tmp___25, & tmp___25);
      }
      }
    }
    }
    goto switch_break___0;
    case_117: /* CIL Label */ 
    goto switch_break___0;
    case_48: /* CIL Label */ 
    case_116: /* CIL Label */ 
    goto switch_break___0;
    switch_default___0: /* CIL Label */ 
    goto switch_break___0;
    switch_break___0: /* CIL Label */ ;
    }
    }
    ADDOPCONS_BINOP("=", "-", i, i, 1, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }
  while_break: /* CIL Label */ 
  ADDOPCONS_NOP("=", __cil_tmp52, 1, & __cil_tmp52, 0, VAR, ICONST, ICONST, 0);
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp52);
  deleteRecord();
  return (__cil_tmp52);
}

/* Function to make 2 rtx equal. 
 * - It is quite simple if both rtx are symbolic. In that case, we just add X=Y
 *   constraint.
 * - If either of them is non-symbolic, then we'd assign values of fields of
 *   concrete rtx to symbolic one by adding constraints. This needs to be done
 *   for all fields for which concrete rtx has values. Currently, we will stick
 *   with code and mode only.
 *
 *   EQUATE_RTX returns 0 when rtx x and y could not equated at all. For the
 *   caller it means that a particular path in infeasible, and thus caller
 *   should call GOTO_NEXT_BRANCH_IN_USER.
 *
 *   The logic of EQUATE_RTX must be such that it generates all combinations of
 *   x and y that equates.
 *   x == y iff (code(x) == code(y) && mode(x) == mode(y) && ...)
 *   since it is an AND, we can return failure even if one of the comparison 
 *   fails.
 */
int EQUATE_RTX (rtx x, rtx y, void* xaddr, void* yaddr, unsigned long long* gcret)
{
  enum rtx_code x_code, y_code;
  enum machine_mode x_mode, y_mode;
  unsigned long long xg, yg;
  void* xst, *yst;
  int ret = 0;

  addNewRecord();

  if (xaddr != 0) {
    xg = (unsigned long long )GET_GENCOUNT(xaddr);
    xst = (void *)GET_SYMVAL_TYPE(xaddr);
    SET_GENCOUNT(& x, xg);
    SET_SYMVAL_TYPE(& x, xst);
  }
  if (yaddr != 0) {
    yg = (unsigned long long )GET_GENCOUNT(yaddr);
    yst = (void *)GET_SYMVAL_TYPE(yaddr);
    SET_GENCOUNT(& y, yg);
    SET_SYMVAL_TYPE(& y, yst);
  }

  if (IS_SYMBOLIC(xaddr) && IS_SYMBOLIC(yaddr)) {
      /* We add X=Y constraint, if it fails then that means these 2 rtx cannot
       * made equal. */
      //if(tryboth(tc1t(GET_GENCOUNT(xaddr), CSEQ, vt(GET_GENCOUNT(yaddr)))) <= 1)
      // We don't need to use tryboth here to explore 2 possibilities: the case
      // where x and y can be equated and the one where they cannot be. This is
      // because we WANT TO equate x and y, and if they cannot be equated, then
      // caller is going to terminate that path anyway. So we can just use tryone
      // here to see if x and y can be equated. If they can not be, then caller
      // will just terminate the path.
      if(tryone(tc1t(GET_GENCOUNT(xaddr), CSEQ, vt(GET_GENCOUNT(yaddr)))) == 1)
        ret = 0;        
      else
        ret = 1;
   } else {

      GET_CODE_CONS(&x, &x_code);
      GET_CODE_CONS(&y, &y_code);

      if (IS_SYMBOLIC(&x_code) && IS_SYMBOLIC(&y_code)) {
        /* If constraint addition fails, then we return 0 as A=C cannot be achieved.
         * But if it succeeds, then we must try for B=D. */
        //if(tryboth(ic1v(GET_GENCOUNT(&x_code), IEQ, GET_GENCOUNT(&y_code))) <= 1)
	//same comment for tryboth as above
        if(tryone(ic1v(GET_GENCOUNT(&x_code), IEQ, GET_GENCOUNT(&y_code))) == 1)
            ret = 0;
        else ret = 1;
      } else if (IS_SYMBOLIC(&x_code)) {
        //if(tryboth(ic1c(GET_GENCOUNT(&x_code), IEQ, y_code)) <= 1)
        if(tryone(ic1c(GET_GENCOUNT(&x_code), IEQ, y_code)) == 1)
            ret = 0;
        else ret = 1;
      } else if (IS_SYMBOLIC(&y_code)) {
        //if(tryboth(ic1v(GET_GENCOUNT(&y_code), IEQ, x_code)) <= 1)
        if(tryone(ic1v(GET_GENCOUNT(&y_code), IEQ, x_code)) == 1)
            ret = 0;
        else ret = 1;
      } else if (x_code != y_code) {
        ret = 0;
      } else
        ret = 1;

      /* If A=C constraint succeed, meaning codes of x and y can be
       * made equal. Then we move on to equate mode now. */
      if (ret == 1) {
          GET_MODE_CONS(&x, &x_mode);
          GET_MODE_CONS(&y, &y_mode);

          if (IS_SYMBOLIC(&x_mode) && IS_SYMBOLIC(&y_mode)) {
            /* If constraint addition succeeds, then we return 1 as B=D is also achieved.
             * But if it fails, then we return 0. */
            //if(tryboth(ic1v(GET_GENCOUNT(&x_mode), INE, GET_GENCOUNT(&y_mode))) <= 1)
            if(tryone(ic1v(GET_GENCOUNT(&x_mode), INE, GET_GENCOUNT(&y_mode))) == 1)
                ret = 0;
            else ret = 1;
          } else if (IS_SYMBOLIC(&x_mode)) {
            /* If constraint addition succeeds, then we return 1 as A!=C is achieved */
            //if(tryboth(ic1c(GET_GENCOUNT(&x_mode), INE, y_mode)) <= 1)
            if(tryone(ic1c(GET_GENCOUNT(&x_mode), INE, y_mode)) == 1)
                ret = 0;
            else ret = 1;
          } else if (IS_SYMBOLIC(&y_mode)) {
            //if(tryboth(ic1v(GET_GENCOUNT(&y_mode), INE, x_mode)) <= 1)
            if(tryone(ic1v(GET_GENCOUNT(&y_mode), INE, x_mode)) == 1)
                ret = 0;
            else ret = 1;
          } else if (x_mode != y_mode) {
            ret = 0;
          } else
            ret = 1;
      }

      /* If ret = 0 here, then it means that rtx x and y must have same code and
       * mode. So actually we should be looking at other fields of them to try.
       * But currently we just stick to code and mode.
       */
   }

   deleteRecord();
   return ret;
}


/*
 * Hand-written function to make 2 rtx unequal. Needed when we want to negate ==
 * condition on 2 rtx. Negating a rtx is hard because rtx is a recursive data 
 * structure of infinite depth. So to negate one rtx, we are actually looking to
 * generate infinite other rtx. While symbolic execution helps us represent
 * these cases compactly, it does not help us represent all cases.
 *
 * Below we will consider CODE and MODE fields of rtx for negation. 
 * So if x = rtx(A,B,..) then neg(x) = rtx(C,D,..) where (A!=C) || (B!=D)
 * We only represent this case below.
 */
int CONTRAST_RTX (rtx x, rtx y, void* xaddr, void* yaddr, unsigned long long* gcret)
{
  enum rtx_code x_code, y_code;
  enum machine_mode x_mode, y_mode;
  unsigned long long xg, yg;
  void* xst, *yst;
  int ret = 0;

  DEBUG_PRINTF("%d:%s:%s:%d", getpid(), __FILE__, __func__, __LINE__);

  addNewRecord();

  if (xaddr != 0) {
    xg = (unsigned long long )GET_GENCOUNT(xaddr);
    xst = (void *)GET_SYMVAL_TYPE(xaddr);
    SET_GENCOUNT(& x, xg);
    SET_SYMVAL_TYPE(& x, xst);
  }
  if (yaddr != 0) {
    yg = (unsigned long long )GET_GENCOUNT(yaddr);
    yst = (void *)GET_SYMVAL_TYPE(yaddr);
    SET_GENCOUNT(& y, yg);
    SET_SYMVAL_TYPE(& y, yst);
  }

  /* We need to handle NULL RTX case. In case
   * when x or y is concrete but not null, our
   * usual processing is enough to handle this case. 
   */
  /* 1. If x is symbolic and y is NULL RTX */
  if (IS_SYMBOLIC(xaddr) && !IS_SYMBOLIC(yaddr)) {
      if (y == NULL || y->code == NULL_RTX_CODE) {
          enum rtx_code code;
          GET_CODE_CONS(xaddr, &code);
	  // Here we really want code != 0 constraint to hold.
	  // If this constraint cannot hold, then it means that
	  // x must be NULL RTX itself. So we can use tryone here.
          if (tryone(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE)) == 0)
              ret = 1;
          else { 
              // If constraint negation is unsatisfiable, then this is
              // infeasible path. Since constraint solver fails when tryone() 
	            // tryone return 1, we do not need to call fail() again. And
	            // our caller will take care of calling GOTO_NEXT_BRANCH_IN_USER.
              assert(tryone(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) == 0);
	            ret = 0;
          }
          deleteRecord();
          return ret;
      }
  } /* 2. If y is symbolic and x is concrete and NULL */
    else if (IS_SYMBOLIC(yaddr) && !IS_SYMBOLIC(xaddr)) {
      if (x == NULL || x->code == NULL_RTX_CODE) {
          enum rtx_code code;
          GET_CODE_CONS(yaddr, &code);
	  // Here we really want code != 0 constraint to hold.
	  // If this constraint cannot hold, then it means that
	  // x must be NULL RTX itself. So we can use tryone here.
          if (tryone(ic1c(GET_GENCOUNT(&code), INE, NULL_RTX_CODE)) == 0)
              ret = 1;
          else { 
              // If constraint negation is unsatisfiable, then this is
              // infeasible path. Since constraint solver fails when tryone() 
	            // tryone return 1, we do not need to call fail() again. And
	            // our caller will take care of calling GOTO_NEXT_BRANCH_IN_USER.
              assert(tryone(ic1c(GET_GENCOUNT(&code), IEQ, NULL_RTX_CODE)) == 0);
	            ret = 0;
          }
          deleteRecord();
          return ret;
      }
  } /* 3. Both are concrete then we have nothing to do */
    else if (!IS_SYMBOLIC(xaddr) && !IS_SYMBOLIC(yaddr)) {
        ret = 0;
        deleteRecord();
        return ret;
  } /* 4. If both are symbolic, then that case is handled below. */

#if 1
	if (tryone(tc1t(GET_GENCOUNT(xaddr), TNE, vt(GET_GENCOUNT(yaddr)))) == 1)
		//GOTO_NEXT_BRANCH_IN_USER;
		ret = 0;
	else {
		ret = 1;
	}
	deleteRecord();
	return ret;
#endif

#if 0
  
  GET_CODE_CONS(&x, &x_code);
  GET_CODE_CONS(&y, &y_code);

  if (IS_SYMBOLIC(&x_code) && IS_SYMBOLIC(&y_code)) {
    /* If constraint addition succeeds, then we return 1 as A!=C is achieved.
     * But if it fails, then we should not call fail() but instead we 
     * should try for B!=D. To explore the 2 possible sets of input which
     * negate X and Y, i.e. Set 1: A != C, Set 2: B != D. We must use
     * tryboth here. Because if we use tryone here, then we will be exploring
     * only one of the possible 2 sets here. In short, using tryboth helps us
     * ensure that we generate all possible value of x and y that do not match.
     * There are 2 such sets of x and y which are listed above, and as a 
     * completeness, we must generate both of them and not only 1. */
     /* Also we have compared output of try with 0 because even if constraint
      * addition fails (returning 0), ret will be 0 (default) and hence
      * we will check for mode comparison. */
		SET_GLOC;
    if(tryboth(ic1v(GET_GENCOUNT(&x_code), INE, GET_GENCOUNT(&y_code))) == 0)
        ret = 1;
    else if (tryone(ic1v(GET_GENCOUNT(&x_code), IEQ, GET_GENCOUNT(&y_code))) == 1)
        GOTO_NEXT_BRANCH_IN_USER;
  } else if (IS_SYMBOLIC(&x_code)) {
    /* If constraint addition succeeds, then we return 1 as A!=C is achieved */
    // We must use tryboth here. Check my comment above as to why we should
    // use tryboth.
		SET_GLOC;
    if(tryboth(ic1c(GET_GENCOUNT(&x_code), INE, y_code)) == 0)
        ret = 1;
    else if (tryone(ic1c(GET_GENCOUNT(&x_code), IEQ, y_code)) == 1)
        GOTO_NEXT_BRANCH_IN_USER;
  } else if (IS_SYMBOLIC(&y_code)) {
		SET_GLOC;
    if(tryboth(ic1v(GET_GENCOUNT(&y_code), INE, x_code)) == 0)
        ret = 1;
    else if(tryone(ic1v(GET_GENCOUNT(&y_code), INE, x_code)) == 1)
        GOTO_NEXT_BRANCH_IN_USER;
  } else if (x_code != y_code) {
    ret = 1;
  } else {
    ret = 0;
  }

  /* If A!=C constraint failed, meaning codes of x and y cannot be
   * made unequal. Let's try for mode now. */
  if (ret == 0) {
      GET_MODE_CONS(&x, &x_mode);
      GET_MODE_CONS(&y, &y_mode);

      if (IS_SYMBOLIC(&x_mode) && IS_SYMBOLIC(&y_mode)) {
        /* If constraint addition succeeds, then we return 1 as B!=D is achieved.
         * But if it fails, then we return 0. Same comment as to why we should use
	 * use tryboth here. Though currently we do not perform any more field 
	 * comparison beyond B ! D. But when that will be introduced we need
	 * tryboth here. Right now we use tryone. As a general rule, last
	 * field comparison in (A != C) || (B != D) can use tryone. This is
	 * because if that comparison fails, then there is no way x and y
	 * can be negated. */
        if(tryone(ic1v(GET_GENCOUNT(&x_mode), INE, GET_GENCOUNT(&y_mode))) == 0)
            ret = 1;
        /* Do we really need to add negation here? Because if tryone above
         * has already failed then it means that negation of that constraint holds.
          else if (tryone(ic1v(GET_GENCOUNT(&x_mode), IEQ, GET_GENCOUNT(&y_mode))) == 1)
          GOTO_NEXT_BRANCH_IN_USER;*/
        /* We don't need to set ret to 0 if constraint addition fails, as value
         * of ret is already 0 in this part. */
      } else if (IS_SYMBOLIC(&x_mode)) {
        /* If constraint addition succeeds, then we return 1 as B!=D is achieved */
        if(tryone(ic1c(GET_GENCOUNT(&x_mode), INE, y_mode)) == 0)
            ret = 1;
        /* Same comment as above.
        else if(tryone(ic1c(GET_GENCOUNT(&x_mode), IEQ, y_mode)) == 1)
          GOTO_NEXT_BRANCH_IN_USER;*/
      } else if (IS_SYMBOLIC(&y_mode)) {
        if(tryone(ic1v(GET_GENCOUNT(&y_mode), INE, x_mode)) == 0)
            ret = 1;
        /* same comment as above.
          else if(tryone(ic1v(GET_GENCOUNT(&y_mode), IEQ, x_mode)) == 1)
          GOTO_NEXT_BRANCH_IN_USER;*/
      } else if (x_mode != y_mode) {
        ret = 1;
      } else {
        ret = 0;
      }
  }
#endif

  /* If ret = 0 here, then it means that rtx x and y must have same code and
   * mode. So actually we should be looking at other fields of them to try
   * for inequality. But right now we will just work with code and mode. */

  deleteRecord();
  return ret;
}

int fprintf_print(FILE* f, const char* format, ...)
{
  va_list args;
  char buf[64];
  va_start(args, format);
  vsprintf(buf, format, args);
  addOutput(st(buf));
  va_end(args);
}

int putc_unlocked_print(char c, FILE* f) {
  addOutput(ct(c));
}

int fputs_unlocked_print(const char* s, FILE* f) {
  addOutput(st(s));
}

char* symvar_to_string(void* addr) {
  static char buf[64];
  if (isVarSymbolic(_symVarList, addr)) {
    memset(buf, 0, 64);
    sprintf(buf, "v(%" PRIu64 ")", getGenCount(_symVarList, addr));
    return buf;
  } else {
    ERROR_PRINTF("[symvar_to_string] Concrete variable passed to symvar_to_string");
    return NULL;
  }
}
