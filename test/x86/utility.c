
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

#include "symHelper.h"
#include "symVarList.h"
#include "cons_solve.h"
#include "transfuncs.h"
#include <limits.h>

void gcc_assert (int expr)
{
   if (expr == 0)
       fail();
}

void gcc_assert_trans (int expr, void* expraddr)
{
    /* gcc_assert checks if expr is 1, if it is then it
     * does nothing. If it is 0, then it calls abort.
     *
     * We will do similar: if expr is 1, then we do nothing.
     * But if it is 0, then we call fail(), which means
     * that particular path would fail.
     */
    /* Lets check if gcc_assert is called with concrete
     * arguments. */
    if(GET_GENCOUNT(expraddr) == gConcreteVarGcount) {
    	if (expr == 0) {
				ERROR_PRINTF("gcc_assert failed. Aborting now.");
       	fail();
			}
    } else {
	    symvar_t sv = GET_GENCOUNT(expraddr);
	/* Let's first add bounds constraint on the
	   expr so that getNext() would not fail. 
	   We assume that expr is of type int
	   which is default C89 behaviour. 
	
	   We hope that getNext() would return only
	   few values and not all values in the range
	   of INT_MIN to INT_MAX. So that this getNext()
	   would not lead to explosion.
	*/
 	if (tryone(ic1c(sv, ILT, INT_MAX)) == 1)
    GOTO_NEXT_BRANCH_IN_USER;
 	if (tryone(ic1c(sv, IGE, INT_MIN)) == 1)
    GOTO_NEXT_BRANCH_IN_USER;
	// If expression evaluates to 0 then we fail()
	// which is expected gcc_assert behaviour
	if (getNext(sv) == 0)
		ERROR_PRINTF("gcc_assert failed. Aborting now.");
	  fail();
  }
}

void gcc_unreachable() { gcc_unreachable_trans(); }

void gcc_unreachable_trans ()
{
    /* gcc_unreachable represents unreachable path inside
     * gcc. We would just call fail() in this case.
     */
		ERROR_PRINTF("gcc_unreachable was called. Aborting now.");
    fail();
}

/********************************************************
      Implementation for boolean and, or, not, xor
      made friendly for swiProlog constraint solver
 *******************************************************/

/* Original implementation */
static unsigned power(unsigned x, unsigned p)
{
    unsigned i;
    unsigned res=1;

    for(i = 0; i < p; i++)
        res = res * x;

    return res;
}

unsigned shleft (unsigned x, unsigned shift)
{
    // x << n = x * pow(2,n)
    unsigned multiplier = power(2, shift);
    return x * multiplier;
}

unsigned shright (unsigned x, unsigned shift)
{
    // x >> n = x / pow(2, n)
    unsigned divisor = power(2, shift);
    return x / divisor;
}

unsigned band (unsigned x, unsigned y)
{
    unsigned res = 0;
    unsigned i;

    for (i = 0; i < 31; i++) {
        unsigned x_rem = x % 2;
        unsigned y_rem = y % 2;
        if (x_rem == 1 && y_rem == 1)
            res += (x_rem * y_rem * power(2,i));
        x = x/2; y = y/2;
    }

    return res;
}

unsigned bor (unsigned x, unsigned y)
{
    unsigned res = 0;
    unsigned i;

    for (i = 0; i < 31; i++) {
        unsigned x_rem = x % 2;
        unsigned y_rem = y % 2;
        if (x_rem != 0 || y_rem != 0)
            res += power(2,i);
        x = x/2; y = y/2;
    }

    return res;
}

unsigned bxor (unsigned x, unsigned y)
{
    unsigned res = 0;
    unsigned i;

    for (i = 0; i < 31; i++) {
        if ((x % 2 == 1 && y % 2 == 0) ||
            (x % 2 == 0 && y % 2 == 1))
            res += power(2,i);
        x = x/2; y = y/2;
    }

    return res;
}

static unsigned int power_trans(unsigned int x, unsigned int p, 
                                void *__cil_tmp6, void *__cil_tmp9, 
                                unsigned long long *ret_gencount) 
{ 
  unsigned int i ;
  unsigned int res ;
  int __cil_tmp5 ;
  unsigned long long __cil_tmp7 ;
  void *__cil_tmp8 ;
  unsigned long long __cil_tmp10 ;
  void *__cil_tmp11 ;

  addNewRecord();
  if (__cil_tmp6 != 0) {
    __cil_tmp7 = (unsigned long long )GET_GENCOUNT(__cil_tmp6);
    __cil_tmp8 = (void *)GET_SYMVAL_TYPE(__cil_tmp6);
    SET_GENCOUNT(& x, __cil_tmp7);
    SET_SYMVAL_TYPE(& x, __cil_tmp8);
  }
  
  if (__cil_tmp9 != 0) {
    __cil_tmp10 = (unsigned long long )GET_GENCOUNT(__cil_tmp9);
    __cil_tmp11 = (void *)GET_SYMVAL_TYPE(__cil_tmp9);
    SET_GENCOUNT(& p, __cil_tmp10);
    SET_SYMVAL_TYPE(& p, __cil_tmp11);
  }
  
  ADDOPCONS_NOP("=", res, 1, & res, 0, VAR, ICONST, ICONST, 0);
  ADDOPCONS_NOP("=", i, 0, & i, 0, VAR, ICONST, ICONST, 0);
  
  while (1) {
    while_continue: /* CIL Label */ ;
    {
        TRY_BINCONS_OP("<", __cil_tmp5, i, p, & i, & p, VAR, VAR, ICONST, ICONST);
        if (! (__cil_tmp5 != 0)) {
            NEGATE_BINARY_CONDITION("<", i, p, & i, & p);
            goto while_break;
        }
    }
    ADDOPCONS_BINOP("=", "*", res, res, x, & res, & res, & x, VAR, VAR, VAR, ICONST,
                    ICONST);
    ADDOPCONS_BINOP("=", "+", i, i, 1U, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }

  while_break: /* CIL Label */ 
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& res);
  deleteRecord();
  return (res);
}

unsigned int band_trans(unsigned int x , unsigned int y , void *__cil_tmp15 , void *__cil_tmp18 ,
                        unsigned long long *ret_gencount ) 
{ 
  unsigned int res ;
  unsigned int i ;
  unsigned int x_rem ;
  unsigned int y_rem ;
  unsigned int tmp ;
  unsigned int __cil_tmp8 ;
  unsigned int __cil_tmp9 ;
  int __cil_tmp10 ;
  void *__cil_tmp11 ;
  unsigned long long __cil_tmp12 ;
  int __cil_tmp13 ;
  int __cil_tmp14 ;
  unsigned long long __cil_tmp16 ;
  void *__cil_tmp17 ;
  unsigned long long __cil_tmp19 ;
  void *__cil_tmp20 ;

  {
  addNewRecord();
  if (__cil_tmp15 != 0) {
    __cil_tmp16 = (unsigned long long )GET_GENCOUNT(__cil_tmp15);
    __cil_tmp17 = (void *)GET_SYMVAL_TYPE(__cil_tmp15);
    SET_GENCOUNT(& x, __cil_tmp16);
    SET_SYMVAL_TYPE(& x, __cil_tmp17);
  }
  if (__cil_tmp18 != 0) {
    __cil_tmp19 = (unsigned long long )GET_GENCOUNT(__cil_tmp18);
    __cil_tmp20 = (void *)GET_SYMVAL_TYPE(__cil_tmp18);
    SET_GENCOUNT(& y, __cil_tmp19);
    SET_SYMVAL_TYPE(& y, __cil_tmp20);
  }
  ADDOPCONS_NOP("=", res, 0, & res, 0, VAR, ICONST, ICONST, 0);
  ADDOPCONS_NOP("=", i, 0, & i, 0, VAR, ICONST, ICONST, 0);
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    TRY_BINCONS_OP("<", __cil_tmp10, i, 31U, & i, 0, VAR, ICONST, ICONST, ICONST);
    if (! (__cil_tmp10 != 0)) {
      NEGATE_BINARY_CONDITION("<", i, 31U, & i, 0);
      goto while_break;
    }
    }
    ADDOPCONS_BINOP("=", "%", x_rem, x, 2U, & x_rem, & x, 0, VAR, VAR, ICONST, ICONST,
                    ICONST);
    ADDOPCONS_BINOP("=", "%", y_rem, y, 2U, & y_rem, & y, 0, VAR, VAR, ICONST, ICONST,
                    ICONST);
    {
    TRY_BINCONS_OP("==", __cil_tmp14, x_rem, 1U, & x_rem, 0, VAR, ICONST, ICONST,
                   ICONST);
    if (__cil_tmp14 != 0) {
      {
      TRY_BINCONS_OP("==", __cil_tmp13, y_rem, 1U, & y_rem, 0, VAR, ICONST, ICONST,
                     ICONST);
      if (__cil_tmp13 != 0) {
        __cil_tmp11 = & i;
        tmp = power_trans(2, i, 0, __cil_tmp11, & __cil_tmp12);
        SET_GENCOUNT(& tmp, __cil_tmp12);
        ADDOPCONS_BINOP("=", "*", __cil_tmp8, x_rem, y_rem, & __cil_tmp8, & x_rem,
                        & y_rem, VAR, VAR, VAR, ICONST, ICONST);
        ADDOPCONS_BINOP("=", "*", __cil_tmp9, __cil_tmp8, tmp, & __cil_tmp9, & __cil_tmp8,
                        & tmp, VAR, VAR, VAR, ICONST, ICONST);
        ADDOPCONS_BINOP("=", "+", res, res, __cil_tmp9, & res, & res, & __cil_tmp9,
                        VAR, VAR, VAR, ICONST, ICONST);
      } else {
        NEGATE_BINARY_CONDITION("==", y_rem, 1U, & y_rem, 0);
      }
      }
    } else {
      NEGATE_BINARY_CONDITION("==", x_rem, 1U, & x_rem, 0);
    }
    }
    ADDOPCONS_BINOP("=", "/", x, x, 2U, & x, & x, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "/", y, y, 2U, & y, & y, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "+", i, i, 1U, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }
  while_break: /* CIL Label */ 
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& res);
  deleteRecord();
  return (res);
}
}

unsigned int shleft_trans(unsigned int x, unsigned int shift, 
                          void *__cil_tmp8, void *__cil_tmp11, 
                          unsigned long long *ret_gencount ) 
{ 
  unsigned int multiplier ;
  unsigned int tmp ;
  unsigned int __cil_tmp5 ;
  void *__cil_tmp6 ;
  unsigned long long __cil_tmp7 ;
  unsigned long long __cil_tmp9 ;
  void *__cil_tmp10 ;
  unsigned long long __cil_tmp12 ;
  void *__cil_tmp13 ;

  addNewRecord();
  if (__cil_tmp8 != 0) {
    __cil_tmp9 = (unsigned long long )GET_GENCOUNT(__cil_tmp8);
    __cil_tmp10 = (void *)GET_SYMVAL_TYPE(__cil_tmp8);
    SET_GENCOUNT(& x, __cil_tmp9);
    SET_SYMVAL_TYPE(& x, __cil_tmp10);
  }

  if (__cil_tmp11 != 0) {
    __cil_tmp12 = (unsigned long long )GET_GENCOUNT(__cil_tmp11);
    __cil_tmp13 = (void *)GET_SYMVAL_TYPE(__cil_tmp11);
    SET_GENCOUNT(& shift, __cil_tmp12);
    SET_SYMVAL_TYPE(& shift, __cil_tmp13);
  }
  
  __cil_tmp6 = & shift;
  tmp = power_trans(2, shift, 0, __cil_tmp6, & __cil_tmp7);
  SET_GENCOUNT(& tmp, __cil_tmp7);
  ADDOPCONS_NOP("=", multiplier, tmp, & multiplier, & tmp, VAR, VAR, ICONST, 0);
  ADDOPCONS_BINOP("=", "*", __cil_tmp5, x, multiplier, & __cil_tmp5, & x, & multiplier,
                  VAR, VAR, VAR, ICONST, ICONST);

  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp5);
  deleteRecord();
  return (__cil_tmp5);
}

unsigned int shright_trans(unsigned int x, unsigned int shift, 
                           void *__cil_tmp8, void *__cil_tmp11, 
                           unsigned long long *ret_gencount) 
{ 
  unsigned int divisor ;
  unsigned int tmp ;
  unsigned int __cil_tmp5 ;
  void *__cil_tmp6 ;
  unsigned long long __cil_tmp7 ;
  unsigned long long __cil_tmp9 ;
  void *__cil_tmp10 ;
  unsigned long long __cil_tmp12 ;
  void *__cil_tmp13 ;

  addNewRecord();
  if (__cil_tmp8 != 0) {
    __cil_tmp9 = (unsigned long long )GET_GENCOUNT(__cil_tmp8);
    __cil_tmp10 = (void *)GET_SYMVAL_TYPE(__cil_tmp8);
    SET_GENCOUNT(& x, __cil_tmp9);
    SET_SYMVAL_TYPE(& x, __cil_tmp10);
  }

  if (__cil_tmp11 != 0) {
    __cil_tmp12 = (unsigned long long )GET_GENCOUNT(__cil_tmp11);
    __cil_tmp13 = (void *)GET_SYMVAL_TYPE(__cil_tmp11);
    SET_GENCOUNT(& shift, __cil_tmp12);
    SET_SYMVAL_TYPE(& shift, __cil_tmp13);
  }

  __cil_tmp6 = & shift;
  tmp = power_trans(2, shift, 0, __cil_tmp6, & __cil_tmp7);
  SET_GENCOUNT(& tmp, __cil_tmp7);
  ADDOPCONS_NOP("=", divisor, tmp, & divisor, & tmp, VAR, VAR, ICONST, 0);
  ADDOPCONS_BINOP("=", "/", __cil_tmp5, x, divisor, & __cil_tmp5, & x, & divisor,
                  VAR, VAR, VAR, ICONST, ICONST);
  
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& __cil_tmp5);
  deleteRecord();
  return (__cil_tmp5);
}

#if 0
unsigned int band_trans(unsigned int x, unsigned int y, 
                        void *__cil_tmp13, void *__cil_tmp16,
                        unsigned long long *ret_gencount) 
{ 
  unsigned int res ;
  unsigned int i ;
  unsigned int tmp ;
  unsigned int __cil_tmp6 ;
  unsigned int __cil_tmp7 ;
  int __cil_tmp8 ;
  void *__cil_tmp9 ;
  unsigned long long __cil_tmp10 ;
  int __cil_tmp11 ;
  int __cil_tmp12 ;
  unsigned long long __cil_tmp14 ;
  void *__cil_tmp15 ;
  unsigned long long __cil_tmp17 ;
  void *__cil_tmp18 ;

  addNewRecord();
  if (__cil_tmp13 != 0) {
    __cil_tmp14 = (unsigned long long )GET_GENCOUNT(__cil_tmp13);
    __cil_tmp15 = (void *)GET_SYMVAL_TYPE(__cil_tmp13);
    SET_GENCOUNT(& x, __cil_tmp14);
    SET_SYMVAL_TYPE(& x, __cil_tmp15);
  }

  if (__cil_tmp16 != 0) {
    __cil_tmp17 = (unsigned long long )GET_GENCOUNT(__cil_tmp16);
    __cil_tmp18 = (void *)GET_SYMVAL_TYPE(__cil_tmp16);
    SET_GENCOUNT(& y, __cil_tmp17);
    SET_SYMVAL_TYPE(& y, __cil_tmp18);
  }

  ADDOPCONS_NOP("=", res, 0, & res, 0, VAR, ICONST, ICONST, 0);
  ADDOPCONS_NOP("=", i, 0, & i, 0, VAR, ICONST, ICONST, 0);

  while (1) {
    while_continue: /* CIL Label */ ;
    {
        TRY_BINCONS_OP("<", __cil_tmp8, i, 31U, & i, 0, VAR, ICONST, ICONST, ICONST);
        if (! (__cil_tmp8 != 0)) {
          NEGATE_BINARY_CONDITION("<", i, 31U, & i, 0);
          goto while_break;
        }
    }
    ADDOPCONS_BINOP("=", "%", __cil_tmp6, x, 2U, & __cil_tmp6, & x, 0, VAR, VAR, ICONST,
                    ICONST, ICONST);
    TRY_BINCONS_OP("==", __cil_tmp12, __cil_tmp6, 1U, & __cil_tmp6, 0, VAR, ICONST,
                   ICONST, ICONST);
    if (__cil_tmp12 != 0) {
      ADDOPCONS_BINOP("=", "%", __cil_tmp7, y, 2U, & __cil_tmp7, & y, 0, VAR, VAR,
                      ICONST, ICONST, ICONST);
      TRY_BINCONS_OP("==", __cil_tmp11, __cil_tmp7, 1U, & __cil_tmp7, 0, VAR, ICONST,
                     ICONST, ICONST);
      if (__cil_tmp11 != 0) {
        __cil_tmp9 = & i;
        tmp = power_trans(2, i, 0, __cil_tmp9, & __cil_tmp10);
        SET_GENCOUNT(& tmp, __cil_tmp10);
        ADDOPCONS_BINOP("=", "+", res, res, tmp, & res, & res, & tmp, VAR, VAR, VAR,
                        ICONST, ICONST);
      } else {
        NEGATE_BINARY_CONDITION("==", __cil_tmp7, 1U, & __cil_tmp7, 0);
      }
    } else {
      NEGATE_BINARY_CONDITION("==", __cil_tmp6, 1U, & __cil_tmp6, 0);
    }
    ADDOPCONS_BINOP("=", "/", x, x, 2U, & x, & x, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "/", y, y, 2U, & y, & y, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "+", i, i, 1U, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }

  while_break: /* CIL Label */ 
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& res);
  deleteRecord();
  return (res);
}
#endif

unsigned int bor_trans(unsigned int x , unsigned int y , 
                       void *__cil_tmp15 , void *__cil_tmp18 ,
                       unsigned long long *ret_gencount ) 
{ 
  unsigned int res ;
  unsigned int i ;
  unsigned int tmp ;
  unsigned int __cil_tmp6 ;
  unsigned int __cil_tmp7 ;
  int __cil_tmp8 ;
  void *__cil_tmp9 ;
  unsigned long long __cil_tmp10 ;
  void *__cil_tmp11 ;
  unsigned long long __cil_tmp12 ;
  int __cil_tmp13 ;
  int __cil_tmp14 ;
  unsigned long long __cil_tmp16 ;
  void *__cil_tmp17 ;
  unsigned long long __cil_tmp19 ;
  void *__cil_tmp20 ;

  addNewRecord();
  if (__cil_tmp15 != 0) {
    __cil_tmp16 = (unsigned long long )GET_GENCOUNT(__cil_tmp15);
    __cil_tmp17 = (void *)GET_SYMVAL_TYPE(__cil_tmp15);
    SET_GENCOUNT(& x, __cil_tmp16);
    SET_SYMVAL_TYPE(& x, __cil_tmp17);
  }
  if (__cil_tmp18 != 0) {
    __cil_tmp19 = (unsigned long long )GET_GENCOUNT(__cil_tmp18);
    __cil_tmp20 = (void *)GET_SYMVAL_TYPE(__cil_tmp18);
    SET_GENCOUNT(& y, __cil_tmp19);
    SET_SYMVAL_TYPE(& y, __cil_tmp20);
  }

  ADDOPCONS_NOP("=", res, 0, & res, 0, VAR, ICONST, ICONST, 0);
  ADDOPCONS_NOP("=", i, 0, & i, 0, VAR, ICONST, ICONST, 0);

  while (1) {
    while_continue: /* CIL Label */ ;
    {
        TRY_BINCONS_OP("<", __cil_tmp8, i, 31U, & i, 0, VAR, ICONST, ICONST, ICONST);
        if (! (__cil_tmp8 != 0)) {
          NEGATE_BINARY_CONDITION("<", i, 31U, & i, 0);
          goto while_break;
        }
    }
    ADDOPCONS_BINOP("=", "%", __cil_tmp6, x, 2U, & __cil_tmp6, & x, 0, VAR, VAR, ICONST,
                    ICONST, ICONST);
    TRY_BINCONS_OP("!=", __cil_tmp14, __cil_tmp6, 0U, & __cil_tmp6, 0, VAR, ICONST,
                   ICONST, ICONST);
    if (__cil_tmp14 != 0) {
      __cil_tmp9 = & i;
      tmp = power_trans(2, i, 0, __cil_tmp9, & __cil_tmp10);
      SET_GENCOUNT(& tmp, __cil_tmp10);
      ADDOPCONS_BINOP("=", "+", res, res, tmp, & res, & res, & tmp, VAR, VAR, VAR,
                      ICONST, ICONST);
    } else {
      NEGATE_BINARY_CONDITION("!=", __cil_tmp6, 0U, & __cil_tmp6, 0);
      ADDOPCONS_BINOP("=", "%", __cil_tmp7, y, 2U, & __cil_tmp7, & y, 0, VAR, VAR,
                      ICONST, ICONST, ICONST);
      TRY_BINCONS_OP("!=", __cil_tmp13, __cil_tmp7, 0U, & __cil_tmp7, 0, VAR, ICONST,
                     ICONST, ICONST);
      if (__cil_tmp13 != 0) {
        __cil_tmp11 = & i;
        tmp = power_trans(2, i, 0, __cil_tmp11, & __cil_tmp12);
        SET_GENCOUNT(& tmp, __cil_tmp12);
        ADDOPCONS_BINOP("=", "+", res, res, tmp, & res, & res, & tmp, VAR, VAR, VAR,
                        ICONST, ICONST);
      } else {
        NEGATE_BINARY_CONDITION("!=", __cil_tmp7, 0U, & __cil_tmp7, 0);
      }
    }
    ADDOPCONS_BINOP("=", "/", x, x, 2U, & x, & x, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "/", y, y, 2U, & y, & y, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "+", i, i, 1U, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }

  while_break: /* CIL Label */ 
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& res);
  deleteRecord();
  return (res);
}

unsigned int bxor_trans(unsigned int x , unsigned int y , 
                        void *__cil_tmp19 , void *__cil_tmp22 ,
                        unsigned long long *ret_gencount ) 
{ 
  unsigned int res ;
  unsigned int i ;
  unsigned int tmp ;
  unsigned int __cil_tmp6 ;
  unsigned int __cil_tmp7 ;
  unsigned int __cil_tmp8 ;
  unsigned int __cil_tmp9 ;
  int __cil_tmp10 ;
  void *__cil_tmp11 ;
  unsigned long long __cil_tmp12 ;
  int __cil_tmp13 ;
  void *__cil_tmp14 ;
  unsigned long long __cil_tmp15 ;
  int __cil_tmp16 ;
  int __cil_tmp17 ;
  int __cil_tmp18 ;
  unsigned long long __cil_tmp20 ;
  void *__cil_tmp21 ;
  unsigned long long __cil_tmp23 ;
  void *__cil_tmp24 ;

  addNewRecord();
  if (__cil_tmp19 != 0) {
    __cil_tmp20 = (unsigned long long )GET_GENCOUNT(__cil_tmp19);
    __cil_tmp21 = (void *)GET_SYMVAL_TYPE(__cil_tmp19);
    SET_GENCOUNT(& x, __cil_tmp20);
    SET_SYMVAL_TYPE(& x, __cil_tmp21);
  }

  if (__cil_tmp22 != 0) {
    __cil_tmp23 = (unsigned long long )GET_GENCOUNT(__cil_tmp22);
    __cil_tmp24 = (void *)GET_SYMVAL_TYPE(__cil_tmp22);
    SET_GENCOUNT(& y, __cil_tmp23);
    SET_SYMVAL_TYPE(& y, __cil_tmp24);
  }

  ADDOPCONS_NOP("=", res, 0, & res, 0, VAR, ICONST, ICONST, 0);
  ADDOPCONS_NOP("=", i, 0, & i, 0, VAR, ICONST, ICONST, 0);

  while (1) {
    while_continue: /* CIL Label */ ;
    {
        TRY_BINCONS_OP("<", __cil_tmp10, i, 31U, & i, 0, VAR, ICONST, ICONST, ICONST);
        if (! (__cil_tmp10 != 0)) {
            NEGATE_BINARY_CONDITION("<", i, 31U, & i, 0);
            goto while_break;
        }
    }
    ADDOPCONS_BINOP("=", "%", __cil_tmp6, x, 2U, & __cil_tmp6, & x, 0, VAR, VAR, ICONST,
                    ICONST, ICONST);
    TRY_BINCONS_OP("==", __cil_tmp18, __cil_tmp6, 1U, & __cil_tmp6, 0, VAR, ICONST,
                   ICONST, ICONST);
    if (__cil_tmp18 != 0) {
      ADDOPCONS_BINOP("=", "%", __cil_tmp7, y, 2U, & __cil_tmp7, & y, 0, VAR, VAR,
                      ICONST, ICONST, ICONST);
      TRY_BINCONS_OP("==", __cil_tmp13, __cil_tmp7, 0U, & __cil_tmp7, 0, VAR, ICONST,
                     ICONST, ICONST);
      if (__cil_tmp13 != 0) {
        __cil_tmp11 = & i;
        tmp = power_trans(2, i, 0, __cil_tmp11, & __cil_tmp12);
        SET_GENCOUNT(& tmp, __cil_tmp12);
        ADDOPCONS_BINOP("=", "+", res, res, tmp, & res, & res, & tmp, VAR, VAR, VAR,
                        ICONST, ICONST);
      } else {
        NEGATE_BINARY_CONDITION("==", __cil_tmp7, 0U, & __cil_tmp7, 0);
        goto _L;
      }
    } else {
      NEGATE_BINARY_CONDITION("==", __cil_tmp6, 1U, & __cil_tmp6, 0);
      _L: /* CIL Label */ 
      ADDOPCONS_BINOP("=", "%", __cil_tmp8, x, 2U, & __cil_tmp8, & x, 0, VAR, VAR,
                      ICONST, ICONST, ICONST);
      TRY_BINCONS_OP("==", __cil_tmp17, __cil_tmp8, 0U, & __cil_tmp8, 0, VAR, ICONST,
                     ICONST, ICONST);
      if (__cil_tmp17 != 0) {
        ADDOPCONS_BINOP("=", "%", __cil_tmp9, y, 2U, & __cil_tmp9, & y, 0, VAR, VAR,
                        ICONST, ICONST, ICONST);
        TRY_BINCONS_OP("==", __cil_tmp16, __cil_tmp9, 1U, & __cil_tmp9, 0, VAR, ICONST,
                       ICONST, ICONST);
        if (__cil_tmp16 != 0) {
          __cil_tmp14 = & i;
          tmp = power_trans(2, i, 0, __cil_tmp14, & __cil_tmp15);
          SET_GENCOUNT(& tmp, __cil_tmp15);
          ADDOPCONS_BINOP("=", "+", res, res, tmp, & res, & res, & tmp, VAR, VAR,
                          VAR, ICONST, ICONST);
        } else {
          NEGATE_BINARY_CONDITION("==", __cil_tmp9, 1U, & __cil_tmp9, 0);
        }
      } else {
        NEGATE_BINARY_CONDITION("==", __cil_tmp8, 0U, & __cil_tmp8, 0);
      }
    }
    ADDOPCONS_BINOP("=", "/", x, x, 2U, & x, & x, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "/", y, y, 2U, & y, & y, 0, VAR, VAR, ICONST, ICONST, ICONST);
    ADDOPCONS_BINOP("=", "+", i, i, 1U, & i, & i, 0, VAR, VAR, ICONST, ICONST, ICONST);
  }

  while_break: /* CIL Label */ 
  *ret_gencount = (unsigned long long )GET_GENCOUNT(& res);
  deleteRecord();
  return (res);
}
