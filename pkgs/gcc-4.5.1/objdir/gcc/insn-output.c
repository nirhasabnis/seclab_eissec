/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "flags.h"
#include "ggc.h"
#include "rtl.h"
#include "expr.h"
#include "insn-codes.h"
#include "tm_p.h"
#include "function.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"

#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "toplev.h"
#include "output.h"
#include "target.h"
#include "tm-constrs.h"

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

static const char * const output_3[] = {
  "test{q}\t%0, %0",
  "cmp{q}\t{%1, %0|%0, %1}",
};

static const char *
output_16 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1159 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_18 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1206 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_20 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1240 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_21 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1240 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_24 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1275 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 1);
}

static const char *
output_26 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1325 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_27 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1325 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 0, 0);
}

static const char *
output_31 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1378 "../../gcc/config/i386/i386.md"
{
#ifndef HAVE_AS_IX86_SAHF
  if (TARGET_64BIT)
    return ASM_BYTE "0x9e";
  else
#endif
  return "sahf";
}
}

static const char *
output_32 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1400 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 0);
}

static const char *
output_33 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1428 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 0);
}

static const char *
output_34 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1451 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 0);
}

static const char *
output_35 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1470 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 1);
}

static const char *
output_36 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1498 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 1);
}

static const char *
output_37 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1521 "../../gcc/config/i386/i386.md"
 return output_fp_compare (insn, operands, 1, 1);
}

static const char *
output_43 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1615 "../../gcc/config/i386/i386.md"
{
  operands[1] = constm1_rtx;
  return "or{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_44 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1629 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_SSELOG1:
      if (get_attr_mode (insn) == MODE_TI)
        return "%vpxor\t%0, %d0";
      return "%vxorps\t%0, %d0";

    case TYPE_SSEMOV:
      switch (get_attr_mode (insn))
	{
	case MODE_TI:
	  return "%vmovdqa\t{%1, %0|%0, %1}";
	case MODE_V4SF:
	  return "%vmovaps\t{%1, %0|%0, %1}";
	case MODE_SI:
          return "%vmovd\t{%1, %0|%0, %1}";
	case MODE_SF:
          return "%vmovss\t{%1, %0|%0, %1}";
	default:
	  gcc_unreachable ();
	}

    case TYPE_MMX:
      return "pxor\t%0, %0";

    case TYPE_MMXMOV:
      if (get_attr_mode (insn) == MODE_DI)
	return "movq\t{%1, %0|%0, %1}";
      return "movd\t{%1, %0|%0, %1}";

    case TYPE_LEA:
      return "lea{l}\t{%a1, %0|%0, %a1}";

    default:
      gcc_assert (!flag_pic || LEGITIMATE_PIC_OPERAND_P (operands[1]));
      return "mov{l}\t{%1, %0|%0, %1}";
    }
}
}

static const char *
output_47 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1774 "../../gcc/config/i386/i386.md"
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
output_53 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1950 "../../gcc/config/i386/i386.md"
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
output_60 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2093 "../../gcc/config/i386/i386.md"
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
output_62 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2198 "../../gcc/config/i386/i386.md"
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

static const char * const output_66[] = {
  "#",
  "#",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "%vpxor\t%0, %d0",
  "%vmovq\t{%1, %0|%0, %1}",
  "%vmovdqa\t{%1, %0|%0, %1}",
  "%vmovq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movlps\t{%1, %0|%0, %1}",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
};

static const char *
output_67 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2637 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vxorps\t%0, %0, %0";
    case 1:
    case 2:
      if (misaligned_operand (operands[0], OImode)
	  || misaligned_operand (operands[1], OImode))
	return "vmovdqu\t{%1, %0|%0, %1}";
      else
	return "vmovdqa\t{%1, %0|%0, %1}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_68 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2676 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      if (get_attr_mode (insn) == MODE_V4SF)
	return "%vxorps\t%0, %d0";
      else
	return "%vpxor\t%0, %d0";
    case 1:
    case 2:
      /* TDmode values are passed as TImode on the stack.  Moving them
	 to stack may result in unaligned memory access.  */
      if (misaligned_operand (operands[0], TImode)
	  || misaligned_operand (operands[1], TImode))
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovups\t{%1, %0|%0, %1}";
	 else
	   return "%vmovdqu\t{%1, %0|%0, %1}";
	}
      else
	{
	  if (get_attr_mode (insn) == MODE_V4SF)
	    return "%vmovaps\t{%1, %0|%0, %1}";
	 else
	   return "%vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_69 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2811 "../../gcc/config/i386/i386.md"
{
  /* Anything else should be already split before reg-stack.  */
  gcc_assert (which_alternative == 1);
  return "push{l}\t%1";
}
}

static const char *
output_70 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2869 "../../gcc/config/i386/i386.md"
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
output_71 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2959 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char *
output_72 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2983 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_73 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2995 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_74 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3042 "../../gcc/config/i386/i386.md"
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
      return "#";
    case 5:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "%vxorps\t%0, %d0";
	case MODE_V2DF:
	  return "%vxorpd\t%0, %d0";
	case MODE_TI:
	  return "%vpxor\t%0, %d0";
	default:
	  gcc_unreachable ();
	}
    case 6:
    case 7:
    case 8:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "%vmovaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "%vmovapd\t{%1, %0|%0, %1}";
	case MODE_TI:
	  return "%vmovdqa\t{%1, %0|%0, %1}";
	case MODE_DI:
	  return "%vmovq\t{%1, %0|%0, %1}";
	case MODE_DF:
	  if (TARGET_AVX)
	    {
	      if (REG_P (operands[0]) && REG_P (operands[1]))
		return "vmovsd\t{%1, %0, %0|%0, %0, %1}";
	      else
		return "vmovsd\t{%1, %0|%0, %1}";
	    }
	  else
	    return "movsd\t{%1, %0|%0, %1}";
	case MODE_V1DF:
	  if (TARGET_AVX)
	    {
	      if (REG_P (operands[0]))
		return "vmovlpd\t{%1, %0, %0|%0, %0, %1}";
	      else
		return "vmovlpd\t{%1, %0|%0, %1}";
	    }
	  else
	    return "movlpd\t{%1, %0|%0, %1}";
	case MODE_V2SF:
	  if (TARGET_AVX)
	    {
	      if (REG_P (operands[0]))
		return "vmovlps\t{%1, %0, %0|%0, %0, %1}";
	      else
		return "vmovlps\t{%1, %0|%0, %1}";
	    }
	  else
	    return "movlps\t{%1, %0|%0, %1}";
	default:
	  gcc_unreachable ();
	}

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_75 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3331 "../../gcc/config/i386/i386.md"
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
      return "#";

    case 5:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "xorps\t%0, %0";
	case MODE_V2DF:
	  return "xorpd\t%0, %0";
	case MODE_TI:
	  return "pxor\t%0, %0";
	default:
	  gcc_unreachable ();
	}
    case 6:
    case 7:
    case 8:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	case MODE_TI:
	  return "movdqa\t{%1, %0|%0, %1}";
	case MODE_DI:
	  return "movq\t{%1, %0|%0, %1}";
	case MODE_DF:
	  return "movsd\t{%1, %0|%0, %1}";
	case MODE_V1DF:
	  return "movlpd\t{%1, %0|%0, %1}";
	case MODE_V2SF:
	  return "movlps\t{%1, %0|%0, %1}";
	default:
	  gcc_unreachable ();
	}

    default:
      gcc_unreachable();
    }
}
}

static const char *
output_76 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3460 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char *
output_77 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3486 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_78 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3498 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_79 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3534 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3: case 4:
      return "#";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_80 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3561 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return standard_80387_constant_opcode (operands[1]);

    case 3: case 4:
      return "#";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_81 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3595 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      if (get_attr_mode (insn) == MODE_V4SF)
	return "%vmovaps\t{%1, %0|%0, %1}";
      else
	return "%vmovdqa\t{%1, %0|%0, %1}";
    case 2:
      if (get_attr_mode (insn) == MODE_V4SF)
	return "%vxorps\t%0, %d0";
      else
	return "%vpxor\t%0, %d0";
    case 3:
    case 4:
	return "#";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_82 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3639 "../../gcc/config/i386/i386.md"
{
  /* This insn should be already split before reg-stack.  */
  gcc_unreachable ();
}
}

static const char *
output_83 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3748 "../../gcc/config/i386/i386.md"
{
  if (STACK_TOP_P (operands[0]))
    return "fxch\t%1";
  else
    return "fxch\t%0";
}
}

static const char * const output_92[] = {
  "#",
  "#",
  "#",
  "movd\t{%1, %0|%0, %1}",
  "movd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
  "%vmovd\t{%1, %0|%0, %1}",
};

static const char *
output_94 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4198 "../../gcc/config/i386/i386.md"
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
output_95 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4251 "../../gcc/config/i386/i386.md"
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
output_97 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4402 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
    case 1:
      return output_387_reg_move (insn, operands);

    case 2:
      return "%vcvtss2sd\t{%1, %d0|%d0, %1}";

    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_99 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4433 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_100 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4462 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_101 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4462 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_102 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4552 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);
    case 1:
      return "%vcvtsd2ss\t{%1, %d0|%d0, %1}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_104 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4584 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_105 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4594 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);
    case 1:
      return "%vcvtsd2ss\t{%1, %d0|%d0, %1}";

    default:
      return "#";
    }
}
}

static const char *
output_106 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4617 "../../gcc/config/i386/i386.md"
{
  switch (which_alternative)
    {
    case 0:
      return output_387_reg_move (insn, operands);

    default:
      return "#";
    }
}
}

static const char *
output_107 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4638 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_108 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4686 "../../gcc/config/i386/i386.md"
{
  gcc_assert (!which_alternative);
  return output_387_reg_move (insn, operands);
}
}

static const char *
output_109 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4700 "../../gcc/config/i386/i386.md"
{
  gcc_assert (!which_alternative);
  return output_387_reg_move (insn, operands);
}
}

static const char *
output_110 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4713 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_111 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4713 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_112 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4722 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_113 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4722 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_121 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4982 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 1);
}

static const char *
output_122 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4982 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 1);
}

static const char *
output_123 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4982 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 1);
}

static const char *
output_130 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5068 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_132 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5125 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_133 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5125 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char * const output_155[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_156[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_159[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
};

static const char * const output_160[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
};

static const char * const output_161[] = {
  "fild%Z1\t%1",
  "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
};

static const char * const output_162[] = {
  "fild%Z1\t%1",
  "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
};

static const char * const output_173[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_174[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_175[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_176[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_177[] = {
  "fild%Z1\t%1",
  "#",
};

static const char * const output_178[] = {
  "fild%Z1\t%1",
  "#",
};

static const char *
output_197 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5993 "../../gcc/config/i386/i386.md"
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
output_198 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5993 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_LEA:
      operands[2] = SET_SRC (XVECEXP (PATTERN (insn), 0, 0));
      return "lea{q}\t{%a2, %0|%0, %a2}";

    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      /* Use add as much as possible to replace lea for AGU optimization. */
      if (which_alternative == 2 && TARGET_OPT_AGU)
        return "add{q}\t{%1, %0|%0, %1}";
        
      gcc_assert (rtx_equal_p (operands[0], operands[1]));

      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (DImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{q}\t{%2, %0|%0, %2}";
        }
      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_199 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6122 "../../gcc/config/i386/i386.md"
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
output_200 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6170 "../../gcc/config/i386/i386.md"
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
output_201 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6218 "../../gcc/config/i386/i386.md"
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
output_202 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6270 "../../gcc/config/i386/i386.md"
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
output_203 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6325 "../../gcc/config/i386/i386.md"
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
output_204 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6372 "../../gcc/config/i386/i386.md"
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
output_205 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6372 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* ???? In DImode, we ought to handle there the 32bit case too
	 - do we need new constraint?  */
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (DImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{q}\t{%2, %0|%0, %2}";
        }
      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_206 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6477 "../../gcc/config/i386/i386.md"
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
output_207 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6524 "../../gcc/config/i386/i386.md"
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
output_208 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6566 "../../gcc/config/i386/i386.md"
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
output_209 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6566 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
	  gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* ???? In DImode, we ought to handle there the 32bit case too
	 - do we need new constraint?  */
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4, %eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (DImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{q}\t{%2, %0|%0, %2}";
        }
      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_210 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6668 "../../gcc/config/i386/i386.md"
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
output_211 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6713 "../../gcc/config/i386/i386.md"
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
output_212 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6815 "../../gcc/config/i386/i386.md"
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
output_213 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6860 "../../gcc/config/i386/i386.md"
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
output_214 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6905 "../../gcc/config/i386/i386.md"
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
output_215 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6948 "../../gcc/config/i386/i386.md"
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
output_216 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6948 "../../gcc/config/i386/i386.md"
{
  switch (get_attr_type (insn))
    {
    case TYPE_INCDEC:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      if (operands[2] == const1_rtx)
        return "inc{q}\t%0";
      else
        {
          gcc_assert (operands[2] == constm1_rtx);
          return "dec{q}\t%0";
	}

    default:
      gcc_assert (rtx_equal_p (operands[0], operands[1]));
      /* Make things pretty and `subl $4,%eax' rather than `addl $-4,%eax'.
	 Exceptions: -128 encodes smaller than 128, so swap sign and op.  */
      if (CONST_INT_P (operands[2])
	  /* Avoid overflows.  */
	  && (DImode != DImode
	      || ((INTVAL (operands[2]) & ((((unsigned int) 1) << 31) - 1))))
          && (INTVAL (operands[2]) == 128
	      || (INTVAL (operands[2]) < 0
		  && INTVAL (operands[2]) != -128)))
        {
          operands[2] = GEN_INT (-INTVAL (operands[2]));
          return "sub{q}\t{%2, %0|%0, %2}";
        }
      return "add{q}\t{%2, %0|%0, %2}";
    }
}
}

static const char *
output_217 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6999 "../../gcc/config/i386/i386.md"
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
output_218 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7045 "../../gcc/config/i386/i386.md"
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
output_219 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7125 "../../gcc/config/i386/i386.md"
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

static const char * const output_262[] = {
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %1, %0|%0, %1, %2}",
  "imul{l}\t{%2, %0|%0, %2}",
};

static const char * const output_263[] = {
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %1, %0|%0, %1, %2}",
  "imul{w}\t{%2, %0|%0, %2}",
};

static const char *
output_281 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 8170 "../../gcc/config/i386/i386.md"
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
output_289 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 8484 "../../gcc/config/i386/i386.md"
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
output_290 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 8541 "../../gcc/config/i386/i386.md"
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

static const char * const output_291[] = {
  "and{b}\t{%2, %0|%0, %2}",
  "and{b}\t{%2, %0|%0, %2}",
  "and{l}\t{%k2, %k0|%k0, %k2}",
};

static const char *
output_293 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 8660 "../../gcc/config/i386/i386.md"
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

static const char * const output_308[] = {
  "or{b}\t{%2, %0|%0, %2}",
  "or{b}\t{%2, %0|%0, %2}",
  "or{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_309[] = {
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{b}\t{%2, %0|%0, %2}",
  "xor{l}\t{%k2, %k0|%k0, %k2}",
};

static const char * const output_376[] = {
  "not{b}\t%0",
  "not{l}\t%k0",
};

static const char *
output_383 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10057 "../../gcc/config/i386/i386.md"
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
output_384 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10226 "../../gcc/config/i386/i386.md"
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
output_385 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10276 "../../gcc/config/i386/i386.md"
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
output_386 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10377 "../../gcc/config/i386/i386.md"
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
output_387 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10424 "../../gcc/config/i386/i386.md"
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
output_388 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10478 "../../gcc/config/i386/i386.md"
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
output_389 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10528 "../../gcc/config/i386/i386.md"
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
output_390 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10580 "../../gcc/config/i386/i386.md"
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
output_391 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10645 "../../gcc/config/i386/i386.md"
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
output_392 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10717 "../../gcc/config/i386/i386.md"
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
output_393 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 10767 "../../gcc/config/i386/i386.md"
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

static const char * const output_396[] = {
  "{cltd|cdq}",
  "sar{l}\t{%2, %0|%0, %2}",
};

static const char * const output_398[] = {
  "sar{l}\t{%2, %0|%0, %2}",
  "sar{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_404[] = {
  "sar{w}\t{%2, %0|%0, %2}",
  "sar{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_411[] = {
  "sar{b}\t{%2, %0|%0, %2}",
  "sar{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_412[] = {
  "sar{b}\t{%1, %0|%0, %1}",
  "sar{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_419[] = {
  "shr{l}\t{%2, %0|%0, %2}",
  "shr{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_425[] = {
  "shr{w}\t{%2, %0|%0, %2}",
  "shr{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_432[] = {
  "shr{b}\t{%2, %0|%0, %2}",
  "shr{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_433[] = {
  "shr{b}\t{%1, %0|%0, %1}",
  "shr{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_440[] = {
  "rol{l}\t{%2, %0|%0, %2}",
  "rol{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_442[] = {
  "rol{w}\t{%2, %0|%0, %2}",
  "rol{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_445[] = {
  "rol{b}\t{%1, %0|%0, %1}",
  "rol{b}\t{%b1, %0|%0, %b1}",
};

static const char * const output_446[] = {
  "rol{b}\t{%2, %0|%0, %2}",
  "rol{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_449[] = {
  "ror{l}\t{%2, %0|%0, %2}",
  "ror{l}\t{%b2, %0|%0, %b2}",
};

static const char * const output_451[] = {
  "ror{w}\t{%2, %0|%0, %2}",
  "ror{w}\t{%b2, %0|%0, %b2}",
};

static const char * const output_454[] = {
  "ror{b}\t{%2, %0|%0, %2}",
  "ror{b}\t{%b2, %0|%0, %b2}",
};

static const char * const output_455[] = {
  "ror{b}\t{%1, %0|%0, %1}",
  "ror{b}\t{%b1, %0|%0, %b1}",
};

static const char *
output_481 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13526 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P0";
  else
    return "call\t%P0";
}
}

static const char *
output_482 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13541 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[0], Pmode))
    return "call\t%P0";
  return "call\t%A0";
}
}

static const char * const output_483[] = {
  "jmp\t%P0",
  "jmp\t%A0",
};

static const char *
output_484 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13584 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P0";
  else
    return "call\t%P0";
}
}

static const char *
output_485 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13596 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[0], Pmode))
    return "call\t%P0";
  return "call\t%A0";
}
}

static const char * const output_486[] = {
  "jmp\t%P0",
  "jmp\t%A0",
};

static const char *
output_496 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13869 "../../gcc/config/i386/i386.md"
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
output_497 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13892 "../../gcc/config/i386/i386.md"
{ return output_set_got (operands[0], NULL_RTX); }
}

static const char *
output_498 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 13902 "../../gcc/config/i386/i386.md"
{ return output_set_got (operands[0], operands[1]); }
}

static const char *
output_506 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14149 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{w}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_507 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14149 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{l}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_508 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14169 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{w}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_509 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14169 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{l}\t{%1, %0|%0, %1}";
#endif
}
}

static const char *
output_510 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14169 "../../gcc/config/i386/i386.md"
{
#if TARGET_MACHO
  return "popcnt\t{%1, %0|%0, %1}";
#else
  return "popcnt{q}\t{%1, %0|%0, %1}";
#endif
}
}

static const char * const output_511[] = {
  "bswap\t%0",
  "movbe\t{%1, %0|%0, %1}",
  "movbe\t{%1, %0|%0, %1}",
};

static const char * const output_513[] = {
  "xchg{b}\t{%h0, %b0|%b0, %h0}",
  "rol{w}\t{$8, %0|%0, 8}",
};

static const char *
output_528 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14840 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_529 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14840 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_530 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14860 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_531 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14860 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_532 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14879 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_533 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14879 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_534 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14895 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_535 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14895 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_536 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14910 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_537 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14910 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_538 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14925 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_539 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14925 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_540 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14952 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_541 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14952 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_543 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14988 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_544 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 14988 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_545 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15006 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_546 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15006 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_547 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15026 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_548 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15026 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_549 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15046 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_550 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15046 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_551 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15046 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_552 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15046 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_553 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15066 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_554 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15066 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_555 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15066 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_556 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15066 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_557 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15086 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_558 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15104 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_559 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15123 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_560 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15140 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_561 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15154 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_562 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15171 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_563 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15171 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_564 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15189 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_565 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15189 "../../gcc/config/i386/i386.md"
 return which_alternative ? "#" : output_387_binary_op (insn, operands);
}

static const char *
output_566 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15207 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_567 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15207 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_568 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15224 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_569 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15224 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_570 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15242 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_571 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15242 "../../gcc/config/i386/i386.md"
 return output_387_binary_op (insn, operands);
}

static const char *
output_572 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15304 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_573 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 15304 "../../gcc/config/i386/i386.md"
 return output_387_reg_move (insn, operands);
}

static const char *
output_612 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16624 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_616 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16685 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_617 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16685 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_625 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16879 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_627 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16938 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_628 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 16938 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_636 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17141 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_638 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17200 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char *
output_639 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 17200 "../../gcc/config/i386/i386.md"
 return output_fix_trunc (insn, operands, 0);
}

static const char * const output_668[] = {
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_669[] = {
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_671[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
  "cmov%O2%C1\t{%2, %0|%0, %2}",
  "cmov%O2%c1\t{%3, %0|%0, %3}",
};

static const char * const output_672[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
  "#",
  "#",
};

static const char * const output_673[] = {
  "fcmov%F1\t{%2, %0|%0, %2}",
  "fcmov%f1\t{%3, %0|%0, %3}",
};

static const char *
output_692 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 18755 "../../gcc/config/i386/i386.md"
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
output_694 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20064 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P1";
  else
    return "call\t%P1";
}
}

static const char *
output_695 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20080 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[1], Pmode))
    return "call\t%P1";
  return "call\t%A1";
}
}

static const char * const output_696[] = {
  "jmp\t%P1",
  "jmp\t%A1",
};

static const char *
output_697 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20105 "../../gcc/config/i386/i386.md"
{
  if (SIBLING_CALL_P (insn))
    return "jmp\t%P1";
  else
    return "call\t%P1";
}
}

static const char *
output_698 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20157 "../../gcc/config/i386/i386.md"
{
  if (constant_call_address_operand (operands[1], Pmode))
    return "call\t%P1";
  return "call\t%A1";
}
}

static const char * const output_699[] = {
  "jmp\t%P1",
  "jmp\t%A1",
};

static const char *
output_700 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20238 "../../gcc/config/i386/i386.md"
{ return ASM_SHORT "0x0b0f"; }
}

static const char *
output_701 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20338 "../../gcc/config/i386/i386.md"
{
  static const char * const patterns[4] = {
   "prefetchnta\t%a0", "prefetcht2\t%a0", "prefetcht1\t%a0", "prefetcht0\t%a0"
  };

  int locality = INTVAL (operands[1]);
  gcc_assert (locality >= 0 && locality <= 3);

  return patterns[locality];
}
}

static const char *
output_702 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 20378 "../../gcc/config/i386/i386.md"
{
  if (INTVAL (operands[1]) == 0)
    return "prefetch\t%a0";
  else
    return "prefetchw\t%a0";
}
}

static const char * const output_717[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vpxor\t%0, %0, %0",
  "vmovq\t{%1, %0|%0, %1}",
  "vmovq\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_718[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vpxor\t%0, %0, %0",
  "vmovq\t{%1, %0|%0, %1}",
  "vmovq\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_719[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vpxor\t%0, %0, %0",
  "vmovq\t{%1, %0|%0, %1}",
  "vmovq\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_720[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vpxor\t%0, %0, %0",
  "vmovq\t{%1, %0|%0, %1}",
  "vmovq\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_721[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_722[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_723[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_724[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_725[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vxorps\t%0, %0, %0",
  "vmovaps\t{%1, %0|%0, %1}",
  "vmovlps\t{%1, %0, %0|%0, %0, %1}",
  "vmovlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_726[] = {
  "pxor\t%0, %0",
  "movq\t{%1, %0|%0, %1}",
  "movq\t{%1, %0|%0, %1}",
  "movdq2q\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "xorps\t%0, %0",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
  "#",
  "#",
};

static const char * const output_729[] = {
  "pfsub\t{%2, %0|%0, %2}",
  "pfsubr\t{%1, %0|%0, %1}",
};

static const char * const output_752[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_754[] = {
  "punpckhdq\t%0, %0",
  "unpckhps\t%0, %0",
  "#",
  "#",
  "#",
  "#",
};

static const char *
output_816 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1251 "../../gcc/config/i386/mmx.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "pinsrw\t{%3, %2, %0|%0, %2, %3}";
  else
    return "pinsrw\t{%3, %k2, %0|%0, %k2, %3}";
}
}

static const char *
output_818 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1298 "../../gcc/config/i386/mmx.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "pshufw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char * const output_822[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_824[] = {
  "punpckhdq\t%0, %0",
  "punpckhdq\t%0, %0",
  "pshufd\t{$85, %1, %0|%0, %1, 85}",
  "unpckhps\t%0, %0",
  "#",
  "#",
  "#",
};

static const char *
output_825 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1543 "../../gcc/config/i386/mmx.md"
{
  /* These two instructions have the same operation, but their encoding
     is different.  Prefer the one that is de facto standard.  */
  if (TARGET_SSE || TARGET_3DNOW_A)
    return "pavgb\t{%2, %0|%0, %2}";
  else
    return "pavgusb\t{%2, %0|%0, %2}";
}
}

static const char *
output_832 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_833 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_834 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_835 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_836 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_837 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_838 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_839 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_840 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_841 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_842 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_843 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_844 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 183 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	case MODE_V4SF:
	  return "vmovaps\t{%1, %0|%0, %1}";
	case MODE_V4DF:
	case MODE_V2DF:
	  return "vmovapd\t{%1, %0|%0, %1}";
	default:
	  return "vmovdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_845 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_846 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_847 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_848 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_849 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_850 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_851 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return standard_sse_constant_opcode (insn, operands[1]);
    case 1:
    case 2:
      switch (get_attr_mode (insn))
	{
	case MODE_V4SF:
	  return "movaps\t{%1, %0|%0, %1}";
	case MODE_V2DF:
	  return "movapd\t{%1, %0|%0, %1}";
	default:
	  return "movdqa\t{%1, %0|%0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1158 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2909 "../../gcc/config/i386/sse.md"
 return TARGET_AVX ? "vcvtpd2dq{x}\t{%1, %0|%0, %1}"
		       : "cvtpd2dq\t{%1, %0|%0, %1}";
}

static const char *
output_1160 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2941 "../../gcc/config/i386/sse.md"
 return TARGET_AVX ? "vcvttpd2dq{x}\t{%1, %0|%0, %1}"
		       : "cvttpd2dq\t{%1, %0|%0, %1}";
}

static const char *
output_1166 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3033 "../../gcc/config/i386/sse.md"
 return TARGET_AVX ? "vcvtpd2ps{x}\t{%1, %0|%0, %1}"
		       : "cvtpd2ps\t{%1, %0|%0, %1}";
}

static const char * const output_1169[] = {
  "vmovhlps\t{%2, %1, %0|%0, %1, %2}",
  "vmovlps\t{%H2, %1, %0|%0, %1, %H2}",
  "vmovhps\t{%2, %0|%0, %2}",
};

static const char * const output_1170[] = {
  "movhlps\t{%2, %0|%0, %2}",
  "movlps\t{%H2, %0|%0, %H2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char * const output_1171[] = {
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
  "vmovlps\t{%2, %H0|%H0, %2}",
};

static const char * const output_1172[] = {
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
  "movlps\t{%2, %H0|%H0, %2}",
};

static const char *
output_1183 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3587 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 8) << 4;
  mask |= (INTVAL (operands[6]) - 8) << 6;
  operands[3] = GEN_INT (mask);

  return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1184 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3629 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1185 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3629 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  return "vshufps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1186 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3655 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  return "shufps\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char *
output_1187 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3655 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[3]) << 0;
  mask |= INTVAL (operands[4]) << 2;
  mask |= (INTVAL (operands[5]) - 4) << 4;
  mask |= (INTVAL (operands[6]) - 4) << 6;
  operands[3] = GEN_INT (mask);

  return "shufps\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char * const output_1188[] = {
  "%vmovhps\t{%1, %0|%0, %1}",
  "%vmovhlps\t{%1, %d0|%d0, %1}",
  "%vmovlps\t{%H1, %d0|%d0, %H1}",
};

static const char * const output_1189[] = {
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "vmovlps\t{%2, %H0|%H0, %2}",
};

static const char * const output_1190[] = {
  "movhps\t{%2, %0|%0, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "movlps\t{%2, %H0|%H0, %2}",
};

static const char * const output_1191[] = {
  "vmovlps\t{%1, %0|%0, %1}",
  "vmovaps\t{%1, %0|%0, %1}",
  "vmovlps\t{%1, %0, %0|%0, %0, %1}",
};

static const char * const output_1192[] = {
  "movlps\t{%1, %0|%0, %1}",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
};

static const char * const output_1193[] = {
  "shufps\t{$0xe4, %1, %2, %0|%0, %2, %1, 0xe4}",
  "vmovlps\t{%2, %1, %0|%0, %1, %2}",
  "vmovlps\t{%2, %0|%0, %2}",
};

static const char * const output_1194[] = {
  "shufps\t{$0xe4, %1, %0|%0, %1, 0xe4}",
  "movlps\t{%2, %0|%0, %2}",
  "movlps\t{%2, %0|%0, %2}",
};

static const char * const output_1197[] = {
  "vshufps\t{$0, %1, %1, %0|%0, %1, %1, 0}",
  "vbroadcastss\t{%1, %0|%0, %1}",
};

static const char * const output_1199[] = {
  "vunpcklps\t{%2, %1, %0|%0, %1, %2}",
  "vinsertps\t{$0x10, %2, %1, %0|%0, %1, %2, 0x10}",
  "vmovss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1200[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "insertps\t{$0x10, %2, %0|%0, %2, 0x10}",
  "movss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1201[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "movss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1202[] = {
  "vmovlhps\t{%2, %1, %0|%0, %1, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1203[] = {
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char * const output_1204[] = {
  "vinsertps\t{$0xe, %2, %2, %0|%0, %2, %2, 0xe}",
  "vmovss\t{%2, %0|%0, %2}",
  "vmovd\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
  "vpinsrd\t{$0, %2, %1, %0|%0, %1, %2, 0}",
  "#",
};

static const char * const output_1205[] = {
  "vinsertps\t{$0xe, %2, %2, %0|%0, %2, %2, 0xe}",
  "vmovd\t{%2, %0|%0, %2}",
  "vmovd\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
  "vpinsrd\t{$0, %2, %1, %0|%0, %1, %2, 0}",
  "#",
};

static const char * const output_1206[] = {
  "insertps\t{$0xe, %2, %0|%0, %2, 0xe}",
  "movss\t{%2, %0|%0, %2}",
  "movd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "pinsrd\t{$0, %2, %0|%0, %2, 0}",
  "#",
};

static const char * const output_1207[] = {
  "insertps\t{$0xe, %2, %0|%0, %2, 0xe}",
  "movd\t{%2, %0|%0, %2}",
  "movd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "pinsrd\t{$0, %2, %0|%0, %2, 0}",
  "#",
};

static const char * const output_1208[] = {
  "movss\t{%2, %0|%0, %2}",
  "movd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "#",
};

static const char * const output_1209[] = {
  "movd\t{%2, %0|%0, %2}",
  "movd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "#",
};

static const char * const output_1210[] = {
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "#",
};

static const char * const output_1211[] = {
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "#",
};

static const char *
output_1212 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4028 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])) << 4);
  return "vinsertps\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1213 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4046 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])) << 4);
  return "insertps\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char * const output_1232[] = {
  "vunpckhpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovddup\t{%H1, %0|%0, %H1}",
  "vmovlpd\t{%H1, %2, %0|%0, %2, %H1}",
  "vmovhpd\t{%1, %0|%0, %1}",
};

static const char * const output_1233[] = {
  "unpckhpd\t{%2, %0|%0, %2}",
  "movddup\t{%H1, %0|%0, %H1}",
  "movlpd\t{%H1, %0|%0, %H1}",
  "movhpd\t{%1, %0|%0, %1}",
};

static const char * const output_1234[] = {
  "unpckhpd\t{%2, %0|%0, %2}",
  "movlpd\t{%H1, %0|%0, %H1}",
  "movhpd\t{%1, %0|%0, %1}",
};

static const char * const output_1235[] = {
  "vmovddup\t{%1, %0|%0, %1}",
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1236[] = {
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovddup\t{%1, %0|%0, %1}",
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovlpd\t{%2, %H0|%H0, %2}",
};

static const char * const output_1237[] = {
  "unpcklpd\t{%2, %0|%0, %2}",
  "movddup\t{%1, %0|%0, %1}",
  "movhpd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %H0|%H0, %2}",
};

static const char * const output_1238[] = {
  "unpcklpd\t{%2, %0|%0, %2}",
  "movhpd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %H0|%H0, %2}",
};

static const char *
output_1239 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4576 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 4) << 1;
  mask |= (INTVAL (operands[5]) - 2) << 2;
  mask |= (INTVAL (operands[6]) - 6) << 3;
  operands[3] = GEN_INT (mask);

  return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1244 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4691 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1245 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4691 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  return "vshufpd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1246 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4713 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  return "shufpd\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char *
output_1247 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4713 "../../gcc/config/i386/sse.md"
{
  int mask;
  mask = INTVAL (operands[3]);
  mask |= (INTVAL (operands[4]) - 2) << 1;
  operands[3] = GEN_INT (mask);

  return "shufpd\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char * const output_1248[] = {
  "vmovhpd\t{%1, %0|%0, %1}",
  "vunpckhpd\t{%1, %1, %0|%0, %1, %1}",
  "#",
  "#",
  "#",
};

static const char * const output_1249[] = {
  "movhpd\t{%1, %0|%0, %1}",
  "unpckhpd\t%0, %0",
  "#",
  "#",
  "#",
};

static const char * const output_1250[] = {
  "%vmovlpd\t{%1, %0|%0, %1}",
  "#",
  "#",
  "#",
  "#",
};

static const char * const output_1251[] = {
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "#",
  "#",
  "#",
};

static const char * const output_1252[] = {
  "movhpd\t{%2, %0|%0, %2}",
  "unpcklpd\t{%2, %0|%0, %2}",
  "shufpd\t{$1, %1, %0|%0, %1, 1}",
  "#",
  "#",
  "#",
};

static const char * const output_1253[] = {
  "vmovsd\t{%2, %0|%0, %2}",
  "vmovlpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovsd\t{%2, %1, %0|%0, %1, %2}",
  "vmovhpd\t{%H1, %2, %0|%0, %2, %H1}",
  "#",
  "#",
  "#",
};

static const char * const output_1254[] = {
  "movsd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %0|%0, %2}",
  "movsd\t{%2, %0|%0, %2}",
  "shufpd\t{$2, %2, %0|%0, %2, 2}",
  "movhpd\t{%H1, %0|%0, %H1}",
  "#",
  "#",
  "#",
};

static const char * const output_1255[] = {
  "movhps\t{%1, %0|%0, %1}",
  "movhlps\t{%1, %0|%0, %1}",
  "movlps\t{%H1, %0|%0, %H1}",
};

static const char * const output_1256[] = {
  "movlps\t{%1, %0|%0, %1}",
  "movaps\t{%1, %0|%0, %1}",
  "movlps\t{%1, %0|%0, %1}",
};

static const char * const output_1257[] = {
  "vmovsd\t{%2, %1, %0|%0, %1, %2}",
  "vmovlpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovlpd\t{%2, %0|%0, %2}",
  "vmovhps\t{%H1, %2, %0|%0, %2, %H1}",
  "vmovhps\t{%1, %H0|%H0, %1}",
};

static const char * const output_1258[] = {
  "movsd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %0|%0, %2}",
  "movlpd\t{%2, %0|%0, %2}",
  "shufpd\t{$2, %2, %0|%0, %2, 2}",
  "movhps\t{%H1, %0|%0, %H1}",
  "movhps\t{%1, %H0|%H0, %1}",
};

static const char * const output_1262[] = {
  "vunpcklpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovhpd\t{%2, %1, %0|%0, %1, %2}",
  "vmovsd\t{%1, %0|%0, %1}",
};

static const char * const output_1263[] = {
  "unpcklpd\t{%2, %0|%0, %2}",
  "movhpd\t{%2, %0|%0, %2}",
  "movsd\t{%1, %0|%0, %1}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char *
output_1317 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5907 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);
  return "vpsrldq\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1321 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5937 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);
  return "psrldq\t{%2, %0|%0, %2}";
}
}

static const char *
output_1325 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5967 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);
  return "vpslldq\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1329 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5996 "../../gcc/config/i386/sse.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) / 8);
  return "pslldq\t{%2, %0|%0, %2}";
}
}

static const char *
output_1459 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6921 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "vpinsrb\t{%3, %2, %1, %0|%0, %1, %2, %3}";
  else
    return "vpinsrb\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
}
}

static const char *
output_1460 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6921 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "vpinsrw\t{%3, %2, %1, %0|%0, %1, %2, %3}";
  else
    return "vpinsrw\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
}
}

static const char *
output_1461 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6921 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "vpinsrd\t{%3, %2, %1, %0|%0, %1, %2, %3}";
  else
    return "vpinsrd\t{%3, %k2, %1, %0|%0, %1, %k2, %3}";
}
}

static const char *
output_1462 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6945 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "pinsrb\t{%3, %2, %0|%0, %2, %3}";
  else
    return "pinsrb\t{%3, %k2, %0|%0, %k2, %3}";
}
}

static const char *
output_1463 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6965 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  if (MEM_P (operands[2]))
    return "pinsrw\t{%3, %2, %0|%0, %2, %3}";
  else
    return "pinsrw\t{%3, %k2, %0|%0, %k2, %3}";
}
}

static const char *
output_1464 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 6986 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (exact_log2 (INTVAL (operands[3])));
  return "pinsrd\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char *
output_1470 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7137 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshufd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1471 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7181 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= INTVAL (operands[2]) << 0;
  mask |= INTVAL (operands[3]) << 2;
  mask |= INTVAL (operands[4]) << 4;
  mask |= INTVAL (operands[5]) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshuflw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1472 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 7226 "../../gcc/config/i386/sse.md"
{
  int mask = 0;
  mask |= (INTVAL (operands[2]) - 4) << 0;
  mask |= (INTVAL (operands[3]) - 4) << 2;
  mask |= (INTVAL (operands[4]) - 4) << 4;
  mask |= (INTVAL (operands[5]) - 4) << 6;
  operands[2] = GEN_INT (mask);

  return "%vpshufhw\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char * const output_1473[] = {
  "vmovd\t{%2, %0|%0, %2}",
  "vmovd\t{%2, %0|%0, %2}",
  "vmovss\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1474[] = {
  "movd\t{%2, %0|%0, %2}",
  "movd\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
  "movss\t{%2, %0|%0, %2}",
};

static const char * const output_1478[] = {
  "vmovhps\t{%1, %0|%0, %1}",
  "vpsrldq\t{$8, %1, %0|%0, %1, 8}",
  "vmovq\t{%H1, %0|%0, %H1}",
};

static const char * const output_1479[] = {
  "movhps\t{%1, %0|%0, %1}",
  "psrldq\t{$8, %0|%0, 8}",
  "movq\t{%H1, %0|%0, %H1}",
};

static const char * const output_1480[] = {
  "movhps\t{%1, %0|%0, %1}",
  "movhlps\t{%1, %0|%0, %1}",
  "movlps\t{%H1, %0|%0, %H1}",
};

static const char * const output_1481[] = {
  "vpshufd\t{$0, %1, %0|%0, %1, 0}",
  "vbroadcastss\t{%1, %0|%0, %1}",
};

static const char * const output_1482[] = {
  "%vpshufd\t{$0, %1, %0|%0, %1, 0}",
  "shufps\t{$0, %0, %0|%0, %0, 0}",
};

static const char * const output_1483[] = {
  "vpunpcklqdq\t{%1, %1, %0|%0, %1, %1}",
  "vmovddup\t{%1, %0|%0, %1}",
};

static const char * const output_1484[] = {
  "punpcklqdq\t%0, %0",
  "movddup\t{%1, %0|%0, %1}",
};

static const char * const output_1485[] = {
  "punpcklqdq\t%0, %0",
  "movlhps\t%0, %0",
};

static const char * const output_1486[] = {
  "vpinsrd\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
  "vpunpckldq\t{%2, %1, %0|%0, %1, %2}",
  "vmovd\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1487[] = {
  "pinsrd\t{$0x1, %2, %0|%0, %2, 0x1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1488[] = {
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1489[] = {
  "unpcklps\t{%2, %0|%0, %2}",
  "movss\t{%1, %0|%0, %1}",
  "punpckldq\t{%2, %0|%0, %2}",
  "movd\t{%1, %0|%0, %1}",
};

static const char * const output_1490[] = {
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1491[] = {
  "punpcklqdq\t{%2, %0|%0, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char * const output_1492[] = {
  "vmovq\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
  "vmovhps\t{%2, %1, %0|%0, %1, %2}",
};

static const char * const output_1493[] = {
  "movq\t{%1, %0|%0, %1}",
  "movq2dq\t{%1, %0|%0, %1}",
  "punpcklqdq\t{%2, %0|%0, %2}",
  "movlhps\t{%2, %0|%0, %2}",
  "movhps\t{%2, %0|%0, %2}",
};

static const char *
output_1550 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9165 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);
  return "vpalignr\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1551 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9182 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);
  return "palignr\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char *
output_1552 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 9200 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) / 8);
  return "palignr\t{%3, %2, %0|%0, %2, %3}";
}
}

static const char * const output_1636[] = {
  "%vpcmpestrm\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestrm\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestri\t{%6, %4, %2|%2, %4, %6}",
  "%vpcmpestri\t{%6, %4, %2|%2, %4, %6}",
};

static const char * const output_1640[] = {
  "%vpcmpistrm\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistrm\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistri\t{%4, %3, %2|%2, %3, %4}",
  "%vpcmpistri\t{%4, %3, %2|%2, %3, %4}",
};

static const char *
output_1690 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11228 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((16 * 8) - INTVAL (operands[2]));
  return "vprotb\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1691 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11228 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((8 * 8) - INTVAL (operands[2]));
  return "vprotw\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1692 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11228 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((4 * 8) - INTVAL (operands[2]));
  return "vprotd\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1693 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11228 "../../gcc/config/i386/sse.md"
{
  operands[3] = GEN_INT ((2 * 8) - INTVAL (operands[2]));
  return "vprotq\t{%3, %1, %0|%0, %1, %3}";
}
}

static const char *
output_1724 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11544 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrueb\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalseb\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1725 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11544 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtruew\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalsew\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1726 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11544 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrued\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalsed\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char *
output_1727 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11544 "../../gcc/config/i386/sse.md"
{
  return ((INTVAL (operands[3]) != 0)
	  ? "vpcomtrueq\t{%2, %1, %0|%0, %1, %2}"
	  : "vpcomfalseq\t{%2, %1, %0|%0, %1, %2}");
}
}

static const char * const output_1746[] = {
  "vbroadcastss\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1747[] = {
  "vbroadcastss\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1748[] = {
  "vbroadcastsd\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1749[] = {
  "vbroadcastsd\t{%1, %0|%0, %1}",
  "#",
};

static const char * const output_1750[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1751[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1752[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1753[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1754[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char * const output_1755[] = {
  "vbroadcastf128\t{%1, %0|%0, %1}",
  "vinsertf128\t{$1, %1, %0, %0|%0, %0, %1, 1}",
  "vperm2f128\t{$0, %t1, %t1, %0|%0, %t1, %t1, 0}",
};

static const char *
output_1756 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11820 "../../gcc/config/i386/sse.md"
{
  int elt = INTVAL (operands[3]);
  switch (which_alternative)
    {
    case 0:
    case 1:
      operands[1] = adjust_address_nv (operands[1], SFmode, elt * 4);
      return "vbroadcastss\t{%1, %0|%0, %1}";
    case 2:
      operands[2] = GEN_INT (elt * 0x55);
      return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1759 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11932 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V4SFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1760 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11932 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V2DFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilpd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1761 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11932 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V8SFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilps\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1762 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 11932 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vpermilp_parallel (operands[2], V4DFmode) - 1;
  operands[2] = GEN_INT (mask);
  return "vpermilpd\t{%2, %1, %0|%0, %1, %2}";
}
}

static const char *
output_1770 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12017 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V8SImode) - 1;
  operands[3] = GEN_INT (mask);
  return "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1771 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12017 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V8SFmode) - 1;
  operands[3] = GEN_INT (mask);
  return "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1772 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12017 "../../gcc/config/i386/sse.md"
{
  int mask = avx_vperm2f128_parallel (operands[3], V4DFmode) - 1;
  operands[3] = GEN_INT (mask);
  return "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}";
}
}

static const char *
output_1793 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	case MODE_OI:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1794 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	case MODE_OI:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1795 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12227 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	case MODE_OI:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1796 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12263 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%x1, %0|%0, %x1}";
	case MODE_V4DF:
	  return "vmovapd\t{%x1, %0|%0, %x1}";
	case MODE_OI:
	  return "vmovdqa\t{%x1, %0|%0, %x1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1797 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12263 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%x1, %0|%0, %x1}";
	case MODE_V4DF:
	  return "vmovapd\t{%x1, %0|%0, %x1}";
	case MODE_OI:
	  return "vmovdqa\t{%x1, %0|%0, %x1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1798 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12263 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%x1, %0|%0, %x1}";
	case MODE_V4DF:
	  return "vmovapd\t{%x1, %0|%0, %x1}";
	case MODE_OI:
	  return "vmovdqa\t{%x1, %0|%0, %x1}";
	default:
	  break;
	}
    default:
      break;
    }
  gcc_unreachable ();
}
}

static const char *
output_1799 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1800 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1801 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1802 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1803 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1804 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 12308 "../../gcc/config/i386/sse.md"
{
  switch (which_alternative)
    {
    case 0:
      return "vinsertf128\t{$0x1, %2, %t1, %0|%0, %t1, %2, 0x1}";
    case 1:
      switch (get_attr_mode (insn))
        {
	case MODE_V8SF:
	  return "vmovaps\t{%1, %x0|%x0, %1}";
	case MODE_V4DF:
	  return "vmovapd\t{%1, %x0|%x0, %1}";
	default:
	  return "vmovdqa\t{%1, %x0|%x0, %1}";
	}
    default:
      gcc_unreachable ();
    }
}
}

static const char *
output_1817 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 196 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{b}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{b}\t%0";
    }

  return "lock{%;} add{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_1818 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 196 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{w}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{w}\t%0";
    }

  return "lock{%;} add{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_1819 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 196 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} inc{l}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} dec{l}\t%0";
    }

  return "lock{%;} add{l}\t{%1, %0|%0, %1}";
}
}

static const char *
output_1820 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 216 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{b}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{b}\t%0";
    }

  return "lock{%;} sub{b}\t{%1, %0|%0, %1}";
}
}

static const char *
output_1821 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 216 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{w}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{w}\t%0";
    }

  return "lock{%;} sub{w}\t{%1, %0|%0, %1}";
}
}

static const char *
output_1822 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 216 "../../gcc/config/i386/sync.md"
{
  if (TARGET_USE_INCDEC)
    {
      if (operands[1] == const1_rtx)
	return "lock{%;} dec{l}\t%0";
      if (operands[1] == constm1_rtx)
	return "lock{%;} inc{l}\t%0";
    }

  return "lock{%;} sub{l}\t{%1, %0|%0, %1}";
}
}



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
    "r,?mr",
    DImode,
    0,
    1
  },
  {
    const0_operand,
    "",
    DImode,
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
    nonimmediate_operand,
    "rm,r",
    DImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "re,rm",
    DImode,
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
    register_operand,
    "=a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
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
    "=a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
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
    "f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    SFmode,
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
    "f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    DFmode,
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
    "f",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
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
    "f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    0
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
    "f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f,x",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "f,xm",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
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
    nonimmediate_operand,
    "=r,m,*y,*y,?rm,?*y,*x,*x,?r,m,?*Yi,*x",
    SImode,
    0,
    1
  },
  {
    general_operand,
    "g,ri,C,*y,*y,rm,C,*x,*Yi,*x,r,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
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
    "+rm,r",
    HImode,
    1,
    1
  },
  {
    general_operand,
    "rn,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
    HImode,
    1,
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
    push_operand,
    "=X",
    QImode,
    0,
    1
  },
  {
    nonmemory_no_elim_operand,
    "rn",
    QImode,
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
    register_operand,
    "+r",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "+r",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "+q",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "+q",
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
    register_operand,
    "=R",
    HImode,
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
    nonimmediate_operand,
    "=r,o,*y,m*y,*y,*Y2,m,*Y2,*Y2,*x,m,*x,*x",
    DImode,
    0,
    1
  },
  {
    general_operand,
    "riFo,riF,C,*y,m,C,*Y2,*Y2,m,C,*x,*x,m",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    OImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,xm,x",
    OImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    TImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,xm,x",
    TImode,
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
    push_operand,
    "=<,<,<",
    DFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "f,rFo,Y2",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,*r,o,Y2*x,Y2*x,Y2*x,m",
    DFmode,
    0,
    1
  },
  {
    general_operand,
    "fm,f,G,*roF,*Fr,C,Y2*x,mY2*x,Y2*x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,r,o,Y2*x,Y2*x,Y2*x,m",
    DFmode,
    0,
    1
  },
  {
    general_operand,
    "fm,f,G,roF,Fr,C,Y2*x,m,Y2*x",
    DFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "+f",
    DFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "+f",
    DFmode,
    0,
    1
  },
  {
    push_operand,
    "=X,X,X",
    XFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "f,Fo,*r",
    XFmode,
    0,
    1
  },
  {
    push_operand,
    "=<,<",
    XFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "f,ro",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,*r,o",
    XFmode,
    0,
    1
  },
  {
    general_operand,
    "fm,f,G,*roF,F*r",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m,f,r,o",
    XFmode,
    0,
    1
  },
  {
    general_operand,
    "fm,f,G,roF,Fr",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,x,?r,?o",
    TFmode,
    0,
    1
  },
  {
    general_operand,
    "xm,x,C,roF,Fr",
    TFmode,
    0,
    1
  },
  {
    push_operand,
    "=<,<,<",
    TFmode,
    0,
    1
  },
  {
    general_no_elim_operand,
    "x,Fo,*r",
    TFmode,
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
    "=f,m,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,f,xm",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,m",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=fm,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "f,xm",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=fm",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,Y2,?f,?x,?*r",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "f,Y2m,f,f,f",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,X,m,m,m",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?f,?x,?*r",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "f,f,f,f",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,m",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?f,?x,?*r",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f,f,f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,m",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?f,?Y2,?*r",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f,f,f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,m",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=&x,&x",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x,&x",
    V4SFmode,
    0,
    0
  },
  {
    scratch_operand,
    "=x,x",
    V4SFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=&x,&x",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x,&x",
    V2DFmode,
    0,
    0
  },
  {
    scratch_operand,
    "=x,x",
    V2DFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "xm,xm",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x",
    V2DFmode,
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
    "x,m",
    SFmode,
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
    "x,m",
    DFmode,
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
    register_operand,
    "",
    VOIDmode,
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
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    DFmode,
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
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    SFmode,
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
    register_operand,
    "",
    DFmode,
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
    XFmode,
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
    XFmode,
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
    "=f,f,x,x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r,r,m,!x",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f,x,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r,r,m,!x",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,x",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,x",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r,r,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m,m,X",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,r,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,r,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m,!x",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m,!x",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,X",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,X",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,x",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=X,x",
    SImode,
    0,
    0
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
    "=r,o",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    TImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "roe,re",
    TImode,
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
    "=rm,r",
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
    x86_64_general_operand,
    "re,rm",
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
    "=r,rm,r,r",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0,r,r",
    DImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "rme,re,0,le",
    DImode,
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
    x86_64_general_operand,
    "rme,re",
    DImode,
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
    DImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    DImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "rme",
    DImode,
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
    "=r,o",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0",
    TImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "roe,re",
    TImode,
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
    "=rm,r",
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
    x86_64_general_operand,
    "re,rm",
    DImode,
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
    nonimmediate_operand,
    "=rm,r",
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
    x86_64_general_operand,
    "re,rm",
    DImode,
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
    x86_64_general_operand,
    "re,rm",
    DImode,
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
    scratch_operand,
    "=r",
    DImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "%0",
    DImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "rem",
    DImode,
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
    "=ro",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    TImode,
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
    "=rm",
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
    register_operand,
    "=x,x,f,!r",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,x,0,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,X,X",
    V4SFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x,x,f,!r",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,x,0,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,0,X,X",
    V2DFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x,x,!r",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,x,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "xm,0,X",
    V4SFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x,x,!r",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,x,0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "xm,0,X",
    V2DFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
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
    absneg_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
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
    absneg_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,!r",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
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
    absneg_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "0,x",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,0",
    TFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    TFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xmC",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xmC",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    TFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xmC",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    V4SFmode,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "1,1,x,1,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    V2DFmode,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "1,1,x,1,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,x,x",
    TFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=x,x,x,x,x",
    TFmode,
    0,
    0
  },
  {
    register_operand,
    "x,0,0,x,x",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "1,1,x,1,x",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "X,xm,xm,0,0",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm,1,xm,1",
    TFmode,
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
    register_operand,
    "=&r,r",
    DImode,
    0,
    1
  },
  {
    reg_or_pm1_operand,
    "n,0",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "Jc,Jc",
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
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm",
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
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "f",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "f",
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
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "f",
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
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
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
    scratch_operand,
    "=a,a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
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
    scratch_operand,
    "=a,a",
    HImode,
    0,
    0
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
    "=r",
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
    "=&q",
    SImode,
    0,
    0
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
    "rm",
    HImode,
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
    nonimmediate_operand,
    "rm",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m,r",
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
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+Q,r",
    HImode,
    1,
    1
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=Q",
    HImode,
    0,
    0
  },
  {
    register_operand,
    "0",
    DImode,
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
    scratch_operand,
    "=&Q",
    HImode,
    0,
    0
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=Q",
    HImode,
    0,
    0
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
    "=a",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    1
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0
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
    "b",
    SImode,
    0,
    1
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0
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
    "b",
    SImode,
    0,
    1
  },
  {
    call_insn_operand,
    "",
    SImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=d",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=c",
    SImode,
    0,
    0
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
    "b",
    SImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
    "",
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
    tls_symbolic_operand,
    "",
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
    "b",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=&a",
    SImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    1
  },
  {
    tls_modbase_operand,
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
    register_operand,
    "=f,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0,xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,fm",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "%0",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    HImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?r",
    SImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    SFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "fm,0",
    DFmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "1",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    1
  },
  {
    const_double_operand,
    "F",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    const_double_operand,
    "F",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=u",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    const_double_operand,
    "F",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "u",
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "u",
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "u",
    XFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=2",
    XFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
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
    register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
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
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
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
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
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
    "=f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
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
    XFmode,
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
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f",
    XFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=m,?r",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&1f,&1f",
    XFmode,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,?r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    XFmode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m,m",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "=X,m",
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
    memory_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    DFmode,
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
    "=c",
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
    register_operand,
    "2",
    SImode,
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
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    SImode,
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
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    HImode,
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
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    QImode,
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
    "=c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
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
    register_operand,
    "=D",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    QImode,
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
    register_operand,
    "=S",
    SImode,
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
    "=c",
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
    register_operand,
    "2",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=&c",
    SImode,
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
    "a",
    QImode,
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
    register_operand,
    "=r",
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
    register_operand,
    "=r,r",
    HImode,
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
    "rm,0",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    HImode,
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
    ix86_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "rm,0",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=r,r",
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
    register_operand,
    "r,0",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "0,r",
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
    register_operand,
    "=f,f,r,r",
    SFmode,
    0,
    1
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "f,0,rm,0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,f,0,rm",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f,f,&r,&r",
    DFmode,
    0,
    1
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "f,0,rm,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,f,0,rm",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    XFmode,
    0,
    1
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "f,0",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    XFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
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
    address_operand,
    "p",
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
    address_operand,
    "p",
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
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
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
    memory_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
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
    flags_reg_operand,
    "",
    CCZmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
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
    flags_reg_operand,
    "",
    CCZmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
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
    register_operand,
    "=r",
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
    "qm",
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
    register_operand,
    "0",
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
    "=r",
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
    "=A",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "c",
    SImode,
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
    register_operand,
    "=c",
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
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,r,m",
    V8QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,irm,r",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,r,m",
    V4HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,irm,r",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,r,m",
    V2SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,irm,r",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,r,m",
    V1DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,irm,r",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,*x,*x,*x,m,r,m",
    V8QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,C,*x,m,*x,irm,r",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,*x,*x,*x,m,r,m",
    V4HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,C,*x,m,*x,irm,r",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,*x,*x,*x,m,r,m",
    V2SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,C,*x,m,*x,irm,r",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*Y2,*Y2,m,*x,*x,*x,m,r,m",
    V1DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!ym,!?y,*Y2,!y,C,*Y2m,*Y2,C,*x,m,*x,irm,r",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=!?y,!?y,m,!y,*Y2,*x,*x,*x,m,r,m",
    V2SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,!?ym,!?y,*Y2,!y,C,*x,m,*x,irm,r",
    V2SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "y",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y,y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,ym",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym,0",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y,y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "ym,C",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,y,m,f,r",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,ym,y,m,m",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=y,x,y,x,f,r",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,o,o,o,o",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V1DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "yN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4HImode,
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
    const_pow2_1_to_8_operand,
    "n",
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
    register_operand,
    "y",
    V4HImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V4HImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
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
    "=y",
    V2SImode,
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
    "=y,y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm",
    SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "ym,C",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,y,m,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,ym,y,m",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=y,Y2,Y2,x,y,x,r",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,Y2,0,o,o,o",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
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
    "y",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "D",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "y",
    V8QImode,
    0,
    1
  },
  {
    emms_operation,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V1TImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V1TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_or_sse_const_operand,
    "C,xm,x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=?x,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&x,X",
    V4SImode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
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
    "=x",
    V32QImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    V4SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    V2DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    V8SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    avx_comparison_float_operator,
    "",
    V4DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    V2DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    V4SFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    sse_comparison_operator,
    "",
    V2DFmode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
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
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
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
    "x,m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "y,m",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
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
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
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
    "x,m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const0_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,o,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,o,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_8_to_11_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_12_to_15_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,0,0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m,x",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,*y,*y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m,x,m",
    SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,m,C,*ym,C",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,*y,*y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,m,0,m",
    SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,m,C,*ym,C",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m,0,m",
    SFmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,C,x,x,0",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "x,m,*r,x,*rm,x*rfF",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,C,x,x,0",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "x,m,*r,x,*rm,x*rfF",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,C,0,0,0",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "x,m,*r,x,*rm,*rfF",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,C,0,0,0",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "x,m,*r,x,*rm,*rfF",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,0,0",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "m,*r,x,x*rfF",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,m",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,0,0",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "m,*r,x,x*rfF",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,0,0",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "m,x,x*rfF",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,0,0",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "m,x,x*rfF",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    const_pow2_1_to_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    SFmode,
    0,
    1
  },
  {
    const_pow2_1_to_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m,f,r",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x,m,m",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=rm",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x*rf",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "o",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,o,o,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,1,x,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,o,o,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,1,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,o,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,0,0",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "1,xm",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,1,m,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,1,m,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_5_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_6_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_2_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o,o,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,0,o,o,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m,m,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,o,o,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,o,o,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,x,0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,x,0,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,m,m,m",
    V2DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,x,x,o,0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,m,x,x,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,x,x,x,m,m,m",
    V2DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,0,0,x,o,0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,m,x,0,0,x,*f,r",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,0,o,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x,x,0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=x,x,m,x,x,o",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,0,x,o,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x,0,0,0",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,m",
    DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,m,C",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,Y2,Y2,x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,m,0,0",
    DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "Y2,m,C,x,m",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V1TImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V1TImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V1TImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V1TImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "xN",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    QImode,
    0,
    1
  },
  {
    const_pow2_1_to_32768_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
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
    const_pow2_1_to_128_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
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
    const_pow2_1_to_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "rm",
    QImode,
    0,
    1
  },
  {
    const_pow2_1_to_32768_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8HImode,
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
    const_pow2_1_to_128_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SImode,
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
    const_pow2_1_to_8_operand,
    "n",
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
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
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
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_7_operand,
    "n",
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
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_4_to_7_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x,Yi,x",
    V4SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "C,C,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,r,x",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,Yi,x,x",
    V4SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "C,C,C,0",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,r,m,x",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=mx,r",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "x,Yi",
    V4SImode,
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
    memory_operand,
    "o",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=mx",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,o",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=m,x,x",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,0,o",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "Y2,0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,*y,*y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,x,rm,0,rm",
    SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "rm,x,C,*ym,C",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x,*y,*y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,0,rm,0,rm",
    SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "rm,x,C,*ym,C",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,rm,0,rm",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,*y,*y",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m,0,*rm",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "x,C,*y,C",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,x,x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "0,0,0",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "Y2,x,m",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,?x,x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,*y,x,x",
    DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,x,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=Y2,?Y2,Y2,x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "mY2,*y,0,0,0",
    DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "C,C,Y2,x,m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
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
    "x",
    V8SFmode,
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
    "x",
    V4DFmode,
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
    "x",
    V4SFmode,
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
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "D",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    address_operand,
    "p",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "a",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    TImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    TImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    TImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    TImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
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
    nonimmediate_operand,
    "ym",
    DImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=y",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "ym",
    V8QImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
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
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
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
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "Yz",
    V4SFmode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "Yz",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%0",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "0",
    V16QImode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "Yz",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "a,a",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=Yz,Yz,X,X",
    V16QImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,c,c",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "x,x,x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "a,a,a,a",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d,d,d",
    SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n,n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c,c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=Yz,Yz",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=Yz,Yz,X,X",
    V16QImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,c,c",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "x,x,x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m,x,m",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n,n,n,n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=&x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "%x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V8HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V2DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V2DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V32QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V16HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V8SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V4DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V8SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "x,x",
    V4DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_7_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_15_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_31_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_63_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm,x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "x,m",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    ix86_comparison_int_operator,
    "",
    V16QImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    ix86_comparison_int_operator,
    "",
    V8HImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    ix86_comparison_int_operator,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    ix86_comparison_int_operator,
    "",
    V2DImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    ix86_comparison_uns_operator,
    "",
    V16QImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    ix86_comparison_uns_operator,
    "",
    V8HImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    ix86_comparison_uns_operator,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    ix86_comparison_uns_operator,
    "",
    V2DImode,
    0,
    0
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
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
    register_operand,
    "=x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
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
    register_operand,
    "=x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
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
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
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
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "%x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    vzeroall_operation,
    "",
    VOIDmode,
    0,
    0
  },
  {
    vzeroupper_operation,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?x",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?x",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?x",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,?x",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,0,?x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,o,x",
    V4SFmode,
    0,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,o,?x",
    V8SFmode,
    0,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "m,o,?x",
    V4DFmode,
    0,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    0
  },
  {
    const_int_operand,
    "C,n,n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    avx_vpermilp_v4sf_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    avx_vpermilp_v2df_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    avx_vpermilp_v8sf_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    avx_vpermilp_v4df_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "n",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SImode,
    0,
    1
  },
  {
    avx_vperm2f128_v8si_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8SFmode,
    0,
    1
  },
  {
    avx_vperm2f128_v8sf_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4DFmode,
    0,
    1
  },
  {
    avx_vperm2f128_v4df_operand,
    "",
    VOIDmode,
    0,
    0
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
    "=x",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "xm",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V2DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V8SFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    V4DFmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V2DFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V8SFmode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,xm",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V16QImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V8HImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V4SImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V2DImode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V4SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "=x,x",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "x,x",
    V2DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "xm,C",
    V2DFmode,
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
    memory_operand,
    "+m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "q",
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
    memory_operand,
    "+m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "a",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "r",
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
    memory_operand,
    "+m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a",
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
    "=A",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "A",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "b",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "c",
    SImode,
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
    cmpxchg8b_pic_memory_operand,
    "+m",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "A",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "SD",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=q",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
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
    memory_operand,
    "+m",
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
    register_operand,
    "=r",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
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
    memory_operand,
    "+m",
    QImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "qn",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    HImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "rn",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "ri",
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
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    x86_64_general_operand,
    "",
    DImode,
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
    register_operand,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    SFmode,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    cmp_fp_expander_operand,
    "",
    DFmode,
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
    register_operand,
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
    const0_operand,
    "",
    VOIDmode,
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
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
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
    DFmode,
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
    register_operand,
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
    register_operand,
    "",
    VOIDmode,
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
    VOIDmode,
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
    float_operator,
    "",
    VOIDmode,
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
    VOIDmode,
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
    float_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    1,
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
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    general_operand,
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
    push_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    any_fp_register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    push_operand,
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
    push_operand,
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
    push_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    any_fp_register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    push_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    push_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    any_fp_register_operand,
    "",
    TFmode,
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
    general_operand,
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
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    DFmode,
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
    immediate_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    TFmode,
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
    push_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    push_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    push_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
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
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
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
    SFmode,
    0,
    1
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
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
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
    register_operand,
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
    0,
    "",
    SFmode,
    0,
    1
  },
  {
    0,
    "",
    DFmode,
    0,
    1
  },
  {
    0,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    DFmode,
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
    SFmode,
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
    nonimmediate_operand,
    "",
    DFmode,
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
    SFmode,
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
    memory_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    DFmode,
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
    register_operand,
    "",
    XFmode,
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
    memory_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    DFmode,
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
    register_operand,
    "",
    SFmode,
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
    register_operand,
    "",
    DFmode,
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
    SFmode,
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
    DFmode,
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
    SFmode,
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
    SFmode,
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
    scratch_operand,
    "",
    V4SFmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
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
    DFmode,
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
    scratch_operand,
    "",
    V2DFmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
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
    scratch_operand,
    "",
    V4SFmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
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
    V2DFmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
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
    SFmode,
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
    DFmode,
    0,
    1
  },
  {
    register_operand,
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
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
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
    register_operand,
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
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "Y2",
    DFmode,
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
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "Y2",
    DFmode,
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
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "x",
    SFmode,
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
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "x",
    SFmode,
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
    VOIDmode,
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
    VOIDmode,
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
    "",
    VOIDmode,
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
    VOIDmode,
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
    "",
    VOIDmode,
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
    register_operand,
    "",
    VOIDmode,
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
    register_operand,
    "",
    VOIDmode,
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
    "",
    VOIDmode,
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
    VOIDmode,
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
    "",
    VOIDmode,
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
    VOIDmode,
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
    memory_operand,
    "",
    HImode,
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
    "",
    VOIDmode,
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
    VOIDmode,
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
    memory_operand,
    "",
    HImode,
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
    "",
    VOIDmode,
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
    VOIDmode,
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
    memory_operand,
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
    register_operand,
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
    memory_operand,
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
    memory_operand,
    "",
    SImode,
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
    register_operand,
    "",
    VOIDmode,
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
    memory_operand,
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
    memory_operand,
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
    memory_operand,
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
    memory_operand,
    "",
    SImode,
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
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    HImode,
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
    memory_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    HImode,
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
    memory_operand,
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
    register_operand,
    "",
    DFmode,
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
    register_operand,
    "",
    XFmode,
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
    register_operand,
    "",
    SFmode,
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
    register_operand,
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
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    register_operand,
    "",
    DFmode,
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
    register_operand,
    "",
    XFmode,
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
    register_operand,
    "",
    XFmode,
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
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    DImode,
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
    memory_operand,
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
    register_operand,
    "",
    XFmode,
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
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
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
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
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
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
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
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
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
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
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
    memory_operand,
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
    "",
    V4SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
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
    DImode,
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
    memory_operand,
    "",
    DImode,
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
    XFmode,
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
    DImode,
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
    SFmode,
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
    memory_operand,
    "",
    DImode,
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
    DFmode,
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
    memory_operand,
    "",
    DImode,
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
    XFmode,
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
    memory_operand,
    "",
    DImode,
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
    SFmode,
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
    0,
    "",
    VOIDmode,
    0,
    0
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
    DFmode,
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
    0,
    "",
    VOIDmode,
    0,
    0
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
    XFmode,
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
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    scratch_operand,
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
    x86_64_general_operand,
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
    x86_64_general_operand,
    "",
    DImode,
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
    DImode,
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
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    absneg_operator,
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
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    SFmode,
    0,
    0
  },
  {
    0,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    DFmode,
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
    register_operand,
    "",
    XFmode,
    0,
    1
  },
  {
    absneg_operator,
    "",
    XFmode,
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
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    vector_move_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    V4SFmode,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    0,
    "",
    V4SFmode,
    0,
    1
  },
  {
    0,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    V2DFmode,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    0,
    "",
    V2DFmode,
    0,
    1
  },
  {
    0,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    TFmode,
    0,
    0
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    0,
    "",
    TFmode,
    0,
    1
  },
  {
    0,
    "",
    TFmode,
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
    nonimmediate_operand,
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
    nonimmediate_operand,
    "",
    DImode,
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
    ix86_fp_comparison_operator,
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
    0,
    "",
    VOIDmode,
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
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
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
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
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
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
    "",
    VOIDmode,
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
    scratch_operand,
    "=a",
    HImode,
    0,
    0
  },
  {
    ix86_swapped_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    float_operator,
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
    scratch_operand,
    "=a",
    HImode,
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
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    HImode,
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
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    HImode,
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
    tls_symbolic_operand,
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
    VOIDmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
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
    DImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
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
    0,
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
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
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
    call_insn_operand,
    "",
    SImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
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
    tls_symbolic_operand,
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
    tls_modbase_operand,
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
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    tls_symbolic_operand,
    "",
    DImode,
    0,
    1
  },
  {
    tls_modbase_operand,
    "",
    DImode,
    0,
    1
  },
  {
    0,
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
    register_operand,
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
    binary_fp_operator,
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
    binary_fp_operator,
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
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    binary_fp_operator,
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
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
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
    general_operand,
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
    SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
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
    general_operand,
    "",
    DFmode,
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
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    XFmode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    XFmode,
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
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    XFmode,
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
    0,
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
    0
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
    VOIDmode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    XFmode,
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
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    SFmode,
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
    DImode,
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
    memory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
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
    XFmode,
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
    "",
    VOIDmode,
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
    XFmode,
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
    register_operand,
    "",
    SImode,
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
    memory_operand,
    "",
    SImode,
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
    memory_operand,
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
    XFmode,
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
    memory_operand,
    "",
    HImode,
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
    "",
    VOIDmode,
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
    XFmode,
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
    memory_operand,
    "",
    HImode,
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
    "",
    VOIDmode,
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
    XFmode,
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
    memory_operand,
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
    register_operand,
    "",
    SImode,
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
    memory_operand,
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
    memory_operand,
    "",
    SImode,
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
    register_operand,
    "",
    XFmode,
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
    memory_operand,
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
    memory_operand,
    "",
    SImode,
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
    memory_operand,
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
    memory_operand,
    "",
    SImode,
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
    nonmemory_operand,
    "",
    SImode,
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
    0,
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
    general_operand,
    "",
    BLKmode,
    0,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
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
    register_operand,
    "",
    VOIDmode,
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
    memory_operand,
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
    SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
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
    immediate_operand,
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
    general_operand,
    "",
    BLKmode,
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
    register_operand,
    "",
    VOIDmode,
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
    register_operand,
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
    general_operand,
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
    comparison_operator,
    "",
    VOIDmode,
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
    comparison_operator,
    "",
    VOIDmode,
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
    general_operand,
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
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    ix86_fp_comparison_operator,
    "",
    VOIDmode,
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
    register_and_not_any_fp_reg_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    fcmov_comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
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
    flags_reg_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    fp_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    binary_fp_operator,
    "",
    VOIDmode,
    0,
    0
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
    QImode,
    0,
    1
  },
  {
    comparison_operator,
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
    const_int_operand,
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
    comparison_operator,
    "",
    VOIDmode,
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
    const_int_operand,
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
    comparison_operator,
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
    x86_64_general_operand,
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
    x86_64_general_operand,
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
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    address_operand,
    "",
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
    memory_operand,
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
    nonimmediate_operand,
    "rm",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "i",
    SImode,
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
    register_operand,
    "r",
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
    const_int_operand,
    "i",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
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
    V2SFmode,
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
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V1DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
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
    const_0_to_3_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4HImode,
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
    V2SImode,
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
    nonimmediate_operand,
    "",
    V2SImode,
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
    V2SImode,
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
    V2SImode,
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
    V2SImode,
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
    V4HImode,
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
    const_int_operand,
    "",
    VOIDmode,
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
    V4HImode,
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
    V4HImode,
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
    V8QImode,
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
    const_int_operand,
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
    register_operand,
    "",
    V8QImode,
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
    V8QImode,
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
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V1TImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
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
    scratch_operand,
    "",
    V4SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    zero_extended_scalar_load_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    zero_extended_scalar_load_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V1TImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
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
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
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
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    V4SFmode,
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
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2DFmode,
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
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
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
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
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
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
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
    V8HImode,
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
    V4SImode,
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
    V2DImode,
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
    V4SFmode,
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
    V2DFmode,
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
    V4SFmode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
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
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
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
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
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
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
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
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
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
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
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
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_3_operand,
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
    register_operand,
    "",
    V16QImode,
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
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
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
    register_operand,
    "",
    V4SImode,
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
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
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
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
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
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
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
    V2DFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
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
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
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
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
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
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
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
    memory_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_255_mul_8_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V16QImode,
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
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V8HImode,
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
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V4SImode,
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
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    general_operand,
    "",
    V2DImode,
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
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
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
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
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
    V4SImode,
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
    V4SImode,
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
    V4SImode,
    0,
    1
  },
  {
    const_0_to_3_operand,
    "",
    VOIDmode,
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
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
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
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "",
    V16QImode,
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
    nonimm_not_xmm0_operand,
    "",
    V16QImode,
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
    const_0_to_255_operand,
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
    V16QImode,
    0,
    1
  },
  {
    reg_not_xmm0_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimm_not_xmm0_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
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
    V8HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
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
    V4SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
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
    V2DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
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
    V16QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16QImode,
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
    V2DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2DImode,
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
    V8SImode,
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
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
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
    register_operand,
    "",
    V4DFmode,
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
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    0
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
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    avx_vbroadcast_operand,
    "",
    VOIDmode,
    0,
    0
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
    V2DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    const_0_to_255_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V16QImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V16HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V8HImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DImode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V8SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V4SFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V4DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    V2DFmode,
    0,
    1
  },
  {
    const_0_to_1_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    V32QImode,
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
    V16HImode,
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
    V8SImode,
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
    V4DImode,
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
    V8SFmode,
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
    V4DFmode,
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
    memory_operand,
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
    memory_operand,
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
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data insn_data[] = 
{
  /* ../../gcc/config/i386/i386.md:904 */
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
  /* ../../gcc/config/i386/i386.md:904 */
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
  /* ../../gcc/config/i386/i386.md:904 */
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
  /* ../../gcc/config/i386/i386.md:904 */
  {
    "*cmpdi_ccno_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_3 },
#else
    { 0, output_3, 0 },
#endif
    0,
    &operand_data[7],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:916 */
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
    &operand_data[9],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:916 */
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
    &operand_data[11],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:916 */
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
    &operand_data[13],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:916 */
  {
    "*cmpdi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[15],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:925 */
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
    &operand_data[9],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:925 */
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
    &operand_data[11],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:925 */
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
    &operand_data[13],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:925 */
  {
    "*cmpdi_minus_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp{q}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[15],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:936 */
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
    &operand_data[17],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:964 */
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
    &operand_data[18],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:991 */
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
    &operand_data[20],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1021 */
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
    &operand_data[22],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1150 */
  {
    "*cmpfp_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_16 },
#else
    { 0, 0, output_16 },
#endif
    0,
    &operand_data[24],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1170 */
  {
    "*cmpfp_0_cc",
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
    &operand_data[24],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1198 */
  {
    "*cmpfp_xf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_18 },
#else
    { 0, 0, output_18 },
#endif
    0,
    &operand_data[27],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1211 */
  {
    "*cmpfp_xf_cc",
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
    &operand_data[27],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1232 */
  {
    "*cmpfp_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_20 },
#else
    { 0, 0, output_20 },
#endif
    0,
    &operand_data[30],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1232 */
  {
    "*cmpfp_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_21 },
#else
    { 0, 0, output_21 },
#endif
    0,
    &operand_data[33],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1245 */
  {
    "*cmpfp_sf_cc",
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
    &operand_data[30],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1245 */
  {
    "*cmpfp_df_cc",
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
    &operand_data[33],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1266 */
  {
    "*cmpfp_u",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_24 },
#else
    { 0, 0, output_24 },
#endif
    0,
    &operand_data[36],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1286 */
  {
    "*cmpfp_u_cc",
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
    &operand_data[36],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1314 */
  {
    "*cmpfp_hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_26 },
#else
    { 0, 0, output_26 },
#endif
    0,
    &operand_data[39],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1314 */
  {
    "*cmpfp_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_27 },
#else
    { 0, 0, output_27 },
#endif
    0,
    &operand_data[43],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1331 */
  {
    "*cmpfp_hi_cc",
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
    &operand_data[39],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1331 */
  {
    "*cmpfp_si_cc",
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
    &operand_data[43],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1361 */
  {
    "x86_fnstsw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnstsw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fnstsw_1,
    &operand_data[24],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1373 */
  {
    "x86_sahf_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_31 },
#else
    { 0, 0, output_31 },
#endif
    (insn_gen_fn) gen_x86_sahf_1,
    &operand_data[47],
    1,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1393 */
  {
    "*cmpfp_i_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_32 },
#else
    { 0, 0, output_32 },
#endif
    0,
    &operand_data[48],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1421 */
  {
    "*cmpfp_i_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_33 },
#else
    { 0, 0, output_33 },
#endif
    0,
    &operand_data[50],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1443 */
  {
    "*cmpfp_i_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_34 },
#else
    { 0, 0, output_34 },
#endif
    0,
    &operand_data[37],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1463 */
  {
    "*cmpfp_iu_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_35 },
#else
    { 0, 0, output_35 },
#endif
    0,
    &operand_data[48],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:1491 */
  {
    "*cmpfp_iu_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_36 },
#else
    { 0, 0, output_36 },
#endif
    0,
    &operand_data[50],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1513 */
  {
    "*cmpfp_iu_387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_37 },
#else
    { 0, 0, output_37 },
#endif
    0,
    &operand_data[37],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1552 */
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
    &operand_data[52],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1569 */
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
    &operand_data[52],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1578 */
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
    &operand_data[54],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1589 */
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
    &operand_data[54],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1599 */
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
    &operand_data[55],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1609 */
  {
    "*movsi_or",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_43 },
#else
    { 0, 0, output_43 },
#endif
    0,
    &operand_data[57],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:1623 */
  {
    "*movsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_44 },
#else
    { 0, 0, output_44 },
#endif
    0,
    &operand_data[59],
    2,
    0,
    12,
    3
  },
  /* ../../gcc/config/i386/i386.md:1734 */
  {
    "*swapsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{l}\t%1, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[61],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1753 */
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
    &operand_data[63],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1770 */
  {
    "*movhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_47 },
#else
    { 0, 0, output_47 },
#endif
    0,
    &operand_data[65],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:1852 */
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
    &operand_data[67],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1866 */
  {
    "*swaphi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{w}\t%1, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[67],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1890 */
  {
    "*movstricthi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{w}\t{%1, %0|%0, %1}",
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
  /* ../../gcc/config/i386/i386.md:1899 */
  {
    "*movstricthi_xor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{w}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[71],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1919 */
  {
    "*pushqi2",
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
    &operand_data[73],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:1946 */
  {
    "*movqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_53 },
#else
    { 0, 0, output_53 },
#endif
    0,
    &operand_data[75],
    2,
    0,
    7,
    3
  },
  /* ../../gcc/config/i386/i386.md:2010 */
  {
    "*swapqi_1",
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
    &operand_data[77],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2024 */
  {
    "*swapqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xchg{b}\t%1, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[79],
    2,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2048 */
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
    &operand_data[81],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:2057 */
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
    &operand_data[83],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2067 */
  {
    "*movsi_extv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%h1, %0|%0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[85],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2077 */
  {
    "*movhi_extv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movs{bl|x}\t{%h1, %k0|%k0, %h1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[87],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2087 */
  {
    "*movqi_extv_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_60 },
#else
    { 0, 0, output_60 },
#endif
    0,
    &operand_data[89],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2182 */
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
    &operand_data[85],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2192 */
  {
    "*movqi_extzv_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_62 },
#else
    { 0, 0, output_62 },
#endif
    0,
    &operand_data[91],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:2245 */
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
    &operand_data[93],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2275 */
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
    &operand_data[95],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2292 */
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
    &operand_data[97],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:2409 */
  {
    "*movdi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_66 },
#else
    { 0, output_66, 0 },
#endif
    0,
    &operand_data[99],
    2,
    0,
    13,
    2
  },
  /* ../../gcc/config/i386/i386.md:2632 */
  {
    "*movoi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_67 },
#else
    { 0, 0, output_67 },
#endif
    0,
    &operand_data[101],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2671 */
  {
    "*movti_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_68 },
#else
    { 0, 0, output_68 },
#endif
    0,
    &operand_data[103],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2807 */
  {
    "*pushsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_69 },
#else
    { 0, 0, output_69 },
#endif
    0,
    &operand_data[105],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:2857 */
  {
    "*movsf_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_70 },
#else
    { 0, 0, output_70 },
#endif
    0,
    &operand_data[107],
    2,
    0,
    16,
    3
  },
  /* ../../gcc/config/i386/i386.md:2953 */
  {
    "*swapsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_71 },
#else
    { 0, 0, output_71 },
#endif
    0,
    &operand_data[109],
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:2979 */
  {
    "*pushdf_nointeger",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_72 },
#else
    { 0, 0, output_72 },
#endif
    0,
    &operand_data[111],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:2991 */
  {
    "*pushdf_integer",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_73 },
#else
    { 0, 0, output_73 },
#endif
    0,
    &operand_data[113],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:3023 */
  {
    "*movdf_nointeger",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_74 },
#else
    { 0, 0, output_74 },
#endif
    0,
    &operand_data[115],
    2,
    0,
    9,
    3
  },
  /* ../../gcc/config/i386/i386.md:3316 */
  {
    "*movdf_integer",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_75 },
#else
    { 0, 0, output_75 },
#endif
    0,
    &operand_data[117],
    2,
    0,
    9,
    3
  },
  /* ../../gcc/config/i386/i386.md:3454 */
  {
    "*swapdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_76 },
#else
    { 0, 0, output_76 },
#endif
    0,
    &operand_data[119],
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3482 */
  {
    "*pushxf_nointeger",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_77 },
#else
    { 0, 0, output_77 },
#endif
    0,
    &operand_data[121],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:3494 */
  {
    "*pushxf_integer",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_78 },
#else
    { 0, 0, output_78 },
#endif
    0,
    &operand_data[123],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:3525 */
  {
    "*movxf_nointeger",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_79 },
#else
    { 0, 0, output_79 },
#endif
    0,
    &operand_data[125],
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:3553 */
  {
    "*movxf_integer",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_80 },
#else
    { 0, 0, output_80 },
#endif
    0,
    &operand_data[127],
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:3590 */
  {
    "*movtf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_81 },
#else
    { 0, 0, output_81 },
#endif
    0,
    &operand_data[129],
    2,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:3635 */
  {
    "*pushtf_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_82 },
#else
    { 0, 0, output_82 },
#endif
    0,
    &operand_data[131],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:3742 */
  {
    "swapxf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_83 },
#else
    { 0, 0, output_83 },
#endif
    (insn_gen_fn) gen_swapxf,
    &operand_data[133],
    2,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:3800 */
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
    &operand_data[135],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3819 */
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
    &operand_data[137],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3836 */
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
    &operand_data[139],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3845 */
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
    &operand_data[141],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3855 */
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
    &operand_data[143],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3912 */
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
    &operand_data[145],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3921 */
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
    &operand_data[147],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:3930 */
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
    &operand_data[149],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:3991 */
  {
    "zero_extendsidi2_32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_92 },
#else
    { 0, output_92, 0 },
#endif
    (insn_gen_fn) gen_zero_extendsidi2_32,
    &operand_data[151],
    2,
    0,
    7,
    2
  },
  /* ../../gcc/config/i386/i386.md:4084 */
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
    &operand_data[153],
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:4194 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_94 },
#else
    { 0, 0, output_94 },
#endif
    (insn_gen_fn) gen_extendhisi2,
    &operand_data[156],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4247 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_95 },
#else
    { 0, 0, output_95 },
#endif
    (insn_gen_fn) gen_extendqihi2,
    &operand_data[158],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4273 */
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
    &operand_data[149],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4397 */
  {
    "*extendsfdf2_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_97 },
#else
    { 0, 0, output_97 },
#endif
    0,
    &operand_data[160],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:4420 */
  {
    "*extendsfdf2_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtss2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[162],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4429 */
  {
    "*extendsfdf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_99 },
#else
    { 0, 0, output_99 },
#endif
    0,
    &operand_data[164],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4457 */
  {
    "*extendsfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_100 },
#else
    { 0, 0, output_100 },
#endif
    0,
    &operand_data[166],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4457 */
  {
    "*extenddfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_101 },
#else
    { 0, 0, output_101 },
#endif
    0,
    &operand_data[168],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4547 */
  {
    "*truncdfsf_fast_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_102 },
#else
    { 0, 0, output_102 },
#endif
    0,
    &operand_data[170],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:4569 */
  {
    "*truncdfsf_fast_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsd2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[172],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:4579 */
  {
    "*truncdfsf_fast_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_104 },
#else
    { 0, 0, output_104 },
#endif
    0,
    &operand_data[174],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4588 */
  {
    "*truncdfsf_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_105 },
#else
    { 0, 0, output_105 },
#endif
    0,
    &operand_data[176],
    3,
    0,
    5,
    3
  },
  /* ../../gcc/config/i386/i386.md:4611 */
  {
    "*truncdfsf_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_106 },
#else
    { 0, 0, output_106 },
#endif
    0,
    &operand_data[179],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4631 */
  {
    "*truncdfsf2_i387_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_107 },
#else
    { 0, 0, output_107 },
#endif
    0,
    &operand_data[182],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4680 */
  {
    "*truncxfsf2_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_108 },
#else
    { 0, 0, output_108 },
#endif
    0,
    &operand_data[184],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4694 */
  {
    "*truncxfdf2_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_109 },
#else
    { 0, 0, output_109 },
#endif
    0,
    &operand_data[187],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:4708 */
  {
    "truncxfsf2_i387_noop",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_110 },
#else
    { 0, 0, output_110 },
#endif
    (insn_gen_fn) gen_truncxfsf2_i387_noop,
    &operand_data[190],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4708 */
  {
    "truncxfdf2_i387_noop",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_111 },
#else
    { 0, 0, output_111 },
#endif
    (insn_gen_fn) gen_truncxfdf2_i387_noop,
    &operand_data[192],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4717 */
  {
    "*truncxfsf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_112 },
#else
    { 0, 0, output_112 },
#endif
    0,
    &operand_data[194],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4717 */
  {
    "*truncxfdf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_113 },
#else
    { 0, 0, output_113 },
#endif
    0,
    &operand_data[196],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4861 */
  {
    "*fixuns_truncsf_1",
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
    &operand_data[198],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4861 */
  {
    "*fixuns_truncdf_1",
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
    &operand_data[203],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4904 */
  {
    "fix_truncsfsi_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttss2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfsi_sse,
    &operand_data[208],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4904 */
  {
    "fix_truncdfsi_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttsd2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfsi_sse,
    &operand_data[210],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4946 */
  {
    "fix_trunchi_fisttp_i387_1",
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
    (insn_gen_fn) gen_fix_trunchi_fisttp_i387_1,
    &operand_data[212],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4946 */
  {
    "fix_truncsi_fisttp_i387_1",
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
    (insn_gen_fn) gen_fix_truncsi_fisttp_i387_1,
    &operand_data[214],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4946 */
  {
    "fix_truncdi_fisttp_i387_1",
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
    (insn_gen_fn) gen_fix_truncdi_fisttp_i387_1,
    &operand_data[216],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:4973 */
  {
    "fix_trunchi_i387_fisttp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_121 },
#else
    { 0, 0, output_121 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387_fisttp,
    &operand_data[218],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4973 */
  {
    "fix_truncsi_i387_fisttp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_122 },
#else
    { 0, 0, output_122 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387_fisttp,
    &operand_data[221],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4973 */
  {
    "fix_truncdi_i387_fisttp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_123 },
#else
    { 0, 0, output_123 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387_fisttp,
    &operand_data[224],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:4986 */
  {
    "fix_trunchi_i387_fisttp_with_temp",
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
    (insn_gen_fn) gen_fix_trunchi_i387_fisttp_with_temp,
    &operand_data[227],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4986 */
  {
    "fix_truncsi_i387_fisttp_with_temp",
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
    (insn_gen_fn) gen_fix_truncsi_i387_fisttp_with_temp,
    &operand_data[231],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:4986 */
  {
    "fix_truncdi_i387_fisttp_with_temp",
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
    (insn_gen_fn) gen_fix_truncdi_i387_fisttp_with_temp,
    &operand_data[235],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5026 */
  {
    "*fix_trunchi_i387_1",
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
    &operand_data[212],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5026 */
  {
    "*fix_truncsi_i387_1",
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
    &operand_data[214],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5026 */
  {
    "*fix_truncdi_i387_1",
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
    &operand_data[216],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5059 */
  {
    "fix_truncdi_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_130 },
#else
    { 0, 0, output_130 },
#endif
    (insn_gen_fn) gen_fix_truncdi_i387,
    &operand_data[239],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:5073 */
  {
    "fix_truncdi_i387_with_temp",
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
    (insn_gen_fn) gen_fix_truncdi_i387_with_temp,
    &operand_data[244],
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5117 */
  {
    "fix_trunchi_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_132 },
#else
    { 0, 0, output_132 },
#endif
    (insn_gen_fn) gen_fix_trunchi_i387,
    &operand_data[250],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:5117 */
  {
    "fix_truncsi_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_133 },
#else
    { 0, 0, output_133 },
#endif
    (insn_gen_fn) gen_fix_truncsi_i387,
    &operand_data[254],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:5130 */
  {
    "fix_trunchi_i387_with_temp",
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
    (insn_gen_fn) gen_fix_trunchi_i387_with_temp,
    &operand_data[258],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5130 */
  {
    "fix_truncsi_i387_with_temp",
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
    (insn_gen_fn) gen_fix_truncsi_i387_with_temp,
    &operand_data[263],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5169 */
  {
    "x86_fnstcw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnstcw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fnstcw_1,
    &operand_data[218],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5178 */
  {
    "x86_fldcw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_x86_fldcw_1,
    &operand_data[41],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5203 */
  {
    "*floathisf2_1",
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
    &operand_data[268],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5203 */
  {
    "*floathidf2_1",
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
    &operand_data[270],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5203 */
  {
    "*floathixf2_1",
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
    &operand_data[272],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5217 */
  {
    "*floathisf2_i387_with_temp",
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
    &operand_data[274],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5217 */
  {
    "*floathidf2_i387_with_temp",
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
    &operand_data[277],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5217 */
  {
    "*floathixf2_i387_with_temp",
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
    &operand_data[280],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5230 */
  {
    "*floathisf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[283],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5230 */
  {
    "*floathidf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[285],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5230 */
  {
    "*floathixf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[287],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatsisf2_1",
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
    &operand_data[289],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatdisf2_1",
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
    &operand_data[291],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatsidf2_1",
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
    &operand_data[293],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatdidf2_1",
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
    &operand_data[295],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatsixf2_1",
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
    &operand_data[297],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5294 */
  {
    "*floatdixf2_1",
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
    &operand_data[299],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:5331 */
  {
    "*floatsisf2_vector_mixed_with_temp",
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
    &operand_data[301],
    3,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:5331 */
  {
    "*floatsidf2_vector_mixed_with_temp",
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
    &operand_data[304],
    3,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:5346 */
  {
    "*floatsisf2_vector_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_155 },
#else
    { 0, output_155, 0 },
#endif
    0,
    &operand_data[307],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5346 */
  {
    "*floatsidf2_vector_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_156 },
#else
    { 0, output_156, 0 },
#endif
    0,
    &operand_data[309],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5361 */
  {
    "*floatsisf2_mixed_with_temp",
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
    &operand_data[311],
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:5361 */
  {
    "*floatsidf2_mixed_with_temp",
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
    &operand_data[314],
    3,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*floatsisf2_mixed_interunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_159 },
#else
    { 0, output_159, 0 },
#endif
    0,
    &operand_data[317],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:5405 */
  {
    "*floatsidf2_mixed_interunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_160 },
#else
    { 0, output_160, 0 },
#endif
    0,
    &operand_data[319],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:5430 */
  {
    "*floatsisf2_mixed_nointerunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_161 },
#else
    { 0, output_161, 0 },
#endif
    0,
    &operand_data[307],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5430 */
  {
    "*floatsidf2_mixed_nointerunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_162 },
#else
    { 0, output_162, 0 },
#endif
    0,
    &operand_data[309],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5453 */
  {
    "*floatsisf2_vector_sse_with_temp",
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
    &operand_data[321],
    3,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:5453 */
  {
    "*floatsidf2_vector_sse_with_temp",
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
    &operand_data[324],
    3,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:5467 */
  {
    "*floatsisf2_vector_sse",
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
    &operand_data[327],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5467 */
  {
    "*floatsidf2_vector_sse",
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
    &operand_data[329],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5600 */
  {
    "*floatsisf2_sse_with_temp",
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
    &operand_data[331],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5600 */
  {
    "*floatsidf2_sse_with_temp",
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
    &operand_data[334],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5614 */
  {
    "*floatsisf2_sse_interunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[331],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5614 */
  {
    "*floatsidf2_sse_interunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[334],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5649 */
  {
    "*floatsisf2_sse_nointerunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2ss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[327],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5649 */
  {
    "*floatsidf2_sse_nointerunit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsi2sd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[329],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatsisf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_173 },
#else
    { 0, output_173, 0 },
#endif
    0,
    &operand_data[337],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatdisf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_174 },
#else
    { 0, output_174, 0 },
#endif
    0,
    &operand_data[340],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatsidf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_175 },
#else
    { 0, output_175, 0 },
#endif
    0,
    &operand_data[343],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatdidf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_176 },
#else
    { 0, output_176, 0 },
#endif
    0,
    &operand_data[346],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatsixf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_177 },
#else
    { 0, output_177, 0 },
#endif
    0,
    &operand_data[349],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5698 */
  {
    "*floatdixf2_i387_with_temp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_178 },
#else
    { 0, output_178, 0 },
#endif
    0,
    &operand_data[352],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatsisf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[355],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatdisf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[357],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatsidf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[359],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatdidf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[361],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatsixf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[363],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5713 */
  {
    "*floatdixf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fild%Z1\t%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5750 */
  {
    "floatdisf2_i387_with_xmm",
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
    (insn_gen_fn) gen_floatdisf2_i387_with_xmm,
    &operand_data[367],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5750 */
  {
    "floatdidf2_i387_with_xmm",
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
    (insn_gen_fn) gen_floatdidf2_i387_with_xmm,
    &operand_data[372],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5750 */
  {
    "floatdixf2_i387_with_xmm",
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
    (insn_gen_fn) gen_floatdixf2_i387_with_xmm,
    &operand_data[377],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5812 */
  {
    "*floatunssisf2_1",
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
    &operand_data[382],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5812 */
  {
    "*floatunssidf2_1",
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
    &operand_data[386],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5812 */
  {
    "*floatunssixf2_1",
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
    &operand_data[390],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5912 */
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
    &operand_data[394],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5912 */
  {
    "*addti3_doubleword",
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
    &operand_data[397],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5935 */
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
    &operand_data[400],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5935 */
  {
    "*adddi3_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[403],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5948 */
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
    &operand_data[406],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:5961 */
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
    &operand_data[409],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:5986 */
  {
    "*addsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_197 },
#else
    { 0, 0, output_197 },
#endif
    0,
    &operand_data[411],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:5986 */
  {
    "*adddi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_198 },
#else
    { 0, 0, output_198 },
#endif
    0,
    &operand_data[414],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:6115 */
  {
    "*addhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_199 },
#else
    { 0, 0, output_199 },
#endif
    0,
    &operand_data[417],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6163 */
  {
    "*addhi_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_200 },
#else
    { 0, 0, output_200 },
#endif
    0,
    &operand_data[420],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:6211 */
  {
    "*addqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_201 },
#else
    { 0, 0, output_201 },
#endif
    0,
    &operand_data[423],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:6263 */
  {
    "*addqi_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_202 },
#else
    { 0, 0, output_202 },
#endif
    0,
    &operand_data[426],
    3,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:6318 */
  {
    "*addqi_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_203 },
#else
    { 0, 0, output_203 },
#endif
    0,
    &operand_data[429],
    2,
    1,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6358 */
  {
    "*addsi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_204 },
#else
    { 0, 0, output_204 },
#endif
    0,
    &operand_data[431],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6358 */
  {
    "*adddi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_205 },
#else
    { 0, 0, output_205 },
#endif
    0,
    &operand_data[434],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6467 */
  {
    "*addhi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_206 },
#else
    { 0, 0, output_206 },
#endif
    0,
    &operand_data[437],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6514 */
  {
    "*addqi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_207 },
#else
    { 0, 0, output_207 },
#endif
    0,
    &operand_data[440],
    3,
    2,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:6555 */
  {
    "*addsi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_208 },
#else
    { 0, 0, output_208 },
#endif
    0,
    &operand_data[443],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6555 */
  {
    "*adddi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_209 },
#else
    { 0, 0, output_209 },
#endif
    0,
    &operand_data[446],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6660 */
  {
    "*addhi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_210 },
#else
    { 0, 0, output_210 },
#endif
    0,
    &operand_data[449],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6705 */
  {
    "*addqi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_211 },
#else
    { 0, 0, output_211 },
#endif
    0,
    &operand_data[452],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6807 */
  {
    "*addsi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_212 },
#else
    { 0, 0, output_212 },
#endif
    0,
    &operand_data[455],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6852 */
  {
    "*addhi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_213 },
#else
    { 0, 0, output_213 },
#endif
    0,
    &operand_data[458],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6897 */
  {
    "*addqi_4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_214 },
#else
    { 0, 0, output_214 },
#endif
    0,
    &operand_data[461],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6935 */
  {
    "*addsi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_215 },
#else
    { 0, 0, output_215 },
#endif
    0,
    &operand_data[443],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6935 */
  {
    "*adddi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_216 },
#else
    { 0, 0, output_216 },
#endif
    0,
    &operand_data[446],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:6990 */
  {
    "*addhi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_217 },
#else
    { 0, 0, output_217 },
#endif
    0,
    &operand_data[449],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:7036 */
  {
    "*addqi_5",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_218 },
#else
    { 0, 0, output_218 },
#endif
    0,
    &operand_data[452],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:7113 */
  {
    "addqi_ext_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_219 },
#else
    { 0, 0, output_219 },
#endif
    (insn_gen_fn) gen_addqi_ext_1,
    &operand_data[464],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:7150 */
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
    &operand_data[467],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7172 */
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
    &operand_data[470],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7225 */
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
    &operand_data[474],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7275 */
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
    &operand_data[478],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7396 */
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
    &operand_data[483],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7396 */
  {
    "*subti3_doubleword",
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
    &operand_data[486],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7418 */
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
    &operand_data[489],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7418 */
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
    &operand_data[492],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7418 */
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
    &operand_data[495],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7418 */
  {
    "*subdi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[498],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7440 */
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
    &operand_data[501],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7451 */
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
    &operand_data[489],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7451 */
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
    &operand_data[492],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7451 */
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
    &operand_data[495],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7451 */
  {
    "*subdi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[498],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7482 */
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
    &operand_data[489],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7482 */
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
    &operand_data[492],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7482 */
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
    &operand_data[495],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7482 */
  {
    "*subdi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[498],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[503],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[507],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[511],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[515],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[519],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
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
    &operand_data[523],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
  {
    "*adddi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "adc{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[527],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7523 */
  {
    "*subdi3_carry",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[531],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7570 */
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
    &operand_data[535],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7570 */
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
    &operand_data[538],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7570 */
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
    &operand_data[541],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7570 */
  {
    "*adddi3_cconly_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[544],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7583 */
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
    &operand_data[9],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7583 */
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
    &operand_data[11],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7583 */
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
    &operand_data[13],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[406],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[489],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[417],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[492],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[400],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
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
    &operand_data[495],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
  {
    "*adddi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[403],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7595 */
  {
    "*subdi3_cc_overflow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[498],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:7670 */
  {
    "*mulsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_262 },
#else
    { 0, output_262, 0 },
#endif
    0,
    &operand_data[547],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:7737 */
  {
    "*mulhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_263 },
#else
    { 0, output_263, 0 },
#endif
    0,
    &operand_data[550],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:7766 */
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
    &operand_data[553],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7805 */
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
    &operand_data[556],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7805 */
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
    &operand_data[556],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7824 */
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
    &operand_data[559],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7824 */
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
    &operand_data[559],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7883 */
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
    &operand_data[562],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7883 */
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
    &operand_data[562],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7948 */
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
    &operand_data[566],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:7948 */
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
    &operand_data[566],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8006 */
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
    &operand_data[569],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8006 */
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
    &operand_data[573],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8041 */
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
    &operand_data[577],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8041 */
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
    &operand_data[582],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8065 */
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
    &operand_data[569],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8065 */
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
    &operand_data[573],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8086 */
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
    &operand_data[577],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8086 */
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
    &operand_data[582],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8159 */
  {
    "*testqi_1_maybe_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_281 },
#else
    { 0, 0, output_281 },
#endif
    0,
    &operand_data[587],
    2,
    0,
    4,
    3
  },
  /* ../../gcc/config/i386/i386.md:8184 */
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
    &operand_data[589],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:8184 */
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
    &operand_data[591],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:8184 */
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
    &operand_data[593],
    2,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:8212 */
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
    &operand_data[595],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8246 */
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
    &operand_data[597],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8262 */
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
    &operand_data[22],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8302 */
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
    &operand_data[599],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8478 */
  {
    "*andsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_289 },
#else
    { 0, 0, output_289 },
#endif
    0,
    &operand_data[602],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:8535 */
  {
    "*andhi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_290 },
#else
    { 0, 0, output_290 },
#endif
    0,
    &operand_data[605],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:8566 */
  {
    "*andqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_291 },
#else
    { 0, output_291, 0 },
#endif
    0,
    &operand_data[423],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:8579 */
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
    &operand_data[608],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8648 */
  {
    "*andqi_2_maybe_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_293 },
#else
    { 0, 0, output_293 },
#endif
    0,
    &operand_data[610],
    3,
    2,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:8672 */
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
    &operand_data[440],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8672 */
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
    &operand_data[437],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8672 */
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
    &operand_data[431],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8701 */
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
    &operand_data[613],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8719 */
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
    &operand_data[615],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8739 */
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
    &operand_data[615],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8783 */
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
    &operand_data[618],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8801 */
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
    &operand_data[467],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
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
    &operand_data[437],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
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
    &operand_data[437],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
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
    &operand_data[431],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
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
    &operand_data[431],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
  {
    "*iordi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[434],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8878 */
  {
    "*xordi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[434],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8890 */
  {
    "*iorqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_308 },
#else
    { 0, output_308, 0 },
#endif
    0,
    &operand_data[621],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:8890 */
  {
    "*xorqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_309 },
#else
    { 0, output_309, 0 },
#endif
    0,
    &operand_data[621],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:8926 */
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
    &operand_data[624],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8926 */
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
    &operand_data[624],
    2,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[440],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[440],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[437],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[437],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[431],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
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
    &operand_data[431],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
  {
    "*iordi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[434],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8937 */
  {
    "*xordi_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[434],
    3,
    2,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8980 */
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
    &operand_data[626],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8980 */
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
    &operand_data[626],
    2,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[452],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[452],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[449],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[449],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[443],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
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
    &operand_data[443],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
  {
    "*iordi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[446],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:8994 */
  {
    "*xordi_3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{q}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[446],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9007 */
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
    &operand_data[615],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9007 */
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
    &operand_data[615],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9044 */
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
    &operand_data[618],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9044 */
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
    &operand_data[618],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9063 */
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
    &operand_data[628],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9063 */
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
    &operand_data[628],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9169 */
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
    &operand_data[631],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9202 */
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
    &operand_data[634],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9202 */
  {
    "*negti2_doubleword",
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
    &operand_data[636],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9225 */
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
    &operand_data[638],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9225 */
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
    &operand_data[640],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9225 */
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
    &operand_data[642],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9225 */
  {
    "*negdi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{q}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[644],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9251 */
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
    &operand_data[638],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9251 */
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
    &operand_data[640],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9251 */
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
    &operand_data[642],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9251 */
  {
    "*negdi2_cmpz",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg{q}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[644],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9289 */
  {
    "*absnegsf2_mixed",
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
    &operand_data[646],
    4,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:9289 */
  {
    "*absnegdf2_mixed",
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
    &operand_data[650],
    4,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/i386.md:9298 */
  {
    "*absnegsf2_sse",
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
    &operand_data[654],
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:9298 */
  {
    "*absnegdf2_sse",
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
    &operand_data[658],
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/i386.md:9307 */
  {
    "*absnegsf2_i387",
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
    &operand_data[662],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:9307 */
  {
    "*absnegdf2_i387",
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
    &operand_data[666],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:9307 */
  {
    "*absnegxf2_i387",
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
    &operand_data[670],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:9322 */
  {
    "*absnegtf2_sse",
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
    &operand_data[674],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*abssf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[678],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*negsf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[678],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*absdf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[680],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*negdf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[680],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*absxf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9460 */
  {
    "*negxf2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9470 */
  {
    "*absextendsfdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[684],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9470 */
  {
    "*negextendsfdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[684],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9479 */
  {
    "*absextendsfxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[686],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9479 */
  {
    "*negextendsfxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[686],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9488 */
  {
    "*absextenddfxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[688],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9488 */
  {
    "*negextenddfxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fchs",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[688],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9513 */
  {
    "copysignsf3_const",
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
    (insn_gen_fn) gen_copysignsf3_const,
    &operand_data[690],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9513 */
  {
    "copysigndf3_const",
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
    (insn_gen_fn) gen_copysigndf3_const,
    &operand_data[694],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9513 */
  {
    "copysigntf3_const",
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
    (insn_gen_fn) gen_copysigntf3_const,
    &operand_data[698],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9530 */
  {
    "copysignsf3_var",
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
    (insn_gen_fn) gen_copysignsf3_var,
    &operand_data[702],
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:9530 */
  {
    "copysigndf3_var",
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
    (insn_gen_fn) gen_copysigndf3_var,
    &operand_data[708],
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:9530 */
  {
    "copysigntf3_var",
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
    (insn_gen_fn) gen_copysigntf3_var,
    &operand_data[714],
    6,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/i386.md:9569 */
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
    &operand_data[640],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9569 */
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
    &operand_data[642],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9569 */
  {
    "*one_cmpldi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "not{q}\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[644],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9578 */
  {
    "*one_cmplqi2_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_376 },
#else
    { 0, output_376, 0 },
#endif
    0,
    &operand_data[720],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:9598 */
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
    &operand_data[638],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9598 */
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
    &operand_data[640],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9598 */
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
    &operand_data[642],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9598 */
  {
    "*one_cmpldi2_2",
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
    &operand_data[644],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:9951 */
  {
    "*ashldi3_1",
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
    &operand_data[722],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:9984 */
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
    &operand_data[725],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:10051 */
  {
    "*ashlsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_383 },
#else
    { 0, 0, output_383 },
#endif
    0,
    &operand_data[728],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:10211 */
  {
    "*ashlsi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_384 },
#else
    { 0, 0, output_384 },
#endif
    0,
    &operand_data[731],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10262 */
  {
    "*ashlsi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_385 },
#else
    { 0, 0, output_385 },
#endif
    0,
    &operand_data[734],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10370 */
  {
    "*ashlhi3_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_386 },
#else
    { 0, 0, output_386 },
#endif
    0,
    &operand_data[737],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:10417 */
  {
    "*ashlhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_387 },
#else
    { 0, 0, output_387 },
#endif
    0,
    &operand_data[740],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10463 */
  {
    "*ashlhi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_388 },
#else
    { 0, 0, output_388 },
#endif
    0,
    &operand_data[743],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10514 */
  {
    "*ashlhi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_389 },
#else
    { 0, 0, output_389 },
#endif
    0,
    &operand_data[746],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10573 */
  {
    "*ashlqi3_1_lea",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_390 },
#else
    { 0, 0, output_390 },
#endif
    0,
    &operand_data[749],
    3,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:10638 */
  {
    "*ashlqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_391 },
#else
    { 0, 0, output_391 },
#endif
    0,
    &operand_data[752],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:10702 */
  {
    "*ashlqi3_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_392 },
#else
    { 0, 0, output_392 },
#endif
    0,
    &operand_data[755],
    3,
    2,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:10753 */
  {
    "*ashlqi3_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_393 },
#else
    { 0, 0, output_393 },
#endif
    0,
    &operand_data[758],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:11004 */
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
    &operand_data[761],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11037 */
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
    &operand_data[725],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11086 */
  {
    "*ashrsi3_31",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_396 },
#else
    { 0, output_396, 0 },
#endif
    0,
    &operand_data[764],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11127 */
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
    &operand_data[767],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11152 */
  {
    "*ashrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_398 },
#else
    { 0, output_398, 0 },
#endif
    0,
    &operand_data[770],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11179 */
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
    &operand_data[767],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11195 */
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
    &operand_data[773],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11230 */
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
    &operand_data[731],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11245 */
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
    &operand_data[734],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11282 */
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
    &operand_data[776],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11294 */
  {
    "*ashrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_404 },
#else
    { 0, output_404, 0 },
#endif
    0,
    &operand_data[779],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11309 */
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
    &operand_data[776],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11325 */
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
    &operand_data[782],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11343 */
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
    &operand_data[743],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11358 */
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
    &operand_data[746],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11379 */
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
    &operand_data[785],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11391 */
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
    &operand_data[788],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11404 */
  {
    "*ashrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_411 },
#else
    { 0, output_411, 0 },
#endif
    0,
    &operand_data[790],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11416 */
  {
    "*ashrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_412 },
#else
    { 0, output_412, 0 },
#endif
    0,
    &operand_data[793],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11432 */
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
    &operand_data[795],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11448 */
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
    &operand_data[798],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11466 */
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
    &operand_data[755],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11481 */
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
    &operand_data[758],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11639 */
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
    &operand_data[761],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11679 */
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
    &operand_data[767],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11704 */
  {
    "*lshrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_419 },
#else
    { 0, output_419, 0 },
#endif
    0,
    &operand_data[770],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11732 */
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
    &operand_data[767],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11748 */
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
    &operand_data[773],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11783 */
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
    &operand_data[731],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11798 */
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
    &operand_data[734],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11835 */
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
    &operand_data[776],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11847 */
  {
    "*lshrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_425 },
#else
    { 0, output_425, 0 },
#endif
    0,
    &operand_data[779],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11862 */
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
    &operand_data[776],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11878 */
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
    &operand_data[782],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11896 */
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
    &operand_data[743],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11911 */
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
    &operand_data[746],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11932 */
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
    &operand_data[785],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11944 */
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
    &operand_data[788],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:11956 */
  {
    "*lshrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_432 },
#else
    { 0, output_432, 0 },
#endif
    0,
    &operand_data[790],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11968 */
  {
    "*lshrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_433 },
#else
    { 0, output_433, 0 },
#endif
    0,
    &operand_data[793],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:11984 */
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
    &operand_data[785],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12000 */
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
    &operand_data[798],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12018 */
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
    &operand_data[755],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12033 */
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
    &operand_data[758],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12068 */
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
    &operand_data[801],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12124 */
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
    &operand_data[767],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12150 */
  {
    "*rotlsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_440 },
#else
    { 0, output_440, 0 },
#endif
    0,
    &operand_data[770],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12182 */
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
    &operand_data[776],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12194 */
  {
    "*rotlhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_442 },
#else
    { 0, output_442, 0 },
#endif
    0,
    &operand_data[779],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12223 */
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
    &operand_data[788],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12235 */
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
    &operand_data[785],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12247 */
  {
    "*rotlqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_445 },
#else
    { 0, output_445, 0 },
#endif
    0,
    &operand_data[793],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12260 */
  {
    "*rotlqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_446 },
#else
    { 0, output_446, 0 },
#endif
    0,
    &operand_data[790],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12291 */
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
    &operand_data[801],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12347 */
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
    &operand_data[767],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12373 */
  {
    "*rotrsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_449 },
#else
    { 0, output_449, 0 },
#endif
    0,
    &operand_data[770],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12405 */
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
    &operand_data[776],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12417 */
  {
    "*rotrhi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_451 },
#else
    { 0, output_451, 0 },
#endif
    0,
    &operand_data[779],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12446 */
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
    &operand_data[785],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12458 */
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
    &operand_data[788],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12470 */
  {
    "*rotrqi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_454 },
#else
    { 0, output_454, 0 },
#endif
    0,
    &operand_data[790],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12482 */
  {
    "*rotrqi3_1_slp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_455 },
#else
    { 0, output_455, 0 },
#endif
    0,
    &operand_data[793],
    2,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:12717 */
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
    &operand_data[805],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12750 */
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
    &operand_data[807],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12767 */
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
    &operand_data[807],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12782 */
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
    &operand_data[809],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12791 */
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
    &operand_data[811],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12875 */
  {
    "*avx_setccsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D1ss\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[813],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12875 */
  {
    "*avx_setccdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D1sd\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[817],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12887 */
  {
    "*sse_setccsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D1ss\t{%3, %0|%0, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[821],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12887 */
  {
    "*sse_setccdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D1sd\t{%3, %0|%0, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[825],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:12901 */
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
    &operand_data[829],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:12919 */
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
    &operand_data[829],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:13057 */
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
    &operand_data[831],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13090 */
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
    &operand_data[835],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13119 */
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
    &operand_data[831],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13152 */
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
    &operand_data[835],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13188 */
  {
    "*fp_jcc_1_387",
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
    &operand_data[840],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13206 */
  {
    "*fp_jcc_1r_387",
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
    &operand_data[840],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13224 */
  {
    "*fp_jcc_2_387",
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
    &operand_data[845],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13239 */
  {
    "*fp_jcc_2r_387",
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
    &operand_data[845],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13254 */
  {
    "*fp_jcc_3_387",
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
    &operand_data[850],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13311 */
  {
    "*fp_jcc_4_hi_387",
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
    &operand_data[855],
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:13311 */
  {
    "*fp_jcc_4_si_387",
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
    &operand_data[861],
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:13378 */
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
    &operand_data[664],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:13398 */
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
    &operand_data[558],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13443 */
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
    &operand_data[867],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13519 */
  {
    "*call_pop_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_481 },
#else
    { 0, 0, output_481 },
#endif
    0,
    &operand_data[869],
    3,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:13534 */
  {
    "*call_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_482 },
#else
    { 0, 0, output_482 },
#endif
    0,
    &operand_data[872],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:13548 */
  {
    "*sibcall_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_483 },
#else
    { 0, output_483, 0 },
#endif
    0,
    &operand_data[875],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:13580 */
  {
    "*call_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_484 },
#else
    { 0, 0, output_484 },
#endif
    0,
    &operand_data[878],
    2,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:13592 */
  {
    "*call_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_485 },
#else
    { 0, 0, output_485 },
#endif
    0,
    &operand_data[880],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:13603 */
  {
    "*sibcall_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_486 },
#else
    { 0, output_486, 0 },
#endif
    0,
    &operand_data[882],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:13755 */
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
  /* ../../gcc/config/i386/i386.md:13772 */
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
    &operand_data[884],
    1,
    1,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:13781 */
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
    &operand_data[664],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:13803 */
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
  /* ../../gcc/config/i386/i386.md:13815 */
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
  /* ../../gcc/config/i386/i386.md:13826 */
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
    &operand_data[600],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:13836 */
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
    &operand_data[726],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13844 */
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
  /* ../../gcc/config/i386/i386.md:13852 */
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
    &operand_data[885],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:13866 */
  {
    "pad",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_496 },
#else
    { 0, 0, output_496 },
#endif
    (insn_gen_fn) gen_pad,
    &operand_data[664],
    1,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:13887 */
  {
    "set_got",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_497 },
#else
    { 0, 0, output_497 },
#endif
    (insn_gen_fn) gen_set_got,
    &operand_data[55],
    1,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:13896 */
  {
    "set_got_labelled",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_498 },
#else
    { 0, 0, output_498 },
#endif
    (insn_gen_fn) gen_set_got_labelled,
    &operand_data[887],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:13965 */
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
  /* ../../gcc/config/i386/i386.md:13973 */
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
  /* ../../gcc/config/i386/i386.md:14020 */
  {
    "*ffs_no_cmove",
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
    &operand_data[889],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14044 */
  {
    "*ffssi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bsf{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[889],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14084 */
  {
    "ctzsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bsf{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ctzsi2,
    &operand_data[889],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14122 */
  {
    "clzsi2_abm",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lzcnt{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_clzsi2_abm,
    &operand_data[889],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14132 */
  {
    "bsr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bsr{l}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bsr,
    &operand_data[889],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14143 */
  {
    "popcounthi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_506 },
#else
    { 0, 0, output_506 },
#endif
    (insn_gen_fn) gen_popcounthi2,
    &operand_data[892],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14143 */
  {
    "popcountsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_507 },
#else
    { 0, 0, output_507 },
#endif
    (insn_gen_fn) gen_popcountsi2,
    &operand_data[889],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14160 */
  {
    "*popcounthi2_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_508 },
#else
    { 0, 0, output_508 },
#endif
    0,
    &operand_data[892],
    2,
    1,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14160 */
  {
    "*popcountsi2_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_509 },
#else
    { 0, 0, output_509 },
#endif
    0,
    &operand_data[889],
    2,
    1,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14160 */
  {
    "*popcountdi2_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_510 },
#else
    { 0, 0, output_510 },
#endif
    0,
    &operand_data[894],
    2,
    1,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14216 */
  {
    "*bswapsi_movbe",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_511 },
#else
    { 0, output_511, 0 },
#endif
    0,
    &operand_data[896],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/i386.md:14231 */
  {
    "*bswapsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bswap\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[898],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14239 */
  {
    "*bswaphi_lowpart_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_513 },
#else
    { 0, output_513, 0 },
#endif
    0,
    &operand_data[900],
    1,
    1,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:14250 */
  {
    "bswaphi_lowpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rol{w}\t{$8, %0|%0, 8}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bswaphi_lowpart,
    &operand_data[71],
    1,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14346 */
  {
    "clzhi2_abm",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lzcnt{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_clzhi2_abm,
    &operand_data[892],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14356 */
  {
    "*bsrhi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bsr{w}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[892],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14395 */
  {
    "paritydi2_cmp",
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
    (insn_gen_fn) gen_paritydi2_cmp,
    &operand_data[901],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14445 */
  {
    "paritysi2_cmp",
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
    (insn_gen_fn) gen_paritysi2_cmp,
    &operand_data[905],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14469 */
  {
    "*parityhi2_cmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor{b}\t{%h0, %b0|%b0, %h0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[908],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14484 */
  {
    "*tls_global_dynamic_32_gnu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lea{l}\t{%a2@tlsgd(,%1,1), %0|%0, %a2@tlsgd[%1*1]}\n\tcall\t%P3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[910],
    6,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14553 */
  {
    "*tls_local_dynamic_base_32_gnu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lea{l}\t{%&@tlsldm(%1), %0|%0, %&@tlsldm[%1]}\n\tcall\t%P2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[916],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14619 */
  {
    "*tls_local_dynamic_32_once",
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
    &operand_data[921],
    6,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14643 */
  {
    "*load_tp_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{l}\t{%%gs:0, %0|%0, DWORD PTR gs:0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[55],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14654 */
  {
    "*add_tp_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add{l}\t{%%gs:0, %0|%0, DWORD PTR gs:0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[898],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14711 */
  {
    "*tls_dynamic_lea_32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lea{l}\t{%a2@TLSDESC(%1), %0|%0, %a2@TLSDESC[%1]}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[927],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14724 */
  {
    "*tls_dynamic_call_32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "call\t{*%a1@TLSCALL(%2)|[DWORD PTR [%2+%a1@TLSCALL]]}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[930],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14739 */
  {
    "*tls_dynamic_gnu2_combine_32",
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
    &operand_data[934],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14832 */
  {
    "*fop_sf_comm_mixed_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_528 },
#else
    { 0, 0, output_528 },
#endif
    0,
    &operand_data[939],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:14832 */
  {
    "*fop_df_comm_mixed_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_529 },
#else
    { 0, 0, output_529 },
#endif
    0,
    &operand_data[943],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:14852 */
  {
    "*fop_sf_comm_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_530 },
#else
    { 0, 0, output_530 },
#endif
    0,
    &operand_data[947],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:14852 */
  {
    "*fop_df_comm_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_531 },
#else
    { 0, 0, output_531 },
#endif
    0,
    &operand_data[951],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:14871 */
  {
    "*fop_sf_comm_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_532 },
#else
    { 0, 0, output_532 },
#endif
    0,
    &operand_data[955],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14871 */
  {
    "*fop_df_comm_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_533 },
#else
    { 0, 0, output_533 },
#endif
    0,
    &operand_data[959],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14887 */
  {
    "*fop_sf_comm_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_534 },
#else
    { 0, 0, output_534 },
#endif
    0,
    &operand_data[963],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14887 */
  {
    "*fop_df_comm_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_535 },
#else
    { 0, 0, output_535 },
#endif
    0,
    &operand_data[967],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14902 */
  {
    "*fop_sf_comm_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_536 },
#else
    { 0, 0, output_536 },
#endif
    0,
    &operand_data[971],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14902 */
  {
    "*fop_df_comm_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_537 },
#else
    { 0, 0, output_537 },
#endif
    0,
    &operand_data[975],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14917 */
  {
    "*fop_sf_1_mixed_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_538 },
#else
    { 0, 0, output_538 },
#endif
    0,
    &operand_data[979],
    4,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:14917 */
  {
    "*fop_df_1_mixed_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_539 },
#else
    { 0, 0, output_539 },
#endif
    0,
    &operand_data[983],
    4,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:14944 */
  {
    "*fop_sf_1_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_540 },
#else
    { 0, 0, output_540 },
#endif
    0,
    &operand_data[987],
    4,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:14944 */
  {
    "*fop_df_1_mixed",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_541 },
#else
    { 0, 0, output_541 },
#endif
    0,
    &operand_data[991],
    4,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/i386.md:14970 */
  {
    "*rcpsf2_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vrcpss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[995],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:14981 */
  {
    "*fop_sf_1_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_543 },
#else
    { 0, 0, output_543 },
#endif
    0,
    &operand_data[997],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14981 */
  {
    "*fop_df_1_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_544 },
#else
    { 0, 0, output_544 },
#endif
    0,
    &operand_data[1001],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14999 */
  {
    "*fop_sf_1_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_545 },
#else
    { 0, 0, output_545 },
#endif
    0,
    &operand_data[1005],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:14999 */
  {
    "*fop_df_1_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_546 },
#else
    { 0, 0, output_546 },
#endif
    0,
    &operand_data[1009],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:15017 */
  {
    "*fop_sf_1_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_547 },
#else
    { 0, 0, output_547 },
#endif
    0,
    &operand_data[1013],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15017 */
  {
    "*fop_df_1_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_548 },
#else
    { 0, 0, output_548 },
#endif
    0,
    &operand_data[1017],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15037 */
  {
    "*fop_sf_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_549 },
#else
    { 0, 0, output_549 },
#endif
    0,
    &operand_data[1021],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15037 */
  {
    "*fop_df_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_550 },
#else
    { 0, 0, output_550 },
#endif
    0,
    &operand_data[1025],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15037 */
  {
    "*fop_sf_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_551 },
#else
    { 0, 0, output_551 },
#endif
    0,
    &operand_data[1029],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15037 */
  {
    "*fop_df_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_552 },
#else
    { 0, 0, output_552 },
#endif
    0,
    &operand_data[1033],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15057 */
  {
    "*fop_sf_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_553 },
#else
    { 0, 0, output_553 },
#endif
    0,
    &operand_data[1037],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15057 */
  {
    "*fop_df_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_554 },
#else
    { 0, 0, output_554 },
#endif
    0,
    &operand_data[1041],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15057 */
  {
    "*fop_sf_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_555 },
#else
    { 0, 0, output_555 },
#endif
    0,
    &operand_data[1045],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15057 */
  {
    "*fop_df_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_556 },
#else
    { 0, 0, output_556 },
#endif
    0,
    &operand_data[1049],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15077 */
  {
    "*fop_df_4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_557 },
#else
    { 0, 0, output_557 },
#endif
    0,
    &operand_data[1053],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15096 */
  {
    "*fop_df_5_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_558 },
#else
    { 0, 0, output_558 },
#endif
    0,
    &operand_data[1057],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15114 */
  {
    "*fop_df_6_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_559 },
#else
    { 0, 0, output_559 },
#endif
    0,
    &operand_data[1061],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15133 */
  {
    "*fop_xf_comm_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_560 },
#else
    { 0, 0, output_560 },
#endif
    0,
    &operand_data[1065],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:15147 */
  {
    "*fop_xf_1_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_561 },
#else
    { 0, 0, output_561 },
#endif
    0,
    &operand_data[1069],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15164 */
  {
    "*fop_xf_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_562 },
#else
    { 0, 0, output_562 },
#endif
    0,
    &operand_data[1073],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15164 */
  {
    "*fop_xf_2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_563 },
#else
    { 0, 0, output_563 },
#endif
    0,
    &operand_data[1077],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15182 */
  {
    "*fop_xf_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_564 },
#else
    { 0, 0, output_564 },
#endif
    0,
    &operand_data[1081],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15182 */
  {
    "*fop_xf_3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_565 },
#else
    { 0, 0, output_565 },
#endif
    0,
    &operand_data[1085],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15200 */
  {
    "*fop_xf_4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_566 },
#else
    { 0, 0, output_566 },
#endif
    0,
    &operand_data[1089],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15200 */
  {
    "*fop_xf_4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_567 },
#else
    { 0, 0, output_567 },
#endif
    0,
    &operand_data[1093],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15217 */
  {
    "*fop_xf_5_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_568 },
#else
    { 0, 0, output_568 },
#endif
    0,
    &operand_data[1097],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15217 */
  {
    "*fop_xf_5_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_569 },
#else
    { 0, 0, output_569 },
#endif
    0,
    &operand_data[1101],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15234 */
  {
    "*fop_xf_6_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_570 },
#else
    { 0, 0, output_570 },
#endif
    0,
    &operand_data[1105],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15234 */
  {
    "*fop_xf_6_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_571 },
#else
    { 0, 0, output_571 },
#endif
    0,
    &operand_data[1109],
    4,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:15299 */
  {
    "truncxfsf2_i387_noop_unspec",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_572 },
#else
    { 0, 0, output_572 },
#endif
    (insn_gen_fn) gen_truncxfsf2_i387_noop_unspec,
    &operand_data[190],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:15299 */
  {
    "truncxfdf2_i387_noop_unspec",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_573 },
#else
    { 0, 0, output_573 },
#endif
    (insn_gen_fn) gen_truncxfdf2_i387_noop_unspec,
    &operand_data[192],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:15308 */
  {
    "sqrtxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsqrt",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sqrtxf2,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15318 */
  {
    "sqrt_extendsfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsqrt",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sqrt_extendsfxf2_i387,
    &operand_data[686],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15318 */
  {
    "sqrt_extenddfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsqrt",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sqrt_extenddfxf2_i387,
    &operand_data[688],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15330 */
  {
    "*rsqrtsf2_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vrsqrtss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[995],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15351 */
  {
    "*sqrtsf2_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vsqrtss\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[995],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15351 */
  {
    "*sqrtdf2_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vsqrtsd\t{%1, %d0|%d0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1113],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15391 */
  {
    "fpremxf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fprem",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fpremxf4_i387,
    &operand_data[1115],
    4,
    4,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15459 */
  {
    "fprem1xf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fprem1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fprem1xf4_i387,
    &operand_data[1115],
    4,
    4,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15528 */
  {
    "*sinxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsin",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15537 */
  {
    "*sin_extendsfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsin",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[686],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15537 */
  {
    "*sin_extenddfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsin",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[688],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15550 */
  {
    "*cosxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15559 */
  {
    "*cos_extendsfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[686],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15559 */
  {
    "*cos_extenddfxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[688],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15578 */
  {
    "sincosxf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsincos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sincosxf3,
    &operand_data[1115],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15612 */
  {
    "sincos_extendsfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsincos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sincos_extendsfxf3_i387,
    &operand_data[1119],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15612 */
  {
    "sincos_extenddfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsincos",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sincos_extenddfxf3_i387,
    &operand_data[1122],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15669 */
  {
    "fptanxf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fptan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fptanxf4_i387,
    &operand_data[1125],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15682 */
  {
    "fptan_extendsfxf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fptan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fptan_extendsfxf4_i387,
    &operand_data[1129],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15682 */
  {
    "fptan_extenddfxf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fptan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fptan_extenddfxf4_i387,
    &operand_data[1133],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15730 */
  {
    "*fpatanxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fpatan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1137],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15742 */
  {
    "fpatan_extendsfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fpatan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fpatan_extendsfxf3_i387,
    &operand_data[1141],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15742 */
  {
    "fpatan_extenddfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fpatan",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fpatan_extenddfxf3_i387,
    &operand_data[1145],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15903 */
  {
    "fyl2xxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2x",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2xxf3_i387,
    &operand_data[1137],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15915 */
  {
    "fyl2x_extendsfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2x",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2x_extendsfxf3_i387,
    &operand_data[1149],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:15915 */
  {
    "fyl2x_extenddfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2x",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2x_extenddfxf3_i387,
    &operand_data[1153],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16020 */
  {
    "fyl2xp1xf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2xp1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2xp1xf3_i387,
    &operand_data[1137],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16032 */
  {
    "fyl2xp1_extendsfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2xp1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2xp1_extendsfxf3_i387,
    &operand_data[1149],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16032 */
  {
    "fyl2xp1_extenddfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fyl2xp1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fyl2xp1_extenddfxf3_i387,
    &operand_data[1153],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16082 */
  {
    "fxtractxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxtract",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxtractxf3_i387,
    &operand_data[1115],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16094 */
  {
    "fxtract_extendsfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxtract",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxtract_extendsfxf3_i387,
    &operand_data[1119],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16094 */
  {
    "fxtract_extenddfxf3_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxtract",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxtract_extenddfxf3_i387,
    &operand_data[1122],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16177 */
  {
    "*f2xm1xf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "f2xm1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16187 */
  {
    "*fscalexf4_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fscale",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1115],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16524 */
  {
    "sse4_1_roundsf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vroundss\t{%2, %1, %d0|%d0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_roundsf2,
    &operand_data[1157],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16524 */
  {
    "sse4_1_rounddf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vroundsd\t{%2, %1, %d0|%d0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_rounddf2,
    &operand_data[1160],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16536 */
  {
    "rintxf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "frndint",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_rintxf2,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16595 */
  {
    "*fistdi2_1",
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
    &operand_data[1163],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16618 */
  {
    "fistdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_612 },
#else
    { 0, 0, output_612 },
#endif
    (insn_gen_fn) gen_fistdi2,
    &operand_data[1165],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16628 */
  {
    "fistdi2_with_temp",
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
    (insn_gen_fn) gen_fistdi2_with_temp,
    &operand_data[1168],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:16662 */
  {
    "*fisthi2_1",
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
    &operand_data[271],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16662 */
  {
    "*fistsi2_1",
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
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16680 */
  {
    "fisthi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_616 },
#else
    { 0, 0, output_616 },
#endif
    (insn_gen_fn) gen_fisthi2,
    &operand_data[1172],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16680 */
  {
    "fistsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_617 },
#else
    { 0, 0, output_617 },
#endif
    (insn_gen_fn) gen_fistsi2,
    &operand_data[1174],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16689 */
  {
    "fisthi2_with_temp",
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
    (insn_gen_fn) gen_fisthi2_with_temp,
    &operand_data[1176],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16689 */
  {
    "fistsi2_with_temp",
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
    (insn_gen_fn) gen_fistsi2_with_temp,
    &operand_data[1179],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16747 */
  {
    "frndintxf2_floor",
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
    (insn_gen_fn) gen_frndintxf2_floor,
    &operand_data[1182],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16772 */
  {
    "frndintxf2_floor_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%3\n\tfrndint\n\tfldcw\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_frndintxf2_floor_i387,
    &operand_data[1184],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:16838 */
  {
    "*fisthi2_floor_1",
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
    &operand_data[1188],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16838 */
  {
    "*fistsi2_floor_1",
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
    &operand_data[1190],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16838 */
  {
    "*fistdi2_floor_1",
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
    &operand_data[1163],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:16870 */
  {
    "fistdi2_floor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_625 },
#else
    { 0, 0, output_625 },
#endif
    (insn_gen_fn) gen_fistdi2_floor,
    &operand_data[1192],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16884 */
  {
    "fistdi2_floor_with_temp",
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
    (insn_gen_fn) gen_fistdi2_floor_with_temp,
    &operand_data[1197],
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:16930 */
  {
    "fisthi2_floor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_627 },
#else
    { 0, 0, output_627 },
#endif
    (insn_gen_fn) gen_fisthi2_floor,
    &operand_data[1203],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16930 */
  {
    "fistsi2_floor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_628 },
#else
    { 0, 0, output_628 },
#endif
    (insn_gen_fn) gen_fistsi2_floor,
    &operand_data[1207],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:16943 */
  {
    "fisthi2_floor_with_temp",
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
    (insn_gen_fn) gen_fisthi2_floor_with_temp,
    &operand_data[1211],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:16943 */
  {
    "fistsi2_floor_with_temp",
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
    (insn_gen_fn) gen_fistsi2_floor_with_temp,
    &operand_data[1216],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:17009 */
  {
    "frndintxf2_ceil",
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
    (insn_gen_fn) gen_frndintxf2_ceil,
    &operand_data[1182],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17034 */
  {
    "frndintxf2_ceil_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%3\n\tfrndint\n\tfldcw\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_frndintxf2_ceil_i387,
    &operand_data[1184],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17100 */
  {
    "*fisthi2_ceil_1",
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
    &operand_data[1188],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17100 */
  {
    "*fistsi2_ceil_1",
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
    &operand_data[1190],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17100 */
  {
    "*fistdi2_ceil_1",
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
    &operand_data[1163],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17132 */
  {
    "fistdi2_ceil",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_636 },
#else
    { 0, 0, output_636 },
#endif
    (insn_gen_fn) gen_fistdi2_ceil,
    &operand_data[1192],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:17146 */
  {
    "fistdi2_ceil_with_temp",
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
    (insn_gen_fn) gen_fistdi2_ceil_with_temp,
    &operand_data[1197],
    6,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:17192 */
  {
    "fisthi2_ceil",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_638 },
#else
    { 0, 0, output_638 },
#endif
    (insn_gen_fn) gen_fisthi2_ceil,
    &operand_data[1203],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:17192 */
  {
    "fistsi2_ceil",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_639 },
#else
    { 0, 0, output_639 },
#endif
    (insn_gen_fn) gen_fistsi2_ceil,
    &operand_data[1207],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:17205 */
  {
    "fisthi2_ceil_with_temp",
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
    (insn_gen_fn) gen_fisthi2_ceil_with_temp,
    &operand_data[1211],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:17205 */
  {
    "fistsi2_ceil_with_temp",
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
    (insn_gen_fn) gen_fistsi2_ceil_with_temp,
    &operand_data[1216],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:17269 */
  {
    "frndintxf2_trunc",
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
    (insn_gen_fn) gen_frndintxf2_trunc,
    &operand_data[1182],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17294 */
  {
    "frndintxf2_trunc_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%3\n\tfrndint\n\tfldcw\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_frndintxf2_trunc_i387,
    &operand_data[1184],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17361 */
  {
    "frndintxf2_mask_pm",
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
    (insn_gen_fn) gen_frndintxf2_mask_pm,
    &operand_data[1182],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17386 */
  {
    "frndintxf2_mask_pm_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fldcw\t%3\n\tfrndint\n\tfclex\n\tfldcw\t%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_frndintxf2_mask_pm_i387,
    &operand_data[1184],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17428 */
  {
    "fxamsf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxam\n\tfnstsw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxamsf2_i387,
    &operand_data[30],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17428 */
  {
    "fxamdf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxam\n\tfnstsw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxamdf2_i387,
    &operand_data[33],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17428 */
  {
    "fxamxf2_i387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "fxam\n\tfnstsw\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fxamxf2_i387,
    &operand_data[27],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17440 */
  {
    "fxamsf2_i387_with_temp",
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
    (insn_gen_fn) gen_fxamsf2_i387_with_temp,
    &operand_data[1221],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17440 */
  {
    "fxamdf2_i387_with_temp",
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
    (insn_gen_fn) gen_fxamdf2_i387_with_temp,
    &operand_data[1223],
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17543 */
  {
    "cld",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cld",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_cld,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/i386.md:17640 */
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
    &operand_data[1225],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17670 */
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
    &operand_data[1225],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17700 */
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
    &operand_data[1225],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17762 */
  {
    "*rep_movsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rep{%;} movs{l|d}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1229],
    6,
    4,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17800 */
  {
    "*rep_movqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rep{%;} movsb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1229],
    6,
    4,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17915 */
  {
    "*strsetsi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "stos{l|d}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1235],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17939 */
  {
    "*strsethi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "stosw",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1238],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:17963 */
  {
    "*strsetqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "stosb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1241],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18015 */
  {
    "*rep_stossi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rep{%;} stos{l|d}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1244],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18049 */
  {
    "*rep_stosqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rep{%;} stosb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1249],
    5,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18181 */
  {
    "*cmpstrnqi_nz_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "repz{%;} cmpsb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1254],
    7,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18229 */
  {
    "*cmpstrnqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "repz{%;} cmpsb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1254],
    7,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18299 */
  {
    "*strlenqi_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "repnz{%;} scasb",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1261],
    6,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18436 */
  {
    "*x86_movsicc_0_m1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1267],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18455 */
  {
    "*x86_movsicc_0_m1_se",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1267],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18472 */
  {
    "*x86_movsicc_0_m1_neg",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbb{l}\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1267],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18486 */
  {
    "*movhicc_noc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_668 },
#else
    { 0, output_668, 0 },
#endif
    0,
    &operand_data[1269],
    4,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:18486 */
  {
    "*movsicc_noc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_669 },
#else
    { 0, output_669, 0 },
#endif
    0,
    &operand_data[1273],
    4,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:18499 */
  {
    "*movqicc_noc",
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
    &operand_data[1277],
    5,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/i386.md:18529 */
  {
    "*movsfcc_1_387",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_671 },
#else
    { 0, output_671, 0 },
#endif
    0,
    &operand_data[1282],
    4,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/i386.md:18545 */
  {
    "*movdfcc_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_672 },
#else
    { 0, output_672, 0 },
#endif
    0,
    &operand_data[1286],
    4,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/i386.md:18596 */
  {
    "*movxfcc_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_673 },
#else
    { 0, output_673, 0 },
#endif
    0,
    &operand_data[1290],
    4,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:18613 */
  {
    "*xop_pcmov_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%1, %3, %2, %0|%0, %2, %3, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1294],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18613 */
  {
    "*xop_pcmov_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%1, %3, %2, %0|%0, %2, %3, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1298],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18628 */
  {
    "*avx_smaxsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[955],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18628 */
  {
    "*avx_sminsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[955],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18628 */
  {
    "*avx_smaxdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18628 */
  {
    "*avx_smindf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18639 */
  {
    "smaxsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_smaxsf3,
    &operand_data[963],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18639 */
  {
    "sminsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sminsf3,
    &operand_data[963],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18639 */
  {
    "smaxdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_smaxdf3,
    &operand_data[967],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18639 */
  {
    "smindf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_smindf3,
    &operand_data[967],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18655 */
  {
    "*avx_ieee_sminsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[997],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18655 */
  {
    "*avx_ieee_smindf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1001],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18667 */
  {
    "*ieee_sminsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1005],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18667 */
  {
    "*ieee_smindf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1009],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18678 */
  {
    "*avx_ieee_smaxsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1005],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18678 */
  {
    "*avx_ieee_smaxdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1009],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18690 */
  {
    "*ieee_smaxsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1005],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18690 */
  {
    "*ieee_smaxdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1009],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:18748 */
  {
    "pro_epilogue_adjust_stack_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_692 },
#else
    { 0, 0, output_692 },
#endif
    (insn_gen_fn) gen_pro_epilogue_adjust_stack_1,
    &operand_data[1302],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/i386.md:18875 */
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
    &operand_data[1305],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20056 */
  {
    "*call_value_pop_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_694 },
#else
    { 0, 0, output_694 },
#endif
    0,
    &operand_data[868],
    4,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:20072 */
  {
    "*call_value_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_695 },
#else
    { 0, 0, output_695 },
#endif
    0,
    &operand_data[1307],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:20087 */
  {
    "*sibcall_value_pop_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_696 },
#else
    { 0, output_696, 0 },
#endif
    0,
    &operand_data[1311],
    4,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:20100 */
  {
    "*call_value_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_697 },
#else
    { 0, 0, output_697 },
#endif
    0,
    &operand_data[868],
    3,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:20152 */
  {
    "*call_value_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_698 },
#else
    { 0, 0, output_698 },
#endif
    0,
    &operand_data[1307],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:20164 */
  {
    "*sibcall_value_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_699 },
#else
    { 0, output_699, 0 },
#endif
    0,
    &operand_data[1311],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/i386.md:20235 */
  {
    "trap",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_700 },
#else
    { 0, 0, output_700 },
#endif
    (insn_gen_fn) gen_trap,
    &operand_data[0],
    0,
    0,
    0,
    3
  },
  /* ../../gcc/config/i386/i386.md:20333 */
  {
    "*prefetch_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_701 },
#else
    { 0, 0, output_701 },
#endif
    0,
    &operand_data[1315],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:20373 */
  {
    "*prefetch_3dnow",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_702 },
#else
    { 0, 0, output_702 },
#endif
    0,
    &operand_data[1317],
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/i386.md:20424 */
  {
    "stack_protect_set_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{l}\t{%1, %2|%2, %1}\n\tmov{l}\t{%2, %0|%0, %2}\n\txor{l}\t%2, %2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_stack_protect_set_si,
    &operand_data[1319],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20442 */
  {
    "stack_tls_protect_set_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{l}\t{%%gs:%P1, %2|%2, DWORD PTR gs:%P1}\n\tmov{l}\t{%2, %0|%0, %2}\n\txor{l}\t%2, %2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_stack_tls_protect_set_si,
    &operand_data[1322],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20495 */
  {
    "stack_protect_test_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{l}\t{%1, %3|%3, %1}\n\txor{l}\t{%2, %3|%3, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_stack_protect_test_si,
    &operand_data[1325],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20515 */
  {
    "stack_tls_protect_test_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mov{l}\t{%1, %3|%3, %1}\n\txor{l}\t{%%gs:%P2, %3|%3, DWORD PTR gs:%P2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_stack_tls_protect_test_si,
    &operand_data[1329],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20543 */
  {
    "sse4_2_crc32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "crc32{b}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_crc32qi,
    &operand_data[1333],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20543 */
  {
    "sse4_2_crc32hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "crc32{w}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_crc32hi,
    &operand_data[1336],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20543 */
  {
    "sse4_2_crc32si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "crc32{l}\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_crc32si,
    &operand_data[1339],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20613 */
  {
    "*rdpmc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rdpmc",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1342],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20659 */
  {
    "*rdtsc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rdtsc",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[556],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20718 */
  {
    "*rdtscp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rdtscp",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1344],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20752 */
  {
    "*lwp_llwpcbsi1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "llwpcb\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[726],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20773 */
  {
    "lwp_slwpcbsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slwpcb\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_lwp_slwpcbsi,
    &operand_data[55],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20791 */
  {
    "*lwp_lwpvalsi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwpval\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1346],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/i386.md:20814 */
  {
    "*lwp_lwpinssi3_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwpins\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1346],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:100 */
  {
    "*movv8qi_internal_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_717 },
#else
    { 0, output_717, 0 },
#endif
    0,
    &operand_data[1349],
    2,
    0,
    10,
    2
  },
  /* ../../gcc/config/i386/mmx.md:100 */
  {
    "*movv4hi_internal_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_718 },
#else
    { 0, output_718, 0 },
#endif
    0,
    &operand_data[1351],
    2,
    0,
    10,
    2
  },
  /* ../../gcc/config/i386/mmx.md:100 */
  {
    "*movv2si_internal_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_719 },
#else
    { 0, output_719, 0 },
#endif
    0,
    &operand_data[1353],
    2,
    0,
    10,
    2
  },
  /* ../../gcc/config/i386/mmx.md:100 */
  {
    "*movv1di_internal_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_720 },
#else
    { 0, output_720, 0 },
#endif
    0,
    &operand_data[1355],
    2,
    0,
    10,
    2
  },
  /* ../../gcc/config/i386/mmx.md:127 */
  {
    "*movv8qi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_721 },
#else
    { 0, output_721, 0 },
#endif
    0,
    &operand_data[1357],
    2,
    0,
    14,
    2
  },
  /* ../../gcc/config/i386/mmx.md:127 */
  {
    "*movv4hi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_722 },
#else
    { 0, output_722, 0 },
#endif
    0,
    &operand_data[1359],
    2,
    0,
    14,
    2
  },
  /* ../../gcc/config/i386/mmx.md:127 */
  {
    "*movv2si_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_723 },
#else
    { 0, output_723, 0 },
#endif
    0,
    &operand_data[1361],
    2,
    0,
    14,
    2
  },
  /* ../../gcc/config/i386/mmx.md:127 */
  {
    "*movv1di_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_724 },
#else
    { 0, output_724, 0 },
#endif
    0,
    &operand_data[1363],
    2,
    0,
    14,
    2
  },
  /* ../../gcc/config/i386/mmx.md:221 */
  {
    "*movv2sf_internal_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_725 },
#else
    { 0, output_725, 0 },
#endif
    0,
    &operand_data[1365],
    2,
    0,
    11,
    2
  },
  /* ../../gcc/config/i386/mmx.md:249 */
  {
    "*movv2sf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_726 },
#else
    { 0, output_726, 0 },
#endif
    0,
    &operand_data[1365],
    2,
    0,
    11,
    2
  },
  /* ../../gcc/config/i386/mmx.md:300 */
  {
    "sse_movntdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_movntdi,
    &operand_data[1367],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:323 */
  {
    "*mmx_addv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfadd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1369],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:347 */
  {
    "*mmx_subv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_729 },
#else
    { 0, output_729, 0 },
#endif
    0,
    &operand_data[1372],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/mmx.md:366 */
  {
    "*mmx_mulv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfmul\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1369],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:392 */
  {
    "*mmx_smaxv2sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfmax\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1369],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:392 */
  {
    "*mmx_sminv2sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfmin\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1369],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:404 */
  {
    "*mmx_smaxv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfmax\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:404 */
  {
    "*mmx_sminv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfmin\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:415 */
  {
    "mmx_rcpv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfrcp\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_rcpv2sf2,
    &operand_data[1378],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:425 */
  {
    "mmx_rcpit1v2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfrcpit1\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_rcpit1v2sf3,
    &operand_data[1375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:436 */
  {
    "mmx_rcpit2v2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfrcpit2\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_rcpit2v2sf3,
    &operand_data[1375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:447 */
  {
    "mmx_rsqrtv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfrsqrt\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_rsqrtv2sf2,
    &operand_data[1378],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:457 */
  {
    "mmx_rsqit1v2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfrsqit1\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_rsqit1v2sf3,
    &operand_data[1375],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:468 */
  {
    "mmx_haddv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfacc\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_haddv2sf3,
    &operand_data[1375],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:487 */
  {
    "mmx_hsubv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfnacc\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_hsubv2sf3,
    &operand_data[1375],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:506 */
  {
    "mmx_addsubv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfpnacc\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_addsubv2sf3,
    &operand_data[1375],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:533 */
  {
    "*mmx_eqv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfcmpeq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1380],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:543 */
  {
    "mmx_gtv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfcmpgt\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_gtv2sf3,
    &operand_data[1383],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:553 */
  {
    "mmx_gev2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pfcmpge\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_gev2sf3,
    &operand_data[1383],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:569 */
  {
    "mmx_pf2id",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pf2id\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pf2id,
    &operand_data[1386],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:578 */
  {
    "mmx_pf2iw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pf2iw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pf2iw,
    &operand_data[1386],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:590 */
  {
    "mmx_pi2fw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pi2fw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pi2fw,
    &operand_data[1388],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:602 */
  {
    "mmx_floatv2si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pi2fd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_floatv2si2,
    &operand_data[1388],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:617 */
  {
    "mmx_pswapdv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pswapd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pswapdv2sf2,
    &operand_data[1378],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:627 */
  {
    "*vec_dupv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckldq\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1390],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:636 */
  {
    "*mmx_concatv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_752 },
#else
    { 0, output_752, 0 },
#endif
    0,
    &operand_data[1392],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/mmx.md:661 */
  {
    "*vec_extractv2sf_0",
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
    &operand_data[1395],
    2,
    0,
    6,
    1
  },
  /* ../../gcc/config/i386/mmx.md:682 */
  {
    "*vec_extractv2sf_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_754 },
#else
    { 0, output_754, 0 },
#endif
    0,
    &operand_data[1397],
    2,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_addv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_subv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1402],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_addv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_subv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1408],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_addv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1411],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_subv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1414],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_addv1di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1417],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:745 */
  {
    "*mmx_subv1di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1420],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_ssaddv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_usaddv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddusb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_sssubv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1402],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_ussubv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubusb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1402],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_ssaddv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_usaddv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddusw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_sssubv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1408],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:764 */
  {
    "*mmx_ussubv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubusw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1408],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:781 */
  {
    "*mmx_mulv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmullw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:803 */
  {
    "*mmx_smulv4hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:831 */
  {
    "*mmx_umulv4hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhuw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:869 */
  {
    "*mmx_pmaddwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaddwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1423],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:909 */
  {
    "*mmx_pmulhrwv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhrw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:942 */
  {
    "*sse2_umulv1siv1di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmuludq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1426],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:966 */
  {
    "*mmx_smaxv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:966 */
  {
    "*mmx_sminv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:985 */
  {
    "*mmx_umaxv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxub\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:985 */
  {
    "*mmx_uminv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminub\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:996 */
  {
    "mmx_ashrv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psraw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_ashrv4hi3,
    &operand_data[1429],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:996 */
  {
    "mmx_ashrv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrad\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_ashrv2si3,
    &operand_data[1432],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1010 */
  {
    "mmx_lshrv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrlw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_lshrv4hi3,
    &operand_data[1429],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1010 */
  {
    "mmx_lshrv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrld\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_lshrv2si3,
    &operand_data[1432],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1010 */
  {
    "mmx_lshrv1di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrlq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_lshrv1di3,
    &operand_data[1435],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1024 */
  {
    "mmx_ashlv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psllw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_ashlv4hi3,
    &operand_data[1429],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1024 */
  {
    "mmx_ashlv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pslld\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_ashlv2si3,
    &operand_data[1432],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1024 */
  {
    "mmx_ashlv1di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psllq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_ashlv1di3,
    &operand_data[1435],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1052 */
  {
    "*mmx_eqv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1052 */
  {
    "*mmx_eqv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1052 */
  {
    "*mmx_eqv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1411],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1062 */
  {
    "mmx_gtv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_gtv8qi3,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1062 */
  {
    "mmx_gtv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_gtv4hi3,
    &operand_data[1441],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1062 */
  {
    "mmx_gtv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_gtv2si3,
    &operand_data[1444],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1078 */
  {
    "mmx_andnotv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_andnotv8qi3,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1078 */
  {
    "mmx_andnotv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_andnotv4hi3,
    &operand_data[1441],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1078 */
  {
    "mmx_andnotv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_andnotv2si3,
    &operand_data[1444],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_andv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_iorv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_xorv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_andv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_iorv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_xorv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_andv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1411],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_iorv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1411],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1096 */
  {
    "*mmx_xorv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1411],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1112 */
  {
    "mmx_packsswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packsswb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_packsswb,
    &operand_data[1447],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1124 */
  {
    "mmx_packssdw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packssdw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_packssdw,
    &operand_data[1450],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1136 */
  {
    "mmx_packuswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packuswb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_packuswb,
    &operand_data[1447],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1148 */
  {
    "mmx_punpckhbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpckhbw,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1163 */
  {
    "mmx_punpcklbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpcklbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpcklbw,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1178 */
  {
    "mmx_punpckhwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpckhwd,
    &operand_data[1441],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1191 */
  {
    "mmx_punpcklwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpcklwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpcklwd,
    &operand_data[1441],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1204 */
  {
    "mmx_punpckhdq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhdq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpckhdq,
    &operand_data[1444],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1217 */
  {
    "mmx_punpckldq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckldq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_punpckldq,
    &operand_data[1444],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1243 */
  {
    "*mmx_pinsrw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_816 },
#else
    { 0, 0, output_816 },
#endif
    0,
    &operand_data[1453],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/mmx.md:1262 */
  {
    "mmx_pextrw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pextrw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pextrw,
    &operand_data[1457],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1289 */
  {
    "mmx_pshufw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_818 },
#else
    { 0, 0, output_818 },
#endif
    (insn_gen_fn) gen_mmx_pshufw_1,
    &operand_data[1460],
    6,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/mmx.md:1312 */
  {
    "mmx_pswapdv2si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pswapd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pswapdv2si2,
    &operand_data[1466],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1323 */
  {
    "*vec_dupv4hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pshufw\t{$0, %0, %0|%0, %0, 0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1468],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1334 */
  {
    "*vec_dupv2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckldq\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1470],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1343 */
  {
    "*mmx_concatv2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_822 },
#else
    { 0, output_822, 0 },
#endif
    0,
    &operand_data[1472],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/mmx.md:1368 */
  {
    "*vec_extractv2si_0",
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
    &operand_data[1475],
    2,
    0,
    5,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1389 */
  {
    "*vec_extractv2si_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_824 },
#else
    { 0, output_824, 0 },
#endif
    0,
    &operand_data[1477],
    2,
    0,
    7,
    2
  },
  /* ../../gcc/config/i386/mmx.md:1526 */
  {
    "*mmx_uavgv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_825 },
#else
    { 0, 0, output_825 },
#endif
    0,
    &operand_data[1399],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/mmx.md:1575 */
  {
    "*mmx_uavgv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pavgw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1594 */
  {
    "mmx_psadbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psadbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_psadbw,
    &operand_data[1479],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1604 */
  {
    "mmx_pmovmskb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmovmskb\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mmx_pmovmskb,
    &operand_data[1482],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1622 */
  {
    "*mmx_maskmovq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maskmovq\t{%2, %1|%1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1484],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1670 */
  {
    "*mmx_emms",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "emms",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1487],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/mmx.md:1703 */
  {
    "*mmx_femms",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "femms",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1487],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv16qi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_832 },
#else
    { 0, 0, output_832 },
#endif
    0,
    &operand_data[1488],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv8hi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_833 },
#else
    { 0, 0, output_833 },
#endif
    0,
    &operand_data[1490],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv4si_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_834 },
#else
    { 0, 0, output_834 },
#endif
    0,
    &operand_data[1492],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv2di_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_835 },
#else
    { 0, 0, output_835 },
#endif
    0,
    &operand_data[1494],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv1ti_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_836 },
#else
    { 0, 0, output_836 },
#endif
    0,
    &operand_data[1496],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv4sf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_837 },
#else
    { 0, 0, output_837 },
#endif
    0,
    &operand_data[1498],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv2df_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_838 },
#else
    { 0, 0, output_838 },
#endif
    0,
    &operand_data[1500],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv32qi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_839 },
#else
    { 0, 0, output_839 },
#endif
    0,
    &operand_data[1502],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv16hi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_840 },
#else
    { 0, 0, output_840 },
#endif
    0,
    &operand_data[1504],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv8si_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_841 },
#else
    { 0, 0, output_841 },
#endif
    0,
    &operand_data[1506],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv4di_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_842 },
#else
    { 0, 0, output_842 },
#endif
    0,
    &operand_data[1508],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv8sf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_843 },
#else
    { 0, 0, output_843 },
#endif
    0,
    &operand_data[1510],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:177 */
  {
    "*avx_movv4df_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_844 },
#else
    { 0, 0, output_844 },
#endif
    0,
    &operand_data[1512],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv16qi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_845 },
#else
    { 0, 0, output_845 },
#endif
    0,
    &operand_data[1488],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv8hi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_846 },
#else
    { 0, 0, output_846 },
#endif
    0,
    &operand_data[1490],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv4si_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_847 },
#else
    { 0, 0, output_847 },
#endif
    0,
    &operand_data[1492],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv2di_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_848 },
#else
    { 0, 0, output_848 },
#endif
    0,
    &operand_data[1494],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv1ti_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_849 },
#else
    { 0, 0, output_849 },
#endif
    0,
    &operand_data[1496],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv4sf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_850 },
#else
    { 0, 0, output_850 },
#endif
    0,
    &operand_data[1498],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:221 */
  {
    "*movv2df_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_851 },
#else
    { 0, 0, output_851 },
#endif
    0,
    &operand_data[1500],
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:271 */
  {
    "movdi_to_sse",
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
    (insn_gen_fn) gen_movdi_to_sse,
    &operand_data[1514],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:357 */
  {
    "avx_movups",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovups\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movups,
    &operand_data[1517],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:357 */
  {
    "avx_movupd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovupd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movupd,
    &operand_data[1519],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:357 */
  {
    "avx_movups256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovups\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movups256,
    &operand_data[1521],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:357 */
  {
    "avx_movupd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovupd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movupd256,
    &operand_data[1523],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:370 */
  {
    "sse2_movq128",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movq128,
    &operand_data[1525],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:383 */
  {
    "sse_movups",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movups\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_movups,
    &operand_data[1517],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:383 */
  {
    "sse2_movupd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movupd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movupd,
    &operand_data[1519],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:395 */
  {
    "avx_movdqu256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovdqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movdqu256,
    &operand_data[1527],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:395 */
  {
    "avx_movdqu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovdqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movdqu,
    &operand_data[1529],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:407 */
  {
    "sse2_movdqu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movdqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movdqu,
    &operand_data[1529],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:418 */
  {
    "avx_movntv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv4sf,
    &operand_data[1531],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:418 */
  {
    "avx_movntv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv2df,
    &operand_data[1533],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:418 */
  {
    "avx_movntv8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv8sf,
    &operand_data[1535],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:418 */
  {
    "avx_movntv4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv4df,
    &operand_data[1537],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:429 */
  {
    "sse_movntv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_movntv4sf,
    &operand_data[1531],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:429 */
  {
    "sse2_movntv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movntv2df,
    &operand_data[1533],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:439 */
  {
    "avx_movntv4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv4di,
    &operand_data[1539],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:439 */
  {
    "avx_movntv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovntdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movntv2di,
    &operand_data[1541],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:450 */
  {
    "sse2_movntv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movntv2di,
    &operand_data[1541],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:460 */
  {
    "sse2_movntsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movnti\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movntsi,
    &operand_data[1543],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:470 */
  {
    "avx_lddqu256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vlddqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_lddqu256,
    &operand_data[1545],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:470 */
  {
    "avx_lddqu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vlddqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_lddqu,
    &operand_data[1547],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:482 */
  {
    "sse3_lddqu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lddqu\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_lddqu,
    &operand_data[1547],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_addv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_subv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1552],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_addv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_subv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1558],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_addv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_subv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1564],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_addv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:549 */
  {
    "*avx_subv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1570],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:569 */
  {
    "*addv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:569 */
  {
    "*subv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1576],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:569 */
  {
    "*addv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:569 */
  {
    "*subv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1582],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:580 */
  {
    "*avx_vmaddv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:580 */
  {
    "*avx_vmsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:580 */
  {
    "*avx_vmaddv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:580 */
  {
    "*avx_vmsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsubsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:594 */
  {
    "sse_vmaddv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmaddv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:594 */
  {
    "sse_vmsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmsubv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:594 */
  {
    "sse2_vmaddv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmaddv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:594 */
  {
    "sse2_vmsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmsubv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:615 */
  {
    "*avx_mulv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:615 */
  {
    "*avx_mulv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:615 */
  {
    "*avx_mulv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:615 */
  {
    "*avx_mulv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:635 */
  {
    "*mulv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:635 */
  {
    "*mulv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:646 */
  {
    "*avx_vmmulv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:646 */
  {
    "*avx_vmmulv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmulsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:660 */
  {
    "sse_vmmulv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmmulv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:660 */
  {
    "sse2_vmmulv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmmulv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:698 */
  {
    "avx_divv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_divv4sf3,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:698 */
  {
    "avx_divv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_divv2df3,
    &operand_data[1588],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:698 */
  {
    "avx_divv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_divv8sf3,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:698 */
  {
    "avx_divv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_divv4df3,
    &operand_data[1600],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:732 */
  {
    "*avx_divv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:732 */
  {
    "*avx_divv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:743 */
  {
    "sse_divv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "divps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_divv4sf3,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:743 */
  {
    "sse2_divv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "divpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_divv2df3,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:753 */
  {
    "*avx_vmdivv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:753 */
  {
    "*avx_vmdivv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdivsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:767 */
  {
    "sse_vmdivv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "divss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmdivv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:767 */
  {
    "sse2_vmdivv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "divsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmdivv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:780 */
  {
    "avx_rcpv8sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vrcpps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_rcpv8sf2,
    &operand_data[1603],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:790 */
  {
    "sse_rcpv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vrcpps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_rcpv4sf2,
    &operand_data[1605],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:801 */
  {
    "*avx_vmrcpv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vrcpss\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1605],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:814 */
  {
    "sse_vmrcpv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rcpss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmrcpv4sf2,
    &operand_data[1608],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:841 */
  {
    "avx_sqrtv8sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsqrtps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_sqrtv8sf2,
    &operand_data[1603],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:864 */
  {
    "sse_sqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vsqrtps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_sqrtv4sf2,
    &operand_data[1605],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:874 */
  {
    "sqrtv4df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsqrtpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sqrtv4df2,
    &operand_data[1611],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:883 */
  {
    "sqrtv2df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vsqrtpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sqrtv2df2,
    &operand_data[1613],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:892 */
  {
    "*avx_vmsqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsqrtss\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1605],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:892 */
  {
    "*avx_vmsqrtv2df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vsqrtsd\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1613],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:905 */
  {
    "sse_vmsqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sqrtss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmsqrtv4sf2,
    &operand_data[1608],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:905 */
  {
    "sse2_vmsqrtv2df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sqrtsd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmsqrtv2df2,
    &operand_data[1616],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:928 */
  {
    "avx_rsqrtv8sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vrsqrtps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_rsqrtv8sf2,
    &operand_data[1603],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:948 */
  {
    "sse_rsqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vrsqrtps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_rsqrtv4sf2,
    &operand_data[1605],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:958 */
  {
    "*avx_vmrsqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vrsqrtss\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1605],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:971 */
  {
    "sse_vmrsqrtv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrtss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmrsqrtv4sf2,
    &operand_data[1608],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_smaxv4sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_sminv4sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_smaxv2df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_sminv2df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_smaxv8sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_sminv8sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_smaxv4df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1011 */
  {
    "*avx_sminv4df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1023 */
  {
    "*smaxv4sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1023 */
  {
    "*sminv4sf3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1023 */
  {
    "*smaxv2df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1023 */
  {
    "*sminv2df3_finite",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_smaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_sminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_smaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_sminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_smaxv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_sminv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_smaxv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1034 */
  {
    "*avx_sminv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1045 */
  {
    "*smaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1045 */
  {
    "*sminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1045 */
  {
    "*smaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1045 */
  {
    "*sminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1055 */
  {
    "*avx_vmsmaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1055 */
  {
    "*avx_vmsminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1055 */
  {
    "*avx_vmsmaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1055 */
  {
    "*avx_vmsminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1069 */
  {
    "sse_vmsmaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmsmaxv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1069 */
  {
    "sse_vmsminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmsminv4sf3,
    &operand_data[1591],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1069 */
  {
    "sse2_vmsmaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmsmaxv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1069 */
  {
    "sse2_vmsminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmsminv2df3,
    &operand_data[1594],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1088 */
  {
    "*avx_ieee_sminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1088 */
  {
    "*avx_ieee_sminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1088 */
  {
    "*avx_ieee_sminv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1088 */
  {
    "*avx_ieee_sminv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vminpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1600],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1100 */
  {
    "*avx_ieee_smaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1100 */
  {
    "*avx_ieee_smaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1100 */
  {
    "*avx_ieee_smaxv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1100 */
  {
    "*avx_ieee_smaxv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaxpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1600],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1112 */
  {
    "*ieee_sminv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1112 */
  {
    "*ieee_sminv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "minpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1123 */
  {
    "*ieee_smaxv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1123 */
  {
    "*ieee_smaxv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maxpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1134 */
  {
    "avx_addsubv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_addsubv8sf3,
    &operand_data[1597],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1148 */
  {
    "avx_addsubv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_addsubv4df3,
    &operand_data[1600],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1162 */
  {
    "*avx_addsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1176 */
  {
    "sse3_addsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addsubps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_addsubv4sf3,
    &operand_data[1591],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1190 */
  {
    "*avx_addsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaddsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1204 */
  {
    "sse3_addsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addsubpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_addsubv2df3,
    &operand_data[1594],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1218 */
  {
    "avx_haddv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhaddpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_haddv4df3,
    &operand_data[1600],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1218 */
  {
    "avx_hsubv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_hsubv4df3,
    &operand_data[1600],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1245 */
  {
    "avx_haddv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhaddps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_haddv8sf3,
    &operand_data[1597],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1245 */
  {
    "avx_hsubv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_hsubv8sf3,
    &operand_data[1597],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1288 */
  {
    "*avx_haddv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhaddps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1288 */
  {
    "*avx_hsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhsubps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1315 */
  {
    "sse3_haddv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "haddps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_haddv4sf3,
    &operand_data[1591],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1315 */
  {
    "sse3_hsubv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "hsubps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_hsubv4sf3,
    &operand_data[1591],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1343 */
  {
    "*avx_haddv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhaddpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1343 */
  {
    "*avx_hsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vhsubpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1588],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1362 */
  {
    "sse3_haddv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "haddpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_haddv2df3,
    &operand_data[1594],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1362 */
  {
    "sse3_hsubv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "hsubpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_hsubv2df3,
    &operand_data[1594],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1429 */
  {
    "avx_cmppsv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmppsv4sf3,
    &operand_data[1619],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1429 */
  {
    "avx_cmppdv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmppdv2df3,
    &operand_data[1623],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1429 */
  {
    "avx_cmppsv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmppsv8sf3,
    &operand_data[1627],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1429 */
  {
    "avx_cmppdv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmppdv4df3,
    &operand_data[1631],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1443 */
  {
    "avx_cmpssv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmpss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmpssv4sf3,
    &operand_data[1635],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1443 */
  {
    "avx_cmpsdv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmpsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cmpsdv2df3,
    &operand_data[1639],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1462 */
  {
    "*avx_maskcmpv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1643],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1462 */
  {
    "*avx_maskcmpv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1647],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1462 */
  {
    "*avx_maskcmpv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3ps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1651],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1462 */
  {
    "*avx_maskcmpv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3pd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1655],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1474 */
  {
    "sse_maskcmpsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3ss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_maskcmpsf3,
    &operand_data[1659],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1474 */
  {
    "sse2_maskcmpdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3sd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_maskcmpdf3,
    &operand_data[1663],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1474 */
  {
    "sse_maskcmpv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3ps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_maskcmpv4sf3,
    &operand_data[1667],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1474 */
  {
    "sse2_maskcmpv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3pd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_maskcmpv2df3,
    &operand_data[1671],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1486 */
  {
    "*avx_vmmaskcmpv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3ss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1675],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1486 */
  {
    "*avx_vmmaskcmpv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcmp%D3sd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1679],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1500 */
  {
    "sse_vmmaskcmpv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3ss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_vmmaskcmpv4sf3,
    &operand_data[1667],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1500 */
  {
    "sse2_vmmaskcmpv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp%D3sd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_vmmaskcmpv2df3,
    &operand_data[1671],
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1514 */
  {
    "sse_comi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcomiss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_comi,
    &operand_data[1586],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1514 */
  {
    "sse2_comi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcomisd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_comi,
    &operand_data[1589],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1534 */
  {
    "sse_ucomi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vucomiss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_ucomi,
    &operand_data[1586],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1534 */
  {
    "sse2_ucomi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vucomisd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_ucomi,
    &operand_data[1589],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1575 */
  {
    "avx_andnotv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_andnotv4sf3,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1575 */
  {
    "avx_andnotv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_andnotv2df3,
    &operand_data[1588],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1575 */
  {
    "avx_andnotv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_andnotv8sf3,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1575 */
  {
    "avx_andnotv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_andnotv4df3,
    &operand_data[1600],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1587 */
  {
    "sse_andnotv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_andnotv4sf3,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1587 */
  {
    "sse2_andnotv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_andnotv2df3,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_andv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_iorv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_xorv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1549],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_andv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_iorv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_xorv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1555],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_andv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_iorv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_xorv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1561],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_andv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_iorv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1606 */
  {
    "*avx_xorv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1567],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*andv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*iorv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*xorv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1573],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*andv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*iorv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1626 */
  {
    "*xorv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1579],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1660 */
  {
    "*avx_andnotsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1294],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1660 */
  {
    "*avx_andnotdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1298],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1672 */
  {
    "*andnotsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1683],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1672 */
  {
    "*andnotdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1686],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_andsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1294],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_iorsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1294],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_xorsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1294],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_anddf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1298],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_iordf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1298],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1683 */
  {
    "*avx_xordf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1298],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*andsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1683],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*iorsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1683],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*xorsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1683],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*anddf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1686],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*iordf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1686],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1694 */
  {
    "*xordf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorpd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1686],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:1723 */
  {
    "fma4_fmaddv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1723 */
  {
    "fma4_fmaddv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1736 */
  {
    "fma4_fmsubv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1736 */
  {
    "fma4_fmsubv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1750 */
  {
    "fma4_fnmaddv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmaddv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1750 */
  {
    "fma4_fnmaddv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmaddv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1763 */
  {
    "fma4_fnmsubv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1763 */
  {
    "fma4_fnmsubv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1776 */
  {
    "fma4_fmaddsf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddsf4,
    &operand_data[1697],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1776 */
  {
    "fma4_fmadddf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmadddf4,
    &operand_data[1701],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1776 */
  {
    "fma4_fmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1776 */
  {
    "fma4_fmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1791 */
  {
    "fma4_vmfmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfmaddv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1791 */
  {
    "fma4_vmfmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfmaddv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1808 */
  {
    "fma4_fmsubsf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubsf4,
    &operand_data[1697],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1808 */
  {
    "fma4_fmsubdf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubdf4,
    &operand_data[1701],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1808 */
  {
    "fma4_fmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1808 */
  {
    "fma4_fmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1823 */
  {
    "fma4_vmfmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfmsubv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1823 */
  {
    "fma4_vmfmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfmsubv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1840 */
  {
    "fma4_fnmaddsf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmaddsf4,
    &operand_data[1697],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1840 */
  {
    "fma4_fnmadddf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmadddf4,
    &operand_data[1701],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1840 */
  {
    "fma4_fnmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmaddv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1840 */
  {
    "fma4_fnmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmaddv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1855 */
  {
    "fma4_vmfnmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfnmaddv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1855 */
  {
    "fma4_vmfnmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfnmaddv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1872 */
  {
    "fma4_fnmsubsf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubsf4,
    &operand_data[1697],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1872 */
  {
    "fma4_fnmsubdf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubdf4,
    &operand_data[1701],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1872 */
  {
    "fma4_fnmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1872 */
  {
    "fma4_fnmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fnmsubv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1888 */
  {
    "fma4_vmfnmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfnmsubv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1888 */
  {
    "fma4_vmfnmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_vmfnmsubv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1904 */
  {
    "fma4i_fmaddv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1904 */
  {
    "fma4i_fmaddv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1918 */
  {
    "fma4i_fmsubv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1918 */
  {
    "fma4i_fmsubv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1932 */
  {
    "fma4i_fnmaddv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmaddv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1932 */
  {
    "fma4i_fnmaddv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmaddv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1946 */
  {
    "fma4i_fnmsubv8sf4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmsubv8sf4256,
    &operand_data[1689],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1946 */
  {
    "fma4i_fnmsubv4df4256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmsubv4df4256,
    &operand_data[1693],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1961 */
  {
    "fma4i_fmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1961 */
  {
    "fma4i_fmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1975 */
  {
    "fma4i_fmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1975 */
  {
    "fma4i_fmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1989 */
  {
    "fma4i_fnmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmaddv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:1989 */
  {
    "fma4i_fnmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmaddv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2003 */
  {
    "fma4i_fnmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmsubv4sf4,
    &operand_data[1705],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2003 */
  {
    "fma4i_fnmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fnmsubv2df4,
    &operand_data[1709],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2020 */
  {
    "fma4i_vmfmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfmaddv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2020 */
  {
    "fma4i_vmfmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfmaddv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2037 */
  {
    "fma4i_vmfmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfmsubv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2037 */
  {
    "fma4i_vmfmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfmsubv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2054 */
  {
    "fma4i_vmfnmaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfnmaddv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2054 */
  {
    "fma4i_vmfnmaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmaddsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfnmaddv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2071 */
  {
    "fma4i_vmfnmsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfnmsubv4sf4,
    &operand_data[1705],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2071 */
  {
    "fma4i_vmfnmsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfnmsubsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_vmfnmsubv2df4,
    &operand_data[1709],
    4,
    1,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2095 */
  {
    "fma4_fmaddsubv8sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddsubv8sf4,
    &operand_data[1689],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2114 */
  {
    "fma4_fmaddsubv4df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddsubv4df4,
    &operand_data[1693],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2133 */
  {
    "fma4_fmaddsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddsubv4sf4,
    &operand_data[1705],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2152 */
  {
    "fma4_fmaddsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmaddsubv2df4,
    &operand_data[1709],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2171 */
  {
    "fma4_fmsubaddv8sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubaddv8sf4,
    &operand_data[1689],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2190 */
  {
    "fma4_fmsubaddv4df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubaddv4df4,
    &operand_data[1693],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2209 */
  {
    "fma4_fmsubaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubaddv4sf4,
    &operand_data[1705],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2228 */
  {
    "fma4_fmsubaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4_fmsubaddv2df4,
    &operand_data[1709],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2247 */
  {
    "fma4i_fmaddsubv8sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddsubv8sf4,
    &operand_data[1689],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2268 */
  {
    "fma4i_fmaddsubv4df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddsubv4df4,
    &operand_data[1693],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2289 */
  {
    "fma4i_fmaddsubv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddsubv4sf4,
    &operand_data[1705],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2310 */
  {
    "fma4i_fmaddsubv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmaddsubpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmaddsubv2df4,
    &operand_data[1709],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2331 */
  {
    "fma4i_fmsubaddv8sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubaddv8sf4,
    &operand_data[1689],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2352 */
  {
    "fma4i_fmsubaddv4df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubaddv4df4,
    &operand_data[1693],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2373 */
  {
    "fma4i_fmsubaddv4sf4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubaddv4sf4,
    &operand_data[1705],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2394 */
  {
    "fma4i_fmsubaddv2df4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfmsubaddpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fma4i_fmsubaddv2df4,
    &operand_data[1709],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2421 */
  {
    "sse_cvtpi2ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtpi2ps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvtpi2ps,
    &operand_data[1713],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2433 */
  {
    "sse_cvtps2pi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtps2pi\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvtps2pi,
    &operand_data[1716],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2445 */
  {
    "sse_cvttps2pi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvttps2pi\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvttps2pi,
    &operand_data[1716],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2457 */
  {
    "*avx_cvtsi2ss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtsi2ss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1718],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2470 */
  {
    "sse_cvtsi2ss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtsi2ss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvtsi2ss,
    &operand_data[1721],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2513 */
  {
    "sse_cvtss2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtss2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvtss2si,
    &operand_data[1724],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2528 */
  {
    "sse_cvtss2si_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtss2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvtss2si_2,
    &operand_data[208],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2569 */
  {
    "sse_cvttss2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttss2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_cvttss2si,
    &operand_data[1724],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2599 */
  {
    "avx_cvtdq2ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtdq2ps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtdq2ps,
    &operand_data[1726],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2599 */
  {
    "avx_cvtdq2ps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtdq2ps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtdq2ps256,
    &operand_data[1728],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2609 */
  {
    "sse2_cvtdq2ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtdq2ps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtdq2ps,
    &operand_data[1726],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2642 */
  {
    "avx_cvtps2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtps2dq,
    &operand_data[1730],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2642 */
  {
    "avx_cvtps2dq256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtps2dq256,
    &operand_data[1732],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2653 */
  {
    "sse2_cvtps2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtps2dq,
    &operand_data[1730],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2663 */
  {
    "avx_cvttps2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvttps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvttps2dq,
    &operand_data[1730],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2663 */
  {
    "avx_cvttps2dq256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvttps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvttps2dq256,
    &operand_data[1732],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2673 */
  {
    "sse2_cvttps2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvttps2dq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvttps2dq,
    &operand_data[1730],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2689 */
  {
    "sse2_cvtpi2pd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtpi2pd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtpi2pd,
    &operand_data[1734],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2699 */
  {
    "sse2_cvtpd2pi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtpd2pi\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtpd2pi,
    &operand_data[1736],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2710 */
  {
    "sse2_cvttpd2pi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvttpd2pi\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvttpd2pi,
    &operand_data[1736],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2720 */
  {
    "*avx_cvtsi2sd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtsi2sd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1738],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2733 */
  {
    "sse2_cvtsi2sd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtsi2sd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtsi2sd,
    &operand_data[1741],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2776 */
  {
    "sse2_cvtsd2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsd2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtsd2si,
    &operand_data[1744],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2791 */
  {
    "sse2_cvtsd2si_2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtsd2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtsd2si_2,
    &operand_data[210],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2832 */
  {
    "sse2_cvttsd2si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvttsd2si\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvttsd2si,
    &operand_data[1744],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2862 */
  {
    "avx_cvtdq2pd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtdq2pd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtdq2pd256,
    &operand_data[1746],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2871 */
  {
    "sse2_cvtdq2pd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtdq2pd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtdq2pd,
    &operand_data[1748],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2883 */
  {
    "avx_cvtpd2dq256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtpd2dq{y}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtpd2dq256,
    &operand_data[1750],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2902 */
  {
    "*sse2_cvtpd2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1158 },
#else
    { 0, 0, output_1158 },
#endif
    0,
    &operand_data[1752],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:2918 */
  {
    "avx_cvttpd2dq256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvttpd2dq{y}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvttpd2dq256,
    &operand_data[1750],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2935 */
  {
    "*sse2_cvttpd2dq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1160 },
#else
    { 0, 0, output_1160 },
#endif
    0,
    &operand_data[1752],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:2948 */
  {
    "*avx_cvtsd2ss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtsd2ss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1755],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2962 */
  {
    "sse2_cvtsd2ss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtsd2ss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtsd2ss,
    &operand_data[1758],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:2977 */
  {
    "*avx_cvtss2sd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtss2sd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1761],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:2992 */
  {
    "sse2_cvtss2sd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvtss2sd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtss2sd,
    &operand_data[1764],
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:3007 */
  {
    "avx_cvtpd2ps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtpd2ps{y}\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtpd2ps256,
    &operand_data[1767],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3026 */
  {
    "*sse2_cvtpd2ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1166 },
#else
    { 0, 0, output_1166 },
#endif
    0,
    &operand_data[1769],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3041 */
  {
    "avx_cvtps2pd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vcvtps2pd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_cvtps2pd256,
    &operand_data[1772],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3051 */
  {
    "sse2_cvtps2pd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vcvtps2pd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_cvtps2pd,
    &operand_data[1774],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3304 */
  {
    "*avx_movhlps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1169 },
#else
    { 0, output_1169, 0 },
#endif
    0,
    &operand_data[1776],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3323 */
  {
    "sse_movhlps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1170 },
#else
    { 0, output_1170, 0 },
#endif
    (insn_gen_fn) gen_sse_movhlps,
    &operand_data[1779],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3354 */
  {
    "*avx_movlhps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1171 },
#else
    { 0, output_1171, 0 },
#endif
    0,
    &operand_data[1782],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3373 */
  {
    "sse_movlhps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1172 },
#else
    { 0, output_1172, 0 },
#endif
    (insn_gen_fn) gen_sse_movlhps,
    &operand_data[1785],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3392 */
  {
    "avx_unpckhps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vunpckhps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_unpckhps256,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3408 */
  {
    "*avx_interleave_highv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vunpckhps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3422 */
  {
    "vec_interleave_highv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "unpckhps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_highv4sf,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3436 */
  {
    "avx_unpcklps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vunpcklps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_unpcklps256,
    &operand_data[1597],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3452 */
  {
    "*avx_interleave_lowv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vunpcklps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1585],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3466 */
  {
    "vec_interleave_lowv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "unpcklps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_lowv4sf,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3481 */
  {
    "avx_movshdup256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovshdup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movshdup256,
    &operand_data[1603],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3497 */
  {
    "sse3_movshdup",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovshdup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_movshdup,
    &operand_data[1605],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3514 */
  {
    "avx_movsldup256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovsldup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movsldup256,
    &operand_data[1603],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3530 */
  {
    "sse3_movsldup",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovsldup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_movsldup,
    &operand_data[1605],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3568 */
  {
    "avx_shufps256_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1183 },
#else
    { 0, 0, output_1183 },
#endif
    (insn_gen_fn) gen_avx_shufps256_1,
    &operand_data[1788],
    11,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3618 */
  {
    "*avx_shufps_v4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1184 },
#else
    { 0, 0, output_1184 },
#endif
    0,
    &operand_data[1799],
    7,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3618 */
  {
    "*avx_shufps_v4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1185 },
#else
    { 0, 0, output_1185 },
#endif
    0,
    &operand_data[1806],
    7,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3644 */
  {
    "sse_shufps_v4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1186 },
#else
    { 0, 0, output_1186 },
#endif
    (insn_gen_fn) gen_sse_shufps_v4sf,
    &operand_data[1813],
    7,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3644 */
  {
    "sse_shufps_v4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1187 },
#else
    { 0, 0, output_1187 },
#endif
    (insn_gen_fn) gen_sse_shufps_v4si,
    &operand_data[1820],
    7,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:3669 */
  {
    "sse_storehps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1188 },
#else
    { 0, output_1188, 0 },
#endif
    (insn_gen_fn) gen_sse_storehps,
    &operand_data[1827],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3693 */
  {
    "*avx_loadhps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1189 },
#else
    { 0, output_1189, 0 },
#endif
    0,
    &operand_data[1829],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3709 */
  {
    "sse_loadhps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1190 },
#else
    { 0, output_1190, 0 },
#endif
    (insn_gen_fn) gen_sse_loadhps,
    &operand_data[1832],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3724 */
  {
    "*avx_storelps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1191 },
#else
    { 0, output_1191, 0 },
#endif
    0,
    &operand_data[1835],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3738 */
  {
    "sse_storelps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1192 },
#else
    { 0, output_1192, 0 },
#endif
    (insn_gen_fn) gen_sse_storelps,
    &operand_data[1835],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3761 */
  {
    "*avx_loadlps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1193 },
#else
    { 0, output_1193, 0 },
#endif
    0,
    &operand_data[1837],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3778 */
  {
    "sse_loadlps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1194 },
#else
    { 0, output_1194, 0 },
#endif
    (insn_gen_fn) gen_sse_loadlps,
    &operand_data[1840],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:3794 */
  {
    "*avx_movss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovss\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1843],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3806 */
  {
    "sse_movss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_movss,
    &operand_data[1846],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3827 */
  {
    "*vec_dupv4sf_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1197 },
#else
    { 0, output_1197, 0 },
#endif
    0,
    &operand_data[1849],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:3841 */
  {
    "*vec_dupv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "shufps\t{$0, %0, %0|%0, %0, 0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1851],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:3851 */
  {
    "*vec_concatv2sf_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1199 },
#else
    { 0, output_1199, 0 },
#endif
    0,
    &operand_data[1853],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:3874 */
  {
    "*vec_concatv2sf_sse4_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1200 },
#else
    { 0, output_1200, 0 },
#endif
    0,
    &operand_data[1856],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:3895 */
  {
    "*vec_concatv2sf_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1201 },
#else
    { 0, output_1201, 0 },
#endif
    0,
    &operand_data[1859],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:3909 */
  {
    "*vec_concatv4sf_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1202 },
#else
    { 0, output_1202, 0 },
#endif
    0,
    &operand_data[1862],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:3922 */
  {
    "*vec_concatv4sf_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1203 },
#else
    { 0, output_1203, 0 },
#endif
    0,
    &operand_data[1865],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:3943 */
  {
    "*vec_setv4sf_0_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1204 },
#else
    { 0, output_1204, 0 },
#endif
    0,
    &operand_data[1868],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:3943 */
  {
    "*vec_setv4si_0_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1205 },
#else
    { 0, output_1205, 0 },
#endif
    0,
    &operand_data[1871],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:3965 */
  {
    "*vec_setv4sf_0_sse4_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1206 },
#else
    { 0, output_1206, 0 },
#endif
    0,
    &operand_data[1874],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:3965 */
  {
    "*vec_setv4si_0_sse4_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1207 },
#else
    { 0, output_1207, 0 },
#endif
    0,
    &operand_data[1877],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:3986 */
  {
    "*vec_setv4sf_0_sse2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1208 },
#else
    { 0, output_1208, 0 },
#endif
    0,
    &operand_data[1880],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:3986 */
  {
    "*vec_setv4si_0_sse2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1209 },
#else
    { 0, output_1209, 0 },
#endif
    0,
    &operand_data[1883],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:4003 */
  {
    "vec_setv4sf_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1210 },
#else
    { 0, output_1210, 0 },
#endif
    (insn_gen_fn) gen_vec_setv4sf_0,
    &operand_data[1886],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4003 */
  {
    "vec_setv4si_0",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1211 },
#else
    { 0, output_1211, 0 },
#endif
    (insn_gen_fn) gen_vec_setv4si_0,
    &operand_data[1889],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4020 */
  {
    "*vec_setv4sf_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1212 },
#else
    { 0, 0, output_1212 },
#endif
    0,
    &operand_data[1892],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4038 */
  {
    "*vec_setv4sf_sse4_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1213 },
#else
    { 0, 0, output_1213 },
#endif
    0,
    &operand_data[1896],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4056 */
  {
    "*avx_insertps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1900],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4070 */
  {
    "sse4_1_insertps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "insertps\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_insertps,
    &operand_data[1904],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4109 */
  {
    "*vec_extractv4sf_0",
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
    &operand_data[1908],
    2,
    0,
    4,
    1
  },
  /* ../../gcc/config/i386/sse.md:4148 */
  {
    "vec_extract_lo_v4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v4di,
    &operand_data[1910],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4148 */
  {
    "vec_extract_lo_v4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v4df,
    &operand_data[1912],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4162 */
  {
    "vec_extract_hi_v4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v4di,
    &operand_data[1910],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4162 */
  {
    "vec_extract_hi_v4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v4df,
    &operand_data[1912],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4176 */
  {
    "vec_extract_lo_v8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v8si,
    &operand_data[1914],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4176 */
  {
    "vec_extract_lo_v8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v8sf,
    &operand_data[1916],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4191 */
  {
    "vec_extract_hi_v8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v8si,
    &operand_data[1914],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4191 */
  {
    "vec_extract_hi_v8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v8sf,
    &operand_data[1916],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4206 */
  {
    "vec_extract_lo_v16hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v16hi,
    &operand_data[1918],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4223 */
  {
    "vec_extract_hi_v16hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v16hi,
    &operand_data[1918],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4240 */
  {
    "vec_extract_lo_v32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x0, %1, %0|%0, %1, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_lo_v32qi,
    &operand_data[1920],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4261 */
  {
    "vec_extract_hi_v32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vextractf128\t{$0x1, %1, %0|%0, %1, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_extract_hi_v32qi,
    &operand_data[1920],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:4282 */
  {
    "*sse4_1_extractps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vextractps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1922],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4296 */
  {
    "*vec_extract_v4sf_mem",
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
    &operand_data[1925],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4330 */
  {
    "avx_unpckhpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vunpckhpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_unpckhpd256,
    &operand_data[1600],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4358 */
  {
    "*avx_interleave_highv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1232 },
#else
    { 0, output_1232, 0 },
#endif
    0,
    &operand_data[1928],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:4376 */
  {
    "*sse3_interleave_highv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1233 },
#else
    { 0, output_1233, 0 },
#endif
    0,
    &operand_data[1931],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:4394 */
  {
    "*sse2_interleave_highv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1234 },
#else
    { 0, output_1234, 0 },
#endif
    0,
    &operand_data[1934],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4434 */
  {
    "*avx_unpcklpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1235 },
#else
    { 0, output_1235, 0 },
#endif
    0,
    &operand_data[1937],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:4465 */
  {
    "*avx_interleave_lowv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1236 },
#else
    { 0, output_1236, 0 },
#endif
    0,
    &operand_data[1940],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:4483 */
  {
    "*sse3_interleave_lowv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1237 },
#else
    { 0, output_1237, 0 },
#endif
    0,
    &operand_data[1943],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:4501 */
  {
    "*sse2_interleave_lowv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1238 },
#else
    { 0, output_1238, 0 },
#endif
    0,
    &operand_data[1946],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4565 */
  {
    "avx_shufpd256_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1239 },
#else
    { 0, 0, output_1239 },
#endif
    (insn_gen_fn) gen_avx_shufpd256_1,
    &operand_data[1949],
    7,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4626 */
  {
    "*avx_interleave_highv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpckhqdq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4640 */
  {
    "vec_interleave_highv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhqdq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_highv2di,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4654 */
  {
    "*avx_interleave_lowv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpcklqdq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4668 */
  {
    "vec_interleave_lowv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpcklqdq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_lowv2di,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:4682 */
  {
    "*avx_shufpd_v2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1244 },
#else
    { 0, 0, output_1244 },
#endif
    0,
    &operand_data[1962],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4682 */
  {
    "*avx_shufpd_v2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1245 },
#else
    { 0, 0, output_1245 },
#endif
    0,
    &operand_data[1967],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4704 */
  {
    "sse2_shufpd_v2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1246 },
#else
    { 0, 0, output_1246 },
#endif
    (insn_gen_fn) gen_sse2_shufpd_v2df,
    &operand_data[1972],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4704 */
  {
    "sse2_shufpd_v2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1247 },
#else
    { 0, 0, output_1247 },
#endif
    (insn_gen_fn) gen_sse2_shufpd_v2di,
    &operand_data[1977],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:4727 */
  {
    "*avx_storehpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1248 },
#else
    { 0, output_1248, 0 },
#endif
    0,
    &operand_data[1982],
    2,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:4743 */
  {
    "sse2_storehpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1249 },
#else
    { 0, output_1249, 0 },
#endif
    (insn_gen_fn) gen_sse2_storehpd,
    &operand_data[1984],
    2,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:4772 */
  {
    "sse2_storelpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1250 },
#else
    { 0, output_1250, 0 },
#endif
    (insn_gen_fn) gen_sse2_storelpd,
    &operand_data[1986],
    2,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:4818 */
  {
    "*avx_loadhpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1251 },
#else
    { 0, output_1251, 0 },
#endif
    0,
    &operand_data[1988],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:4836 */
  {
    "sse2_loadhpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1252 },
#else
    { 0, output_1252, 0 },
#endif
    (insn_gen_fn) gen_sse2_loadhpd,
    &operand_data[1991],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:4879 */
  {
    "*avx_loadlpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1253 },
#else
    { 0, output_1253, 0 },
#endif
    0,
    &operand_data[1994],
    3,
    0,
    7,
    2
  },
  /* ../../gcc/config/i386/sse.md:4899 */
  {
    "sse2_loadlpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1254 },
#else
    { 0, output_1254, 0 },
#endif
    (insn_gen_fn) gen_sse2_loadlpd,
    &operand_data[1997],
    3,
    0,
    8,
    2
  },
  /* ../../gcc/config/i386/sse.md:4934 */
  {
    "*vec_extractv2df_1_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1255 },
#else
    { 0, output_1255, 0 },
#endif
    0,
    &operand_data[2000],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4948 */
  {
    "*vec_extractv2df_0_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1256 },
#else
    { 0, output_1256, 0 },
#endif
    0,
    &operand_data[2002],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:4962 */
  {
    "*avx_movsd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1257 },
#else
    { 0, output_1257, 0 },
#endif
    0,
    &operand_data[2004],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:4979 */
  {
    "sse2_movsd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1258 },
#else
    { 0, output_1258, 0 },
#endif
    (insn_gen_fn) gen_sse2_movsd,
    &operand_data[2007],
    3,
    0,
    6,
    2
  },
  /* ../../gcc/config/i386/sse.md:4998 */
  {
    "*vec_dupv2df_sse3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovddup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2010],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5008 */
  {
    "vec_dupv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "unpcklpd\t%0, %0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_dupv2df,
    &operand_data[2012],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5017 */
  {
    "*vec_concatv2df_sse3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovddup\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2010],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5028 */
  {
    "*vec_concatv2df_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1262 },
#else
    { 0, output_1262, 0 },
#endif
    0,
    &operand_data[2014],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:5042 */
  {
    "*vec_concatv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1263 },
#else
    { 0, output_1263, 0 },
#endif
    0,
    &operand_data[2017],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_addv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_subv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2023],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_addv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_subv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2029],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_addv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_subv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2035],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_addv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2038],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5080 */
  {
    "*avx_subv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2041],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*addv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*subv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2047],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*addv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*subv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2053],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*addv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*subv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2059],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*addv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5091 */
  {
    "*subv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2065],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_ssaddv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddsb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_usaddv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddusb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_sssubv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubsb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2023],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_ussubv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubusb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2023],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_ssaddv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_usaddv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpaddusw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_sssubv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2029],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5110 */
  {
    "*avx_ussubv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsubusw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2029],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_ssaddv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_usaddv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddusb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_sssubv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2047],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_ussubv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubusb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2047],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_ssaddv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_usaddv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "paddusw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_sssubv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2053],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5121 */
  {
    "*sse2_ussubv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psubusw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2053],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5132 */
  {
    "mulv16qi3",
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
    (insn_gen_fn) gen_mulv16qi3,
    &operand_data[2068],
    3,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:5179 */
  {
    "*avx_mulv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmullw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5189 */
  {
    "*mulv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmullw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5212 */
  {
    "*avxv8hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmulhw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5228 */
  {
    "*smulv8hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5257 */
  {
    "*avx_umulv8hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmulhuw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5273 */
  {
    "*umulv8hi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhuw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5303 */
  {
    "*avx_umulv2siv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmuludq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2071],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5320 */
  {
    "*sse2_umulv2siv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmuludq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2074],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5351 */
  {
    "*avx_mulv2siv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmuldq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2071],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5369 */
  {
    "*sse4_1_mulv2siv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmuldq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2074],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5420 */
  {
    "*avx_pmaddwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaddwd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2077],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5457 */
  {
    "*sse2_pmaddwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaddwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2080],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5505 */
  {
    "*avx_mulv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmulld\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5516 */
  {
    "*sse4_1_mulv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulld\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5526 */
  {
    "*sse2_mulv4si3",
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
    &operand_data[2083],
    3,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:5579 */
  {
    "mulv2di3",
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
    (insn_gen_fn) gen_mulv2di3,
    &operand_data[2086],
    3,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:5871 */
  {
    "*avx_ashrv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsraw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2089],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5871 */
  {
    "*avx_ashrv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsrad\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2092],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5886 */
  {
    "ashrv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psraw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ashrv8hi3,
    &operand_data[2095],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5886 */
  {
    "ashrv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrad\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ashrv4si3,
    &operand_data[2098],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5901 */
  {
    "*avx_lshrv1ti3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1317 },
#else
    { 0, 0, output_1317 },
#endif
    0,
    &operand_data[2101],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:5916 */
  {
    "*avx_lshrv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsrlw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2089],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5916 */
  {
    "*avx_lshrv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsrld\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2092],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5916 */
  {
    "*avx_lshrv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsrlq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2104],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5931 */
  {
    "sse2_lshrv1ti3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1321 },
#else
    { 0, 0, output_1321 },
#endif
    (insn_gen_fn) gen_sse2_lshrv1ti3,
    &operand_data[2107],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:5947 */
  {
    "lshrv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrlw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_lshrv8hi3,
    &operand_data[2095],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5947 */
  {
    "lshrv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrld\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_lshrv4si3,
    &operand_data[2098],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5947 */
  {
    "lshrv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psrlq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_lshrv2di3,
    &operand_data[2110],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5962 */
  {
    "*avx_ashlv1ti3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1325 },
#else
    { 0, 0, output_1325 },
#endif
    0,
    &operand_data[2101],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:5976 */
  {
    "*avx_ashlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsllw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2089],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5976 */
  {
    "*avx_ashlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpslld\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2092],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5976 */
  {
    "*avx_ashlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsllq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2104],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:5991 */
  {
    "sse2_ashlv1ti3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1329 },
#else
    { 0, 0, output_1329 },
#endif
    (insn_gen_fn) gen_sse2_ashlv1ti3,
    &operand_data[2107],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6005 */
  {
    "ashlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psllw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ashlv8hi3,
    &operand_data[2095],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6005 */
  {
    "ashlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pslld\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ashlv4si3,
    &operand_data[2098],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6005 */
  {
    "ashlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psllq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ashlv2di3,
    &operand_data[2110],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_smaxv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxsb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_sminv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminsb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_umaxv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxub\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_uminv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminub\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_smaxv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_sminv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_umaxv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxuw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_uminv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminuw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_smaxv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_sminv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminsd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_umaxv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaxud\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6042 */
  {
    "*avx_uminv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpminud\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6067 */
  {
    "*umaxv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxub\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6067 */
  {
    "*uminv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminub\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6086 */
  {
    "*smaxv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6086 */
  {
    "*sminv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6141 */
  {
    "*sse4_1_smaxv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6141 */
  {
    "*sse4_1_sminv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminsb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6141 */
  {
    "*sse4_1_smaxv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6141 */
  {
    "*sse4_1_sminv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6197 */
  {
    "*sse4_1_umaxv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxuw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6197 */
  {
    "*sse4_1_uminv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminuw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6197 */
  {
    "*sse4_1_umaxv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaxud\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6197 */
  {
    "*sse4_1_uminv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pminud\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6332 */
  {
    "*avx_eqv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpeqb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6332 */
  {
    "*avx_eqv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpeqw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6332 */
  {
    "*avx_eqv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpeqd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6332 */
  {
    "*avx_eqv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpeqq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2038],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6347 */
  {
    "*sse2_eqv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6347 */
  {
    "*sse2_eqv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6347 */
  {
    "*sse2_eqv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6367 */
  {
    "*sse4_1_eqv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpeqq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6378 */
  {
    "*avx_gtv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpgtb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6378 */
  {
    "*avx_gtv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpgtw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6378 */
  {
    "*avx_gtv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpgtd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6378 */
  {
    "*avx_gtv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmpgtq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6393 */
  {
    "sse2_gtv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_gtv16qi3,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6393 */
  {
    "sse2_gtv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_gtv8hi3,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6393 */
  {
    "sse2_gtv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_gtv4si3,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6404 */
  {
    "sse4_2_gtv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pcmpgtq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_gtv2di3,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6466 */
  {
    "*avx_andnotv32qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2125],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6466 */
  {
    "*avx_andnotv16hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2128],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6466 */
  {
    "*avx_andnotv8si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2131],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6466 */
  {
    "*avx_andnotv4di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandnps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2134],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6477 */
  {
    "*sse_andnotv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6477 */
  {
    "*sse_andnotv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6477 */
  {
    "*sse_andnotv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6477 */
  {
    "*sse_andnotv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andnps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6487 */
  {
    "*avx_andnotv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpandn\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6487 */
  {
    "*avx_andnotv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpandn\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6487 */
  {
    "*avx_andnotv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpandn\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6487 */
  {
    "*avx_andnotv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpandn\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6498 */
  {
    "sse2_andnotv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_andnotv16qi3,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6498 */
  {
    "sse2_andnotv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_andnotv8hi3,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6498 */
  {
    "sse2_andnotv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_andnotv4si3,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6498 */
  {
    "sse2_andnotv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_andnotv2di3,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6509 */
  {
    "*andnottf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pandn\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2137],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_andv32qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2140],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_iorv32qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2140],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_xorv32qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2140],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_andv16hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2143],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_iorv16hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2143],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_xorv16hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2143],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_andv8si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2146],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_iorv8si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2146],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_xorv8si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2146],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_andv4di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vandps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2149],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_iorv4di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2149],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6528 */
  {
    "*avx_xorv4di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vxorps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2149],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_andv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_iorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_xorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_andv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_iorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_xorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_andv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_iorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_xorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_andv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_iorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "orps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6540 */
  {
    "*sse_xorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "xorps\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_andv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpand\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_iorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_xorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpxor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_andv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpand\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_iorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_xorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpxor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_andv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpand\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_iorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_xorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpxor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2032],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_andv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpand\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2038],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_iorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2038],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6551 */
  {
    "*avx_xorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpxor\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2038],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_andv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_iorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_xorv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_andv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_iorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_xorv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_andv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_iorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_xorv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2056],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_andv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_iorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6563 */
  {
    "*sse2_xorv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2062],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6582 */
  {
    "*andtf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pand\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2152],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6582 */
  {
    "*iortf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "por\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2152],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6582 */
  {
    "*xortf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pxor\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2152],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6635 */
  {
    "*avx_packsswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpacksswb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2155],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6648 */
  {
    "sse2_packsswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packsswb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_packsswb,
    &operand_data[2158],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6661 */
  {
    "*avx_packssdw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpackssdw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2161],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6674 */
  {
    "sse2_packssdw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packssdw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_packssdw,
    &operand_data[2164],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6687 */
  {
    "*avx_packuswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpackuswb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2155],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6700 */
  {
    "sse2_packuswb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packuswb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_packuswb,
    &operand_data[2158],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6713 */
  {
    "*avx_interleave_highv16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpckhbw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6733 */
  {
    "vec_interleave_highv16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_highv16qi,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6753 */
  {
    "*avx_interleave_lowv16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpcklbw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6773 */
  {
    "vec_interleave_lowv16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpcklbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_lowv16qi,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6793 */
  {
    "*avx_interleave_highv8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpckhwd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6809 */
  {
    "vec_interleave_highv8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_highv8hi,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6825 */
  {
    "*avx_interleave_lowv8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpcklwd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6841 */
  {
    "vec_interleave_lowv8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpcklwd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_lowv8hi,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6857 */
  {
    "*avx_interleave_highv4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpckhdq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6871 */
  {
    "vec_interleave_highv4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckhdq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_highv4si,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6885 */
  {
    "*avx_interleave_lowv4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpunpckldq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6899 */
  {
    "vec_interleave_lowv4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "punpckldq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_interleave_lowv4si,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:6913 */
  {
    "*avx_pinsrb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1459 },
#else
    { 0, 0, output_1459 },
#endif
    0,
    &operand_data[2167],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6913 */
  {
    "*avx_pinsrw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1460 },
#else
    { 0, 0, output_1460 },
#endif
    0,
    &operand_data[2171],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6913 */
  {
    "*avx_pinsrd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1461 },
#else
    { 0, 0, output_1461 },
#endif
    0,
    &operand_data[2175],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6937 */
  {
    "*sse4_1_pinsrb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1462 },
#else
    { 0, 0, output_1462 },
#endif
    0,
    &operand_data[2179],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6957 */
  {
    "*sse2_pinsrw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1463 },
#else
    { 0, 0, output_1463 },
#endif
    0,
    &operand_data[2183],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:6978 */
  {
    "*sse4_1_pinsrd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1464 },
#else
    { 0, 0, output_1464 },
#endif
    0,
    &operand_data[2187],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:7031 */
  {
    "*sse4_1_pextrb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpextrb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2191],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7045 */
  {
    "*sse4_1_pextrb_memory",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpextrb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2194],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7058 */
  {
    "*sse2_pextrw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpextrw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2197],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7072 */
  {
    "*sse4_1_pextrw_memory",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpextrw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2200],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7085 */
  {
    "*sse4_1_pextrd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpextrd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2203],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7128 */
  {
    "sse2_pshufd_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1470 },
#else
    { 0, 0, output_1470 },
#endif
    (insn_gen_fn) gen_sse2_pshufd_1,
    &operand_data[2206],
    6,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:7168 */
  {
    "sse2_pshuflw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1471 },
#else
    { 0, 0, output_1471 },
#endif
    (insn_gen_fn) gen_sse2_pshuflw_1,
    &operand_data[2212],
    6,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:7213 */
  {
    "sse2_pshufhw_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1472 },
#else
    { 0, 0, output_1472 },
#endif
    (insn_gen_fn) gen_sse2_pshufhw_1,
    &operand_data[2218],
    6,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:7253 */
  {
    "*avx_loadld",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1473 },
#else
    { 0, output_1473, 0 },
#endif
    0,
    &operand_data[2224],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:7269 */
  {
    "sse2_loadld",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1474 },
#else
    { 0, output_1474, 0 },
#endif
    (insn_gen_fn) gen_sse2_loadld,
    &operand_data[2227],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:7285 */
  {
    "sse2_stored",
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
    (insn_gen_fn) gen_sse2_stored,
    &operand_data[2230],
    2,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:7301 */
  {
    "*vec_ext_v4si_mem",
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
    &operand_data[2232],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7339 */
  {
    "*sse2_storeq",
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
    &operand_data[2235],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7397 */
  {
    "*vec_extractv2di_1_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1478 },
#else
    { 0, output_1478, 0 },
#endif
    0,
    &operand_data[2237],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:7415 */
  {
    "*vec_extractv2di_1_sse2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1479 },
#else
    { 0, output_1479, 0 },
#endif
    0,
    &operand_data[2239],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:7432 */
  {
    "*vec_extractv2di_1_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1480 },
#else
    { 0, output_1480, 0 },
#endif
    0,
    &operand_data[2237],
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:7446 */
  {
    "*vec_dupv4si_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1481 },
#else
    { 0, output_1481, 0 },
#endif
    0,
    &operand_data[2241],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7460 */
  {
    "*vec_dupv4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1482 },
#else
    { 0, output_1482, 0 },
#endif
    0,
    &operand_data[2243],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7472 */
  {
    "*vec_dupv2di_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1483 },
#else
    { 0, output_1483, 0 },
#endif
    0,
    &operand_data[2245],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7484 */
  {
    "*vec_dupv2di_sse3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1484 },
#else
    { 0, output_1484, 0 },
#endif
    0,
    &operand_data[2247],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7495 */
  {
    "*vec_dupv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1485 },
#else
    { 0, output_1485, 0 },
#endif
    0,
    &operand_data[2249],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7506 */
  {
    "*vec_concatv2si_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1486 },
#else
    { 0, output_1486, 0 },
#endif
    0,
    &operand_data[2251],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:7527 */
  {
    "*vec_concatv2si_sse4_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1487 },
#else
    { 0, output_1487, 0 },
#endif
    0,
    &operand_data[2254],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:7547 */
  {
    "*vec_concatv2si_sse2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1488 },
#else
    { 0, output_1488, 0 },
#endif
    0,
    &operand_data[2257],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:7561 */
  {
    "*vec_concatv2si_sse",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1489 },
#else
    { 0, output_1489, 0 },
#endif
    0,
    &operand_data[2260],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:7575 */
  {
    "*vec_concatv4si_1_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1490 },
#else
    { 0, output_1490, 0 },
#endif
    0,
    &operand_data[2263],
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:7588 */
  {
    "*vec_concatv4si_1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1491 },
#else
    { 0, output_1491, 0 },
#endif
    0,
    &operand_data[2266],
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:7601 */
  {
    "*vec_concatv2di_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1492 },
#else
    { 0, output_1492, 0 },
#endif
    0,
    &operand_data[2269],
    3,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:7619 */
  {
    "vec_concatv2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1493 },
#else
    { 0, output_1493, 0 },
#endif
    (insn_gen_fn) gen_vec_concatv2di,
    &operand_data[2272],
    3,
    0,
    5,
    2
  },
  /* ../../gcc/config/i386/sse.md:7865 */
  {
    "*avx_uavgv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpavgb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2020],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7890 */
  {
    "*sse2_uavgv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pavgb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2044],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7933 */
  {
    "*avx_uavgv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpavgw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7954 */
  {
    "*sse2_uavgv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pavgw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7977 */
  {
    "*avx_psadbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsadbw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2275],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:7988 */
  {
    "sse2_psadbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psadbw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_psadbw,
    &operand_data[2278],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8000 */
  {
    "avx_movmskps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovmskps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movmskps256,
    &operand_data[2281],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8000 */
  {
    "avx_movmskpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmovmskpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_movmskpd256,
    &operand_data[2283],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8011 */
  {
    "sse_movmskps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovmskps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_movmskps,
    &operand_data[2285],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8011 */
  {
    "sse2_movmskpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovmskpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_movmskpd,
    &operand_data[2287],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8022 */
  {
    "sse2_pmovmskb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovmskb\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_pmovmskb,
    &operand_data[2191],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8042 */
  {
    "*sse2_maskmovdqu",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmaskmovdqu\t{%2, %1|%1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2289],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8075 */
  {
    "sse_ldmxcsr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vldmxcsr\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_ldmxcsr,
    &operand_data[45],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8085 */
  {
    "sse_stmxcsr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vstmxcsr\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse_stmxcsr,
    &operand_data[221],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8104 */
  {
    "*sse_sfence",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sfence",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[884],
    1,
    1,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:8114 */
  {
    "sse2_clflush",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "clflush\t%a0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse2_clflush,
    &operand_data[2292],
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8132 */
  {
    "*sse2_mfence",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mfence",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[884],
    1,
    1,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:8151 */
  {
    "*sse2_lfence",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lfence",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[884],
    1,
    1,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:8161 */
  {
    "sse3_mwait",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mwait",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_mwait,
    &operand_data[2293],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8172 */
  {
    "sse3_monitor",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "monitor\t%0, %1, %2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse3_monitor,
    &operand_data[2293],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8199 */
  {
    "*avx_phaddwv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8243 */
  {
    "ssse3_phaddwv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phaddwv8hi3,
    &operand_data[2122],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8288 */
  {
    "ssse3_phaddwv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phaddwv4hi3,
    &operand_data[1441],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8317 */
  {
    "*avx_phadddv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8345 */
  {
    "ssse3_phadddv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phadddv4si3,
    &operand_data[1820],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8374 */
  {
    "ssse3_phadddv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phadddv2si3,
    &operand_data[1444],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8395 */
  {
    "*avx_phaddswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8439 */
  {
    "ssse3_phaddswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phaddswv8hi3,
    &operand_data[2122],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8484 */
  {
    "ssse3_phaddswv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phaddsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phaddswv4hi3,
    &operand_data[1441],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8513 */
  {
    "*avx_phsubwv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8557 */
  {
    "ssse3_phsubwv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubwv8hi3,
    &operand_data[2122],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8602 */
  {
    "ssse3_phsubwv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubwv4hi3,
    &operand_data[1441],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8631 */
  {
    "*avx_phsubdv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8659 */
  {
    "ssse3_phsubdv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubdv4si3,
    &operand_data[1820],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8688 */
  {
    "ssse3_phsubdv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubdv2si3,
    &operand_data[1444],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8709 */
  {
    "*avx_phsubswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8753 */
  {
    "ssse3_phsubswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubswv8hi3,
    &operand_data[2122],
    3,
    14,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8798 */
  {
    "ssse3_phsubswv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "phsubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_phsubswv4hi3,
    &operand_data[1441],
    3,
    6,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8827 */
  {
    "*avx_pmaddubsw128",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmaddubsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2296],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8881 */
  {
    "ssse3_pmaddubsw128",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaddubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_pmaddubsw128,
    &operand_data[2299],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8936 */
  {
    "ssse3_pmaddubsw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmaddubsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_pmaddubsw,
    &operand_data[2302],
    3,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:8995 */
  {
    "*avx_pmulhrswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmulhrsw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2026],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9019 */
  {
    "*ssse3_pmulhrswv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhrsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2050],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9061 */
  {
    "*ssse3_pmulhrswv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pmulhrsw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1405],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9083 */
  {
    "*avx_pshufbv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshufb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9095 */
  {
    "ssse3_pshufbv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pshufb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_pshufbv16qi3,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9107 */
  {
    "ssse3_pshufbv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pshufb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_pshufbv8qi3,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9119 */
  {
    "*avx_psignv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsignb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2113],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9119 */
  {
    "*avx_psignv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsignw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2116],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9119 */
  {
    "*avx_psignv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpsignd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1806],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9132 */
  {
    "ssse3_psignv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv16qi3,
    &operand_data[2119],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9132 */
  {
    "ssse3_psignv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv8hi3,
    &operand_data[2122],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9132 */
  {
    "ssse3_psignv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv4si3,
    &operand_data[1820],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9145 */
  {
    "ssse3_psignv8qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignb\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv8qi3,
    &operand_data[1438],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9145 */
  {
    "ssse3_psignv4hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv4hi3,
    &operand_data[1441],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9145 */
  {
    "ssse3_psignv2si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "psignd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_ssse3_psignv2si3,
    &operand_data[1444],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9158 */
  {
    "*avx_palignrti",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1550 },
#else
    { 0, 0, output_1550 },
#endif
    0,
    &operand_data[2305],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:9175 */
  {
    "ssse3_palignrti",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1551 },
#else
    { 0, 0, output_1551 },
#endif
    (insn_gen_fn) gen_ssse3_palignrti,
    &operand_data[2309],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:9193 */
  {
    "ssse3_palignrdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1552 },
#else
    { 0, 0, output_1552 },
#endif
    (insn_gen_fn) gen_ssse3_palignrdi,
    &operand_data[2313],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:9211 */
  {
    "absv16qi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpabsb\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv16qi2,
    &operand_data[2317],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9211 */
  {
    "absv8hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpabsw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv8hi2,
    &operand_data[2212],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9211 */
  {
    "absv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpabsd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv4si2,
    &operand_data[2206],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9222 */
  {
    "absv8qi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pabsb\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv8qi2,
    &operand_data[2319],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9222 */
  {
    "absv4hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pabsw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv4hi2,
    &operand_data[1460],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9222 */
  {
    "absv2si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pabsd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv2si2,
    &operand_data[1466],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9239 */
  {
    "sse4a_movntsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_movntsf,
    &operand_data[2321],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9239 */
  {
    "sse4a_movntdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntsd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_movntdf,
    &operand_data[2323],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9249 */
  {
    "sse4a_vmmovntv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntss\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_vmmovntv4sf,
    &operand_data[2325],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9249 */
  {
    "sse4a_vmmovntv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "movntsd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_vmmovntv2df,
    &operand_data[2327],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9261 */
  {
    "sse4a_extrqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "extrq\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_extrqi,
    &operand_data[2329],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9274 */
  {
    "sse4a_extrq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "extrq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_extrq,
    &operand_data[2333],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9285 */
  {
    "sse4a_insertqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "insertq\t{%4, %3, %2, %0|%0, %2, %3, %4}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_insertqi,
    &operand_data[2336],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9300 */
  {
    "sse4a_insertq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "insertq\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4a_insertq,
    &operand_data[2336],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9318 */
  {
    "avx_blendps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendps,
    &operand_data[2341],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9318 */
  {
    "avx_blendpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendpd,
    &operand_data[2345],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9318 */
  {
    "avx_blendps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendps256,
    &operand_data[2349],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9318 */
  {
    "avx_blendpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendpd256,
    &operand_data[2353],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9332 */
  {
    "avx_blendvps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendvps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendvps,
    &operand_data[2357],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9332 */
  {
    "avx_blendvpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendvpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendvpd,
    &operand_data[2361],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9332 */
  {
    "avx_blendvps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendvps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendvps256,
    &operand_data[2365],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9332 */
  {
    "avx_blendvpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vblendvpd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_blendvpd256,
    &operand_data[2369],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9347 */
  {
    "sse4_1_blendps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "blendps\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_blendps,
    &operand_data[2373],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9347 */
  {
    "sse4_1_blendpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "blendpd\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_blendpd,
    &operand_data[2377],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9361 */
  {
    "sse4_1_blendvps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "blendvps\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_blendvps,
    &operand_data[2381],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9361 */
  {
    "sse4_1_blendvpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "blendvpd\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_blendvpd,
    &operand_data[2385],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9375 */
  {
    "avx_dpps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_dpps,
    &operand_data[2389],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9375 */
  {
    "avx_dppd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_dppd,
    &operand_data[2393],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9375 */
  {
    "avx_dpps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdpps\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_dpps256,
    &operand_data[2397],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9375 */
  {
    "avx_dppd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vdppd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_dppd256,
    &operand_data[2401],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9390 */
  {
    "sse4_1_dpps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpps\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_dpps,
    &operand_data[2405],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9390 */
  {
    "sse4_1_dppd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dppd\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_dppd,
    &operand_data[2409],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9405 */
  {
    "sse4_1_movntdqa",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vmovntdqa\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_movntdqa,
    &operand_data[2413],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9416 */
  {
    "*avx_mpsadbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmpsadbw\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2415],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9430 */
  {
    "sse4_1_mpsadbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mpsadbw\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_mpsadbw,
    &operand_data[2419],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9443 */
  {
    "*avx_packusdw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpackusdw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2161],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9457 */
  {
    "sse4_1_packusdw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packusdw\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_packusdw,
    &operand_data[2164],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9470 */
  {
    "*avx_pblendvb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpblendvb\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2423],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9484 */
  {
    "sse4_1_pblendvb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pblendvb\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_pblendvb,
    &operand_data[2427],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9496 */
  {
    "*avx_pblendw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpblendw\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2431],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9510 */
  {
    "sse4_1_pblendw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pblendw\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_pblendw,
    &operand_data[2435],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9523 */
  {
    "sse4_1_phminposuw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vphminposuw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_phminposuw,
    &operand_data[2212],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9534 */
  {
    "sse4_1_extendv8qiv8hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv8qiv8hi2,
    &operand_data[2296],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9554 */
  {
    "*sse4_1_extendv8qiv8hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2439],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9575 */
  {
    "sse4_1_extendv4qiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv4qiv4si2,
    &operand_data[2441],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9591 */
  {
    "*sse4_1_extendv4qiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2443],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9608 */
  {
    "sse4_1_extendv2qiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv2qiv2di2,
    &operand_data[2275],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9622 */
  {
    "*sse4_1_extendv2qiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxbq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2445],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9637 */
  {
    "sse4_1_extendv4hiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv4hiv4si2,
    &operand_data[2447],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9653 */
  {
    "*sse4_1_extendv4hiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2449],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9670 */
  {
    "sse4_1_extendv2hiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv2hiv2di2,
    &operand_data[2451],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9684 */
  {
    "*sse4_1_extendv2hiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2453],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9699 */
  {
    "sse4_1_extendv2siv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_extendv2siv2di2,
    &operand_data[2455],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9713 */
  {
    "*sse4_1_extendv2siv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovsxdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2457],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9728 */
  {
    "sse4_1_zero_extendv8qiv8hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv8qiv8hi2,
    &operand_data[2296],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9748 */
  {
    "*sse4_1_zero_extendv8qiv8hi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2439],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9769 */
  {
    "sse4_1_zero_extendv4qiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv4qiv4si2,
    &operand_data[2441],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9785 */
  {
    "*sse4_1_zero_extendv4qiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2443],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9802 */
  {
    "sse4_1_zero_extendv2qiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv2qiv2di2,
    &operand_data[2275],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9816 */
  {
    "*sse4_1_zero_extendv2qiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxbq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2445],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9831 */
  {
    "sse4_1_zero_extendv4hiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv4hiv4si2,
    &operand_data[2447],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9847 */
  {
    "*sse4_1_zero_extendv4hiv4si2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2459],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9864 */
  {
    "sse4_1_zero_extendv2hiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv2hiv2di2,
    &operand_data[2451],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9878 */
  {
    "*sse4_1_zero_extendv2hiv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2461],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9893 */
  {
    "sse4_1_zero_extendv2siv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_zero_extendv2siv2di2,
    &operand_data[2455],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9907 */
  {
    "*sse4_1_zero_extendv2siv2di2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpmovzxdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2457],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9924 */
  {
    "avx_vtestps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vtestps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vtestps,
    &operand_data[1586],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9924 */
  {
    "avx_vtestpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vtestpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vtestpd,
    &operand_data[1589],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9924 */
  {
    "avx_vtestps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vtestps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vtestps256,
    &operand_data[1598],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9924 */
  {
    "avx_vtestpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vtestpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vtestpd256,
    &operand_data[1601],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9938 */
  {
    "avx_ptest256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vptest\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_ptest256,
    &operand_data[2135],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9950 */
  {
    "sse4_1_ptest",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vptest\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_ptest,
    &operand_data[1957],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9962 */
  {
    "avx_roundps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vroundps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_roundps256,
    &operand_data[2463],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9962 */
  {
    "avx_roundpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vroundpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_roundpd256,
    &operand_data[2466],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9976 */
  {
    "sse4_1_roundps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vroundps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_roundps,
    &operand_data[2469],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9976 */
  {
    "sse4_1_roundpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vroundpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_roundpd,
    &operand_data[2472],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9991 */
  {
    "*avx_roundss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vroundss\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2475],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:9991 */
  {
    "*avx_roundsd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vroundsd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2479],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10008 */
  {
    "sse4_1_roundss",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "roundss\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_roundss,
    &operand_data[2483],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10008 */
  {
    "sse4_1_roundsd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "roundsd\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_1_roundsd,
    &operand_data[2487],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10031 */
  {
    "sse4_2_pcmpestr",
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
    (insn_gen_fn) gen_sse4_2_pcmpestr,
    &operand_data[2491],
    7,
    10,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10088 */
  {
    "sse4_2_pcmpestri",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpcmpestri\t{%5, %3, %1|%1, %3, %5}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpestri,
    &operand_data[2498],
    6,
    5,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10115 */
  {
    "sse4_2_pcmpestrm",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpcmpestrm\t{%5, %3, %1|%1, %3, %5}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpestrm,
    &operand_data[2504],
    6,
    5,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10142 */
  {
    "sse4_2_pcmpestr_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1636 },
#else
    { 0, output_1636, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpestr_cconly,
    &operand_data[2510],
    7,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:10167 */
  {
    "sse4_2_pcmpistr",
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
    (insn_gen_fn) gen_sse4_2_pcmpistr,
    &operand_data[2517],
    5,
    6,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10215 */
  {
    "sse4_2_pcmpistri",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpcmpistri\t{%3, %2, %1|%1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpistri,
    &operand_data[2522],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10238 */
  {
    "sse4_2_pcmpistrm",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vpcmpistrm\t{%3, %2, %1|%1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpistrm,
    &operand_data[2526],
    4,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10261 */
  {
    "sse4_2_pcmpistr_cconly",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1640 },
#else
    { 0, output_1640, 0 },
#endif
    (insn_gen_fn) gen_sse4_2_pcmpistr_cconly,
    &operand_data[2530],
    5,
    0,
    4,
    2
  },
  /* ../../gcc/config/i386/sse.md:10294 */
  {
    "xop_pmacsww",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacsww\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacsww,
    &operand_data[2535],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10306 */
  {
    "xop_pmacssww",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacssww\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacssww,
    &operand_data[2535],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10317 */
  {
    "xop_pmacsdd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacsdd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacsdd,
    &operand_data[2539],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10329 */
  {
    "xop_pmacssdd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacssdd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacssdd,
    &operand_data[2539],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10340 */
  {
    "xop_pmacssdql",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacssdql\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacssdql,
    &operand_data[2543],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10359 */
  {
    "xop_pmacssdqh",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacssdqh\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacssdqh,
    &operand_data[2543],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10379 */
  {
    "xop_pmacsdql",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacsdql\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacsdql,
    &operand_data[2543],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10403 */
  {
    "xop_mulv2div2di3_low",
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
    (insn_gen_fn) gen_xop_mulv2div2di3_low,
    &operand_data[2547],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10441 */
  {
    "xop_pmacsdqh",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacsdqh\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacsdqh,
    &operand_data[2543],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10465 */
  {
    "xop_mulv2div2di3_high",
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
    (insn_gen_fn) gen_xop_mulv2div2di3_high,
    &operand_data[2547],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10504 */
  {
    "xop_pmacsswd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacsswd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacsswd,
    &operand_data[2550],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10528 */
  {
    "xop_pmacswd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmacswd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmacswd,
    &operand_data[2550],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10552 */
  {
    "xop_pmadcsswd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmadcsswd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmadcsswd,
    &operand_data[2550],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10592 */
  {
    "xop_pmadcswd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpmadcswd\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pmadcswd,
    &operand_data[2550],
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v16qi,
    &operand_data[2554],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v8hi,
    &operand_data[2558],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v4si,
    &operand_data[2562],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v2di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v2di,
    &operand_data[2566],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v4sf,
    &operand_data[2570],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10633 */
  {
    "xop_pcmov_v2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v2df,
    &operand_data[2574],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v32qi256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v32qi256,
    &operand_data[2578],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v16hi256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v16hi256,
    &operand_data[2582],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v8si256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v8si256,
    &operand_data[2586],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v4di256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v4di256,
    &operand_data[2590],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v8sf256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v8sf256,
    &operand_data[2594],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10643 */
  {
    "xop_pcmov_v4df256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcmov\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pcmov_v4df256,
    &operand_data[2598],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:10654 */
  {
    "xop_phaddbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddbw,
    &operand_data[2602],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10683 */
  {
    "xop_phaddbd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddbd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddbd,
    &operand_data[2604],
    2,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10720 */
  {
    "xop_phaddbq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddbq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddbq,
    &operand_data[2606],
    2,
    7,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10773 */
  {
    "xop_phaddwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddwd,
    &operand_data[2608],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10794 */
  {
    "xop_phaddwq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddwq,
    &operand_data[2453],
    2,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10823 */
  {
    "xop_phadddq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphadddq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phadddq,
    &operand_data[2610],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10840 */
  {
    "xop_phaddubw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddubw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddubw,
    &operand_data[2602],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10869 */
  {
    "xop_phaddubd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddubd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddubd,
    &operand_data[2604],
    2,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10906 */
  {
    "xop_phaddubq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddubq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddubq,
    &operand_data[2606],
    2,
    7,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10959 */
  {
    "xop_phadduwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphadduwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phadduwd,
    &operand_data[2608],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:10980 */
  {
    "xop_phadduwq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphadduwq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phadduwq,
    &operand_data[2453],
    2,
    3,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11009 */
  {
    "xop_phaddudq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphaddudq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phaddudq,
    &operand_data[2610],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11026 */
  {
    "xop_phsubbw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubbw\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phsubbw,
    &operand_data[2602],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11055 */
  {
    "xop_phsubwd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubwd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phsubwd,
    &operand_data[2608],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11076 */
  {
    "xop_phsubdq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vphsubdq\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_phsubdq,
    &operand_data[2610],
    2,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11094 */
  {
    "xop_pperm",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpperm\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pperm,
    &operand_data[2612],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11107 */
  {
    "xop_pperm_pack_v2di_v4si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpperm\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pperm_pack_v2di_v4si,
    &operand_data[2616],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11120 */
  {
    "xop_pperm_pack_v4si_v8hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpperm\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pperm_pack_v4si_v8hi,
    &operand_data[2620],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11133 */
  {
    "xop_pperm_pack_v8hi_v16qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpperm\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_pperm_pack_v8hi_v16qi,
    &operand_data[2624],
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11211 */
  {
    "xop_rotlv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_rotlv16qi3,
    &operand_data[2628],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11211 */
  {
    "xop_rotlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_rotlv8hi3,
    &operand_data[2631],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11211 */
  {
    "xop_rotlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_rotlv4si3,
    &operand_data[2634],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11211 */
  {
    "xop_rotlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_rotlv2di3,
    &operand_data[2637],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11222 */
  {
    "xop_rotrv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1690 },
#else
    { 0, 0, output_1690 },
#endif
    (insn_gen_fn) gen_xop_rotrv16qi3,
    &operand_data[2628],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11222 */
  {
    "xop_rotrv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1691 },
#else
    { 0, 0, output_1691 },
#endif
    (insn_gen_fn) gen_xop_rotrv8hi3,
    &operand_data[2631],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11222 */
  {
    "xop_rotrv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1692 },
#else
    { 0, 0, output_1692 },
#endif
    (insn_gen_fn) gen_xop_rotrv4si3,
    &operand_data[2634],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11222 */
  {
    "xop_rotrv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1693 },
#else
    { 0, 0, output_1693 },
#endif
    (insn_gen_fn) gen_xop_rotrv2di3,
    &operand_data[2637],
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11258 */
  {
    "xop_vrotlv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vrotlv16qi3,
    &operand_data[2640],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11258 */
  {
    "xop_vrotlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vrotlv8hi3,
    &operand_data[2643],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11258 */
  {
    "xop_vrotlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vrotlv4si3,
    &operand_data[2646],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11258 */
  {
    "xop_vrotlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vprotq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vrotlv2di3,
    &operand_data[2649],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11313 */
  {
    "xop_ashlv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshab\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_ashlv16qi3,
    &operand_data[2640],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11313 */
  {
    "xop_ashlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshaw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_ashlv8hi3,
    &operand_data[2643],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11313 */
  {
    "xop_ashlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshad\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_ashlv4si3,
    &operand_data[2646],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11313 */
  {
    "xop_ashlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshaq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_ashlv2di3,
    &operand_data[2649],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11332 */
  {
    "xop_lshlv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshlb\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_lshlv16qi3,
    &operand_data[2640],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11332 */
  {
    "xop_lshlv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshlw\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_lshlv8hi3,
    &operand_data[2643],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11332 */
  {
    "xop_lshlv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshld\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_lshlv4si3,
    &operand_data[2646],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11332 */
  {
    "xop_lshlv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpshlq\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_lshlv2di3,
    &operand_data[2649],
    3,
    3,
    2,
    1
  },
  /* ../../gcc/config/i386/sse.md:11454 */
  {
    "xop_frczv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_frczv4sf2,
    &operand_data[1605],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11454 */
  {
    "xop_frczv2df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_frczv2df2,
    &operand_data[1613],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11465 */
  {
    "xop_vmfrczv4sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczss\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vmfrczv4sf2,
    &operand_data[1591],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11465 */
  {
    "xop_vmfrczv2df2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczsd\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vmfrczv2df2,
    &operand_data[1594],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11478 */
  {
    "xop_frczv8sf2256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczps\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_frczv8sf2256,
    &operand_data[1603],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11478 */
  {
    "xop_frczv4df2256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vfrczpd\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_frczv4df2256,
    &operand_data[1611],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11488 */
  {
    "xop_maskcmpv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1b\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmpv16qi3,
    &operand_data[2652],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11488 */
  {
    "xop_maskcmpv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1w\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmpv8hi3,
    &operand_data[2656],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11488 */
  {
    "xop_maskcmpv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1d\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmpv4si3,
    &operand_data[2660],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11488 */
  {
    "xop_maskcmpv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1q\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmpv2di3,
    &operand_data[2664],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11502 */
  {
    "xop_maskcmp_unsv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1ub\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_unsv16qi3,
    &operand_data[2668],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11502 */
  {
    "xop_maskcmp_unsv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1uw\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_unsv8hi3,
    &operand_data[2672],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11502 */
  {
    "xop_maskcmp_unsv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1ud\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_unsv4si3,
    &operand_data[2676],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11502 */
  {
    "xop_maskcmp_unsv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1uq\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_unsv2di3,
    &operand_data[2680],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11519 */
  {
    "xop_maskcmp_uns2v16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1ub\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_uns2v16qi3,
    &operand_data[2668],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11519 */
  {
    "xop_maskcmp_uns2v8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1uw\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_uns2v8hi3,
    &operand_data[2672],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11519 */
  {
    "xop_maskcmp_uns2v4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1ud\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_uns2v4si3,
    &operand_data[2676],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11519 */
  {
    "xop_maskcmp_uns2v2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpcom%Y1uq\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_maskcmp_uns2v2di3,
    &operand_data[2680],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11536 */
  {
    "xop_pcom_tfv16qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1724 },
#else
    { 0, 0, output_1724 },
#endif
    (insn_gen_fn) gen_xop_pcom_tfv16qi3,
    &operand_data[2684],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11536 */
  {
    "xop_pcom_tfv8hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1725 },
#else
    { 0, 0, output_1725 },
#endif
    (insn_gen_fn) gen_xop_pcom_tfv8hi3,
    &operand_data[2688],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11536 */
  {
    "xop_pcom_tfv4si3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1726 },
#else
    { 0, 0, output_1726 },
#endif
    (insn_gen_fn) gen_xop_pcom_tfv4si3,
    &operand_data[2692],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11536 */
  {
    "xop_pcom_tfv2di3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1727 },
#else
    { 0, 0, output_1727 },
#endif
    (insn_gen_fn) gen_xop_pcom_tfv2di3,
    &operand_data[2696],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11555 */
  {
    "xop_vpermil2v4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermil2ps\t{%4, %3, %2, %1, %0|%0, %1, %2, %3, %4}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vpermil2v4sf3,
    &operand_data[2700],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11555 */
  {
    "xop_vpermil2v2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermil2pd\t{%4, %3, %2, %1, %0|%0, %1, %2, %3, %4}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vpermil2v2df3,
    &operand_data[2705],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11555 */
  {
    "xop_vpermil2v8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermil2ps\t{%4, %3, %2, %1, %0|%0, %1, %2, %3, %4}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vpermil2v8sf3,
    &operand_data[2710],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11555 */
  {
    "xop_vpermil2v4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermil2pd\t{%4, %3, %2, %1, %0|%0, %1, %2, %3, %4}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_xop_vpermil2v4df3,
    &operand_data[2715],
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11570 */
  {
    "*avx_aesenc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaesenc\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11582 */
  {
    "aesenc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "aesenc\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aesenc,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11593 */
  {
    "*avx_aesenclast",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaesenclast\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11605 */
  {
    "aesenclast",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "aesenclast\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aesenclast,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11616 */
  {
    "*avx_aesdec",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaesdec\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11628 */
  {
    "aesdec",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "aesdec\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aesdec,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11639 */
  {
    "*avx_aesdeclast",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vaesdeclast\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1956],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11651 */
  {
    "aesdeclast",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "aesdeclast\t{%2, %0|%0, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aesdeclast,
    &operand_data[1959],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11662 */
  {
    "aesimc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vaesimc\t{%1, %0|%0, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aesimc,
    &operand_data[1525],
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11673 */
  {
    "aeskeygenassist",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%vaeskeygenassist\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_aeskeygenassist,
    &operand_data[2720],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11686 */
  {
    "*vpclmulqdq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpclmulqdq\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2723],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11700 */
  {
    "pclmulqdq",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pclmulqdq\t{%3, %2, %0|%0, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_pclmulqdq,
    &operand_data[2727],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11733 */
  {
    "*avx_vzeroall",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vzeroall",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2731],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:11764 */
  {
    "*avx_vzeroupper",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vzeroupper",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2732],
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/i386/sse.md:11775 */
  {
    "vec_dupv8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1746 },
#else
    { 0, output_1746, 0 },
#endif
    (insn_gen_fn) gen_vec_dupv8si,
    &operand_data[2733],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:11775 */
  {
    "vec_dupv8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1747 },
#else
    { 0, output_1747, 0 },
#endif
    (insn_gen_fn) gen_vec_dupv8sf,
    &operand_data[2735],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:11775 */
  {
    "vec_dupv4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1748 },
#else
    { 0, output_1748, 0 },
#endif
    (insn_gen_fn) gen_vec_dupv4di,
    &operand_data[2737],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:11775 */
  {
    "vec_dupv4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1749 },
#else
    { 0, output_1749, 0 },
#endif
    (insn_gen_fn) gen_vec_dupv4df,
    &operand_data[2739],
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1750 },
#else
    { 0, output_1750, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v32qi,
    &operand_data[2741],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v16hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1751 },
#else
    { 0, output_1751, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v16hi,
    &operand_data[2743],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1752 },
#else
    { 0, output_1752, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v8si,
    &operand_data[2745],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1753 },
#else
    { 0, output_1753, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v4di,
    &operand_data[2747],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1754 },
#else
    { 0, output_1754, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v8sf,
    &operand_data[2749],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11794 */
  {
    "avx_vbroadcastf128_v4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_1755 },
#else
    { 0, output_1755, 0 },
#endif
    (insn_gen_fn) gen_avx_vbroadcastf128_v4df,
    &operand_data[2751],
    2,
    1,
    3,
    2
  },
  /* ../../gcc/config/i386/sse.md:11813 */
  {
    "*avx_vperm_broadcast_v4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1756 },
#else
    { 0, 0, output_1756 },
#endif
    0,
    &operand_data[2753],
    4,
    0,
    3,
    3
  },
  /* ../../gcc/config/i386/sse.md:11841 */
  {
    "*avx_vperm_broadcast_v8sf",
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
    &operand_data[2757],
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/sse.md:11841 */
  {
    "*avx_vperm_broadcast_v4df",
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
    &operand_data[2761],
    4,
    0,
    3,
    1
  },
  /* ../../gcc/config/i386/sse.md:11925 */
  {
    "*avx_vpermilpv4sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1759 },
#else
    { 0, 0, output_1759 },
#endif
    0,
    &operand_data[2765],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11925 */
  {
    "*avx_vpermilpv2df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1760 },
#else
    { 0, 0, output_1760 },
#endif
    0,
    &operand_data[2769],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11925 */
  {
    "*avx_vpermilpv8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1761 },
#else
    { 0, 0, output_1761 },
#endif
    0,
    &operand_data[2773],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11925 */
  {
    "*avx_vpermilpv4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1762 },
#else
    { 0, 0, output_1762 },
#endif
    0,
    &operand_data[2777],
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:11943 */
  {
    "avx_vpermilvarv4sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermilps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vpermilvarv4sf3,
    &operand_data[2781],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11943 */
  {
    "avx_vpermilvarv2df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermilpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vpermilvarv2df3,
    &operand_data[2784],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11943 */
  {
    "avx_vpermilvarv8sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermilps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vpermilvarv8sf3,
    &operand_data[2787],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11943 */
  {
    "avx_vpermilvarv4df3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vpermilpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_vpermilvarv4df3,
    &operand_data[2790],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11993 */
  {
    "*avx_vperm2f128v8si_full",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2793],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11993 */
  {
    "*avx_vperm2f128v8sf_full",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2349],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:11993 */
  {
    "*avx_vperm2f128v4df_full",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vperm2f128\t{%3, %2, %1, %0|%0, %1, %2, %3}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[2797],
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12008 */
  {
    "*avx_vperm2f128v8si_nozero",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1770 },
#else
    { 0, 0, output_1770 },
#endif
    0,
    &operand_data[2801],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:12008 */
  {
    "*avx_vperm2f128v8sf_nozero",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1771 },
#else
    { 0, 0, output_1771 },
#endif
    0,
    &operand_data[2806],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:12008 */
  {
    "*avx_vperm2f128v4df_nozero",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1772 },
#else
    { 0, 0, output_1772 },
#endif
    0,
    &operand_data[2811],
    5,
    0,
    1,
    3
  },
  /* ../../gcc/config/i386/sse.md:12051 */
  {
    "vec_set_lo_v4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v4di,
    &operand_data[2816],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12051 */
  {
    "vec_set_lo_v4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v4df,
    &operand_data[2819],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12066 */
  {
    "vec_set_hi_v4di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v4di,
    &operand_data[2816],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12066 */
  {
    "vec_set_hi_v4df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v4df,
    &operand_data[2819],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12081 */
  {
    "vec_set_lo_v8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v8si,
    &operand_data[2822],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12081 */
  {
    "vec_set_lo_v8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v8sf,
    &operand_data[2825],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12097 */
  {
    "vec_set_hi_v8si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v8si,
    &operand_data[2822],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12097 */
  {
    "vec_set_hi_v8sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v8sf,
    &operand_data[2825],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12113 */
  {
    "vec_set_lo_v16hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v16hi,
    &operand_data[2828],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12131 */
  {
    "vec_set_hi_v16hi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v16hi,
    &operand_data[2828],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12149 */
  {
    "vec_set_lo_v32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x0, %2, %1, %0|%0, %1, %2, 0x0}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_lo_v32qi,
    &operand_data[2831],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12171 */
  {
    "vec_set_hi_v32qi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vinsertf128\t{$0x1, %2, %1, %0|%0, %1, %2, 0x1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_vec_set_hi_v32qi,
    &operand_data[2831],
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12193 */
  {
    "avx_maskloadps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovps\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskloadps,
    &operand_data[2834],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12193 */
  {
    "avx_maskloadpd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovpd\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskloadpd,
    &operand_data[2837],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12193 */
  {
    "avx_maskloadps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovps\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskloadps256,
    &operand_data[2840],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12193 */
  {
    "avx_maskloadpd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovpd\t{%1, %2, %0|%0, %2, %1}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskloadpd256,
    &operand_data[2843],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12207 */
  {
    "avx_maskstoreps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskstoreps,
    &operand_data[2846],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12207 */
  {
    "avx_maskstorepd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskstorepd,
    &operand_data[2849],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12207 */
  {
    "avx_maskstoreps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovps\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskstoreps256,
    &operand_data[2852],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12207 */
  {
    "avx_maskstorepd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "vmaskmovpd\t{%2, %1, %0|%0, %1, %2}",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_avx_maskstorepd256,
    &operand_data[2855],
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/i386/sse.md:12221 */
  {
    "avx_si256_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1793 },
#else
    { 0, 0, output_1793 },
#endif
    (insn_gen_fn) gen_avx_si256_si,
    &operand_data[2858],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12221 */
  {
    "avx_ps256_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1794 },
#else
    { 0, 0, output_1794 },
#endif
    (insn_gen_fn) gen_avx_ps256_ps,
    &operand_data[2860],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12221 */
  {
    "avx_pd256_pd",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1795 },
#else
    { 0, 0, output_1795 },
#endif
    (insn_gen_fn) gen_avx_pd256_pd,
    &operand_data[2862],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12257 */
  {
    "avx_si_si256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1796 },
#else
    { 0, 0, output_1796 },
#endif
    (insn_gen_fn) gen_avx_si_si256,
    &operand_data[2864],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12257 */
  {
    "avx_ps_ps256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1797 },
#else
    { 0, 0, output_1797 },
#endif
    (insn_gen_fn) gen_avx_ps_ps256,
    &operand_data[2866],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12257 */
  {
    "avx_pd_pd256",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1798 },
#else
    { 0, 0, output_1798 },
#endif
    (insn_gen_fn) gen_avx_pd_pd256,
    &operand_data[2868],
    2,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12302 */
  {
    "*vec_concatv32qi_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1799 },
#else
    { 0, 0, output_1799 },
#endif
    0,
    &operand_data[2870],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12302 */
  {
    "*vec_concatv16hi_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1800 },
#else
    { 0, 0, output_1800 },
#endif
    0,
    &operand_data[2873],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12302 */
  {
    "*vec_concatv8si_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1801 },
#else
    { 0, 0, output_1801 },
#endif
    0,
    &operand_data[2876],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12302 */
  {
    "*vec_concatv4di_avx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_1802 },
#else
    { 0, 0, output_1802 },
#endif
    0,
    &operand_data[2879],
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/i386/sse.md:12302 */
  {
#else