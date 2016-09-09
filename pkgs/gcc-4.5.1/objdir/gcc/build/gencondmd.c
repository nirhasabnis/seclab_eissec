/* Generated automatically by the program `genconditions' from the target
   machine description file.  */

#include "bconfig.h"
#include "system.h"

/* It is necessary, but not entirely safe, to include the headers below
   in a generator program.  As a defensive measure, don't do so when the
   table isn't going to have anything in it.  */
#if GCC_VERSION >= 3001

/* Do not allow checking to confuse the issue.  */
#undef ENABLE_CHECKING
#undef ENABLE_TREE_CHECKING
#undef ENABLE_RTL_CHECKING
#undef ENABLE_RTL_FLAG_CHECKING
#undef ENABLE_GC_CHECKING
#undef ENABLE_GC_ALWAYS_COLLECT

#include "coretypes.h"
#include "tm.h"
#include "insn-constants.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"

/* Fake - insn-config.h doesn't exist yet.  */
#define MAX_RECOG_OPERANDS 10
#define MAX_DUP_OPERANDS 10
#define MAX_INSNS_PER_SPLIT 5

#include "regs.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "toplev.h"
#include "reload.h"
#include "tm-constrs.h"

#define HAVE_eh_return 1
#include "except.h"

/* Dummy external declarations.  */
extern rtx insn;
extern rtx ins1;
extern rtx operands[];

#endif /* gcc >= 3.0.1 */

/* Structure definition duplicated from gensupport.h rather than
   drag in that file and its dependencies.  */
struct c_test
{
  const char *expr;
  int value;
};

/* This table lists each condition found in the machine description.
   Each condition is mapped to its truth value (0 or 1), or -1 if that
   cannot be calculated at compile time.
   If we don't have __builtin_constant_p, or it's not acceptable in array
   initializers, fall back to assuming that all conditions potentially
   vary at run time.  It works in 3.0.1 and later; 3.0 only when not
   optimizing.  */

#if GCC_VERSION >= 3001
static const struct c_test insn_conditions[] = {

#line 11678 "../../gcc/config/i386/sse.md"
  { "TARGET_AES",
    __builtin_constant_p 
#line 11678 "../../gcc/config/i386/sse.md"
(TARGET_AES)
    ? (int) 
#line 11678 "../../gcc/config/i386/sse.md"
(TARGET_AES)
    : -1 },
#line 2566 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_check_movabs (insn, 1)",
    __builtin_constant_p 
#line 2566 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_check_movabs (insn, 1))
    ? (int) 
#line 2566 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_check_movabs (insn, 1))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V32QImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V32QImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V32QImode, operands))
    : -1 },
#line 6329 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_XOP ",
    __builtin_constant_p 
#line 6329 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP )
    ? (int) 
#line 6329 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP )
    : -1 },
#line 6475 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (PLUS, HImode, operands)",
    __builtin_constant_p 
#line 6475 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    ? (int) 
#line 6475 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    : -1 },
#line 11455 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11455 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    ? (int) 
#line 11455 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    : -1 },
#line 4526 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && reload_completed",
    __builtin_constant_p 
#line 4526 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && reload_completed)
    ? (int) 
#line 4526 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && reload_completed)
    : -1 },
  { "(ix86_match_ccmode (insn, CCNOmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9617 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9617 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 12740 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !TARGET_PARTIAL_REG_STALL",
    __builtin_constant_p 
#line 12740 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_PARTIAL_REG_STALL)
    ? (int) 
#line 12740 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_PARTIAL_REG_STALL)
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V8HImode)\n\
       || register_operand (operands[1], V8HImode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V8HImode)
       || register_operand (operands[1], V8HImode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V8HImode)
       || register_operand (operands[1], V8HImode)))
    : -1 },
#line 620 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (MULT, V4DFmode, operands)",
    __builtin_constant_p 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (MULT, V4DFmode, operands))
    ? (int) 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (MULT, V4DFmode, operands))
    : -1 },
#line 362 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 4887 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 4887 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 4887 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    : -1 },
#line 19769 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_size_p () || !TARGET_ADD_ESP_4",
    __builtin_constant_p 
#line 19769 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_4)
    ? (int) 
#line 19769 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_4)
    : -1 },
#line 17490 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && TARGET_C99_FUNCTIONS\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 17490 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 17490 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 17413 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 17413 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    ? (int) 
#line 17413 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    : -1 },
#line 9086 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && QI_REG_P (operands[0])\n\
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
    && !(INTVAL (operands[2]) & ~(255 << 8))\n\
    && GET_MODE (operands[0]) != QImode",
    __builtin_constant_p 
#line 9086 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (operands[2]) & ~(255 << 8))
    && GET_MODE (operands[0]) != QImode)
    ? (int) 
#line 9086 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (operands[2]) & ~(255 << 8))
    && GET_MODE (operands[0]) != QImode)
    : -1 },
  { "((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[2])\n\
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])\n\
       || GET_MODE (operands[3]) == VOIDmode)) && ( reload_completed)",
    __builtin_constant_p (
#line 7177 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[2])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)) && 
#line 7185 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 7177 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[2])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)) && 
#line 7185 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 14837 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14837 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14837 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V8HImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V8HImode, operands))
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (SFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))\n\
   && ix86_binary_operator_ok (MINUS, V8QImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V8QImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V8QImode, operands))
    : -1 },
#line 7230 "../../gcc/config/i386/i386.md"
  { "(GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])\n\
       || GET_MODE (operands[3]) == VOIDmode)",
    __builtin_constant_p 
#line 7230 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode))
    ? (int) 
#line 7230 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V16QImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V16QImode, operands))
    : -1 },
#line 1495 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE_MATH\n\
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])",
    __builtin_constant_p 
#line 1495 "../../gcc/config/i386/i386.md"
(TARGET_SSE_MATH
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    ? (int) 
#line 1495 "../../gcc/config/i386/i386.md"
(TARGET_SSE_MATH
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    : -1 },
#line 20313 "../../gcc/config/i386/i386.md"
  { "TARGET_PREFETCH_SSE || TARGET_3DNOW",
    __builtin_constant_p 
#line 20313 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE || TARGET_3DNOW)
    ? (int) 
#line 20313 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE || TARGET_3DNOW)
    : -1 },
#line 20271 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && INTVAL (operands[4]) + X86_64_SSE_REGPARM_MAX * 16 - 16 < 128\n\
   && INTVAL (operands[4]) + INTVAL (operands[2]) * 16 >= -128",
    __builtin_constant_p 
#line 20271 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && INTVAL (operands[4]) + X86_64_SSE_REGPARM_MAX * 16 - 16 < 128
   && INTVAL (operands[4]) + INTVAL (operands[2]) * 16 >= -128)
    ? (int) 
#line 20271 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && INTVAL (operands[4]) + X86_64_SSE_REGPARM_MAX * 16 - 16 < 128
   && INTVAL (operands[4]) + INTVAL (operands[2]) * 16 >= -128)
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V4SFmode)\n\
       || register_operand (operands[1], V4SFmode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V4SFmode)
       || register_operand (operands[1], V4SFmode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V4SFmode)
       || register_operand (operands[1], V4SFmode)))
    : -1 },
#line 20254 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT",
    __builtin_constant_p 
#line 20254 "../../gcc/config/i386/i386.md"
(TARGET_64BIT)
    ? (int) 
#line 20254 "../../gcc/config/i386/i386.md"
(TARGET_64BIT)
    : -1 },
#line 11252 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11252 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11252 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 14837 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14837 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14837 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V32QImode)\n\
       || register_operand (operands[1], V32QImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V32QImode)
       || register_operand (operands[1], V32QImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V32QImode)
       || register_operand (operands[1], V32QImode)))
    : -1 },
#line 6618 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCZmode)\n\
   && ix86_binary_operator_ok (PLUS, SImode, operands)\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)",
    __builtin_constant_p 
#line 6618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCZmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    ? (int) 
#line 6618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCZmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    : -1 },
#line 1338 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    ? (int) 
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    : -1 },
#line 164 "../../gcc/config/i386/sync.md"
  { "!TARGET_64BIT && TARGET_CMPXCHG8B && flag_pic",
    __builtin_constant_p 
#line 164 "../../gcc/config/i386/sync.md"
(!TARGET_64BIT && TARGET_CMPXCHG8B && flag_pic)
    ? (int) 
#line 164 "../../gcc/config/i386/sync.md"
(!TARGET_64BIT && TARGET_CMPXCHG8B && flag_pic)
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V2DImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V2DImode, operands))
    : -1 },
#line 1603 "../../gcc/config/i386/sse.md"
  { "AVX256_VEC_FLOAT_MODE_P (V8SFmode)",
    __builtin_constant_p 
#line 1603 "../../gcc/config/i386/sse.md"
(AVX256_VEC_FLOAT_MODE_P (V8SFmode))
    ? (int) 
#line 1603 "../../gcc/config/i386/sse.md"
(AVX256_VEC_FLOAT_MODE_P (V8SFmode))
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (DFmode, DImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, DImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, DImode))
    : -1 },
#line 4593 "../../gcc/config/i386/i386.md"
  { "TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 4593 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387)
    ? (int) 
#line 4593 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387)
    : -1 },
#line 11918 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11918 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11918 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || HImode != DImode))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 5434 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5434 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5434 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 3666 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && GET_MODE (operands[0]) == XFmode\n\
   && ! (ANY_FP_REG_P (operands[0]) ||\n\
	 (GET_CODE (operands[0]) == SUBREG\n\
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))\n\
   && ! (ANY_FP_REG_P (operands[1]) ||\n\
	 (GET_CODE (operands[1]) == SUBREG\n\
	  && ANY_FP_REG_P (SUBREG_REG (operands[1]))))",
    __builtin_constant_p 
#line 3666 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && GET_MODE (operands[0]) == XFmode
   && ! (ANY_FP_REG_P (operands[0]) ||
	 (GET_CODE (operands[0]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))
   && ! (ANY_FP_REG_P (operands[1]) ||
	 (GET_CODE (operands[1]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[1])))))
    ? (int) 
#line 3666 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && GET_MODE (operands[0]) == XFmode
   && ! (ANY_FP_REG_P (operands[0]) ||
	 (GET_CODE (operands[0]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))
   && ! (ANY_FP_REG_P (operands[1]) ||
	 (GET_CODE (operands[1]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[1])))))
    : -1 },
#line 9572 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NOT, HImode, operands)",
    __builtin_constant_p 
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, HImode, operands))
    ? (int) 
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, HImode, operands))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V16QImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V16QImode, operands))
    : -1 },
#line 10186 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_2\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 10186 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2
   && can_create_pseudo_p ())
    ? (int) 
#line 10186 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2
   && can_create_pseudo_p ())
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands))
    : -1 },
#line 15022 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (DFmode)\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 15022 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 15022 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 7476 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7476 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7476 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands))
    : -1 },
  { "(TARGET_LWP) && (Pmode == SImode)",
    __builtin_constant_p (
#line 20776 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    ? (int) (
#line 20776 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    : -1 },
#line 3822 "../../gcc/config/i386/i386.md"
  { "!TARGET_ZERO_EXTEND_WITH_AND\n\
   || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 3822 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND
   || optimize_function_for_size_p (cfun))
    ? (int) 
#line 3822 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND
   || optimize_function_for_size_p (cfun))
    : -1 },
#line 19527 "../../gcc/config/i386/i386.md"
  { "peep2_regno_dead_p (0, FLAGS_REG) && REGNO (operands[0]) == REGNO (operands[1])",
    __builtin_constant_p 
#line 19527 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG) && REGNO (operands[0]) == REGNO (operands[1]))
    ? (int) 
#line 19527 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG) && REGNO (operands[0]) == REGNO (operands[1]))
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V16QImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V16QImode, operands))
    : -1 },
  { "(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math) && (TARGET_64BIT)",
    __builtin_constant_p 
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math) && (TARGET_64BIT))
    ? (int) 
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math) && (TARGET_64BIT))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (XOR, V2DFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (XOR, V2DFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (XOR, V2DFmode, operands))
    : -1 },
#line 5530 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5530 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX
   && can_create_pseudo_p ())
    ? (int) 
#line 5530 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX
   && can_create_pseudo_p ())
    : -1 },
#line 3028 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && ((optimize_function_for_size_p (cfun)\n\
       || !TARGET_INTEGER_DFMODE_MOVES) && !TARGET_64BIT)\n\
   && (reload_in_progress || reload_completed\n\
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)\n\
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)\n\
           && optimize_function_for_size_p (cfun)\n\
           && !memory_operand (operands[0], DFmode)\n\
	   && standard_80387_constant_p (operands[1]))\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || ((optimize_function_for_size_p (cfun)\n\
            || !TARGET_MEMORY_MISMATCH_STALL\n\
	    || reload_in_progress || reload_completed)\n\
 	   && memory_operand (operands[0], DFmode)))",
    __builtin_constant_p 
#line 3028 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && ((optimize_function_for_size_p (cfun)
       || !TARGET_INTEGER_DFMODE_MOVES) && !TARGET_64BIT)
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
           && !memory_operand (operands[0], DFmode)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || ((optimize_function_for_size_p (cfun)
            || !TARGET_MEMORY_MISMATCH_STALL
	    || reload_in_progress || reload_completed)
 	   && memory_operand (operands[0], DFmode))))
    ? (int) 
#line 3028 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && ((optimize_function_for_size_p (cfun)
       || !TARGET_INTEGER_DFMODE_MOVES) && !TARGET_64BIT)
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
           && !memory_operand (operands[0], DFmode)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || ((optimize_function_for_size_p (cfun)
            || !TARGET_MEMORY_MISMATCH_STALL
	    || reload_in_progress || reload_completed)
 	   && memory_operand (operands[0], DFmode))))
    : -1 },
#line 11852 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11852 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11852 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 17529 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 7942 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && X87_ENABLE_ARITH (SFmode))\n\
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 7942 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (SFmode))
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 7942 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (SFmode))
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 11332 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11332 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    ? (int) 
#line 11332 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    : -1 },
  { "((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (DFmode == TFmode))) && ( reload_completed)",
    __builtin_constant_p (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (DFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (DFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 7624 "../../gcc/config/i386/sse.md"
  { "!TARGET_64BIT && TARGET_SSE",
    __builtin_constant_p 
#line 7624 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE)
    ? (int) 
#line 7624 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE)
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (IOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V8HImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V8HImode, operands))
    : -1 },
#line 3528 "../../gcc/config/i386/i386.md"
  { "optimize_function_for_size_p (cfun)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && (reload_in_progress || reload_completed\n\
       || standard_80387_constant_p (operands[1])\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || memory_operand (operands[0], XFmode))",
    __builtin_constant_p 
#line 3528 "../../gcc/config/i386/i386.md"
(optimize_function_for_size_p (cfun)
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || standard_80387_constant_p (operands[1])
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode)))
    ? (int) 
#line 3528 "../../gcc/config/i386/i386.md"
(optimize_function_for_size_p (cfun)
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || standard_80387_constant_p (operands[1])
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode)))
    : -1 },
#line 14268 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_MOVBE\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 14268 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_MOVBE
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 14268 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_MOVBE
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands))
    : -1 },
#line 2994 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT || TARGET_INTEGER_DFMODE_MOVES",
    __builtin_constant_p 
#line 2994 "../../gcc/config/i386/i386.md"
(TARGET_64BIT || TARGET_INTEGER_DFMODE_MOVES)
    ? (int) 
#line 2994 "../../gcc/config/i386/i386.md"
(TARGET_64BIT || TARGET_INTEGER_DFMODE_MOVES)
    : -1 },
#line 18525 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && TARGET_CMOVE)\n\
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
  { "(TARGET_CMPXCHG) && (TARGET_64BIT && TARGET_CMPXCHG16B)",
    __builtin_constant_p (
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 23 "../../gcc/config/i386/sync.md"
(TARGET_64BIT && TARGET_CMPXCHG16B))
    ? (int) (
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 23 "../../gcc/config/i386/sync.md"
(TARGET_64BIT && TARGET_CMPXCHG16B))
    : -1 },
#line 18946 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && flag_pic",
    __builtin_constant_p 
#line 18946 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && flag_pic)
    ? (int) 
#line 18946 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && flag_pic)
    : -1 },
#line 6522 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (PLUS, QImode, operands)",
    __builtin_constant_p 
#line 6522 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    ? (int) 
#line 6522 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (IOR, V2DFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (IOR, V2DFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (IOR, V2DFmode, operands))
    : -1 },
#line 19783 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_size_p () || !TARGET_ADD_ESP_8",
    __builtin_constant_p 
#line 19783 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_8)
    ? (int) 
#line 19783 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_8)
    : -1 },
#line 17322 "../../gcc/config/i386/i386.md"
  { "(TARGET_USE_FANCY_MATH_387\n\
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
	|| TARGET_MIX_SSE_I387)\n\
    && flag_unsafe_math_optimizations)\n\
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
       && !flag_trapping_math)",
    __builtin_constant_p 
#line 17322 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	|| TARGET_MIX_SSE_I387)
    && flag_unsafe_math_optimizations)
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
       && !flag_trapping_math))
    ? (int) 
#line 17322 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	|| TARGET_MIX_SSE_I387)
    && flag_unsafe_math_optimizations)
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
       && !flag_trapping_math))
    : -1 },
#line 742 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode)",
    __builtin_constant_p 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
    ? (int) 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
    : -1 },
#line 8884 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (XOR, HImode, operands)",
    __builtin_constant_p 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, HImode, operands))
    ? (int) 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, HImode, operands))
    : -1 },
#line 5653 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5653 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5653 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (MINUS, V4DFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (MINUS, V4DFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (MINUS, V4DFmode, operands))
    : -1 },
#line 9581 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NOT, QImode, operands)",
    __builtin_constant_p 
#line 9581 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, QImode, operands))
    ? (int) 
#line 9581 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, QImode, operands))
    : -1 },
#line 1063 "../../gcc/config/i386/sse.md"
  { "AVX128_VEC_FLOAT_MODE_P (V2DFmode)",
    __builtin_constant_p 
#line 1063 "../../gcc/config/i386/sse.md"
(AVX128_VEC_FLOAT_MODE_P (V2DFmode))
    ? (int) 
#line 1063 "../../gcc/config/i386/sse.md"
(AVX128_VEC_FLOAT_MODE_P (V2DFmode))
    : -1 },
#line 388 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 388 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 388 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 19860 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && (INTVAL (operands[2]) == 3\n\
       || INTVAL (operands[2]) == 5\n\
       || INTVAL (operands[2]) == 9)",
    __builtin_constant_p 
#line 19860 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    ? (int) 
#line 19860 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    : -1 },
#line 19064 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL && reload_completed\n\
   && (GET_MODE (operands[0]) == HImode\n\
       || (GET_MODE (operands[0]) == QImode\n\
	   && (TARGET_PROMOTE_QImode\n\
	       || optimize_insn_for_size_p ())))",
    __builtin_constant_p 
#line 19064 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && (GET_MODE (operands[0]) == HImode
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ()))))
    ? (int) 
#line 19064 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && (GET_MODE (operands[0]) == HImode
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ()))))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMIN, V8HImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V8HImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V8HImode, operands))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V4SImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V4SImode, operands))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (PLUS, QImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, operands))
    : -1 },
#line 16736 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && ((SImode != DImode) || TARGET_64BIT)\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 8177 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && !TARGET_64BIT",
    __builtin_constant_p 
#line 8177 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && !TARGET_64BIT)
    ? (int) 
#line 8177 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && !TARGET_64BIT)
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (XFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 20377 "../../gcc/config/i386/i386.md"
  { "TARGET_3DNOW && !TARGET_64BIT",
    __builtin_constant_p 
#line 20377 "../../gcc/config/i386/i386.md"
(TARGET_3DNOW && !TARGET_64BIT)
    ? (int) 
#line 20377 "../../gcc/config/i386/i386.md"
(TARGET_3DNOW && !TARGET_64BIT)
    : -1 },
#line 8931 "../../gcc/config/i386/i386.md"
  { "(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 8931 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 8931 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 11344 "../../gcc/config/i386/sse.md"
  { "TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 11344 "../../gcc/config/i386/sse.md"
(TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 11344 "../../gcc/config/i386/sse.md"
(TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 8615 "../../gcc/config/i386/i386.md"
  { "(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && reload_completed",
    __builtin_constant_p 
#line 8615 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && reload_completed)
    ? (int) 
#line 8615 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && reload_completed)
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V4SImode)\n\
       || register_operand (operands[1], V4SImode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V4SImode)
       || register_operand (operands[1], V4SImode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V4SImode)
       || register_operand (operands[1], V4SImode)))
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && ( reload_completed)",
    __builtin_constant_p (
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && 
#line 1343 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && 
#line 1343 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 4506 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_VECTOR_FP_CONVERTS\n\
   && optimize_insn_for_speed_p ()\n\
   && reload_completed && SSE_REG_P (operands[0])",
    __builtin_constant_p 
#line 4506 "../../gcc/config/i386/i386.md"
(TARGET_USE_VECTOR_FP_CONVERTS
   && optimize_insn_for_speed_p ()
   && reload_completed && SSE_REG_P (operands[0]))
    ? (int) 
#line 4506 "../../gcc/config/i386/i386.md"
(TARGET_USE_VECTOR_FP_CONVERTS
   && optimize_insn_for_speed_p ()
   && reload_completed && SSE_REG_P (operands[0]))
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((DImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 9604 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_unary_operator_ok (NOT, QImode, operands)",
    __builtin_constant_p 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, QImode, operands))
    ? (int) 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, QImode, operands))
    : -1 },
#line 1613 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && operands[1] == constm1_rtx",
    __builtin_constant_p 
#line 1613 "../../gcc/config/i386/i386.md"
(reload_completed
   && operands[1] == constm1_rtx)
    ? (int) 
#line 1613 "../../gcc/config/i386/i386.md"
(reload_completed
   && operands[1] == constm1_rtx)
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (SFmode, SImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, SImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, SImode))
    : -1 },
#line 1479 "../../gcc/config/i386/sse.md"
  { "!TARGET_XOP \n\
  && (SSE_FLOAT_MODE_P (V2DFmode) || SSE_VEC_FLOAT_MODE_P (V2DFmode))",
    __builtin_constant_p 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (V2DFmode) || SSE_VEC_FLOAT_MODE_P (V2DFmode)))
    ? (int) 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (V2DFmode) || SSE_VEC_FLOAT_MODE_P (V2DFmode)))
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V2DFmode)\n\
       || register_operand (operands[1], V2DFmode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V2DFmode)
       || register_operand (operands[1], V2DFmode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V2DFmode)
       || register_operand (operands[1], V2DFmode)))
    : -1 },
#line 5846 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)\n\
   && TARGET_SSE\n\
   && reload_completed",
    __builtin_constant_p 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    ? (int) 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    : -1 },
#line 14907 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (SFmode)\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14907 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (SFmode)
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14907 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (SFmode)
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 511 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4A",
    __builtin_constant_p 
#line 511 "../../gcc/config/i386/sse.md"
(TARGET_SSE4A)
    ? (int) 
#line 511 "../../gcc/config/i386/sse.md"
(TARGET_SSE4A)
    : -1 },
#line 6398 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_XOP",
    __builtin_constant_p 
#line 6398 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP)
    ? (int) 
#line 6398 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP)
    : -1 },
#line 5605 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5605 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 5605 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    : -1 },
#line 14876 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14876 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14876 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 9286 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 6364 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1",
    __builtin_constant_p 
#line 6364 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1)
    ? (int) 
#line 6364 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1)
    : -1 },
  { "(TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL) && ( reload_completed)",
    __builtin_constant_p (
#line 18506 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL) && 
#line 18508 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 18506 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL) && 
#line 18508 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 1581 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)",
    __builtin_constant_p 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode))
    ? (int) 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode))
    : -1 },
#line 18492 "../../gcc/config/i386/i386.md"
  { "TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3]))",
    __builtin_constant_p 
#line 18492 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    ? (int) 
#line 18492 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    : -1 },
#line 8987 "../../gcc/config/i386/i386.md"
  { "(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCNOmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 8987 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 8987 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 16736 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && ((SImode != DImode) || TARGET_64BIT)\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 19986 "../../gcc/config/i386/i386.md"
  { "TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()",
    __builtin_constant_p 
#line 19986 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ())
    ? (int) 
#line 19986 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ())
    : -1 },
#line 5488 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MULT, V8HImode, operands)",
    __builtin_constant_p 
#line 5488 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V8HImode, operands))
    ? (int) 
#line 5488 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V8HImode, operands))
    : -1 },
#line 4907 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode)\n\
   && (!TARGET_FISTTP || TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4907 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    ? (int) 
#line 4907 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 12679 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !TARGET_USE_BT",
    __builtin_constant_p 
#line 12679 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_USE_BT)
    ? (int) 
#line 12679 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_USE_BT)
    : -1 },
#line 9056 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 9056 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 9056 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    : -1 },
#line 18567 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_80387 && TARGET_CMOVE\n\
   && !(MEM_P (operands[2]) && MEM_P (operands[3]))",
    __builtin_constant_p 
#line 18567 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    ? (int) 
#line 18567 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    : -1 },
#line 4551 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_MIX_SSE_I387 && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 4551 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387 && flag_unsafe_math_optimizations)
    ? (int) 
#line 4551 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387 && flag_unsafe_math_optimizations)
    : -1 },
#line 7502 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7502 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7502 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 5331 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MULT, V4SImode, operands)",
    __builtin_constant_p 
#line 5331 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V4SImode, operands))
    ? (int) 
#line 5331 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V4SImode, operands))
    : -1 },
#line 5865 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && ((TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)\n\
	&& TARGET_SSE)\n\
       || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)))
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (SFmode, DImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, DImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, DImode))
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (DFmode, SImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, SImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, SImode))
    : -1 },
#line 6711 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCZmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 6711 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 6711 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (IOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V4SImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V4SImode, operands))
    : -1 },
#line 11287 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11287 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    ? (int) 
#line 11287 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    : -1 },
#line 6367 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (PLUS, SImode, operands)\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)",
    __builtin_constant_p 
#line 6367 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    ? (int) 
#line 6367 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    : -1 },
#line 4312 "../../gcc/config/i386/i386.md"
  { "0",
    __builtin_constant_p 
#line 4312 "../../gcc/config/i386/i386.md"
(0)
    ? (int) 
#line 4312 "../../gcc/config/i386/i386.md"
(0)
    : -1 },
#line 327 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && ix86_binary_operator_ok (PLUS, V2SFmode, operands)",
    __builtin_constant_p 
#line 327 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (PLUS, V2SFmode, operands))
    ? (int) 
#line 327 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (PLUS, V2SFmode, operands))
    : -1 },
#line 12040 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 12040 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    ? (int) 
#line 12040 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    : -1 },
#line 5245 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && reload_completed",
    __builtin_constant_p 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    ? (int) 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    : -1 },
#line 3813 "../../gcc/config/i386/i386.md"
  { "reload_completed && TARGET_ZERO_EXTEND_WITH_AND\n\
   && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 3813 "../../gcc/config/i386/i386.md"
(reload_completed && TARGET_ZERO_EXTEND_WITH_AND
   && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 3813 "../../gcc/config/i386/i386.md"
(reload_completed && TARGET_ZERO_EXTEND_WITH_AND
   && optimize_function_for_speed_p (cfun))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (XOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V16QImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V16QImode, operands))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (IOR, V4SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (IOR, V4SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (IOR, V4SFmode, operands))
    : -1 },
#line 4991 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	&& (TARGET_64BIT || HImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (IOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V16QImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V16QImode, operands))
    : -1 },
#line 351 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 351 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 351 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 12755 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 12755 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 12755 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
    : -1 },
#line 13482 "../../gcc/config/i386/i386.md"
  { "(peep2_reg_dead_p (3, operands[1])\n\
    || operands_match_p (operands[1], operands[3]))\n\
   && ! reg_overlap_mentioned_p (operands[3], operands[0])",
    __builtin_constant_p 
#line 13482 "../../gcc/config/i386/i386.md"
((peep2_reg_dead_p (3, operands[1])
    || operands_match_p (operands[1], operands[3]))
   && ! reg_overlap_mentioned_p (operands[3], operands[0]))
    ? (int) 
#line 13482 "../../gcc/config/i386/i386.md"
((peep2_reg_dead_p (3, operands[1])
    || operands_match_p (operands[1], operands[3]))
   && ! reg_overlap_mentioned_p (operands[3], operands[0]))
    : -1 },
#line 7460 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 7488 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (MINUS, QImode, operands)",
    __builtin_constant_p 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands))
    ? (int) 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands))
    : -1 },
#line 20549 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE4_2 || TARGET_CRC32",
    __builtin_constant_p 
#line 20549 "../../gcc/config/i386/i386.md"
(TARGET_SSE4_2 || TARGET_CRC32)
    ? (int) 
#line 20549 "../../gcc/config/i386/i386.md"
(TARGET_SSE4_2 || TARGET_CRC32)
    : -1 },
#line 14986 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 14986 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 14986 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 9463 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (reload_completed\n\
       || !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)))
    : -1 },
#line 5818 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)\n\
   && TARGET_SSE",
    __builtin_constant_p 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE)
    ? (int) 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE)
    : -1 },
#line 5257 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
        || TARGET_MIX_SSE_I387)\n\
    && reload_completed",
    __builtin_constant_p 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    ? (int) 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    : -1 },
  { "(TARGET_SSE2) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3658 "../../gcc/config/i386/i386.md"
(TARGET_SSE2) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    ? (int) (
#line 3658 "../../gcc/config/i386/i386.md"
(TARGET_SSE2) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    : -1 },
#line 4478 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (TARGET_SSE2 && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4478 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_SSE2 && TARGET_SSE_MATH))
    ? (int) 
#line 4478 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_SSE2 && TARGET_SSE_MATH))
    : -1 },
#line 4825 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (SFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    ? (int) 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (SFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    : -1 },
#line 6202 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V4SImode, operands)",
    __builtin_constant_p 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V4SImode, operands))
    ? (int) 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V4SImode, operands))
    : -1 },
#line 49 "../../gcc/config/i386/sync.md"
  { "!(TARGET_64BIT || TARGET_SSE2)",
    __builtin_constant_p 
#line 49 "../../gcc/config/i386/sync.md"
(!(TARGET_64BIT || TARGET_SSE2))
    ? (int) 
#line 49 "../../gcc/config/i386/sync.md"
(!(TARGET_64BIT || TARGET_SSE2))
    : -1 },
  { "(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 7813 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 7813 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 6091 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SMIN, V8HImode, operands)",
    __builtin_constant_p 
#line 6091 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SMIN, V8HImode, operands))
    ? (int) 
#line 6091 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SMIN, V8HImode, operands))
    : -1 },
#line 4401 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 4401 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387)
    ? (int) 
#line 4401 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387)
    : -1 },
  { "(ix86_unary_operator_ok (NEG, DImode, operands)) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 9206 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    ? (int) (
#line 9206 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    : -1 },
#line 8166 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
    && ix86_match_ccmode (insn,\n\
 			 CONST_INT_P (operands[1])\n\
 			 && INTVAL (operands[1]) >= 0 ? CCNOmode : CCZmode)",
    __builtin_constant_p 
#line 8166 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
    && ix86_match_ccmode (insn,
 			 CONST_INT_P (operands[1])
 			 && INTVAL (operands[1]) >= 0 ? CCNOmode : CCZmode))
    ? (int) 
#line 8166 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
    && ix86_match_ccmode (insn,
 			 CONST_INT_P (operands[1])
 			 && INTVAL (operands[1]) >= 0 ? CCNOmode : CCZmode))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (AND, V4SFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (AND, V4SFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (AND, V4SFmode, operands))
    : -1 },
#line 2029 "../../gcc/config/i386/i386.md"
  { "TARGET_PARTIAL_REG_STALL",
    __builtin_constant_p 
#line 2029 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL)
    ? (int) 
#line 2029 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL)
    : -1 },
#line 4442 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (!MEM_P (operands[1]) || rtx_equal_p (operands[1], operands[2]))",
    __builtin_constant_p 
#line 4442 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (!MEM_P (operands[1]) || rtx_equal_p (operands[1], operands[2])))
    ? (int) 
#line 4442 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (!MEM_P (operands[1]) || rtx_equal_p (operands[1], operands[2])))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (IOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V2DImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V2DImode, operands))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (DFmode, DImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 5380 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && TARGET_INTER_UNIT_CONVERSIONS\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5380 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5380 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 7917 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 7917 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 7917 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (XFmode, DImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, DImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, DImode))
    : -1 },
#line 397 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V2SFmode, operands)",
    __builtin_constant_p 
#line 397 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2SFmode, operands))
    ? (int) 
#line 397 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2SFmode, operands))
    : -1 },
#line 16729 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && ((SImode != DImode) || TARGET_64BIT)",
    __builtin_constant_p 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT))
    ? (int) 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT))
    : -1 },
#line 8483 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (AND, SImode, operands)",
    __builtin_constant_p 
#line 8483 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, SImode, operands))
    ? (int) 
#line 8483 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, SImode, operands))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V16QImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V16QImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V16QImode, operands))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (DFmode, SImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (DFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands))
    : -1 },
#line 14876 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14876 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14876 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 8287 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && ix86_match_ccmode (insn, CCNOmode)\n\
   && INTVAL (operands[1]) > 0\n\
   && INTVAL (operands[2]) >= 0\n\
   /* Ensure that resulting mask is zero or sign extended operand.  */\n\
   && (INTVAL (operands[1]) + INTVAL (operands[2]) <= 32\n\
       || (INTVAL (operands[1]) + INTVAL (operands[2]) == 64\n\
	   && INTVAL (operands[1]) > 32))\n\
   && (GET_MODE (operands[0]) == SImode\n\
       || GET_MODE (operands[0]) == DImode\n\
       || GET_MODE (operands[0]) == HImode\n\
       || GET_MODE (operands[0]) == QImode)",
    __builtin_constant_p 
#line 8287 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && INTVAL (operands[1]) > 0
   && INTVAL (operands[2]) >= 0
   /* Ensure that resulting mask is zero or sign extended operand.  */
   && (INTVAL (operands[1]) + INTVAL (operands[2]) <= 32
       || (INTVAL (operands[1]) + INTVAL (operands[2]) == 64
	   && INTVAL (operands[1]) > 32))
   && (GET_MODE (operands[0]) == SImode
       || GET_MODE (operands[0]) == DImode
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode))
    ? (int) 
#line 8287 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && INTVAL (operands[1]) > 0
   && INTVAL (operands[2]) >= 0
   /* Ensure that resulting mask is zero or sign extended operand.  */
   && (INTVAL (operands[1]) + INTVAL (operands[2]) <= 32
       || (INTVAL (operands[1]) + INTVAL (operands[2]) == 64
	   && INTVAL (operands[1]) > 32))
   && (GET_MODE (operands[0]) == SImode
       || GET_MODE (operands[0]) == DImode
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode))
    : -1 },
#line 5653 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5653 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5653 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5798 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 5581 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_SSE_MATH\n\
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun)\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5581 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun)
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5581 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun)
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 4906 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 4906 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 4906 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
  { "(TARGET_XADD) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 175 "../../gcc/config/i386/sync.md"
(TARGET_XADD) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 175 "../../gcc/config/i386/sync.md"
(TARGET_XADD) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((DImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 12142 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATE, SImode, operands)",
    __builtin_constant_p 
#line 12142 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, operands))
    ? (int) 
#line 12142 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, operands))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (SFmode, SImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V16QImode)\n\
       || register_operand (operands[1], V16QImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V16QImode)
       || register_operand (operands[1], V16QImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V16QImode)
       || register_operand (operands[1], V16QImode)))
    : -1 },
#line 14949 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14949 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14949 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 742 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode)",
    __builtin_constant_p 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
    ? (int) 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
    : -1 },
#line 3443 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && ! (ANY_FP_REG_P (operands[0]) ||\n\
	 (GET_CODE (operands[0]) == SUBREG\n\
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))\n\
   && ! (ANY_FP_REG_P (operands[1]) ||\n\
	 (GET_CODE (operands[1]) == SUBREG\n\
	  && ANY_FP_REG_P (SUBREG_REG (operands[1]))))",
    __builtin_constant_p 
#line 3443 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && ! (ANY_FP_REG_P (operands[0]) ||
	 (GET_CODE (operands[0]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))
   && ! (ANY_FP_REG_P (operands[1]) ||
	 (GET_CODE (operands[1]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[1])))))
    ? (int) 
#line 3443 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && ! (ANY_FP_REG_P (operands[0]) ||
	 (GET_CODE (operands[0]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[0]))))
   && ! (ANY_FP_REG_P (operands[1]) ||
	 (GET_CODE (operands[1]) == SUBREG
	  && ANY_FP_REG_P (SUBREG_REG (operands[1])))))
    : -1 },
#line 1057 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (EQ, V8QImode, operands)",
    __builtin_constant_p 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V8QImode, operands))
    ? (int) 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V8QImode, operands))
    : -1 },
#line 2552 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_check_movabs (insn, 0)",
    __builtin_constant_p 
#line 2552 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_check_movabs (insn, 0))
    ? (int) 
#line 2552 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_check_movabs (insn, 0))
    : -1 },
#line 8852 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && ANY_QI_REG_P (operands[0])\n\
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
    && !(~INTVAL (operands[2]) & ~255)\n\
    && !(INTVAL (operands[2]) & 128)\n\
    && GET_MODE (operands[0]) != QImode",
    __builtin_constant_p 
#line 8852 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (operands[2]) & ~255)
    && !(INTVAL (operands[2]) & 128)
    && GET_MODE (operands[0]) != QImode)
    ? (int) 
#line 8852 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (operands[2]) & ~255)
    && !(INTVAL (operands[2]) & 128)
    && GET_MODE (operands[0]) != QImode)
    : -1 },
#line 1699 "../../gcc/config/i386/sse.md"
  { "SSE_FLOAT_MODE_P (SFmode)",
    __builtin_constant_p 
#line 1699 "../../gcc/config/i386/sse.md"
(SSE_FLOAT_MODE_P (SFmode))
    ? (int) 
#line 1699 "../../gcc/config/i386/sse.md"
(SSE_FLOAT_MODE_P (SFmode))
    : -1 },
#line 2398 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && reload_completed\n\
   && operands[1] == constm1_rtx",
    __builtin_constant_p 
#line 2398 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && reload_completed
   && operands[1] == constm1_rtx)
    ? (int) 
#line 2398 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && reload_completed
   && operands[1] == constm1_rtx)
    : -1 },
#line 10056 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ASHIFT, SImode, operands)",
    __builtin_constant_p 
#line 10056 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFT, SImode, operands))
    ? (int) 
#line 10056 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFT, SImode, operands))
    : -1 },
#line 620 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (MULT, V4SFmode, operands)",
    __builtin_constant_p 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MULT, V4SFmode, operands))
    ? (int) 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MULT, V4SFmode, operands))
    : -1 },
#line 4543 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && INTVAL (operands[2]) + 2 == INTVAL (operands[3])",
    __builtin_constant_p 
#line 4543 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && INTVAL (operands[2]) + 2 == INTVAL (operands[3]))
    ? (int) 
#line 4543 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && INTVAL (operands[2]) + 2 == INTVAL (operands[3]))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMIN, V4SImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V4SImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V4SImode, operands))
    : -1 },
#line 1581 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)",
    __builtin_constant_p 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode))
    ? (int) 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode))
    : -1 },
#line 19565 "../../gcc/config/i386/i386.md"
  { "exact_log2 (INTVAL (operands[2])) >= 0\n\
   && REGNO (operands[0]) == REGNO (operands[1])\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19565 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (operands[2])) >= 0
   && REGNO (operands[0]) == REGNO (operands[1])
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19565 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (operands[2])) >= 0
   && REGNO (operands[0]) == REGNO (operands[1])
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 15152 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && !COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 15152 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 15152 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 7618 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V4DImode)\n\
       || register_operand (operands[1], V4DImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4DImode)
       || register_operand (operands[1], V4DImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4DImode)
       || register_operand (operands[1], V4DImode)))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (PLUS, SImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, operands))
    : -1 },
#line 13003 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 13003 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 13003 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((SImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (IOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V2DImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V2DImode, operands))
    : -1 },
  { "(ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 9286 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 15188 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15188 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15188 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 12422 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATERT, HImode, operands)",
    __builtin_constant_p 
#line 12422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, HImode, operands))
    ? (int) 
#line 12422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, HImode, operands))
    : -1 },
#line 4114 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 4114 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 4114 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V16QImode)\n\
       || register_operand (operands[1], V16QImode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V16QImode)
       || register_operand (operands[1], V16QImode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V16QImode)
       || register_operand (operands[1], V16QImode)))
    : -1 },
#line 18714 "../../gcc/config/i386/i386.md"
  { "REGNO (operands[0]) != REGNO (operands[1])",
    __builtin_constant_p 
#line 18714 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1]))
    ? (int) 
#line 18714 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1]))
    : -1 },
#line 5757 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    : -1 },
#line 1000 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && ix86_match_ccmode (insn, CCmode)",
    __builtin_constant_p 
#line 1000 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCmode))
    ? (int) 
#line 1000 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCmode))
    : -1 },
#line 17445 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 17445 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && can_create_pseudo_p ())
    ? (int) 
#line 17445 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && can_create_pseudo_p ())
    : -1 },
#line 640 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (MULT, V2DFmode, operands)",
    __builtin_constant_p 
#line 640 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MULT, V2DFmode, operands))
    ? (int) 
#line 640 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MULT, V2DFmode, operands))
    : -1 },
#line 1057 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (EQ, V2SImode, operands)",
    __builtin_constant_p 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V2SImode, operands))
    ? (int) 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V2SImode, operands))
    : -1 },
#line 9463 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (reload_completed\n\
       || !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)))
    : -1 },
#line 8098 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE || TARGET_3DNOW_A",
    __builtin_constant_p 
#line 8098 "../../gcc/config/i386/sse.md"
(TARGET_SSE || TARGET_3DNOW_A)
    ? (int) 
#line 8098 "../../gcc/config/i386/sse.md"
(TARGET_SSE || TARGET_3DNOW_A)
    : -1 },
#line 5394 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5394 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5394 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (IOR, V8SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (IOR, V8SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (IOR, V8SFmode, operands))
    : -1 },
#line 14350 "../../gcc/config/i386/i386.md"
  { "TARGET_ABM",
    __builtin_constant_p 
#line 14350 "../../gcc/config/i386/i386.md"
(TARGET_ABM)
    ? (int) 
#line 14350 "../../gcc/config/i386/i386.md"
(TARGET_ABM)
    : -1 },
#line 5366 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 5366 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387)
    ? (int) 
#line 5366 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387)
    : -1 },
#line 5380 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && TARGET_INTER_UNIT_CONVERSIONS\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5380 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5380 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 8695 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (AND, SImode, operands)",
    __builtin_constant_p 
#line 8695 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands))
    ? (int) 
#line 8695 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands))
    : -1 },
#line 574 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands)",
    __builtin_constant_p 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands))
    ? (int) 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands))
    : -1 },
#line 10927 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)",
    __builtin_constant_p 
#line 10927 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    ? (int) 
#line 10927 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    : -1 },
#line 11157 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11157 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11157 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 4926 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && reload_completed",
    __builtin_constant_p 
#line 4926 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && reload_completed)
    ? (int) 
#line 4926 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && reload_completed)
    : -1 },
#line 19182 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && ! TARGET_USE_MOV0\n\
   && TARGET_SPLIT_LONG_MOVES\n\
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19182 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ! TARGET_USE_MOV0
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19182 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ! TARGET_USE_MOV0
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 11141 "../../gcc/config/i386/sse.md"
  { "TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3]))",
    __builtin_constant_p 
#line 11141 "../../gcc/config/i386/sse.md"
(TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    ? (int) 
#line 11141 "../../gcc/config/i386/sse.md"
(TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    : -1 },
  { "(ix86_unary_operator_ok (NEG, TImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9206 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, TImode, operands)) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9206 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, TImode, operands)) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 15063 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (SFmode, HImode)\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, HImode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, HImode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5674 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5674 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5674 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V4HImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V4HImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V4HImode, operands))
    : -1 },
#line 1251 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && TARGET_SAHF && !TARGET_CMOVE",
    __builtin_constant_p 
#line 1251 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && TARGET_SAHF && !TARGET_CMOVE)
    ? (int) 
#line 1251 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && TARGET_SAHF && !TARGET_CMOVE)
    : -1 },
#line 25 "../../gcc/config/i386/sync.md"
  { "!TARGET_64BIT && TARGET_CMPXCHG8B && !flag_pic",
    __builtin_constant_p 
#line 25 "../../gcc/config/i386/sync.md"
(!TARGET_64BIT && TARGET_CMPXCHG8B && !flag_pic)
    ? (int) 
#line 25 "../../gcc/config/i386/sync.md"
(!TARGET_64BIT && TARGET_CMPXCHG8B && !flag_pic)
    : -1 },
  { "(ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (PLUS, DImode, operands)\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 6367 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, DImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 6367 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, DImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V4SImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V4SImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V4SImode, operands))
    : -1 },
#line 3713 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && MEM_P (operands[1])\n\
   && (GET_MODE (operands[0]) == TFmode\n\
       || GET_MODE (operands[0]) == XFmode\n\
       || GET_MODE (operands[0]) == SFmode\n\
       || GET_MODE (operands[0]) == DFmode)\n\
   && (operands[2] = find_constant_src (insn))",
    __builtin_constant_p 
#line 3713 "../../gcc/config/i386/i386.md"
(reload_completed
   && MEM_P (operands[1])
   && (GET_MODE (operands[0]) == TFmode
       || GET_MODE (operands[0]) == XFmode
       || GET_MODE (operands[0]) == SFmode
       || GET_MODE (operands[0]) == DFmode)
   && (operands[2] = find_constant_src (insn)))
    ? (int) 
#line 3713 "../../gcc/config/i386/i386.md"
(reload_completed
   && MEM_P (operands[1])
   && (GET_MODE (operands[0]) == TFmode
       || GET_MODE (operands[0]) == XFmode
       || GET_MODE (operands[0]) == SFmode
       || GET_MODE (operands[0]) == DFmode)
   && (operands[2] = find_constant_src (insn)))
    : -1 },
#line 8656 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (AND, QImode, operands)\n\
   && ix86_match_ccmode (insn,\n\
			 CONST_INT_P (operands[2])\n\
			 && INTVAL (operands[2]) >= 0 ? CCNOmode : CCZmode)",
    __builtin_constant_p 
#line 8656 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, operands)
   && ix86_match_ccmode (insn,
			 CONST_INT_P (operands[2])
			 && INTVAL (operands[2]) >= 0 ? CCNOmode : CCZmode))
    ? (int) 
#line 8656 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, operands)
   && ix86_match_ccmode (insn,
			 CONST_INT_P (operands[2])
			 && INTVAL (operands[2]) >= 0 ? CCNOmode : CCZmode))
    : -1 },
#line 7460 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (MINUS, QImode, operands)",
    __builtin_constant_p 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands))
    ? (int) 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (IOR, V2SImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V2SImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V2SImode, operands))
    : -1 },
#line 4366 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 1)",
    __builtin_constant_p 
#line 4366 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    ? (int) 
#line 4366 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V8HImode, operands))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V16QImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V16QImode, operands))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (PLUS, HImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, operands))
    : -1 },
#line 6216 "../../gcc/config/i386/i386.md"
  { "TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (PLUS, QImode, operands)",
    __builtin_constant_p 
#line 6216 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    ? (int) 
#line 6216 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    : -1 },
#line 620 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (MULT, V2DFmode, operands)",
    __builtin_constant_p 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MULT, V2DFmode, operands))
    ? (int) 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MULT, V2DFmode, operands))
    : -1 },
#line 6813 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGCmode)\n\
   && (INTVAL (operands[2]) & 0xffffffff) != 0x80000000",
    __builtin_constant_p 
#line 6813 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffffffff) != 0x80000000)
    ? (int) 
#line 6813 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffffffff) != 0x80000000)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V2DFmode)\n\
       || register_operand (operands[1], V2DFmode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V2DFmode)
       || register_operand (operands[1], V2DFmode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V2DFmode)
       || register_operand (operands[1], V2DFmode)))
    : -1 },
#line 5394 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5394 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5394 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 16736 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && ((DImode != DImode) || TARGET_64BIT)\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 5757 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    : -1 },
#line 10375 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)",
    __builtin_constant_p 
#line 10375 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    ? (int) 
#line 10375 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    : -1 },
#line 5639 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5639 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5639 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 1348 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && !TARGET_SSE",
    __builtin_constant_p 
#line 1348 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !TARGET_SSE)
    ? (int) 
#line 1348 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !TARGET_SSE)
    : -1 },
#line 1949 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 1949 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 1949 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 20018 "../../gcc/config/i386/i386.md"
  { "INTVAL (operands[2]) >= 0 && INTVAL (operands[2]) <= 3\n\
   /* Validate MODE for lea.  */\n\
   && ((!TARGET_PARTIAL_REG_STALL\n\
	&& (GET_MODE (operands[0]) == QImode\n\
	    || GET_MODE (operands[0]) == HImode))\n\
       || GET_MODE (operands[0]) == SImode\n\
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode))\n\
   /* We reorder load and the shift.  */\n\
   && !rtx_equal_p (operands[1], operands[3])\n\
   && !reg_overlap_mentioned_p (operands[0], operands[4])\n\
   /* Last PLUS must consist of operand 0 and 3.  */\n\
   && !rtx_equal_p (operands[0], operands[3])\n\
   && (rtx_equal_p (operands[3], operands[6])\n\
       || rtx_equal_p (operands[3], operands[7]))\n\
   && (rtx_equal_p (operands[0], operands[6])\n\
       || rtx_equal_p (operands[0], operands[7]))\n\
   /* The intermediate operand 0 must die or be same as output.  */\n\
   && (rtx_equal_p (operands[0], operands[5])\n\
       || peep2_reg_dead_p (3, operands[0]))",
    __builtin_constant_p 
#line 20018 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) >= 0 && INTVAL (operands[2]) <= 3
   /* Validate MODE for lea.  */
   && ((!TARGET_PARTIAL_REG_STALL
	&& (GET_MODE (operands[0]) == QImode
	    || GET_MODE (operands[0]) == HImode))
       || GET_MODE (operands[0]) == SImode
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode))
   /* We reorder load and the shift.  */
   && !rtx_equal_p (operands[1], operands[3])
   && !reg_overlap_mentioned_p (operands[0], operands[4])
   /* Last PLUS must consist of operand 0 and 3.  */
   && !rtx_equal_p (operands[0], operands[3])
   && (rtx_equal_p (operands[3], operands[6])
       || rtx_equal_p (operands[3], operands[7]))
   && (rtx_equal_p (operands[0], operands[6])
       || rtx_equal_p (operands[0], operands[7]))
   /* The intermediate operand 0 must die or be same as output.  */
   && (rtx_equal_p (operands[0], operands[5])
       || peep2_reg_dead_p (3, operands[0])))
    ? (int) 
#line 20018 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) >= 0 && INTVAL (operands[2]) <= 3
   /* Validate MODE for lea.  */
   && ((!TARGET_PARTIAL_REG_STALL
	&& (GET_MODE (operands[0]) == QImode
	    || GET_MODE (operands[0]) == HImode))
       || GET_MODE (operands[0]) == SImode
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode))
   /* We reorder load and the shift.  */
   && !rtx_equal_p (operands[1], operands[3])
   && !reg_overlap_mentioned_p (operands[0], operands[4])
   /* Last PLUS must consist of operand 0 and 3.  */
   && !rtx_equal_p (operands[0], operands[3])
   && (rtx_equal_p (operands[3], operands[6])
       || rtx_equal_p (operands[3], operands[7]))
   && (rtx_equal_p (operands[0], operands[6])
       || rtx_equal_p (operands[0], operands[7]))
   /* The intermediate operand 0 must die or be same as output.  */
   && (rtx_equal_p (operands[0], operands[5])
       || peep2_reg_dead_p (3, operands[0])))
    : -1 },
  { "(TARGET_LWP) && (Pmode == DImode)",
    __builtin_constant_p (
#line 20776 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    ? (int) (
#line 20776 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V4HImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V4HImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V4HImode, operands))
    : -1 },
#line 8884 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (IOR, HImode, operands)",
    __builtin_constant_p 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, HImode, operands))
    ? (int) 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, HImode, operands))
    : -1 },
#line 4977 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || HImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 4977 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || DImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 5394 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5394 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5394 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (AND, V4SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (AND, V4SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (AND, V4SFmode, operands))
    : -1 },
#line 2836 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && MEM_P (operands[1])\n\
   && (operands[2] = find_constant_src (insn))",
    __builtin_constant_p 
#line 2836 "../../gcc/config/i386/i386.md"
(reload_completed
   && MEM_P (operands[1])
   && (operands[2] = find_constant_src (insn)))
    ? (int) 
#line 2836 "../../gcc/config/i386/i386.md"
(reload_completed
   && MEM_P (operands[1])
   && (operands[2] = find_constant_src (insn)))
    : -1 },
#line 10643 "../../gcc/config/i386/i386.md"
  { "TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)",
    __builtin_constant_p 
#line 10643 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    ? (int) 
#line 10643 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    : -1 },
#line 6587 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (IOR, TFmode, operands)",
    __builtin_constant_p 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, TFmode, operands))
    ? (int) 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, TFmode, operands))
    : -1 },
#line 1028 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands)",
    __builtin_constant_p 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands))
    ? (int) 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands))
    : -1 },
#line 2242 "../../gcc/config/i386/sse.md"
  { "TARGET_FMA4 && TARGET_FUSED_MADD",
    __builtin_constant_p 
#line 2242 "../../gcc/config/i386/sse.md"
(TARGET_FMA4 && TARGET_FUSED_MADD)
    ? (int) 
#line 2242 "../../gcc/config/i386/sse.md"
(TARGET_FMA4 && TARGET_FUSED_MADD)
    : -1 },
#line 5605 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5605 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 5605 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    : -1 },
#line 5674 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5674 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5674 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 9076 "../../gcc/config/i386/sse.md"
  { "TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V4HImode, operands)",
    __builtin_constant_p 
#line 9076 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V4HImode, operands))
    ? (int) 
#line 9076 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V4HImode, operands))
    : -1 },
#line 11488 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11488 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    ? (int) 
#line 11488 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V4DImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V4DImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V4DImode, operands))
    : -1 },
#line 9474 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387)",
    __builtin_constant_p 
#line 9474 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387))
    ? (int) 
#line 9474 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387))
    : -1 },
  { "(TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 14168 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode)) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 14168 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode)) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (XOR, V4SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (XOR, V4SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (XOR, V4SFmode, operands))
    : -1 },
#line 370 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && ix86_binary_operator_ok (MULT, V2SFmode, operands)",
    __builtin_constant_p 
#line 370 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (MULT, V2SFmode, operands))
    ? (int) 
#line 370 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (MULT, V2SFmode, operands))
    : -1 },
#line 19464 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY_WRITE\n\
   /* Do not split stack checking probes.  */\n\
   && GET_CODE (operands[3]) != IOR && operands[1] != const0_rtx",
    __builtin_constant_p 
#line 19464 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY_WRITE
   /* Do not split stack checking probes.  */
   && GET_CODE (operands[3]) != IOR && operands[1] != const0_rtx)
    ? (int) 
#line 19464 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY_WRITE
   /* Do not split stack checking probes.  */
   && GET_CODE (operands[3]) != IOR && operands[1] != const0_rtx)
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMAX, V4SImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V4SImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V4SImode, operands))
    : -1 },
#line 7386 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 7386 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 7386 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 9506 "../../gcc/config/i386/i386.md"
  { "(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (DFmode == TFmode))",
    __builtin_constant_p 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (DFmode == TFmode)))
    ? (int) 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (DFmode == TFmode)))
    : -1 },
  { "(TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && ( reload_completed)",
    __builtin_constant_p (
#line 4114 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && 
#line 4116 "../../gcc/config/i386/sse.md"
( reload_completed))
    ? (int) (
#line 4114 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && 
#line 4116 "../../gcc/config/i386/sse.md"
( reload_completed))
    : -1 },
#line 12378 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATERT, SImode, operands)",
    __builtin_constant_p 
#line 12378 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, SImode, operands))
    ? (int) 
#line 12378 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, SImode, operands))
    : -1 },
#line 8895 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (XOR, QImode, operands)",
    __builtin_constant_p 
#line 8895 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, QImode, operands))
    ? (int) 
#line 8895 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, QImode, operands))
    : -1 },
#line 6903 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGCmode)\n\
   && (INTVAL (operands[2]) & 0xff) != 0x80",
    __builtin_constant_p 
#line 6903 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xff) != 0x80)
    ? (int) 
#line 6903 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xff) != 0x80)
    : -1 },
#line 8680 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (AND, SImode, operands)",
    __builtin_constant_p 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands))
    ? (int) 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands))
    : -1 },
#line 9276 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands)",
    __builtin_constant_p 
#line 9276 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands))
    ? (int) 
#line 9276 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands))
    : -1 },
#line 11885 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11885 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11885 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (XOR, V8QImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V8QImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V8QImode, operands))
    : -1 },
#line 17490 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && TARGET_C99_FUNCTIONS\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 17490 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 17490 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 5605 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5605 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 5605 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    : -1 },
#line 768 "../../gcc/config/i386/i386.md"
  { "TARGET_QIMODE_MATH",
    __builtin_constant_p 
#line 768 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH)
    ? (int) 
#line 768 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH)
    : -1 },
#line 5245 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && reload_completed",
    __builtin_constant_p 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    ? (int) 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    : -1 },
#line 10710 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
    || !TARGET_PARTIAL_FLAG_REG_STALL\n\
    || (operands[2] == const1_rtx\n\
	&& (TARGET_SHIFT1\n\
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)",
    __builtin_constant_p 
#line 10710 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    ? (int) 
#line 10710 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    : -1 },
#line 4764 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode))",
    __builtin_constant_p 
#line 4764 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)))
    ? (int) 
#line 4764 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)))
    : -1 },
#line 3497 "../../gcc/config/i386/i386.md"
  { "optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 3497 "../../gcc/config/i386/i386.md"
(optimize_function_for_speed_p (cfun))
    ? (int) 
#line 3497 "../../gcc/config/i386/i386.md"
(optimize_function_for_speed_p (cfun))
    : -1 },
#line 11667 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && ((optimize > 0 && flag_peephole2)\n\
		     ? epilogue_completed : reload_completed)",
    __builtin_constant_p 
#line 11667 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		     ? epilogue_completed : reload_completed))
    ? (int) 
#line 11667 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		     ? epilogue_completed : reload_completed))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (IOR, HImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, operands))
    : -1 },
#line 3321 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && optimize_function_for_speed_p (cfun)\n\
   && TARGET_INTEGER_DFMODE_MOVES\n\
   && (reload_in_progress || reload_completed\n\
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)\n\
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)\n\
           && optimize_function_for_size_p (cfun)\n\
	   && standard_80387_constant_p (operands[1]))\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || memory_operand (operands[0], DFmode))",
    __builtin_constant_p 
#line 3321 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && optimize_function_for_speed_p (cfun)
   && TARGET_INTEGER_DFMODE_MOVES
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode)))
    ? (int) 
#line 3321 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && optimize_function_for_speed_p (cfun)
   && TARGET_INTEGER_DFMODE_MOVES
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode)))
    : -1 },
  { "(ix86_match_ccmode (insn, CCZmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 6561 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 6561 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (XOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V2DImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V2DImode, operands))
    : -1 },
  { "(TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 5846 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)\n\
   && TARGET_SSE\n\
   && reload_completed",
    __builtin_constant_p 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    ? (int) 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    : -1 },
#line 12265 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATE, QImode, operands)",
    __builtin_constant_p 
#line 12265 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, QImode, operands))
    ? (int) 
#line 12265 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, QImode, operands))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V8HImode)\n\
       || register_operand (operands[1], V8HImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8HImode)
       || register_operand (operands[1], V8HImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8HImode)
       || register_operand (operands[1], V8HImode)))
    : -1 },
#line 9552 "../../gcc/config/i386/i386.md"
  { "((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)\n\
    || (TARGET_SSE2 && (TFmode == TFmode)))\n\
   && reload_completed",
    __builtin_constant_p 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (TFmode == TFmode)))
   && reload_completed)
    ? (int) 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (TFmode == TFmode)))
   && reload_completed)
    : -1 },
#line 12475 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATERT, QImode, operands)",
    __builtin_constant_p 
#line 12475 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, QImode, operands))
    ? (int) 
#line 12475 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, QImode, operands))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMIN, V4SImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V4SImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V4SImode, operands))
    : -1 },
#line 15278 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))\n\
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[2]))",
    __builtin_constant_p 
#line 15278 "../../gcc/config/i386/i386.md"
(reload_completed
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[2])))
    ? (int) 
#line 15278 "../../gcc/config/i386/i386.md"
(reload_completed
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[2])))
    : -1 },
#line 742 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode)",
    __builtin_constant_p 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
    ? (int) 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
    : -1 },
#line 19346 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL\n\
   && ix86_match_ccmode (insn, CCNOmode)\n\
   && true_regnum (operands[2]) != AX_REG\n\
   && peep2_reg_dead_p (1, operands[2])",
    __builtin_constant_p 
#line 19346 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL
   && ix86_match_ccmode (insn, CCNOmode)
   && true_regnum (operands[2]) != AX_REG
   && peep2_reg_dead_p (1, operands[2]))
    ? (int) 
#line 19346 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL
   && ix86_match_ccmode (insn, CCNOmode)
   && true_regnum (operands[2]) != AX_REG
   && peep2_reg_dead_p (1, operands[2]))
    : -1 },
  { "(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))\n\
   && (INTVAL (operands[3]) & 0x3f) == 0x3f) && ( 1)",
    __builtin_constant_p (
#line 13036 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x3f) == 0x3f) && 
#line 13039 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 13036 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x3f) == 0x3f) && 
#line 13039 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 19491 "../../gcc/config/i386/i386.md"
  { "(GET_MODE (operands[0]) == QImode\n\
    || GET_MODE (operands[0]) == HImode)\n\
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19491 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode
    || GET_MODE (operands[0]) == HImode)
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19491 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode
    || GET_MODE (operands[0]) == HImode)
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 10017 "../../gcc/config/i386/sse.md"
  { "TARGET_ROUND",
    __builtin_constant_p 
#line 10017 "../../gcc/config/i386/sse.md"
(TARGET_ROUND)
    ? (int) 
#line 10017 "../../gcc/config/i386/sse.md"
(TARGET_ROUND)
    : -1 },
#line 4777 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 4777 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 4777 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 3916 "../../gcc/config/i386/i386.md"
  { "TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 3916 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 3916 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
    : -1 },
#line 7606 "../../gcc/config/i386/sse.md"
  { "!TARGET_64BIT && TARGET_AVX",
    __builtin_constant_p 
#line 7606 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_AVX)
    ? (int) 
#line 7606 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_AVX)
    : -1 },
  { "(TARGET_AVX) && ( reload_completed)",
    __builtin_constant_p (
#line 11847 "../../gcc/config/i386/sse.md"
(TARGET_AVX) && 
#line 11849 "../../gcc/config/i386/sse.md"
( reload_completed))
    ? (int) (
#line 11847 "../../gcc/config/i386/sse.md"
(TARGET_AVX) && 
#line 11849 "../../gcc/config/i386/sse.md"
( reload_completed))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V8QImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V8QImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_MINUS, V8QImode, operands))
    : -1 },
#line 9604 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_unary_operator_ok (NOT, HImode, operands)",
    __builtin_constant_p 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, HImode, operands))
    ? (int) 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, HImode, operands))
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))\n\
   && ix86_binary_operator_ok (PLUS, V2SImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V2SImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V2SImode, operands))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (XFmode, DImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (XOR, V4DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (XOR, V4DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (XOR, V4DFmode, operands))
    : -1 },
#line 9107 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && ANY_QI_REG_P (operands[0])\n\
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
    && !(INTVAL (operands[2]) & ~255)\n\
    && (INTVAL (operands[2]) & 128)\n\
    && GET_MODE (operands[0]) != QImode",
    __builtin_constant_p 
#line 9107 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (operands[2]) & ~255)
    && (INTVAL (operands[2]) & 128)
    && GET_MODE (operands[0]) != QImode)
    ? (int) 
#line 9107 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (operands[2]) & ~255)
    && (INTVAL (operands[2]) & 128)
    && GET_MODE (operands[0]) != QImode)
    : -1 },
#line 169 "../../gcc/config/i386/mmx.md"
  { "TARGET_64BIT && TARGET_AVX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 169 "../../gcc/config/i386/mmx.md"
(TARGET_64BIT && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 169 "../../gcc/config/i386/mmx.md"
(TARGET_64BIT && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V16HImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V16HImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V16HImode, operands))
    : -1 },
  { "(!TARGET_PARTIAL_REG_STALL\n\
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))) && ( reload_completed)",
    __builtin_constant_p (
#line 12771 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))) && 
#line 12774 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 12771 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))) && 
#line 12774 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 13036 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))\n\
   && (INTVAL (operands[3]) & 0x3f) == 0x3f",
    __builtin_constant_p 
#line 13036 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x3f) == 0x3f)
    ? (int) 
#line 13036 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x3f) == 0x3f)
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V8QImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V8QImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_PLUS, V8QImode, operands))
    : -1 },
#line 8595 "../../gcc/config/i386/i386.md"
  { "(TARGET_FAST_PREFIX && !TARGET_PARTIAL_REG_STALL)\n\
    || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 8595 "../../gcc/config/i386/i386.md"
((TARGET_FAST_PREFIX && !TARGET_PARTIAL_REG_STALL)
    || optimize_function_for_size_p (cfun))
    ? (int) 
#line 8595 "../../gcc/config/i386/i386.md"
((TARGET_FAST_PREFIX && !TARGET_PARTIAL_REG_STALL)
    || optimize_function_for_size_p (cfun))
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MINUS, V2DImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V2DImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V2DImode, operands))
    : -1 },
#line 7909 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 7909 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V16QImode, operands))
    ? (int) 
#line 7909 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V16QImode, operands))
    : -1 },
#line 11961 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (LSHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11961 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    ? (int) 
#line 11961 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    : -1 },
#line 6202 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V4SImode, operands)",
    __builtin_constant_p 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V4SImode, operands))
    ? (int) 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V4SImode, operands))
    : -1 },
  { "(ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 4949 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || HImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    ? (int) 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    : -1 },
#line 226 "../../gcc/config/i386/mmx.md"
  { "TARGET_AVX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 226 "../../gcc/config/i386/mmx.md"
(TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 226 "../../gcc/config/i386/mmx.md"
(TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 14986 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 14986 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 14986 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 9552 "../../gcc/config/i386/i386.md"
  { "((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
    || (TARGET_SSE2 && (DFmode == TFmode)))\n\
   && reload_completed",
    __builtin_constant_p 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (DFmode == TFmode)))
   && reload_completed)
    ? (int) 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (DFmode == TFmode)))
   && reload_completed)
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (AND, V8HImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V8HImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V8HImode, operands))
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (DFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 5197 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)",
    __builtin_constant_p 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    ? (int) 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V8HImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V8HImode, operands))
    : -1 },
#line 17322 "../../gcc/config/i386/i386.md"
  { "(TARGET_USE_FANCY_MATH_387\n\
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
	|| TARGET_MIX_SSE_I387)\n\
    && flag_unsafe_math_optimizations)\n\
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
       && !flag_trapping_math)",
    __builtin_constant_p 
#line 17322 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	|| TARGET_MIX_SSE_I387)
    && flag_unsafe_math_optimizations)
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
       && !flag_trapping_math))
    ? (int) 
#line 17322 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	|| TARGET_MIX_SSE_I387)
    && flag_unsafe_math_optimizations)
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
       && !flag_trapping_math))
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))\n\
   && ix86_binary_operator_ok (MINUS, V2SImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V2SImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V2SImode, operands))
    : -1 },
  { "(ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 5409 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5409 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5409 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 15022 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (SFmode)\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 15022 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (SFmode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 15022 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (SFmode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 6372 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (EQ, V2DImode, operands)",
    __builtin_constant_p 
#line 6372 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (EQ, V2DImode, operands))
    ? (int) 
#line 6372 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (EQ, V2DImode, operands))
    : -1 },
#line 19502 "../../gcc/config/i386/i386.md"
  { "(GET_MODE (operands[0]) == HImode\n\
    || GET_MODE (operands[0]) == SImode\n\
    || (GET_MODE (operands[0]) == DImode && TARGET_64BIT))\n\
   && (optimize_insn_for_size_p () || TARGET_MOVE_M1_VIA_OR)\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19502 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == HImode
    || GET_MODE (operands[0]) == SImode
    || (GET_MODE (operands[0]) == DImode && TARGET_64BIT))
   && (optimize_insn_for_size_p () || TARGET_MOVE_M1_VIA_OR)
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19502 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == HImode
    || GET_MODE (operands[0]) == SImode
    || (GET_MODE (operands[0]) == DImode && TARGET_64BIT))
   && (optimize_insn_for_size_p () || TARGET_MOVE_M1_VIA_OR)
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 1015 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCmode)",
    __builtin_constant_p 
#line 1015 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCmode))
    ? (int) 
#line 1015 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCmode))
    : -1 },
#line 7832 "../../gcc/config/i386/i386.md"
  { "TARGET_QIMODE_MATH\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 7832 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 7832 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
  { "(ix86_match_ccmode (insn, CCGOCmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 6943 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 6943 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 8309 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && INTVAL (operands[1]) > 0\n\
   && INTVAL (operands[2]) >= 0\n\
   && INTVAL (operands[1]) + INTVAL (operands[2]) <= 32\n\
   && (GET_MODE (operands[0]) == SImode\n\
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode)\n\
       || GET_MODE (operands[0]) == HImode\n\
       || GET_MODE (operands[0]) == QImode)",
    __builtin_constant_p 
#line 8309 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && INTVAL (operands[1]) > 0
   && INTVAL (operands[2]) >= 0
   && INTVAL (operands[1]) + INTVAL (operands[2]) <= 32
   && (GET_MODE (operands[0]) == SImode
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode)
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode))
    ? (int) 
#line 8309 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && INTVAL (operands[1]) > 0
   && INTVAL (operands[2]) >= 0
   && INTVAL (operands[1]) + INTVAL (operands[2]) <= 32
   && (GET_MODE (operands[0]) == SImode
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode)
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode))
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V8HImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V8HImode, operands))
    : -1 },
#line 9295 "../../gcc/config/i386/i386.md"
  { "TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (SFmode)",
    __builtin_constant_p 
#line 9295 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (SFmode))
    ? (int) 
#line 9295 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (SFmode))
    : -1 },
#line 5470 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_SSE_MATH\n\
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 5470 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 5470 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun))
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((SImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 8680 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (AND, HImode, operands)",
    __builtin_constant_p 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, HImode, operands))
    ? (int) 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, HImode, operands))
    : -1 },
  { "(reload_completed) && (TARGET_HIMODE_MATH)",
    __builtin_constant_p (
#line 8074 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 773 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    ? (int) (
#line 8074 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 773 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMAX, V16QImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V16QImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V16QImode, operands))
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || DImode != DImode))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 2596 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !symbolic_operand (operands[1], DImode)\n\
   && !x86_64_immediate_operand (operands[1], DImode) && 1",
    __builtin_constant_p 
#line 2596 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode) && 1)
    ? (int) 
#line 2596 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode) && 1)
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || HImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 19846 "../../gcc/config/i386/i386.md"
  { "INTVAL (operands[2]) == 3\n\
   || INTVAL (operands[2]) == 5\n\
   || INTVAL (operands[2]) == 9",
    __builtin_constant_p 
#line 19846 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) == 3
   || INTVAL (operands[2]) == 5
   || INTVAL (operands[2]) == 9)
    ? (int) 
#line 19846 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) == 3
   || INTVAL (operands[2]) == 5
   || INTVAL (operands[2]) == 9)
    : -1 },
  { "(ix86_binary_operator_ok (PLUS, TImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 5918 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, TImode, operands)) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 5918 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, TImode, operands)) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 4509 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 0)",
    __builtin_constant_p 
#line 4509 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    ? (int) 
#line 4509 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    : -1 },
#line 11384 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11384 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    ? (int) 
#line 11384 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    : -1 },
#line 5717 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (XFmode, SImode)",
    __builtin_constant_p 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, SImode))
    ? (int) 
#line 5717 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, SImode))
    : -1 },
#line 5380 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && TARGET_INTER_UNIT_CONVERSIONS\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5380 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5380 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
  { "(TARGET_80387\n\
   && TARGET_SAHF && !TARGET_CMOVE) && ( reload_completed)",
    __builtin_constant_p (
#line 1251 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && TARGET_SAHF && !TARGET_CMOVE) && 
#line 1254 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 1251 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && TARGET_SAHF && !TARGET_CMOVE) && 
#line 1254 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (IOR, SImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (AND, V4HImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V4HImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V4HImode, operands))
    : -1 },
#line 13323 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[3]))\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[3])\n\
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode\n\
   && !TARGET_CMOVE",
    __builtin_constant_p 
#line 13323 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[3]))
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[1]) == GET_MODE (operands[3])
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode
   && !TARGET_CMOVE)
    ? (int) 
#line 13323 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[3]))
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[1]) == GET_MODE (operands[3])
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode
   && !TARGET_CMOVE)
    : -1 },
#line 8064 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && TARGET_64BIT",
    __builtin_constant_p 
#line 8064 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && TARGET_64BIT)
    ? (int) 
#line 8064 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && TARGET_64BIT)
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (IOR, V4HImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V4HImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V4HImode, operands))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (AND, V8SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (AND, V8SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (AND, V8SFmode, operands))
    : -1 },
#line 1028 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands)",
    __builtin_constant_p 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands))
    ? (int) 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands))
    : -1 },
#line 388 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 388 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 388 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 14148 "../../gcc/config/i386/i386.md"
  { "TARGET_POPCNT",
    __builtin_constant_p 
#line 14148 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT)
    ? (int) 
#line 14148 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT)
    : -1 },
#line 7339 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && reload_completed \n\
   && ix86_lea_for_add_ok (PLUS, insn, operands)",
    __builtin_constant_p 
#line 7339 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && reload_completed 
   && ix86_lea_for_add_ok (PLUS, insn, operands))
    ? (int) 
#line 7339 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && reload_completed 
   && ix86_lea_for_add_ok (PLUS, insn, operands))
    : -1 },
  { "(TARGET_SSE2) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3658 "../../gcc/config/i386/i386.md"
(TARGET_SSE2) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    ? (int) (
#line 3658 "../../gcc/config/i386/i386.md"
(TARGET_SSE2) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    : -1 },
#line 9856 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun)\n\
       || !TARGET_PARTIAL_FLAG_REG_STALL\n\
       || (operands[2] == const1_rtx\n\
	   && (TARGET_SHIFT1\n\
	       || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, DImode, operands)",
    __builtin_constant_p 
#line 9856 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    ? (int) 
#line 9856 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    : -1 },
#line 5583 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5583 "../../gcc/config/i386/sse.md"
(TARGET_SSE2
   && can_create_pseudo_p ())
    ? (int) 
#line 5583 "../../gcc/config/i386/sse.md"
(TARGET_SSE2
   && can_create_pseudo_p ())
    : -1 },
#line 17529 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V8SImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V8SImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V8SImode, operands))
    : -1 },
#line 3882 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && ANY_QI_REG_P (operands[0])\n\
   && (TARGET_ZERO_EXTEND_WITH_AND\n\
       && optimize_function_for_speed_p (cfun))\n\
   && !reg_overlap_mentioned_p (operands[0], operands[1])",
    __builtin_constant_p 
#line 3882 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (operands[0])
   && (TARGET_ZERO_EXTEND_WITH_AND
       && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (operands[0], operands[1]))
    ? (int) 
#line 3882 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (operands[0])
   && (TARGET_ZERO_EXTEND_WITH_AND
       && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (operands[0], operands[1]))
    : -1 },
#line 19232 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p () && ix86_match_ccmode (insn, CCNOmode)",
    __builtin_constant_p 
#line 19232 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ix86_match_ccmode (insn, CCNOmode))
    ? (int) 
#line 19232 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ix86_match_ccmode (insn, CCNOmode))
    : -1 },
#line 7980 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && X87_ENABLE_ARITH (SFmode))\n\
    || TARGET_SSE_MATH",
    __builtin_constant_p 
#line 7980 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (SFmode))
    || TARGET_SSE_MATH)
    ? (int) 
#line 7980 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (SFmode))
    || TARGET_SSE_MATH)
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V1TImode)\n\
       || register_operand (operands[1], V1TImode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V1TImode)
       || register_operand (operands[1], V1TImode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V1TImode)
       || register_operand (operands[1], V1TImode)))
    : -1 },
  { "(TARGET_SSE) && ( reload_completed\n\
   && (TARGET_INTER_UNIT_MOVES\n\
       || MEM_P (operands [0])\n\
       || !GENERAL_REGNO_P (true_regnum (operands [0]))))",
    __builtin_constant_p (
#line 7290 "../../gcc/config/i386/sse.md"
(TARGET_SSE) && 
#line 7292 "../../gcc/config/i386/sse.md"
( reload_completed
   && (TARGET_INTER_UNIT_MOVES
       || MEM_P (operands [0])
       || !GENERAL_REGNO_P (true_regnum (operands [0])))))
    ? (int) (
#line 7290 "../../gcc/config/i386/sse.md"
(TARGET_SSE) && 
#line 7292 "../../gcc/config/i386/sse.md"
( reload_completed
   && (TARGET_INTER_UNIT_MOVES
       || MEM_P (operands [0])
       || !GENERAL_REGNO_P (true_regnum (operands [0])))))
    : -1 },
#line 10219 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
     || !TARGET_PARTIAL_FLAG_REG_STALL\n\
     || (operands[2] == const1_rtx\n\
	 && (TARGET_SHIFT1\n\
	     || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, SImode, operands)",
    __builtin_constant_p 
#line 10219 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
     || !TARGET_PARTIAL_FLAG_REG_STALL
     || (operands[2] == const1_rtx
	 && (TARGET_SHIFT1
	     || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    ? (int) 
#line 10219 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
     || !TARGET_PARTIAL_FLAG_REG_STALL
     || (operands[2] == const1_rtx
	 && (TARGET_SHIFT1
	     || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    : -1 },
#line 7948 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 7948 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V8HImode, operands))
    ? (int) 
#line 7948 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V8HImode, operands))
    : -1 },
#line 277 "../../gcc/config/i386/mmx.md"
  { "!TARGET_64BIT && reload_completed\n\
   && (!MMX_REG_P (operands[0]) && !SSE_REG_P (operands[0]))\n\
   && (!MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1]))",
    __builtin_constant_p 
#line 277 "../../gcc/config/i386/mmx.md"
(!TARGET_64BIT && reload_completed
   && (!MMX_REG_P (operands[0]) && !SSE_REG_P (operands[0]))
   && (!MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1])))
    ? (int) 
#line 277 "../../gcc/config/i386/mmx.md"
(!TARGET_64BIT && reload_completed
   && (!MMX_REG_P (operands[0]) && !SSE_REG_P (operands[0]))
   && (!MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1])))
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))\n\
   && ix86_binary_operator_ok (PLUS, V8QImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V8QImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V8QImode, operands))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V32QImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V32QImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V32QImode, operands))
    : -1 },
#line 8540 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (AND, HImode, operands)",
    __builtin_constant_p 
#line 8540 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, HImode, operands))
    ? (int) 
#line 8540 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, HImode, operands))
    : -1 },
#line 13131 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_BT || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 13131 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun))
    ? (int) 
#line 13131 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun))
    : -1 },
  { "(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))) && ( 1)",
    __builtin_constant_p (
#line 13003 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))) && 
#line 13005 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 13003 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || optimize_function_for_size_p (cfun))) && 
#line 13005 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V8QImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V8QImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V8QImode, operands))
    : -1 },
#line 15646 "../../gcc/config/i386/i386.md"
  { "find_regno_note (insn, REG_UNUSED, REGNO (operands[1]))\n\
   && !(reload_completed || reload_in_progress)",
    __builtin_constant_p 
#line 15646 "../../gcc/config/i386/i386.md"
(find_regno_note (insn, REG_UNUSED, REGNO (operands[1]))
   && !(reload_completed || reload_in_progress))
    ? (int) 
#line 15646 "../../gcc/config/i386/i386.md"
(find_regno_note (insn, REG_UNUSED, REGNO (operands[1]))
   && !(reload_completed || reload_in_progress))
    : -1 },
#line 16583 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16583 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16583 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MINUS, V4SImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V4SImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V4SImode, operands))
    : -1 },
#line 18684 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 18684 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 18684 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    : -1 },
#line 10269 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
    || !TARGET_PARTIAL_FLAG_REG_STALL\n\
    || (operands[2] == const1_rtx\n\
	&& (TARGET_SHIFT1\n\
	    || TARGET_DOUBLE_WITH_ADD)))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, SImode, operands)",
    __builtin_constant_p 
#line 10269 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    ? (int) 
#line 10269 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    : -1 },
#line 362 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 18973 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL && reload_completed\n\
   && ((GET_MODE (operands[0]) == HImode\n\
	&& ((optimize_function_for_speed_p (cfun) && !TARGET_FAST_PREFIX)\n\
            /* ??? next two lines just !satisfies_constraint_K (...) */\n\
	    || !CONST_INT_P (operands[2])\n\
	    || satisfies_constraint_K (operands[2])))\n\
       || (GET_MODE (operands[0]) == QImode\n\
	   && (TARGET_PROMOTE_QImode || optimize_function_for_size_p (cfun))))",
    __builtin_constant_p 
#line 18973 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ((GET_MODE (operands[0]) == HImode
	&& ((optimize_function_for_speed_p (cfun) && !TARGET_FAST_PREFIX)
            /* ??? next two lines just !satisfies_constraint_K (...) */
	    || !CONST_INT_P (operands[2])
	    || satisfies_constraint_K (operands[2])))
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode || optimize_function_for_size_p (cfun)))))
    ? (int) 
#line 18973 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ((GET_MODE (operands[0]) == HImode
	&& ((optimize_function_for_speed_p (cfun) && !TARGET_FAST_PREFIX)
            /* ??? next two lines just !satisfies_constraint_K (...) */
	    || !CONST_INT_P (operands[2])
	    || satisfies_constraint_K (operands[2])))
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode || optimize_function_for_size_p (cfun)))))
    : -1 },
#line 14922 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14922 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14922 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 12007 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 12007 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    ? (int) 
#line 12007 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    : -1 },
#line 5434 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5434 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5434 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (PLUS, V2DImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V2DImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V2DImode, operands))
    : -1 },
#line 4868 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH\n\
   && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 4868 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH
   && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 4868 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH
   && optimize_function_for_speed_p (cfun))
    : -1 },
#line 5818 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)\n\
   && TARGET_SSE",
    __builtin_constant_p 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE)
    ? (int) 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE)
    : -1 },
#line 9258 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NEG, QImode, operands)",
    __builtin_constant_p 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, QImode, operands))
    ? (int) 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, QImode, operands))
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V16QImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V16QImode, operands))
    : -1 },
#line 6202 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V8HImode, operands)",
    __builtin_constant_p 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V8HImode, operands))
    ? (int) 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMAX, V8HImode, operands))
    : -1 },
#line 15689 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && flag_unsafe_math_optimizations\n\
   && standard_80387_constant_p (operands[3]) == 2",
    __builtin_constant_p 
#line 15689 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    ? (int) 
#line 15689 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    : -1 },
#line 17402 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 17402 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations)
    ? (int) 
#line 17402 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations)
    : -1 },
#line 6482 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)",
    __builtin_constant_p 
#line 6482 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2))
    ? (int) 
#line 6482 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2))
    : -1 },
  { "(TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5530 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX
   && can_create_pseudo_p ()) && 
#line 5533 "../../gcc/config/i386/sse.md"
( 1))
    ? (int) (
#line 5530 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_SSE4_1 && !TARGET_AVX
   && can_create_pseudo_p ()) && 
#line 5533 "../../gcc/config/i386/sse.md"
( 1))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V2DFmode, operands))
    : -1 },
#line 5757 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 5757 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
    : -1 },
#line 12391 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands)",
    __builtin_constant_p 
#line 12391 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    ? (int) 
#line 12391 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    : -1 },
#line 9295 "../../gcc/config/i386/i386.md"
  { "TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (DFmode)",
    __builtin_constant_p 
#line 9295 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (DFmode))
    ? (int) 
#line 9295 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387 && SSE_FLOAT_MODE_P (DFmode))
    : -1 },
  { "(TARGET_USE_BT || optimize_function_for_size_p (cfun)) && ( 1)",
    __builtin_constant_p (
#line 13131 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)) && 
#line 13133 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 13131 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)) && 
#line 13133 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 15368 "../../gcc/config/i386/i386.md"
  { "(TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (DFmode))\n\
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 15368 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (DFmode))
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 15368 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (DFmode))
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 12365 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATERT, SImode, operands)",
    __builtin_constant_p 
#line 12365 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    ? (int) 
#line 12365 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    : -1 },
#line 8974 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (XOR, SImode, operands)",
    __builtin_constant_p 
#line 8974 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands))
    ? (int) 
#line 8974 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V4DFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4DFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4DFmode, operands))
    : -1 },
#line 5434 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5434 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5434 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 11132 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11132 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11132 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 14907 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (DFmode)\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14907 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14907 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V16HImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V16HImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V16HImode, operands))
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (DFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 6337 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (EQ, V16QImode, operands)",
    __builtin_constant_p 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V16QImode, operands))
    ? (int) 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V16QImode, operands))
    : -1 },
  { "(TARGET_CMPXCHG) && (TARGET_64BIT || TARGET_CMPXCHG8B)",
    __builtin_constant_p (
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 22 "../../gcc/config/i386/sync.md"
(TARGET_64BIT || TARGET_CMPXCHG8B))
    ? (int) (
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 22 "../../gcc/config/i386/sync.md"
(TARGET_64BIT || TARGET_CMPXCHG8B))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (XOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V8HImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V8HImode, operands))
    : -1 },
#line 841 "../../gcc/config/i386/i386.md"
  { "Pmode == SImode",
    __builtin_constant_p 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode)
    ? (int) 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode)
    : -1 },
#line 5639 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5639 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5639 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
  { "(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH\n\
   && optimize_function_for_speed_p (cfun)) && ( reload_completed)",
    __builtin_constant_p (
#line 4868 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH
   && optimize_function_for_speed_p (cfun)) && 
#line 4871 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 4868 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH
   && optimize_function_for_speed_p (cfun)) && 
#line 4871 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 13249 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])\n\
   && !TARGET_CMOVE",
    __builtin_constant_p 
#line 13249 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && !TARGET_CMOVE)
    ? (int) 
#line 13249 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && !TARGET_CMOVE)
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || SImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 931 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)",
    __builtin_constant_p 
#line 931 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode))
    ? (int) 
#line 931 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode))
    : -1 },
#line 10471 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
    || !TARGET_PARTIAL_FLAG_REG_STALL\n\
    || (operands[2] == const1_rtx\n\
	&& (TARGET_SHIFT1\n\
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)",
    __builtin_constant_p 
#line 10471 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    ? (int) 
#line 10471 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (operands[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    : -1 },
#line 3780 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && !(SSE_REG_P (operands[0]) || SSE_REG_P (operands[1]))",
    __builtin_constant_p 
#line 3780 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(SSE_REG_P (operands[0]) || SSE_REG_P (operands[1])))
    ? (int) 
#line 3780 "../../gcc/config/i386/i386.md"
(reload_completed
   && !(SSE_REG_P (operands[0]) || SSE_REG_P (operands[1])))
    : -1 },
#line 10320 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun)\n\
       || !TARGET_PARTIAL_FLAG_REG_STALL\n\
       || (operands[2] == const1_rtx\n\
	   && (TARGET_SHIFT1\n\
	       || TARGET_DOUBLE_WITH_ADD)))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, SImode, operands)",
    __builtin_constant_p 
#line 10320 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    ? (int) 
#line 10320 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    : -1 },
#line 3556 "../../gcc/config/i386/i386.md"
  { "optimize_function_for_speed_p (cfun)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && (reload_in_progress || reload_completed\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || memory_operand (operands[0], XFmode))",
    __builtin_constant_p 
#line 3556 "../../gcc/config/i386/i386.md"
(optimize_function_for_speed_p (cfun)
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode)))
    ? (int) 
#line 3556 "../../gcc/config/i386/i386.md"
(optimize_function_for_speed_p (cfun)
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode)))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_MINUS, V16QImode, operands))
    : -1 },
#line 574 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands)",
    __builtin_constant_p 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands))
    ? (int) 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands))
    : -1 },
  { "(TARGET_LWP) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 20811 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 20811 "../../gcc/config/i386/i386.md"
(TARGET_LWP) && 
#line 760 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 14769 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_GNU2_TLS",
    __builtin_constant_p 
#line 14769 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_GNU2_TLS)
    ? (int) 
#line 14769 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_GNU2_TLS)
    : -1 },
#line 1479 "../../gcc/config/i386/sse.md"
  { "!TARGET_XOP \n\
  && (SSE_FLOAT_MODE_P (DFmode) || SSE_VEC_FLOAT_MODE_P (DFmode))",
    __builtin_constant_p 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (DFmode) || SSE_VEC_FLOAT_MODE_P (DFmode)))
    ? (int) 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (DFmode) || SSE_VEC_FLOAT_MODE_P (DFmode)))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (AND, V2DImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V2DImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V2DImode, operands))
    : -1 },
  { "(reload_completed) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9208 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9208 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 778 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 10996 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)",
    __builtin_constant_p 
#line 10996 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    ? (int) 
#line 10996 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (IOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V4SImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V4SImode, operands))
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (DFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 6587 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (XOR, TFmode, operands)",
    __builtin_constant_p 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, TFmode, operands))
    ? (int) 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, TFmode, operands))
    : -1 },
#line 6587 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (AND, TFmode, operands)",
    __builtin_constant_p 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, TFmode, operands))
    ? (int) 
#line 6587 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, TFmode, operands))
    : -1 },
#line 19970 "../../gcc/config/i386/i386.md"
  { "TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()\n\
   && satisfies_constraint_K (operands[2])",
    __builtin_constant_p 
#line 19970 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()
   && satisfies_constraint_K (operands[2]))
    ? (int) 
#line 19970 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()
   && satisfies_constraint_K (operands[2]))
    : -1 },
#line 8384 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && QI_REG_P (operands[2])\n\
    && GET_MODE (operands[2]) != QImode\n\
    && ((ix86_match_ccmode (insn, CCZmode)\n\
    	 && !(INTVAL (operands[3]) & ~(255 << 8)))\n\
	|| (ix86_match_ccmode (insn, CCNOmode)\n\
	    && !(INTVAL (operands[3]) & ~(127 << 8))))",
    __builtin_constant_p 
#line 8384 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[2])
    && GET_MODE (operands[2]) != QImode
    && ((ix86_match_ccmode (insn, CCZmode)
    	 && !(INTVAL (operands[3]) & ~(255 << 8)))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (operands[3]) & ~(127 << 8)))))
    ? (int) 
#line 8384 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[2])
    && GET_MODE (operands[2]) != QImode
    && ((ix86_match_ccmode (insn, CCZmode)
    	 && !(INTVAL (operands[3]) & ~(255 << 8)))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (operands[3]) & ~(127 << 8)))))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (XOR, QImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, operands))
    : -1 },
#line 19218 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && TARGET_SPLIT_LONG_MOVES\n\
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn",
    __builtin_constant_p 
#line 19218 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn)
    ? (int) 
#line 19218 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn)
    : -1 },
#line 5197 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)",
    __builtin_constant_p 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    ? (int) 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    : -1 },
#line 3972 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && true_regnum (operands[0]) == true_regnum (operands[1])",
    __builtin_constant_p 
#line 3972 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) == true_regnum (operands[1]))
    ? (int) 
#line 3972 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) == true_regnum (operands[1]))
    : -1 },
#line 26 "../../gcc/config/i386/sync.md"
  { "TARGET_64BIT && TARGET_CMPXCHG16B",
    __builtin_constant_p 
#line 26 "../../gcc/config/i386/sync.md"
(TARGET_64BIT && TARGET_CMPXCHG16B)
    ? (int) 
#line 26 "../../gcc/config/i386/sync.md"
(TARGET_64BIT && TARGET_CMPXCHG16B)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V1TImode)\n\
       || register_operand (operands[1], V1TImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V1TImode)
       || register_operand (operands[1], V1TImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V1TImode)
       || register_operand (operands[1], V1TImode)))
    : -1 },
#line 10897 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && INTVAL (operands[2]) == 63\n\
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)",
    __builtin_constant_p 
#line 10897 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && INTVAL (operands[2]) == 63
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    ? (int) 
#line 10897 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && INTVAL (operands[2]) == 63
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    : -1 },
#line 4573 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 4573 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH)
    ? (int) 
#line 4573 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_SSE_MATH)
    : -1 },
#line 7177 "../../gcc/config/i386/i386.md"
  { "(GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[2])\n\
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])\n\
       || GET_MODE (operands[3]) == VOIDmode)",
    __builtin_constant_p 
#line 7177 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[2])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode))
    ? (int) 
#line 7177 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[2])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode))
    : -1 },
#line 12155 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATE, SImode, operands)",
    __builtin_constant_p 
#line 12155 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, SImode, operands))
    ? (int) 
#line 12155 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, SImode, operands))
    : -1 },
#line 14705 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_GNU2_TLS",
    __builtin_constant_p 
#line 14705 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_GNU2_TLS)
    ? (int) 
#line 14705 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_GNU2_TLS)
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (AND, V16QImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V16QImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V16QImode, operands))
    : -1 },
#line 4712 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 4712 "../../gcc/config/i386/i386.md"
(TARGET_80387 && flag_unsafe_math_optimizations)
    ? (int) 
#line 4712 "../../gcc/config/i386/i386.md"
(TARGET_80387 && flag_unsafe_math_optimizations)
    : -1 },
#line 12463 "../../gcc/config/i386/i386.md"
  { "(! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 12463 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 12463 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands))
    : -1 },
  { "(ix86_match_ccmode (insn, CCmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 920 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 920 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (AND, V2DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (AND, V2DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (AND, V2DFmode, operands))
    : -1 },
#line 19251 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && ((TARGET_NOT_UNPAIRABLE\n\
        && (!MEM_P (operands[0])\n\
            || !memory_displacement_operand (operands[0], SImode)))\n\
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], SImode)))\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19251 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], SImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], SImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19251 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], SImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], SImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
  { "((TARGET_USE_BT || optimize_function_for_size_p (cfun))\n\
   && (INTVAL (operands[3]) & 0x1f) == 0x1f) && ( 1)",
    __builtin_constant_p (
#line 13168 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x1f) == 0x1f) && 
#line 13171 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 13168 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x1f) == 0x1f) && 
#line 13171 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 1647 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)",
    __builtin_constant_p 
#line 1647 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode))
    ? (int) 
#line 1647 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode))
    : -1 },
  { "(TARGET_SSE2) && (TARGET_SSE4_2)",
    __builtin_constant_p (
#line 6438 "../../gcc/config/i386/sse.md"
(TARGET_SSE2) && 
#line 76 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2))
    ? (int) (
#line 6438 "../../gcc/config/i386/sse.md"
(TARGET_SSE2) && 
#line 76 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2))
    : -1 },
#line 16729 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && ((SImode != DImode) || TARGET_64BIT)",
    __builtin_constant_p 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT))
    ? (int) 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((SImode != DImode) || TARGET_64BIT))
    : -1 },
#line 8895 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (IOR, QImode, operands)",
    __builtin_constant_p 
#line 8895 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, QImode, operands))
    ? (int) 
#line 8895 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, QImode, operands))
    : -1 },
#line 11692 "../../gcc/config/i386/sse.md"
  { "TARGET_PCLMUL && TARGET_AVX",
    __builtin_constant_p 
#line 11692 "../../gcc/config/i386/sse.md"
(TARGET_PCLMUL && TARGET_AVX)
    ? (int) 
#line 11692 "../../gcc/config/i386/sse.md"
(TARGET_PCLMUL && TARGET_AVX)
    : -1 },
#line 19536 "../../gcc/config/i386/i386.md"
  { "peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19536 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19536 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 1394 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 1394 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 1394 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 2410 "../../gcc/config/i386/sse.md"
  { "TARGET_FMA4",
    __builtin_constant_p 
#line 2410 "../../gcc/config/i386/sse.md"
(TARGET_FMA4)
    ? (int) 
#line 2410 "../../gcc/config/i386/sse.md"
(TARGET_FMA4)
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))\n\
   && ix86_binary_operator_ok (MINUS, V4HImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V4HImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V4HImode, operands))
    : -1 },
#line 12352 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATERT, SImode, operands)",
    __builtin_constant_p 
#line 12352 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    ? (int) 
#line 12352 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, operands))
    : -1 },
#line 18525 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && TARGET_CMOVE)\n\
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 7488 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (MINUS, HImode, operands)",
    __builtin_constant_p 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands))
    ? (int) 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (IOR, V2DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (IOR, V2DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (IOR, V2DFmode, operands))
    : -1 },
#line 12110 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands)",
    __builtin_constant_p 
#line 12110 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands))
    ? (int) 
#line 12110 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands))
    : -1 },
#line 5887 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5887 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_SSE_MATH)
    ? (int) 
#line 5887 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_SSE_MATH)
    : -1 },
#line 5605 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5605 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 5605 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((SImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((SImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V4SImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V4SImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V4SImode, operands))
    : -1 },
#line 7488 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (MINUS, SImode, operands)",
    __builtin_constant_p 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    ? (int) 
#line 7488 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands))
    : -1 },
#line 1588 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (PLUS, V4HImode, operands)",
    __builtin_constant_p 
#line 1588 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (PLUS, V4HImode, operands))
    ? (int) 
#line 1588 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (PLUS, V4HImode, operands))
    : -1 },
#line 397 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V2SFmode, operands)",
    __builtin_constant_p 
#line 397 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2SFmode, operands))
    ? (int) 
#line 397 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2SFmode, operands))
    : -1 },
#line 9463 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (reload_completed\n\
       || !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 9463 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (reload_completed
       || !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)))
    : -1 },
  { "(TARGET_XOP) && ( reload_completed)",
    __builtin_constant_p (
#line 10478 "../../gcc/config/i386/sse.md"
(TARGET_XOP) && 
#line 10480 "../../gcc/config/i386/sse.md"
( reload_completed))
    ? (int) (
#line 10478 "../../gcc/config/i386/sse.md"
(TARGET_XOP) && 
#line 10480 "../../gcc/config/i386/sse.md"
( reload_completed))
    : -1 },
  { "(TARGET_CMPXCHG) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 117 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 117 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V8SFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V8SFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V8SFmode, operands))
    : -1 },
#line 1688 "../../gcc/config/i386/sse.md"
  { "AVX_FLOAT_MODE_P (DFmode)",
    __builtin_constant_p 
#line 1688 "../../gcc/config/i386/sse.md"
(AVX_FLOAT_MODE_P (DFmode))
    ? (int) 
#line 1688 "../../gcc/config/i386/sse.md"
(AVX_FLOAT_MODE_P (DFmode))
    : -1 },
#line 20156 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && !SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 20156 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn))
    ? (int) 
#line 20156 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn))
    : -1 },
#line 4635 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && !(TARGET_SSE2 && TARGET_SSE_MATH)\n\
   && !TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 4635 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(TARGET_SSE2 && TARGET_SSE_MATH)
   && !TARGET_MIX_SSE_I387)
    ? (int) 
#line 4635 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(TARGET_SSE2 && TARGET_SSE_MATH)
   && !TARGET_MIX_SSE_I387)
    : -1 },
#line 17261 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math",
    __builtin_constant_p 
#line 17261 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math)
    ? (int) 
#line 17261 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math)
    : -1 },
  { "(ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_unary_operator_ok (NOT, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 10914 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)",
    __builtin_constant_p 
#line 10914 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    ? (int) 
#line 10914 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    : -1 },
#line 15063 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (DFmode, SImode)\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, SImode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, SImode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (XFmode, SImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (XFmode, SImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 18525 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && TARGET_CMOVE)\n\
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 18525 "../../gcc/config/i386/i386.md"
((TARGET_80387 && TARGET_CMOVE)
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 3944 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))\n\
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1]))",
    __builtin_constant_p 
#line 3944 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1])))
    ? (int) 
#line 3944 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1])))
    : -1 },
#line 12240 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATE, QImode, operands)",
    __builtin_constant_p 
#line 12240 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, QImode, operands))
    ? (int) 
#line 12240 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, QImode, operands))
    : -1 },
#line 4894 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)\n\
   && (!TARGET_FISTTP || TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    ? (int) 
#line 4894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    : -1 },
#line 1479 "../../gcc/config/i386/sse.md"
  { "!TARGET_XOP \n\
  && (SSE_FLOAT_MODE_P (SFmode) || SSE_VEC_FLOAT_MODE_P (SFmode))",
    __builtin_constant_p 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (SFmode) || SSE_VEC_FLOAT_MODE_P (SFmode)))
    ? (int) 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (SFmode) || SSE_VEC_FLOAT_MODE_P (SFmode)))
    : -1 },
#line 15689 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && flag_unsafe_math_optimizations\n\
   && standard_80387_constant_p (operands[3]) == 2",
    __builtin_constant_p 
#line 15689 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    ? (int) 
#line 15689 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    : -1 },
#line 990 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (UMIN, V8QImode, operands)",
    __builtin_constant_p 
#line 990 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (UMIN, V8QImode, operands))
    ? (int) 
#line 990 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (UMIN, V8QImode, operands))
    : -1 },
#line 5818 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)\n\
   && TARGET_SSE",
    __builtin_constant_p 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE)
    ? (int) 
#line 5818 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE)
    : -1 },
#line 15257 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))\n\
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 15257 "../../gcc/config/i386/i386.md"
(reload_completed
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[1])))
    ? (int) 
#line 15257 "../../gcc/config/i386/i386.md"
(reload_completed
   && X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && X87_ENABLE_FLOAT (GET_MODE (operands[0]), GET_MODE (operands[1])))
    : -1 },
#line 13969 "../../gcc/config/i386/i386.md"
  { "epilogue_completed",
    __builtin_constant_p 
#line 13969 "../../gcc/config/i386/i386.md"
(epilogue_completed)
    ? (int) 
#line 13969 "../../gcc/config/i386/i386.md"
(epilogue_completed)
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands))
    : -1 },
#line 19750 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_size_p () || !TARGET_SUB_ESP_4",
    __builtin_constant_p 
#line 19750 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4)
    ? (int) 
#line 19750 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4)
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V32QImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V32QImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V32QImode, operands))
    : -1 },
#line 4825 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && !(SSE_FLOAT_MODE_P (XFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (XFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    ? (int) 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (XFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    : -1 },
#line 1412 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && reload_completed",
    __builtin_constant_p 
#line 1412 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && reload_completed)
    ? (int) 
#line 1412 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && reload_completed)
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V2DImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V2DImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V2DImode, operands))
    : -1 },
#line 18506 "../../gcc/config/i386/i386.md"
  { "TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL",
    __builtin_constant_p 
#line 18506 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL)
    ? (int) 
#line 18506 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !TARGET_PARTIAL_REG_STALL)
    : -1 },
#line 3509 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && (GET_MODE (operands[0]) == XFmode\n\
       || GET_MODE (operands[0]) == DFmode)\n\
   && !ANY_FP_REG_P (operands[1])",
    __builtin_constant_p 
#line 3509 "../../gcc/config/i386/i386.md"
(reload_completed
   && (GET_MODE (operands[0]) == XFmode
       || GET_MODE (operands[0]) == DFmode)
   && !ANY_FP_REG_P (operands[1]))
    ? (int) 
#line 3509 "../../gcc/config/i386/i386.md"
(reload_completed
   && (GET_MODE (operands[0]) == XFmode
       || GET_MODE (operands[0]) == DFmode)
   && !ANY_FP_REG_P (operands[1]))
    : -1 },
#line 19002 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL && reload_completed\n\
   && optimize_insn_for_speed_p ()\n\
   && ((GET_MODE (operands[1]) == HImode && ! TARGET_FAST_PREFIX)\n\
       || (GET_MODE (operands[1]) == QImode && TARGET_PROMOTE_QImode))\n\
   /* Ensure that the operand will remain sign-extended immediate.  */\n\
   && ix86_match_ccmode (insn, INTVAL (operands[4]) >= 0 ? CCNOmode : CCZmode)",
    __builtin_constant_p 
#line 19002 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && optimize_insn_for_speed_p ()
   && ((GET_MODE (operands[1]) == HImode && ! TARGET_FAST_PREFIX)
       || (GET_MODE (operands[1]) == QImode && TARGET_PROMOTE_QImode))
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (operands[4]) >= 0 ? CCNOmode : CCZmode))
    ? (int) 
#line 19002 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && optimize_insn_for_speed_p ()
   && ((GET_MODE (operands[1]) == HImode && ! TARGET_FAST_PREFIX)
       || (GET_MODE (operands[1]) == QImode && TARGET_PROMOTE_QImode))
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (operands[4]) >= 0 ? CCNOmode : CCZmode))
    : -1 },
#line 1467 "../../gcc/config/i386/i386.md"
  { "TARGET_MIX_SSE_I387\n\
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])",
    __builtin_constant_p 
#line 1467 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    ? (int) 
#line 1467 "../../gcc/config/i386/i386.md"
(TARGET_MIX_SSE_I387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    : -1 },
#line 3459 "../../gcc/config/i386/i386.md"
  { "reload_completed || TARGET_80387",
    __builtin_constant_p 
#line 3459 "../../gcc/config/i386/i386.md"
(reload_completed || TARGET_80387)
    ? (int) 
#line 3459 "../../gcc/config/i386/i386.md"
(reload_completed || TARGET_80387)
    : -1 },
#line 2674 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE && !TARGET_64BIT\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 2674 "../../gcc/config/i386/i386.md"
(TARGET_SSE && !TARGET_64BIT
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 2674 "../../gcc/config/i386/i386.md"
(TARGET_SSE && !TARGET_64BIT
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 4825 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (DFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    ? (int) 
#line 4825 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && !(SSE_FLOAT_MODE_P (DFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
    : -1 },
#line 19891 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && optimize_insn_for_speed_p ()\n\
   && (INTVAL (operands[2]) == 3\n\
       || INTVAL (operands[2]) == 5\n\
       || INTVAL (operands[2]) == 9)",
    __builtin_constant_p 
#line 19891 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && optimize_insn_for_speed_p ()
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    ? (int) 
#line 19891 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && optimize_insn_for_speed_p ()
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V8HImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_PLUS, V8HImode, operands))
    : -1 },
#line 6302 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_2",
    __builtin_constant_p 
#line 6302 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2)
    ? (int) 
#line 6302 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2)
    : -1 },
#line 3485 "../../gcc/config/i386/i386.md"
  { "optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 3485 "../../gcc/config/i386/i386.md"
(optimize_function_for_size_p (cfun))
    ? (int) 
#line 3485 "../../gcc/config/i386/i386.md"
(optimize_function_for_size_p (cfun))
    : -1 },
  { "(TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && ( reload_completed)",
    __builtin_constant_p (
#line 1373 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && 
#line 1375 "../../gcc/config/i386/mmx.md"
( reload_completed))
    ? (int) (
#line 1373 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && !(MEM_P (operands[0]) && MEM_P (operands[1]))) && 
#line 1375 "../../gcc/config/i386/mmx.md"
( reload_completed))
    : -1 },
#line 14892 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14892 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14892 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 11658 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_CMOVE",
    __builtin_constant_p 
#line 11658 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_CMOVE)
    ? (int) 
#line 11658 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_CMOVE)
    : -1 },
#line 6337 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (EQ, V4SImode, operands)",
    __builtin_constant_p 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V4SImode, operands))
    ? (int) 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V4SImode, operands))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V8SImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V8SImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V8SImode, operands))
    : -1 },
#line 14234 "../../gcc/config/i386/i386.md"
  { "TARGET_BSWAP",
    __builtin_constant_p 
#line 14234 "../../gcc/config/i386/i386.md"
(TARGET_BSWAP)
    ? (int) 
#line 14234 "../../gcc/config/i386/i386.md"
(TARGET_BSWAP)
    : -1 },
#line 5865 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && ((TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)\n\
	&& TARGET_SSE)\n\
       || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)))
    : -1 },
#line 971 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (SMAX, V4HImode, operands)",
    __builtin_constant_p 
#line 971 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (SMAX, V4HImode, operands))
    ? (int) 
#line 971 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (SMAX, V4HImode, operands))
    : -1 },
#line 5257 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
        || TARGET_MIX_SSE_I387)\n\
    && reload_completed",
    __builtin_constant_p 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    ? (int) 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (XFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
  { "(ix86_match_ccmode (insn, CCGOCmode)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 931 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 931 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 14219 "../../gcc/config/i386/i386.md"
  { "TARGET_MOVBE && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 14219 "../../gcc/config/i386/i386.md"
(TARGET_MOVBE && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 14219 "../../gcc/config/i386/i386.md"
(TARGET_MOVBE && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 13323 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[3]))\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[3])\n\
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode\n\
   && !TARGET_CMOVE",
    __builtin_constant_p 
#line 13323 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[3]))
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[1]) == GET_MODE (operands[3])
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode
   && !TARGET_CMOVE)
    ? (int) 
#line 13323 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[3]))
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[1]) == GET_MODE (operands[3])
   && ix86_fp_compare_mode (swap_condition (GET_CODE (operands[0]))) == CCFPmode
   && !TARGET_CMOVE)
    : -1 },
#line 5520 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (MULT, V4SImode, operands)",
    __builtin_constant_p 
#line 5520 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (MULT, V4SImode, operands))
    ? (int) 
#line 5520 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (MULT, V4SImode, operands))
    : -1 },
#line 18602 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && TARGET_CMOVE",
    __builtin_constant_p 
#line 18602 "../../gcc/config/i386/i386.md"
(TARGET_80387 && TARGET_CMOVE)
    ? (int) 
#line 18602 "../../gcc/config/i386/i386.md"
(TARGET_80387 && TARGET_CMOVE)
    : -1 },
#line 15675 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && flag_unsafe_math_optimizations\n\
   && standard_80387_constant_p (operands[3]) == 2",
    __builtin_constant_p 
#line 15675 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    ? (int) 
#line 15675 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && standard_80387_constant_p (operands[3]) == 2)
    : -1 },
#line 7884 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 7884 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V16QImode, operands))
    ? (int) 
#line 7884 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V16QImode, operands))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (XOR, V2DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (XOR, V2DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (XOR, V2DFmode, operands))
    : -1 },
  { "((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (SFmode == TFmode))) && ( reload_completed)",
    __builtin_constant_p (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (SFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (SFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 1523 "../../gcc/config/i386/mmx.md"
  { "TARGET_SSE || TARGET_3DNOW",
    __builtin_constant_p 
#line 1523 "../../gcc/config/i386/mmx.md"
(TARGET_SSE || TARGET_3DNOW)
    ? (int) 
#line 1523 "../../gcc/config/i386/mmx.md"
(TARGET_SSE || TARGET_3DNOW)
    : -1 },
#line 11722 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11722 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11722 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 9258 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NEG, HImode, operands)",
    __builtin_constant_p 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, HImode, operands))
    ? (int) 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, HImode, operands))
    : -1 },
#line 8435 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (AND, DImode, operands)",
    __builtin_constant_p 
#line 8435 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (AND, DImode, operands))
    ? (int) 
#line 8435 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (AND, DImode, operands))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V4SImode)\n\
       || register_operand (operands[1], V4SImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4SImode)
       || register_operand (operands[1], V4SImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4SImode)
       || register_operand (operands[1], V4SImode)))
    : -1 },
#line 742 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode)",
    __builtin_constant_p 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
    ? (int) 
#line 742 "../../gcc/config/i386/mmx.md"
(TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
    : -1 },
#line 1057 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (EQ, V4HImode, operands)",
    __builtin_constant_p 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V4HImode, operands))
    ? (int) 
#line 1057 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (EQ, V4HImode, operands))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V2DImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V2DImode, operands))
    : -1 },
#line 12771 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 12771 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 12771 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun)))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (PLUS, V4SFmode, operands))
    : -1 },
  { "(!TARGET_64BIT) && ( reload_completed)",
    __builtin_constant_p (
#line 12297 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT) && 
#line 12299 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 12297 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT) && 
#line 12299 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 6425 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (PLUS, SImode, operands)\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)",
    __builtin_constant_p 
#line 6425 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    ? (int) 
#line 6425 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    : -1 },
#line 7972 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && X87_ENABLE_ARITH (DFmode))\n\
    || (TARGET_SSE2 && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 7972 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (DFmode))
    || (TARGET_SSE2 && TARGET_SSE_MATH))
    ? (int) 
#line 7972 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (DFmode))
    || (TARGET_SSE2 && TARGET_SSE_MATH))
    : -1 },
#line 3364 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands)",
    __builtin_constant_p 
#line 3364 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands))
    ? (int) 
#line 3364 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands))
    : -1 },
#line 7942 "../../gcc/config/i386/i386.md"
  { "(TARGET_80387 && X87_ENABLE_ARITH (DFmode))\n\
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 7942 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (DFmode))
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 7942 "../../gcc/config/i386/i386.md"
((TARGET_80387 && X87_ENABLE_ARITH (DFmode))
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 9313 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
    : -1 },
#line 942 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE_MATH",
    __builtin_constant_p 
#line 942 "../../gcc/config/i386/sse.md"
(TARGET_SSE_MATH)
    ? (int) 
#line 942 "../../gcc/config/i386/sse.md"
(TARGET_SSE_MATH)
    : -1 },
#line 18902 "../../gcc/config/i386/i386.md"
  { "TARGET_STACK_PROBE",
    __builtin_constant_p 
#line 18902 "../../gcc/config/i386/i386.md"
(TARGET_STACK_PROBE)
    ? (int) 
#line 18902 "../../gcc/config/i386/i386.md"
(TARGET_STACK_PROBE)
    : -1 },
#line 4402 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 1)",
    __builtin_constant_p 
#line 4402 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    ? (int) 
#line 4402 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    : -1 },
#line 6352 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_XOP\n\
   && ix86_binary_operator_ok (EQ, V4SImode, operands)",
    __builtin_constant_p 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V4SImode, operands))
    ? (int) 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V4SImode, operands))
    : -1 },
  { "(TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_MINUS, V8HImode, operands))
    : -1 },
#line 5380 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && TARGET_INTER_UNIT_CONVERSIONS\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5380 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5380 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && TARGET_INTER_UNIT_CONVERSIONS
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 15188 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15188 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15188 "../../gcc/config/i386/i386.md"
(TARGET_80387 && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 5206 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    ? (int) 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    : -1 },
#line 362 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 922 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && ix86_binary_operator_ok (MULT, V4HImode, operands)",
    __builtin_constant_p 
#line 922 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (MULT, V4HImode, operands))
    ? (int) 
#line 922 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (MULT, V4HImode, operands))
    : -1 },
  { "(ix86_binary_operator_ok (PLUS, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_binary_operator_ok (PLUS, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_binary_operator_ok (PLUS, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 11267 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11267 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11267 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (DFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (DFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 11218 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11218 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11218 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 1479 "../../gcc/config/i386/sse.md"
  { "!TARGET_XOP \n\
  && (SSE_FLOAT_MODE_P (V4SFmode) || SSE_VEC_FLOAT_MODE_P (V4SFmode))",
    __builtin_constant_p 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (V4SFmode) || SSE_VEC_FLOAT_MODE_P (V4SFmode)))
    ? (int) 
#line 1479 "../../gcc/config/i386/sse.md"
(!TARGET_XOP 
  && (SSE_FLOAT_MODE_P (V4SFmode) || SSE_VEC_FLOAT_MODE_P (V4SFmode)))
    : -1 },
#line 4384 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 1)",
    __builtin_constant_p 
#line 4384 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    ? (int) 
#line 4384 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 1))
    : -1 },
#line 5689 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5689 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5689 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands))
    : -1 },
#line 19392 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY",
    __builtin_constant_p 
#line 19392 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY)
    ? (int) 
#line 19392 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY)
    : -1 },
#line 12487 "../../gcc/config/i386/i386.md"
  { "(! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 12487 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 12487 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 574 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands)",
    __builtin_constant_p 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands))
    ? (int) 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (PLUS, V2DFmode, operands))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (PLUS, V4DFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (PLUS, V4DFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (PLUS, V4DFmode, operands))
    : -1 },
#line 5030 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || DImode != DImode))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
   && can_create_pseudo_p ())
    ? (int) 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
   && can_create_pseudo_p ())
    : -1 },
#line 6146 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V4SImode, operands)",
    __builtin_constant_p 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V4SImode, operands))
    ? (int) 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V4SImode, operands))
    : -1 },
#line 13264 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])\n\
   && SELECT_CC_MODE (GET_CODE (operands[0]),\n\
		      operands[1], operands[2]) == CCFPmode\n\
   && !TARGET_CMOVE",
    __builtin_constant_p 
#line 13264 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && !TARGET_CMOVE)
    ? (int) 
#line 13264 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && !TARGET_CMOVE)
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V8HImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V8HImode, operands))
    : -1 },
#line 5639 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5639 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5639 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])) && ( reload_completed)",
    __builtin_constant_p (
#line 1292 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && GET_MODE (operands[1]) == GET_MODE (operands[2])) && 
#line 1296 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 1292 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && GET_MODE (operands[1]) == GET_MODE (operands[2])) && 
#line 1296 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 12129 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATE, SImode, operands)",
    __builtin_constant_p 
#line 12129 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, operands))
    ? (int) 
#line 12129 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, operands))
    : -1 },
#line 4801 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || SSE_FLOAT_MODE_P (DFmode)",
    __builtin_constant_p 
#line 4801 "../../gcc/config/i386/i386.md"
(TARGET_80387 || SSE_FLOAT_MODE_P (DFmode))
    ? (int) 
#line 4801 "../../gcc/config/i386/i386.md"
(TARGET_80387 || SSE_FLOAT_MODE_P (DFmode))
    : -1 },
#line 7895 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 7895 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 7895 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 18881 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_STACK_PROBE",
    __builtin_constant_p 
#line 18881 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_STACK_PROBE)
    ? (int) 
#line 18881 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_STACK_PROBE)
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V4SImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V4SImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V4SImode, operands))
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (SFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 14922 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14922 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14922 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 10961 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)",
    __builtin_constant_p 
#line 10961 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    ? (int) 
#line 10961 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
    : -1 },
#line 10521 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
    || !TARGET_PARTIAL_FLAG_REG_STALL\n\
    || (operands[2] == const1_rtx\n\
	&& (TARGET_SHIFT1\n\
	    || TARGET_DOUBLE_WITH_ADD)))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)",
    __builtin_constant_p 
#line 10521 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    ? (int) 
#line 10521 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    : -1 },
#line 6352 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_XOP\n\
   && ix86_binary_operator_ok (EQ, V16QImode, operands)",
    __builtin_constant_p 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V16QImode, operands))
    ? (int) 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V16QImode, operands))
    : -1 },
#line 8974 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (IOR, SImode, operands)",
    __builtin_constant_p 
#line 8974 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands))
    ? (int) 
#line 8974 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands))
    : -1 },
#line 7367 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT\n\
   && TARGET_AVX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 7367 "../../gcc/config/i386/sse.md"
(TARGET_64BIT
   && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 7367 "../../gcc/config/i386/sse.md"
(TARGET_64BIT
   && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 14857 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14857 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14857 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 3582 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4)\n\
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4)\n\
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4)\n\
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4))",
    __builtin_constant_p 
#line 3582 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4)
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4)
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4)
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4)))
    ? (int) 
#line 3582 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4)
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4)
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4)
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4)))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (XOR, V2DImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V2DImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V2DImode, operands))
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && ( reload_completed)",
    __builtin_constant_p (
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && 
#line 1343 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))) && 
#line 1343 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 8680 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (AND, QImode, operands)",
    __builtin_constant_p 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, QImode, operands))
    ? (int) 
#line 8680 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, QImode, operands))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMAX, V8HImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V8HImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMAX, V8HImode, operands))
    : -1 },
#line 1541 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW)\n\
   && ix86_binary_operator_ok (PLUS, V8QImode, operands)",
    __builtin_constant_p 
#line 1541 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW)
   && ix86_binary_operator_ok (PLUS, V8QImode, operands))
    ? (int) 
#line 1541 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW)
   && ix86_binary_operator_ok (PLUS, V8QImode, operands))
    : -1 },
#line 18535 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && TARGET_CMOVE\n\
   && !(MEM_P (operands[2]) && MEM_P (operands[3]))",
    __builtin_constant_p 
#line 18535 "../../gcc/config/i386/i386.md"
(TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    ? (int) 
#line 18535 "../../gcc/config/i386/i386.md"
(TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    : -1 },
#line 9163 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)",
    __builtin_constant_p 
#line 9163 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode))
    ? (int) 
#line 9163 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode))
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (XFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands))
    : -1 },
#line 3593 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 3593 "../../gcc/config/i386/i386.md"
(TARGET_SSE2
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 3593 "../../gcc/config/i386/i386.md"
(TARGET_SSE2
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 5297 "../../gcc/config/i386/i386.md"
  { "((TARGET_80387\n\
     && X87_ENABLE_FLOAT (SFmode, DImode)\n\
     && (!((DImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((DImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
	&& ((DImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    ? (int) 
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, DImode)
     && (!((DImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((DImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((DImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ())
    : -1 },
#line 5689 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5689 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5689 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
  { "(reload_completed) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3007 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    ? (int) (
#line 3007 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == SImode))
    : -1 },
#line 8405 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && GET_MODE (operands[2]) != QImode\n\
    && (!REG_P (operands[2]) || ANY_QI_REG_P (operands[2]))\n\
    && ((ix86_match_ccmode (insn, CCZmode)\n\
	 && !(INTVAL (operands[3]) & ~255))\n\
	|| (ix86_match_ccmode (insn, CCNOmode)\n\
	    && !(INTVAL (operands[3]) & ~127)))",
    __builtin_constant_p 
#line 8405 "../../gcc/config/i386/i386.md"
(reload_completed
    && GET_MODE (operands[2]) != QImode
    && (!REG_P (operands[2]) || ANY_QI_REG_P (operands[2]))
    && ((ix86_match_ccmode (insn, CCZmode)
	 && !(INTVAL (operands[3]) & ~255))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (operands[3]) & ~127))))
    ? (int) 
#line 8405 "../../gcc/config/i386/i386.md"
(reload_completed
    && GET_MODE (operands[2]) != QImode
    && (!REG_P (operands[2]) || ANY_QI_REG_P (operands[2]))
    && ((ix86_match_ccmode (insn, CCZmode)
	 && !(INTVAL (operands[3]) & ~255))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (operands[3]) & ~127))))
    : -1 },
#line 7322 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE",
    __builtin_constant_p 
#line 7322 "../../gcc/config/i386/sse.md"
(TARGET_SSE)
    ? (int) 
#line 7322 "../../gcc/config/i386/sse.md"
(TARGET_SSE)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V2DImode)\n\
       || register_operand (operands[1], V2DImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V2DImode)
       || register_operand (operands[1], V2DImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V2DImode)
       || register_operand (operands[1], V2DImode)))
    : -1 },
#line 1640 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A) && TARGET_64BIT",
    __builtin_constant_p 
#line 1640 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A) && TARGET_64BIT)
    ? (int) 
#line 1640 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A) && TARGET_64BIT)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V4DFmode)\n\
       || register_operand (operands[1], V4DFmode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4DFmode)
       || register_operand (operands[1], V4DFmode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4DFmode)
       || register_operand (operands[1], V4DFmode)))
    : -1 },
#line 841 "../../gcc/config/i386/i386.md"
  { "Pmode == DImode",
    __builtin_constant_p 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode)
    ? (int) 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode)
    : -1 },
#line 10151 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, SImode, operands)",
    __builtin_constant_p 
#line 10151 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    ? (int) 
#line 10151 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, SImode, operands))
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V2DImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V2DImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V2DImode, operands))
    : -1 },
#line 20178 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !SIBLING_CALL_P (insn)\n\
   && ix86_cmodel != CM_LARGE && ix86_cmodel != CM_LARGE_PIC",
    __builtin_constant_p 
#line 20178 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !SIBLING_CALL_P (insn)
   && ix86_cmodel != CM_LARGE && ix86_cmodel != CM_LARGE_PIC)
    ? (int) 
#line 20178 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !SIBLING_CALL_P (insn)
   && ix86_cmodel != CM_LARGE && ix86_cmodel != CM_LARGE_PIC)
    : -1 },
#line 254 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 254 "../../gcc/config/i386/mmx.md"
(TARGET_MMX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 254 "../../gcc/config/i386/mmx.md"
(TARGET_MMX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMIN, V16QImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V16QImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V16QImode, operands))
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V8HImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MINUS, V8HImode, operands))
    : -1 },
#line 12333 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands)",
    __builtin_constant_p 
#line 12333 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands))
    ? (int) 
#line 12333 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands))
    : -1 },
#line 9572 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NOT, SImode, operands)",
    __builtin_constant_p 
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, SImode, operands))
    ? (int) 
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, SImode, operands))
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))\n\
   && ix86_binary_operator_ok (MINUS, V1DImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V1DImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
   && ix86_binary_operator_ok (MINUS, V1DImode, operands))
    : -1 },
  { "(!TARGET_PARTIAL_REG_STALL\n\
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)) && ( reload_completed)",
    __builtin_constant_p (
#line 12755 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)) && 
#line 12758 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 12755 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)) && 
#line 12758 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 7742 "../../gcc/config/i386/i386.md"
  { "TARGET_HIMODE_MATH\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 7742 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 7742 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
  { "(TARGET_AVX) && ( reload_completed && REG_P (operands[1]))",
    __builtin_constant_p (
#line 11779 "../../gcc/config/i386/sse.md"
(TARGET_AVX) && 
#line 11783 "../../gcc/config/i386/sse.md"
( reload_completed && REG_P (operands[1])))
    ? (int) (
#line 11779 "../../gcc/config/i386/sse.md"
(TARGET_AVX) && 
#line 11783 "../../gcc/config/i386/sse.md"
( reload_completed && REG_P (operands[1])))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V16QImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V16QImode, operands))
    : -1 },
#line 6202 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V8HImode, operands)",
    __builtin_constant_p 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V8HImode, operands))
    ? (int) 
#line 6202 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (UMIN, V8HImode, operands))
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (IOR, V4DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (IOR, V4DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (IOR, V4DFmode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (XOR, V2SImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V2SImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V2SImode, operands))
    : -1 },
#line 6759 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && ix86_match_ccmode (insn, CCGCmode)",
    __builtin_constant_p 
#line 6759 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && ix86_match_ccmode (insn, CCGCmode))
    ? (int) 
#line 6759 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && ix86_match_ccmode (insn, CCGCmode))
    : -1 },
#line 6146 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V4SImode, operands)",
    __builtin_constant_p 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V4SImode, operands))
    ? (int) 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V4SImode, operands))
    : -1 },
#line 19080 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL && TARGET_CMOVE\n\
   && (GET_MODE (operands[0]) == HImode\n\
       || (GET_MODE (operands[0]) == QImode\n\
	   && (TARGET_PROMOTE_QImode\n\
	       || optimize_insn_for_size_p ())))",
    __builtin_constant_p 
#line 19080 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && TARGET_CMOVE
   && (GET_MODE (operands[0]) == HImode
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ()))))
    ? (int) 
#line 19080 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && TARGET_CMOVE
   && (GET_MODE (operands[0]) == HImode
       || (GET_MODE (operands[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ()))))
    : -1 },
#line 9506 "../../gcc/config/i386/i386.md"
  { "(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (SFmode == TFmode))",
    __builtin_constant_p 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (SFmode == TFmode)))
    ? (int) 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (SFmode == TFmode)))
    : -1 },
#line 5618 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5618 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5618 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
  { "(TARGET_USE_FANCY_MATH_387\n\
   && flag_unsafe_math_optimizations\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 17366 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && can_create_pseudo_p ()) && 
#line 17370 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 17366 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && can_create_pseudo_p ()) && 
#line 17370 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (AND, V16QImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V16QImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V16QImode, operands))
    : -1 },
#line 17529 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 17529 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 8831 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
    && QI_REG_P (operands[0])\n\
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
    && !(~INTVAL (operands[2]) & ~(255 << 8))\n\
    && GET_MODE (operands[0]) != QImode",
    __builtin_constant_p 
#line 8831 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (operands[2]) & ~(255 << 8))
    && GET_MODE (operands[0]) != QImode)
    ? (int) 
#line 8831 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (operands[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (operands[2]) & ~(255 << 8))
    && GET_MODE (operands[0]) != QImode)
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SS_PLUS, V16QImode, operands))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V8SFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V8SFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V8SFmode, operands))
    : -1 },
#line 7352 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && reload_completed\n\
   && (TARGET_INTER_UNIT_MOVES\n\
       || MEM_P (operands [0])\n\
       || !GENERAL_REGNO_P (true_regnum (operands [0])))",
    __builtin_constant_p 
#line 7352 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && reload_completed
   && (TARGET_INTER_UNIT_MOVES
       || MEM_P (operands [0])
       || !GENERAL_REGNO_P (true_regnum (operands [0]))))
    ? (int) 
#line 7352 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && reload_completed
   && (TARGET_INTER_UNIT_MOVES
       || MEM_P (operands [0])
       || !GENERAL_REGNO_P (true_regnum (operands [0]))))
    : -1 },
#line 1273 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])",
    __builtin_constant_p 
#line 1273 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2]))
    ? (int) 
#line 1273 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2]))
    : -1 },
#line 8135 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT || TARGET_SSE2",
    __builtin_constant_p 
#line 8135 "../../gcc/config/i386/sse.md"
(TARGET_64BIT || TARGET_SSE2)
    ? (int) 
#line 8135 "../../gcc/config/i386/sse.md"
(TARGET_64BIT || TARGET_SSE2)
    : -1 },
#line 12451 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATERT, QImode, operands)",
    __builtin_constant_p 
#line 12451 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, QImode, operands))
    ? (int) 
#line 12451 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, QImode, operands))
    : -1 },
#line 7043 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 7043 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 7043 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 1317 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW_A",
    __builtin_constant_p 
#line 1317 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW_A)
    ? (int) 
#line 1317 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW_A)
    : -1 },
  { "(TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ()) && 
#line 5211 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 5674 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5674 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5674 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 13793 "../../gcc/config/i386/i386.md"
  { "ix86_can_use_return_insn_p ()",
    __builtin_constant_p 
#line 13793 "../../gcc/config/i386/i386.md"
(ix86_can_use_return_insn_p ())
    ? (int) 
#line 13793 "../../gcc/config/i386/i386.md"
(ix86_can_use_return_insn_p ())
    : -1 },
  { "(! TARGET_POPCNT) && ( reload_completed)",
    __builtin_constant_p (
#line 14451 "../../gcc/config/i386/i386.md"
(! TARGET_POPCNT) && 
#line 14453 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 14451 "../../gcc/config/i386/i386.md"
(! TARGET_POPCNT) && 
#line 14453 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 19265 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && ((TARGET_NOT_UNPAIRABLE\n\
        && (!MEM_P (operands[0])\n\
            || !memory_displacement_operand (operands[0], HImode)))\n\
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], HImode)))\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19265 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], HImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], HImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19265 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], HImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], HImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 11840 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11840 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11840 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
  { "(TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3]))) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 18492 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3]))) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 18492 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE && !(MEM_P (operands[2]) && MEM_P (operands[3]))) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 9632 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_unary_operator_ok (NOT, SImode, operands)",
    __builtin_constant_p 
#line 9632 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands))
    ? (int) 
#line 9632 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands))
    : -1 },
#line 10198 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && reload_completed\n\
   && true_regnum (operands[0]) != true_regnum (operands[1])",
    __builtin_constant_p 
#line 10198 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1]))
    ? (int) 
#line 10198 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1]))
    : -1 },
#line 19478 "../../gcc/config/i386/i386.md"
  { "GET_MODE_SIZE (GET_MODE (operands[0])) <= UNITS_PER_WORD\n\
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())\n\
   && GENERAL_REG_P (operands[0])\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19478 "../../gcc/config/i386/i386.md"
(GET_MODE_SIZE (GET_MODE (operands[0])) <= UNITS_PER_WORD
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && GENERAL_REG_P (operands[0])
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19478 "../../gcc/config/i386/i386.md"
(GET_MODE_SIZE (GET_MODE (operands[0])) <= UNITS_PER_WORD
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && GENERAL_REG_P (operands[0])
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
  { "(ix86_binary_operator_ok (PLUS, DImode, operands)) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 5918 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, DImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    ? (int) (
#line 5918 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, DImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    : -1 },
#line 9012 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MULT, V8HImode, operands)",
    __builtin_constant_p 
#line 9012 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MULT, V8HImode, operands))
    ? (int) 
#line 9012 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MULT, V8HImode, operands))
    : -1 },
#line 9785 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, DImode, operands)",
    __builtin_constant_p 
#line 9785 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    ? (int) 
#line 9785 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMAX, V16QImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V16QImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V16QImode, operands))
    : -1 },
#line 7352 "../../gcc/config/i386/i386.md"
  { "reload_completed && ix86_lea_for_add_ok (PLUS, insn, operands)",
    __builtin_constant_p 
#line 7352 "../../gcc/config/i386/i386.md"
(reload_completed && ix86_lea_for_add_ok (PLUS, insn, operands))
    ? (int) 
#line 7352 "../../gcc/config/i386/i386.md"
(reload_completed && ix86_lea_for_add_ok (PLUS, insn, operands))
    : -1 },
#line 175 "../../gcc/config/i386/sync.md"
  { "TARGET_XADD",
    __builtin_constant_p 
#line 175 "../../gcc/config/i386/sync.md"
(TARGET_XADD)
    ? (int) 
#line 175 "../../gcc/config/i386/sync.md"
(TARGET_XADD)
    : -1 },
#line 6168 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (PLUS, HImode, operands)",
    __builtin_constant_p 
#line 6168 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    ? (int) 
#line 6168 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    : -1 },
  { "(TARGET_USE_FANCY_MATH_387\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 17445 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && can_create_pseudo_p ()) && 
#line 17448 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 17445 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && can_create_pseudo_p ()) && 
#line 17448 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
  { "((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])\n\
       || GET_MODE (operands[3]) == VOIDmode)) && ( reload_completed)",
    __builtin_constant_p (
#line 7230 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)) && 
#line 7237 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 7230 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)) && 
#line 7237 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 15004 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 15004 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 15004 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (XOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V16QImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V16QImode, operands))
    : -1 },
#line 2982 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && !TARGET_INTEGER_DFMODE_MOVES",
    __builtin_constant_p 
#line 2982 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !TARGET_INTEGER_DFMODE_MOVES)
    ? (int) 
#line 2982 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !TARGET_INTEGER_DFMODE_MOVES)
    : -1 },
  { "((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (TFmode == TFmode))) && ( reload_completed)",
    __builtin_constant_p (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (TFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 9520 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (TFmode == TFmode))) && 
#line 9523 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 19713 "../../gcc/config/i386/i386.md"
  { "(((!TARGET_FUSE_CMP_AND_BRANCH || optimize_insn_for_size_p ())\n\
     && incdec_operand (operands[3], GET_MODE (operands[3])))\n\
    || (!TARGET_FUSE_CMP_AND_BRANCH\n\
	&& INTVAL (operands[3]) == 128))\n\
   && ix86_match_ccmode (insn, CCGCmode)\n\
   && peep2_reg_dead_p (1, operands[2])",
    __builtin_constant_p 
#line 19713 "../../gcc/config/i386/i386.md"
((((!TARGET_FUSE_CMP_AND_BRANCH || optimize_insn_for_size_p ())
     && incdec_operand (operands[3], GET_MODE (operands[3])))
    || (!TARGET_FUSE_CMP_AND_BRANCH
	&& INTVAL (operands[3]) == 128))
   && ix86_match_ccmode (insn, CCGCmode)
   && peep2_reg_dead_p (1, operands[2]))
    ? (int) 
#line 19713 "../../gcc/config/i386/i386.md"
((((!TARGET_FUSE_CMP_AND_BRANCH || optimize_insn_for_size_p ())
     && incdec_operand (operands[3], GET_MODE (operands[3])))
    || (!TARGET_FUSE_CMP_AND_BRANCH
	&& INTVAL (operands[3]) == 128))
   && ix86_match_ccmode (insn, CCGCmode)
   && peep2_reg_dead_p (1, operands[2]))
    : -1 },
#line 4046 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && reload_completed\n\
   && !SSE_REG_P (operands[0]) && !MMX_REG_P (operands[0])",
    __builtin_constant_p 
#line 4046 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && !SSE_REG_P (operands[0]) && !MMX_REG_P (operands[0]))
    ? (int) 
#line 4046 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && !SSE_REG_P (operands[0]) && !MMX_REG_P (operands[0]))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (AND, V4SImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V4SImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V4SImode, operands))
    : -1 },
#line 5257 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
        || TARGET_MIX_SSE_I387)\n\
    && reload_completed",
    __builtin_constant_p 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    ? (int) 
#line 5257 "../../gcc/config/i386/i386.md"
(TARGET_80387
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
        || TARGET_MIX_SSE_I387)
    && reload_completed)
    : -1 },
#line 12168 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands)",
    __builtin_constant_p 
#line 12168 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands))
    ? (int) 
#line 12168 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands))
    : -1 },
#line 2584 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !symbolic_operand (operands[1], DImode)\n\
   && !x86_64_immediate_operand (operands[1], DImode)",
    __builtin_constant_p 
#line 2584 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode))
    ? (int) 
#line 2584 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (AND, V8HImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V8HImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (AND, V8HImode, operands))
    : -1 },
#line 6072 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (UMAX, V16QImode, operands)",
    __builtin_constant_p 
#line 6072 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (UMAX, V16QImode, operands))
    ? (int) 
#line 6072 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (UMAX, V16QImode, operands))
    : -1 },
#line 9286 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9286 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 15063 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (SFmode, SImode)\n\
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, SImode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, SImode)
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 11091 "../../gcc/config/i386/i386.md"
  { "INTVAL (operands[2]) == 31\n\
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11091 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) == 31
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11091 "../../gcc/config/i386/i386.md"
(INTVAL (operands[2]) == 31
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 11202 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11202 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11202 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 10760 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun)\n\
    || !TARGET_PARTIAL_FLAG_REG_STALL\n\
    || (operands[2] == const1_rtx\n\
	&& (TARGET_SHIFT1\n\
	    || TARGET_DOUBLE_WITH_ADD)))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)",
    __builtin_constant_p 
#line 10760 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    ? (int) 
#line 10760 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (operands[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (AND, V2DFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (AND, V2DFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (AND, V2DFmode, operands))
    : -1 },
#line 9552 "../../gcc/config/i386/i386.md"
  { "((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
    || (TARGET_SSE2 && (SFmode == TFmode)))\n\
   && reload_completed",
    __builtin_constant_p 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (SFmode == TFmode)))
   && reload_completed)
    ? (int) 
#line 9552 "../../gcc/config/i386/i386.md"
(((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    || (TARGET_SSE2 && (SFmode == TFmode)))
   && reload_completed)
    : -1 },
#line 4491 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 0)",
    __builtin_constant_p 
#line 4491 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    ? (int) 
#line 4491 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    : -1 },
#line 4991 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	&& (TARGET_64BIT || SImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 15004 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 15004 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 15004 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 6146 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V16QImode, operands)",
    __builtin_constant_p 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V16QImode, operands))
    ? (int) 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMAX, V16QImode, operands))
    : -1 },
#line 362 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 362 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (AND, V2DImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V2DImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (AND, V2DImode, operands))
    : -1 },
#line 971 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (SMIN, V4HImode, operands)",
    __builtin_constant_p 
#line 971 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (SMIN, V4HImode, operands))
    ? (int) 
#line 971 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (SMIN, V4HImode, operands))
    : -1 },
#line 10422 "../../gcc/config/i386/i386.md"
  { "TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)",
    __builtin_constant_p 
#line 10422 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    ? (int) 
#line 10422 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
    : -1 },
#line 8639 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (AND, DImode, operands)",
    __builtin_constant_p 
#line 8639 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, DImode, operands))
    ? (int) 
#line 8639 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, DImode, operands))
    : -1 },
#line 3925 "../../gcc/config/i386/i386.md"
  { "!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 3925 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
    ? (int) 
#line 3925 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
    : -1 },
#line 18392 "../../gcc/config/i386/i386.md"
  { "peep2_reg_dead_p (4, operands[7]) && peep2_reg_dead_p (4, operands[8])",
    __builtin_constant_p 
#line 18392 "../../gcc/config/i386/i386.md"
(peep2_reg_dead_p (4, operands[7]) && peep2_reg_dead_p (4, operands[8]))
    ? (int) 
#line 18392 "../../gcc/config/i386/i386.md"
(peep2_reg_dead_p (4, operands[7]) && peep2_reg_dead_p (4, operands[8]))
    : -1 },
#line 5689 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5689 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5689 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 5206 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    ? (int) 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    : -1 },
#line 5096 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V2DImode, operands)",
    __builtin_constant_p 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V2DImode, operands))
    ? (int) 
#line 5096 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MINUS, V2DImode, operands))
    : -1 },
#line 17366 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && flag_unsafe_math_optimizations\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 17366 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && can_create_pseudo_p ())
    ? (int) 
#line 17366 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && flag_unsafe_math_optimizations
   && can_create_pseudo_p ())
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMIN, V8HImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V8HImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMIN, V8HImode, operands))
    : -1 },
#line 8145 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2",
    __builtin_constant_p 
#line 8145 "../../gcc/config/i386/sse.md"
(TARGET_SSE2)
    ? (int) 
#line 8145 "../../gcc/config/i386/sse.md"
(TARGET_SSE2)
    : -1 },
#line 11169 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11169 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11169 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (MINUS, HImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, HImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, HImode, operands))
    : -1 },
#line 11396 "../../gcc/config/i386/i386.md"
  { "(! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11396 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    ? (int) 
#line 11396 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    : -1 },
#line 14949 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && !COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14949 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14949 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && !COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
  { "(ix86_binary_operator_ok (MINUS, SImode, operands)) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 7402 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    ? (int) (
#line 7402 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, operands)) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    : -1 },
#line 3956 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && ANY_QI_REG_P (operands[0])\n\
   && (ANY_QI_REG_P (operands[1]) || MEM_P (operands[1]))\n\
   && (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))\n\
   && !reg_overlap_mentioned_p (operands[0], operands[1])",
    __builtin_constant_p 
#line 3956 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (operands[0])
   && (ANY_QI_REG_P (operands[1]) || MEM_P (operands[1]))
   && (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (operands[0], operands[1]))
    ? (int) 
#line 3956 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (operands[0])
   && (ANY_QI_REG_P (operands[1]) || MEM_P (operands[1]))
   && (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (operands[0], operands[1]))
    : -1 },
  { "(TARGET_64BIT && !TARGET_PARTIAL_REG_STALL) && ( reload_completed)",
    __builtin_constant_p (
#line 12740 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_PARTIAL_REG_STALL) && 
#line 12742 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 12740 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !TARGET_PARTIAL_REG_STALL) && 
#line 12742 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 888 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (MULT, V4HImode, operands)",
    __builtin_constant_p 
#line 888 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (MULT, V4HImode, operands))
    ? (int) 
#line 888 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (MULT, V4HImode, operands))
    : -1 },
#line 5245 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && reload_completed",
    __builtin_constant_p 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    ? (int) 
#line 5245 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && reload_completed)
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || SImode != DImode))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
   && can_create_pseudo_p ()) && 
#line 5036 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 8048 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_64BIT",
    __builtin_constant_p 
#line 8048 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_64BIT)
    ? (int) 
#line 8048 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_64BIT)
    : -1 },
#line 15138 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && COMMUTATIVE_ARITH_P (operands[3])",
    __builtin_constant_p 
#line 15138 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && COMMUTATIVE_ARITH_P (operands[3]))
    ? (int) 
#line 15138 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && COMMUTATIVE_ARITH_P (operands[3]))
    : -1 },
#line 18584 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && reload_completed",
    __builtin_constant_p 
#line 18584 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed)
    ? (int) 
#line 18584 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed)
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V8SImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V8SImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V8SImode, operands))
    : -1 },
#line 9075 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 9075 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    ? (int) 
#line 9075 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (XFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (XFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 14168 "../../gcc/config/i386/i386.md"
  { "TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode)",
    __builtin_constant_p 
#line 14168 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode))
    ? (int) 
#line 14168 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode))
    : -1 },
#line 1628 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A) && !TARGET_64BIT",
    __builtin_constant_p 
#line 1628 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A) && !TARGET_64BIT)
    ? (int) 
#line 1628 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A) && !TARGET_64BIT)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V8SFmode)\n\
       || register_operand (operands[1], V8SFmode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8SFmode)
       || register_operand (operands[1], V8SFmode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8SFmode)
       || register_operand (operands[1], V8SFmode)))
    : -1 },
#line 14857 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14857 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14857 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
  { "(((TARGET_80387\n\
     && X87_ENABLE_FLOAT (SFmode, SImode)\n\
     && (!((SImode != DImode || TARGET_64BIT)\n\
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
	 || TARGET_MIX_SSE_I387))\n\
    || ((SImode != DImode || TARGET_64BIT)\n\
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
	&& ((SImode == SImode\n\
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS\n\
	     && optimize_function_for_speed_p (cfun)\n\
	     && flag_trapping_math)\n\
	    || !(TARGET_INTER_UNIT_CONVERSIONS\n\
	         || optimize_function_for_size_p (cfun)))))\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 5297 "../../gcc/config/i386/i386.md"
(((TARGET_80387
     && X87_ENABLE_FLOAT (SFmode, SImode)
     && (!((SImode != DImode || TARGET_64BIT)
	   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
	 || TARGET_MIX_SSE_I387))
    || ((SImode != DImode || TARGET_64BIT)
	&& SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
	&& ((SImode == SImode
	     && TARGET_SSE2 && TARGET_USE_VECTOR_CONVERTS
	     && optimize_function_for_speed_p (cfun)
	     && flag_trapping_math)
	    || !(TARGET_INTER_UNIT_CONVERSIONS
	         || optimize_function_for_size_p (cfun)))))
   && can_create_pseudo_p ()) && 
#line 5312 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 2605 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ((optimize > 0 && flag_peephole2)\n\
		    ? epilogue_completed : reload_completed)\n\
   && !symbolic_operand (operands[1], DImode)\n\
   && !x86_64_immediate_operand (operands[1], DImode)",
    __builtin_constant_p 
#line 2605 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		    ? epilogue_completed : reload_completed)
   && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode))
    ? (int) 
#line 2605 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		    ? epilogue_completed : reload_completed)
   && !symbolic_operand (operands[1], DImode)
   && !x86_64_immediate_operand (operands[1], DImode))
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))\n\
   && ix86_binary_operator_ok (PLUS, V1DImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V1DImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V1DImode, operands))
    : -1 },
#line 4991 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	&& (TARGET_64BIT || DImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4991 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	&& (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 18551 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_80387 && TARGET_CMOVE\n\
   && !(MEM_P (operands[2]) && MEM_P (operands[3]))",
    __builtin_constant_p 
#line 18551 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    ? (int) 
#line 18551 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_80387 && TARGET_CMOVE
   && !(MEM_P (operands[2]) && MEM_P (operands[3])))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (AND, V8HImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V8HImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V8HImode, operands))
    : -1 },
#line 10105 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && true_regnum (operands[0]) != true_regnum (operands[1])\n\
   && GET_MODE_SIZE (GET_MODE (operands[0])) <= 4",
    __builtin_constant_p 
#line 10105 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1])
   && GET_MODE_SIZE (GET_MODE (operands[0])) <= 4)
    ? (int) 
#line 10105 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1])
   && GET_MODE_SIZE (GET_MODE (operands[0])) <= 4)
    : -1 },
#line 1377 "../../gcc/config/i386/i386.md"
  { "TARGET_SAHF",
    __builtin_constant_p 
#line 1377 "../../gcc/config/i386/i386.md"
(TARGET_SAHF)
    ? (int) 
#line 1377 "../../gcc/config/i386/i386.md"
(TARGET_SAHF)
    : -1 },
#line 224 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE\n\
   && (register_operand (operands[0], V2DImode)\n\
       || register_operand (operands[1], V2DImode))",
    __builtin_constant_p 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V2DImode)
       || register_operand (operands[1], V2DImode)))
    ? (int) 
#line 224 "../../gcc/config/i386/sse.md"
(TARGET_SSE
   && (register_operand (operands[0], V2DImode)
       || register_operand (operands[1], V2DImode)))
    : -1 },
#line 11409 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ASHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11409 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    ? (int) 
#line 11409 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
    : -1 },
#line 4731 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && reload_completed",
    __builtin_constant_p 
#line 4731 "../../gcc/config/i386/i386.md"
(TARGET_80387 && reload_completed)
    ? (int) 
#line 4731 "../../gcc/config/i386/i386.md"
(TARGET_80387 && reload_completed)
    : -1 },
#line 9593 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_unary_operator_ok (NOT, SImode, operands)",
    __builtin_constant_p 
#line 9593 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_unary_operator_ok (NOT, SImode, operands))
    ? (int) 
#line 9593 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_unary_operator_ok (NOT, SImode, operands))
    : -1 },
#line 3933 "../../gcc/config/i386/i386.md"
  { "(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))\n\
   && reload_completed",
    __builtin_constant_p 
#line 3933 "../../gcc/config/i386/i386.md"
((!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && reload_completed)
    ? (int) 
#line 3933 "../../gcc/config/i386/i386.md"
((!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && reload_completed)
    : -1 },
#line 11144 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11144 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11144 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
  { "(!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES) && ( reload_completed)",
    __builtin_constant_p (
#line 276 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES) && 
#line 278 "../../gcc/config/i386/sse.md"
( reload_completed))
    ? (int) (
#line 276 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES) && 
#line 278 "../../gcc/config/i386/sse.md"
( reload_completed))
    : -1 },
#line 276 "../../gcc/config/i386/sse.md"
  { "!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES",
    __builtin_constant_p 
#line 276 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES)
    ? (int) 
#line 276 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES)
    : -1 },
#line 200 "../../gcc/config/i386/mmx.md"
  { "TARGET_64BIT && TARGET_MMX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 200 "../../gcc/config/i386/mmx.md"
(TARGET_64BIT && TARGET_MMX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 200 "../../gcc/config/i386/mmx.md"
(TARGET_64BIT && TARGET_MMX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V4DFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4DFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4DFmode, operands))
    : -1 },
#line 9036 "../../gcc/config/i386/sse.md"
  { "TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V8HImode, operands)",
    __builtin_constant_p 
#line 9036 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V8HImode, operands))
    ? (int) 
#line 9036 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3 && ix86_binary_operator_ok (MULT, V8HImode, operands))
    : -1 },
#line 15634 "../../gcc/config/i386/i386.md"
  { "find_regno_note (insn, REG_UNUSED, REGNO (operands[0]))\n\
   && !(reload_completed || reload_in_progress)",
    __builtin_constant_p 
#line 15634 "../../gcc/config/i386/i386.md"
(find_regno_note (insn, REG_UNUSED, REGNO (operands[0]))
   && !(reload_completed || reload_in_progress))
    ? (int) 
#line 15634 "../../gcc/config/i386/i386.md"
(find_regno_note (insn, REG_UNUSED, REGNO (operands[0]))
   && !(reload_completed || reload_in_progress))
    : -1 },
#line 20224 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 20224 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SIBLING_CALL_P (insn))
    ? (int) 
#line 20224 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SIBLING_CALL_P (insn))
    : -1 },
#line 1647 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode)",
    __builtin_constant_p 
#line 1647 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode))
    ? (int) 
#line 1647 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode))
    : -1 },
#line 9907 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun)\n\
       || !TARGET_PARTIAL_FLAG_REG_STALL\n\
       || (operands[2] == const1_rtx\n\
	   && (TARGET_SHIFT1\n\
	       || TARGET_DOUBLE_WITH_ADD)))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFT, DImode, operands)",
    __builtin_constant_p 
#line 9907 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    ? (int) 
#line 9907 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun)
       || !TARGET_PARTIAL_FLAG_REG_STALL
       || (operands[2] == const1_rtx
	   && (TARGET_SHIFT1
	       || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, DImode, operands))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V4HImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V4HImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V4HImode, operands))
    : -1 },
#line 74 "../../gcc/config/i386/sync.md"
  { "TARGET_CMPXCHG",
    __builtin_constant_p 
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG)
    ? (int) 
#line 74 "../../gcc/config/i386/sync.md"
(TARGET_CMPXCHG)
    : -1 },
#line 3650 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && reload_completed\n\
   && !SSE_REG_P (operands[1])",
    __builtin_constant_p 
#line 3650 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && reload_completed
   && !SSE_REG_P (operands[1]))
    ? (int) 
#line 3650 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && reload_completed
   && !SSE_REG_P (operands[1]))
    : -1 },
#line 6858 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGCmode)\n\
   && (INTVAL (operands[2]) & 0xffff) != 0x8000",
    __builtin_constant_p 
#line 6858 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffff) != 0x8000)
    ? (int) 
#line 6858 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffff) != 0x8000)
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)\n\
   && ix86_binary_operator_ok (AND, V4DFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (AND, V4DFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode)
   && ix86_binary_operator_ok (AND, V4DFmode, operands))
    : -1 },
#line 922 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 922 "../../gcc/config/i386/sse.md"
(TARGET_AVX && TARGET_SSE_MATH)
    ? (int) 
#line 922 "../../gcc/config/i386/sse.md"
(TARGET_AVX && TARGET_SSE_MATH)
    : -1 },
#line 6337 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (EQ, V8HImode, operands)",
    __builtin_constant_p 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V8HImode, operands))
    ? (int) 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V8HImode, operands))
    : -1 },
#line 9645 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)",
    __builtin_constant_p 
#line 9645 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode))
    ? (int) 
#line 9645 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode))
    : -1 },
#line 5846 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)\n\
   && TARGET_SSE\n\
   && reload_completed",
    __builtin_constant_p 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    ? (int) 
#line 5846 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode)
   && TARGET_SSE
   && reload_completed)
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (XOR, V4HImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V4HImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (XOR, V4HImode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (AND, V8QImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V8QImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V8QImode, operands))
    : -1 },
#line 2660 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE || TARGET_64BIT",
    __builtin_constant_p 
#line 2660 "../../gcc/config/i386/i386.md"
(TARGET_SSE || TARGET_64BIT)
    ? (int) 
#line 2660 "../../gcc/config/i386/i386.md"
(TARGET_SSE || TARGET_64BIT)
    : -1 },
#line 7965 "../../gcc/config/i386/i386.md"
  { "TARGET_80387",
    __builtin_constant_p 
#line 7965 "../../gcc/config/i386/i386.md"
(TARGET_80387)
    ? (int) 
#line 7965 "../../gcc/config/i386/i386.md"
(TARGET_80387)
    : -1 },
  { "(ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 13216 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (GET_MODE (operands[1]) == SFmode || GET_MODE (operands[1]) == DFmode)\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])\n\
   && SELECT_CC_MODE (GET_CODE (operands[0]),\n\
		      operands[1], operands[2]) == CCFPmode\n\
   && !TARGET_CMOVE",
    __builtin_constant_p 
#line 13216 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (GET_MODE (operands[1]) == SFmode || GET_MODE (operands[1]) == DFmode)
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && !TARGET_CMOVE)
    ? (int) 
#line 13216 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (GET_MODE (operands[1]) == SFmode || GET_MODE (operands[1]) == DFmode)
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && !TARGET_CMOVE)
    : -1 },
#line 14187 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode)",
    __builtin_constant_p 
#line 14187 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode))
    ? (int) 
#line 14187 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_POPCNT && ix86_match_ccmode (insn, CCZmode))
    : -1 },
#line 13168 "../../gcc/config/i386/i386.md"
  { "(TARGET_USE_BT || optimize_function_for_size_p (cfun))\n\
   && (INTVAL (operands[3]) & 0x1f) == 0x1f",
    __builtin_constant_p 
#line 13168 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x1f) == 0x1f)
    ? (int) 
#line 13168 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (operands[3]) & 0x1f) == 0x1f)
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (XOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V8HImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V8HImode, operands))
    : -1 },
#line 15121 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (DFmode)\n\
   && !(TARGET_SSE2 && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 15121 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(TARGET_SSE2 && TARGET_SSE_MATH))
    ? (int) 
#line 15121 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(TARGET_SSE2 && TARGET_SSE_MATH))
    : -1 },
#line 2387 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && reload_completed",
    __builtin_constant_p 
#line 2387 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && reload_completed)
    ? (int) 
#line 2387 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && reload_completed)
    : -1 },
#line 11644 "../../gcc/config/i386/sse.md"
  { "TARGET_AES && TARGET_AVX",
    __builtin_constant_p 
#line 11644 "../../gcc/config/i386/sse.md"
(TARGET_AES && TARGET_AVX)
    ? (int) 
#line 11644 "../../gcc/config/i386/sse.md"
(TARGET_AES && TARGET_AVX)
    : -1 },
#line 6352 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && !TARGET_XOP\n\
   && ix86_binary_operator_ok (EQ, V8HImode, operands)",
    __builtin_constant_p 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V8HImode, operands))
    ? (int) 
#line 6352 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && !TARGET_XOP
   && ix86_binary_operator_ok (EQ, V8HImode, operands))
    : -1 },
#line 20570 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && (TARGET_SSE4_2 || TARGET_CRC32)",
    __builtin_constant_p 
#line 20570 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_SSE4_2 || TARGET_CRC32))
    ? (int) 
#line 20570 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_SSE4_2 || TARGET_CRC32))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V16HImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V16HImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V16HImode, operands))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V8QImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V8QImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (US_PLUS, V8QImode, operands))
    : -1 },
#line 1517 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[0]))\n\
   && TARGET_CMOVE\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[0])) && TARGET_SSE_MATH)\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])",
    __builtin_constant_p 
#line 1517 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && TARGET_CMOVE
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[0])) && TARGET_SSE_MATH)
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    ? (int) 
#line 1517 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[0]))
   && TARGET_CMOVE
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[0])) && TARGET_SSE_MATH)
   && GET_MODE (operands[0]) == GET_MODE (operands[1]))
    : -1 },
#line 8186 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3 && TARGET_64BIT",
    __builtin_constant_p 
#line 8186 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && TARGET_64BIT)
    ? (int) 
#line 8186 "../../gcc/config/i386/sse.md"
(TARGET_SSE3 && TARGET_64BIT)
    : -1 },
  { "(X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || DImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    ? (int) (
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ()) && 
#line 4956 "../../gcc/config/i386/i386.md"
( 1))
    : -1 },
#line 5798 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 16722 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387",
    __builtin_constant_p 
#line 16722 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387)
    ? (int) 
#line 16722 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387)
    : -1 },
#line 14243 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_XCHGB || optimize_function_for_size_p (cfun)",
    __builtin_constant_p 
#line 14243 "../../gcc/config/i386/i386.md"
(TARGET_USE_XCHGB || optimize_function_for_size_p (cfun))
    ? (int) 
#line 14243 "../../gcc/config/i386/i386.md"
(TARGET_USE_XCHGB || optimize_function_for_size_p (cfun))
    : -1 },
#line 5509 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (MULT, V4SImode, operands)",
    __builtin_constant_p 
#line 5509 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MULT, V4SImode, operands))
    ? (int) 
#line 5509 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (MULT, V4SImode, operands))
    : -1 },
#line 2590 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE && TARGET_64BIT",
    __builtin_constant_p 
#line 2590 "../../gcc/config/i386/sse.md"
(TARGET_SSE && TARGET_64BIT)
    ? (int) 
#line 2590 "../../gcc/config/i386/sse.md"
(TARGET_SSE && TARGET_64BIT)
    : -1 },
#line 20216 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 20216 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !SIBLING_CALL_P (insn))
    ? (int) 
#line 20216 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !SIBLING_CALL_P (insn))
    : -1 },
  { "(ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 12199 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ROTATE, HImode, operands)",
    __builtin_constant_p 
#line 12199 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, HImode, operands))
    ? (int) 
#line 12199 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, HImode, operands))
    : -1 },
#line 16736 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && ((DImode != DImode) || TARGET_64BIT)\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16736 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT)
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 16729 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && ((DImode != DImode) || TARGET_64BIT)",
    __builtin_constant_p 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT))
    ? (int) 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT))
    : -1 },
#line 5409 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5409 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5409 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (XOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V4SImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (XOR, V4SImode, operands))
    : -1 },
#line 5030 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || SImode != DImode))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
   && can_create_pseudo_p ())
    ? (int) 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
   && can_create_pseudo_p ())
    : -1 },
#line 4126 "../../gcc/config/i386/i386.md"
  { "(reload_completed\n\
    && dead_or_set_p (insn, operands[1])\n\
    && !reg_mentioned_p (operands[1], operands[0]))",
    __builtin_constant_p 
#line 4126 "../../gcc/config/i386/i386.md"
((reload_completed
    && dead_or_set_p (insn, operands[1])
    && !reg_mentioned_p (operands[1], operands[0])))
    ? (int) 
#line 4126 "../../gcc/config/i386/i386.md"
((reload_completed
    && dead_or_set_p (insn, operands[1])
    && !reg_mentioned_p (operands[1], operands[0])))
    : -1 },
#line 5080 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(TARGET_64BIT && SSE_FLOAT_MODE_P (GET_MODE (operands[1])))",
    __builtin_constant_p 
#line 5080 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(TARGET_64BIT && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    ? (int) 
#line 5080 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(TARGET_64BIT && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    : -1 },
#line 2780 "../../gcc/config/i386/i386.md"
  { "reload_completed && !SSE_REG_P (operands[0])\n\
   && !SSE_REG_P (operands[1])",
    __builtin_constant_p 
#line 2780 "../../gcc/config/i386/i386.md"
(reload_completed && !SSE_REG_P (operands[0])
   && !SSE_REG_P (operands[1]))
    ? (int) 
#line 2780 "../../gcc/config/i386/i386.md"
(reload_completed && !SSE_REG_P (operands[0])
   && !SSE_REG_P (operands[1]))
    : -1 },
#line 4801 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || SSE_FLOAT_MODE_P (SFmode)",
    __builtin_constant_p 
#line 4801 "../../gcc/config/i386/i386.md"
(TARGET_80387 || SSE_FLOAT_MODE_P (SFmode))
    ? (int) 
#line 4801 "../../gcc/config/i386/i386.md"
(TARGET_80387 || SSE_FLOAT_MODE_P (SFmode))
    : -1 },
#line 5409 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5409 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5409 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (MINUS, V8SFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (MINUS, V8SFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (MINUS, V8SFmode, operands))
    : -1 },
#line 7104 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && TARGET_64BIT",
    __builtin_constant_p 
#line 7104 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && TARGET_64BIT)
    ? (int) 
#line 7104 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && TARGET_64BIT)
    : -1 },
#line 9604 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_unary_operator_ok (NOT, SImode, operands)",
    __builtin_constant_p 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands))
    ? (int) 
#line 9604 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands))
    : -1 },
#line 10578 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)",
    __builtin_constant_p 
#line 10578 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    ? (int) 
#line 10578 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
    : -1 },
#line 2722 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 2722 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 2722 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 4907 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode)\n\
   && (!TARGET_FISTTP || TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4907 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    ? (int) 
#line 4907 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    : -1 },
#line 12097 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATE, DImode, operands)",
    __builtin_constant_p 
#line 12097 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, DImode, operands))
    ? (int) 
#line 12097 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, DImode, operands))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (XOR, SImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands))
    : -1 },
#line 4949 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || SImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    ? (int) 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    : -1 },
#line 1581 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)",
    __builtin_constant_p 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode))
    ? (int) 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode))
    : -1 },
#line 1034 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCmode)",
    __builtin_constant_p 
#line 1034 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode))
    ? (int) 
#line 1034 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode))
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed)",
    __builtin_constant_p (
#line 7317 "../../gcc/config/i386/i386.md"
(TARGET_64BIT) && 
#line 7319 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 7317 "../../gcc/config/i386/i386.md"
(TARGET_64BIT) && 
#line 7319 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 4977 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || SImode != DImode))\n\
	&& TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH))
    ? (int) 
#line 4977 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || SImode != DImode))
	&& TARGET_SSE_MATH))
    : -1 },
#line 1016 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands)",
    __builtin_constant_p 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands))
    ? (int) 
#line 1016 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V4SFmode, operands))
    : -1 },
#line 4764 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode))",
    __builtin_constant_p 
#line 4764 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)))
    ? (int) 
#line 4764 "../../gcc/config/i386/i386.md"
(TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)))
    : -1 },
#line 8191 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 8191 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 8191 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 7437 "../../gcc/config/i386/sse.md"
  { "!TARGET_SSE2 && TARGET_SSE\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 7437 "../../gcc/config/i386/sse.md"
(!TARGET_SSE2 && TARGET_SSE
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 7437 "../../gcc/config/i386/sse.md"
(!TARGET_SSE2 && TARGET_SSE
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 1681 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW",
    __builtin_constant_p 
#line 1681 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW)
    ? (int) 
#line 1681 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW)
    : -1 },
#line 750 "../../gcc/config/i386/mmx.md"
  { "(TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))\n\
   && ix86_binary_operator_ok (PLUS, V4HImode, operands)",
    __builtin_constant_p 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V4HImode, operands))
    ? (int) 
#line 750 "../../gcc/config/i386/mmx.md"
((TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
   && ix86_binary_operator_ok (PLUS, V4HImode, operands))
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V4DImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V4DImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V4DImode, operands))
    : -1 },
#line 14892 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && COMMUTATIVE_ARITH_P (operands[3])\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 14892 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 14892 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && COMMUTATIVE_ARITH_P (operands[3])
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 574 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands)",
    __builtin_constant_p 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands))
    ? (int) 
#line 574 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MINUS, V4SFmode, operands))
    : -1 },
#line 5618 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5618 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5618 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 4091 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE && reload_completed",
    __builtin_constant_p 
#line 4091 "../../gcc/config/i386/sse.md"
(TARGET_SSE && reload_completed)
    ? (int) 
#line 4091 "../../gcc/config/i386/sse.md"
(TARGET_SSE && reload_completed)
    : -1 },
#line 19303 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && (true_regnum (operands[2]) != AX_REG\n\
       || satisfies_constraint_K (operands[3]))\n\
   && peep2_reg_dead_p (1, operands[2])",
    __builtin_constant_p 
#line 19303 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && (true_regnum (operands[2]) != AX_REG
       || satisfies_constraint_K (operands[3]))
   && peep2_reg_dead_p (1, operands[2]))
    ? (int) 
#line 19303 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && (true_regnum (operands[2]) != AX_REG
       || satisfies_constraint_K (operands[3]))
   && peep2_reg_dead_p (1, operands[2]))
    : -1 },
#line 9188 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)",
    __builtin_constant_p 
#line 9188 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode))
    ? (int) 
#line 9188 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode))
    : -1 },
  { "(TARGET_SSE2\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 5583 "../../gcc/config/i386/sse.md"
(TARGET_SSE2
   && can_create_pseudo_p ()) && 
#line 5586 "../../gcc/config/i386/sse.md"
( 1))
    ? (int) (
#line 5583 "../../gcc/config/i386/sse.md"
(TARGET_SSE2
   && can_create_pseudo_p ()) && 
#line 5586 "../../gcc/config/i386/sse.md"
( 1))
    : -1 },
#line 14025 "../../gcc/config/i386/i386.md"
  { "!TARGET_CMOVE",
    __builtin_constant_p 
#line 14025 "../../gcc/config/i386/i386.md"
(!TARGET_CMOVE)
    ? (int) 
#line 14025 "../../gcc/config/i386/i386.md"
(!TARGET_CMOVE)
    : -1 },
#line 6120 "../../gcc/config/i386/i386.md"
  { "TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (PLUS, HImode, operands)",
    __builtin_constant_p 
#line 6120 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    ? (int) 
#line 6120 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
    : -1 },
  { "(reload_completed) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3007 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    ? (int) (
#line 3007 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 841 "../../gcc/config/i386/i386.md"
(Pmode == DImode))
    : -1 },
#line 18684 "../../gcc/config/i386/i386.md"
  { "AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 18684 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 18684 "../../gcc/config/i386/i386.md"
(AVX_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
    : -1 },
#line 19426 "../../gcc/config/i386/i386.md"
  { "REGNO (operands[0]) != REGNO (operands[1])\n\
   && ((MMX_REG_P (operands[0]) && MMX_REG_P (operands[1])) \n\
       || (SSE_REG_P (operands[0]) && SSE_REG_P (operands[1])))",
    __builtin_constant_p 
#line 19426 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1])
   && ((MMX_REG_P (operands[0]) && MMX_REG_P (operands[1])) 
       || (SSE_REG_P (operands[0]) && SSE_REG_P (operands[1]))))
    ? (int) 
#line 19426 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1])
   && ((MMX_REG_P (operands[0]) && MMX_REG_P (operands[1])) 
       || (SSE_REG_P (operands[0]) && SSE_REG_P (operands[1]))))
    : -1 },
#line 3383 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands)",
    __builtin_constant_p 
#line 3383 "../../gcc/config/i386/sse.md"
(TARGET_SSE && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands))
    ? (int) 
#line 3383 "../../gcc/config/i386/sse.md"
(TARGET_SSE && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands))
    : -1 },
#line 620 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (MULT, V8SFmode, operands)",
    __builtin_constant_p 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (MULT, V8SFmode, operands))
    ? (int) 
#line 620 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (MULT, V8SFmode, operands))
    : -1 },
#line 9258 "../../gcc/config/i386/i386.md"
  { "ix86_unary_operator_ok (NEG, SImode, operands)",
    __builtin_constant_p 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, SImode, operands))
    ? (int) 
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, SImode, operands))
    : -1 },
#line 8530 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (AND, SImode, operands)",
    __builtin_constant_p 
#line 8530 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (AND, SImode, operands))
    ? (int) 
#line 8530 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (AND, SImode, operands))
    : -1 },
#line 9313 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 5085 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (PLUS, V4SImode, operands)",
    __builtin_constant_p 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V4SImode, operands))
    ? (int) 
#line 5085 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (PLUS, V4SImode, operands))
    : -1 },
#line 5689 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5689 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5689 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 9037 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 9037 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 9037 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    : -1 },
#line 4473 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 0)",
    __builtin_constant_p 
#line 4473 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    ? (int) 
#line 4473 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_vec_interleave_v2df_operator_ok (operands, 0))
    : -1 },
#line 1699 "../../gcc/config/i386/sse.md"
  { "SSE_FLOAT_MODE_P (DFmode)",
    __builtin_constant_p 
#line 1699 "../../gcc/config/i386/sse.md"
(SSE_FLOAT_MODE_P (DFmode))
    ? (int) 
#line 1699 "../../gcc/config/i386/sse.md"
(SSE_FLOAT_MODE_P (DFmode))
    : -1 },
#line 11696 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11696 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11696 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 3761 "../../gcc/config/i386/i386.md"
  { "reload_completed && FP_REGNO_P (REGNO (operands[0]))\n\
   && (standard_80387_constant_p (operands[1]) == 8\n\
       || standard_80387_constant_p (operands[1]) == 9)",
    __builtin_constant_p 
#line 3761 "../../gcc/config/i386/i386.md"
(reload_completed && FP_REGNO_P (REGNO (operands[0]))
   && (standard_80387_constant_p (operands[1]) == 8
       || standard_80387_constant_p (operands[1]) == 9))
    ? (int) 
#line 3761 "../../gcc/config/i386/i386.md"
(reload_completed && FP_REGNO_P (REGNO (operands[0]))
   && (standard_80387_constant_p (operands[1]) == 8
       || standard_80387_constant_p (operands[1]) == 9))
    : -1 },
#line 5618 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5618 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5618 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
  { "(TARGET_SSE4_2\n\
   && can_create_pseudo_p ()) && ( 1)",
    __builtin_constant_p (
#line 10186 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2
   && can_create_pseudo_p ()) && 
#line 10189 "../../gcc/config/i386/sse.md"
( 1))
    ? (int) (
#line 10186 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_2
   && can_create_pseudo_p ()) && 
#line 10189 "../../gcc/config/i386/sse.md"
( 1))
    : -1 },
#line 8884 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (XOR, SImode, operands)",
    __builtin_constant_p 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, SImode, operands))
    ? (int) 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, SImode, operands))
    : -1 },
#line 5618 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5618 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5618 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 15368 "../../gcc/config/i386/i386.md"
  { "(TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (SFmode))\n\
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 15368 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (SFmode))
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 15368 "../../gcc/config/i386/i386.md"
((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (SFmode))
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 19142 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY\n\
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))",
    __builtin_constant_p 
#line 19142 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0)))
    ? (int) 
#line 19142 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0)))
    : -1 },
#line 20392 "../../gcc/config/i386/i386.md"
  { "TARGET_3DNOW && TARGET_64BIT",
    __builtin_constant_p 
#line 20392 "../../gcc/config/i386/i386.md"
(TARGET_3DNOW && TARGET_64BIT)
    ? (int) 
#line 20392 "../../gcc/config/i386/i386.md"
(TARGET_3DNOW && TARGET_64BIT)
    : -1 },
#line 5197 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)",
    __builtin_constant_p 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    ? (int) 
#line 5197 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (UMIN, V16QImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V16QImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (UMIN, V16QImode, operands))
    : -1 },
#line 15083 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_ARITH (DFmode)\n\
   && !(TARGET_SSE2 && TARGET_SSE_MATH)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 15083 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(TARGET_SSE2 && TARGET_SSE_MATH)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 15083 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_ARITH (DFmode)
   && !(TARGET_SSE2 && TARGET_SSE_MATH)
   && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 11108 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))\n\
   && INTVAL (operands[2]) == 31\n\
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)",
    __builtin_constant_p 
#line 11108 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && INTVAL (operands[2]) == 31
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    ? (int) 
#line 11108 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && INTVAL (operands[2]) == 31
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
    : -1 },
#line 9506 "../../gcc/config/i386/i386.md"
  { "(SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)\n\
   || (TARGET_SSE2 && (TFmode == TFmode))",
    __builtin_constant_p 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (TFmode == TFmode)))
    ? (int) 
#line 9506 "../../gcc/config/i386/i386.md"
((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH)
   || (TARGET_SSE2 && (TFmode == TFmode)))
    : -1 },
#line 5136 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 5136 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
    ? (int) 
#line 5136 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
    : -1 },
#line 14561 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_GNU_TLS",
    __builtin_constant_p 
#line 14561 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_GNU_TLS)
    ? (int) 
#line 14561 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_GNU_TLS)
    : -1 },
#line 953 "../../gcc/config/i386/mmx.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (MULT, V2SImode, operands)",
    __builtin_constant_p 
#line 953 "../../gcc/config/i386/mmx.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V2SImode, operands))
    ? (int) 
#line 953 "../../gcc/config/i386/mmx.md"
(TARGET_SSE2 && ix86_binary_operator_ok (MULT, V2SImode, operands))
    : -1 },
  { "(ix86_unary_operator_ok (NEG, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9258 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 6337 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (EQ, V2DImode, operands)",
    __builtin_constant_p 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V2DImode, operands))
    ? (int) 
#line 6337 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (EQ, V2DImode, operands))
    : -1 },
#line 1603 "../../gcc/config/i386/sse.md"
  { "AVX256_VEC_FLOAT_MODE_P (V4DFmode)",
    __builtin_constant_p 
#line 1603 "../../gcc/config/i386/sse.md"
(AVX256_VEC_FLOAT_MODE_P (V4DFmode))
    ? (int) 
#line 1603 "../../gcc/config/i386/sse.md"
(AVX256_VEC_FLOAT_MODE_P (V4DFmode))
    : -1 },
#line 5865 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT\n\
   && ((TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)\n\
	&& TARGET_SSE)\n\
       || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))",
    __builtin_constant_p 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)))
    ? (int) 
#line 5865 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && ((TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode)
	&& TARGET_SSE)
       || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)))
    : -1 },
#line 11820 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11820 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11820 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 3183 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && (reload_in_progress || reload_completed\n\
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)\n\
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)\n\
           && optimize_function_for_size_p (cfun)\n\
	   && standard_80387_constant_p (operands[1]))\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || memory_operand (operands[0], DFmode))",
    __builtin_constant_p 
#line 3183 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode)))
    ? (int) 
#line 3183 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!(TARGET_SSE2 && TARGET_SSE_MATH)
           && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode)))
    : -1 },
#line 7639 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT && TARGET_AVX",
    __builtin_constant_p 
#line 7639 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_AVX)
    ? (int) 
#line 7639 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_AVX)
    : -1 },
#line 19031 "../../gcc/config/i386/i386.md"
  { "! TARGET_PARTIAL_REG_STALL && reload_completed\n\
   && ! TARGET_FAST_PREFIX\n\
   && optimize_insn_for_speed_p ()\n\
   /* Ensure that the operand will remain sign-extended immediate.  */\n\
   && ix86_match_ccmode (insn, INTVAL (operands[3]) >= 0 ? CCNOmode : CCZmode)",
    __builtin_constant_p 
#line 19031 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ! TARGET_FAST_PREFIX
   && optimize_insn_for_speed_p ()
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (operands[3]) >= 0 ? CCNOmode : CCZmode))
    ? (int) 
#line 19031 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ! TARGET_FAST_PREFIX
   && optimize_insn_for_speed_p ()
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (operands[3]) >= 0 ? CCNOmode : CCZmode))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMAX, V4SImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V4SImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V4SImode, operands))
    : -1 },
#line 5206 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    ? (int) 
#line 5206 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && can_create_pseudo_p ())
    : -1 },
#line 11937 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands)",
    __builtin_constant_p 
#line 11937 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    ? (int) 
#line 11937 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
    : -1 },
#line 1322 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 1322 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    ? (int) 
#line 1322 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V8SImode)\n\
       || register_operand (operands[1], V8SImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8SImode)
       || register_operand (operands[1], V8SImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V8SImode)
       || register_operand (operands[1], V8SImode)))
    : -1 },
#line 7520 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (MINUS, QImode, operands)",
    __builtin_constant_p 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, QImode, operands))
    ? (int) 
#line 7520 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, QImode, operands))
    : -1 },
  { "((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[3])) && ( reload_completed)",
    __builtin_constant_p (
#line 7281 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[3])) && 
#line 7287 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 7281 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[3])) && 
#line 7287 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
#line 19937 "../../gcc/config/i386/i386.md"
  { "TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()\n\
   && !satisfies_constraint_K (operands[2])",
    __builtin_constant_p 
#line 19937 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()
   && !satisfies_constraint_K (operands[2]))
    ? (int) 
#line 19937 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()
   && !satisfies_constraint_K (operands[2]))
    : -1 },
#line 11706 "../../gcc/config/i386/sse.md"
  { "TARGET_PCLMUL",
    __builtin_constant_p 
#line 11706 "../../gcc/config/i386/sse.md"
(TARGET_PCLMUL)
    ? (int) 
#line 11706 "../../gcc/config/i386/sse.md"
(TARGET_PCLMUL)
    : -1 },
#line 11299 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (ASHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11299 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    ? (int) 
#line 11299 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    : -1 },
#line 4941 "../../gcc/config/i386/i386.md"
  { "TARGET_AVOID_VECTOR_DECODE && optimize_insn_for_speed_p ()",
    __builtin_constant_p 
#line 4941 "../../gcc/config/i386/i386.md"
(TARGET_AVOID_VECTOR_DECODE && optimize_insn_for_speed_p ())
    ? (int) 
#line 4941 "../../gcc/config/i386/i386.md"
(TARGET_AVOID_VECTOR_DECODE && optimize_insn_for_speed_p ())
    : -1 },
  { "(TARGET_POPCNT) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 14148 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 14148 "../../gcc/config/i386/i386.md"
(TARGET_POPCNT) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 8571 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (AND, QImode, operands)",
    __builtin_constant_p 
#line 8571 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, operands))
    ? (int) 
#line 8571 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, operands))
    : -1 },
#line 9313 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 9313 "../../gcc/config/i386/i386.md"
(TARGET_80387 && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
    : -1 },
#line 1028 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands)",
    __builtin_constant_p 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands))
    ? (int) 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMIN, V4SFmode, operands))
    : -1 },
#line 11365 "../../gcc/config/i386/i386.md"
  { "(optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11365 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    ? (int) 
#line 11365 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
    : -1 },
#line 1063 "../../gcc/config/i386/sse.md"
  { "AVX128_VEC_FLOAT_MODE_P (V4SFmode)",
    __builtin_constant_p 
#line 1063 "../../gcc/config/i386/sse.md"
(AVX128_VEC_FLOAT_MODE_P (V4SFmode))
    ? (int) 
#line 1063 "../../gcc/config/i386/sse.md"
(AVX128_VEC_FLOAT_MODE_P (V4SFmode))
    : -1 },
#line 4845 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 4845 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH)
    ? (int) 
#line 4845 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH)
    : -1 },
#line 1648 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX",
    __builtin_constant_p 
#line 1648 "../../gcc/config/i386/mmx.md"
(TARGET_MMX)
    ? (int) 
#line 1648 "../../gcc/config/i386/mmx.md"
(TARGET_MMX)
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (AND, V4SImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V4SImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (AND, V4SImode, operands))
    : -1 },
#line 1322 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 1322 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    ? (int) 
#line 1322 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    : -1 },
#line 4949 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_FISTTP\n\
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || DImode != DImode))\n\
	&& TARGET_SSE_MATH)\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    ? (int) 
#line 4949 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_FISTTP
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || DImode != DImode))
	&& TARGET_SSE_MATH)
   && can_create_pseudo_p ())
    : -1 },
#line 5030 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && !TARGET_FISTTP\n\
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
	 && (TARGET_64BIT || HImode != DImode))\n\
   && can_create_pseudo_p ()",
    __builtin_constant_p 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
   && can_create_pseudo_p ())
    ? (int) 
#line 5030 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && !TARGET_FISTTP
   && !(SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
	 && (TARGET_64BIT || HImode != DImode))
   && can_create_pseudo_p ())
    : -1 },
#line 20357 "../../gcc/config/i386/i386.md"
  { "TARGET_PREFETCH_SSE && TARGET_64BIT",
    __builtin_constant_p 
#line 20357 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE && TARGET_64BIT)
    ? (int) 
#line 20357 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE && TARGET_64BIT)
    : -1 },
#line 7420 "../../gcc/config/i386/sse.md"
  { "!TARGET_64BIT\n\
   && TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 7420 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT
   && TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 7420 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT
   && TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 5653 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5653 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5653 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 15063 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (DFmode, HImode)\n\
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, HImode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 15063 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (DFmode, HImode)
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
   && (TARGET_USE_HIMODE_FIOP || optimize_function_for_size_p (cfun)))
    : -1 },
#line 20337 "../../gcc/config/i386/i386.md"
  { "TARGET_PREFETCH_SSE && !TARGET_64BIT",
    __builtin_constant_p 
#line 20337 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE && !TARGET_64BIT)
    ? (int) 
#line 20337 "../../gcc/config/i386/i386.md"
(TARGET_PREFETCH_SSE && !TARGET_64BIT)
    : -1 },
#line 5434 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5434 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5434 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
  { "(reload_completed) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 9208 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    ? (int) (
#line 9208 "../../gcc/config/i386/i386.md"
(reload_completed) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (IOR, V4SFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (IOR, V4SFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (IOR, V4SFmode, operands))
    : -1 },
#line 6268 "../../gcc/config/i386/i386.md"
  { "!TARGET_PARTIAL_REG_STALL\n\
   && ix86_binary_operator_ok (PLUS, QImode, operands)",
    __builtin_constant_p 
#line 6268 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    ? (int) 
#line 6268 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
    : -1 },
#line 1292 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && GET_MODE (operands[1]) == GET_MODE (operands[2])",
    __builtin_constant_p 
#line 1292 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && GET_MODE (operands[1]) == GET_MODE (operands[2]))
    ? (int) 
#line 1292 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && GET_MODE (operands[1]) == GET_MODE (operands[2]))
    : -1 },
#line 5639 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5639 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5639 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 7308 "../../gcc/config/i386/sse.md"
  { "reload_completed",
    __builtin_constant_p 
#line 7308 "../../gcc/config/i386/sse.md"
(reload_completed)
    ? (int) 
#line 7308 "../../gcc/config/i386/sse.md"
(reload_completed)
    : -1 },
#line 19410 "../../gcc/config/i386/i386.md"
  { "REGNO (operands[0]) != REGNO (operands[1])\n\
   && GENERAL_REGNO_P (REGNO (operands[0]))\n\
   && GENERAL_REGNO_P (REGNO (operands[1]))",
    __builtin_constant_p 
#line 19410 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1])
   && GENERAL_REGNO_P (REGNO (operands[0]))
   && GENERAL_REGNO_P (REGNO (operands[1])))
    ? (int) 
#line 19410 "../../gcc/config/i386/i386.md"
(REGNO (operands[0]) != REGNO (operands[1])
   && GENERAL_REGNO_P (REGNO (operands[0]))
   && GENERAL_REGNO_P (REGNO (operands[1])))
    : -1 },
#line 19758 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_size_p () || !TARGET_SUB_ESP_8",
    __builtin_constant_p 
#line 19758 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8)
    ? (int) 
#line 19758 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8)
    : -1 },
#line 7681 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT && TARGET_SSE",
    __builtin_constant_p 
#line 7681 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_SSE)
    ? (int) 
#line 7681 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_SSE)
    : -1 },
#line 6533 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V4DImode, operands)",
    __builtin_constant_p 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V4DImode, operands))
    ? (int) 
#line 6533 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V4DImode, operands))
    : -1 },
#line 20168 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 20168 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn))
    ? (int) 
#line 20168 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn))
    : -1 },
  { "(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math) && (TARGET_64BIT)",
    __builtin_constant_p 
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math) && (TARGET_64BIT))
    ? (int) 
((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math) && (TARGET_64BIT))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (XOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V16QImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (XOR, V16QImode, operands))
    : -1 },
#line 640 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (MULT, V4SFmode, operands)",
    __builtin_constant_p 
#line 640 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MULT, V4SFmode, operands))
    ? (int) 
#line 640 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (MULT, V4SFmode, operands))
    : -1 },
#line 3869 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && (!TARGET_ZERO_EXTEND_WITH_AND\n\
       || optimize_function_for_size_p (cfun))\n\
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1]))",
    __builtin_constant_p 
#line 3869 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND
       || optimize_function_for_size_p (cfun))
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1])))
    ? (int) 
#line 3869 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND
       || optimize_function_for_size_p (cfun))
   && (!REG_P (operands[1]) || ANY_QI_REG_P (operands[1])))
    : -1 },
#line 11771 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)",
    __builtin_constant_p 
#line 11771 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    ? (int) 
#line 11771 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
    : -1 },
#line 5366 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 5366 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387)
    ? (int) 
#line 5366 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387)
    : -1 },
#line 5366 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 5366 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387)
    ? (int) 
#line 5366 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387)
    : -1 },
#line 1611 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (XOR, V8SFmode, operands)",
    __builtin_constant_p 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (XOR, V8SFmode, operands))
    ? (int) 
#line 1611 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (XOR, V8SFmode, operands))
    : -1 },
#line 769 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V4HImode, operands)",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V4HImode, operands))
    ? (int) 
#line 769 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (SS_MINUS, V4HImode, operands))
    : -1 },
#line 13672 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT",
    __builtin_constant_p 
#line 13672 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)
    ? (int) 
#line 13672 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)
    : -1 },
#line 2414 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 2414 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 2414 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 17413 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)\n\
       || TARGET_MIX_SSE_I387)\n\
   && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 17413 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    ? (int) 
#line 17413 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
       || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    : -1 },
#line 8884 "../../gcc/config/i386/i386.md"
  { "ix86_binary_operator_ok (IOR, SImode, operands)",
    __builtin_constant_p 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, SImode, operands))
    ? (int) 
#line 8884 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, SImode, operands))
    : -1 },
#line 2439 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && reload_completed\n\
   && (! MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1]))",
    __builtin_constant_p 
#line 2439 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && (! MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1])))
    ? (int) 
#line 2439 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && (! MMX_REG_P (operands[1]) && !SSE_REG_P (operands[1])))
    : -1 },
#line 1338 "../../gcc/config/i386/i386.md"
  { "X87_FLOAT_MODE_P (GET_MODE (operands[1]))\n\
   && TARGET_SAHF && !TARGET_CMOVE\n\
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))\n\
   && (GET_MODE (operands [3]) == GET_MODE (operands[1]))",
    __builtin_constant_p 
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    ? (int) 
#line 1338 "../../gcc/config/i386/i386.md"
(X87_FLOAT_MODE_P (GET_MODE (operands[1]))
   && TARGET_SAHF && !TARGET_CMOVE
   && (TARGET_USE_SIMODE_FIOP || optimize_function_for_size_p (cfun))
   && (GET_MODE (operands [3]) == GET_MODE (operands[1])))
    : -1 },
#line 7618 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands)",
    __builtin_constant_p 
#line 7618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands))
    ? (int) 
#line 7618 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands))
    : -1 },
#line 1028 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only\n\
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands)",
    __builtin_constant_p 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands))
    ? (int) 
#line 1028 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V2DFmode) && flag_finite_math_only
   && ix86_binary_operator_ok (SMAX, V2DFmode, operands))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (AND, V2SImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V2SImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (AND, V2SImode, operands))
    : -1 },
#line 1631 "../../gcc/config/i386/sse.md"
  { "SSE_VEC_FLOAT_MODE_P (V4SFmode)\n\
   && ix86_binary_operator_ok (XOR, V4SFmode, operands)",
    __builtin_constant_p 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (XOR, V4SFmode, operands))
    ? (int) 
#line 1631 "../../gcc/config/i386/sse.md"
(SSE_VEC_FLOAT_MODE_P (V4SFmode)
   && ix86_binary_operator_ok (XOR, V4SFmode, operands))
    : -1 },
#line 7281 "../../gcc/config/i386/i386.md"
  { "(GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode\n\
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))\n\
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[1])\n\
   && GET_MODE (operands[0]) == GET_MODE (operands[3])",
    __builtin_constant_p 
#line 7281 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[3]))
    ? (int) 
#line 7281 "../../gcc/config/i386/i386.md"
((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[3]))
    : -1 },
#line 5893 "../../gcc/config/i386/i386.md"
  { "(TARGET_64BIT || TARGET_KEEPS_VECTOR_ALIGNED_STACK)\n\
   && TARGET_SSE2 && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 5893 "../../gcc/config/i386/i386.md"
((TARGET_64BIT || TARGET_KEEPS_VECTOR_ALIGNED_STACK)
   && TARGET_SSE2 && TARGET_SSE_MATH)
    ? (int) 
#line 5893 "../../gcc/config/i386/i386.md"
((TARGET_64BIT || TARGET_KEEPS_VECTOR_ALIGNED_STACK)
   && TARGET_SSE2 && TARGET_SSE_MATH)
    : -1 },
#line 7969 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 7969 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V8HImode, operands))
    ? (int) 
#line 7969 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (PLUS, V8HImode, operands))
    : -1 },
#line 6091 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (SMAX, V8HImode, operands)",
    __builtin_constant_p 
#line 6091 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SMAX, V8HImode, operands))
    ? (int) 
#line 6091 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (SMAX, V8HImode, operands))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (XOR, HImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, operands))
    : -1 },
#line 1688 "../../gcc/config/i386/sse.md"
  { "AVX_FLOAT_MODE_P (SFmode)",
    __builtin_constant_p 
#line 1688 "../../gcc/config/i386/sse.md"
(AVX_FLOAT_MODE_P (SFmode))
    ? (int) 
#line 1688 "../../gcc/config/i386/sse.md"
(AVX_FLOAT_MODE_P (SFmode))
    : -1 },
#line 14017 "../../gcc/config/i386/i386.md"
  { "TARGET_CMOVE",
    __builtin_constant_p 
#line 14017 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE)
    ? (int) 
#line 14017 "../../gcc/config/i386/i386.md"
(TARGET_CMOVE)
    : -1 },
#line 12320 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATERT, DImode, operands)",
    __builtin_constant_p 
#line 12320 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, DImode, operands))
    ? (int) 
#line 12320 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, DImode, operands))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V8HImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_PLUS, V8HImode, operands))
    : -1 },
#line 7002 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && TARGET_64BIT",
    __builtin_constant_p 
#line 7002 "../../gcc/config/i386/sse.md"
(TARGET_AVX && TARGET_64BIT)
    ? (int) 
#line 7002 "../../gcc/config/i386/sse.md"
(TARGET_AVX && TARGET_64BIT)
    : -1 },
#line 17464 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && TARGET_C99_FUNCTIONS",
    __builtin_constant_p 
#line 17464 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS)
    ? (int) 
#line 17464 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && TARGET_C99_FUNCTIONS)
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V16HImode)\n\
       || register_operand (operands[1], V16HImode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V16HImode)
       || register_operand (operands[1], V16HImode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V16HImode)
       || register_operand (operands[1], V16HImode)))
    : -1 },
#line 5126 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V8HImode, operands)",
    __builtin_constant_p 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V8HImode, operands))
    ? (int) 
#line 5126 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (US_MINUS, V8HImode, operands))
    : -1 },
#line 3333 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 3333 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 3333 "../../gcc/config/i386/sse.md"
(TARGET_SSE && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V2DFmode)\n\
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V2DFmode)
   && ix86_binary_operator_ok (MINUS, V2DFmode, operands))
    : -1 },
#line 1581 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V4DFmode)",
    __builtin_constant_p 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode))
    ? (int) 
#line 1581 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V4DFmode))
    : -1 },
#line 4037 "../../gcc/config/i386/i386.md"
  { "!TARGET_64BIT && reload_completed\n\
   && true_regnum (operands[0]) == true_regnum (operands[1])",
    __builtin_constant_p 
#line 4037 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && true_regnum (operands[0]) == true_regnum (operands[1]))
    ? (int) 
#line 4037 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && true_regnum (operands[0]) == true_regnum (operands[1]))
    : -1 },
#line 7460 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (MINUS, HImode, operands)",
    __builtin_constant_p 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands))
    ? (int) 
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands))
    : -1 },
#line 6146 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V16QImode, operands)",
    __builtin_constant_p 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V16QImode, operands))
    ? (int) 
#line 6146 "../../gcc/config/i386/sse.md"
(TARGET_SSE4_1 && ix86_binary_operator_ok (SMIN, V16QImode, operands))
    : -1 },
  { "(ix86_match_ccmode (insn, CCGOCmode)\n\
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 7460 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, DImode, operands)) && 
#line 751 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },
#line 8147 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 8147 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 8147 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 19279 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_speed_p ()\n\
   && ((TARGET_NOT_UNPAIRABLE\n\
        && (!MEM_P (operands[0])\n\
            || !memory_displacement_operand (operands[0], QImode)))\n\
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], QImode)))\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19279 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], QImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], QImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19279 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (operands[0])
            || !memory_displacement_operand (operands[0], QImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (operands[0], QImode)))
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 5366 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387",
    __builtin_constant_p 
#line 5366 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387)
    ? (int) 
#line 5366 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387)
    : -1 },
#line 7402 "../../gcc/config/i386/sse.md"
  { "!TARGET_64BIT\n\
   && TARGET_AVX\n\
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 7402 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT
   && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 7402 "../../gcc/config/i386/sse.md"
(!TARGET_64BIT
   && TARGET_AVX
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 990 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (UMAX, V8QImode, operands)",
    __builtin_constant_p 
#line 990 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (UMAX, V8QImode, operands))
    ? (int) 
#line 990 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (UMAX, V8QImode, operands))
    : -1 },
#line 16729 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && ((DImode != DImode) || TARGET_64BIT)",
    __builtin_constant_p 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT))
    ? (int) 
#line 16729 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && ((DImode != DImode) || TARGET_64BIT))
    : -1 },
#line 10132 "../../gcc/config/i386/i386.md"
  { "reload_completed\n\
   && true_regnum (operands[0]) != true_regnum (operands[1])",
    __builtin_constant_p 
#line 10132 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1]))
    ? (int) 
#line 10132 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (operands[0]) != true_regnum (operands[1]))
    : -1 },
#line 4886 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && !(MEM_P (operands[1]) && MEM_P (operands[2]))",
    __builtin_constant_p 
#line 4886 "../../gcc/config/i386/sse.md"
(TARGET_AVX && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    ? (int) 
#line 4886 "../../gcc/config/i386/sse.md"
(TARGET_AVX && !(MEM_P (operands[1]) && MEM_P (operands[2])))
    : -1 },
#line 6561 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCZmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)",
    __builtin_constant_p 
#line 6561 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    ? (int) 
#line 6561 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    : -1 },
#line 4887 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH",
    __builtin_constant_p 
#line 4887 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    ? (int) 
#line 4887 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
    : -1 },
#line 6072 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (UMIN, V16QImode, operands)",
    __builtin_constant_p 
#line 6072 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (UMIN, V16QImode, operands))
    ? (int) 
#line 6072 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (UMIN, V16QImode, operands))
    : -1 },
#line 2862 "../../gcc/config/i386/i386.md"
  { "!(MEM_P (operands[0]) && MEM_P (operands[1]))\n\
   && (reload_in_progress || reload_completed\n\
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)\n\
       || (!TARGET_SSE_MATH && optimize_function_for_size_p (cfun)\n\
	   && standard_80387_constant_p (operands[1]))\n\
       || GET_CODE (operands[1]) != CONST_DOUBLE\n\
       || memory_operand (operands[0], SFmode))",
    __builtin_constant_p 
#line 2862 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!TARGET_SSE_MATH && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], SFmode)))
    ? (int) 
#line 2862 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[0]) && MEM_P (operands[1]))
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!TARGET_SSE_MATH && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (operands[1]))
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], SFmode)))
    : -1 },
#line 537 "../../gcc/config/i386/mmx.md"
  { "TARGET_3DNOW && ix86_binary_operator_ok (EQ, V2SFmode, operands)",
    __builtin_constant_p 
#line 537 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (EQ, V2SFmode, operands))
    ? (int) 
#line 537 "../../gcc/config/i386/mmx.md"
(TARGET_3DNOW && ix86_binary_operator_ok (EQ, V2SFmode, operands))
    : -1 },
#line 5798 "../../gcc/config/i386/i386.md"
  { "TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)\n\
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES\n\
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5798 "../../gcc/config/i386/i386.md"
(TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode)
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 841 "../../gcc/config/i386/mmx.md"
  { "(TARGET_SSE || TARGET_3DNOW_A)\n\
   && ix86_binary_operator_ok (MULT, V4HImode, operands)",
    __builtin_constant_p 
#line 841 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (MULT, V4HImode, operands))
    ? (int) 
#line 841 "../../gcc/config/i386/mmx.md"
((TARGET_SSE || TARGET_3DNOW_A)
   && ix86_binary_operator_ok (MULT, V4HImode, operands))
    : -1 },
#line 7661 "../../gcc/config/i386/sse.md"
  { "TARGET_64BIT && TARGET_SSE4_1",
    __builtin_constant_p 
#line 7661 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_SSE4_1)
    ? (int) 
#line 7661 "../../gcc/config/i386/sse.md"
(TARGET_64BIT && TARGET_SSE4_1)
    : -1 },
#line 19876 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT\n\
   && (INTVAL (operands[2]) == 3\n\
       || INTVAL (operands[2]) == 5\n\
       || INTVAL (operands[2]) == 9)",
    __builtin_constant_p 
#line 19876 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    ? (int) 
#line 19876 "../../gcc/config/i386/i386.md"
(TARGET_64BIT
   && (INTVAL (operands[2]) == 3
       || INTVAL (operands[2]) == 5
       || INTVAL (operands[2]) == 9))
    : -1 },
#line 5409 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387\n\
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5409 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5409 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_MIX_SSE_I387
   && (TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 4732 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && !(MEM_P (operands[0]) && MEM_P (operands[1]))",
    __builtin_constant_p 
#line 4732 "../../gcc/config/i386/sse.md"
(TARGET_AVX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    ? (int) 
#line 4732 "../../gcc/config/i386/sse.md"
(TARGET_AVX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (XOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V4SImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (XOR, V4SImode, operands))
    : -1 },
#line 6568 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE2 && ix86_binary_operator_ok (IOR, V8HImode, operands)",
    __builtin_constant_p 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V8HImode, operands))
    ? (int) 
#line 6568 "../../gcc/config/i386/sse.md"
(TARGET_SSE2 && ix86_binary_operator_ok (IOR, V8HImode, operands))
    : -1 },
#line 5268 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   || ((DImode != DImode || TARGET_64BIT)\n\
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    ? (int) 
#line 5268 "../../gcc/config/i386/i386.md"
(TARGET_80387
   || ((DImode != DImode || TARGET_64BIT)
       && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
    : -1 },
#line 1399 "../../gcc/config/i386/sse.md"
  { "TARGET_SSE3",
    __builtin_constant_p 
#line 1399 "../../gcc/config/i386/sse.md"
(TARGET_SSE3)
    ? (int) 
#line 1399 "../../gcc/config/i386/sse.md"
(TARGET_SSE3)
    : -1 },
#line 19555 "../../gcc/config/i386/i386.md"
  { "exact_log2 (INTVAL (operands[1])) >= 0\n\
   && peep2_regno_dead_p (0, FLAGS_REG)",
    __builtin_constant_p 
#line 19555 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (operands[1])) >= 0
   && peep2_regno_dead_p (0, FLAGS_REG))
    ? (int) 
#line 19555 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (operands[1])) >= 0
   && peep2_regno_dead_p (0, FLAGS_REG))
    : -1 },
#line 5115 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V16QImode, operands)",
    __builtin_constant_p 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V16QImode, operands))
    ? (int) 
#line 5115 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (US_MINUS, V16QImode, operands))
    : -1 },
#line 11532 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ((optimize > 0 && flag_peephole2)\n\
		    ? epilogue_completed : reload_completed)",
    __builtin_constant_p 
#line 11532 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		    ? epilogue_completed : reload_completed))
    ? (int) 
#line 11532 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		    ? epilogue_completed : reload_completed))
    : -1 },
#line 6545 "../../gcc/config/i386/sse.md"
  { "(TARGET_SSE && !TARGET_SSE2)\n\
   && ix86_binary_operator_ok (IOR, V16QImode, operands)",
    __builtin_constant_p 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V16QImode, operands))
    ? (int) 
#line 6545 "../../gcc/config/i386/sse.md"
((TARGET_SSE && !TARGET_SSE2)
   && ix86_binary_operator_ok (IOR, V16QImode, operands))
    : -1 },
#line 4894 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)\n\
   && (!TARGET_FISTTP || TARGET_SSE_MATH)",
    __builtin_constant_p 
#line 4894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    ? (int) 
#line 4894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
    : -1 },
  { "(ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p 
((ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT))
    ? (int) 
((ix86_binary_operator_ok (IOR, DImode, operands)) && (TARGET_64BIT))
    : -1 },
#line 180 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && (register_operand (operands[0], V4SFmode)\n\
       || register_operand (operands[1], V4SFmode))",
    __builtin_constant_p 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4SFmode)
       || register_operand (operands[1], V4SFmode)))
    ? (int) 
#line 180 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && (register_operand (operands[0], V4SFmode)
       || register_operand (operands[1], V4SFmode)))
    : -1 },
#line 1101 "../../gcc/config/i386/mmx.md"
  { "TARGET_MMX && ix86_binary_operator_ok (IOR, V8QImode, operands)",
    __builtin_constant_p 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V8QImode, operands))
    ? (int) 
#line 1101 "../../gcc/config/i386/mmx.md"
(TARGET_MMX && ix86_binary_operator_ok (IOR, V8QImode, operands))
    : -1 },
#line 12296 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX",
    __builtin_constant_p 
#line 12296 "../../gcc/config/i386/sse.md"
(TARGET_AVX)
    ? (int) 
#line 12296 "../../gcc/config/i386/sse.md"
(TARGET_AVX)
    : -1 },
#line 17261 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math",
    __builtin_constant_p 
#line 17261 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math)
    ? (int) 
#line 17261 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !flag_trapping_math)
    : -1 },
#line 4922 "../../gcc/config/i386/i386.md"
  { "TARGET_SHORTEN_X87_SSE\n\
   && peep2_reg_dead_p (2, operands[0])",
    __builtin_constant_p 
#line 4922 "../../gcc/config/i386/i386.md"
(TARGET_SHORTEN_X87_SSE
   && peep2_reg_dead_p (2, operands[0]))
    ? (int) 
#line 4922 "../../gcc/config/i386/i386.md"
(TARGET_SHORTEN_X87_SSE
   && peep2_reg_dead_p (2, operands[0]))
    : -1 },
#line 12410 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATERT, HImode, operands)",
    __builtin_constant_p 
#line 12410 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, HImode, operands))
    ? (int) 
#line 12410 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, HImode, operands))
    : -1 },
#line 6047 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX && ix86_binary_operator_ok (SMAX, V8HImode, operands)",
    __builtin_constant_p 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V8HImode, operands))
    ? (int) 
#line 6047 "../../gcc/config/i386/sse.md"
(TARGET_AVX && ix86_binary_operator_ok (SMAX, V8HImode, operands))
    : -1 },
#line 9058 "../../gcc/config/i386/sse.md"
  { "TARGET_SSSE3",
    __builtin_constant_p 
#line 9058 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3)
    ? (int) 
#line 9058 "../../gcc/config/i386/sse.md"
(TARGET_SSSE3)
    : -1 },
#line 554 "../../gcc/config/i386/sse.md"
  { "AVX_VEC_FLOAT_MODE_P (V8SFmode)\n\
   && ix86_binary_operator_ok (PLUS, V8SFmode, operands)",
    __builtin_constant_p 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (PLUS, V8SFmode, operands))
    ? (int) 
#line 554 "../../gcc/config/i386/sse.md"
(AVX_VEC_FLOAT_MODE_P (V8SFmode)
   && ix86_binary_operator_ok (PLUS, V8SFmode, operands))
    : -1 },
#line 19832 "../../gcc/config/i386/i386.md"
  { "optimize_insn_for_size_p ()",
    __builtin_constant_p 
#line 19832 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ())
    ? (int) 
#line 19832 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ())
    : -1 },
#line 5653 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))",
    __builtin_constant_p 
#line 5653 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    ? (int) 
#line 5653 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun)))
    : -1 },
#line 11423 "../../gcc/config/i386/sse.md"
  { "TARGET_XOP",
    __builtin_constant_p 
#line 11423 "../../gcc/config/i386/sse.md"
(TARGET_XOP)
    ? (int) 
#line 11423 "../../gcc/config/i386/sse.md"
(TARGET_XOP)
    : -1 },
#line 5349 "../../gcc/config/i386/i386.md"
  { "TARGET_SSE2 && TARGET_MIX_SSE_I387\n\
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun)",
    __builtin_constant_p 
#line 5349 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun))
    ? (int) 
#line 5349 "../../gcc/config/i386/i386.md"
(TARGET_SSE2 && TARGET_MIX_SSE_I387
   && TARGET_USE_VECTOR_CONVERTS && optimize_function_for_speed_p (cfun))
    : -1 },
#line 9001 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCNOmode)\n\
   && ix86_binary_operator_ok (IOR, QImode, operands)",
    __builtin_constant_p 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, operands))
    ? (int) 
#line 9001 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, operands))
    : -1 },
#line 5674 "../../gcc/config/i386/i386.md"
  { "(SImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5674 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5674 "../../gcc/config/i386/i386.md"
((SImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 9347 "../../gcc/config/i386/i386.md"
  { "reload_completed && SSE_REG_P (operands[0])",
    __builtin_constant_p 
#line 9347 "../../gcc/config/i386/i386.md"
(reload_completed && SSE_REG_P (operands[0]))
    ? (int) 
#line 9347 "../../gcc/config/i386/i386.md"
(reload_completed && SSE_REG_P (operands[0]))
    : -1 },
  { "(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 7813 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    ? (int) (
#line 7813 "../../gcc/config/i386/i386.md"
(!(MEM_P (operands[1]) && MEM_P (operands[2]))) && 
#line 777 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
    : -1 },
#line 8921 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (IOR, SImode, operands)",
    __builtin_constant_p 
#line 8921 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (IOR, SImode, operands))
    ? (int) 
#line 8921 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (IOR, SImode, operands))
    : -1 },
#line 17253 "../../gcc/config/i386/i386.md"
  { "TARGET_USE_FANCY_MATH_387\n\
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387)\n\
   && flag_unsafe_math_optimizations",
    __builtin_constant_p 
#line 17253 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    ? (int) 
#line 17253 "../../gcc/config/i386/i386.md"
(TARGET_USE_FANCY_MATH_387
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387)
   && flag_unsafe_math_optimizations)
    : -1 },
#line 14311 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_ABM",
    __builtin_constant_p 
#line 14311 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_ABM)
    ? (int) 
#line 14311 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_ABM)
    : -1 },
#line 5394 "../../gcc/config/i386/i386.md"
  { "(DImode != DImode || TARGET_64BIT)\n\
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387\n\
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))\n\
   && reload_completed\n\
   && (SSE_REG_P (operands[0])\n\
       || (GET_CODE (operands[0]) == SUBREG\n\
	   && SSE_REG_P (operands[0])))",
    __builtin_constant_p 
#line 5394 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    ? (int) 
#line 5394 "../../gcc/config/i386/i386.md"
((DImode != DImode || TARGET_64BIT)
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_MIX_SSE_I387
   && !(TARGET_INTER_UNIT_CONVERSIONS || optimize_function_for_size_p (cfun))
   && reload_completed
   && (SSE_REG_P (operands[0])
       || (GET_CODE (operands[0]) == SUBREG
	   && SSE_REG_P (operands[0]))))
    : -1 },
#line 12187 "../../gcc/config/i386/i386.md"
  { "(TARGET_SHIFT1 || optimize_function_for_size_p (cfun))\n\
   && ix86_binary_operator_ok (ROTATE, HImode, operands)",
    __builtin_constant_p 
#line 12187 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, HImode, operands))
    ? (int) 
#line 12187 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, HImode, operands))
    : -1 },
#line 5740 "../../gcc/config/i386/i386.md"
  { "TARGET_80387\n\
   && X87_ENABLE_FLOAT (SFmode, DImode)\n\
   && reload_completed\n\
   && FP_REG_P (operands[0])",
    __builtin_constant_p 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    ? (int) 
#line 5740 "../../gcc/config/i386/i386.md"
(TARGET_80387
   && X87_ENABLE_FLOAT (SFmode, DImode)
   && reload_completed
   && FP_REG_P (operands[0]))
    : -1 },
#line 769 "../../gcc/config/i386/i386.md"
  { "TARGET_HIMODE_MATH",
    __builtin_constant_p 
#line 769 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
    ? (int) 
#line 769 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
    : -1 },
#line 12598 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && (TARGET_USE_BT || reload_completed)",
    __builtin_constant_p 
#line 12598 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || reload_completed))
    ? (int) 
#line 12598 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && (TARGET_USE_BT || reload_completed))
    : -1 },
#line 14429 "../../gcc/config/i386/i386.md"
  { "! TARGET_POPCNT",
    __builtin_constant_p 
#line 14429 "../../gcc/config/i386/i386.md"
(! TARGET_POPCNT)
    ? (int) 
#line 14429 "../../gcc/config/i386/i386.md"
(! TARGET_POPCNT)
    : -1 },
#line 6943 "../../gcc/config/i386/i386.md"
  { "ix86_match_ccmode (insn, CCGOCmode)\n\
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))\n\
   /* Current assemblers are broken and do not allow @GOTOFF in\n\
      ought but a memory context.  */\n\
   && ! pic_symbolic_operand (operands[2], VOIDmode)",
    __builtin_constant_p 
#line 6943 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    ? (int) 
#line 6943 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (operands[1]) && MEM_P (operands[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
    : -1 },
#line 6556 "../../gcc/config/i386/sse.md"
  { "TARGET_AVX\n\
   && ix86_binary_operator_ok (IOR, V4SImode, operands)",
    __builtin_constant_p 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V4SImode, operands))
    ? (int) 
#line 6556 "../../gcc/config/i386/sse.md"
(TARGET_AVX
   && ix86_binary_operator_ok (IOR, V4SImode, operands))
    : -1 },
#line 8921 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands)",
    __builtin_constant_p 
#line 8921 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands))
    ? (int) 
#line 8921 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands))
    : -1 },
#line 20811 "../../gcc/config/i386/i386.md"
  { "TARGET_LWP",
    __builtin_constant_p 
#line 20811 "../../gcc/config/i386/i386.md"
(TARGET_LWP)
    ? (int) 
#line 20811 "../../gcc/config/i386/i386.md"
(TARGET_LWP)
    : -1 },
#line 16583 "../../gcc/config/i386/i386.md"
  { "SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH\n\
   && !flag_trapping_math && !flag_rounding_math",
    __builtin_constant_p 
#line 16583 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math && !flag_rounding_math)
    ? (int) 
#line 16583 "../../gcc/config/i386/i386.md"
(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH
   && !flag_trapping_math && !flag_rounding_math)
    : -1 },
#line 18894 "../../gcc/config/i386/i386.md"
  { "TARGET_64BIT && TARGET_STACK_PROBE",
    __builtin_constant_p 
#line 18894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_STACK_PROBE)
    ? (int) 
#line 18894 "../../gcc/config/i386/i386.md"
(TARGET_64BIT && TARGET_STACK_PROBE)
    : -1 },
  { "(!TARGET_CMOVE) && ( reload_completed)",
    __builtin_constant_p (
#line 14025 "../../gcc/config/i386/i386.md"
(!TARGET_CMOVE) && 
#line 14027 "../../gcc/config/i386/i386.md"
( reload_completed))
    ? (int) (
#line 14025 "../../gcc/config/i386/i386.md"
(!TARGET_CMOVE) && 
#line 14027 "../../gcc/config/i386/i386.md"
( reload_completed))
    : -1 },
  { "(ix86_unary_operator_ok (NOT, DImode, operands)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, DImode, operands)) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    ? (int) (
#line 9572 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, DImode, operands)) && 
#line 757 "../../gcc/config/i386/i386.md"
(TARGET_64BIT))
    : -1 },

};
#endif /* gcc >= 3.0.1 */

int
main(void)
{
  unsigned int i;
  const char *p;
  puts ("(define_conditions [");
#if GCC_VERSION >= 3001
  for (i = 0; i < ARRAY_SIZE (insn_conditions); i++)
    {
      printf ("  (%d \"", insn_conditions[i].value);
      for (p = insn_conditions[i].expr; *p; p++)
        {
          switch (*p)
	     {
	     case '\\':
	     case '\"': putchar ('\\'); break;
	     default: break;
	     }
          putchar (*p);
        }
      puts ("\")");
    }
#endif /* gcc >= 3.0.1 */
  puts ("])");
  fflush (stdout);
return ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;
}
