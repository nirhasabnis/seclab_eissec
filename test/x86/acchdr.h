
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

#ifndef ACC_HDR_H
#define ACC_HDR_H

#define IN_GCC
#define IN_TRANSFORMED_CODE
enum rtx_code GET_CODE (const rtx r);
void GET_CODE_CONS(const rtx* rtxAddr, enum rtx_code* codeAddr);
enum machine_mode GET_MODE (const rtx r);
void GET_MODE_CONS(const rtx* rtxAddr, enum machine_mode* modeAddr);
rtx XEXP (const rtx r, int n);
void XEXP_CONS(const rtx* rtxAddr, int idx, rtx* xAddr);
rtx XCEXP (rtx r, int n, enum rtx_code c);
void XCEXP_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, rtx* xAddr);
rtx XC2EXP (rtx r, int n, enum rtx_code c1, enum rtx_code c2);
void XC2EXP_CONS(const rtx* rtxAddr, int idx, enum rtx_code c1, enum rtx_code c2, rtx* xAddr);
char* XSTR (rtx r, int n);
void XSTR_CONS(const rtx* rtxAddr, int idx, char** xAddr);
char* XCSTR (rtx r, int n, enum rtx_code c);
void XCSTR_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, char** xAddr);
int XINT (rtx r, int n);
void XINT_CONS(const rtx* rtxAddr, int idx, int* intAddr); 
int XCINT (rtx r, int n, enum rtx_code c);
void XCINT_CONS (const rtx* rtxAddr, int idx, enum rtx_code c, int* intAddr);
unsigned int XCUINT (const_rtx r, int n, enum rtx_code c);
void XCUINT_CONS(const rtx* rtxAddr, int idx, enum rtx_code c, unsigned int* uintAddr); 
int REGNO (rtx r);
/* REGNO symbolic */
void REGNO_CONS(const rtx* rtxAddr, unsigned int* regAddr); 
/* REGNO symbolic to concrete*/
int REGNO_S2C(rtx r);
void REGNO_S2C_CONS(const rtx* rtxAddr, unsigned int* regAddr);
#if 0
int SUBREG_REG(rtx r);
void SUBREG_REG_CONS(const rtx* rtxAddr, rtx* regAddr); 
int SUBREG_BYTE(rtx r);
void SUBREG_BYTE_CONS(const rtx* rtxAddr, unsigned int* byteAddr); 
#endif
rtvec XVEC(rtx r, int n);
void XVEC_CONS(const rtx* rtxAddr, int n, rtvec* vecAddr); 
rtvec XCVEC(rtx r, int n, enum rtx_code c);
void XCVEC_CONS(const rtx* rtxAddr, int n, enum rtx_code c, rtvec* vecAddr); 
rtx XVECEXP(rtx r, int n, int m);
void XVECEXP_CONS(const rtx* rtxAddr, int n, int m, rtx* expAddr);
rtx XCVECEXP(rtx r, int n, int m, enum rtx_code c);
void XCVECEXP_CONS(const rtx* rtxAddr, int n, int m, enum rtx_code c, rtx* expAddr);
int XVECLEN(rtx r, int n );
void XVECLEN_CONS(const rtx* rtxAddr, int n, int* lenAddr); 
int XCVECLEN(rtx r, int n, enum rtx_code c);
void XCVECLEN_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* lenAddr); 
int XWINT(rtx r, int n);
void XWINT_CONS(const rtx* rtxAddr, int n, int* intAddr);
int XCWINT(rtx r, int n, enum rtx_code c);
void XCWINT_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* intAddr);
void XCWINT_S2C_CONS(const rtx* rtxAddr, int n, enum rtx_code c, int* intAddr);
//void* X0INT(const rtx, N);      (RTL_CHECK1 (RTX, N, '0').rt_int)
#define X0INT_CONS XINT_CONS
//void* X0UINT(const rtx, N);     (RTL_CHECK1 (RTX, N, '0').rt_uint)
//int MEM_P(void* r);
void MEM_P_CONS(const rtx* rtxAddr, int* ret);
//int CONST_INT_P(void* r);
void CONST_INT_P_CONS(const rtx* rtxAddr, int* ret);
//int REG_P(void* r);
void REG_P_CONS(const rtx* rtxAddr, int* ret);
#if 0
void* PUT_CODE_CONS(const rtx, Code); (GET_CODE_CONS(rtx, Code))
void* PUT_MODE_CONS(const rtx, Mode); (GET_MODE_CONS(rtx, Mode))
void* GET_NUM_ELEM_CONS(rtvec);
void* RTVEC_ELT_CONS(rtvec, i);
void* RTL_CHECK1_CONS(const rtx, n, c1); (addCons(tc1t(rtx, EQ, xtl("rtl", ntv(), ntv(), xtn("list", n+1, 0), ntv(), 0))))
void* RTL_CHECK2_CONS(const rtx, n, c1, c2); (RTL_CHECK1_CONS(rtx, n, c1))
void* RTL_CHECKC1_CONS(const rtx, n, c1); (RTL_CHECK1_CONS(rtx, n, c1))
void* RTL_CHECKC2_CONS(const rtx, n, c1, c2); (RTL_CHECK2_CONS(rtx, n, c1, c2))a
void* XWINT_CONS(const rtx, n, Wint);
void* XCWINT_CONS(const rtx, n, c, Wint); (XWINT_CONS(rtx, n, Wint))
void* XCMWINT_CONS(const rtx, n, c, m, Wint); (XWINT_CONS(rtx, n, Wint))
void* XCNMWINT_CONS(const rtx, n, c, m, Wint); (XWINT_CONS(rtx, n, Wint))
#endif
void GET_MODE_CLASS_CONS(const void* modeAddr, enum mode_class* mclass);
void GET_MODE_SIZE_CONS(const void* modeAddr, unsigned char* msize);
void GET_MODE_NUNITS_CONS(const void* modeAddr, unsigned char* mnunits);
void CONST0_RTX_CONS(const void* modeAddr, rtx* rtxAddr);
void REGNO_REG_CLASS_CONS(const void* regnoAddr, enum reg_class* regclass); 
void GET_RTX_CLASS_CONS(const void* codeAddr, enum rtx_class* rclass);
void GET_RTX_FORMAT_CONS(const void* codeAddr, char** rformat);
void GET_RTX_LENGTH_CONS(const void* codeAddr, int* rlength);
void SET_NTH_FIELD_OF_INSN(const rtx* insnAddr, int n, const void* fldt);
//void* PATTERN(INSN);   XEXP (INSN, 5)
void PATTERN_CONS(const rtx* insnAddr, void* patAddr);
//void* INSN_CODE(INSN); XINT(INSN, 6)
void PUT_INSN_CODE_CONS(rtx* insnAddr, void* codeAddr);
void INSN_CODE_CONS(const rtx* insnAddr, void* codeAddr);
int MARK_CONSTRAINT_VAR(const_rtx x);
int MARK_CONSTRAINT_VAR_CONS(const rtx* x);

/* Array accessor function */
void GET_ELEM_CONS (const void* arrAddr, unsigned int n, unsigned int i, 
        const void* xAddr);
void PUT_ELEM_CONS (const void* arrAddr, unsigned int n, unsigned int i, const void* x);

/* structure accessor function */
void GET_FIELD_CONS (const void* strAddr, unsigned int numfld, unsigned int fldno,
                     const char* fn, const void* xAddr);
void PUT_FIELD_CONS (const void* strAddr, unsigned int numfld, unsigned int fldno,
                             const char* fn, const void* x);

int are_sym_rtx_equal (rtx x, rtx y, void* x_addr, void* y_addr);
int is_rtx_null_trans (rtx x , rtx y , void *x_addr , void *y_addr);

int rtx_structurally_equal_p_trans (rtx x , rtx y , void *, void *,
                                   unsigned long long *);

/* Makes rtx x = y. Used while negating != constraint */
int EQUATE_RTX (rtx x, rtx y, void* xaddr, void* yaddr, unsigned long long* gcret);

/* Makes rtx x != y. Used while negating == constraint */
int CONTRAST_RTX (rtx x, rtx y, void* xaddr, void* yaddr, unsigned long long* gcret);

/* Printing related function */
int fprint_print(FILE*, const char* format, ...);
int putc_unlocked_print(char c, FILE*);
int fputs_unlocked_print(const char* s, FILE*);
char* symvar_to_string(void* addr);
#endif /* RTL_ACCESSORS_H */
