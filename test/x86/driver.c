
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
#include <unistd.h>
#include <stdio.h>

#include "symHelper.h"
#include "symVarList.h"
#include "cons_solve.h"

#define IN_GCC
#define IN_TRANSFORMED_CODE

#include "ansidecl.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl-trans.h"
#include "insn-config.h"
#include "recog.h"
#include "flags.h"
#include "insn-modes.h"
#include "genrtl.h"
#include "output.h"

//#include "rtl-accessors.h"
//#include "transfuncs.h"

void PUT_INSN_CODE_CONS(void*, void*);

element_t* _symVarList = NULL;

static const char **save_argv;
extern bool ggc_protect_identifiers;
extern const char *main_input_filename;
extern void* logcsfp;

void init_gcc(int argc, char** argv)
{
	save_argv = CONST_CAST2 (const char **, char **, argv);
	general_init (argv[0]);
	decode_options (argc, CONST_CAST2 (const char **, char **, argv));
	initialize_plugins();
	process_options();
	init_adjust_machine_modes ();
	backend_init ();
	lang_dependent_init (main_input_filename);
	ggc_protect_identifiers = true;
	init_cgraph ();
	init_final (main_input_filename);
}

static void set_symbolic_globals()
{
  SET_SYMBOLIC(&recog_data);
  SET_SYMBOLIC(recog_data.operand);
}

#define GET_CODE(RTX)       ((enum rtx_code) (RTX)->code)

void* stack_bottom;

static int prepare_printing(char* fname)
{
  // asm_out_file is the global variable used by gcc
  // to designate a file to which assembly instructions
  // are printed.
  if (asm_out_file != NULL)
  	fclose(asm_out_file);
	asm_out_file = fopen(fname, "w+");
  if (asm_out_file == NULL) {
  	perror("Error in fopen: ");
    return -1;
  }
  return 0;
}

// This function is supposed to be called after
// gcc has written assembly instructions to asm_out_file
char asm_name[128];
static char* get_asm_insn ()
{
	long fpos = 0;
  if((fpos = ftell (asm_out_file)) == -1) {
  	perror("Error in ftell: ");
		ERROR_PRINTF("Error in ftell:");
  	rewind (asm_out_file);
  	return NULL;
  }
    
  rewind (asm_out_file);

  assert (fpos < 128);
  memset (asm_name, 0, 128);
  if(fread (asm_name, 1, fpos, asm_out_file) != fpos) {
    	rewind (asm_out_file);
  	ERROR_PRINTF("Error in fread: ");
		return NULL;
	}

  rewind (asm_out_file);
  return asm_name;
}

int main(int argc, char* argv[])
{
  stack_bottom = &argv[argc];

  char* dummyargv[] = {"./main", "dummy.c"};
	init_gcc(2, dummyargv);
	init_recog();

#if 0
	char *opts = ix86_target_string (ix86_isa_flags, target_flags,
           ix86_arch_string, ix86_tune_string,
           ix86_fpmath_string, true);
#endif
	//fprintf(stderr, ix86_debug_options());
#if 0
    split_paths();
#endif

#if 0
		FILE* rfp = fopen("/tmp/rtx", "r");
		if (rfp == NULL) {
			perror("Error in fopen: ");
			return 0;
		}
		
		while(!feof(rfp)) {
			rtx x; int line;
			read_rtx(rfp, &x, &line);
			print_rtl_single(stdout, x);
		}
		return 0;
#endif

    logcs = 1;
    loglevel = INFO;
    initSym();
    begin();
    assert(prepare_printing(argv[1]) == 0);

    addNewRecord();
    set_symbolic_globals();

    rtx x0;
    rtx insn;
    rtx op;
    enum machine_mode mode;

    long long insn_code_gcount = 0;
    long long tmpl_gcount = 0;
    int pid, pid1, stat, insn_code, clobbers;
    const char* template;
    char asm_insn[128], *p;
#ifdef USE_FORK
    if((pid = fork()) == 0) {
#endif
        SET_GENCOUNT(&insn, 0); // 0 must be generation count for input
        //SET_GENCOUNT(&asm_insn[0], 1); // 1 must be generation count for output
        SET_GENCOUNT(&insn_code, 1); // 1 must be generation count for output
        PATTERN_CONS(&insn, &x0);
        SET_GENCOUNT(&clobbers, 10);

        // Step 1: get instruction code
#ifndef TEST_MODE
        insn_code = recog_1_trans (x0, insn, &clobbers, &x0, &insn, &clobbers, 
                                   &insn_code_gcount);
#else
        insn_code = recog_test_trans (x0, insn, &clobbers, &x0, &insn, &clobbers, 
                                   &insn_code_gcount);
#endif
				INFO_PRINTF("Insn_code: %d", insn_code);
        SET_GENCOUNT(&insn_code, insn_code_gcount);
//#define FIRST_STAGE_ONLY
#ifdef FIRST_STAGE_ONLY
				addOutput(it(insn_code));
				backTrack();
#else
        if (insn_code == -1) {
						addOutput(st("<NULL>"));
            backTrack();
				} else {
        		PUT_INSN_CODE_CONS(&insn, &insn_code);

        		// Step 2: get instruction template
        		template = get_insn_template_trans (insn_code, insn, 
                                            &insn_code, &insn,
                                            &tmpl_gcount);
						INFO_PRINTF("Template: %s", template ? template : "<NULL>");
						//addOutput(st(template));

						if (template != NULL) {
							// Step 3: get assembly instruction
							unsigned long long asm_insn_gcount;
							memset(asm_insn, 0, 128);
							p = &asm_insn[0];
							output_asm_insn_trans (template, recog_data.operand,
											 &template, recog_data.operand);
							addOutput(st(asm_insn));
							//INFO_PRINTF("Got asm insn: %s", asm_insn ? asm_insn : "<NULL>");
							//INFO_PRINTF("Read asm insn from file: %s", asm_insn ? asm_insn : "<NULL>");
						} else 
    					addOutput(st("<NULL>"));
    				//SET_GENCOUNT(&x0, 0); // 0 must be generation count for input
    				//rtx x1 = XEXP_CONS(&x0, 0, &x1);
    				//print_reg_trans(x1, 'k', asm_out_file, &x1, 0);
   					backTrack();
				}
#endif
#if USE_FORK
    } else {
        pid1 = wait(&stat);
        if (pid1 != pid)
            fatal("Unexpected error in wait");
        if (!WIFEXITED(stat))
            fatal("Unexpected exit by child");
        finish();
        //wait(&pid1);
    }
#endif


		/*
		if (insn_id != -1) {
			which_alternative = -1;
			extract_constrain_insn_cached (insn);

			const char* tmpl = get_insn_template (insn_id, insn);

			asm_out_file = fopen(argv[3], "w+");
			if (asm_out_file) {
				long before = ftell (asm_out_file);
								
				// Ask GCC to print assembly instruction
				output_asm_insn (tmpl, operands);
			}
		}*/

		return 0;
}



