/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#define IN_GCC
#define IN_TRANSFORMED_CODE
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "flags.h"
//#include "ggc.h"
#include "rtl-trans.h"
#if 0
#include "expr.h"
#include "insn-codes.h"
#endif
#include "tm_p.h"
//#include "function.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"

//#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "toplev.h"
//#include "output.h"
//#include "target.h"
//#include "tm-constrs.h"
//

#define GEN_INT(x) NULL_RTX

//TODO: rm this later
extern FILE* asm_out_file;
#define optimize_function_for_size_p(x) 0

static const char * const output_0[] = {
  "test{b}\t%0, %0",
  "cmp{b}\t{%1, %0|%0, %1}",
};

static const char * const output_1[] = {
  "test{w}\t%0, %0",
  "cmp{w}\t{%1, %0|%0, %1}",
};

static const char * const output_2[] = {
  "test{l}\t%0, %0",
  "cmp{l}\t{%1, %0|%0, %1}",
};

static const char *
output_18 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1095 "../../gcc/config/i386/i386.md"
{
  operands[1] = constm1_rtx;
  return "or{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_20 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1161 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      /* movzwl is faster than movw on p2 due to partial word stalls,
	 though not as fast as an aligned movl.  */
      return "movz{wl|x}\t{%1, %k0|%k0, %1}";
    default:
      if (get_attr_mode (insn) == MODE_SI)
        return "mov{l}\t{%k1, %k0|%k0, %k1}";
      else
        return "mov{w}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_22 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1237 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      gcc_assert (ANY_QI_REG_P (operands[1]) || MEM_P (operands[1]));
      return "movz{bl|x}\t{%1, %k0|%k0, %1}";
    default:
      if (get_attr_mode (insn) == MODE_SI)
        return "mov{l}\t{%k1, %k0|%k0, %k1}";
      else
        return "mov{b}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_25 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1334 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movs{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_27 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1439 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      return "movz{bl|x}\t{%h1, %k0|%k0, %h1}";
    default:
      return "mov{b}\t{%h1, %0|%0, %h1}";
    }
}
}

static const char *
output_31 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1872 "../../gcc/config/i386/i386.md"
{
  /* Anything else should be already split before reg-stack.  */
  gcc_assert (which_alternative == 1);
  return "push{l}\t%1";
}
}

static const char *
output_32 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 1930 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3:
    case 4:
      return "mov{l}\t{%1, %0|%0, %1}";
    case 5:
      if (get_attr_mode (insn) == MODE_TI)
	return "%vpxor\t%0, %d0";
      else
	return "%vxorps\t%0, %d0";
    case 6:
      if (get_attr_mode (insn) == MODE_V4SF)
	return "%vmovaps\t{%1, %0|%0, %1}";
      else
	return "%vmovss\t{%1, %d0|%d0, %1}";
    case 7:
      if (TARGET_AVX)
	return REG_P (operands[1]) ? "vmovss\t{%1, %0, %0|%0, %0, %1}"
				   : "vmovss\t{%1, %0|%0, %1}";
      else
	return "movss\t{%1, %0|%0, %1}";
    case 8:
      return "%vmovss\t{%1, %0|%0, %1}";

    case 9: case 10: case 14: case 15:
      return "movd\t{%1, %0|%0, %1}";
    case 12: case 13:
      return "%vmovd\t{%1, %0|%0, %1}";

    case 11:
      return "movq\t{%1, %0|%0, %1}";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_33 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2020 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char *
output_34 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2044 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char * const output_43[] = {
  "#",
  "#",
  "#",
  "movd\t{%1, %0|%0, %1}",
  "movd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char *
output_45 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2465 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_prefix_0f (insn))
    {
    case 0:
      return "{cwtl|cwde}";
    default:
      return "movs{wl|x}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_46 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2518 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_prefix_0f (insn))
    {
    case 0:
      return "{cbtw|cbw}";
    default:
      return "movs{bw|x}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_52 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2647 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      operands[2] = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
      return "lea{l}\t{%a2, %0|%0, %a2}";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      /* Use add as much as possible to replace lea for AGU optimization. */
      if (which_alternative == 2 && TARGET_OPT_AGU)
        return "add{l}\t{%1, %0|%0, %1}";
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));

      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (SImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{l}\t{%2, %0|%0, %2}";
        }
      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_53 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2776 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{w}\t{%2, %0|%0, %2}";
	}
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_54 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2824 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{w}\t{%2, %0|%0, %2}";
	}
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_55 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2872 "../../gcc/config/i386/i386.md"
{
  int widen = (which_alternative == 2);
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return widen ? "inc{l}\t%k0" : "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return widen ? "dec{l}\t%k0" : "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  if (widen)
	    return "sub{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sub{b}\t{%2, %0|%0, %2}";
	}
      if (widen)
        return "add{l}\t{%k2, %k0|%k0, %k2}";
      else
        return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_56 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2924 "../../gcc/config/i386/i386.md"
{
  int widen = (which_alternative == 2);
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return widen ? "inc{l}\t%k0" : "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return widen ? "dec{l}\t%k0" : "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  if (widen)
	    return "sub{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sub{b}\t{%2, %0|%0, %2}";
	}
      if (widen)
        return "add{l}\t{%k2, %k0|%k0, %k2}";
      else
        return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_57 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 2979 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[1] == const1_rtx)
	return "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[1] == constm1_rtx);
	  return "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.  */
      if (CONST_INT_P (operands[1])
	  && INTVAL (operands[1]) < 0)
	{
	  operands[1] = GEN_INT (-INTVAL (operands[1]));
	  return "sub{b}\t{%1, %0|%0, %1}";
	}
      return "add{b}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_58 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3026 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* ???? In DImode, we ought to handle there the 32bit case too
	 - do we need new constraint?  */
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (SImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{l}\t{%2, %0|%0, %2}";
        }
      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_59 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3131 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{w}\t{%2, %0|%0, %2}";
	}
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_60 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3178 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx
		      || (CONST_INT_P (operands[2])
		          && INTVAL (operands[2]) == 255));
	  return "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.  */
      if (CONST_INT_P (operands[2])
          && INTVAL (operands[2]) < 0)
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{b}\t{%2, %0|%0, %2}";
	}
      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_61 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3220 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* ???? In DImode, we ought to handle there the 32bit case too
	 - do we need new constraint?  */
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4, %eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (SImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{l}\t{%2, %0|%0, %2}";
        }
      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_62 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3322 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{w}\t{%2, %0|%0, %2}";
	}
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_63 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3367 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx
		      || (CONST_INT_P (operands[2])
			  && INTVAL (operands[2]) == 255));
	  return "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.  */
      if (CONST_INT_P (operands[2])
          && INTVAL (operands[2]) < 0)
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{b}\t{%2, %0|%0, %2}";
	}
      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_64 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3469 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{l}\t%0";
      else
        {
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{l}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if ((INTVAL (operands[2]) == -128
	   || (INTVAL (operands[2]) > 0
	       && INTVAL (operands[2]) != 128)))
	return "sub{l}\t{%2, %0|%0, %2}";
      operands[2] = GEN_INT (-INTVAL (operands[2]));
      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_65 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3514 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx)
        return "inc{w}\t%0";
      else
	{
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{w}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if ((INTVAL (operands[2]) == -128
	   || (INTVAL (operands[2]) > 0
	       && INTVAL (operands[2]) != 128)))
	return "sub{w}\t{%2, %0|%0, %2}";
      operands[2] = GEN_INT (-INTVAL (operands[2]));
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_66 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3559 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == constm1_rtx
	  || (CONST_INT_P (operands[2])
	      && INTVAL (operands[2]) == 255))
        return "inc{b}\t%0";
      else
	{
	  gcc_assert (operands[2] == const1_rtx);
          return "dec{b}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (INTVAL (operands[2]) < 0)
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "add{b}\t{%2, %0|%0, %2}";
        }
      return "sub{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_67 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3602 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{l}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{l}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (SImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{l}\t{%2, %0|%0, %2}";
        }
      return "add{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_68 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3653 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{w}\t%0";
      else
	{
	  gcc_assert (operands[2] == constm1_rtx);
	  return "dec{w}\t%0";
	}

    default:
      /* Make things pretty and `subw $4,%ax' rather than `addw $-4,%ax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{w}\t{%2, %0|%0, %2}";
	}
      return "add{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_69 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3699 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx
		      || (CONST_INT_P (operands[2])
			  && INTVAL (operands[2]) == 255));
	  return "dec{b}\t%0";
	}

    default:
      /* Make things pretty and `subb $4,%al' rather than `addb $-4,%al'.  */
      if (CONST_INT_P (operands[2])
          && INTVAL (operands[2]) < 0)
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{b}\t{%2, %0|%0, %2}";
	}
      return "add{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_70 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 3779 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      if (operands[2] == const1_rtx)
	return "inc{b}\t%h0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx
		      || (CONST_INT_P (operands[2])
			  && INTVAL (operands[2]) == 255));
          return "dec{b}\t%h0";
	}

    default:
      return "add{b}\t{%2, %h0|%h0, %2}";
    }
}
}

static const char * const output_104[] = {
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %0|%0, %2}",
};

static const char * const output_105[] = {
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %0|%0, %2}",
};

static const char *
output_123 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 4697 "../../gcc/config/i386/i386.md"
{
  if (which_alternative == 3)
    {
      if (CONST_INT_P (operands[1]) && INTVAL (operands[1]) < 0)
	operands[1] = GEN_INT (INTVAL (operands[1]) & 0xff);
      return "test{l}\t{%1, %k0|%k0, %1}";
    }
  return "test{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_131 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 5011 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      {
	enum machine_mode mode;

	gcc_assert (CONST_INT_P (operands[2]));
        if (INTVAL (operands[2]) == 0xff)
	  mode = QImode;
	else
	  {
	    gcc_assert (INTVAL (operands[2]) == 0xffff);
	    mode = HImode;
	  }

	operands[1] = gen_lowpart (mode, operands[1]);
	if (mode == QImode)
	  return "movz{bl|x}\t{%1, %0|%0, %1}";
	else
	  return "movz{wl|x}\t{%1, %0|%0, %1}";
      }

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      return "and{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_132 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 5068 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOVX:
      gcc_assert (CONST_INT_P (operands[2]));
      gcc_assert (INTVAL (operands[2]) == 0xff);
      return "movz{bl|x}\t{%b1, %k0|%k0, %b1}";

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));

      return "and{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char * const output_133[] = {
  "and{b}\t{%2, %0|%0, %2}",
  "and{b}\t{%2, %0|%0, %2}",
  "and{l}\t{%k2, %k0|%k0, %k2}",
};

static const char *
output_135 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 5187 "../../gcc/config/i386/i386.md"
{
  if (which_alternative == 2)
    {
      if (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 0)
        operands[2] = GEN_INT (INTVAL (operands[2]) & 0xff);
      return "and{l}\t{%2, %k0|%k0, %2}";
    }
  return "and{b}\t{%2, %0|%0, %2}";
}
}

static const char * const output_148[] = {
  "or{b}\t{%2, %0|%0, %2}",
  "or{b}\t{%2, %0|%0, %2}",
  "or{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_149[] = {
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_182[] = {
  "not{b}\t%0",
  "not{l}\t%k0",
};

static const char *
output_187 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6276 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      return "add{l}\t%0, %0";

    case TYPE_LEA:
      return "#";

    default:
      if (REG_P (operands[2]))
	return "sal{l}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_188 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6445 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{l}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_189 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6495 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{l}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{l}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{l}\t%0";
      else
	return "sal{l}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_190 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6596 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{w}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_191 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6643 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{w}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_192 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6697 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{w}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_193 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6747 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{w}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{w}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{w}\t%0";
      else
	return "sal{w}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_194 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6799 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      return "#";
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      if (REG_P (operands[1]) && !ANY_QI_REG_P (operands[1]))
        return "add{l}\t%k0, %k0";
      else
        return "add{b}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t{%b2, %k0|%k0, %b2}";
	  else
	    return "sal{b}\t{%b2, %0|%0, %b2}";
	}
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t%0";
	  else
	    return "sal{b}\t%0";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sal{b}\t{%2, %0|%0, %2}";
	}
    }
}
}

static const char *
output_195 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6864 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      if (REG_P (operands[1]) && !ANY_QI_REG_P (operands[1]))
        return "add{l}\t%k0, %k0";
      else
        return "add{b}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t{%b2, %k0|%k0, %b2}";
	  else
	    return "sal{b}\t{%b2, %0|%0, %b2}";
	}
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t%0";
	  else
	    return "sal{b}\t%0";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_SI)
	    return "sal{l}\t{%2, %k0|%k0, %2}";
	  else
	    return "sal{b}\t{%2, %0|%0, %2}";
	}
    }
}
}

static const char *
output_196 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6936 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{b}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{b}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{b}\t%0";
      else
	return "sal{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_197 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 6986 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_ALU:
      gcc_assert (operands[2] == const1_rtx);
      return "add{b}\t%0, %0";

    default:
      if (REG_P (operands[2]))
	return "sal{b}\t{%b2, %0|%0, %b2}";
      else if (operands[2] == const1_rtx
	       && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
	return "sal{b}\t%0";
      else
	return "sal{b}\t{%2, %0|%0, %2}";
    }
}
}

static const char * const output_200[] = {
  "{cltd|cdq}",
  "sar{l}\t{%2, %0|%0, %2}",
};

static const char * const output_202[] = {
  "sar{l}\t{%2, %0|%0, %2}",
  "sar{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_208[] = {
  "sar{w}\t{%2, %0|%0, %2}",
  "sar{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_215[] = {
  "sar{b}\t{%2, %0|%0, %2}",
  "sar{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_216[] = {
  "sar{b}\t{%1, %0|%0, %1}",
  "sar{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_223[] = {
  "shr{l}\t{%2, %0|%0, %2}",
  "shr{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_229[] = {
  "shr{w}\t{%2, %0|%0, %2}",
  "shr{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_236[] = {
  "shr{b}\t{%2, %0|%0, %2}",
  "shr{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_237[] = {
  "shr{b}\t{%1, %0|%0, %1}",
  "shr{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_244[] = {
  "rol{l}\t{%2, %0|%0, %2}",
  "rol{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_246[] = {
  "rol{w}\t{%2, %0|%0, %2}",
  "rol{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_249[] = {
  "rol{b}\t{%1, %0|%0, %1}",
  "rol{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_250[] = {
  "rol{b}\t{%2, %0|%0, %2}",
  "rol{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_253[] = {
  "ror{l}\t{%2, %0|%0, %2}",
  "ror{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_255[] = {
  "ror{w}\t{%2, %0|%0, %2}",
  "ror{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_258[] = {
  "ror{b}\t{%2, %0|%0, %2}",
  "ror{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_259[] = {
  "ror{b}\t{%1, %0|%0, %1}",
  "ror{b}\t{%b1, %0|%0, %b1}",
};

static const char *
output_274 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9525 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P0";
  else
    return "call\t%P0";
}
}

static const char *
output_275 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9540 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[0], Pmode))
    return "call\t%P0";
  return "call\t%A0";
}
}

static const char * const output_276[] = {
  "jmp\t%P0",
  "jmp\t%A0",
};

static const char *
output_277 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9583 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P0";
  else
    return "call\t%P0";
}
}

static const char *
output_278 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9595 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[0], Pmode))
    return "call\t%P0";
  return "call\t%A0";
}
}

static const char * const output_279[] = {
  "jmp\t%P0",
  "jmp\t%A0",
};

static const char *
output_289 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9825 "../../gcc/config/i386/i386.md"
{
#ifdef ASM_OUTPUT_MAX_SKIP_PAD
  ASM_OUTPUT_MAX_SKIP_PAD (asm_out_file, 4, (int)INTVAL (operands[0]));
#else
  /* It is tempting to use ASM_OUTPUT_ALIGN here, but we don't want to do that.
     The align insn is used to avoid 3 jump instructions in the row to improve
     branch prediction and the benefits hardly outweigh the cost of extra 8
     nops on the average inserted by full alignment pseudo operation.  */
#endif
  return "";
}
}

static const char *
output_290 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9848 "../../gcc/config/i386/i386.md"
{ return output_set_got (operands[0], NULL_RTX); }
}

static const char *
output_291 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9858 "../../gcc/config/i386/i386.md"
{ return output_set_got (operands[0], operands[1]); }
}

static const char *
output_294 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 9942 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_IMOV:
      return "mov{l}\t{%1, %0|%0, %1}";

    case TYPE_ALU:
      if (CONST_INT_P (operands[2])
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
	          && INTVAL (operands[2]) != -128)))
	{
	  operands[2] = GEN_INT (-INTVAL (operands[2]));
	  return "sub{l}\t{%2, %0|%0, %2}";
	}
      return "add{l}\t{%2, %0|%0, %2}";

    case TYPE_LEA:
      operands[2] = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
      return "lea{l}\t{%a2, %0|%0, %a2}";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_295 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 11050 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P1";
  else
    return "call\t%P1";
}
}

static const char *
output_296 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 11066 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[1], Pmode))
    return "call\t%P1";
  return "call\t%A1";
}
}

static const char * const output_297[] = {
  "jmp\t%P1",
  "jmp\t%A1",
};

static const char *
output_298 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 11091 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P1";
  else
    return "call\t%P1";
}
}

static const char *
output_299 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 11117 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[1], Pmode))
    return "call\t%P1";
  return "call\t%A1";
}
}

static const char *
output_301 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
//#line 11147 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char * const output_302[] = {
  "jmp\t%P1",
  "jmp\t%A1",
};



static const struct insn_operand_data operand_data[] = 
{
  {
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "q,?mq",
    QImode,
    0,
    1
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,?mr",
    HImode,
    0,
    1
  },
  {
    const0_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,?mr",
    SImode,
    0,
    1
  },
  {
    const0_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm,q",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm,r",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm,r",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "Qmn",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    push_operand,
    "=<",
    SImode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "ri*m",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r*m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    const0_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    1
  },
  {
    push_operand,
    "=X",
    HImode,
    0,
    1
  },
  {
    nonmemory_no_elim_operand,
    "rn",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "r,rn,rm,rn",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=q,q,q,r,r,?r,m",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "q,qn,qm,q,rn,qm,qn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "*qn,m",
    QImode,
    0,
    1
  },
  {
    q_regs_operand,
    "+q",
    QImode,
    1,
    1
  },
  {
    const0_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=Qm,?r",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q,Q",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=R",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=Qm,?R",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q,Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "Qmn",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "+Q",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "Q",
    SImode,
    0,
    1
  },
  {
    push_operand,
    "=<",
    DImode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "riF*m",
    DImode,
    0,
    1
  },
  {
    push_operand,
    "=<,<,<",
    SFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "f,rFm,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,r,m,x,x,x,m,!*y,!m,!*y,?Yi,?r,!*Ym,!r",
    SFmode,
    0,
    1
  },
  {
    general_operand,
    "fm,f,G,rmF,Fr,C,x,xm,x,m,*y,*y,r,Yi,r,*Ym",
    SFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "+f",
    SFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "+f",
    SFmode,
    0,
    1
  },
  {
    push_operand,
    "=<,<,<,<",
    DFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "f,Fo,*r,Y2",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=r,?&q",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm,0",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r,?&q",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm,0",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,?r,?o,?*Ym,?*y,?*Yi,*Y2",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm,r,r,m,r,m",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=*A,r,?r,?*o",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,0,r,r",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,X,X,&r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=*a,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "*0,rm",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=*a,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "*0,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,o",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "roiF,riF",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    no_seg_address_operand,
    "p",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm,r,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r,r",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "g,ri,0,li",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm,ln",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qmn,rn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q,r,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0,r",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qmn,rn,ln",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "qn,qnm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "g,ri",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rmn,rn",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=q,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "g",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rmn",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qmn",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=rm",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=rm",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=qm",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "Qmn",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "%0",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "r",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "i",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    1
  },
  {
    const248_operand,
    "i",
    VOIDmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "ri",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "l",
    VOIDmode,
    0,
    1
  },
  {
    const248_operand,
    "i",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "r",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "i",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,o",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "roiF,riF",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=qm,q",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qn,qm",
    QImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm",
    HImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm",
    SImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm",
    SImode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qnm",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rnm",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "rim",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r,r,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "K,i,mr",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r,r,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%rm,rm,0",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "K,n,mr",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=A",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%a",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=1",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=a",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qm",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=&d",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=&d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "1",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,q,qm,r",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "n,n,qn,n",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,q,qm",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "n,n,qn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,r,rm",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "n,n,rn",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%!*a,r,rm",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "i,i,ri",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,qm",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "ri,rm,L",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,qm",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "rn,rm,L",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm,q",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "qn,qmn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=q,qm,*r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qmn,qn,n",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+q,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "qmn,qn",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "Qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=q,m,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,0",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qmn,qn,rn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+q,m",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+q,qm",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "qmn,qn",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "=Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "Q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "=q",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "0",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "qmn",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=ro",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+r*m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "Ic",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,l",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "cI,M",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,r",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,l",
    HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "cI,M",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "cI",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,r,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,l",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "cI,cI,M",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,r",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "cI,cI",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "Jc",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=*d,rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "*a,0",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "i,i",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,rm",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "I,c",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm,rm",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "I,c",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=r",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm",
    QImode,
    1,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm,qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "I,c",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "+qm,qm",
    QImode,
    1,
    1
  },
  {
    nonmemory_operand,
    "I,c",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const1_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=q",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    const1_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "I",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "rN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=q",
    SImode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=qm",
    QImode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "+qm",
    QImode,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    constant_call_address_operand,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    call_insn_operand,
    "lsm",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    1
  },
  {
    sibcall_insn_operand,
    "s,U",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i,i",
    SImode,
    0,
    1
  },
  {
    constant_call_address_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "lsm",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    sibcall_insn_operand,
    "s,U",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    BLKmode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,r",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i,i",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "lsm",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    sibcall_insn_operand,
    "s,U",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "i,i",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "+f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=D",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=S",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "1",
    SImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    1,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    DImode,
    0,
    1
  },
  {
    push_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    OImode,
    0,
    1
  },
  {
    general_operand,
    "",
    OImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    1
  },
  {
    general_operand,
    "",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    CDImode,
    0,
    1
  },
  {
    general_operand,
    "",
    CDImode,
    0,
    1
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    any_fp_register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const248_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const248_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    QImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ix86_carry_flag_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "",
    QImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    1
  },
  {
    ashldi_input_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    index_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    1
  },
  {
    shiftdi_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_1_to_31_operand,
    "",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const8_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const8_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    1,
    1
  },
  {
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    bt_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    ix86_comparison_operator,
    "",
    QImode,
    0,
    0
  },
  {
    q_regs_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    BLKmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    aligned_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    promotable_binary_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    aligned_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    aligned_operand,
    "",
    HImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    push_operand,
    "",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    push_operand,
    "",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0
  },
  {
    push_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SFmode,
    0,
    0
  },
  {
    push_operand,
    "",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0
  },
  {
    push_operand,
    "",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "q",
    QImode,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    memory_operand,
    "",
    HImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    scratch_operand,
    "q",
    QImode,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    compare_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    ext_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    arith_or_logical_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    commutative_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    commutative_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    arith_or_logical_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "r",
    HImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data insn_data[] = 
{
  /* ../../gcc/config/i386/i386.md:827 */
  {
    "*cmpqi_ccno_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_0 },
#else
    { 0, output_0, 0 },
#endif
    0,
    &operand_data[1],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:827 */
  {
    "*cmphi_ccno_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1 },
#else
    { 0, output_1, 0 },
#endif
    0,
    &operand_data[3],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:827 */
  {
    "*cmpsi_ccno_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_2 },
#else
    { 0, output_2, 0 },
#endif
    0,
    &operand_data[5],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:839 */
  {
    "*cmpqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[7],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:839 */
  {
    "*cmphi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:839 */
  {
    "*cmpsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:848 */
  {
    "*cmpqi_minus_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[7],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:848 */
  {
    "*cmphi_minus_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:848 */
  {
    "*cmpsi_minus_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:859 */
  {
    "*cmpqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%h1, %0|%0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:887 */
  {
    "*cmpqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t%h0, %h0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[14],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:914 */
  {
    "*cmpqi_ext_3_insn",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[16],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:944 */
  {
    "*cmpqi_ext_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[18],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1032 */
  {
    "*pushsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[20],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1049 */
  {
    "*pushsi2_prologue",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[20],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1058 */
  {
    "*popsi1_epilogue",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[22],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1069 */
  {
    "popsi1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pop{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_popsi1,
    &operand_data[22],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1079 */
  {
    "*movsi_xor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[23],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1089 */
  {
    "*movsi_or",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_18 },
#else
    { 0, 0, output_18 },
#endif
    0,
    &operand_data[25],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1140 */
  {
    "*pushhi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "push{l}\t%k1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[27],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1157 */
  {
    "*movhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_20 },
#else
    { 0, 0, output_20 },
#endif
    0,
    &operand_data[29],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:1212 */
  {
    "*swaphi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{l}\t%k1, %k0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[31],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1233 */
  {
    "*movqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_22 },
#else
    { 0, 0, output_22 },
#endif
    0,
    &operand_data[33],
    2,
    0,
    7,
    3
  },
  /* ../../gcc/config/i386/i386.md:1309 */
  {
    "*movstrictqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[35],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:1318 */
  {
    "*movstrictqi_xor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[37],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1328 */
  {
    "*movqi_extv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_25 },
#else
    { 0, 0, output_25 },
#endif
    0,
    &operand_data[39],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1423 */
  {
    "*movsi_extzv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%h1, %0|%0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[41],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1433 */
  {
    "*movqi_extzv_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_27 },
#else
    { 0, 0, output_27 },
#endif
    0,
    &operand_data[43],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1486 */
  {
    "movsi_insv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{b}\t{%b1, %h0|%h0, %b1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_movsi_insv_1,
    &operand_data[45],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1516 */
  {
    "*movqi_insv_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[47],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1533 */
  {
    "*pushdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[49],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1868 */
  {
    "*pushsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_31 },
#else
    { 0, 0, output_31 },
#endif
    0,
    &operand_data[51],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:1918 */
  {
    "*movsf_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_32 },
#else
    { 0, 0, output_32 },
#endif
    0,
    &operand_data[53],
    2,
    0,
    16,
    3
  },
  /* ../../gcc/config/i386/i386.md:2014 */
  {
    "*swapsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_33 },
#else
    { 0, 0, output_33 },
#endif
    0,
    &operand_data[55],
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:2040 */
  {
    "*pushdf_nointeger",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_34 },
#else
    { 0, 0, output_34 },
#endif
    0,
    &operand_data[57],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:2067 */
  {
    "zero_extendhisi2_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhisi2_and,
    &operand_data[59],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2086 */
  {
    "*zero_extendhisi2_movzwl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{wl|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[61],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2103 */
  {
    "*zero_extendqihi2_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[63],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2112 */
  {
    "*zero_extendqihi2_movzbw_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[65],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2122 */
  {
    "*zero_extendqihi2_movzbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%1, %k0|%k0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[67],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2179 */
  {
    "*zero_extendqisi2_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[69],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2188 */
  {
    "*zero_extendqisi2_movzbl_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[71],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2197 */
  {
    "*zero_extendqisi2_movzbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movz{bl|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[73],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2258 */
  {
    "zero_extendsidi2_32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_43 },
#else
    { 0, output_43, 0 },
#endif
    (insn_gen_fn) gen_zero_extendsidi2_32,
    &operand_data[75],
    2,
    0,
    7,
    2
  },
  /* ../../gcc/config/i386/i386.md:2351 */
  {
    "*extendsidi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[77],
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:2461 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_45 },
#else
    { 0, 0, output_45 },
#endif
    (insn_gen_fn) gen_extendhisi2,
    &operand_data[80],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2514 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_46 },
#else
    { 0, 0, output_46 },
#endif
    (insn_gen_fn) gen_extendqihi2,
    &operand_data[82],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2540 */
  {
    "extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendqisi2,
    &operand_data[73],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2566 */
  {
    "*adddi3_doubleword",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[84],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2589 */
  {
    "*addsi3_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[87],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2602 */
  {
    "addqi3_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addqi3_cc,
    &operand_data[90],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2615 */
  {
    "*lea_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lea{l}\t{%a1, %0|%0, %a1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[93],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2640 */
  {
    "*addsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_52 },
#else
    { 0, 0, output_52 },
#endif
    0,
    &operand_data[95],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:2769 */
  {
    "*addhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_53 },
#else
    { 0, 0, output_53 },
#endif
    0,
    &operand_data[98],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2817 */
  {
    "*addhi_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_54 },
#else
    { 0, 0, output_54 },
#endif
    0,
    &operand_data[101],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2865 */
  {
    "*addqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_55 },
#else
    { 0, 0, output_55 },
#endif
    0,
    &operand_data[104],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2917 */
  {
    "*addqi_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_56 },
#else
    { 0, 0, output_56 },
#endif
    0,
    &operand_data[107],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:2972 */
  {
    "*addqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_57 },
#else
    { 0, 0, output_57 },
#endif
    0,
    &operand_data[110],
    2,
    1,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3012 */
  {
    "*addsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_58 },
#else
    { 0, 0, output_58 },
#endif
    0,
    &operand_data[112],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3121 */
  {
    "*addhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_59 },
#else
    { 0, 0, output_59 },
#endif
    0,
    &operand_data[115],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3168 */
  {
    "*addqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_60 },
#else
    { 0, 0, output_60 },
#endif
    0,
    &operand_data[118],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3209 */
  {
    "*addsi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_61 },
#else
    { 0, 0, output_61 },
#endif
    0,
    &operand_data[121],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3314 */
  {
    "*addhi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_62 },
#else
    { 0, 0, output_62 },
#endif
    0,
    &operand_data[124],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3359 */
  {
    "*addqi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_63 },
#else
    { 0, 0, output_63 },
#endif
    0,
    &operand_data[127],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3461 */
  {
    "*addsi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_64 },
#else
    { 0, 0, output_64 },
#endif
    0,
    &operand_data[130],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3506 */
  {
    "*addhi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_65 },
#else
    { 0, 0, output_65 },
#endif
    0,
    &operand_data[133],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3551 */
  {
    "*addqi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_66 },
#else
    { 0, 0, output_66 },
#endif
    0,
    &operand_data[136],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3589 */
  {
    "*addsi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_67 },
#else
    { 0, 0, output_67 },
#endif
    0,
    &operand_data[121],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3644 */
  {
    "*addhi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_68 },
#else
    { 0, 0, output_68 },
#endif
    0,
    &operand_data[124],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3690 */
  {
    "*addqi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_69 },
#else
    { 0, 0, output_69 },
#endif
    0,
    &operand_data[127],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3767 */
  {
    "addqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_70 },
#else
    { 0, 0, output_70 },
#endif
    (insn_gen_fn) gen_addqi_ext_1,
    &operand_data[139],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3804 */
  {
    "*addqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[142],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3826 */
  {
    "*lea_general_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[145],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3879 */
  {
    "*lea_general_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[149],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3929 */
  {
    "*lea_general_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[153],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4050 */
  {
    "*subdi3_doubleword",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[158],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4072 */
  {
    "*subqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[161],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4072 */
  {
    "*subhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[164],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4072 */
  {
    "*subsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[167],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4094 */
  {
    "*subqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[170],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4105 */
  {
    "*subqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[161],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4105 */
  {
    "*subhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[164],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4105 */
  {
    "*subsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[167],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4136 */
  {
    "*subqi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[161],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4136 */
  {
    "*subhi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[164],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4136 */
  {
    "*subsi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[167],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*addqi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[172],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*subqi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[176],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*addhi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[180],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*subhi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[184],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*addsi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[188],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4177 */
  {
    "*subsi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[192],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4224 */
  {
    "*addqi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[196],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4224 */
  {
    "*addhi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[199],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4224 */
  {
    "*addsi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4237 */
  {
    "*subqi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[7],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4237 */
  {
    "*subhi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[9],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4237 */
  {
    "*subsi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[11],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*addqi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[90],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*subqi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[161],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*addhi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[98],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*subhi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[164],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*addsi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[87],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4249 */
  {
    "*subsi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[167],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4315 */
  {
    "*mulsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_104 },
#else
    { 0, output_104, 0 },
#endif
    0,
    &operand_data[205],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4354 */
  {
    "*mulhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_105 },
#else
    { 0, output_105, 0 },
#endif
    0,
    &operand_data[208],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:4373 */
  {
    "*mulqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{b}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[211],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4407 */
  {
    "*mulsidi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{l}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[214],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4407 */
  {
    "*umulsidi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{l}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[214],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4421 */
  {
    "*mulqihi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{b}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[217],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4421 */
  {
    "*umulqihi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{b}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[217],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4470 */
  {
    "*smulsi3_highpart_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "imul{l}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[220],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4470 */
  {
    "*umulsi3_highpart_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul{l}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[220],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4508 */
  {
    "divqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{b}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_divqi3,
    &operand_data[224],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4508 */
  {
    "udivqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{b}\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_udivqi3,
    &operand_data[224],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4533 */
  {
    "*divmodhi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[227],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4533 */
  {
    "*divmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[231],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4568 */
  {
    "*divmodhi4_noext",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{w}\t%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[235],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4568 */
  {
    "*divmodsi4_noext",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "idiv{l}\t%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[240],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4592 */
  {
    "*udivmodhi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[227],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4592 */
  {
    "*udivmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[231],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4613 */
  {
    "*udivmodhi4_noext",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{w}\t%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[235],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4613 */
  {
    "*udivmodsi4_noext",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "div{l}\t%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[240],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4686 */
  {
    "*testqi_1_maybe_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_123 },
#else
    { 0, 0, output_123 },
#endif
    0,
    &operand_data[245],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4711 */
  {
    "*testqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[247],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:4711 */
  {
    "*testhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[249],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:4711 */
  {
    "*testsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[251],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:4739 */
  {
    "*testqi_ext_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[253],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4773 */
  {
    "*testqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%1, %h0|%h0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[255],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4789 */
  {
    "*testqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "test{b}\t{%h1, %h0|%h0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[18],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4829 */
  {
    "*testqi_ext_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[257],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5005 */
  {
    "*andsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_131 },
#else
    { 0, 0, output_131 },
#endif
    0,
    &operand_data[260],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5062 */
  {
    "*andhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_132 },
#else
    { 0, 0, output_132 },
#endif
    0,
    &operand_data[263],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5093 */
  {
    "*andqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_133 },
#else
    { 0, output_133, 0 },
#endif
    0,
    &operand_data[104],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:5106 */
  {
    "*andqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[266],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5175 */
  {
    "*andqi_2_maybe_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_135 },
#else
    { 0, 0, output_135 },
#endif
    0,
    &operand_data[268],
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:5199 */
  {
    "*andqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[118],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5199 */
  {
    "*andhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[115],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5199 */
  {
    "*andsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[112],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5228 */
  {
    "*andqi_2_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[271],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5246 */
  {
    "andqi_ext_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_andqi_ext_0,
    &operand_data[273],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5266 */
  {
    "*andqi_ext_0_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[273],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5310 */
  {
    "*andqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[276],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5328 */
  {
    "*andqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[142],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*iorhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[115],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*xorhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[115],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*iorsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[112],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*xorsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[112],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5417 */
  {
    "*iorqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_148 },
#else
    { 0, output_148, 0 },
#endif
    0,
    &operand_data[279],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:5417 */
  {
    "*xorqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_149 },
#else
    { 0, output_149, 0 },
#endif
    0,
    &operand_data[279],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:5453 */
  {
    "*iorqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[282],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5453 */
  {
    "*xorqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[282],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*iorqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[118],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*xorqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[118],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*iorhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[115],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*xorhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[115],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*iorsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[112],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5464 */
  {
    "*xorsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[112],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5507 */
  {
    "*iorqi_2_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[284],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5507 */
  {
    "*xorqi_2_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[284],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*iorqi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[127],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*xorqi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[127],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*iorhi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[124],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*xorhi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[124],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*iorsi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[121],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5521 */
  {
    "*xorsi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[121],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5534 */
  {
    "*iorqi_ext_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[273],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5534 */
  {
    "*xorqi_ext_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[273],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5571 */
  {
    "*iorqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[276],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5571 */
  {
    "*xorqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[276],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5590 */
  {
    "*iorqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[286],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5590 */
  {
    "*xorqi_ext_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%h2, %h0|%h0, %h2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[286],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5696 */
  {
    "*xorqi_cc_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%2, %h0|%h0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[289],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5729 */
  {
    "*negdi2_doubleword",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[292],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5752 */
  {
    "*negqi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[294],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5752 */
  {
    "*neghi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[296],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5752 */
  {
    "*negsi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[298],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5778 */
  {
    "*negqi2_cmpz",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[294],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5778 */
  {
    "*neghi2_cmpz",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[296],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5778 */
  {
    "*negsi2_cmpz",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[298],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5817 */
  {
    "*one_cmplhi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[296],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5817 */
  {
    "*one_cmplsi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[298],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5826 */
  {
    "*one_cmplqi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_182 },
#else
    { 0, output_182, 0 },
#endif
    0,
    &operand_data[300],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5846 */
  {
    "*one_cmplqi2_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[294],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5846 */
  {
    "*one_cmplhi2_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[296],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5846 */
  {
    "*one_cmplsi2_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[298],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6205 */
  {
    "x86_shld",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shld{l}\t{%s2%1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_shld,
    &operand_data[302],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:6270 */
  {
    "*ashlsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_187 },
#else
    { 0, 0, output_187 },
#endif
    0,
    &operand_data[305],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6430 */
  {
    "*ashlsi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_188 },
#else
    { 0, 0, output_188 },
#endif
    0,
    &operand_data[308],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6481 */
  {
    "*ashlsi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_189 },
#else
    { 0, 0, output_189 },
#endif
    0,
    &operand_data[311],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6589 */
  {
    "*ashlhi3_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_190 },
#else
    { 0, 0, output_190 },
#endif
    0,
    &operand_data[314],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6636 */
  {
    "*ashlhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_191 },
#else
    { 0, 0, output_191 },
#endif
    0,
    &operand_data[317],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6682 */
  {
    "*ashlhi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_192 },
#else
    { 0, 0, output_192 },
#endif
    0,
    &operand_data[320],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6733 */
  {
    "*ashlhi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_193 },
#else
    { 0, 0, output_193 },
#endif
    0,
    &operand_data[323],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6792 */
  {
    "*ashlqi3_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_194 },
#else
    { 0, 0, output_194 },
#endif
    0,
    &operand_data[326],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:6857 */
  {
    "*ashlqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_195 },
#else
    { 0, 0, output_195 },
#endif
    0,
    &operand_data[329],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6921 */
  {
    "*ashlqi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_196 },
#else
    { 0, 0, output_196 },
#endif
    0,
    &operand_data[332],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6972 */
  {
    "*ashlqi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_197 },
#else
    { 0, 0, output_197 },
#endif
    0,
    &operand_data[335],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:7221 */
  {
    "*ashrdi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[338],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7254 */
  {
    "x86_shrd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shrd{l}\t{%s2%1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_shrd,
    &operand_data[302],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7303 */
  {
    "*ashrsi3_31",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_200 },
#else
    { 0, output_200, 0 },
#endif
    0,
    &operand_data[341],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7344 */
  {
    "*ashrsi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7369 */
  {
    "*ashrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_202 },
#else
    { 0, output_202, 0 },
#endif
    0,
    &operand_data[347],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7396 */
  {
    "*ashrsi3_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7412 */
  {
    "*ashrsi3_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[350],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7447 */
  {
    "*ashrsi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[308],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7462 */
  {
    "*ashrsi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[311],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7499 */
  {
    "*ashrhi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7511 */
  {
    "*ashrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_208 },
#else
    { 0, output_208, 0 },
#endif
    0,
    &operand_data[356],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7526 */
  {
    "*ashrhi3_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7542 */
  {
    "*ashrhi3_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[359],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7560 */
  {
    "*ashrhi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[320],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7575 */
  {
    "*ashrhi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[323],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7596 */
  {
    "*ashrqi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7608 */
  {
    "*ashrqi3_1_one_bit_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7621 */
  {
    "*ashrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_215 },
#else
    { 0, output_215, 0 },
#endif
    0,
    &operand_data[367],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7633 */
  {
    "*ashrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_216 },
#else
    { 0, output_216, 0 },
#endif
    0,
    &operand_data[370],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7649 */
  {
    "*ashrqi3_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[372],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7665 */
  {
    "*ashrqi3_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7683 */
  {
    "*ashrqi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[332],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7698 */
  {
    "*ashrqi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sar{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[335],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7856 */
  {
    "*lshrdi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[338],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7896 */
  {
    "*lshrsi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7921 */
  {
    "*lshrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_223 },
#else
    { 0, output_223, 0 },
#endif
    0,
    &operand_data[347],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:7949 */
  {
    "*lshrsi3_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7965 */
  {
    "*lshrsi3_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[350],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8000 */
  {
    "*lshrsi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[308],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8015 */
  {
    "*lshrsi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[311],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8052 */
  {
    "*lshrhi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8064 */
  {
    "*lshrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_229 },
#else
    { 0, output_229, 0 },
#endif
    0,
    &operand_data[356],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8079 */
  {
    "*lshrhi3_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8095 */
  {
    "*lshrhi3_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[359],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8113 */
  {
    "*lshrhi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[320],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8128 */
  {
    "*lshrhi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[323],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8149 */
  {
    "*lshrqi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8161 */
  {
    "*lshrqi3_1_one_bit_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8173 */
  {
    "*lshrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_236 },
#else
    { 0, output_236, 0 },
#endif
    0,
    &operand_data[367],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8185 */
  {
    "*lshrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_237 },
#else
    { 0, output_237, 0 },
#endif
    0,
    &operand_data[370],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8201 */
  {
    "*lshrqi2_one_bit_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8217 */
  {
    "*lshrqi2_one_bit_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8235 */
  {
    "*lshrqi2_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[332],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8250 */
  {
    "*lshrqi2_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shr{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[335],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8285 */
  {
    "ix86_rotldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ix86_rotldi3,
    &operand_data[378],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8341 */
  {
    "*rotlsi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rol{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8367 */
  {
    "*rotlsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_244 },
#else
    { 0, output_244, 0 },
#endif
    0,
    &operand_data[347],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8399 */
  {
    "*rotlhi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rol{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8411 */
  {
    "*rotlhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_246 },
#else
    { 0, output_246, 0 },
#endif
    0,
    &operand_data[356],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8440 */
  {
    "*rotlqi3_1_one_bit_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rol{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8452 */
  {
    "*rotlqi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rol{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8464 */
  {
    "*rotlqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_249 },
#else
    { 0, output_249, 0 },
#endif
    0,
    &operand_data[370],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8477 */
  {
    "*rotlqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_250 },
#else
    { 0, output_250, 0 },
#endif
    0,
    &operand_data[367],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8508 */
  {
    "ix86_rotrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ix86_rotrdi3,
    &operand_data[378],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8564 */
  {
    "*rotrsi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ror{l}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[344],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8590 */
  {
    "*rotrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_253 },
#else
    { 0, output_253, 0 },
#endif
    0,
    &operand_data[347],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8622 */
  {
    "*rotrhi3_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ror{w}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[353],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8634 */
  {
    "*rotrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_255 },
#else
    { 0, output_255, 0 },
#endif
    0,
    &operand_data[356],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8663 */
  {
    "*rotrqi3_1_one_bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ror{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8675 */
  {
    "*rotrqi3_1_one_bit_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ror{b}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8687 */
  {
    "*rotrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_258 },
#else
    { 0, output_258, 0 },
#endif
    0,
    &operand_data[367],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8699 */
  {
    "*rotrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_259 },
#else
    { 0, output_259, 0 },
#endif
    0,
    &operand_data[370],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:8934 */
  {
    "*btsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bt{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[382],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8967 */
  {
    "*setcc_si_1_and",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[384],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8984 */
  {
    "*setcc_si_1_movzbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[384],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8999 */
  {
    "*setcc_qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "set%C1\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[386],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9008 */
  {
    "*setcc_qi_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "set%C1\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[388],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9090 */
  {
    "*jcc_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%+j%C1\t%l0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[390],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9108 */
  {
    "*jcc_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%+j%c1\t%l0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[390],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9246 */
  {
    "*jcc_btsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[392],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9279 */
  {
    "*jcc_btsi_mask",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[396],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9308 */
  {
    "*jcc_btsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[392],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9341 */
  {
    "*jcc_btsi_mask_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[396],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9377 */
  {
    "jump",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "jmp\t%l0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_jump,
    &operand_data[390],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9397 */
  {
    "*indirect_jump",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "jmp\t%A0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[216],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9442 */
  {
    "*tablejump_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "jmp\t%A0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[401],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9518 */
  {
    "*call_pop_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_274 },
#else
    { 0, 0, output_274 },
#endif
    0,
    &operand_data[403],
    3,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:9533 */
  {
    "*call_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_275 },
#else
    { 0, 0, output_275 },
#endif
    0,
    &operand_data[406],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9547 */
  {
    "*sibcall_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_276 },
#else
    { 0, output_276, 0 },
#endif
    0,
    &operand_data[409],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:9579 */
  {
    "*call_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_277 },
#else
    { 0, 0, output_277 },
#endif
    0,
    &operand_data[412],
    2,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:9591 */
  {
    "*call_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_278 },
#else
    { 0, 0, output_278 },
#endif
    0,
    &operand_data[414],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9602 */
  {
    "*sibcall_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_279 },
#else
    { 0, output_279, 0 },
#endif
    0,
    &operand_data[416],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:9714 */
  {
    "blockage",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_blockage,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9731 */
  {
    "*memory_blockage",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[418],
    1,
    1,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9740 */
  {
    "prologue_use",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_prologue_use,
    &operand_data[390],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9762 */
  {
    "return_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ret",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return_internal,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9773 */
  {
    "return_internal_long",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rep\n\tret",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return_internal_long,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9783 */
  {
    "return_pop_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ret\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return_pop_internal,
    &operand_data[258],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9792 */
  {
    "return_indirect_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "jmp\t%A0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return_indirect_internal,
    &operand_data[303],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9800 */
  {
    "nop",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nop",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_nop,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9808 */
  {
    "vswapmov",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movl.s\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vswapmov,
    &operand_data[419],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9822 */
  {
    "pad",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_289 },
#else
    { 0, 0, output_289 },
#endif
    (insn_gen_fn) gen_pad,
    &operand_data[390],
    1,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:9843 */
  {
    "set_got",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_290 },
#else
    { 0, 0, output_290 },
#endif
    (insn_gen_fn) gen_set_got,
    &operand_data[23],
    1,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9852 */
  {
    "set_got_labelled",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_291 },
#else
    { 0, 0, output_291 },
#endif
    (insn_gen_fn) gen_set_got_labelled,
    &operand_data[421],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:9891 */
  {
    "eh_return_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_eh_return_internal,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9899 */
  {
    "leave",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "leave",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_leave,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:9935 */
  {
    "pro_epilogue_adjust_stack_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_294 },
#else
    { 0, 0, output_294 },
#endif
    (insn_gen_fn) gen_pro_epilogue_adjust_stack_1,
    &operand_data[423],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:11042 */
  {
    "*call_value_pop_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_295 },
#else
    { 0, 0, output_295 },
#endif
    0,
    &operand_data[402],
    4,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:11058 */
  {
    "*call_value_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_296 },
#else
    { 0, 0, output_296 },
#endif
    0,
    &operand_data[426],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:11073 */
  {
    "*sibcall_value_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_297 },
#else
    { 0, output_297, 0 },
#endif
    0,
    &operand_data[430],
    4,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11086 */
  {
    "*call_value_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_298 },
#else
    { 0, 0, output_298 },
#endif
    0,
    &operand_data[402],
    3,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:11112 */
  {
    "*call_value_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_299 },
#else
    { 0, 0, output_299 },
#endif
    0,
    &operand_data[426],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:11130 */
  {
    "allocate_stack_worker_32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "call\t___chkstk",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_allocate_stack_worker_32,
    &operand_data[434],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11141 */
  {
    "swapxf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_301 },
#else
    { 0, 0, output_301 },
#endif
    (insn_gen_fn) gen_swapxf,
    &operand_data[436],
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:11156 */
  {
    "*sibcall_value_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_302 },
#else
    { 0, output_302, 0 },
#endif
    0,
    &operand_data[430],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11237 */
  {
    "*strmovsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{l|d}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[438],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11267 */
  {
    "*strmovhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movsw",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[438],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11324 */
  {
    "*strmovqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movsb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[438],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:784 */
  {
    "cbranchqi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cbranchqi4,
    &operand_data[442],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:784 */
  {
    "cbranchhi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cbranchhi4,
    &operand_data[446],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:784 */
  {
    "cbranchsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cbranchsi4,
    &operand_data[450],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:803 */
  {
    "cstoreqi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cstoreqi4,
    &operand_data[454],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:803 */
  {
    "cstorehi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cstorehi4,
    &operand_data[458],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:803 */
  {
    "cstoresi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cstoresi4,
    &operand_data[462],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:820 */
  {
    "cmpsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpsi_1,
    &operand_data[451],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:902 */
  {
    "cmpqi_ext_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpqi_ext_3,
    &operand_data[466],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:967 */
  {
    "cbranchxf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cbranchxf4,
    &operand_data[468],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:985 */
  {
    "cbranchcc4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cbranchcc4,
    &operand_data[472],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1000 */
  {
    "cstorecc4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cstorecc4,
    &operand_data[476],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1017 */
  {
    "movsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movsi,
    &operand_data[451],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1134 */
  {
    "movhi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movhi,
    &operand_data[447],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1297 */
  {
    "movstrictqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movstrictqi,
    &operand_data[480],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1527 */
  {
    "movdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdi,
    &operand_data[482],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1650 */
  {
    "movdi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[484],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1659 */
  {
    "movoi-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[482],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1838 */
  {
    "movoi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movoi,
    &operand_data[486],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1844 */
  {
    "movoi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[488],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1856 */
  {
    "movcdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movcdi,
    &operand_data[490],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1894 */
  {
    "movcdi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[492],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:1904 */
  {
    "movdf-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[494],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2029 */
  {
    "movdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdf,
    &operand_data[496],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2054 */
  {
    "zero_extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhisi2,
    &operand_data[498],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2076 */
  {
    "zero_extendhisi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[500],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2095 */
  {
    "zero_extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqihi2,
    &operand_data[501],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2132 */
  {
    "zero_extendqihi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[501],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2145 */
  {
    "zero_extendqihi2+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[501],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2161 */
  {
    "zero_extendqisi2-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[503],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2171 */
  {
    "zero_extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqisi2,
    &operand_data[505],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2207 */
  {
    "zero_extendqisi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[505],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2219 */
  {
    "zero_extendqisi2+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[505],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2235 */
  {
    "zero_extendsidi2-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[507],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2246 */
  {
    "zero_extendsidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendsidi2,
    &operand_data[509],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2300 */
  {
    "zero_extendsidi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[511],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2309 */
  {
    "extendsidi2-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[513],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2337 */
  {
    "extendsidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extendsidi2,
    &operand_data[515],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2388 */
  {
    "extendsidi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[518],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2403 */
  {
    "extendsidi2+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[518],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2433 */
  {
    "addqi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[515],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2559 */
  {
    "addqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addqi3,
    &operand_data[521],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2559 */
  {
    "addhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addhi3,
    &operand_data[524],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2559 */
  {
    "addsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addsi3,
    &operand_data[527],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:2566 */
  {
    "addsi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[530],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:3826 */
  {
    "addsi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[533],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:3879 */
  {
    "addsi3+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[537],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:3929 */
  {
    "subqi3-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[541],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4001 */
  {
    "subqi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[546],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4043 */
  {
    "subqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subqi3,
    &operand_data[521],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4043 */
  {
    "subhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subhi3,
    &operand_data[524],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4043 */
  {
    "subsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subsi3,
    &operand_data[527],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4050 */
  {
    "subsi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[530],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "addqi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addqi3_carry,
    &operand_data[549],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "subqi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subqi3_carry,
    &operand_data[549],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "addhi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addhi3_carry,
    &operand_data[554],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "subhi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subhi3_carry,
    &operand_data[554],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "addsi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addsi3_carry,
    &operand_data[559],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4164 */
  {
    "subsi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subsi3_carry,
    &operand_data[559],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4279 */
  {
    "addxf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addxf3,
    &operand_data[564],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4279 */
  {
    "subxf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_subxf3,
    &operand_data[564],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4289 */
  {
    "mulhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulhi3,
    &operand_data[567],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4289 */
  {
    "mulsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulsi3,
    &operand_data[570],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4298 */
  {
    "mulqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulqi3,
    &operand_data[573],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4385 */
  {
    "mulsidi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulsidi3,
    &operand_data[576],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4385 */
  {
    "umulsidi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_umulsidi3,
    &operand_data[576],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4396 */
  {
    "mulqihi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulqihi3,
    &operand_data[579],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4396 */
  {
    "umulqihi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_umulqihi3,
    &operand_data[579],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4436 */
  {
    "smulsi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_smulsi3_highpart,
    &operand_data[582],
    4,
    1,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4436 */
  {
    "umulsi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_umulsi3_highpart,
    &operand_data[582],
    4,
    1,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4522 */
  {
    "divmodhi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_divmodhi4,
    &operand_data[586],
    4,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4522 */
  {
    "divmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_divmodsi4,
    &operand_data[590],
    4,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4533 */
  {
    "divmodsi4+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[594],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4533 */
  {
    "udivmodhi4-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[598],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4581 */
  {
    "udivmodhi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_udivmodhi4,
    &operand_data[586],
    4,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4581 */
  {
    "udivmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_udivmodsi4,
    &operand_data[590],
    4,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4592 */
  {
    "udivmodsi4+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[594],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4592 */
  {
    "testsi_ccno_1-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[598],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4650 */
  {
    "testsi_ccno_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_testsi_ccno_1,
    &operand_data[601],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4659 */
  {
    "testqi_ccz_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_testqi_ccz_1,
    &operand_data[603],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4726 */
  {
    "testqi_ext_ccno_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_testqi_ext_ccno_0,
    &operand_data[605],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4846 */
  {
    "testqi_ext_ccno_0+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[607],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4905 */
  {
    "testqi_ext_ccno_0+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[612],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4926 */
  {
    "andqi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[607],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4949 */
  {
    "andqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_andqi3,
    &operand_data[521],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4949 */
  {
    "andhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_andhi3,
    &operand_data[524],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:4949 */
  {
    "andsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_andsi3,
    &operand_data[527],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5117 */
  {
    "andsi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[533],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5127 */
  {
    "andsi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[466],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5137 */
  {
    "andsi3+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[466],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5353 */
  {
    "iorqi3-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[616],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5374 */
  {
    "iorqi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[619],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "iorqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_iorqi3,
    &operand_data[521],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "xorqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xorqi3,
    &operand_data[521],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "iorhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_iorhi3,
    &operand_data[524],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "xorhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xorhi3,
    &operand_data[524],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "iorsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_iorsi3,
    &operand_data[527],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5398 */
  {
    "xorsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xorsi3,
    &operand_data[527],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5608 */
  {
    "xorsi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[616],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5608 */
  {
    "xorsi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[616],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5629 */
  {
    "xorqi_cc_ext_1-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[619],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5629 */
  {
    "xorqi_cc_ext_1-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[619],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5648 */
  {
    "xorqi_cc_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xorqi_cc_ext_1,
    &operand_data[622],
    3,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5723 */
  {
    "negqi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_negqi2,
    &operand_data[521],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5723 */
  {
    "neghi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_neghi2,
    &operand_data[524],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5723 */
  {
    "negsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_negsi2,
    &operand_data[527],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5729 */
  {
    "negsi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[530],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5811 */
  {
    "one_cmplqi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_one_cmplqi2,
    &operand_data[521],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5811 */
  {
    "one_cmplhi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_one_cmplhi2,
    &operand_data[524],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5811 */
  {
    "one_cmplsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_one_cmplsi2,
    &operand_data[527],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5858 */
  {
    "one_cmplsi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[625],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5858 */
  {
    "one_cmplsi2+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[629],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5858 */
  {
    "ashldi3-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[633],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:5886 */
  {
    "ashldi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[637],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6003 */
  {
    "ashldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashldi3,
    &operand_data[641],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6184 */
  {
    "ashldi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[644],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6195 */
  {
    "x86_shift_adj_1-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[644],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6219 */
  {
    "x86_shift_adj_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_x86_shift_adj_1,
    &operand_data[648],
    4,
    3,
    1,
    0
  },
  /* ../../gcc/config/i386/i386.md:6235 */
  {
    "x86_shift_adj_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_x86_shift_adj_2,
    &operand_data[648],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6263 */
  {
    "ashlsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashlsi3,
    &operand_data[652],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6319 */
  {
    "ashlsi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[655],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6346 */
  {
    "ashlhi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[658],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6582 */
  {
    "ashlhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashlhi3,
    &operand_data[661],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:6783 */
  {
    "ashlqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashlqi3,
    &operand_data[664],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7074 */
  {
    "ashrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrdi3,
    &operand_data[667],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7081 */
  {
    "x86_64_shift_adj_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_x86_64_shift_adj_3,
    &operand_data[670],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7233 */
  {
    "x86_64_shift_adj_3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[673],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7244 */
  {
    "x86_shift_adj_3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[673],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7268 */
  {
    "x86_shift_adj_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_x86_shift_adj_3,
    &operand_data[648],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7296 */
  {
    "ashrsi3_31",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrsi3_31,
    &operand_data[341],
    3,
    0,
    2,
    0
  },
  /* ../../gcc/config/i386/i386.md:7337 */
  {
    "ashrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrsi3,
    &operand_data[652],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7492 */
  {
    "ashrhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrhi3,
    &operand_data[661],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7589 */
  {
    "ashrqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrqi3,
    &operand_data[664],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7754 */
  {
    "lshrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrdi3,
    &operand_data[667],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7868 */
  {
    "lshrdi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[673],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7879 */
  {
    "lshrsi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[673],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:7889 */
  {
    "lshrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrsi3,
    &operand_data[652],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8045 */
  {
    "lshrhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrhi3,
    &operand_data[661],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8142 */
  {
    "lshrqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrqi3,
    &operand_data[664],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8266 */
  {
    "rotldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotldi3,
    &operand_data[667],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8285 */
  {
    "rotldi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[677],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8334 */
  {
    "rotlsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotlsi3,
    &operand_data[652],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8392 */
  {
    "rotlhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotlhi3,
    &operand_data[661],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8423 */
  {
    "rotlhi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[501],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8433 */
  {
    "rotlqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotlqi3,
    &operand_data[664],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8489 */
  {
    "rotrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotrdi3,
    &operand_data[667],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8508 */
  {
    "rotrdi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[677],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8557 */
  {
    "rotrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotrsi3,
    &operand_data[652],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8615 */
  {
    "rotrhi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotrhi3,
    &operand_data[661],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8646 */
  {
    "rotrhi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[501],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8656 */
  {
    "rotrqi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_rotrqi3,
    &operand_data[664],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8714 */
  {
    "extv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extv,
    &operand_data[681],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8731 */
  {
    "extzv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extzv,
    &operand_data[685],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8748 */
  {
    "insv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_insv,
    &operand_data[689],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8967 */
  {
    "insv+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[693],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:8984 */
  {
    "insv+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[693],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9025 */
  {
    "insv+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[695],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9036 */
  {
    "insv+4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[697],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9047 */
  {
    "insv+5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[695],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9067 */
  {
    "insv+6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[697],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9134 */
  {
    "indirect_jump-6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[698],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9150 */
  {
    "indirect_jump-5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[698],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9246 */
  {
    "indirect_jump-4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[700],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9279 */
  {
    "indirect_jump-3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[704],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9308 */
  {
    "indirect_jump-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[700],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9341 */
  {
    "indirect_jump-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[704],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9392 */
  {
    "indirect_jump",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_indirect_jump,
    &operand_data[609],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9404 */
  {
    "tablejump",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_tablejump,
    &operand_data[709],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9452 */
  {
    "tablejump+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[710],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9473 */
  {
    "call_pop-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[710],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9505 */
  {
    "call_pop",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call_pop,
    &operand_data[714],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9559 */
  {
    "call",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call,
    &operand_data[718],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9569 */
  {
    "sibcall",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall,
    &operand_data[718],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9624 */
  {
    "call_value_pop",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call_value_pop,
    &operand_data[720],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9638 */
  {
    "call_value",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call_value,
    &operand_data[725],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9651 */
  {
    "sibcall_value",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall_value,
    &operand_data[725],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9666 */
  {
    "untyped_call",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_untyped_call,
    &operand_data[729],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9722 */
  {
    "memory_blockage",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_memory_blockage,
    &operand_data[0],
    0,
    2,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9750 */
  {
    "return",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_return,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9838 */
  {
    "prologue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_prologue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9862 */
  {
    "epilogue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_epilogue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9867 */
  {
    "sibcall_epilogue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall_epilogue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9872 */
  {
    "eh_return",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_eh_return,
    &operand_data[533],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9891 */
  {
    "eh_return+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9907 */
  {
    "movmemsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movmemsi,
    &operand_data[732],
    6,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:9985 */
  {
    "builtin_setjmp_receiver",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_builtin_setjmp_receiver,
    &operand_data[390],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10008 */
  {
    "builtin_setjmp_receiver+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[738],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10035 */
  {
    "builtin_setjmp_receiver+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[742],
    5,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10066 */
  {
    "builtin_setjmp_receiver+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[747],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10087 */
  {
    "builtin_setjmp_receiver+4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[546],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10102 */
  {
    "builtin_setjmp_receiver+5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[546],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10115 */
  {
    "builtin_setjmp_receiver+6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[751],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10137 */
  {
    "builtin_setjmp_receiver+7",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[755],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10147 */
  {
    "builtin_setjmp_receiver+8",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[758],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10159 */
  {
    "builtin_setjmp_receiver+9",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[761],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10169 */
  {
    "builtin_setjmp_receiver+10",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[764],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10179 */
  {
    "builtin_setjmp_receiver+11",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[767],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10191 */
  {
    "builtin_setjmp_receiver+12",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[756],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10205 */
  {
    "builtin_setjmp_receiver+13",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[765],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10219 */
  {
    "builtin_setjmp_receiver+14",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[768],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10233 */
  {
    "builtin_setjmp_receiver+15",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[770],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10244 */
  {
    "builtin_setjmp_receiver+16",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[773],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10255 */
  {
    "builtin_setjmp_receiver+17",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[776],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10267 */
  {
    "builtin_setjmp_receiver+18",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[779],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10289 */
  {
    "builtin_setjmp_receiver+19",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[527],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10303 */
  {
    "builtin_setjmp_receiver+20",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[524],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10317 */
  {
    "builtin_setjmp_receiver+21",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[521],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10338 */
  {
    "builtin_setjmp_receiver+22",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[783],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10359 */
  {
    "builtin_setjmp_receiver+23",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[787],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10377 */
  {
    "builtin_setjmp_receiver+24",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[791],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10412 */
  {
    "builtin_setjmp_receiver+25",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[795],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10426 */
  {
    "builtin_setjmp_receiver+26",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[795],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10443 */
  {
    "builtin_setjmp_receiver+27",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[799],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10460 */
  {
    "builtin_setjmp_receiver+28",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[803],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10481 */
  {
    "builtin_setjmp_receiver+29",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[807],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10498 */
  {
    "builtin_setjmp_receiver+30",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[807],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10516 */
  {
    "builtin_setjmp_receiver+31",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[811],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10529 */
  {
    "builtin_setjmp_receiver+32",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[813],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10540 */
  {
    "builtin_setjmp_receiver+33",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[533],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10555 */
  {
    "builtin_setjmp_receiver+34",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[814],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10564 */
  {
    "movxf-33",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[816],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10573 */
  {
    "movxf-32",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[706],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10583 */
  {
    "movxf-31",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[819],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10593 */
  {
    "movxf-30",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[821],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10623 */
  {
    "movxf-29",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10633 */
  {
    "movxf-28",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10645 */
  {
    "movxf-27",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10653 */
  {
    "movxf-26",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10663 */
  {
    "movxf-25",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10676 */
  {
    "movxf-24",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[824],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10690 */
  {
    "movxf-23",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10704 */
  {
    "movxf-22",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10715 */
  {
    "movxf-21",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[824],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10727 */
  {
    "movxf-20",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[647],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10740 */
  {
    "movxf-19",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[612],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10756 */
  {
    "movxf-18",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10766 */
  {
    "movxf-17",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10778 */
  {
    "movxf-16",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10786 */
  {
    "movxf-15",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10796 */
  {
    "movxf-14",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10809 */
  {
    "movxf-13",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[826],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10823 */
  {
    "movxf-12",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10837 */
  {
    "movxf-11",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10848 */
  {
    "movxf-10",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[826],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10860 */
  {
    "movxf-9",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[760],
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10872 */
  {
    "movxf-8",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[705],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10886 */
  {
    "movxf-7",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[828],
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10936 */
  {
    "movxf-6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[831],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10949 */
  {
    "movxf-5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[835],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10962 */
  {
    "movxf-4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[839],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10980 */
  {
    "movxf-3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[843],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:10996 */
  {
    "movxf-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[847],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11012 */
  {
    "movxf-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[851],
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11124 */
  {
    "movxf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movxf,
    &operand_data[855],
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11183 */
  {
    "strmov",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_strmov,
    &operand_data[857],
    4,
    4,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11212 */
  {
    "strmov_singleop",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_strmov_singleop,
    &operand_data[857],
    6,
    0,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11297 */
  {
    "strset",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_strset,
    &operand_data[857],
    3,
    1,
    0,
    0
  },
  /* ../../gcc/config/i386/i386.md:11317 */
  {
    "strlenqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_strlenqi_1,
    &operand_data[863],
    3,
    0,
    0,
    0
  },
};


const char *
get_insn_name (int code)
{
  if (code == NOOP_MOVE_INSN_CODE)
    return "NOOP_MOVE";
  else
    return insn_data[code].name;
}
