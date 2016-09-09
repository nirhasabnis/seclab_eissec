
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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#include "symRTL.h"

unsigned long long rtlCount = 0;

#define PREFIX "rtlacc_"
#define TERM_RTX "rtx"
#define TERM_RTVEC "rtvec"
#define TERM_RT_INT "rt_int"
#define TERM_RT_UINT "rt_uint"

static char* gen_sym_val (const char* str)
{
    if (!str)
      return NULL;

    /* Find out number of digits in the decimal
     * representation of count. */
    char count[24];
    memset (count, 0, 24);
    sprintf (count, "%lld", rtlCount);

    int len = strlen(PREFIX) + strlen(str) + strlen(count) + 1;

    char* s = (char*) malloc ( len );
    memset (s, 0, len);
    sprintf (s, "%s%s%s", PREFIX, str, count);

    return s;
}

symrtvec gen_rtvec_sym_val (unsigned int fldno)
{
		symrtvec vec = (symrtvec) malloc (sizeof (struct symrtvec_def));

		assert ((fldno >= 0) && (fldno <= FLD_SIZE));

		char buf[32];
		memset (buf, 0, 32);
		sprintf (buf, "num_elem%d", fldno);
		vec->num_elem = gen_sym_val (buf);

		int i = 0;
		for (i = 0; i < VEC_ELEM_SIZE; i++) {
			vec->elem[i] = get_new_symrtl ();
		}

		return vec;
}

void init_symu (struct symu* s, enum u_tag u_tag, ...)
{
		if (!s)
			return;

		switch (u_tag)
		{
				case RT_NONE:
					for (int i = 0; i < FLD_SIZE; i++) {
						char buf[32];
						memset (buf, 0, 32);
						sprintf (buf, "u_uname%d", i);
    				s->u_tag = RT_NONE;

						//if (s->u_data.u_name[i])
						//	free (s->u_data.u_name[i]);

    				s->u_data.u_name[i] = gen_sym_val (buf);
					}
				break;

				case RT_UNION:
				{
						va_list args;
						va_start (args, u_tag);

						int fldno = va_arg (args, int);
						enum symrtunion_tag tag = va_arg (args, enum symrtunion_tag);

						if (fldno == -1) {
							for (int i = 0; i < FLD_SIZE; i++) {
								char buf[32];
								memset (buf, 0, 32);

								switch (tag)
								{
										case RT_INT:
											sprintf (buf, "rt_int%d", i);
											s->u_data.fld[i].symrtunion.rt_int = gen_sym_val (buf);
											break;

										case RT_UINT:
											sprintf (buf, "rt_uint%d", i);
											s->u_data.fld[i].symrtunion.rt_uint = gen_sym_val (buf);
											break;

										case RT_RTX:
											s->u_data.fld[i].symrtunion.rt_rtx = get_new_symrtl ();
											break;

										case RT_RTVEC:
											s->u_data.fld[i].symrtunion.rt_rtvec = gen_rtvec_sym_val (i);
											break;
	
										case RT_STR: break;
								}

								s->u_tag = tag;
							}
						} else {
								char buf[32];
								memset (buf, 0, 32);

								assert (fldno > 0 && fldno < FLD_SIZE);

								switch (tag)
								{
										case RT_INT:
											sprintf (buf, "rt_int%d", fldno);
											s->u_data.fld[fldno].symrtunion.rt_int = gen_sym_val (buf);
											break;

										case RT_UINT:
											sprintf (buf, "rt_uint%d", fldno);
											s->u_data.fld[fldno].symrtunion.rt_uint = gen_sym_val (buf);
											break;

										case RT_RTX:
											s->u_data.fld[fldno].symrtunion.rt_rtx = get_new_symrtl ();
											break;

										case RT_RTVEC:
											s->u_data.fld[fldno].symrtunion.rt_rtvec = gen_rtvec_sym_val (fldno);
											break;
	
										case RT_STR: break;
								}

								s->u_tag = tag;
						}
				}
				break;

				case RT_HOST_WIDE_INT:
					for (int i = 0; i < FLD_SIZE; i++) {
						char buf[32];
						memset (buf, 0, 32);
						sprintf (buf, "hwint%d", i);
    				s->u_tag = RT_HOST_WIDE_INT;

						//if (s->u_data.hwint[i])
						//	free (s->u_data.hwint[i]);

    				s->u_data.hwint[i] = gen_sym_val (buf);
					}
					break;

				case RT_BLOCK_SYMBOL:
						/* TODO: */
				case RT_REAL_VALUE:
						/* TODO: */
				case RT_FIXED_VALUE:
						/* TODO: */
					break;
		}
}

symrtx get_new_symrtl (void)
{
    symrtx s = (symrtx) malloc (sizeof(symrtl));
    memset (s, 0, sizeof(symrtl));

    s->code          = gen_sym_val ("code");
    s->mode          = gen_sym_val ("mode");
    s->jump          = gen_sym_val ("jump");
    s->call          = gen_sym_val ("call");
    s->unchanging    = gen_sym_val ("unchanging");
    s->volatil       = gen_sym_val ("volatil");
    s->in_struct     = gen_sym_val ("in_struct");
    s->used          = gen_sym_val ("used");
    s->frame_related = gen_sym_val ("frame_related");
    s->return_val    = gen_sym_val ("return_val");

		init_symu (&s->u, RT_NONE);

    rtlCount++;

    return s;
}

static int get_len_symrtvec (const symrtvec v)
{
		int len = 0;

		if (!v)
			return len;

		len += strlen (TERM_RTVEC);
		len += strlen ("(");
		len += strlen (v->num_elem);
		len += strlen (",");

		for (int j = 0; j < VEC_ELEM_SIZE; j++) {
			len += get_len_symrtl (v->elem[j]);

			if (j != VEC_ELEM_SIZE - 1)
				len += strlen (",");
		}

		len += strlen (")");

		return len;
}

static int get_len_symrtl (const symrtx s)
{
    int len = 0;
    
    if (!s)
      return 0;

    len += strlen (TERM_RTX);
    len += strlen ("(");
    len += strlen (s->code);
    len += strlen (",");
    len += strlen (s->mode);
    len += strlen (",");
    len += strlen (s->jump);
    len += strlen (",");
    len += strlen (s->call);
    len += strlen (",");
    len += strlen (s->unchanging);
    len += strlen (",");
    len += strlen (s->volatil);
    len += strlen (",");
    len += strlen (s->in_struct);
    len += strlen (",");
    len += strlen (s->used);
    len += strlen (",");
    len += strlen (s->frame_related);
    len += strlen (",");
    len += strlen (s->return_val);
    len += strlen (",");

    switch (s->u.u_tag)
    {
        case RT_NONE:
						for (int i = 0; i < FLD_SIZE; i++) {
            	len += strlen (s->u.u_data.u_name[i]);
    					len += strlen (",");
						}
            break;

        case RT_UNION:
						for (int i = 0; i < FLD_SIZE; i++) {
            	switch (s->u.u_data.fld[i].symrtunion_tag)
            	{
                	case RT_INT:
                    len += strlen (TERM_RT_INT);
                    len += strlen ("(");
                    len += strlen (s->u.u_data.fld[i].symrtunion.rt_int);
                    len += strlen (")");
                    break;

                	case RT_UINT:
                    len += strlen (TERM_RT_UINT);
                    len += strlen ("(");
                    len += strlen (s->u.u_data.fld[i].symrtunion.rt_uint);
                    len += strlen (")");
                    break;

                	case RT_RTX:
                    len += get_len_symrtl (s->u.u_data.fld[i].symrtunion.rt_rtx);
										break;

									case RT_RTVEC:
										len += get_len_symrtvec (s->u.u_data.fld[i].symrtunion.rt_rtvec);
										break;

									case RT_STR: break;
            	}
    					len += strlen (",");
						}
            break;
            
        case RT_HOST_WIDE_INT:
						for (int i = 0; i < FLD_SIZE; i++) {
            	len += strlen (s->u.u_data.hwint[i]);
    					len += strlen (",");
						}
            break;

        default:
            break;
    }

    len += strlen (")");

    return len;
}

char* print_symrtvec (const symrtvec v)
{
		if (!v)
			return NULL;

		int len = get_len_symrtvec (v);
		char* out = (char*) malloc (len);
		memset (out, 0, len + 1);

		strcat (out, TERM_RTVEC);
		strcat (out, "(");
		strcat (out, v->num_elem);
    strcat (out, ",");

		for (int j = 0; j < VEC_ELEM_SIZE; j++) {
			strcat (out, print_symrtl (v->elem[j]));

			if (j != VEC_ELEM_SIZE - 1)
				strcat (out, ",");
		}

		strcat (out, ")");

		return out;
}

char* print_symrtl (const symrtx s)
{
    if (!s)
      return NULL;

    int len = get_len_symrtl (s);
    char* out = (char*) malloc (len + 1);
    memset (out, 0, len + 1);

    strcpy (out, TERM_RTX);
    strcat (out, "(");
    strcat (out, s->code);
    strcat (out, ",");
    strcat (out, s->mode);
    strcat (out, ",");
    strcat (out, s->jump);
    strcat (out, ",");
    strcat (out, s->call);
    strcat (out, ",");
    strcat (out, s->unchanging);
    strcat (out, ",");
    strcat (out, s->volatil);
    strcat (out, ",");
    strcat (out, s->in_struct);
    strcat (out, ",");
    strcat (out, s->used);
    strcat (out, ",");
    strcat (out, s->frame_related);
    strcat (out, ",");
    strcat (out, s->return_val);
    strcat (out, ",");
                              
    switch (s->u.u_tag)
    {
        case RT_NONE:
						for (int i = 0; i < FLD_SIZE; i++) {
            	strcat (out, s->u.u_data.u_name[i]);
							strcat (out, ",");
						}
            break;

        case RT_UNION:
						for (int i = 0; i < FLD_SIZE; i++) {
            	switch (s->u.u_data.fld[0].symrtunion_tag)
            	{
                case RT_INT:
                    strcat (out, TERM_RT_INT);
                    strcat (out, "(");
                    strcat (out, s->u.u_data.fld[0].symrtunion.rt_int);
                    strcat (out, ")");
                    break;

                case RT_UINT:
                    strcat (out, TERM_RT_UINT);
                    strcat (out, "(");
                    strcat (out, s->u.u_data.fld[0].symrtunion.rt_uint);
                    strcat (out, ")");
                    break;

                case RT_RTX:
                    strcat (out, print_symrtl (s->u.u_data.fld[0].symrtunion.rt_rtx));
										break;

								case RT_RTVEC:
										strcat (out, print_symrtvec (s->u.u_data.fld[0].symrtunion.rt_rtvec));

								case RT_STR: break;
            	}
							strcat (out, ",");
						}
            break;
            
        case RT_HOST_WIDE_INT:
						for (int i = 0; i < FLD_SIZE; i++) {
            	strcat (out, s->u.u_data.hwint[0]);
							strcat (out, ",");
						}
            break;

        default:
            break;
    }

    strcat (out, ")");

    return out;
}

void free_symrtl (symrtx s)
{
    if (!s)
      return;

    if (s->code)          free (s->code);
    if (s->mode)          free (s->mode);
    if (s->jump)          free (s->jump);
    if (s->call)          free (s->call);
    if (s->unchanging)    free (s->unchanging);
    if (s->volatil)       free (s->volatil);
    if (s->in_struct)     free (s->in_struct);
    if (s->used)          free (s->used);
    if (s->frame_related) free (s->frame_related);
    if (s->return_val)    free (s->return_val);

    switch (s->u.u_tag)
    {
        case RT_NONE:
						for (int i = 0; i < FLD_SIZE; i++)
            	if (s->u.u_data.u_name[i]) free (s->u.u_data.u_name[i]);
            break;

        case RT_UNION:
						for (int i = 0; i < FLD_SIZE; i++)
            	switch (s->u.u_data.fld[i].symrtunion_tag)
            	{
                case RT_INT:
                case RT_UINT:
                    if (s->u.u_data.fld[i].symrtunion.rt_int)
                      free (s->u.u_data.fld[i].symrtunion.rt_int);
                    break;

                case RT_RTX:
                     free_symrtl (s->u.u_data.fld[i].symrtunion.rt_rtx);
										 break;

								case RT_RTVEC:
										 {
										 		symrtvec vec = s->u.u_data.fld[i].symrtunion.rt_rtvec;
										 		if (vec) {
													if (vec->num_elem)
														free (vec->num_elem);

													for (int j = 0; j < VEC_ELEM_SIZE; j++) {
														if (vec->elem[j])
															free_symrtl (vec->elem[j]);
													}

													free (vec);
										 		}
										 }
										 break;

								case RT_STR: break;
            	}
            break;
            
        case RT_HOST_WIDE_INT:
						for (int i = 0; i < FLD_SIZE; i++)
            	if (s->u.u_data.hwint[i]) free (s->u.u_data.hwint[i]);
            break;

        default:
            break;
    }

    free (s);
}
