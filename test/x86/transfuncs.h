
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

#ifndef TRANSFUNCS_H
#define TRANSFUNCS_H

#define rtx void*
#define FILE void
#define addr_space_t unsigned char

/* recog related */

int recog_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_1_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_1_mem_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_1_reg_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_1_default_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_2_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_3_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_4_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_5_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_6_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_7_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_8_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_9_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_10_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_11_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_12_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_13_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_14_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_15_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_16_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_17_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_18_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_19_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_20_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_21_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_22_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_23_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_24_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_25_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_26_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_27_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_28_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_29_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_30_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_31_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_32_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_33_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_34_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_35_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_36_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_37_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_38_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_39_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_40_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_41_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_42_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_43_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_44_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_45_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_46_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_47_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);
int recog_48_trans (rtx, rtx, int*, void*, void*, void*, unsigned long long*);

/* utility functions */
void gcc_assert_trans (int, void*);
void gcc_assert (int);
void gcc_unreachable_trans ();
void gcc_unreachable ();
unsigned shleft_trans (unsigned, unsigned, void*, void*, unsigned long long*);
unsigned shright_trans (unsigned, unsigned, void*, void*, unsigned long long*);
unsigned band_trans (unsigned, unsigned, void*, void*, unsigned long long*);
unsigned bor_trans (unsigned, unsigned, void*, void*, unsigned long long*);
unsigned bxor_trans (unsigned, unsigned, void*, void*, unsigned long long*);

/* operand related */
int ext_register_operand_1_trans(rtx , enum machine_mode , void*, void*, unsigned long long * );; 
int ext_register_operand_trans(rtx , enum machine_mode, void*, void*, unsigned long long * );
int register_no_elim_operand_1_trans(rtx , enum machine_mode, void*, void*, unsigned long long * ); 
int register_no_elim_operand_trans(rtx , enum machine_mode, void*, void* , unsigned long long * ); 
int nonmemory_no_elim_operand_trans(rtx , enum machine_mode, void*, void* , unsigned long long * ); 
int const0_operand_1_trans(rtx , enum machine_mode, void*, void*, unsigned long long * ); 
int const0_operand_trans(rtx , enum machine_mode, void*, void*, unsigned long long * ); 
int const1_operand_trans(rtx , enum machine_mode, void*, void*, unsigned long long * ); 
int pic_symbolic_operand_1_trans (rtx op, enum machine_mode, void*, void*, unsigned long long*);
int pic_symbolic_operand_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int indec_operand_1_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int incdec_operand_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int aligned_operand_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int symbolic_operand_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int symbolic_operand_1_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);
int pic_32bit_operand_1_trans (rtx, enum machine_mode mode, void*, void*, unsigned long long*);
int q_regs_operand_1_trans (rtx, enum machine_mode mode, void*, void*, unsigned long long*);
int q_regs_operand_trans (rtx, enum machine_mode mode, void*, void*, unsigned long long*);
int vector_all_ones_operand_1_trans (rtx op, enum machine_mode, void*, void*, unsigned long long*);
int vector_all_ones_operand_trans (rtx op, enum machine_mode, void*, void*, unsigned long long*);

//unsigned get_mode_alignment_trans (enum machine_mode, void*, unsigned long long*);
enum rtx_code ix86_fp_compare_code_to_integer_trans(enum rtx_code code , void*, unsigned long long * );
int ix86_carry_flag_operator_1_trans(rtx, enum machine_mode, void*, void*, unsigned long long * );
int ix86_carry_flag_operator_trans(rtx, enum machine_mode, void*, void*, unsigned long long * ); 
int ix86_trivial_fp_comparison_operator_trans(rtx , enum machine_mode, void*, void* , unsigned long long * );
int float_operator_trans(rtx , enum machine_mode, void*, void* , unsigned long long * ); 
int mult_operator_trans(rtx, enum machine_mode, void*, void*, unsigned long long*);
int general_operand_trans(rtx , enum machine_mode ,void*, void* , unsigned long long * ); 
int register_operand_trans(rtx , enum machine_mode ,void*, void*, unsigned long long * ); 
int immediate_operand_trans(rtx , enum machine_mode , void*, void* , unsigned long long * ); 
int nonimmediate_operand_trans(rtx , enum machine_mode , void*, void* , unsigned long long * );
int nonmemory_operand_trans(rtx , enum machine_mode , void*, void*, unsigned long long * );
int push_operand_trans(rtx , enum machine_mode , void*, void* , unsigned long long * );
int memory_operand_trans(rtx, enum machine_mode, void*, void*, unsigned long long *);
int ix86_match_ccmode_trans (rtx, enum machine_mode, void*, void*, unsigned long
long);
int scratch_operand_trans(rtx, enum machine_mode, void *, void *, unsigned long
long);
unsigned char ix86_swap_binary_operands_p_trans(enum rtx_code code , enum machine_mode mode ,
                                                rtx *operands , void *__cil_tmp43 ,
                                                void *__cil_tmp46 , void *__cil_tmp49 ,
                                                unsigned long long *ret_gencount ) ;
//bool hard_reg_set_intersect_p (const HARD_REG_SET, const HARD_REG_SET, void*, void*, unsigned long long*);
int ix86_binary_operator_ok_trans(enum rtx_code code , enum machine_mode , rtx *operands , void*, void*, void* , unsigned long long * );
int ix86_unary_operator_ok_trans(enum rtx_code, enum machine_mode, rtx *, void*, void*, void*, unsigned long long *);
int memory_address_addr_space_p(enum machine_mode mode  __attribute__((__unused__)) ,
                                rtx addr , addr_space_t as ) ;
int rtx_equal_p_trans(rtx x , rtx y , void *__cil_tmp33 , void *__cil_tmp36 , unsigned long long *ret_gencount ) ;
int rtx_structurally_equal_p_trans(rtx x , rtx y , void* , void*, unsigned long long *ret_gencount);

bool legitimate_pic_operand_p_trans(rtx, unsigned long long);
int reg_classes_intersect_p_trans(enum reg_class c1 , enum reg_class c2 , void *__cil_tmp15 ,
                                  void *__cil_tmp18 , unsigned long long *ret_gencount ) ;

long trunc_int_for_mode_trans(long c , enum machine_mode mode , void *__cil_tmp16 ,
                              void *__cil_tmp19 , unsigned long long *ret_gencount ) ;
unsigned char ix86_cannot_change_mode_class_trans(enum machine_mode from , enum machine_mode to ,
                                                  enum reg_class regclass , void *__cil_tmp29 ,
                                                  void *__cil_tmp32 , void *__cil_tmp35 ,
                                                  unsigned long long *ret_gencount ) ;
__inline static int emms_operation_1_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                                           void *__cil_tmp54 , void *__cil_tmp57 ,
                                           unsigned long long *ret_gencount ) ;

int emms_operation_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                         void *__cil_tmp18 , void *__cil_tmp21 , unsigned long long *ret_gencount );

__inline static int vzeroall_operation_1_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                                               void *__cil_tmp43 , void *__cil_tmp46 ,
                                               unsigned long long *ret_gencount ) ;

int vzeroall_operation_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                             void *__cil_tmp18 , void *__cil_tmp21 , unsigned long long *ret_gencount );

__inline static int vzeroupper_operation_1_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                                                 void *__cil_tmp37 , void *__cil_tmp40 ,
                                                 unsigned long long *ret_gencount ) ;

int vzeroupper_operation_trans(rtx op , enum machine_mode mode  __attribute__((__unused__)) ,
                               void *__cil_tmp18 , void *__cil_tmp21 , unsigned long long *ret_gencount );

int const_int_operand_trans(rtx op , enum machine_mode mode , void *__cil_tmp19 ,
                            void *__cil_tmp22 , unsigned long long *ret_gencount );

int standard_sse_constant_p_trans (rtx, void*, unsigned long long*);
const char* standard_sse_constant_opcode_trans (rtx, rtx, void*, void*, unsigned long long*);

int avx_vpermilp_parallel (rtx, enum machine_mode, void*, void*, unsigned long long*);
int avx_vperm2f128_parallel_trans (rtx, enum machine_mode, void*, void*, unsigned long long*);

/* attribute related */
enum attr_type get_attr_type_trans(rtx insn  __attribute__((__unused__)) , void* ,
                                           unsigned long long *ret_gencount );
enum attr_mode get_attr_mode_trans(rtx insn, void*, unsigned long long*);
int get_attr_prefix_0f_trans(rtx insn, void*, unsigned long long*);
enum attr_unit get_attr_unit (rtx insn, void*, unsigned long long*);


/* Get insn template */
char const   *get_insn_template_trans(int, rtx, void*, void* , unsigned long long *);

/* Printing related functions */
void output_addr_const(FILE* file, rtx x, void*);
char *output_asm_insn_trans(char const *templ , rtx operands[], void*,
                            void*); 

void output_operand_trans(rtx x , int code , void*, void*);

int print_operand_trans(FILE *file , rtx x , int code , void*, void*);

void print_reg_trans(rtx x , int code , FILE *file , void* , void*);
int ix86_decompose_address (rtx addr, struct ix86_address *out, void*, unsigned long long*);
void print_operand_address (FILE *file, rtx addr, void*); 
bool output_addr_const_extra(FILE* file, rtx x, void*, unsigned long long*);

enum rtx_code reverse_condition_trans (enum rtx_code code, void*, unsigned long long*); 

enum rtx_code ix86_fp_compare_code_to_integer_trans (enum rtx_code code, void*, unsigned long long*);

void put_condition_code_trans (enum rtx_code code, enum machine_mode mode, int reverse,
		    int fp, FILE *file,
		    void*, void*, void*, void*, void*, unsigned long long*);

#if 0
output_387_reg_move
standard_80387_constant_opcode
output_fix_trunc
gen_lowpart

SIBLING_CALL_P
INSN_CODE

constant_call_address_operand
output_set_got
output_387_binary_op

$$$$ check output_701
exact_log2
standard_sse_constant_opcode
avx_vpermilp_parallel
avx_vperm2f128_parallel

optimize_function_for_size_p
which_alternative
#endif

#endif
