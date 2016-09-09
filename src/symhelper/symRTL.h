
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

#ifndef SYMRTL_H
#define SYMRTL_H

struct symrtl;
typedef struct symrtl* symrtx;

/*
 * Maximum number of elements that can be present in 
 * the RTL vector. Currently, we think 15 should be 
 * enough, but if it turns out to be insufficient, then
 * we can increase the limit.
 *
 * We have to come up with this approach because the size of a 
 * vector can grow dynamically. So it is absolutely not possible
 * to determine maximum number of elements in vector while
 * we are in XVECEXP gcc accessor function.
 */
#define VEC_ELEM_SIZE 15

/*
 * Symbolic RTL vector
 */
struct symrtvec_def {
	char* num_elem;
	symrtx elem[VEC_ELEM_SIZE];
};

typedef struct symrtvec_def* symrtvec;

/* This is the maximum number of fields that can exist in 
 * RTL. We need to know this number beforehand because
 * in GCC accessor functions, we need to put a constraint
 * that the incoming parameter is of type rtx, and we need
 * to construct prolog term for rtx in the constraint. This
 * prolog term must be fully expanded (the term must have
 * the maximum number of possible fields in RTL), otherwise
 * we will face the issue of terms not matching on unification.
 *
 * Value 10 is determined empirically.
 */
#define FLD_SIZE 10

/*
 * Structure to represent symbolic RTL
 */
typedef struct symrtl {
    char* code;
    char* mode;
    char* jump;
    char* call;
    char* unchanging;
    char* volatil;
    char* in_struct;
    char* used;
    char* frame_related;
    char* return_val;

    struct symu {
      enum u_tag {
          RT_NONE,
          RT_UNION,
          RT_HOST_WIDE_INT,
          RT_BLOCK_SYMBOL,
          RT_REAL_VALUE,
          RT_FIXED_VALUE,
      } u_tag;

			union u_data {

				/* In case of RT_NONE */
      	char* u_name[FLD_SIZE];

				/* In case of RT_UNION */
      	struct symrtunion {
        	enum symrtunion_tag {
          	RT_INT,
          	RT_UINT,
						RT_STR,
          	RT_RTX,
						RT_RTVEC
        	} symrtunion_tag;

        	union symrtunion_def {
          	char* rt_int;
          	char* rt_uint;
          	char* rt_str;
          	symrtx rt_rtx;
						symrtvec rt_rtvec;
        	} symrtunion;
      	} fld[FLD_SIZE];

				/* RT_HOST_WIDE_INT */
      	char* hwint[FLD_SIZE];

      /* TODO: add these later */
			} u_data;
    } u;
} symrtl;

extern unsigned long long rtlCount;


/*
 * Initialise union field of rtl structure
 *
 * Params: symu [in/out]: pointer to struct symu
 *
 *         u_tag [in]: tag of data to set
 *
 *         fields of varargs:
 *
 *         if u_tag is RT_UNION, then 3rd parameter
 *         should be the field number out of 
 *         fld[] to set, and 4th parameter should be
 *         the type of that field out of RT_INT, RT_UINT, 
 *         and some others.
 *
 *         If you want to set all fields of RT_UNION, then
 *         pass 3rd parameter as -1.
 */
void init_symu (struct symu*, enum u_tag, ...);

/*
 * Generate new symbolic rtl structure.
 */
symrtx get_new_symrtl (void);

/*
 * Generate symbolic rtl vector
 */
symrtvec gen_rtvec_sym_val (unsigned int fldno);

/*
 * Get length of symbolic RTL vector if it is
 * printed.
 */
static int get_len_symrtvec (const symrtvec v);

/*
 * Get length of symbolic rtl if it is
 * printed.
 */
static int get_len_symrtl (const symrtx s);

/*
 * Return the symbolic RTL vector in printed form
 */
char* print_symrtvec (const symrtvec v);

/*
 * Return the symbolic rtl in printed
 * form.
 */
char* print_symrtl (const symrtx s);

/*
 * Free the symbolic rtl.
 */
void free_symrtl (symrtx s);

#endif /* SYMRTL_H */
