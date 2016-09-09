
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
#define IN_GCC
#define IN_TRANSFORMED_CODE
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl-trans.h"
#include "tm_p.h"
#include "insn-attr.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "flags.h"
#include "regs.h"
#include "hard-reg-set.h"
#include <inttypes.h>

enum rtx_code GET_CODE(rtx);
enum machine_mode GET_MODE(rtx);


#ifndef STACK_PUSH_CODE
#ifdef STACK_GROWS_DOWNWARD
#define STACK_PUSH_CODE PRE_DEC
#else
#define STACK_PUSH_CODE PRE_INC
#endif
#endif

#ifndef STACK_POP_CODE
#ifdef STACK_GROWS_DOWNWARD
#define STACK_POP_CODE POST_INC
#else
#define STACK_POP_CODE POST_DEC
#endif
#endif

extern FILE* asm_out_file;
int insn_counter;

#ifdef ASSEMBLER_DIALECT
/* Number of the assembler dialect to use, starting at 0.  */
static int dialect_number;
#endif

static unsigned int insn_noperands;

rtx this_is_asm_operands;
#define ASM_COMMENT_START '#'

#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))

int MARK_CONSTRAINT_VAR(rtx x);
void print_reg (rtx x, int code, FILE *file);
void print_operand (FILE *file, rtx x, int code); 
void output_operand (rtx x, int code ATTRIBUTE_UNUSED);
void put_condition_code (enum rtx_code code, enum machine_mode mode, int reverse,
		    int fp, FILE *file);
bool ix86_legitimate_address_p (enum machine_mode mode ATTRIBUTE_UNUSED, rtx addr, bool strict);

int rtx_structurally_equal_p (rtx, rtx);

#if 0
int
ext_register_operand_1 (rtx  op, enum machine_mode  mode)
//#line 58 "../../gcc/config/i386/predicates.md"
{
  if ((!TARGET_64BIT || GET_MODE (op) != DImode)
      && GET_MODE (op) != SImode && GET_MODE (op) != HImode)
    return 0;
  if (GET_CODE (op) == SUBREG)
    op = SUBREG_REG (op);

  /* Be careful to accept only registers having upper parts.  */
  return REGNO (op) > LAST_VIRTUAL_REGISTER || REGNO (op) < 4;
}

int
ext_register_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (register_operand (op, mode)) && (
(ext_register_operand_1 (op, mode)));
}

int
register_no_elim_operand_1 (rtx  op, enum machine_mode  mode ATTRIBUTE_UNUSED)
//#line 527 "../../gcc/config/i386/predicates.md"
{
  if (GET_CODE (op) == SUBREG)
    op = SUBREG_REG (op);
  return !(op == arg_pointer_rtx
	   || op == frame_pointer_rtx
	   || IN_RANGE (REGNO (op),
			FIRST_PSEUDO_REGISTER, LAST_VIRTUAL_REGISTER));
}


int
register_no_elim_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (register_operand (op, mode)) && (
(register_no_elim_operand_1 (op, mode)));
}

int
nonmemory_no_elim_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (register_no_elim_operand (op, mode)) || (immediate_operand (op, mode));
}

int
const0_operand_1 (rtx  op, enum machine_mode  mode ATTRIBUTE_UNUSED)
//#line 591 "../../gcc/config/i386/predicates.md"
{
  if (mode == VOIDmode)
    mode = GET_MODE (op);
  return op == CONST0_RTX (mode);
}

int
const0_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return 
(const0_operand_1 (op, mode));
}


int
const1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
//#line 600 "../../gcc/config/i386/predicates.md"
    (op == const1_rtx));
}
#endif

/*
unsigned int
get_mode_alignment (enum machine_mode mode)
{
  return MIN (BIGGEST_ALIGNMENT, MAX (1, mode_base_align[mode]*BITS_PER_UNIT));
}
*/

#if 0
int
misaligned_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == MEM) && (
//#line 1146 "../../gcc/config/i386/predicates.md"
//(MEM_ALIGN (op) < GET_MODE_ALIGNMENT (mode)))) && (
(mode == VOIDmode || GET_MODE (op) == mode)));
}
#endif

int
address_operand (rtx op, enum machine_mode mode)
{
  return memory_address_p (mode, op);
}

int
comparison_operator (rtx op, enum machine_mode mode)
{
  return ((mode == VOIDmode || GET_MODE (op) == mode)
	  && COMPARISON_P (op));
}

int
ix86_match_ccmode (rtx insn, enum machine_mode req_mode)
{
  rtx set;
  enum machine_mode set_mode;

  set = PATTERN (insn);
  if (GET_CODE (set) == PARALLEL)
    set = XVECEXP (set, 0, 0);
  gcc_assert (GET_CODE (set) == SET);
  gcc_assert (GET_CODE (SET_SRC (set)) == COMPARE);

  set_mode = GET_MODE (SET_DEST (set));
  switch (set_mode)
    {
    case CCNOmode:
      if (req_mode != CCNOmode
	  && (req_mode != CCmode
	      || XEXP (SET_SRC (set), 1) != const0_rtx))
	return 0;
      break;
    case CCmode:
      if (req_mode == CCGCmode)
	return 0;
      /* FALLTHRU */
    case CCGCmode:
      if (req_mode == CCGOCmode || req_mode == CCNOmode)
	return 0;
      /* FALLTHRU */
    case CCGOCmode:
      if (req_mode == CCZmode)
	return 0;
      /* FALLTHRU */
    case CCAmode:
    case CCCmode:
    case CCOmode:
    case CCSmode:
    case CCZmode:
      break;

    default:
      gcc_unreachable ();
    }

  return (GET_MODE (SET_SRC (set)) == set_mode);
}

/* Generate insn patterns to do an integer compare of OPERANDS.  */

/* Return 1 if OP should match a MATCH_SCRATCH, i.e., if it is a SCRATCH
   or a hard register.  */

int
scratch_operand (rtx op, enum machine_mode mode)
{
  if (GET_MODE (op) != mode && mode != VOIDmode)
    return 0;

  return (GET_CODE (op) == SCRATCH
	  || (REG_P (op)
	      && REGNO (op) < FIRST_PSEUDO_REGISTER));
}

enum rtx_code
ix86_fp_compare_code_to_integer (enum rtx_code code)
{
  switch (code)
    {
    case GT:
      return GTU;
    case GE:
      return GEU;
    case ORDERED:
    case UNORDERED:
      return code;
      break;
    case UNEQ:
      return EQ;
      break;
    case UNLT:
      return LTU;
      break;
    case UNLE:
      return LEU;
      break;
    case LTGT:
      return NE;
      break;
    default:
      return UNKNOWN;
    }
}

#if 0
int
ix86_carry_flag_operator_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
//#line 1055 "../../gcc/config/i386/predicates.md"
{
  enum machine_mode inmode = GET_MODE (XEXP (op, 0));
  enum rtx_code code = GET_CODE (op);

  if (inmode == CCFPmode || inmode == CCFPUmode)
    {
      if (!ix86_trivial_fp_comparison_operator (op, mode))
	return 0;
      code = ix86_fp_compare_code_to_integer (code);
    }
  else if (inmode == CCCmode)
   return code == LTU || code == GTU;
  else if (inmode != CCmode)
    return 0;

  return code == LTU;
}

int
ix86_carry_flag_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case LTU:
    case LT:
    case UNLT:
    case GTU:
    case GT:
    case UNGT:
    case LE:
    case UNLE:
    case GE:
    case UNGE:
    case LTGT:
    case UNEQ:
      break;
    default:
      return false;
    }
  return (
(ix86_carry_flag_operator_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
ix86_trivial_fp_comparison_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case GT:
    case GE:
    case UNLT:
    case UNLE:
    case UNEQ:
    case LTGT:
    case ORDERED:
    case UNORDERED:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
float_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == FLOAT) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
mult_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == MULT) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}
#endif

int
general_operand (rtx op, enum machine_mode mode)
{
  enum rtx_code code = GET_CODE (op);

  if (mode == VOIDmode)
    mode = GET_MODE (op);

  /* Don't accept CONST_INT or anything similar
     if the caller wants something floating.  */
  if (GET_MODE (op) == VOIDmode && mode != VOIDmode
      /*&& GET_MODE_CLASS (mode) != MODE_INT*/
			&&	 !GET_MODE_CLASS_EQ_MODE_INT(mode)
      /*&& GET_MODE_CLASS (mode) != MODE_PARTIAL_INT)*/
		  && !GET_MODE_CLASS_EQ_MODE_PARTIAL_INT(mode))
    return 0;

  if (CONST_INT_P (op)
      && mode != VOIDmode
      && trunc_int_for_mode (INTVAL (op), mode) != INTVAL (op))
    return 0;

  if (CONSTANT_P (op))
    return ((GET_MODE (op) == VOIDmode || GET_MODE (op) == mode
	     || mode == VOIDmode)
	    && (! flag_pic || LEGITIMATE_PIC_OPERAND_P (op))
	    && LEGITIMATE_CONSTANT_P (op));

  /* Except for certain constants with VOIDmode, already checked for,
     OP's mode must match MODE if MODE specifies a mode.  */

  if (GET_MODE (op) != mode)
    return 0;

  if (code == SUBREG)
    {
      rtx sub = SUBREG_REG (op);

#ifdef INSN_SCHEDULING
      /* On machines that have insn scheduling, we want all memory
	 reference to be explicit, so outlaw paradoxical SUBREGs.
	 However, we must allow them after reload so that they can
	 get cleaned up by cleanup_subreg_operands.  */
      if (!reload_completed && MEM_P (sub)
	  && GET_MODE_SIZE (mode) > GET_MODE_SIZE (GET_MODE (sub)))
	return 0;
#endif
      /* Avoid memories with nonzero SUBREG_BYTE, as offsetting the memory
         may result in incorrect reference.  We should simplify all valid
         subregs of MEM anyway.  But allow this after reload because we
	 might be called from cleanup_subreg_operands.

	 ??? This is a kludge.  */
      if (!reload_completed && SUBREG_BYTE (op) != 0
	  && MEM_P (sub))
	return 0;

      /* FLOAT_MODE subregs can't be paradoxical.  Combine will occasionally
	 create such rtl, and we must reject it.  */
      if (SCALAR_FLOAT_MODE_P (GET_MODE (op))
	  && GET_MODE_SIZE (GET_MODE (op)) > GET_MODE_SIZE (GET_MODE (sub)))
	return 0;

      op = sub;
      code = GET_CODE (op);
    }

  if (code == REG)
    /* A register whose class is NO_REGS is not a general operand.  */
    return (REGNO (op) >= FIRST_PSEUDO_REGISTER
	    || /*REGNO_REG_CLASS (REGNO (op)) != NO_REGS*/
				 !REGNO_REG_CLASS_EQ_NO_REGS(REGNO(op)));

  if (code == MEM)
    {
      rtx y = XEXP (op, 0);

      if (! volatile_ok && MEM_VOLATILE_P (op))
	       return 0;
      
      /* Use the mem's mode, since it will be reloaded thus.  */
      /*TODO: rm if (memory_address_addr_space_p (GET_MODE (op), y, MEM_ADDR_SPACE (op)))
	return 1;*/
       if (ix86_legitimate_address_p(GET_MODE(op), y, true))
        return 1;
    }

  return 0;
}


bool
ix86_legitimate_address_p (enum machine_mode mode ATTRIBUTE_UNUSED,
               rtx addr, bool strict)
{
  rtx base = NULL_RTX, index = NULL_RTX, disp = NULL_RTX;
  int scale = 1;
  rtx base_reg, index_reg;
  rtx scale_rtx = NULL_RTX;
  enum ix86_address_seg seg = SEG_DEFAULT;
  int ok = 1;

  // we have inlined ix86_decompose_address below.
  //int ok = ix86_decompose_address (addr, parts);

  if (REG_P (addr) || GET_CODE (addr) == SUBREG)
    base = addr;
#if 0
  else if (GET_CODE (addr) == PLUS)
    {
          rtx addends[4] ATTRIBUTE_SYMBOLIC, op;
          rtx op0, op1, op2, op3;
          rtx op0_, op1_, op2_, op3_;
          int n = 0, i;

          op = addr;

          // Code commented below is written into code marked in
          // /* -- */ block. This is done to avoid looping condition
          // based on symbolic variable.
          //
          // do
          // {
          //  if (n >= 4) {
          //    ok = 0;
          //    goto out;
          //  }
          //  addends[n++] = XEXP (op, 1);
          //  op = XEXP (op, 0);
          // } while (GET_CODE (op) == PLUS);

          /* -- */

          op0 = XEXP(op, 1); n++;
          op0_ = XEXP(op, 0);
          if (GET_CODE(op0_) != PLUS)
            goto next;

          op1 = XEXP(op0, 1); n++;
          op1_ = XEXP(op0, 0);
          if (GET_CODE(op1_) != PLUS)
            goto next;

          op2 = XEXP(op1, 1); n++;
          op2_ = XEXP(op1, 0);
          if (GET_CODE(op2_) != PLUS)
            goto next;

          op3 = XEXP(op2, 1); n++;
          op3_ = XEXP(op2, 0);
          if (GET_CODE(op3_) != PLUS)
            goto next;

          ok = 0;
          goto out;
      
          next:
          switch(n) {
            case 1: addends[0] = op0; op = op0_; break;
            case 2: addends[0] = op0; addends[1] = op1; op = op1_; break;
            case 3: addends[0] = op0; addends[1] = op1;
                    addends[2] = op2; op = op2_; break;
            case 4: addends[0] = op0; addends[1] = op1;
                    addends[2] = op2; addends[3] = op3; op = op3_; break;
            default: gcc_unreachable();
          }

          /* -- */

          if (n >= 4) {
            ok = 0;
            goto out;
          }
          addends[n] = op;

          for (i = n; i >= 0; --i)
          {
              op = addends[i];
              switch (GET_CODE (op)) 
              {
                case MULT:
                  if (index) {
                    ok = 0;
                    goto out;
                  }
                  index = XEXP (op, 0);
                  scale_rtx = XEXP (op, 1);
                  break;

                case UNSPEC:
                  if (XINT (op, 1) == UNSPEC_TP
                      && TARGET_TLS_DIRECT_SEG_REFS
                      && seg == SEG_DEFAULT)
                      seg = TARGET_64BIT ? SEG_FS : SEG_GS;
                  else {
                      ok = 0;
                      goto out;
                  }
                  break;

                case REG:
                case SUBREG:
                  if (!base)
                      base = op;
                  else if (!index)
                      index = op;
                  else {
                      ok = 0;
                      goto out;
                  }
                  break;

                case CONST:
                case CONST_INT:
                case SYMBOL_REF:
                case LABEL_REF:
                  if (disp) {
                    ok = 0;
                    goto out;
                  }
                  disp = op;
                  break;

                default: 
                  ok = 0;
                  goto out;
              }
          }
    }
  #endif
  else if (GET_CODE (addr) == MULT)
    {
      index = XEXP (addr, 0);   /* index*scale */
      scale_rtx = XEXP (addr, 1);
    }
  else if (GET_CODE (addr) == ASHIFT)
    {
      rtx tmp;

      /* We're called for lea too, which implements ashift on occasion.  */
      index = XEXP (addr, 0);
      tmp = XEXP (addr, 1);
      if (!CONST_INT_P (tmp)) {
        ok = 0; goto out;
      }
      scale = INTVAL (tmp);
      if ((unsigned HOST_WIDE_INT) scale > 3) {
        ok = 0; goto out;
      }
      //scale = 1 << scale;
      // replacing << operator by expanding its semantics.
      switch(scale) {
        case 0: scale = 1; break;
        case 1: scale = 2; break;
        case 2: scale = 4; break;
        case 3: scale = 8; break;
        default: gcc_unreachable();
      }
      ok = -1;
    }
  
  else
    disp = addr;      /* displacement */

  /* Extract the integral value of scale.  */
  if (scale_rtx)
  {
      if (!CONST_INT_P (scale_rtx))
        ok = 0;
      scale = INTVAL (scale_rtx);
  }

  base_reg = base != NULL_RTX && GET_CODE (base) == SUBREG ? SUBREG_REG (base) : base;
  index_reg = index != NULL_RTX && GET_CODE (index) == SUBREG ? SUBREG_REG (index) : index;

  /* Avoid useless 0 displacement.  */
  if (disp == const0_rtx && (base || index))
    disp = NULL_RTX;

  /* Allow arg pointer and stack pointer as index if there is not scaling.  */
  if (base_reg && index_reg && scale == 1 &&
      (index_reg == arg_pointer_rtx ||
       index_reg == frame_pointer_rtx ||
       (REG_P (index_reg) && REGNO (index_reg) == STACK_POINTER_REGNUM)))
  {
      rtx tmp;
      tmp = base, base = index, index = tmp;
      tmp = base_reg, base_reg = index_reg, index_reg = tmp;
  }

  /* Special case: %ebp cannot be encoded as a base without a displacement.
     Similarly %r13.  */
  if (!disp
      && base_reg
      && (base_reg == hard_frame_pointer_rtx
    || base_reg == frame_pointer_rtx
    || base_reg == arg_pointer_rtx
    || (REG_P (base_reg)
        && (REGNO (base_reg) == HARD_FRAME_POINTER_REGNUM
      || REGNO (base_reg) == R13_REG))))
    disp = const0_rtx;

  /* Special case: scaling cannot be encoded without base or displacement.  */
  if (!base && !disp && index && scale != 1)
    disp = const0_rtx;

  out:

  //if (ix86_decompose_address (addr, &parts) <= 0)
    /* Decomposition failed.  */
  //return false;

  if(ok <= 0)
      return false;

  // base = parts.base;
  // index = parts.index;
  // disp = parts.disp;
  // scale = parts.scale;

  /* Validate base register.

     Don't allow SUBREG's that span more than a word here.  It can lead to spill
     failures when the base is one word out of a two word structure, which is
     represented internally as a DImode int.  */

  if (base)
    {
      rtx reg;

      if (REG_P (base))
          reg = base;
      else if (GET_CODE (base) == SUBREG
         && REG_P (SUBREG_REG (base))
         && GET_MODE_SIZE (GET_MODE (SUBREG_REG (base))) <= UNITS_PER_WORD)
          reg = SUBREG_REG (base);
      else
        /* Base is not a register.  */
        return false;

      if (GET_MODE (base) != Pmode)
        /* Base is not in Pmode.  */
        return false;

      if ((strict && ! REG_OK_FOR_BASE_STRICT_P (reg))
        || (! strict && ! REG_OK_FOR_BASE_NONSTRICT_P (reg)))
        /* Base is not valid.  */
        return false;
    }

  /* Validate index register.

     Don't allow SUBREG's that span more than a word here -- same as above.  */

  if (index)
  {
          rtx reg;

      if (REG_P (index))
          reg = index;
      else if (GET_CODE (index) == SUBREG
             && REG_P (SUBREG_REG (index))
             && GET_MODE_SIZE (GET_MODE (SUBREG_REG (index))) <= UNITS_PER_WORD)
        reg = SUBREG_REG (index);
      else
        /* Index is not a register.  */
        return false;

          if (GET_MODE (index) != Pmode)
      /* Index is not in Pmode.  */
      return false;

          if ((strict && ! REG_OK_FOR_INDEX_STRICT_P (reg))
        || (! strict && ! REG_OK_FOR_INDEX_NONSTRICT_P (reg)))
      /* Index is not valid.  */
      return false;
  }

  /* Validate scale factor.  */
  if (scale != 1)
  {
      if (!index)
        /* Scale without index.  */
        return false;

      if (scale != 2 && scale != 4 && scale != 8)
        /* Scale is not a valid multiplier.  */
        return false;
  }

  /* Validate displacement.  */
  if (disp)
  {
      if (GET_CODE (disp) == CONST
      && GET_CODE (XEXP (disp, 0)) == UNSPEC
      && XINT (XEXP (disp, 0), 1) != UNSPEC_MACHOPIC_OFFSET)
      switch (XINT (XEXP (disp, 0), 1))
      {
        /* Refuse GOTOFF and GOT in 64bit mode since it is always 64bit when
           used.  While ABI specify also 32bit relocations, we don't produce
           them at all and use IP relative instead.  */
        case UNSPEC_GOT:
        case UNSPEC_GOTOFF:
        case UNSPEC_GOTPCREL:
        case UNSPEC_GOTTPOFF:
        case UNSPEC_GOTNTPOFF:
        case UNSPEC_INDNTPOFF:
        case UNSPEC_NTPOFF:
        case UNSPEC_DTPOFF:
          return false;
          break;

        default:
          /* Invalid address unspec.  */
          return false;
      }
  }

  /* Everything looks valid.  */
  return true;
}


int
register_operand (rtx op, enum machine_mode mode)
{
  if (GET_MODE (op) != mode && mode != VOIDmode)
    return 0;

  if (GET_CODE (op) == SUBREG)
    {
      rtx sub = SUBREG_REG (op);

      /* Before reload, we can allow (SUBREG (MEM...)) as a register operand
	 because it is guaranteed to be reloaded into one.
	 Just make sure the MEM is valid in itself.
	 (Ideally, (SUBREG (MEM)...) should not exist after reload,
	 but currently it does result from (SUBREG (REG)...) where the
	 reg went on the stack.)  */
      if (! reload_completed && MEM_P (sub))
	return general_operand (op, mode);

#ifdef CANNOT_CHANGE_MODE_CLASS
      if (REG_P (sub)
	  && REGNO (sub) < FIRST_PSEUDO_REGISTER
	  && REG_CANNOT_CHANGE_MODE_P (REGNO (sub), GET_MODE (sub), mode)
	  && !GET_MODE_CLASS_EQ_MODE_COMPLEX_INT(GET_MODE(sub))
	  && !GET_MODE_CLASS_EQ_MODE_COMPLEX_FLOAT(GET_MODE (sub)))
	return 0;
#endif

      /* FLOAT_MODE subregs can't be paradoxical.  Combine will occasionally
	 create such rtl, and we must reject it.  */
      if (SCALAR_FLOAT_MODE_P (GET_MODE (op))
	  && GET_MODE_SIZE (GET_MODE (op)) > GET_MODE_SIZE (GET_MODE (sub)))
	return 0;

      op = sub;
    }

  /* We don't consider registers whose class is NO_REGS
     to be a register operand.  */
  return (REG_P (op)
	  && (REGNO (op) >= FIRST_PSEUDO_REGISTER
	      || !REGNO_REG_CLASS_EQ_NO_REGS(REGNO(op))));
}

/* Nonzero if the constant value X is a legitimate general operand
   when generating PIC code.  It is given that flag_pic is on and
   that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
bool
legitimate_pic_operand_p (rtx x)
{
  rtx inner;

  switch (GET_CODE (x))
    {
    case CONST:
      inner = XEXP (x, 0);
      if (GET_CODE (inner) == PLUS
	  && CONST_INT_P (XEXP (inner, 1)))
	inner = XEXP (inner, 0);

      /* Only some unspecs are valid as "constants".  */
      if (GET_CODE (inner) == UNSPEC)
	switch (XINT (inner, 1))
	  {
	  case UNSPEC_GOT:
	  case UNSPEC_GOTOFF:
	  case UNSPEC_PLTOFF:
	    return TARGET_64BIT;
	  case UNSPEC_TPOFF:
	    x = XVECEXP (inner, 0, 0);
	    return (GET_CODE (x) == SYMBOL_REF
		    && SYMBOL_REF_TLS_MODEL (x) == TLS_MODEL_LOCAL_EXEC);
	  //TODO: rm case UNSPEC_MACHOPIC_OFFSET:
	  //  return legitimate_pic_address_disp_p (x);
	  default:
	    return false;
	  }
      /* FALLTHRU */

    case SYMBOL_REF:
    //TODO: rm case LABEL_REF:
    //  return legitimate_pic_address_disp_p (x);

    default:
      return true;
    }
}

bool
legitimate_constant_p (rtx x)
{
  switch (GET_CODE (x))
    {
    case CONST:
      x = XEXP (x, 0);

      if (GET_CODE (x) == PLUS)
  {
    if (!CONST_INT_P (XEXP (x, 1)))
      return false;
    x = XEXP (x, 0);
  }

      if (TARGET_MACHO && darwin_local_data_pic (x))
  return true;

      /* Only some unspecs are valid as "constants".  */
      if (GET_CODE (x) == UNSPEC)
  switch (XINT (x, 1))
    {
    case UNSPEC_GOT:
    case UNSPEC_GOTOFF:
    case UNSPEC_PLTOFF:
      return TARGET_64BIT;
    case UNSPEC_TPOFF:
    case UNSPEC_NTPOFF:
      x = XVECEXP (x, 0, 0);
      return (GET_CODE (x) == SYMBOL_REF
        && SYMBOL_REF_TLS_MODEL (x) == TLS_MODEL_LOCAL_EXEC);
    case UNSPEC_DTPOFF:
      x = XVECEXP (x, 0, 0);
      return (GET_CODE (x) == SYMBOL_REF
        && SYMBOL_REF_TLS_MODEL (x) == TLS_MODEL_LOCAL_DYNAMIC);
    default:
      return false;
    }

      /* We must have drilled down to a symbol.  */
      if (GET_CODE (x) == LABEL_REF)
  return true;
      if (GET_CODE (x) != SYMBOL_REF)
  return false;
      /* FALLTHRU */

    case SYMBOL_REF:
      /* TLS symbols are never valid.  */
      if (SYMBOL_REF_TLS_MODEL (x))
  return false;

      /* DLLIMPORT symbols are never valid.  */
      if (TARGET_DLLIMPORT_DECL_ATTRIBUTES
    && SYMBOL_REF_DLLIMPORT_P (x))
  return false;
      break;

    case CONST_DOUBLE:
      if (GET_MODE (x) == TImode
    && x != CONST0_RTX (TImode)
          && !TARGET_64BIT)
  return false;
      break;

/* TODO: removed since we dont want SSE for now.
    case CONST_VECTOR:
      if (!standard_sse_constant_p (x))
  return false;
*/

    default:
      break;
    }

  /* Otherwise we handle everything else in the move patterns.  */
  return true;
}


int
immediate_operand (rtx op, enum machine_mode mode)
{
  /* Don't accept CONST_INT or anything similar
     if the caller wants something floating.  */
  if (GET_MODE (op) == VOIDmode && mode != VOIDmode
      /*&& GET_MODE_CLASS (mode) != MODE_INT*/
			&&	 !GET_MODE_CLASS_EQ_MODE_INT(mode)
      /*&& GET_MODE_CLASS (mode) != MODE_PARTIAL_INT)*/
		  && !GET_MODE_CLASS_EQ_MODE_PARTIAL_INT(mode))
    return 0;

  if (CONST_INT_P (op)
      && mode != VOIDmode
      && trunc_int_for_mode (INTVAL (op), mode) != INTVAL (op))
    return 0;

  return (CONSTANT_P (op)
	  && (GET_MODE (op) == mode || mode == VOIDmode
	      || GET_MODE (op) == VOIDmode)
	  && (! flag_pic || LEGITIMATE_PIC_OPERAND_P (op))
	  && LEGITIMATE_CONSTANT_P (op));
}

int
nonimmediate_operand (rtx op, enum machine_mode mode)
{
  return (general_operand (op, mode) && ! CONSTANT_P (op));
}

/* Return 1 if OP is a register reference or immediate value of mode MODE.  */

int
nonmemory_operand (rtx op, enum machine_mode mode)
{
  if (CONSTANT_P (op))
    {
      /* Don't accept CONST_INT or anything similar
	 if the caller wants something floating.  */
      if (GET_MODE (op) == VOIDmode && mode != VOIDmode
      /*&& GET_MODE_CLASS (mode) != MODE_INT*/
			&&	 !GET_MODE_CLASS_EQ_MODE_INT(mode)
      /*&& GET_MODE_CLASS (mode) != MODE_PARTIAL_INT)*/
		  && !GET_MODE_CLASS_EQ_MODE_PARTIAL_INT(mode))
	return 0;

      if (CONST_INT_P (op)
	  && mode != VOIDmode
	  && trunc_int_for_mode (INTVAL (op), mode) != INTVAL (op))
	return 0;

      return ((GET_MODE (op) == VOIDmode || GET_MODE (op) == mode
	       || mode == VOIDmode)
	      && (! flag_pic || LEGITIMATE_PIC_OPERAND_P (op))
	      && LEGITIMATE_CONSTANT_P (op));
    }

  if (GET_MODE (op) != mode && mode != VOIDmode)
    return 0;

  if (GET_CODE (op) == SUBREG)
    {
      /* Before reload, we can allow (SUBREG (MEM...)) as a register operand
	 because it is guaranteed to be reloaded into one.
	 Just make sure the MEM is valid in itself.
	 (Ideally, (SUBREG (MEM)...) should not exist after reload,
	 but currently it does result from (SUBREG (REG)...) where the
	 reg went on the stack.)  */
      if (! reload_completed && MEM_P (SUBREG_REG (op)))
	return general_operand (op, mode);
      op = SUBREG_REG (op);
    }

  /* We don't consider registers whose class is NO_REGS
     to be a register operand.  */
  return (REG_P (op)
	  && (REGNO (op) >= FIRST_PSEUDO_REGISTER
	      || /*REGNO_REG_CLASS (REGNO (op)) != NO_REGS));*/
				 !REGNO_REG_CLASS_EQ_NO_REGS(REGNO(op))));
}

/* Return 1 if OP is a valid operand that stands for pushing a
   value of mode MODE onto the stack.

   The main use of this function is as a predicate in match_operand
   expressions in the machine description.  */

int
push_operand (rtx op, enum machine_mode mode)
{
  unsigned int rounded_size = GET_MODE_SIZE (mode);
#ifdef PUSH_ROUNDING
  rounded_size = PUSH_ROUNDING (rounded_size);
#endif

  if (!MEM_P(op))
    return 0;

  if (mode != VOIDmode && GET_MODE (op) != mode)
    return 0;

  op = XEXP (op, 0);

  if (rounded_size == GET_MODE_SIZE (mode))
    {
      if (GET_CODE (op) != STACK_PUSH_CODE)
	return 0;
    }
  else
    {
      if (GET_CODE (op) != PRE_MODIFY
	  || GET_CODE (XEXP (op, 1)) != PLUS
	  || XEXP (XEXP (op, 1), 0) != XEXP (op, 0)
	  || !CONST_INT_P (XEXP (XEXP (op, 1), 1))
#ifdef STACK_GROWS_DOWNWARD
	  || INTVAL (XEXP (XEXP (op, 1), 1)) != - (int) rounded_size
#else
	  || INTVAL (XEXP (XEXP (op, 1), 1)) != (int) rounded_size
#endif
	  )
	return 0;
    }

  return XEXP (op, 0) == stack_pointer_rtx;
}

int
memory_operand (rtx op, enum machine_mode mode)
{
  rtx inner;

  if (! reload_completed)
    /* Note that no SUBREG is a memory operand before end of reload pass,
       because (SUBREG (MEM...)) forces reloading into a register.  */
   return MEM_P (op) && general_operand (op, mode);

  if (mode != VOIDmode && GET_MODE (op) != mode)
    return 0;

  inner = op;
  if (GET_CODE (inner) == SUBREG)
    inner = SUBREG_REG (inner);

  return (MEM_P (inner) && general_operand (op, mode));
}

/* Helper function of ix86_fixup_binary_operands to canonicalize
   operand order.  Returns true if the operands should be swapped.  */

bool
ix86_swap_binary_operands_p (enum rtx_code code, enum machine_mode mode,
			     rtx operands[])
{
  rtx dst = recog_data.operand[0];
  rtx src1 = recog_data.operand[1];
  rtx src2 = recog_data.operand[2];

  /* If the operation is not commutative, we can't do anything.  */
  if (!GET_RTX_CLASS_EQ_RTX_COMM_ARITH(code))
    return false;

  /* Highest priority is that src1 should match dst.  */
  if (rtx_equal_p (dst, src1))
    return false;
  if (rtx_equal_p (dst, src2))
    return true;

  /* Next highest priority is that immediate constants come second.  */
  if (immediate_operand (src2, mode))
    return false;
  if (immediate_operand (src1, mode))
    return true;

  /* Lowest priority is that memory references should come second.  */
  if (MEM_P (src2))
    return false;
  if (MEM_P (src1))
    return true;

  return false;
}

int
ix86_binary_operator_ok (enum rtx_code code, enum machine_mode mode,
			 rtx operands[3])
{
  rtx dst = recog_data.operand[0];
  rtx src1 = recog_data.operand[1];
  rtx src2 = recog_data.operand[2];

  /* Both source operands cannot be in memory.  */
  if (MEM_P (src1) && MEM_P (src2))
    return 0;

  /* Canonicalize operand order for commutative operators.  */
  if (ix86_swap_binary_operands_p (code, mode, operands))
    {
      rtx temp = src1;
      src1 = src2;
      src2 = temp;
    }

  /* If the destination is memory, we must have a matching source operand.  */
  if (MEM_P (dst) && !rtx_equal_p (dst, src1))
      return 0;

  /* Source 1 cannot be a constant.  */
  if (CONSTANT_P (src1))
    return 0;

  /* Source 1 cannot be a non-matching memory.  */
  if (MEM_P (src1) && !rtx_equal_p (dst, src1))
    return 0;

  return 1;
}


/* Return TRUE or FALSE depending on whether the unary operator meets the
   appropriate constraints.  */

int
ix86_unary_operator_ok (enum rtx_code code ATTRIBUTE_UNUSED,
			enum machine_mode mode ATTRIBUTE_UNUSED,
			rtx operands[2] ATTRIBUTE_UNUSED)
{
  /* If one of operands is memory, source and destination must match.  */
  if ((MEM_P (recog_data.operand[0])
       || MEM_P (recog_data.operand[1]))
      && ! rtx_equal_p (recog_data.operand[0], recog_data.operand[1]))
    return FALSE;
  return TRUE;
}
int
memory_address_addr_space_p (enum machine_mode mode ATTRIBUTE_UNUSED,
			     rtx addr, addr_space_t as)
{
#ifdef GO_IF_LEGITIMATE_ADDRESS
  gcc_assert (ADDR_SPACE_GENERIC_P (as));
  GO_IF_LEGITIMATE_ADDRESS (mode, addr, win);
  return 0;

 win:
  return 1;
#else
  //return targetm.addr_space.legitimate_address_p (mode, addr, 0, as);
#endif
}

/* Return 1 if X is all 0s and 2 if x is all 1s
   in supported SSE vector mode.  */

int
standard_sse_constant_p (rtx x)
{
  enum machine_mode mode = GET_MODE (x);

  if (x == const0_rtx || x == CONST0_RTX (GET_MODE (x)))
    return 1;
  if (/*vector_all_ones_operand (x, mode)*/1)
    switch (mode)
      {
      case V16QImode:
      case V8HImode:
      case V4SImode:
      case V2DImode:
	if (TARGET_SSE2)
	  return 2;
      default:
	break;
      }

  return 0;
}

/* Return the opcode of the special instruction to be used to load
   the constant X.  */

const char *
standard_sse_constant_opcode (rtx insn, rtx x)
{
  switch (standard_sse_constant_p (x))
    {
    case 1:
      switch (/*get_attr_mode (insn)*/1)
	{
	case MODE_V4SF:
	  return TARGET_AVX ? "vxorps\t%0, %0, %0" : "xorps\t%0, %0";
	case MODE_V2DF:
	  return TARGET_AVX ? "vxorpd\t%0, %0, %0" : "xorpd\t%0, %0";
	case MODE_TI:
	  return TARGET_AVX ? "vpxor\t%0, %0, %0" : "pxor\t%0, %0";
	case MODE_V8SF:
	  return "vxorps\t%x0, %x0, %x0";
	case MODE_V4DF:
	  return "vxorpd\t%x0, %x0, %x0";
	case MODE_OI:
	  return "vpxor\t%x0, %x0, %x0";
	default:
	  break;
	}
    case 2:
      return TARGET_AVX ? "vpcmpeqd\t%0, %0, %0" : "pcmpeqd\t%0, %0";
    default:
      break;
    }
  gcc_unreachable ();
}

/* Helper for avx_vpermilps256_operand et al.  This is also used by
   the expansion functions to turn the parallel back into a mask.
   The return value is 0 for no match and the imm8+1 for a match.  */

int
avx_vpermilp_parallel (rtx par, enum machine_mode mode)
{
  unsigned i, nelt = GET_MODE_NUNITS (mode);
  unsigned mask = 0;
  unsigned char ipar[8];

  if (XVECLEN (par, 0) != (int) nelt)
    return 0;

  /* Validate that all of the elements are constants, and not totally
     out of range.  Copy the data into an integral array to make the
     subsequent checks easier.  */
  for (i = 0; i < nelt; ++i)
    {
      rtx er = XVECEXP (par, 0, i);
      unsigned HOST_WIDE_INT ei;

      if (!CONST_INT_P (er))
	return 0;
      ei = INTVAL (er);
      if (ei >= nelt)
	return 0;
      ipar[i] = ei;
    }

  switch (mode)
    {
    case V4DFmode:
      /* In the 256-bit DFmode case, we can only move elements within
         a 128-bit lane.  */
      for (i = 0; i < 2; ++i)
	{
	  if (ipar[i] >= 2)
	    return 0;
	  mask |= ipar[i] << i;
	}
      for (i = 2; i < 4; ++i)
	{
	  if (ipar[i] < 2)
	    return 0;
	  mask |= (ipar[i] - 2) << i;
	}
      break;

    case V8SFmode:
      /* In the 256-bit SFmode case, we have full freedom of movement
	 within the low 128-bit lane, but the high 128-bit lane must
	 mirror the exact same pattern.  */
      for (i = 0; i < 4; ++i)
	if (ipar[i] + 4 != ipar[i + 4])
	  return 0;
      nelt = 4;
      /* FALLTHRU */

    case V2DFmode:
    case V4SFmode:
      /* In the 128-bit case, we've full freedom in the placement of
	 the elements from the source operand.  */
      for (i = 0; i < nelt; ++i)
	mask |= ipar[i] << (i * (nelt / 2));
      break;

    default:
      gcc_unreachable ();
    }

  /* Make sure success has a non-zero value by adding one.  */
  return mask + 1;
}

/* Helper for avx_vperm2f128_v4df_operand et al.  This is also used by
   the expansion functions to turn the parallel back into a mask.
   The return value is 0 for no match and the imm8+1 for a match.  */

int
avx_vperm2f128_parallel (rtx par, enum machine_mode mode)
{
  unsigned i, nelt = GET_MODE_NUNITS (mode), nelt2 = nelt / 2;
  unsigned mask = 0;
  unsigned char ipar[8];

  if (XVECLEN (par, 0) != (int) nelt)
    return 0;

  /* Validate that all of the elements are constants, and not totally
     out of range.  Copy the data into an integral array to make the
     subsequent checks easier.  */
  for (i = 0; i < nelt; ++i)
    {
      rtx er = XVECEXP (par, 0, i);
      unsigned HOST_WIDE_INT ei;

      if (!CONST_INT_P (er))
	return 0;
      ei = INTVAL (er);
      if (ei >= 2 * nelt)
	return 0;
      ipar[i] = ei;
    }

  /* Validate that the halves of the permute are halves.  */
  for (i = 0; i < nelt2 - 1; ++i)
    if (ipar[i] + 1 != ipar[i + 1])
      return 0;
  for (i = nelt2; i < nelt - 1; ++i)
    if (ipar[i] + 1 != ipar[i + 1])
      return 0;

  /* Reconstruct the mask.  */
  for (i = 0; i < 2; ++i)
    {
      unsigned e = ipar[i * nelt2];
      if (e % nelt2)
	return 0;
      e /= nelt2;
      mask |= e << (i * 4);
    }

  /* Make sure success has a non-zero value by adding one.  */
  return mask + 1;
}

int
rtx_equal_p (rtx x, rtx y)
{
  return rtx_structurally_equal_p (x, y);

  /* Our definition of rtx_equal_p is same as rtx_structurally_equal_p
   * So we dont need a original definition of rtx_equal_p. */
#if 0
  int i;
  int j;
  enum rtx_code code;
  const char *fmt;

  if (x == y)
    return 1;
  if (x == 0 || y == 0)
    return 0;

  code = GET_CODE (x);
  /* Rtx's of different codes cannot be equal.  */
  if (code != GET_CODE (y))
    return 0;

  /* (MULT:SI x y) and (MULT:HI x y) are NOT equivalent.
     (REG:SI x) and (REG:HI x) are NOT equivalent.  */

  if (GET_MODE (x) != GET_MODE (y))
    return 0;
#endif

  /* MEMs refering to different address space are not equivalent.  */
/* TODO: rm */
#if 0
  if (code == MEM && MEM_ADDR_SPACE (x) != MEM_ADDR_SPACE (y))
    return 0;
#endif

#if 0
  /* Some RTL can be compared nonrecursively.  */
  switch (code)
    {
    case REG:
      return (REGNO (x) == REGNO (y));

    case LABEL_REF:
      return XEXP (x, 0) == XEXP (y, 0);

    case SYMBOL_REF:
      return XSTR (x, 0) == XSTR (y, 0);

    case DEBUG_EXPR:
    case VALUE:
    case SCRATCH:
    case CONST_DOUBLE:
    case CONST_INT:
    case CONST_FIXED:
      return 0;

    default:
      break;
    }

  /* Compare the elements.  If any pair of corresponding elements
     fail to match, return 0 for the whole thing.  */

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    {
      switch (fmt[i])
	{
	case 'w':
	  if (XWINT (x, i) != XWINT (y, i))
	    return 0;
	  break;

	case 'n':
	case 'i':
	  if (XINT (x, i) != XINT (y, i))
	    return 0;
	  break;

	case 'V':
	case 'E':
	  /* Two vectors must have the same length.  */
	  if (XVECLEN (x, i) != XVECLEN (y, i))
	    return 0;

	  /* And the corresponding elements must match.  */
	  for (j = 0; j < XVECLEN (x, i); j++)
	    if (rtx_equal_p (XVECEXP (x, i, j),  XVECEXP (y, i, j)) == 0)
	      return 0;
	  break;

	case 'e':
	  if (rtx_equal_p (XEXP (x, i), XEXP (y, i)) == 0)
	    return 0;
	  break;

	case 'S':
	case 's':
	  if ((XSTR (x, i) || XSTR (y, i))
	      && (! XSTR (x, i) || ! XSTR (y, i)
		  /*TODO: rm || strcmp (XSTR (x, i), XSTR (y, i))*/))
	    return 0;
	  break;

	case 'u':
	  /* These are just backpointers, so they don't matter.  */
	  break;

	case '0':
	case 't':
	  break;

	  /* It is believed that rtx's at this level will never
	     contain anything but integers and other rtx's,
	     except for within LABEL_REFs and SYMBOL_REFs.  */
	default:
	  gcc_unreachable ();
       break;
	}
    }
#endif
  return 1;
}

/***************************************************************
 *          Function to compare 2 rtx structurally
 **************************************************************/
/*
 * It is generated from symbolically-transforming 'rtx_equal_p'.
 * rtx_equal_p checks for physical and structural equlity also.
 * But we need structural equality only as we are dealing with
 * symbolic rtx here. Note that both arguments can be symbolic
 * to our function.
 */
#if 0
int
rtx_structurally_equal_p (rtx x, rtx y)
{
  int i;
  int j;
  enum rtx_code code;
  const char *fmt;

  code = GET_CODE (x);
  /* Rtx's of different codes cannot be equal.  */
  if (code != GET_CODE (y))
    return 0;

  /* (MULT:SI x y) and (MULT:HI x y) are NOT equivalent.
     (REG:SI x) and (REG:HI x) are NOT equivalent.  */

  if (GET_MODE (x) != GET_MODE (y))
    return 0;

  /* MEMs refering to different address space are not equivalent.  */
/* TODO: rm */
#if 0
  if (code == MEM && MEM_ADDR_SPACE (x) != MEM_ADDR_SPACE (y))
    return 0;

  /* Some RTL can be compared nonrecursively.  */
  switch (code)
    {
    case REG:
      return (REGNO (x) == REGNO (y));

    case LABEL_REF:
      return XEXP (x, 0) == XEXP (y, 0);

    case SYMBOL_REF:
      return XSTR (x, 0) == XSTR (y, 0);

    case DEBUG_EXPR:
    case VALUE:
    case SCRATCH:
    case CONST_DOUBLE:
    case CONST_INT:
    case CONST_FIXED:
      return 0;

    default:
      break;
    }

  /* Compare the elements.  If any pair of corresponding elements
     fail to match, return 0 for the whole thing.  */

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    {
      switch (fmt[i])
	{
	case 'w':
	  if (XWINT (x, i) != XWINT (y, i))
	    return 0;
	  break;

	case 'n':
	case 'i':
	  if (XINT (x, i) != XINT (y, i))
	    return 0;
	  break;

	case 'V':
	case 'E':
	  /* Two vectors must have the same length.  */
	  if (XVECLEN (x, i) != XVECLEN (y, i))
	    return 0;

	  /* And the corresponding elements must match.  */
	  for (j = 0; j < XVECLEN (x, i); j++)
	    if (rtx_equal_p (XVECEXP (x, i, j),  XVECEXP (y, i, j)) == 0)
	      return 0;
	  break;

	case 'e':
	  if (rtx_equal_p (XEXP (x, i), XEXP (y, i)) == 0)
	    return 0;
	  break;

	case 'S':
	case 's':
	  if ((XSTR (x, i) || XSTR (y, i))
	      && (! XSTR (x, i) || ! XSTR (y, i)
		  /*TODO: rm || strcmp (XSTR (x, i), XSTR (y, i))*/))
	    return 0;
	  break;

	case 'u':
	  /* These are just backpointers, so they don't matter.  */
	  break;

	case '0':
	case 't':
	  break;

	  /* It is believed that rtx's at this level will never
	     contain anything but integers and other rtx's,
	     except for within LABEL_REFs and SYMBOL_REFs.  */
	default:
	  gcc_unreachable ();
       break;
	}
    }
#endif
  return 1;
}
#endif

#if 0
enum rtx_code
swap_condition (enum rtx_code code)
{
  switch (code)
    {
    case EQ:
    case NE:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case LTGT:
      return code;

    case GT:
      return LT;
    case GE:
      return LE;
    case LT:
      return GT;
    case LE:
      return GE;
    case GTU:
      return LTU;
    case GEU:
      return LEU;
    case LTU:
      return GTU;
    case LEU:
      return GEU;
    case UNLT:
      return UNGT;
    case UNLE:
      return UNGE;
    case UNGT:
      return UNLT;
    case UNGE:
      return UNLE;

    default:
      gcc_unreachable ();
      break;
    }
}
#endif

/*****************************************
 *    insn ID to asm instruction mapping
 ****************************************/

const char *
get_insn_template (int code, rtx insn)
{
  switch (insn_data[code].output_format)
    {
    case INSN_OUTPUT_FORMAT_SINGLE:
      return insn_data[code].output.single;
    /*
    case INSN_OUTPUT_FORMAT_MULTI:
      return insn_data[code].output.multi[which_alternative];
    case INSN_OUTPUT_FORMAT_FUNCTION:
      gcc_assert (insn);
      return (*insn_data[code].output.function) (recog_data.operand, insn);
      */
    default:
      gcc_unreachable ();
    }
}

/* Output text from TEMPLATE to the assembler output file,
   obeying %-directions to substitute operands taken from
   the vector OPERANDS.

   %N (for N a digit) means print operand N in usual manner.
   %lN means require operand N to be a CODE_LABEL or LABEL_REF
      and print the label name with no punctuation.
   %cN means require operand N to be a constant
      and print the constant expression with no punctuation.
   %aN means expect operand N to be a memory address
      (not a memory reference!) and print a reference
      to that address.
   %nN means expect operand N to be a constant
      and print a constant expression for minus the value
      of the operand, with no other punctuation.  */


#undef ASM_OUTPUT_OPCODE
/* gcc uses output_operand_lossage to indicate a user or
compiler error. In case of compiler error, it fails with
gcc_unreachable(), and in case of user error, I guess it
just reports it and does not fail. If we
fail in both cases, then we will lose one maping in case of
user error. So we will not fail in both cases, but instead
continue. But we will need to correct this when we plan to
use our mapping to test gcc correctness. */
#define output_operand_lossage(...)

/* Warning just prints warning to console and continues */
#define warning(...)

extern int logcsfp;

void
output_asm_insn (const char *templ, rtx operands[] ATTRIBUTE_SYMBOLIC)
{
  const char *p;
  int c;
#ifdef ASSEMBLER_DIALECT
  int dialect = 0;
#endif
  int oporder[MAX_RECOG_OPERANDS];
  char opoutput[MAX_RECOG_OPERANDS];
  int ops = 0;

  /* An insn may return a null string template
     in a case where no assembler code is needed.  */
  if (templ==0 || *templ == 0)
    return;
  
  memset (opoutput, 0, sizeof opoutput);
  p = templ;
  putc ('\t', asm_out_file);

#ifdef ASM_OUTPUT_OPCODE
  ASM_OUTPUT_OPCODE (asm_out_file, p);
#endif

  while ((c = *p++))
    switch (c)
      {
      case '\n':
            /* Commented as unneeded for our purpose */
        #if 0
        	if (flag_verbose_asm)
        	  output_asm_operand_names (operands, oporder, ops);
        	if (flag_print_asm_name)
        	  output_asm_name ();
        #endif

        	ops = 0;
        	memset (opoutput, 0, sizeof opoutput);

        	putc (c, asm_out_file);
        #ifdef ASM_OUTPUT_OPCODE
        	while ((c = *p) == '\t')
        	  {
        	    putc (c, asm_out_file);
        	    p++;
        	  }
        	ASM_OUTPUT_OPCODE (asm_out_file, p);
        #endif
        	break;

#ifdef ASSEMBLER_DIALECT
  case '{':
	{
	  int i;

	  if (dialect)
	    output_operand_lossage ("nested assembly dialect alternatives");
	  else
	    dialect = 1;

	  /* If we want the first dialect, do nothing.  Otherwise, skip
	     DIALECT_NUMBER of strings ending with '|'.  */
	  for (i = 0; i < dialect_number; i++)
	    {
	      while (*p && *p != '}' && *p++ != '|')
					;
	      if (*p == '}')
					break;
	      if (*p == '|')
					p++;
	    }

	  if (*p == '\0')
	    output_operand_lossage ("unterminated assembly dialect alternative");
	}
	break;

  case '|':
	if (dialect)
	  {
	    /* Skip to close brace.  */
	    do
	      {
					if (*p == '\0')
		  		{	
		    		output_operand_lossage ("unterminated assembly dialect alternative");
		    		break;
		  		}
	      } while (*p++ != '}');
	    dialect = 0;
	  }
	else
	  putc (c, asm_out_file);
	break;

  case '}':
		if (! dialect)
	  	putc (c, asm_out_file);
		dialect = 0;
	break;
#endif

  case '%':
	/* %% outputs a single %.  */
	if (*p == '%')
	  {
	    p++;
	    putc (c, asm_out_file);
	  }
	/* %= outputs a number which is unique to each insn in the entire
	   compilation.  This is useful for making local labels that are
	   referred to more than once in a given insn.  */
	else if (*p == '=')
	  {
	    p++;
	    fprintf (asm_out_file, "%d", insn_counter);
	  }
	/* % followed by a letter and some digits
	   outputs an operand in a special way depending on the letter.
	   Letters `acln' are implemented directly.
	   Other letters are passed to `output_operand' so that
	   the PRINT_OPERAND macro can define them.  */
	else if (ISALPHA (*p))
	  {
	    int letter = *p++;
	    unsigned long opnum;
	    char *endptr;

	    opnum = strtoul (p, &endptr, 10);

	    if (endptr == p)
	      output_operand_lossage ("operand number missing "
				      "after %%-letter");
	    else if (this_is_asm_operands && opnum >= insn_noperands)
	      output_operand_lossage ("operand number out of range");
	    else if (letter == 'l')
	      output_asm_label (recog_data.operand[opnum]);
	    else if (letter == 'a')
	      output_address (recog_data.operand[opnum]);
	    else if (letter == 'c')
	      {
      		if (CONSTANT_ADDRESS_P (recog_data.operand[opnum]))
      		  output_addr_const (asm_out_file, recog_data.operand[opnum]);
      		else
      		  output_operand (recog_data.operand[opnum], 'c');
	      }
	    else if (letter == 'n')
	      {
            if (CONST_INT_P (recog_data.operand[opnum]))
              fprintf (asm_out_file, HOST_WIDE_INT_PRINT_DEC,
                   - INTVAL (recog_data.operand[opnum]));
            else
              {
                putc ('-', asm_out_file);
                output_addr_const (asm_out_file, recog_data.operand[opnum]);
              }
	      }
	    else
	      output_operand (recog_data.operand[opnum], letter);

	    if (!opoutput[opnum])
	      oporder[ops++] = opnum;
	    opoutput[opnum] = 1;

	    p = endptr;
	    c = *p;
	  }
	/* % followed by a digit outputs an operand the default way.  */
	else if (ISDIGIT (*p))
	  {
	    unsigned long opnum;
	    char *endptr;
      insn_noperands = 3;
      
	    opnum = strtoul (p, &endptr, 10);
      
	    if (this_is_asm_operands && opnum >= insn_noperands)
	      output_operand_lossage ("operand number out of range");
	    else {
        output_operand (recog_data.operand[opnum], 0);
			}

	    if (!opoutput[opnum])
	      oporder[ops++] = opnum;
	    opoutput[opnum] = 1;

	    p = endptr;
	    c = *p;
	  }
	/* % followed by punctuation: output something for that
	   punctuation character alone, with no operand.
	   The PRINT_OPERAND macro decides what is actually done.  */
#ifdef PRINT_OPERAND_PUNCT_VALID_P
	else if (PRINT_OPERAND_PUNCT_VALID_P ((unsigned char) *p))
	  output_operand (NULL_RTX, *p++);
#endif
	else
	  output_operand_lossage ("invalid %%-code");
	break;

      default:
					putc (c, asm_out_file);
  }

#if 0
  /* Write out the variable names for operands, if we know them.  */
  if (flag_verbose_asm)
    output_asm_operand_names (operands, oporder, ops);
  if (flag_print_asm_name)
    output_asm_name ();
#endif

  //putc ('\n', asm_out_file);
}


/*TODO: rm this */
#if 0

/* Output of assembler code from a template, and its subroutines.  */

/* Annotate the assembly with a comment describing the pattern and
   alternative used.  */

void
output_asm_name (void)
{
  /* Niranjan: removed as unnecessary */
  if (debug_insn)
    {
      int num = INSN_CODE (debug_insn);
      fprintf (asm_out_file, "\t%s %d\t%s",
	       ASM_COMMENT_START, INSN_UID (debug_insn),
	       insn_data[num].name);
      if (insn_data[num].n_alternatives > 1)
	fprintf (asm_out_file, "/%d", which_alternative + 1);
#ifdef HAVE_ATTR_length
      fprintf (asm_out_file, "\t[length = %d]",
	       get_attr_length (debug_insn));
#endif
      /* Clear this so only the first assembler insn
	 of any rtl insn will get the special comment for -dp.  */
      debug_insn = 0;
    }
}


/* Output operand names for assembler instructions.  OPERANDS is the
   operand vector, OPORDER is the order to write the operands, and NOPS
   is the number of operands to write.  */

void
output_asm_operand_names (rtx *operands, int *oporder, int nops)
{
  int wrote = 0;
  int i;

  for (i = 0; i < nops; i++)
    {
      int addressp;
      rtx op = operands[oporder[i]];
      tree expr = get_mem_expr_from_op (op, &addressp);

      fprintf (asm_out_file, "%c%s",
	       wrote ? ',' : '\t', wrote ? "" : ASM_COMMENT_START);
      wrote = 1;
      if (expr)
	{
	  fprintf (asm_out_file, "%s",
		   addressp ? "*" : "");
	  print_mem_expr (asm_out_file, expr);  /*TODO: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
	  wrote = 1;
	}
      else if (REG_P (op) && ORIGINAL_REGNO (op)
	       && ORIGINAL_REGNO (op) != REGNO (op))
	fprintf (asm_out_file, " tmp%i", ORIGINAL_REGNO (op));
    }
}
#endif

/* Print operand X using machine-dependent assembler syntax.
   The macro PRINT_OPERAND is defined just to control this function.
   CODE is a non-digit that preceded the operand-number in the % spec,
   such as 'z' if the spec was `%z3'.  CODE is 0 if there was no char
   between the % and the digits.
   When CODE is a non-letter, X is 0.

   The meanings of the letters are machine-dependent and controlled
   by PRINT_OPERAND.  */



void
output_operand (rtx x, int code ATTRIBUTE_UNUSED)
{
  //TODO: rm this if (x && GET_CODE (x) == SUBREG)
  //  x = alter_subreg (&x); /*TODO: <<<<<<<<<<<<<<<<<< */

  /* X must not be a pseudo reg.  */
  //gcc_assert ((x != 0) || !REG_P (x) || REGNO (x) < FIRST_PSEUDO_REGISTER);
  if (!((x == 0) || !REG_P (x) || REGNO (x) < FIRST_PSEUDO_REGISTER))
    return;

  PRINT_OPERAND (asm_out_file, x, code);

  if (x == NULL_RTX)
    return;

  //TODO: commented as unneeded 
  //for_each_rtx (&x, mark_symbol_ref_as_used, NULL);
}

/* Print an integer constant expression in assembler syntax.
   Addition and subtraction are the only arithmetic
   that may appear in these expressions.  */

void
output_addr_const (FILE *file, rtx x)
{
  char buf[256];
  int tmp;

 restart:
  switch (GET_CODE (x))
    {
    case PC:
      putc ('.', file);
      break;

/*TODO: rm later
    case SYMBOL_REF:
      if (SYMBOL_REF_DECL (x))
	{
	  mark_decl_referenced (SYMBOL_REF_DECL (x));
	  assemble_external (SYMBOL_REF_DECL (x));
	}
#ifdef ASM_OUTPUT_SYMBOL_REF
      ASM_OUTPUT_SYMBOL_REF (file, x);
#else
      assemble_name (file, XSTR (x, 0));
#endif
      break;
*/

/* TODO: rm later */
#if 0
    case LABEL_REF:
      x = XEXP (x, 0);
      /* Fall through.  */
    case CODE_LABEL:
      ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (x));
#ifdef ASM_OUTPUT_LABEL_REF
      ASM_OUTPUT_LABEL_REF (file, buf);
#else
      assemble_name (file, buf);
#endif
      break;
#endif

    case CONST_INT:
      /*fprintf (file, HOST_WIDE_INT_PRINT_DEC, XCWINT_S2C (x, 0, CONST_INT));*/
      /*fprintf (file, HOST_WIDE_INT_PRINT_DEC, 10000);*/
      tmp = MARK_CONSTRAINT_VAR(XCWINT(x, 0, CONST_INT));
      //tmp = MARK_CONSTRAINT_VAR(XEXP(x, 0));
    break;

#if 0
    case CONST:
      /* This used to output parentheses around the expression,
	 but that does not work on the 386 (either ATT or BSD assembler).  */
      output_addr_const (file, XEXP (x, 0));
      break;
#endif

/*TODO: rm later */
#if 0
    case CONST_DOUBLE:
      if (GET_MODE (x) == VOIDmode)
	{
	  /* We can use %d if the number is one word and positive.  */
	  if (CONST_DOUBLE_HIGH (x))
	    fprintf (file, HOST_WIDE_INT_PRINT_DOUBLE_HEX,
		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_HIGH (x),
		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_LOW (x));
	  else if (CONST_DOUBLE_LOW (x) < 0)
	    fprintf (file, HOST_WIDE_INT_PRINT_HEX,
		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_LOW (x));
	  else
	    fprintf (file, HOST_WIDE_INT_PRINT_DEC, CONST_DOUBLE_LOW (x));
	}
      else
	/* We can't handle floating point constants;
	   PRINT_OPERAND must handle them.  */
	output_operand_lossage ("floating constant misused");
      break;

    case CONST_FIXED:
      fprintf (file, HOST_WIDE_INT_PRINT_HEX,
	       (unsigned HOST_WIDE_INT) CONST_FIXED_VALUE_LOW (x));
      break;
#endif

#if 0
    case PLUS:
      /* Some assemblers need integer constants to appear last (eg masm).  */
      if (CONST_INT_P (XEXP (x, 0)))
	{
	  output_addr_const (file, XEXP (x, 1));
	  if (INTVAL (XEXP (x, 0)) >= 0)
	    fprintf (file, "+");
	  output_addr_const (file, XEXP (x, 0));
	}
      else
	{
	  output_addr_const (file, XEXP (x, 0));
	  if (!CONST_INT_P (XEXP (x, 1))
	      || INTVAL (XEXP (x, 1)) >= 0)
	    fprintf (file, "+");
	  output_addr_const (file, XEXP (x, 1));
	}
      break;

    case MINUS:
      /* Avoid outputting things like x-x or x+5-x,
	 since some assemblers can't handle that.  */
      //x = simplify_subtraction (x);
      if (GET_CODE (x) != MINUS)
	goto restart;

      output_addr_const (file, XEXP (x, 0));
      fprintf (file, "-");
      if ((CONST_INT_P (XEXP (x, 1)) && INTVAL (XEXP (x, 1)) >= 0)
	  || GET_CODE (XEXP (x, 1)) == PC
	  || GET_CODE (XEXP (x, 1)) == SYMBOL_REF)
	output_addr_const (file, XEXP (x, 1));
      else
	{
	  //fputs (targetm.asm_out.open_paren, file);
	  output_addr_const (file, XEXP (x, 1));
	  //fputs (targetm.asm_out.close_paren, file);
	}
      break;

    case ZERO_EXTEND:
    case SIGN_EXTEND:
    case SUBREG:
    case TRUNCATE:
      output_addr_const (file, XEXP (x, 0));
      break;
#endif

    default:
/*TODO: rm later
#ifdef OUTPUT_ADDR_CONST_EXTRA
      OUTPUT_ADDR_CONST_EXTRA (file, x, fail);
*/
      break;

    fail:
      output_operand_lossage ("invalid expression as operand");
    }
}


bool
output_addr_const_extra (FILE *file, rtx x)
{
  rtx op;

  if (GET_CODE (x) != UNSPEC)
    return false;

  op = XVECEXP (x, 0, 0);
  switch (XINT (x, 1))
    {
    case UNSPEC_GOTTPOFF:
      output_addr_const (file, op);
      /* FIXME: This might be @TPOFF in Sun ld.  */
      fputs ("@gottpoff", file);
      break;

    case UNSPEC_TPOFF:
      output_addr_const (file, op);
      fputs ("@tpoff", file);
      break;

    case UNSPEC_NTPOFF:
      output_addr_const (file, op);
      if (TARGET_64BIT)
				fputs ("@tpoff", file);
      else
				fputs ("@ntpoff", file);
      break;

    case UNSPEC_DTPOFF:
      output_addr_const (file, op);
      fputs ("@dtpoff", file);
      break;

    case UNSPEC_GOTNTPOFF:
      output_addr_const (file, op);
      if (TARGET_64BIT)
				fputs (ASSEMBLER_DIALECT == ASM_ATT ?
	       "@gottpoff(%rip)" : "@gottpoff[rip]", file);
      else
				fputs ("@gotntpoff", file);
      break;

    case UNSPEC_INDNTPOFF:
      output_addr_const (file, op);
      fputs ("@indntpoff", file);
      break;
#if 0
#if TARGET_MACHO
    case UNSPEC_MACHOPIC_OFFSET:
      output_addr_const (file, op);
      putc ('-', file);
      machopic_output_function_base_name (file);
      break;
#endif
#endif
    default:
      return false;
    }

  return true;
}

/* Print a memory reference operand for address X
   using machine-dependent assembler syntax.
   The macro PRINT_OPERAND_ADDRESS exists just to control this function.  */

void
output_address (rtx x)
{
  bool changed = false;
  //walk_alter_subreg (&x, &changed);
  PRINT_OPERAND_ADDRESS (asm_out_file, x);
}

static int override_labelmgmt = 0;

/* Output a LABEL_REF, or a bare CODE_LABEL, as an assembler symbol.  */

void
output_asm_label (rtx x)
{
  char buf[256];

  if (GET_CODE (x) == LABEL_REF)
    x = XEXP (x, 0);
  if (LABEL_P (x)
      || (NOTE_P (x)
	  && NOTE_KIND (x) == NOTE_INSN_DELETED_LABEL)) {
		if (LABEL_P (x)) {
			if (override_labelmgmt) {
				if (LABEL_NAME (x)) {
					strncpy (buf, LABEL_NAME (x), 255);
					buf[256] = 0;
				}
			} else	
				ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (x));
		} else
    	ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (x));
	}
  else
    output_operand_lossage ("'%%l' operand isn't a label");

  //TODO: rm later 
  //assemble_name (asm_out_file, buf);
}

#if 0
/* If OP is a REG or MEM and we can find a MEM_EXPR corresponding to it
   or its address, return that expr .  Set *PADDRESSP to 1 if the expr
   corresponds to the address of the object and 0 if to the object.  */

static tree
get_mem_expr_from_op (rtx op, int *paddressp)
{
  tree expr;
  int inner_addressp;

  *paddressp = 0;

  if (REG_P (op))
    return REG_EXPR (op);
  else if (!MEM_P (op))
    return 0;

  if (MEM_EXPR (op) != 0)
    return MEM_EXPR (op);

  /* Otherwise we have an address, so indicate it and look at the address.  */
  *paddressp = 1;
  op = XEXP (op, 0);

  /* First check if we have a decl for the address, then look at the right side
     if it is a PLUS.  Otherwise, strip off arithmetic and keep looking.
     But don't allow the address to itself be indirect.  */
  if ((expr = get_mem_expr_from_op (op, &inner_addressp)) && ! inner_addressp)
    return expr;
  else if (GET_CODE (op) == PLUS
	   && (expr = get_mem_expr_from_op (XEXP (op, 1), &inner_addressp)))
    return expr;

  while (UNARY_P (op)
	 || GET_RTX_CLASS_EQ_RTX_BIN_ARITH(GET_CODE (op)))
    op = XEXP (op, 0);

  expr = get_mem_expr_from_op (op, &inner_addressp);
  return inner_addressp ? 0 : expr;
}


/* taken from rtlanal.c needed by output_fp_compare. 
 * output_fp_compare is defined in i386.c */
/* Return the reg-note of kind KIND in insn INSN, if there is one.
   If DATUM is nonzero, look for one whose datum is DATUM.  */

rtx
find_reg_note (const_rtx insn, enum reg_note kind, const_rtx datum)
{
  rtx link;

  gcc_assert (insn);

  /* Ignore anything that is not an INSN, JUMP_INSN or CALL_INSN.  */
  if (! INSN_P (insn))
    return 0;
  if (datum == 0)
    {
      for (link = REG_NOTES (insn); link; link = XEXP (link, 1))
	if (REG_NOTE_KIND (link) == kind)
	  return link;
      return 0;
    }

  for (link = REG_NOTES (insn); link; link = XEXP (link, 1))
    if (REG_NOTE_KIND (link) == kind && datum == XEXP (link, 0))
      return link;
  return 0;
}
#endif

/* Meaning of CODE:
   L,W,B,Q,S,T -- print the opcode suffix for specified size of operand.
   C -- print opcode suffix for set/cmov insn.
   c -- like C, but print reversed condition
   F,f -- likewise, but for floating-point.
   O -- if HAVE_AS_IX86_CMOV_SUN_SYNTAX, expand to "w.", "l." or "q.",
        otherwise nothing
   R -- print the prefix for register names.
   z -- print the opcode suffix for the size of the current operand.
   Z -- likewise, with special suffixes for x87 instructions.
   * -- print a star (in certain assembler syntax)
   A -- print an absolute memory reference.
   w -- print the operand as if it's a "word" (HImode) even if it isn't.
   s -- print a shift double count, followed by the assemblers argument
	delimiter.
   b -- print the QImode name of the register for the indicated operand.
	%b0 would print %al if operands[0] is reg 0.
   w --  likewise, print the HImode name of the register.
   k --  likewise, print the SImode name of the register.
   q --  likewise, print the DImode name of the register.
   x --  likewise, print the V4SFmode name of the register.
   t --  likewise, print the V8SFmode name of the register.
   h -- print the QImode name for a "high" register, either ah, bh, ch or dh.
   y -- print "st(0)" instead of "st" as a register.
   d -- print duplicated register operand for AVX instruction.
   D -- print condition for SSE cmp instruction.
   P -- if PIC, print an @PLT suffix.
   X -- don't print any sort of PIC '@' suffix for a symbol.
   & -- print some in-use local-dynamic symbol name.
   H -- print a memory address offset by 8; used for sse high-parts
   Y -- print condition for XOP pcom* instruction.
   + -- print a branch hint as 'cs' or 'ds' prefix
   ; -- print a semicolon (after prefixes due to bug in older gas).
 */

void
print_operand (FILE *file, rtx x, int code)
{
  if (code)
    {
					switch (code)
					{
					case '*':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('*', file);
						return;

					case '&':
						{
      				/*TODO: rm this */
      				#if 0
      							const char *name = get_some_local_dynamic_name ();
      							if (name == NULL)
      								output_operand_lossage ("'%%&' used without any "
      											"local dynamic TLS references");
      							else
      								assemble_name (file, name);
      				#endif
      							return;
						}

					case 'A':
						switch (ASSEMBLER_DIALECT)
							{
							case ASM_ATT:
								putc ('*', file);
								break;

							case ASM_INTEL:
								/* Intel syntax. For absolute addresses, registers should not
						 be surrounded by braces.  */
								if (!REG_P (x))
								{
									putc ('[', file);
									PRINT_OPERAND (file, x, 0);
									putc (']', file);
									return;
								}
								break;

							default:
								gcc_unreachable ();
							}

						PRINT_OPERAND (file, x, 0);
						return;


					case 'L':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('l', file);
						return;

					case 'W':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('w', file);
						return;

					case 'B':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('b', file);
						return;

					case 'Q':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('l', file);
						return;

					case 'S':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('s', file);
						return;

					case 'T':
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('t', file);
						return;

					case 'z':
						if (GET_MODE_CLASS_EQ_MODE_INT(GET_MODE (x)))
							{
									/* Opcodes don't get size suffixes if using Intel opcodes.  */
									if (ASSEMBLER_DIALECT == ASM_INTEL)
										return;

									switch (GET_MODE_SIZE (GET_MODE (x)))
										{
										case 1:
											putc ('b', file);
											return;

										case 2:
											putc ('w', file);
											return;

										case 4:
											putc ('l', file);
											return;

										case 8:
											putc ('q', file);
											return;

										default:
											output_operand_lossage
												("invalid operand size for operand code '%c'", code);
											return;
										}
							}

						if (GET_MODE_CLASS_EQ_MODE_FLOAT(GET_MODE (x)))
							warning
								(0, "non-integer operand used with operand code '%c'", code);
						/* FALLTHRU */

					case 'Z':
						/* 387 opcodes don't get size suffixes if using Intel opcodes.  */
						if (ASSEMBLER_DIALECT == ASM_INTEL)
							return;

						if (GET_MODE_CLASS_EQ_MODE_INT(GET_MODE (x)))
							{
								switch (GET_MODE_SIZE (GET_MODE (x)))
										{
										case 2:
								#ifdef HAVE_AS_IX86_FILDS
											putc ('s', file);
								#endif
											return;

										case 4:
											putc ('l', file);
											return;

										case 8:
								#ifdef HAVE_AS_IX86_FILDQ
											putc ('q', file);
								#else
											fputs ("ll", file);
								#endif
											return;

										default:
											break;
										}
							}
						else if (GET_MODE_CLASS_EQ_MODE_FLOAT(GET_MODE (x)))
							{
												/* 387 opcodes don't get size suffixes
										 if the operands are registers.  */
												if (STACK_REG_P (x))
										return;

												switch (GET_MODE_SIZE (GET_MODE (x)))
										{
										case 4:
											putc ('s', file);
											return;

										case 8:
											putc ('l', file);
											return;

										case 12:
										case 16:
											putc ('t', file);
											return;

										default:
											break;
										}
							}
						else
							{
										output_operand_lossage
									("invalid operand type used with operand code '%c'", code);
										return;
							}

						output_operand_lossage
							("invalid operand size for operand code '%c'", code);
						return;
							
					case 'd':
					case 'b':
					case 'w':
					case 'k':
					case 'q':
					case 'h':
					case 't':
					case 'y':
					case 'x':
					case 'X':
					case 'P':
						break;

					case 's':
						if (CONST_INT_P (x) || ! SHIFT_DOUBLE_OMITS_COUNT)
							{
								PRINT_OPERAND (file, x, 0);
								fputs (", ", file);
							}
						return;

					case 'D':
						/* Little bit of braindamage here.  The SSE compare instructions
							 does use completely different names for the comparisons that the
							 fp conditional moves.  */
						if (TARGET_AVX)
							{
								switch (GET_CODE (x))
										{
										case EQ:
											fputs ("eq", file);
											break;
										case UNEQ:
											fputs ("eq_us", file);
											break;
										case LT:
											fputs ("lt", file);
											break;
										case UNLT:
											fputs ("nge", file);
											break;
										case LE:
											fputs ("le", file);
											break;
										case UNLE:
											fputs ("ngt", file);
											break;
										case UNORDERED:
											fputs ("unord", file);
											break;
										case NE:
											fputs ("neq", file);
											break;
										case LTGT:
											fputs ("neq_oq", file);
											break;
										case GE:
											fputs ("ge", file);
											break;
										case UNGE:
											fputs ("nlt", file);
											break;
										case GT:
											fputs ("gt", file);
											break;
										case UNGT:
											fputs ("nle", file);
											break;
										case ORDERED:
											fputs ("ord", file);
											break;
										default:
											output_operand_lossage ("operand is not a condition code, "
															"invalid operand code 'D'");
											return;
										}
							}
						else
							{
										switch (GET_CODE (x))
										{
										case EQ:
										case UNEQ:
											fputs ("eq", file);
											break;
										case LT:
										case UNLT:
											fputs ("lt", file);
											break;
										case LE:
										case UNLE:
											fputs ("le", file);
											break;
										case UNORDERED:
											fputs ("unord", file);
											break;
										case NE:
										case LTGT:
											fputs ("neq", file);
											break;
										case UNGE:
										case GE:
											fputs ("nlt", file);
											break;
										case UNGT:
										case GT:
											fputs ("nle", file);
											break;
										case ORDERED:
											fputs ("ord", file);
											break;
										default:
											output_operand_lossage ("operand is not a condition code, "
														"invalid operand code 'D'");
											return;
										}
							}
						return;

					case 'O':
				#ifdef HAVE_AS_IX86_CMOV_SUN_SYNTAX
						if (ASSEMBLER_DIALECT == ASM_ATT)
							{
								switch (GET_MODE (x))
						{
						case HImode: putc ('w', file); break;
						case SImode:
						case SFmode: putc ('l', file); break;
						case DImode:
						case DFmode: putc ('q', file); break;
								default: gcc_unreachable ();
						}
								putc ('.', file);
							}
				#endif
						return;

					case 'C':
						if (!COMPARISON_P (x))
							{
								output_operand_lossage ("operand is neither a constant nor a "
											"condition code, invalid operand code "
											"'C'");
								return;
							}
						put_condition_code (GET_CODE (x), GET_MODE (XEXP (x, 0)), 0, 0, file);
						return;

					case 'F':
						if (!COMPARISON_P (x))
							{
								output_operand_lossage ("operand is neither a constant nor a "
											"condition code, invalid operand code "
											"'F'");
								return;
							}
				#ifdef HAVE_AS_IX86_CMOV_SUN_SYNTAX
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('.', file);
				#endif
						put_condition_code (GET_CODE (x), GET_MODE (XEXP (x, 0)), 0, 1, file);
						return;

						/* Like above, but reverse condition */
					case 'c':
						/* Check to see if argument to %c is really a constant
							 and not a condition code which needs to be reversed.  */
						if (!COMPARISON_P (x))
							{
								output_operand_lossage ("operand is neither a constant nor a "
											"condition code, invalid operand "
											"code 'c'");
								return;
							}
						put_condition_code (GET_CODE (x), GET_MODE (XEXP (x, 0)), 1, 0, file);
						return;

					case 'f':
						if (!COMPARISON_P (x))
							{
								output_operand_lossage ("operand is neither a constant nor a "
											"condition code, invalid operand "
											"code 'f'");
								return;
							}
				#ifdef HAVE_AS_IX86_CMOV_SUN_SYNTAX
						if (ASSEMBLER_DIALECT == ASM_ATT)
							putc ('.', file);
				#endif
						put_condition_code (GET_CODE (x), GET_MODE (XEXP (x, 0)), 1, 1, file);
						return;

					case 'H':
						/* It doesn't actually matter what mode we use here, as we're
							 only going to use this for printing.  */
						//TODO: rm this x = adjust_address_nv (x, DImode, 8);
						break;

				/*TODO: rm this later */
				#if 0
					case '+':
						{
							rtx x;

							if (!optimize
									|| optimize_function_for_size_p (cfun) || !TARGET_BRANCH_PREDICTION_HINTS)
								return;

							x = find_reg_note (current_output_insn, REG_BR_PROB, 0);
							if (x)
								{
						int pred_val = INTVAL (XEXP (x, 0));

						if (pred_val < REG_BR_PROB_BASE * 45 / 100
								|| pred_val > REG_BR_PROB_BASE * 55 / 100)
							{
								int taken = pred_val > REG_BR_PROB_BASE / 2;
								int cputaken = final_forward_branch_p (current_output_insn) == 0;

								/* Emit hints only in the case default branch prediction
									 heuristics would fail.  */
								if (taken != cputaken)
									{
							/* We use 3e (DS) prefix for taken branches and
								 2e (CS) prefix for not taken branches.  */
							if (taken)
								fputs ("ds ; ", file);
							else
								fputs ("cs ; ", file);
									}
							}
								}
							return;
						}
				#endif

					case 'Y':
						switch (GET_CODE (x))
							{
							case NE:
								fputs ("neq", file);
								break;
							case EQ:
								fputs ("eq", file);
								break;
							case GE:
							case GEU:
								fputs (INTEGRAL_MODE_P (GET_MODE (x)) ? "ge" : "unlt", file);
								break;
							case GT:
							case GTU:
								fputs (INTEGRAL_MODE_P (GET_MODE (x)) ? "gt" : "unle", file);
								break;
							case LE:
							case LEU:
								fputs ("le", file);
								break;
							case LT:
							case LTU:
								fputs ("lt", file);
								break;
							case UNORDERED:
								fputs ("unord", file);
								break;
							case ORDERED:
								fputs ("ord", file);
								break;
							case UNEQ:
								fputs ("ueq", file);
								break;
							case UNGE:
								fputs ("nlt", file);
								break;
							case UNGT:
								fputs ("nle", file);
								break;
							case UNLE:
								fputs ("ule", file);
								break;
							case UNLT:
								fputs ("ult", file);
								break;
							case LTGT:
								fputs ("une", file);
								break;
							default:
								output_operand_lossage ("operand is not a condition code, "
											"invalid operand code 'Y'");
								return;
							}
						return;

					case ';':
				#if TARGET_MACHO || !HAVE_AS_IX86_REP_LOCK_PREFIX
						fputs (";", file);
				#endif
						return;

					default:
							output_operand_lossage ("invalid operand code '%c'", code);
					}
  }

  if (REG_P (x))
    print_reg (x, code, file);

  else if (MEM_P (x))
  {
			/* No `byte ptr' prefix for call instructions or BLKmode operands.  */
			if (ASSEMBLER_DIALECT == ASM_INTEL && 
					code != 'X' && 
					code != 'P' && 
					GET_MODE (x) != BLKmode)
					{
						const char * size;
						switch (GET_MODE_SIZE (GET_MODE (x)))
							{
							case 1: size = "BYTE"; break;
							case 2: size = "WORD"; break;
							case 4: size = "DWORD"; break;
							case 8: size = "QWORD"; break;
							case 12: size = "TBYTE"; break;
							case 16:
								if (GET_MODE (x) == XFmode)
						      size = "TBYTE";
								else
						      size = "XMMWORD";
								break;
							case 32: size = "YMMWORD"; break;
							default:
								gcc_unreachable ();
							}

						/* Check for explicit size override (codes 'b', 'w' and 'k')  */
						if (code == 'b')
							size = "BYTE";
						else if (code == 'w')
							size = "WORD";
						else if (code == 'k')
							size = "DWORD";

						fputs (size, file);
						fputs (" PTR ", file);
					}

			x = XEXP (x, 0);
			/* Avoid (%rip) for call operands.  */
			if (CONSTANT_ADDRESS_P (x) && 
					code == 'P' && 
					!CONST_INT_P (x))
					output_addr_const (file, x);

			/*
			else if (this_is_asm_operands && ! address_operand (x, VOIDmode))
	       output_operand_lossage ("invalid constraints for operand");*/
			else
	       output_address (x);
		}

/*TODO: rm this later */
#if 0
  else if (GET_CODE (x) == CONST_DOUBLE && GET_MODE (x) == SFmode)
    {
r      REAL_VALUE_TYPE r;
      long l;

      REAL_VALUE_FROM_CONST_DOUBLE (r, x);
      REAL_VALUE_TO_TARGET_SINGLE (r, l);

      if (ASSEMBLER_DIALECT == ASM_ATT)
	putc ('$', file);
      fprintf (file, "0x%08lx", (long unsigned int) l);
    }

  /* These float cases don't actually occur as immediate operands.  */
  else if (GET_CODE (x) == CONST_DOUBLE && GET_MODE (x) == DFmode)
    {
      char dstr[30];

      real_to_decimal (dstr, CONST_DOUBLE_REAL_VALUE (x), sizeof (dstr), 0, 1);
      fputs (dstr, file);
    }

  else if (GET_CODE (x) == CONST_DOUBLE
	   && GET_MODE (x) == XFmode)
    {
      char dstr[30];

      real_to_decimal (dstr, CONST_DOUBLE_REAL_VALUE (x), sizeof (dstr), 0, 1);
      fputs (dstr, file);
    }
#endif

  else
    {
      /* We have patterns that allow zero sets of memory, for instance.
    	 In 64-bit mode, we should probably support all 8-byte vectors,
    	 since we can in fact encode that into an immediate.  */
      /* rm later 
      if (GET_CODE (x) == CONST_VECTOR)
    	{
    	  gcc_assert (x == CONST0_RTX (GET_MODE (x)));
    	  x = const0_rtx;
    	} */
#if 0
      if (code != 'P')
    	{
    	  if (CONST_INT_P (x) || GET_CODE (x) == CONST_DOUBLE)
    	    {
    	      if (ASSEMBLER_DIALECT == ASM_ATT)
    		      putc ('$', file);
    	    }
    	  else if (GET_CODE (x) == CONST || GET_CODE (x) == SYMBOL_REF
    		   || GET_CODE (x) == LABEL_REF)
    	    {
    	      if (ASSEMBLER_DIALECT == ASM_ATT)
    		      putc ('$', file);
    	      else
    		      fputs ("OFFSET FLAT:", file);
    	    }
    	}
#endif

      if (CONST_INT_P (x)) {
        MARK_CONSTRAINT_VAR(INTVAL(x));
      	//unsigned val = INTVAL(x);
      	//fprintf (file, "%s", getGenCount(&val));
      	//fputs(symvar_to_string(&val), file);
      }

      /* TODO: rm later
      else if (flag_pic)
	       output_pic_addr_const (file, x, code);*/
     else 
	       output_addr_const (file, x);
    }

}

/* Names for 8 (low), 8 (high), and 16-bit registers, respectively.  */
static const char *const qi_reg_name[] = QI_REGISTER_NAMES;
static const char *const qi_high_reg_name[] = QI_HIGH_REGISTER_NAMES;
static const char *const hi_reg_name[] = HI_REGISTER_NAMES;


void
print_operand_address (FILE *file, rtx addr)
{
  rtx base = NULL_RTX, index = NULL_RTX, disp = NULL_RTX;
  int scale = 1;
  rtx base_reg, index_reg;
  rtx scale_rtx = NULL_RTX;
  enum ix86_address_seg seg = SEG_DEFAULT;
  int ok = 1;

  // we have inlined ix86_decompose_address below.
  //int ok = ix86_decompose_address (addr, parts);

  if (REG_P (addr) || GET_CODE (addr) == SUBREG)
    base = addr;
#if 0
  else if (GET_CODE (addr) == PLUS)
    {
					rtx addends[4] ATTRIBUTE_SYMBOLIC, op;
          rtx op0, op1, op2, op3;
          rtx op0_, op1_, op2_, op3_;
					int n = 0, i;

					op = addr;

          // Code commented below is written into code marked in
          // /* -- */ block. This is done to avoid looping condition
          // based on symbolic variable.
          //
          // do
          // {
          //  if (n >= 4) {
          //    ok = 0;
          //    goto out;
          //  }
          //  addends[n++] = XEXP (op, 1);
          //  op = XEXP (op, 0);
          // } while (GET_CODE (op) == PLUS);

          /* -- */

          op0 = XEXP(op, 1); n++;
          op0_ = XEXP(op, 0);
          if (GET_CODE(op0_) != PLUS)
            goto next;

          op1 = XEXP(op0, 1); n++;
          op1_ = XEXP(op0, 0);
          if (GET_CODE(op1_) != PLUS)
            goto next;

          op2 = XEXP(op1, 1); n++;
          op2_ = XEXP(op1, 0);
          if (GET_CODE(op2_) != PLUS)
            goto next;

          op3 = XEXP(op2, 1); n++;
          op3_ = XEXP(op2, 0);
          if (GET_CODE(op3_) != PLUS)
            goto next;

          ok = 0;
          goto out;
			
          next:
          switch(n) {
            case 1: addends[0] = op0; op = op0_; break;
            case 2: addends[0] = op0; addends[1] = op1; op = op1_; break;
            case 3: addends[0] = op0; addends[1] = op1;
                    addends[2] = op2; op = op2_; break;
            case 4: addends[0] = op0; addends[1] = op1;
                    addends[2] = op2; addends[3] = op3; op = op3_; break;
            default: gcc_unreachable();
          }

          /* -- */

          if (n >= 4) {
  					ok = 0;
  					goto out;
					}
					addends[n] = op;

					for (i = n; i >= 0; --i)
					{
							op = addends[i];
							switch (GET_CODE (op)) 
              {
  							case MULT:
  								if (index) {
  									ok = 0;
  									goto out;
  								}
  								index = XEXP (op, 0);
  								scale_rtx = XEXP (op, 1);
  								break;

  							case UNSPEC:
  								if (XINT (op, 1) == UNSPEC_TP
  										&& TARGET_TLS_DIRECT_SEG_REFS
  										&& seg == SEG_DEFAULT)
  										seg = TARGET_64BIT ? SEG_FS : SEG_GS;
  								else {
  										ok = 0;
  										goto out;
  								}
  								break;

  							case REG:
  							case SUBREG:
  								if (!base)
  										base = op;
  								else if (!index)
  										index = op;
  								else {
  										ok = 0;
  										goto out;
  								}
  								break;

  							case CONST:
  							case CONST_INT:
  							case SYMBOL_REF:
  							case LABEL_REF:
  								if (disp) {
  									ok = 0;
  									goto out;
  								}
  								disp = op;
  								break;

  							default: 
  								ok = 0;
  								goto out;
							}
					}
		}
  #endif
  else if (GET_CODE (addr) == MULT)
    {
      index = XEXP (addr, 0);		/* index*scale */
      scale_rtx = XEXP (addr, 1);
    }
  else if (GET_CODE (addr) == ASHIFT)
    {
      rtx tmp;

      /* We're called for lea too, which implements ashift on occasion.  */
      index = XEXP (addr, 0);
      tmp = XEXP (addr, 1);
      if (!CONST_INT_P (tmp)) {
				ok = 0; goto out;
      }
      scale = INTVAL (tmp);
      if ((unsigned HOST_WIDE_INT) scale > 3) {
				ok = 0; goto out;
      }
      //scale = 1 << scale;
      // replacing << operator by expanding its semantics.
      switch(scale) {
        case 0: scale = 1; break;
        case 1: scale = 2; break;
        case 2: scale = 4; break;
        case 3: scale = 8; break;
        default: gcc_unreachable();
      }
      ok = -1;
    }
  
  else
    disp = addr;			/* displacement */

  /* Extract the integral value of scale.  */
  if (scale_rtx)
  {
      if (!CONST_INT_P (scale_rtx))
				ok = 0;
      scale = INTVAL (scale_rtx);
  }

  base_reg = base != NULL_RTX && GET_CODE (base) == SUBREG ? SUBREG_REG (base) : base;
  index_reg = index != NULL_RTX && GET_CODE (index) == SUBREG ? SUBREG_REG (index) : index;

  /* Avoid useless 0 displacement.  */
  if (disp == const0_rtx && (base || index))
    disp = NULL_RTX;

  /* Allow arg pointer and stack pointer as index if there is not scaling.  */
  if (base_reg && index_reg && scale == 1 &&
      (index_reg == arg_pointer_rtx ||
	     index_reg == frame_pointer_rtx ||
	     (REG_P (index_reg) && REGNO (index_reg) == STACK_POINTER_REGNUM)))
  {
      rtx tmp;
      tmp = base, base = index, index = tmp;
      tmp = base_reg, base_reg = index_reg, index_reg = tmp;
  }

  /* Special case: %ebp cannot be encoded as a base without a displacement.
     Similarly %r13.  */
  if (!disp
      && base_reg
      && (base_reg == hard_frame_pointer_rtx
	  || base_reg == frame_pointer_rtx
	  || base_reg == arg_pointer_rtx
	  || (REG_P (base_reg)
	      && (REGNO (base_reg) == HARD_FRAME_POINTER_REGNUM
		  || REGNO (base_reg) == R13_REG))))
    disp = const0_rtx;

  /* Special case: scaling cannot be encoded without base or displacement.  */
  if (!base && !disp && index && scale != 1)
    disp = const0_rtx;

  out: gcc_assert (ok);
  //out: 
  
  switch (seg)
    {
				case SEG_DEFAULT:
					break;

				case SEG_FS:
				case SEG_GS:
					if (ASSEMBLER_DIALECT == ASM_ATT)
						putc ('%', file);
					fputs ((seg == SEG_FS ? "fs:" : "gs:"), file);
					break;

				default:
  				gcc_unreachable ();
  }

  if (!base && !index && disp) 
	{
      /* Displacement only requires special attention.  */

      if (CONST_INT_P (disp))
			{
	  		if (ASSEMBLER_DIALECT == ASM_INTEL && seg == SEG_DEFAULT)
	    		fputs ("ds:", file);
	  		//fprintf (file, HOST_WIDE_INT_PRINT_DEC, INTVAL (disp));
        MARK_CONSTRAINT_VAR(INTVAL(disp));
			}
      /*else if (flag_pic)
				output_pic_addr_const (file, disp, 0);*/
      else
				output_addr_const (file, disp);
  }
  else
  {
      if (ASSEMBLER_DIALECT == ASM_ATT)
			{
	  		if (disp)
	    	{
	      	/*if (flag_pic)
							output_pic_addr_const (file, disp, 0);
	      		else*/ if (GET_CODE (disp) == LABEL_REF)
							output_asm_label (disp);
	      		else
							output_addr_const (file, disp);
	    	}

	  		putc ('(', file);
	  		if (base)
	    		print_reg (base, 0, file);
	  		if (index)
	    	{
	      	putc (',', file);
	      	print_reg (index, 0, file);
	      	if (scale != 1) {
						fprintf (file, ",%d", scale);
            //fputs(",", file);
            //MARK_CONSTRAINT_VAR(scale);
          }
	    	}
	  		putc (')', file);
		  }
      else
			{
	  		rtx offset = NULL_RTX;

    	  if (disp)
    	    {
              /* Pull out the offset of a symbol; print any symbol itself.  */
              if (GET_CODE (disp) == CONST
        		  && GET_CODE (XEXP (disp, 0)) == PLUS
        		  && CONST_INT_P (XEXP (XEXP (disp, 0), 1)))
        		{
        		  offset = XEXP (XEXP (disp, 0), 1);
        		  //disp = gen_rtx_CONST (VOIDmode,
        			//		XEXP (XEXP (disp, 0), 0));
              disp = XEXP(XEXP(disp, 0), 0);
        		}

        	      /*if (flag_pic)
        		output_pic_addr_const (file, disp, 0);
        	      else*/ if (GET_CODE (disp) == LABEL_REF)
        		output_asm_label (disp);
        	      else if (CONST_INT_P (disp))
        		offset = disp;
        	      else
        		output_addr_const (file, disp);
    	    }

    	  putc ('[', file);
    	  if (base)
    	    {
    	      print_reg (base, 0, file);
    	      if (offset)
    						{
    							if (INTVAL (offset) >= 0)
    								putc ('+', file);
    							//fprintf (file, HOST_WIDE_INT_PRINT_DEC, INTVAL (offset));
                  MARK_CONSTRAINT_VAR(INTVAL(offset));
    						}
    	    }
    	  else if (offset)
    	    //fprintf (file, HOST_WIDE_INT_PRINT_DEC, INTVAL (offset));
          MARK_CONSTRAINT_VAR(INTVAL(offset));
    	  else
    	    putc ('0', file);

    	  if (index)
    	    {
    	      putc ('+', file);
    	      print_reg (index, 0, file);
    	      if (scale != 1) {
    					//fprintf (file, "*%d", scale);
              putc('*', file);
              MARK_CONSTRAINT_VAR(scale);
            }
    	    }
    	  	putc (']', file);
			}
   }
}


/* Print the name of register X to FILE based on its machine mode and number.
   If CODE is 'w', pretend the mode is HImode.
   If CODE is 'b', pretend the mode is QImode.
   If CODE is 'k', pretend the mode is SImode.
   If CODE is 'q', pretend the mode is DImode.
   If CODE is 'x', pretend the mode is V4SFmode.
   If CODE is 't', pretend the mode is V8SFmode.
   If CODE is 'h', pretend the reg is the 'high' byte register.
   If CODE is 'y', print "st(0)" instead of "st", if the reg is stack op.
   If CODE is 'd', duplicate the operand for AVX instruction.
 */

void
print_reg (rtx x, int code, FILE *file)
{
  const char *reg;
  int tmp;
  bool duplicated = code == 'd' && TARGET_AVX;

  gcc_assert (x == pc_rtx
	      || (REGNO (x) != ARG_POINTER_REGNUM
		  && REGNO (x) != FRAME_POINTER_REGNUM
		  && REGNO (x) != FLAGS_REG
		  && REGNO (x) != FPSR_REG
		  && REGNO (x) != FPCR_REG));

  if (ASSEMBLER_DIALECT == ASM_ATT)
    putc ('%', file);
 
  if (x == pc_rtx)
    {
      gcc_assert (TARGET_64BIT);
      fputs ("rip", file);
      return;
    }

  if (code == 'w' || MMX_REG_P (x))
    code = 2;
  else if (code == 'b')
    code = 1;
  else if (code == 'k')
    code = 4;
  else if (code == 'q')
    code = 8;
  else if (code == 'y')
    code = 3;
  else if (code == 'h')
    code = 0;
  else if (code == 'x')
    code = 16;
  else if (code == 't')
    code = 32;
  else
    code = GET_MODE_SIZE (GET_MODE (x));

  /* Irritatingly, AMD extended registers use different naming convention
     from the normal registers.  */
  if (REX_INT_REG_P (x))
    {
      gcc_assert (TARGET_64BIT);
      switch (code)
      	{
      	  case 0:
      	    error ("extended registers have no high halves");
      	    break;
      	  case 1:
      	    fprintf (file, "r%ib", REGNO_S2C (x) - FIRST_REX_INT_REG + 8);
      	    break;
      	  case 2:
      	    fprintf (file, "r%iw", REGNO_S2C (x) - FIRST_REX_INT_REG + 8);
      	    break;
      	  case 4:
      	    fprintf (file, "r%id", REGNO_S2C (x) - FIRST_REX_INT_REG + 8);
      	    break;
      	  case 8:
      	    fprintf (file, "r%i", REGNO_S2C (x) - FIRST_REX_INT_REG + 8);
      	    break;
      	  default:
      	    error ("unsupported operand size for extended register");
      	    break;
      	}
      return;
    }

  reg = NULL;
  switch (code)
    {
    case 3:
      if (STACK_TOP_P (x))
			{
	  		reg = "st(0)";
	  		break;
			}
      /* FALLTHRU */

    case 8:
    case 4:
    case 12:
      if (! ANY_FP_REG_P (x)) ;
        // we disabled printing 'e' as it is causing issues with 
        // generating imap file
				//putc (code == 8 && TARGET_64BIT ? 'r' : 'e', file);
      		/* FALLTHRU */

    case 16:
    case 2:
    normal:
      //reg = hi_reg_name[REGNO_S2C (x)];
			reg = "hi_reg";
      //fputs("%%", file); fputs(reg, file);
      tmp = MARK_CONSTRAINT_VAR(REGNO(x));
      //fputs(symvar_to_string(&x), file);
      break;

    case 1:
      if (REGNO (x) >= ARRAY_SIZE (qi_reg_name))
				goto normal;        
      //reg = qi_reg_name[REGNO_S2C (x)];
			reg = "qi_reg";
      //fputs("%%", file); fputs(reg, file);
      tmp = MARK_CONSTRAINT_VAR(REGNO(x));
      //fputs(symvar_to_string(&x), file);
      break;

    case 0:
      if (REGNO (x) >= ARRAY_SIZE (qi_high_reg_name))
				goto normal;
      //reg = qi_high_reg_name[REGNO_S2C (x)];
			reg = "qi_high_reg";
      //fputs("%%", file); fputs(reg, file);
      tmp = MARK_CONSTRAINT_VAR(REGNO(x));
      //fputs(symvar_to_string(&x), file);
      break;

    case 32:
      if (SSE_REG_P (x))
			{
	  		gcc_assert (!duplicated);
	  		putc ('y', file);
	  		//fputs (hi_reg_name[REGNO_S2C (x)] + 1, file);
        reg = "hi_reg" + 1;
	  		fputs ("hi_reg" + 1, file);
	  		return;
			}

      break;
    default:
      gcc_unreachable ();
    }

/* We dont need to print reg name as we print the Q_ varname
  fputs (reg, file);

  if (duplicated)
    {
      if (ASSEMBLER_DIALECT == ASM_ATT)
					fprintf (file, ", %%%s", reg);
      else
					fprintf (file, ", %s", reg);
    }
*/
}


/* Return nonzero if there is a register that is in both C1 and C2.  */
int
reg_classes_intersect_p (enum reg_class c1, enum reg_class c2)
{
  return (c1 == c2
	  || c1 == ALL_REGS
	  || c2 == ALL_REGS
	  /*TODO: rm this || hard_reg_set_intersect_p (reg_class_contents[(int) c1],
				      reg_class_contents[(int) c2])*/);
}

bool
ix86_cannot_change_mode_class (enum machine_mode from, enum machine_mode to,
			       enum reg_class regclass)
{
  if (from == to)
    return false;

  /* x87 registers can't do subreg at all, as all values are reformatted
     to extended precision.  */
  if (MAYBE_FLOAT_CLASS_P (regclass))
    return true;

  if (MAYBE_SSE_CLASS_P (regclass) || MAYBE_MMX_CLASS_P (regclass))
    {
      /* Vector registers do not support QI or HImode loads.  If we don't
	 disallow a change to these modes, reload will assume it's ok to
	 drop the subreg from (subreg:SI (reg:HI 100) 0).  This affects
	 the vec_dupv4hi pattern.  */
      if (GET_MODE_SIZE (from) < 4)
	return true;

      /* Vector registers do not support subreg with nonzero offsets, which
	 are otherwise valid for integer registers.  Since we can't see
	 whether we have a nonzero offset from here, prohibit all
         nonparadoxical subregs changing size.  */
      if (GET_MODE_SIZE (to) < GET_MODE_SIZE (from))
	return true;
    }

  return false;
}


HOST_WIDE_INT
trunc_int_for_mode (HOST_WIDE_INT c, enum machine_mode mode)
{
  int width = GET_MODE_BITSIZE (mode);

  /* You want to truncate to a _what_?  */
  gcc_assert (SCALAR_INT_MODE_P (mode));

  /* Canonicalize BImode to 0 and STORE_FLAG_VALUE.  */
  if (mode == BImode)
    return c & 1 ? STORE_FLAG_VALUE : 0;

  /* Sign-extend for the requested mode.  */

  if (width < HOST_BITS_PER_WIDE_INT)
    {
      HOST_WIDE_INT sign = 1;
      sign <<= width - 1;
      c &= (sign << 1) - 1;
      c ^= sign;
      c -= sign;
    }

  return c;
}

#if 0
inline int
emms_operation_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
//#line 1151 "../../gcc/config/i386/predicates.md"
{
  unsigned i;

  if (XVECLEN (op, 0) != 17)
    return 0;

  for (i = 0; i < 8; i++)
    {
      rtx elt = XVECEXP (op, 0, i+1);

      if (GET_CODE (elt) != CLOBBER
	  || GET_CODE (SET_DEST (elt)) != REG
	  || GET_MODE (SET_DEST (elt)) != XFmode
	  || REGNO (SET_DEST (elt)) != FIRST_STACK_REG + i)
        return 0;

      elt = XVECEXP (op, 0, i+9);

      if (GET_CODE (elt) != CLOBBER
	  || GET_CODE (SET_DEST (elt)) != REG
	  || GET_MODE (SET_DEST (elt)) != DImode
	  || REGNO (SET_DEST (elt)) != FIRST_MMX_REG + i)
	return 0;
    }
  return 1;
}

int
emms_operation (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == PARALLEL) && (
(emms_operation_1 (op, mode)))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
vzeroall_operation_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
//#line 1181 "../../gcc/config/i386/predicates.md"
{
  unsigned i, nregs = TARGET_64BIT ? 16 : 8;

  if ((unsigned) XVECLEN (op, 0) != 1 + nregs)
    return 0;

  for (i = 0; i < nregs; i++)
    {
      rtx elt = XVECEXP (op, 0, i+1);

      if (GET_CODE (elt) != SET
	  || GET_CODE (SET_DEST (elt)) != REG
	  || GET_MODE (SET_DEST (elt)) != V8SImode
	  || REGNO (SET_DEST (elt)) != SSE_REGNO (i)
	  || SET_SRC (elt) != CONST0_RTX (V8SImode))
	return 0;
    }
  return 1;
}

int
vzeroall_operation (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == PARALLEL) && (
(vzeroall_operation_1 (op, mode)))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
vzeroupper_operation_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
//#line 1204 "../../gcc/config/i386/predicates.md"
{
  unsigned i, nregs = TARGET_64BIT ? 16 : 8;
 
  if ((unsigned) XVECLEN (op, 0) != 1 + nregs)
    return 0;

  for (i = 0; i < nregs; i++)
    {
      rtx elt = XVECEXP (op, 0, i+1);

      if (GET_CODE (elt) != CLOBBER
	  || GET_CODE (SET_DEST (elt)) != REG
	  || GET_MODE (SET_DEST (elt)) != V8SImode
	  || REGNO (SET_DEST (elt)) != SSE_REGNO (i))
	return 0;
    }
  return 1;
}

int
vzeroupper_operation (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == PARALLEL) && (
(vzeroupper_operation_1 (op, mode)))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}
#endif

int
const_int_operand (rtx op, enum machine_mode mode)
{
  if (!CONST_INT_P (op))
    return 0;

  if (mode != VOIDmode
      && trunc_int_for_mode (INTVAL (op), mode) != INTVAL (op))
    return 0;

  return 1;
}

/* Given an rtx-code for a comparison, return the code for the negated
   comparison.  If no such code exists, return UNKNOWN.

   WATCH OUT!  reverse_condition is not safe to use on a jump that might
   be acting on the results of an IEEE floating point comparison, because
   of the special treatment of non-signaling nans in comparisons.
   Use reversed_comparison_code instead.  */

enum rtx_code
reverse_condition (enum rtx_code code)
{
  switch (code)
    {
    case EQ:
      return NE;
    case NE:
      return EQ;
    case GT:
      return LE;
    case GE:
      return LT;
    case LT:
      return GE;
    case LE:
      return GT;
    case GTU:
      return LEU;
    case GEU:
      return LTU;
    case LTU:
      return GEU;
    case LEU:
      return GTU;
    case UNORDERED:
      return ORDERED;
    case ORDERED:
      return UNORDERED;

    case UNLT:
    case UNLE:
    case UNGT:
    case UNGE:
    case UNEQ:
    case LTGT:
      return UNKNOWN;

    default:
      gcc_unreachable ();
    }
}

void
put_condition_code (enum rtx_code code, enum machine_mode mode, int reverse,
		    int fp, FILE *file)
{
  const char *suffix;

  if (mode == CCFPmode || mode == CCFPUmode)
    {
      code = ix86_fp_compare_code_to_integer (code);
      mode = CCmode;
    }
  if (reverse)
    code = reverse_condition (code);

  switch (code)
    {
    case EQ:
      switch (mode)
	{
	case CCAmode:
	  suffix = "a";
	  break;

	case CCCmode:
	  suffix = "c";
	  break;

	case CCOmode:
	  suffix = "o";
	  break;

	case CCSmode:
	  suffix = "s";
	  break;

	default:
	  suffix = "e";
	}
      break;
    case NE:
      switch (mode)
	{
	case CCAmode:
	  suffix = "na";
	  break;

	case CCCmode:
	  suffix = "nc";
	  break;

	case CCOmode:
	  suffix = "no";
	  break;

	case CCSmode:
	  suffix = "ns";
	  break;

	default:
	  suffix = "ne";
	}
      break;
    case GT:
      gcc_assert (mode == CCmode || mode == CCNOmode || mode == CCGCmode);
      suffix = "g";
      break;
    case GTU:
      /* ??? Use "nbe" instead of "a" for fcmov lossage on some assemblers.
	 Those same assemblers have the same but opposite lossage on cmov.  */
      if (mode == CCmode)
	suffix = fp ? "nbe" : "a";
      else if (mode == CCCmode)
	suffix = "b";
      else
	gcc_unreachable ();
      break;
    case LT:
      switch (mode)
	{
	case CCNOmode:
	case CCGOCmode:
	  suffix = "s";
	  break;

	case CCmode:
	case CCGCmode:
	  suffix = "l";
	  break;

	default:
	  gcc_unreachable ();
	}
      break;
    case LTU:
      gcc_assert (mode == CCmode || mode == CCCmode);
      suffix = "b";
      break;
    case GE:
      switch (mode)
	{
	case CCNOmode:
	case CCGOCmode:
	  suffix = "ns";
	  break;

	case CCmode:
	case CCGCmode:
	  suffix = "ge";
	  break;

	default:
	  gcc_unreachable ();
	}
      break;
    case GEU:
      /* ??? As above.  */
      gcc_assert (mode == CCmode || mode == CCCmode);
      suffix = fp ? "nb" : "ae";
      break;
    case LE:
      gcc_assert (mode == CCmode || mode == CCGCmode || mode == CCNOmode);
      suffix = "le";
      break;
    case LEU:
      /* ??? As above.  */
      if (mode == CCmode)
	suffix = "be";
      else if (mode == CCCmode)
	suffix = fp ? "nb" : "ae";
      else
	gcc_unreachable ();
      break;
    case UNORDERED:
      suffix = fp ? "u" : "p";
      break;
    case ORDERED:
      suffix = fp ? "nu" : "np";
      break;
    default:
      gcc_unreachable ();
    }
  fputs (suffix, file);
}

#undef fputs
#undef fprintf
#undef putc
