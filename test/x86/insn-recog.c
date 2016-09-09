/* Generated automatically by the program `genrecog' from the target
   machine description file.  */

#define IN_GCC
#define IN_TRANSFORMED_CODE
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl-trans.h"
#include "tm_p.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "flags.h"

enum rtx_code swap_condition (enum rtx_code code);

#define optimize_function_for_size_p(x) 0
#define optimize_function_for_speed_p(x) 0


/* `recog' contains a decision tree that recognizes whether the rtx
   X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.  If the rtx is valid, recog
   returns a nonnegative number which is the insn code number for the
   pattern that matched.  This is the same as the order in the machine
   description of the entry that matched.  This number can be used as an
   index into `insn_data' and other tables.

   The third argument to recog is an optional pointer to an int.  If
   present, recog will accept a pattern if it matches except for missing
   CLOBBER expressions at the end.  In that case, the value pointed to by
   the optional pointer will be set to the number of CLOBBERs that need
   to be added (it should be initialized to zero by the caller).  If it
   is set nonzero, the caller should allocate a PARALLEL of the
   appropriate size, copy the initial entries, and call add_clobbers
   (found in insn-emit.c) to fill in the CLOBBERs.


   The function split_insns returns 0 if the rtl could not
   be split or the split rtl as an INSN list if it can be.

   The function peephole2_insns returns 0 if the rtl could not
   be matched. If there was a match, the new rtl is returned in an INSN list,
   and LAST_INSN will point to the last recognized insn in the old sequence.
*/

#if 0
extern rtx gen_split_321 (rtx, rtx *);
extern rtx gen_split_322 (rtx, rtx *);
extern rtx gen_split_324 (rtx, rtx *);
extern rtx gen_split_326 (rtx, rtx *);
extern rtx gen_split_327 (rtx, rtx *);
extern rtx gen_split_330 (rtx, rtx *);
extern rtx gen_split_332 (rtx, rtx *);
extern rtx gen_split_333 (rtx, rtx *);
extern rtx gen_split_334 (rtx, rtx *);
extern rtx gen_split_336 (rtx, rtx *);
extern rtx gen_split_337 (rtx, rtx *);
extern rtx gen_split_338 (rtx, rtx *);
extern rtx gen_split_340 (rtx, rtx *);
extern rtx gen_split_341 (rtx, rtx *);
extern rtx gen_split_343 (rtx, rtx *);
extern rtx gen_split_344 (rtx, rtx *);
extern rtx gen_split_345 (rtx, rtx *);
extern rtx gen_split_349 (rtx, rtx *);
extern rtx gen_split_350 (rtx, rtx *);
extern rtx gen_split_351 (rtx, rtx *);
extern rtx gen_split_352 (rtx, rtx *);
extern rtx gen_split_353 (rtx, rtx *);
extern rtx gen_split_357 (rtx, rtx *);
extern rtx gen_split_377 (rtx, rtx *);
extern rtx gen_split_378 (rtx, rtx *);
extern rtx gen_split_381 (rtx, rtx *);
extern rtx gen_split_382 (rtx, rtx *);
extern rtx gen_split_386 (rtx, rtx *);
extern rtx gen_split_387 (rtx, rtx *);
extern rtx gen_split_388 (rtx, rtx *);
extern rtx gen_split_392 (rtx, rtx *);
extern rtx gen_split_393 (rtx, rtx *);
extern rtx gen_split_394 (rtx, rtx *);
extern rtx gen_split_395 (rtx, rtx *);
extern rtx gen_split_396 (rtx, rtx *);
extern rtx gen_split_403 (rtx, rtx *);
extern rtx gen_split_404 (rtx, rtx *);
extern rtx gen_split_405 (rtx, rtx *);
extern rtx gen_split_406 (rtx, rtx *);
extern rtx gen_split_411 (rtx, rtx *);
extern rtx gen_split_415 (rtx, rtx *);
extern rtx gen_split_416 (rtx, rtx *);
extern rtx gen_split_417 (rtx, rtx *);
extern rtx gen_split_418 (rtx, rtx *);
extern rtx gen_peephole2_420 (rtx, rtx *);
extern rtx gen_split_421 (rtx, rtx *);
extern rtx gen_split_425 (rtx, rtx *);
extern rtx gen_split_426 (rtx, rtx *);
extern rtx gen_peephole2_431 (rtx, rtx *);
extern rtx gen_split_432 (rtx, rtx *);
extern rtx gen_peephole2_439 (rtx, rtx *);
extern rtx gen_split_440 (rtx, rtx *);
extern rtx gen_split_445 (rtx, rtx *);
extern rtx gen_split_448 (rtx, rtx *);
extern rtx gen_split_451 (rtx, rtx *);
extern rtx gen_split_454 (rtx, rtx *);
extern rtx gen_split_459 (rtx, rtx *);
extern rtx gen_split_460 (rtx, rtx *);
extern rtx gen_split_461 (rtx, rtx *);
extern rtx gen_split_462 (rtx, rtx *);
extern rtx gen_split_463 (rtx, rtx *);
extern rtx gen_split_464 (rtx, rtx *);
extern rtx gen_split_465 (rtx, rtx *);
extern rtx gen_split_466 (rtx, rtx *);
extern rtx gen_split_467 (rtx, rtx *);
extern rtx gen_split_468 (rtx, rtx *);
extern rtx gen_split_469 (rtx, rtx *);
extern rtx gen_split_470 (rtx, rtx *);
extern rtx gen_peephole2_473 (rtx, rtx *);
extern rtx gen_peephole2_474 (rtx, rtx *);
extern rtx gen_split_488 (rtx, rtx *);
extern rtx gen_split_491 (rtx, rtx *);
extern rtx gen_split_492 (rtx, rtx *);
extern rtx gen_split_493 (rtx, rtx *);
extern rtx gen_split_494 (rtx, rtx *);
extern rtx gen_split_495 (rtx, rtx *);
extern rtx gen_split_496 (rtx, rtx *);
extern rtx gen_peephole2_497 (rtx, rtx *);
extern rtx gen_peephole2_498 (rtx, rtx *);
extern rtx gen_peephole2_499 (rtx, rtx *);
extern rtx gen_peephole2_500 (rtx, rtx *);
extern rtx gen_peephole2_501 (rtx, rtx *);
extern rtx gen_peephole2_502 (rtx, rtx *);
extern rtx gen_peephole2_503 (rtx, rtx *);
extern rtx gen_peephole2_504 (rtx, rtx *);
extern rtx gen_peephole2_505 (rtx, rtx *);
extern rtx gen_peephole2_506 (rtx, rtx *);
extern rtx gen_peephole2_507 (rtx, rtx *);
extern rtx gen_peephole2_508 (rtx, rtx *);
extern rtx gen_peephole2_509 (rtx, rtx *);
extern rtx gen_peephole2_510 (rtx, rtx *);
extern rtx gen_peephole2_511 (rtx, rtx *);
extern rtx gen_peephole2_512 (rtx, rtx *);
extern rtx gen_peephole2_513 (rtx, rtx *);
extern rtx gen_peephole2_514 (rtx, rtx *);
extern rtx gen_peephole2_515 (rtx, rtx *);
extern rtx gen_peephole2_516 (rtx, rtx *);
extern rtx gen_peephole2_517 (rtx, rtx *);
extern rtx gen_peephole2_518 (rtx, rtx *);
extern rtx gen_peephole2_519 (rtx, rtx *);
extern rtx gen_peephole2_520 (rtx, rtx *);
extern rtx gen_peephole2_521 (rtx, rtx *);
extern rtx gen_peephole2_522 (rtx, rtx *);
extern rtx gen_peephole2_523 (rtx, rtx *);
extern rtx gen_peephole2_524 (rtx, rtx *);
extern rtx gen_peephole2_525 (rtx, rtx *);
extern rtx gen_peephole2_526 (rtx, rtx *);
extern rtx gen_peephole2_527 (rtx, rtx *);
extern rtx gen_peephole2_528 (rtx, rtx *);
extern rtx gen_peephole2_529 (rtx, rtx *);
extern rtx gen_peephole2_530 (rtx, rtx *);
extern rtx gen_peephole2_531 (rtx, rtx *);
extern rtx gen_peephole2_532 (rtx, rtx *);
extern rtx gen_peephole2_533 (rtx, rtx *);
extern rtx gen_peephole2_534 (rtx, rtx *);
extern rtx gen_peephole2_535 (rtx, rtx *);
extern rtx gen_peephole2_536 (rtx, rtx *);
extern rtx gen_peephole2_537 (rtx, rtx *);
extern rtx gen_peephole2_538 (rtx, rtx *);
extern rtx gen_peephole2_539 (rtx, rtx *);
extern rtx gen_peephole2_540 (rtx, rtx *);
extern rtx gen_peephole2_541 (rtx, rtx *);
extern rtx gen_peephole2_542 (rtx, rtx *);
extern rtx gen_peephole2_543 (rtx, rtx *);
extern rtx gen_peephole2_544 (rtx, rtx *);
extern rtx gen_peephole2_545 (rtx, rtx *);
extern rtx gen_peephole2_546 (rtx, rtx *);
extern rtx gen_peephole2_547 (rtx, rtx *);
extern rtx gen_peephole2_548 (rtx, rtx *);
extern rtx gen_peephole2_549 (rtx, rtx *);
extern rtx gen_peephole2_550 (rtx, rtx *);
extern rtx gen_peephole2_551 (rtx, rtx *);
extern rtx gen_peephole2_552 (rtx, rtx *);
extern rtx gen_peephole2_553 (rtx, rtx *);
extern rtx gen_peephole2_554 (rtx, rtx *);
extern rtx gen_peephole2_555 (rtx, rtx *);
extern rtx gen_peephole2_556 (rtx, rtx *);
extern rtx gen_peephole2_557 (rtx, rtx *);
#endif

int
recog_test (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
	rtx x1, x2, x3;
  x1 = XEXP (x0, 0);

  if(GET_CODE(x0) == 15 && GET_CODE(x1) == 20)
    return 1;
  else if (GET_CODE(x0) == 15) {
    x2 = XEXP(x0, 1);
    x3 = XEXP(x0, 2);
    enum rtx_code c1 = GET_CODE(x2) + 10;
    enum rtx_code c = c1 + c1 * 3;
    enum rtx_code d = GET_CODE(x3);    
    if (GET_CODE(x1) > c && GET_CODE(x1) < d)
      return 2;
    else if (c > d)
      return 3;
    else return 4;
  } else
    return 5;
  
ret0:
	return -1;
}

int
recog_1 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L5315;
    case ZERO_EXTRACT:
      goto L208;
    case REG:
    case SUBREG:
      goto L5301;
    default:
      goto L5312;
   }
 L5301: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L195;
    }
  
 L5312:
  if (nonimmediate_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L403;
    }
  goto ret0;

 L5315: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L101;
    }
  goto L5312;
  
 L101: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      return 13;  /* *pushsi2 */
    }
  x1 = XEXP (x0, 0);
  goto L5312;
  
 L208: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L209;
    }
  goto ret0;

 L209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L210;
  goto ret0;

 L210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L217;
  goto ret0;

 L217: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L5316;
 L211: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      return 28;  /* movsi_insv_1 */
    }
  goto ret0;

 L5316: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case LSHIFTRT:
      goto L218;
    case PLUS:
      goto L688;
    case AND:
      goto L1798;
    case IOR:
      goto L2235;
    case XOR:
      goto L2261;
    default:
     break;
   }
  goto L211;

 L218: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L219;
    }
  goto L211;

 L219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    {
      return 29;  /* *movqi_insv_2 */
    }
  goto L211;

 L688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L689;
  goto L211;

 L689: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L690;
    }
  goto L211;

 L690: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L691;
  goto L211;

 L691: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L721;
  goto L211;

 L721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L722;
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L693;
    }
  goto L211;

 L722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L723;
    }
  goto L211;

 L723: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L724;
  goto L211;

 L724: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 71;  /* *addqi_ext_2 */
    }
  goto L211;

 L693: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 70;  /* addqi_ext_1 */
    }
  x1 = XEXP (x0, 1);
  goto L211;

 L1798: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1799;
  goto L211;

 L1799: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L1800;
    }
  goto L211;

 L1800: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1801;
  goto L211;

 L1801: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1851;
  goto L211;

 L1851: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5321;
 L1802: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L1803;
    }
  goto L211;

 L5321: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L1852;
    case ZERO_EXTRACT:
      goto L1882;
    default:
     break;
   }
  goto L1802;

 L1852: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1853;
    }
  goto L1802;

 L1853: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 142;  /* *andqi_ext_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1802;

 L1882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L1883;
    }
  goto L1802;

 L1883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1884;
  goto L1802;

 L1884: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 143;  /* *andqi_ext_2 */
    }
  goto L1802;

 L1803: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 140;  /* andqi_ext_0 */
    }
  x1 = XEXP (x0, 1);
  goto L211;

 L2235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L2236;
  goto L211;

 L2236: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L2237;
    }
  goto L211;

 L2237: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2238;
  goto L211;

 L2238: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2292;
  goto L211;

 L2292: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5323;
 L2239: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L2240;
    }
  goto L211;

 L5323: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L2293;
    case ZERO_EXTRACT:
      goto L2351;
    default:
     break;
   }
  goto L2239;

 L2293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2294;
    }
  goto L2239;

 L2294: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5583 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 168;  /* *iorqi_ext_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2239;

 L2351: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L2352;
    }
  goto L2239;

 L2352: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2353;
  goto L2239;

 L2353: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && 
//#line 5602 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 170;  /* *iorqi_ext_2 */
    }
  goto L2239;

 L2240: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5545 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 166;  /* *iorqi_ext_0 */
    }
  x1 = XEXP (x0, 1);
  goto L211;

 L2261: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L2262;
  goto L211;

 L2262: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L2263;
    }
  goto L211;

 L2263: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2264;
  goto L211;

 L2264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2320;
  goto L211;

 L2320: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5325;
 L2265: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L2266;
    }
  goto L211;

 L5325: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L2321;
    case ZERO_EXTRACT:
      goto L2382;
    default:
     break;
   }
  goto L2265;

 L2321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2322;
    }
  goto L2265;

 L2322: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5583 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 169;  /* *xorqi_ext_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2265;

 L2382: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L2383;
    }
  goto L2265;

 L2383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2384;
  goto L2265;

 L2384: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && 
//#line 5602 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 171;  /* *xorqi_ext_2 */
    }
  goto L2265;

 L2266: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5545 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 167;  /* *xorqi_ext_0 */
    }
  x1 = XEXP (x0, 1);
  goto L211;

 L195: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L5327;
 L140: ATTRIBUTE_UNUSED_LABEL
  if (const0_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L141;
    }
 L150: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L151;
    }
 L392: ATTRIBUTE_UNUSED_LABEL
  if (no_seg_address_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      return 51;  /* *lea_1 */
    }
 L1190: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == MULT)
    goto L1191;
  x1 = XEXP (x0, 0);
  goto L5312;

 L5327: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTRACT:
      goto L196;
    case ZERO_EXTEND:
      goto L251;
    case SIGN_EXTEND:
      goto L345;
    case TRUNCATE:
      goto L1312;
    case NE:
    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case UNGE:
    case UNGT:
    case UNLE:
    case UNLT:
    case LTGT:
      goto L5331;
    default:
      goto L140;
   }
 L5331: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L3678;
    }
  goto L140;

 L196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L197;
    }
  goto L140;

 L197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L198;
  goto L140;

 L198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    {
      return 26;  /* *movsi_extzv_1 */
    }
  goto L140;

 L251: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L5332;
    case QImode:
      goto L5334;
    default:
      break;
    }
  goto L140;

 L5332: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L252;
    }
 L5333: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L257;
    }
  goto L140;

 L252: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2071 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 35;  /* zero_extendhisi2_and */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5333;

 L257: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2089 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND
   || optimize_function_for_size_p (cfun)))
    {
      return 36;  /* *zero_extendhisi2_movzwl */
    }
  x1 = XEXP (x0, 1);
  goto L140;

 L5334: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L298;
    }
  goto L140;

 L298: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2183 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 40;  /* *zero_extendqisi2_and */
    }
 L310: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2192 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 41;  /* *zero_extendqisi2_movzbl_and */
    }
 L315: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2200 "../../gcc/config/i386/i386.md"
((!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && reload_completed))
    {
      return 42;  /* *zero_extendqisi2_movzbl */
    }
  x1 = XEXP (x0, 1);
  goto L140;

 L345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L5335;
    case QImode:
      goto L5336;
    default:
      break;
    }
  goto L140;

 L5335: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      return 45;  /* extendhisi2 */
    }
  goto L140;

 L5336: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      return 47;  /* extendqisi2 */
    }
  goto L140;

 L1312: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L1313;
  goto L140;

 L1313: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == MULT)
    goto L1314;
  goto L140;

 L1314: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L5337;
  goto L140;

 L5337: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L1315;
    case ZERO_EXTEND:
      goto L1340;
    default:
     break;
   }
  goto L140;

 L1315: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      recog_data.operand[1] = x5;
      goto L1316;
    }
  goto L140;

 L1316: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L1317;
  goto L140;

 L1317: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      recog_data.operand[2] = x5;
      goto L1318;
    }
  goto L140;

 L1318: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
//#line 4482 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 111;  /* *smulsi3_highpart_1 */
    }
  goto L140;

 L1340: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      recog_data.operand[1] = x5;
      goto L1341;
    }
  goto L140;

 L1341: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L1342;
  goto L140;

 L1342: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      recog_data.operand[2] = x5;
      goto L1343;
    }
  goto L140;

 L1343: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
//#line 4482 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 112;  /* *umulsi3_highpart_1 */
    }
  goto L140;

 L3678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3679;
  goto L140;

 L3679: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L5339;
  goto L140;

 L5339: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0L)
    goto L5341;
  goto L140;

 L5341: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8972 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 261;  /* *setcc_si_1_and */
    }
 L5342: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8988 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))))
    {
      return 262;  /* *setcc_si_1_movzbl */
    }
  goto L140;

 L141: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1083 "../../gcc/config/i386/i386.md"
(reload_completed)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 17;  /* *movsi_xor */
    }
  x1 = XEXP (x0, 1);
  goto L150;

 L151: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1093 "../../gcc/config/i386/i386.md"
(reload_completed
   && recog_data.operand[1] == constm1_rtx)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 18;  /* *movsi_or */
    }
  x1 = XEXP (x0, 1);
  goto L392;

 L1191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1192;
    }
  x1 = XEXP (x0, 0);
  goto L5312;

 L1192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L1193;
    }
  x1 = XEXP (x0, 0);
  goto L5312;

 L1193: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4321 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 104;  /* *mulsi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L5312;

 L403: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L5343;
  goto ret0;

 L5343: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L404;
    case MINUS:
      goto L804;
    case AND:
      goto L1665;
    case IOR:
      goto L1924;
    case XOR:
      goto L1938;
    case NEG:
      goto L2453;
    case NOT:
      goto L2496;
    case ASHIFT:
      goto L2572;
    case ASHIFTRT:
      goto L2774;
    case LSHIFTRT:
      goto L3104;
    case ROTATE:
      goto L3422;
    case ROTATERT:
      goto L3554;
    default:
     break;
   }
  goto ret0;

 L404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L999;
    }
  goto ret0;

 L999: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1000;
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L406;
    }
  goto ret0;

 L1000: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L1001;
    }
  goto ret0;

 L1001: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1002;
  goto ret0;

 L1002: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1003;
  goto ret0;

 L1003: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1004;
    }
  goto ret0;

 L1004: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 90;  /* *addsi3_carry */
    }
  goto ret0;

 L406: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2646 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 52;  /* *addsi_1 */
    }
  goto ret0;

 L804: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1021;
    }
  goto ret0;

 L1021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1022;
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L806;
    }
  goto ret0;

 L1022: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L1023;
    }
  goto ret0;

 L1023: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1024;
  goto ret0;

 L1024: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1025;
  goto ret0;

 L1025: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1026;
    }
  goto ret0;

 L1026: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 91;  /* *subsi3_carry */
    }
  goto ret0;

 L806: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 78;  /* *subsi_1 */
    }
  goto ret0;

 L1665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1666;
    }
  goto ret0;

 L1666: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L1667;
    }
  goto ret0;

 L1667: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5010 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 131;  /* *andsi_1 */
    }
  goto ret0;

 L1924: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L5356;
  goto ret0;

 L5356: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFT:
      goto L2554;
    case ASHIFTRT:
      goto L2756;
    case REG:
    case SUBREG:
    case MEM:
      goto L5355;
    default:
      goto ret0;
   }
 L5355: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1925;
    }
  goto ret0;

 L2554: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2555;
  goto ret0;

 L2555: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2556;
    }
  goto ret0;

 L2556: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L2557;
  goto ret0;

 L2557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2558;
    }
  goto ret0;

 L2558: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MINUS)
    goto L2559;
  goto ret0;

 L2559: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L2560;
  goto ret0;

 L2560: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, recog_data.operand[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 186;  /* x86_shld */
    }
  goto ret0;

 L2756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2757;
  goto ret0;

 L2757: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2758;
    }
  goto ret0;

 L2758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L2759;
  goto ret0;

 L2759: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2760;
    }
  goto ret0;

 L2760: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MINUS)
    goto L2761;
  goto ret0;

 L2761: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L2762;
  goto ret0;

 L2762: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, recog_data.operand[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 199;  /* x86_shrd */
    }
  goto ret0;

 L1925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L1926;
    }
  goto ret0;

 L1926: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 146;  /* *iorsi_1 */
    }
  goto ret0;

 L1938: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1939;
    }
  goto ret0;

 L1939: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L1940;
    }
  goto ret0;

 L1940: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 147;  /* *xorsi_1 */
    }
  goto ret0;

 L2453: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L2454;
    }
  goto ret0;

 L2454: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 176;  /* *negsi2_1 */
    }
  goto ret0;

 L2496: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L2497;
    }
  goto ret0;

 L2497: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5820 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, SImode, recog_data.operand)))
    {
      return 181;  /* *one_cmplsi2_1 */
    }
  goto ret0;

 L2572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L2573;
    }
  goto ret0;

 L2573: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2574;
    }
  goto ret0;

 L2574: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6275 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 187;  /* *ashlsi3_1 */
    }
  goto ret0;

 L2774: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L2775;
    }
  goto ret0;

 L2775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L5358;
 L2803: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2804;
    }
  goto ret0;

 L5358: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L2776;
    }
 L5359: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2790;
    }
  goto L2803;

 L2776: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7308 "../../gcc/config/i386/i386.md"
(INTVAL (recog_data.operand[2]) == 31
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 200;  /* *ashrsi3_31 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5359;

 L2790: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7349 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 201;  /* *ashrsi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2803;

 L2804: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7374 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 202;  /* *ashrsi3_1 */
    }
  goto ret0;

 L3104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L3105;
    }
  goto ret0;

 L3105: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3106;
    }
 L3119: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3120;
    }
  goto ret0;

 L3106: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7901 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 222;  /* *lshrsi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3119;

 L3120: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7926 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 223;  /* *lshrsi3_1 */
    }
  goto ret0;

 L3422: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L3423;
    }
  goto ret0;

 L3423: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3424;
    }
 L3437: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3438;
    }
  goto ret0;

 L3424: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8346 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 243;  /* *rotlsi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3437;

 L3438: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8372 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 244;  /* *rotlsi3_1 */
    }
  goto ret0;

 L3554: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L3555;
    }
  goto ret0;

 L3555: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3556;
    }
 L3569: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3570;
    }
  goto ret0;

 L3556: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8569 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 252;  /* *rotrsi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3569;

 L3570: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8595 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 253;  /* *rotrsi3_1 */
    }
  goto ret0;
 ret0:
  return -1;
}

#if 0
static int
recog_2 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L5410;
    case HImode:
      goto L5411;
    case SImode:
      goto L5412;
    default:
      break;
    }
 L60: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L61;
    }
 L79: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == QImode)
    goto L5441;
  goto ret0;

 L5410: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MINUS:
      goto L40;
    case NEG:
      goto L566;
    case PLUS:
      goto L665;
    case AND:
      goto L1588;
    case IOR:
      goto L2122;
    case XOR:
      goto L2140;
    case ASHIFT:
      goto L2721;
    case ASHIFTRT:
      goto L3045;
    case LSHIFTRT:
      goto L3361;
    case REG:
    case SUBREG:
    case MEM:
      goto L5407;
    default:
      goto L5413;
   }
 L5407: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L4;
    }
 L5413: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L70;
  goto L60;

 L40: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[0] = x3;
      goto L41;
    }
  goto L60;

 L41: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L42;
    }
  goto L60;

 L42: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 854 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 6;  /* *cmpqi_minus_1 */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L566: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L567;
    }
  goto L60;

 L567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L568;
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L568: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3365 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 63;  /* *addqi_3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L60;

 L665: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L666;
    }
  goto L60;

 L666: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L667;
    }
  goto L60;

 L667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 3697 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 69;  /* *addqi_5 */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L1588: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[0] = x3;
      goto L1589;
    }
  goto L60;

 L1589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1590;
    }
  goto L60;

 L1590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L5443;
  x2 = XEXP (x1, 0);
  goto L60;

 L5443: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0L)
    goto L5445;
  x2 = XEXP (x1, 0);
  goto L60;

 L5445: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4693 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))
    && ix86_match_ccmode (insn,
 			 CONST_INT_P (recog_data.operand[1])
 			 && INTVAL (recog_data.operand[1]) >= 0 ? CCNOmode : CCZmode)))
    {
      return 123;  /* *testqi_1_maybe_si */
    }
 L5446: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4718 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 124;  /* *testqi_1 */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L2122: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2123;
    }
  goto L60;

 L2123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2124;
    }
  goto L60;

 L2124: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 160;  /* *iorqi_3 */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L2140: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2141;
    }
  goto L60;

 L2141: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2142;
    }
  goto L60;

 L2142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 161;  /* *xorqi_3 */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L2721: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2722;
    }
  goto L60;

 L2722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2723;
    }
  goto L60;

 L2723: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 6979 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 197;  /* *ashlqi3_cconly */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L3045: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3046;
    }
  goto L60;

 L3046: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5447;
  goto L60;

 L5447: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3047;
    }
 L5448: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3078;
    }
  goto L60;

 L3047: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7672 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 218;  /* *ashrqi3_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5448;

 L3078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7705 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 220;  /* *ashrqi3_cconly */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L3361: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3362;
    }
  goto L60;

 L3362: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5449;
  goto L60;

 L5449: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3363;
    }
 L5450: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3394;
    }
  goto L60;

 L3363: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8224 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 239;  /* *lshrqi2_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5450;

 L3394: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8257 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 241;  /* *lshrqi2_cconly */
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L4: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L5;
    }
 L22: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L23;
    }
  x2 = XEXP (x1, 0);
  goto L5413;

 L5: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 831 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 0;  /* *cmpqi_ccno_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L22;

 L23: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 843 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)))
    {
      return 3;  /* *cmpqi_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5413;

 L70: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L71;
  goto L60;

 L71: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[0] = x4;
      goto L72;
    }
  goto L60;

 L72: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L73;
  goto L60;

 L73: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L74;
  goto L60;

 L74: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L75;
    }
  x2 = XEXP (x1, 0);
  goto L60;

 L75: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 896 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 10;  /* *cmpqi_ext_2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L60;

 L5411: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MINUS:
      goto L47;
    case NEG:
      goto L549;
    case PLUS:
      goto L647;
    case AND:
      goto L1602;
    case IOR:
      goto L2158;
    case XOR:
      goto L2176;
    case ASHIFT:
      goto L2662;
    case ASHIFTRT:
      goto L2923;
    case LSHIFTRT:
      goto L3239;
    case REG:
    case SUBREG:
    case MEM:
      goto L5408;
    default:
      goto L5418;
   }
 L5408: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L10;
    }
 L5418: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L597;
    }
  goto ret0;

 L47: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[0] = x3;
      goto L48;
    }
  goto ret0;

 L48: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L49;
    }
  goto ret0;

 L49: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 854 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 7;  /* *cmphi_minus_1 */
    }
  goto ret0;

 L549: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L550;
    }
  goto ret0;

 L550: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L551;
    }
  goto ret0;

 L551: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3320 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 62;  /* *addhi_3 */
    }
  goto ret0;

 L647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L648;
    }
  goto ret0;

 L648: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L649;
    }
  goto ret0;

 L649: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 3651 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 68;  /* *addhi_5 */
    }
  goto ret0;

 L1602: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[0] = x3;
      goto L1603;
    }
  goto ret0;

 L1603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1604;
    }
  goto ret0;

 L1604: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4718 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 125;  /* *testhi_1 */
    }
  goto ret0;

 L2158: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2159;
    }
  goto ret0;

 L2159: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L2160;
    }
  goto ret0;

 L2160: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 162;  /* *iorhi_3 */
    }
  goto ret0;

 L2176: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2177;
    }
  goto ret0;

 L2177: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L2178;
    }
  goto ret0;

 L2178: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 163;  /* *xorhi_3 */
    }
  goto ret0;

 L2662: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2663;
    }
  goto ret0;

 L2663: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2664;
    }
  goto ret0;

 L2664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 6740 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 193;  /* *ashlhi3_cconly */
    }
  goto ret0;

 L2923: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2924;
    }
  goto ret0;

 L2924: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5451;
  goto ret0;

 L5451: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2925;
    }
 L5452: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2956;
    }
  goto ret0;

 L2925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7549 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 210;  /* *ashrhi3_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5452;

 L2956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7582 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 212;  /* *ashrhi3_cconly */
    }
  goto ret0;

 L3239: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L3240;
    }
  goto ret0;

 L3240: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5453;
  goto ret0;

 L5453: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3241;
    }
 L5454: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3272;
    }
  goto ret0;

 L3241: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8102 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 231;  /* *lshrhi3_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5454;

 L3272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8135 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 233;  /* *lshrhi3_cconly */
    }
  goto ret0;

 L10: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L11;
    }
 L28: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L29;
    }
  x2 = XEXP (x1, 0);
  goto L5418;

 L11: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 831 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 1;  /* *cmphi_ccno_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L28;

 L29: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 843 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)))
    {
      return 4;  /* *cmphi_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5418;

 L597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L598;
    }
  goto ret0;

 L598: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3512 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xffff) != 0x8000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 65;  /* *addhi_4 */
    }
  goto ret0;

 L5412: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MINUS:
      goto L54;
    case NEG:
      goto L532;
    case PLUS:
      goto L629;
    case AND:
      goto L1609;
    case ZERO_EXTRACT:
      goto L1650;
    case IOR:
      goto L2194;
    case XOR:
      goto L2212;
    case ASHIFT:
      goto L2603;
    case ASHIFTRT:
      goto L2833;
    case LSHIFTRT:
      goto L3149;
    case REG:
    case SUBREG:
    case MEM:
      goto L5409;
    default:
      goto L5417;
   }
 L5409: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L16;
    }
 L5417: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L582;
    }
  goto ret0;

 L54: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L55;
    }
  goto ret0;

 L55: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L56;
    }
  goto ret0;

 L56: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 854 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 8;  /* *cmpsi_minus_1 */
    }
  goto ret0;

 L532: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L533;
    }
  goto ret0;

 L533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L534;
    }
  goto ret0;

 L534: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3215 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (recog_data.operand[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 61;  /* *addsi_3 */
    }
  goto ret0;

 L629: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L630;
    }
  goto ret0;

 L630: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L631;
    }
  goto ret0;

 L631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 3597 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (recog_data.operand[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 67;  /* *addsi_5 */
    }
  goto ret0;

 L1609: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5456;
  goto ret0;

 L5456: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == ZERO_EXTRACT)
    goto L1617;
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L1610;
    }
  goto ret0;

 L1617: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[0] = x4;
      goto L1618;
    }
  goto ret0;

 L1618: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1619;
  goto ret0;

 L1619: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1630;
  goto ret0;

 L1630: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L5457;
 L1620: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L1621;
    }
  goto ret0;

 L5457: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L1631;
    case ZERO_EXTRACT:
      goto L1642;
    default:
     break;
   }
  goto L1620;

 L1631: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1632;
    }
  goto L1620;

 L1632: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4784 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 128;  /* *testqi_ext_1 */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L1620;

 L1642: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L1643;
    }
  goto L1620;

 L1643: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1644;
  goto L1620;

 L1644: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1645;
  goto L1620;

 L1645: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4802 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 129;  /* *testqi_ext_2 */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L1620;

 L1621: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4749 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 127;  /* *testqi_ext_0 */
    }
  goto ret0;

 L1610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1611;
    }
  goto ret0;

 L1611: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4718 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 126;  /* *testsi_1 */
    }
  goto ret0;

 L1650: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L1651;
    }
  goto ret0;

 L1651: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1652;
    }
  goto ret0;

 L1652: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1653;
    }
  goto ret0;

 L1653: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4836 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && INTVAL (recog_data.operand[1]) > 0
   && INTVAL (recog_data.operand[2]) >= 0
   && INTVAL (recog_data.operand[1]) + INTVAL (recog_data.operand[2]) <= 32
   && (GET_MODE (recog_data.operand[0]) == SImode
       || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == DImode)
       || GET_MODE (recog_data.operand[0]) == HImode
       || GET_MODE (recog_data.operand[0]) == QImode)))
    {
      return 130;  /* *testqi_ext_3 */
    }
  goto ret0;

 L2194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2195;
    }
  goto ret0;

 L2195: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L2196;
    }
  goto ret0;

 L2196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 164;  /* *iorsi_3 */
    }
  goto ret0;

 L2212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2213;
    }
  goto ret0;

 L2213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L2214;
    }
  goto ret0;

 L2214: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 165;  /* *xorsi_3 */
    }
  goto ret0;

 L2603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2604;
    }
  goto ret0;

 L2604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2605;
    }
  goto ret0;

 L2605: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 6488 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 189;  /* *ashlsi3_cconly */
    }
  goto ret0;

 L2833: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2834;
    }
  goto ret0;

 L2834: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5459;
  goto ret0;

 L5459: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2835;
    }
 L5460: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2866;
    }
  goto ret0;

 L2835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7419 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 204;  /* *ashrsi3_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5460;

 L2866: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7469 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 206;  /* *ashrsi3_cconly */
    }
  goto ret0;

 L3149: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3150;
    }
  goto ret0;

 L3150: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5461;
  goto ret0;

 L5461: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3151;
    }
 L5462: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3182;
    }
  goto ret0;

 L3151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 7972 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 225;  /* *lshrsi3_one_bit_cconly */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5462;

 L3182: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8022 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 227;  /* *lshrsi3_cconly */
    }
  goto ret0;

 L16: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L17;
    }
 L34: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L35;
    }
  x2 = XEXP (x1, 0);
  goto L5417;

 L17: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 831 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 2;  /* *cmpsi_ccno_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L34;

 L35: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 843 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)))
    {
      return 5;  /* *cmpsi_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5417;

 L582: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L583;
    }
  goto ret0;

 L583: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3467 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xffffffff) != 0x80000000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 64;  /* *addsi_4 */
    }
  goto ret0;

 L61: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L62;
  x2 = XEXP (x1, 0);
  goto L79;

 L62: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L63;
  x2 = XEXP (x1, 0);
  goto L79;

 L63: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L64;
    }
  x2 = XEXP (x1, 0);
  goto L79;

 L64: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L65;
  x2 = XEXP (x1, 0);
  goto L79;

 L65: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && 
//#line 868 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 9;  /* *cmpqi_ext_1 */
    }
  x2 = XEXP (x1, 0);
  goto L79;

 L5441: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L80;
 L5442: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L612;
    }
  goto ret0;

 L80: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L81;
  goto L5442;

 L81: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[0] = x4;
      goto L82;
    }
  goto L5442;

 L82: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L83;
  goto L5442;

 L83: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L84;
  goto L5442;

 L84: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L85;
    }
 L94: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L95;
  x2 = XEXP (x1, 0);
  goto L5442;

 L85: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 923 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 11;  /* *cmpqi_ext_3_insn */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L94;

 L95: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L96;
  x2 = XEXP (x1, 0);
  goto L5442;

 L96: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L97;
    }
  x2 = XEXP (x1, 0);
  goto L5442;

 L97: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L98;
  x2 = XEXP (x1, 0);
  goto L5442;

 L98: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)]
      && 
//#line 957 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)))
    {
      return 12;  /* *cmpqi_ext_4 */
    }
  x2 = XEXP (x1, 0);
  goto L5442;

 L612: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L613;
    }
  goto ret0;

 L613: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3557 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xff) != 0x80)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 66;  /* *addqi_4 */
    }
  goto ret0;
 ret0:
  return -1;
}
#endif

int
recog_3 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5300;
		default:
			goto ret0;
		/* TODO: nir
    case HImode:
      goto L5302;
    case QImode:
      goto L5304;
    case DImode:
      goto L5306;
    case SFmode:
      goto L5307;
    case DFmode:
      goto L5309;
    default:
      break;*/
    }
 L1: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L2;
 L1039: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x1) == CCCmode
      && GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L1040;
  switch (GET_CODE (x1))
    {
    case STRICT_LOW_PART:
      goto L172;
    case PC:
      goto L3842;
    case REG:
    case SUBREG:
      goto L726;
    default:
      goto L3899;
   }
 L726: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L727;
    }
 L3899: ATTRIBUTE_UNUSED_LABEL
  recog_data.operand[0] = x1;
  goto L3900;
 L3936: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L3937;
    }
 L4017: ATTRIBUTE_UNUSED_LABEL
  recog_data.operand[0] = x1;
  goto L4018;

 L5300: ATTRIBUTE_UNUSED_LABEL
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  //TODO: nir goto L1;
	goto ret0;

 L5302: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L154;
    }
 L5303: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L417;
    }
 L5310: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L267;
    }
  goto L1;

 L154: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_no_elim_operand (x1, HImode))
    {
      recog_data.operand[1] = x1;
      return 19;  /* *pushhi2 */
    }
  x1 = XEXP (x0, 0);
  goto L5303;

 L417: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L5360;
 L157: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, HImode))
    {
      recog_data.operand[1] = x1;
      goto L158;
    }
  x1 = XEXP (x0, 0);
  goto L5310;

 L5360: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L418;
    case MINUS:
      goto L790;
    case AND:
      goto L1679;
    case IOR:
      goto L1896;
    case XOR:
      goto L1910;
    case NEG:
      goto L2441;
    case NOT:
      goto L2491;
    case ASHIFT:
      goto L2617;
    case ASHIFTRT:
      goto L2878;
    case LSHIFTRT:
      goto L3194;
    case ROTATE:
      goto L3450;
    case ROTATERT:
      goto L3582;
    default:
     break;
   }
  goto L157;

 L418: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L955;
    }
  goto L157;

 L955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == PLUS)
    goto L956;
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L420;
    }
  goto L157;

 L956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L957;
    }
  goto L157;

 L957: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L958;
  goto L157;

 L958: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L959;
  goto L157;

 L959: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L960;
    }
  goto L157;

 L960: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 88;  /* *addhi3_carry */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L420: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2774 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 53;  /* *addhi_1 */
    }
 L434: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2822 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 54;  /* *addhi_1_lea */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L790: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L977;
    }
  goto L157;

 L977: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == PLUS)
    goto L978;
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L792;
    }
  goto L157;

 L978: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L979;
    }
  goto L157;

 L979: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L980;
  goto L157;

 L980: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L981;
  goto L157;

 L981: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L982;
    }
  goto L157;

 L982: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 89;  /* *subhi3_carry */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L792: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 77;  /* *subhi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L1679: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1680;
    }
  goto L157;

 L1680: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L1681;
    }
  goto L157;

 L1681: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5067 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 132;  /* *andhi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L1896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1897;
    }
  goto L157;

 L1897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L1898;
    }
  goto L157;

 L1898: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 144;  /* *iorhi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L1910: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1911;
    }
  goto L157;

 L1911: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L1912;
    }
  goto L157;

 L1912: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 145;  /* *xorhi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L2441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L2442;
    }
  goto L157;

 L2442: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 175;  /* *neghi2_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L2491: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L2492;
    }
  goto L157;

 L2492: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5820 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, HImode, recog_data.operand)))
    {
      return 180;  /* *one_cmplhi2_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L2617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L2618;
    }
  goto L157;

 L2618: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2619;
    }
  goto L157;

 L2619: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6594 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 190;  /* *ashlhi3_1_lea */
    }
 L2633: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6641 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 191;  /* *ashlhi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L2878: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L2879;
    }
  goto L157;

 L2879: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2880;
    }
 L2893: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2894;
    }
  goto L157;

 L2880: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7504 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 207;  /* *ashrhi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2893;

 L2894: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7516 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 208;  /* *ashrhi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L3194: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L3195;
    }
  goto L157;

 L3195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3196;
    }
 L3209: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3210;
    }
  goto L157;

 L3196: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8057 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 228;  /* *lshrhi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3209;

 L3210: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8069 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 229;  /* *lshrhi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L3450: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L3451;
    }
  goto L157;

 L3451: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3452;
    }
 L3465: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3466;
    }
  goto L157;

 L3452: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8404 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 245;  /* *rotlhi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3465;

 L3466: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8416 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 246;  /* *rotlhi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L3582: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L3583;
    }
  goto L157;

 L3583: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3584;
    }
 L3597: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3598;
    }
  goto L157;

 L3584: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8627 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 254;  /* *rotrhi3_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3597;

 L3598: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8639 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 255;  /* *rotrhi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L157;

 L158: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1160 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 20;  /* *movhi_1 */
    }
  x1 = XEXP (x0, 0);
  goto L5310;

 L267: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L5372;
  x1 = XEXP (x0, 0);
  goto L1;

 L5372: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L268;
    case SIGN_EXTEND:
      goto L349;
    case MULT:
      goto L1205;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1;

 L268: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L269;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L269: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2107 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 37;  /* *zero_extendqihi2_and */
    }
 L281: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2116 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 38;  /* *zero_extendqihi2_movzbw_and */
    }
 L286: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2125 "../../gcc/config/i386/i386.md"
((!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && reload_completed))
    {
      return 39;  /* *zero_extendqihi2_movzbl */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      return 46;  /* extendqihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == HImode)
    goto L5376;
  x1 = XEXP (x0, 0);
  goto L1;

 L5376: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L1272;
    case ZERO_EXTEND:
      goto L1290;
    case REG:
    case SUBREG:
    case MEM:
      goto L5375;
    default:
      x1 = XEXP (x0, 0);
      goto L1;
   }
 L5375: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1206;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1272: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1273;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1273: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L1274;
  x1 = XEXP (x0, 0);
  goto L1;

 L1274: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1275;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1275: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4429 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 109;  /* *mulqihi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1290: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1291;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1292;
  x1 = XEXP (x0, 0);
  goto L1;

 L1292: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1293;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1293: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4429 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 110;  /* *umulqihi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      recog_data.operand[2] = x2;
      goto L1207;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1207: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4359 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 105;  /* *mulhi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L5304: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L189;
    }
 L5313: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L1218;
    }
  goto L1;

 L189: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L5378;
 L168: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L169;
    }
 L201: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == SUBREG
      && XINT (x1, 1) == 0)
    goto L202;
  x1 = XEXP (x0, 0);
  goto L5313;

 L5378: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SIGN_EXTRACT:
      goto L190;
    case PLUS:
      goto L446;
    case MINUS:
      goto L776;
    case AND:
      goto L1693;
    case IOR:
      goto L1952;
    case XOR:
      goto L1966;
    case NEG:
      goto L2429;
    case NOT:
      goto L2501;
    case ASHIFT:
      goto L2676;
    case ASHIFTRT:
      goto L2968;
    case LSHIFTRT:
      goto L3284;
    case ROTATE:
      goto L3494;
    case ROTATERT:
      goto L3610;
    case NE:
    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case UNGE:
    case UNGT:
    case UNLE:
    case UNLT:
    case LTGT:
      goto L5391;
    default:
      goto L168;
   }
 L5391: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L3688;
    }
  goto L168;

 L190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L191;
    }
  goto L168;

 L191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L192;
  goto L168;

 L192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    {
      return 25;  /* *movqi_extv_1 */
    }
  goto L168;

 L446: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L911;
    }
  goto L168;

 L911: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L912;
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L448;
    }
  goto L168;

 L912: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L913;
    }
  goto L168;

 L913: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L914;
  goto L168;

 L914: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L915;
  goto L168;

 L915: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L916;
    }
  goto L168;

 L916: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 86;  /* *addqi3_carry */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L448: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2870 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 55;  /* *addqi_1 */
    }
 L462: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2922 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 56;  /* *addqi_1_lea */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L933;
    }
  goto L168;

 L933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L934;
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L778;
    }
  goto L168;

 L934: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_carry_flag_operator (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L935;
    }
  goto L168;

 L935: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L936;
  goto L168;

 L936: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L937;
  goto L168;

 L937: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L938;
    }
  goto L168;

 L938: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 87;  /* *subqi3_carry */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L778: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 76;  /* *subqi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L1693: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1694;
    }
  goto L168;

 L1694: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1695;
    }
  goto L168;

 L1695: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5098 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 133;  /* *andqi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L1952: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1953;
    }
  goto L168;

 L1953: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1954;
    }
  goto L168;

 L1954: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 148;  /* *iorqi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L1966: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1967;
    }
  goto L168;

 L1967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1968;
    }
  goto L168;

 L1968: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 149;  /* *xorqi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L2429: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2430;
    }
  goto L168;

 L2430: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 174;  /* *negqi2_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L2501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2502;
    }
  goto L168;

 L2502: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5829 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NOT, QImode, recog_data.operand)))
    {
      return 182;  /* *one_cmplqi2_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L2676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2677;
    }
  goto L168;

 L2677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2678;
    }
  goto L168;

 L2678: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6797 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 194;  /* *ashlqi3_1_lea */
    }
 L2692: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6862 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 195;  /* *ashlqi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L2968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2969;
    }
  goto L168;

 L2969: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2970;
    }
 L2999: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3000;
    }
  goto L168;

 L2970: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7601 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 213;  /* *ashrqi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2999;

 L3000: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7626 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 215;  /* *ashrqi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L3284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3285;
    }
  goto L168;

 L3285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3286;
    }
 L3315: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3316;
    }
  goto L168;

 L3286: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8154 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 234;  /* *lshrqi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3315;

 L3316: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8178 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 236;  /* *lshrqi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L3494: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3495;
    }
  goto L168;

 L3495: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3496;
    }
 L3525: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3526;
    }
  goto L168;

 L3496: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8457 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 248;  /* *rotlqi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3525;

 L3526: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8482 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 250;  /* *rotlqi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L3610: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3611;
    }
  goto L168;

 L3611: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3612;
    }
 L3641: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3642;
    }
  goto L168;

 L3612: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8668 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 256;  /* *rotrqi3_1_one_bit */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3641;

 L3642: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8692 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 258;  /* *rotrqi3_1 */
    }
  x1 = XEXP (x0, 1);
  goto L168;

 L3688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3689;
  goto L168;

 L3689: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 263;  /* *setcc_qi */
    }
  goto L168;

 L169: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1236 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 22;  /* *movqi_1 */
    }
  x1 = XEXP (x0, 1);
  goto L201;

 L202: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L203;
  x1 = XEXP (x0, 0);
  goto L5313;

 L203: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L204;
    }
  x1 = XEXP (x0, 0);
  goto L5313;

 L204: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L205;
  x1 = XEXP (x0, 0);
  goto L5313;

 L205: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    {
      return 27;  /* *movqi_extzv_2 */
    }
  x1 = XEXP (x0, 0);
  goto L5313;

 L1218: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L5392;
  x1 = XEXP (x0, 0);
  goto L1;

 L5392: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MULT:
      goto L1219;
    case DIV:
      goto L1355;
    case UDIV:
      goto L1369;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1;

 L1219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1220;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1221;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1221: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4378 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 106;  /* *mulqi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1355: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1356;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1356: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1357;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1357: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4514 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 113;  /* divqi3 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1369: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1370;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1370: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L1371;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1371: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4514 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 114;  /* udivqi3 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L5306: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L222;
    }
 L5311: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L325;
    }
 L5314: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L1234;
    }
  goto L1;

 L222: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, DImode))
    {
      recog_data.operand[1] = x1;
      return 30;  /* *pushdi */
    }
  x1 = XEXP (x0, 0);
  goto L5311;

 L325: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L5395;
  x1 = XEXP (x0, 0);
  goto L5314;

 L5395: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L326;
    case SIGN_EXTEND:
      goto L340;
    case PLUS:
      goto L365;
    case MINUS:
      goto L762;
    case NEG:
      goto L2417;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L5314;

 L326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L327;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L327: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 43;  /* zero_extendsidi2_32 */
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L340: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L341;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L341: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 44;  /* *extendsidi2_1 */
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L365: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L366;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, DImode))
    {
      recog_data.operand[2] = x2;
      goto L367;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L367: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 2572 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, DImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 48;  /* *adddi3_doubleword */
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L762: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L763;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L763: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, DImode))
    {
      recog_data.operand[2] = x2;
      goto L764;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L764: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 4056 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 75;  /* *subdi3_doubleword */
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L2417: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L2418;
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L2418: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 5733 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 173;  /* *negdi2_doubleword */
    }
  x1 = XEXP (x0, 0);
  goto L5314;

 L1234: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L5400;
  x1 = XEXP (x0, 0);
  goto L1;

 L5400: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MULT:
      goto L1235;
    case ASHIFTRT:
      goto L2735;
    case LSHIFTRT:
      goto L3090;
    case ROTATE:
      goto L3408;
    case ROTATERT:
      goto L3540;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1;

 L1235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L5405;
  x1 = XEXP (x0, 0);
  goto L1;

 L5405: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L1236;
    case ZERO_EXTEND:
      goto L1254;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1;

 L1236: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1237;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1237: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L1238;
  x1 = XEXP (x0, 0);
  goto L1;

 L1238: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1239;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1239: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 4415 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 107;  /* *mulsidi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1254: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1255;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1255: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1256;
  x1 = XEXP (x0, 0);
  goto L1;

 L1256: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1257;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L1257: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 4415 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 108;  /* *umulsidi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2735: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L2736;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2736: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L2737;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2737: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 198;  /* *ashrdi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3090: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L3091;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3091: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3092;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3092: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 221;  /* *lshrdi3_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L3409;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_1_to_31_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3410;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3410: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 242;  /* ix86_rotldi3 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3540: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L3541;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_1_to_31_operand (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L3542;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L3542: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 251;  /* ix86_rotrdi3 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L5307: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SFmode))
    {
      recog_data.operand[0] = x1;
      goto L225;
    }
 L5308: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      recog_data.operand[0] = x1;
      goto L228;
    }
  goto L1;

 L225: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, SFmode))
    {
      recog_data.operand[1] = x1;
      return 31;  /* *pushsf */
    }
  x1 = XEXP (x0, 0);
  goto L5308;

 L228: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, SFmode))
    {
      recog_data.operand[1] = x1;
      goto L229;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L229: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1923 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || (!TARGET_SSE_MATH && optimize_function_for_size_p (cfun)
	   && standard_80387_constant_p (recog_data.operand[1]))
       || GET_CODE (recog_data.operand[1]) != CONST_DOUBLE
       || memory_operand (recog_data.operand[0], SFmode))))
    {
      return 32;  /* *movsf_1 */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L5309: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, DFmode))
    {
      recog_data.operand[0] = x1;
      goto L239;
    }
  goto L1;

 L239: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, DFmode))
    {
      recog_data.operand[1] = x1;
      goto L240;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L240: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2043 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !TARGET_INTEGER_DFMODE_MOVES))
    {
      return 34;  /* *pushdf_nointeger */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == COMPARE)
    goto L3;
  x1 = XEXP (x0, 0);
  goto L1039;

 L3: ATTRIBUTE_UNUSED_LABEL
  tem = recog_2 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L1039;

 L1040: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCCmode
      && GET_CODE (x1) == COMPARE)
    goto L1041;
  x1 = XEXP (x0, 0);
  goto L726;

 L1041: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L5463;
    case HImode:
      goto L5464;
    case SImode:
      goto L5465;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L5463: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1042;
    case MINUS:
      goto L1085;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L726;

 L1042: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1043;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1043: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1044;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1044: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[1])
      && 
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 92;  /* *addqi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1085: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[0] = x3;
      goto L1086;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1087;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1087: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    {
      return 95;  /* *subqi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L5464: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1060;
    case MINUS:
      goto L1092;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L726;

 L1060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1061;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1061: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1062;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[1])
      && 
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 93;  /* *addhi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1092: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[0] = x3;
      goto L1093;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1093: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1094;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1094: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    {
      return 96;  /* *subhi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L5465: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1078;
    case MINUS:
      goto L1099;
    case ZERO_EXTRACT:
      goto L3663;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L726;

 L1078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1079;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1080;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[1])
      && 
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 94;  /* *addsi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1099: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L1100;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1101;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L1101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    {
      return 97;  /* *subsi3_cconly_overflow */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L3663: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L3664;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L3664: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3665;
  x1 = XEXP (x0, 0);
  goto L726;

 L3665: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (nonmemory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3666;
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L3666: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 8942 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)))
    {
      return 260;  /* *btsi */
    }
  x1 = XEXP (x0, 0);
  goto L726;

 L172: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == QImode)
    goto L5470;
  goto L3899;

 L5470: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L475;
    }
 L5471: ATTRIBUTE_UNUSED_LABEL
  if (q_regs_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L185;
    }
  goto L3899;

 L475: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L5472;
 L173: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L174;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L5471;

 L5472: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L476;
    case MINUS:
      goto L820;
    case AND:
      goto L1709;
    case IOR:
      goto L1982;
    case XOR:
      goto L1998;
    case ASHIFTRT:
      goto L2984;
    case LSHIFTRT:
      goto L3300;
    case ROTATE:
      goto L3480;
    case ROTATERT:
      goto L3626;
    case NE:
    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case UNGE:
    case UNGT:
    case UNLE:
    case UNLT:
    case LTGT:
      goto L5481;
    default:
      goto L173;
   }
 L5481: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L3694;
    }
  goto L173;

 L476: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L477;
  goto L173;

 L477: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L478;
    }
  goto L173;

 L478: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2977 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 57;  /* *addqi_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L821;
  goto L173;

 L821: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L822;
    }
  goto L173;

 L822: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4099 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 79;  /* *subqi_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L1709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L1710;
  goto L173;

 L1710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1711;
    }
  goto L173;

 L1711: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5111 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 134;  /* *andqi_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L1982: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L1983;
  goto L173;

 L1983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L1984;
    }
  goto L173;

 L1984: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5458 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 150;  /* *iorqi_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L1998: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L1999;
  goto L173;

 L1999: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2000;
    }
  goto L173;

 L2000: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5458 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 151;  /* *xorqi_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L2984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L2985;
  goto L173;

 L2985: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L2986;
    }
 L3015: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3016;
    }
  goto L173;

 L2986: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7613 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 214;  /* *ashrqi3_1_one_bit_slp */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3015;

 L3016: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7638 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 216;  /* *ashrqi3_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L3300: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L3301;
  goto L173;

 L3301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3302;
    }
 L3331: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3332;
    }
  goto L173;

 L3302: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8166 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 235;  /* *lshrqi3_1_one_bit_slp */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3331;

 L3332: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8190 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 237;  /* *lshrqi3_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L3480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L3481;
  goto L173;

 L3481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3482;
    }
 L3511: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3512;
    }
  goto L173;

 L3482: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8445 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 247;  /* *rotlqi3_1_one_bit_slp */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3511;

 L3512: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8469 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 249;  /* *rotlqi3_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L3626: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L3627;
  goto L173;

 L3627: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const1_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3628;
    }
 L3657: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L3658;
    }
  goto L173;

 L3628: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8680 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 257;  /* *rotrqi3_1_one_bit_slp */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3657;

 L3658: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8704 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 259;  /* *rotrqi3_1_slp */
    }
  x1 = XEXP (x0, 1);
  goto L173;

 L3694: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3695;
  goto L173;

 L3695: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 264;  /* *setcc_qi_slp */
    }
  goto L173;

 L174: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1312 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 23;  /* *movstrictqi_1 */
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L5471;

 L185: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L186;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L186: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1322 "../../gcc/config/i386/i386.md"
(reload_completed)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 24;  /* *movstrictqi_xor */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3842: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonimmediate_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      return 272;  /* *indirect_jump */
    }
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L3699;
    case LABEL_REF:
      goto L3839;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3699: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L3700;
    }
 L3733: ATTRIBUTE_UNUSED_LABEL
  if (bt_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L3734;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3700: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L3701;
  goto L3733;

 L3701: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3702;
  goto L3733;

 L3702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L3703;
    case PC:
      goto L3712;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3733;

 L3703: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[0] = x3;
  goto L3704;

 L3704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return 265;  /* *jcc_1 */
    }
  x2 = XEXP (x1, 0);
  goto L3733;

 L3712: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3713;
  x2 = XEXP (x1, 0);
  goto L3733;

 L3713: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[0] = x3;
  return 266;  /* *jcc_2 */

 L3734: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5482;
  x1 = XEXP (x0, 0);
  goto L3899;

 L5482: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTRACT:
      goto L3735;
    case AND:
      goto L3793;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3735: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L3736;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3736: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3737;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3737: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_MODE (x4) == SImode)
    goto L5484;
  x1 = XEXP (x0, 0);
  goto L3899;

 L5484: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTEND:
      goto L3738;
    case AND:
      goto L3767;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3738: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, QImode))
    {
      recog_data.operand[2] = x5;
      goto L3739;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3739: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3740;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3740: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3741;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3741: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[3] = x3;
  goto L3742;

 L3742: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
//#line 9258 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 267;  /* *jcc_btsi */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3767: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      recog_data.operand[2] = x5;
      goto L3768;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3768: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      recog_data.operand[3] = x5;
      goto L3769;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3769: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3770;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3770: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[4] = x3;
  goto L3771;

 L3771: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
//#line 9291 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 268;  /* *jcc_btsi_mask */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3793: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L3794;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3794: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      recog_data.operand[1] = x5;
      goto L3795;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3795: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == QImode)
    goto L5486;
  x1 = XEXP (x0, 0);
  goto L3899;

 L5486: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x5, QImode))
    {
      recog_data.operand[2] = x5;
      goto L3796;
    }
 L5487: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x5) == SUBREG
      && XINT (x5, 1) == 0)
    goto L3828;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3796: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3797;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L5487;

 L3797: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3798;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L5487;

 L3798: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3799;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L5487;

 L3799: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[3] = x3;
  goto L3800;

 L3800: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
//#line 9320 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 269;  /* *jcc_btsi_1 */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L5487;

 L3828: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == AND)
    goto L3829;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3829: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (register_operand (x7, SImode))
    {
      recog_data.operand[2] = x7;
      goto L3830;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3830: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 1);
  if (const_int_operand (x7, SImode))
    {
      recog_data.operand[3] = x7;
      goto L3831;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3831: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3832;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3832: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3833;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3833: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3834;
  x1 = XEXP (x0, 0);
  goto L3899;

 L3834: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[4] = x3;
  goto L3835;

 L3835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
//#line 9357 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 270;  /* *jcc_btsi_mask_1 */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3839: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  recog_data.operand[0] = x2;
  return 271;  /* jump */

 L727: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == PLUS)
    goto L728;
  x1 = XEXP (x0, 0);
  goto L3899;

 L728: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L745;
    case MULT:
      goto L737;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L3899;

 L745: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == MULT)
    goto L746;
  if (index_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L730;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L746: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (index_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L747;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L747: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const248_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L748;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L748: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L749;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L749: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      recog_data.operand[4] = x2;
      goto L750;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L750: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3935 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])))
    {
      return 74;  /* *lea_general_3 */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L730: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L731;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L731: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L732;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L732: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3831 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[2])
   && (GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])
       || GET_MODE (recog_data.operand[3]) == VOIDmode)))
    {
      return 72;  /* *lea_general_1 */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L737: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (index_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L738;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L738: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const248_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L739;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L739: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L740;
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L740: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3884 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && (GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])
       || GET_MODE (recog_data.operand[3]) == VOIDmode)))
    {
      return 73;  /* *lea_general_2 */
    }
  x1 = XEXP (x0, 0);
  goto L3899;

 L3900: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == BLKmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 18)
    goto L3901;
  x1 = XEXP (x0, 0);
  goto L3936;

 L3901: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    {
      return 281;  /* *memory_blockage */
    }
  x1 = XEXP (x0, 0);
  goto L3936;

 L3937: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 12)
    goto L3938;
  x1 = XEXP (x0, 0);
  goto L4017;

 L3938: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_CODE (x2))
    {
    case CONST_INT:
      goto L5488;
    case LABEL_REF:
      goto L3951;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L4017;

 L5488: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0L
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 290;  /* set_got */
    }
  x1 = XEXP (x0, 0);
  goto L4017;

 L3951: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[1] = x3;
  goto L3952;

 L3952: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 291;  /* set_got_labelled */
    }
  x1 = XEXP (x0, 0);
  goto L4017;

 L4018: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CALL)
    goto L4019;
  goto ret0;

 L4019: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MEM)
    goto L4020;
  goto ret0;

 L4020: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5489;
  goto ret0;

 L5489: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4021;
    }
 L5490: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4027;
    }
 L5491: ATTRIBUTE_UNUSED_LABEL
  if (sibcall_insn_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4063;
    }
  goto ret0;

 L4021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[2] = x2;
  return 298;  /* *call_value_0 */

 L4027: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[2] = x2;
  goto L4028;

 L4028: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 11116 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn)))
    {
      return 299;  /* *call_value_1 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5491;

 L4063: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[2] = x2;
  goto L4064;

 L4064: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 11160 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn)))
    {
      return 302;  /* *sibcall_value_1 */
    }
  goto ret0;
 ret0:
  return -1;
}

#if 0
int
recog_4 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L126;
    case PLUS:
      goto L397;
    case MINUS:
      goto L797;
    case AND:
      goto L1658;
    case IOR:
      goto L1917;
    case XOR:
      goto L1931;
    case NEG:
      goto L2447;
    case ASHIFT:
      goto L2565;
    case ASHIFTRT:
      goto L2767;
    case LSHIFTRT:
      goto L3097;
    case ROTATE:
      goto L3415;
    case ROTATERT:
      goto L3547;
    default:
     break;
   }
  goto ret0;

 L126: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L127;
  goto ret0;

 L127: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L128;
  goto ret0;

 L128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L129;
  goto ret0;

 L129: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L130;
  goto ret0;

 L130: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L131;
  goto ret0;

 L131: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (4)])
    {
      return 16;  /* popsi1 */
    }
  goto ret0;

 L397: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L988;
    }
  goto ret0;

 L988: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L989;
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L399;
    }
  goto ret0;

 L989: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L990;
    }
  goto ret0;

 L990: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L991;
  goto ret0;

 L991: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L992;
  goto ret0;

 L992: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L993;
    }
  goto ret0;

 L993: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L994;
  goto ret0;

 L994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 90;  /* *addsi3_carry */
    }
  goto ret0;

 L399: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L400;
  goto ret0;

 L400: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2646 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 52;  /* *addsi_1 */
    }
  goto ret0;

 L797: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1010;
    }
  goto ret0;

 L1010: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L1011;
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L799;
    }
  goto ret0;

 L1011: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L1012;
    }
  goto ret0;

 L1012: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1013;
  goto ret0;

 L1013: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1014;
  goto ret0;

 L1014: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1015;
    }
  goto ret0;

 L1015: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1016;
  goto ret0;

 L1016: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 91;  /* *subsi3_carry */
    }
  goto ret0;

 L799: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L800;
  goto ret0;

 L800: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)))
    {
      return 78;  /* *subsi_1 */
    }
  goto ret0;

 L1658: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1659;
    }
  goto ret0;

 L1659: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1660;
    }
  goto ret0;

 L1660: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1661;
  goto ret0;

 L1661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5010 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, SImode, recog_data.operand)))
    {
      return 131;  /* *andsi_1 */
    }
  goto ret0;

 L1917: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5532;
  goto ret0;

 L5532: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ASHIFT:
      goto L2541;
    case ASHIFTRT:
      goto L2743;
    case REG:
    case SUBREG:
    case MEM:
      goto L5531;
    default:
      goto ret0;
   }
 L5531: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1918;
    }
  goto ret0;

 L2541: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[0]))
    goto L2542;
  goto ret0;

 L2542: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2543;
    }
  goto ret0;

 L2543: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L2544;
  goto ret0;

 L2544: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2545;
    }
  goto ret0;

 L2545: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == QImode
      && GET_CODE (x4) == MINUS)
    goto L2546;
  goto ret0;

 L2546: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L2547;
  goto ret0;

 L2547: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, recog_data.operand[2]))
    goto L2548;
  goto ret0;

 L2548: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2549;
  goto ret0;

 L2549: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 186;  /* x86_shld */
    }
  goto ret0;

 L2743: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[0]))
    goto L2744;
  goto ret0;

 L2744: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2745;
    }
  goto ret0;

 L2745: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFT)
    goto L2746;
  goto ret0;

 L2746: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2747;
    }
  goto ret0;

 L2747: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == QImode
      && GET_CODE (x4) == MINUS)
    goto L2748;
  goto ret0;

 L2748: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L2749;
  goto ret0;

 L2749: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, recog_data.operand[2]))
    goto L2750;
  goto ret0;

 L2750: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2751;
  goto ret0;

 L2751: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 199;  /* x86_shrd */
    }
  goto ret0;

 L1918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1919;
    }
  goto ret0;

 L1919: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1920;
  goto ret0;

 L1920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, SImode, recog_data.operand)))
    {
      return 146;  /* *iorsi_1 */
    }
  goto ret0;

 L1931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1932;
    }
  goto ret0;

 L1932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1933;
    }
  goto ret0;

 L1933: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1934;
  goto ret0;

 L1934: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, SImode, recog_data.operand)))
    {
      return 147;  /* *xorsi_1 */
    }
  goto ret0;

 L2447: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2448;
    }
  goto ret0;

 L2448: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2449;
  goto ret0;

 L2449: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, SImode, recog_data.operand)))
    {
      return 176;  /* *negsi2_1 */
    }
  goto ret0;

 L2565: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2566;
    }
  goto ret0;

 L2566: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2567;
    }
  goto ret0;

 L2567: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2568;
  goto ret0;

 L2568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 6275 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFT, SImode, recog_data.operand)))
    {
      return 187;  /* *ashlsi3_1 */
    }
  goto ret0;

 L2767: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L2768;
    }
  goto ret0;

 L2768: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5534;
 L2796: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2797;
    }
  goto ret0;

 L5534: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L2769;
    }
 L5535: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2783;
    }
  goto L2796;

 L2769: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2770;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5535;

 L2770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7308 "../../gcc/config/i386/i386.md"
(INTVAL (recog_data.operand[2]) == 31
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 200;  /* *ashrsi3_31 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5535;

 L2783: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2784;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2796;

 L2784: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7349 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 201;  /* *ashrsi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2796;

 L2797: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2798;
  goto ret0;

 L2798: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7374 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 202;  /* *ashrsi3_1 */
    }
  goto ret0;

 L3097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3098;
    }
  goto ret0;

 L3098: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3099;
    }
 L3112: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3113;
    }
  goto ret0;

 L3099: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3100;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3112;

 L3100: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7901 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 222;  /* *lshrsi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3112;

 L3113: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3114;
  goto ret0;

 L3114: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7926 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 223;  /* *lshrsi3_1 */
    }
  goto ret0;

 L3415: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3416;
    }
  goto ret0;

 L3416: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3417;
    }
 L3430: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3431;
    }
  goto ret0;

 L3417: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3418;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3430;

 L3418: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8346 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, SImode, recog_data.operand)))
    {
      return 243;  /* *rotlsi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3430;

 L3431: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3432;
  goto ret0;

 L3432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8372 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, SImode, recog_data.operand)))
    {
      return 244;  /* *rotlsi3_1 */
    }
  goto ret0;

 L3547: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3548;
    }
  goto ret0;

 L3548: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3549;
    }
 L3562: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3563;
    }
  goto ret0;

 L3549: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3550;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3562;

 L3550: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8569 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, SImode, recog_data.operand)))
    {
      return 252;  /* *rotrsi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3562;

 L3563: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3564;
  goto ret0;

 L3564: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8595 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, SImode, recog_data.operand)))
    {
      return 253;  /* *rotrsi3_1 */
    }
  goto ret0;
 ret0:
  return -1;
}
#endif

#if 0
static int
recog_5 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L5508;
    case ZERO_EXTRACT:
      goto L671;
    default:
     break;
   }
 L5493: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L125;
    }
 L5494: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L244;
    }
  goto ret0;

 L5508: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L105;
    }
  goto L5493;

 L105: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_no_elim_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L106;
    }
  x2 = XEXP (x1, 0);
  goto L5493;

 L106: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L107;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5493;

 L107: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L108;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5493;

 L108: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    {
      return 14;  /* *pushsi2_prologue */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5493;

 L671: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L672;
    }
  goto ret0;

 L672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L673;
  goto ret0;

 L673: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L674;
  goto ret0;

 L674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5509;
  goto ret0;

 L5509: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L675;
    case AND:
      goto L1785;
    case IOR:
      goto L2222;
    case XOR:
      goto L2248;
    default:
     break;
   }
  goto ret0;

 L675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L676;
  goto ret0;

 L676: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L677;
    }
  goto ret0;

 L677: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L678;
  goto ret0;

 L678: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L705;
  goto ret0;

 L705: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L706;
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L680;
    }
  goto ret0;

 L706: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L707;
    }
  goto ret0;

 L707: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L708;
  goto ret0;

 L708: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L709;
  goto ret0;

 L709: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L710;
  goto ret0;

 L710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 71;  /* *addqi_ext_2 */
    }
  goto ret0;

 L680: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L681;
  goto ret0;

 L681: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 70;  /* addqi_ext_1 */
    }
  goto ret0;

 L1785: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1786;
  goto ret0;

 L1786: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L1787;
    }
  goto ret0;

 L1787: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1788;
  goto ret0;

 L1788: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1837;
  goto ret0;

 L1837: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L5513;
 L1789: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L1790;
    }
  goto ret0;

 L5513: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L1838;
    case ZERO_EXTRACT:
      goto L1866;
    default:
     break;
   }
  goto L1789;

 L1838: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1839;
    }
  goto L1789;

 L1839: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1840;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1789;

 L1840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 142;  /* *andqi_ext_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1789;

 L1866: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L1867;
    }
  goto L1789;

 L1867: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1868;
  goto L1789;

 L1868: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1869;
  goto L1789;

 L1869: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1870;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1789;

 L1870: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 143;  /* *andqi_ext_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1789;

 L1790: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1791;
  goto ret0;

 L1791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 140;  /* andqi_ext_0 */
    }
  goto ret0;

 L2222: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L2223;
  goto ret0;

 L2223: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L2224;
    }
  goto ret0;

 L2224: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2225;
  goto ret0;

 L2225: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2278;
  goto ret0;

 L2278: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L5515;
 L2226: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L2227;
    }
  goto ret0;

 L5515: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2279;
    case ZERO_EXTRACT:
      goto L2335;
    default:
     break;
   }
  goto L2226;

 L2279: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2280;
    }
  goto L2226;

 L2280: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2281;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2226;

 L2281: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5583 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))))
    {
      return 168;  /* *iorqi_ext_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2226;

 L2335: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L2336;
    }
  goto L2226;

 L2336: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2337;
  goto L2226;

 L2337: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2338;
  goto L2226;

 L2338: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2339;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2226;

 L2339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5602 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    {
      return 170;  /* *iorqi_ext_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2226;

 L2227: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2228;
  goto ret0;

 L2228: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5545 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    {
      return 166;  /* *iorqi_ext_0 */
    }
  goto ret0;

 L2248: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L2249;
  goto ret0;

 L2249: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L2250;
    }
  goto ret0;

 L2250: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2251;
  goto ret0;

 L2251: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2306;
  goto ret0;

 L2306: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L5517;
 L2252: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L2253;
    }
  goto ret0;

 L5517: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2307;
    case ZERO_EXTRACT:
      goto L2366;
    default:
     break;
   }
  goto L2252;

 L2307: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2308;
    }
  goto L2252;

 L2308: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2309;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2252;

 L2309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5583 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))))
    {
      return 169;  /* *xorqi_ext_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2252;

 L2366: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L2367;
    }
  goto L2252;

 L2367: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2368;
  goto L2252;

 L2368: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2369;
  goto L2252;

 L2369: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2370;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2252;

 L2370: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5602 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    {
      return 171;  /* *xorqi_ext_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2252;

 L2253: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2254;
  goto ret0;

 L2254: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5545 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    {
      return 167;  /* *xorqi_ext_0 */
    }
  goto ret0;

 L125: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5519;
  x2 = XEXP (x1, 0);
  goto L5494;

 L5519: ATTRIBUTE_UNUSED_LABEL
  tem = recog_4 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L5494;

 L244: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5536;
 L135: ATTRIBUTE_UNUSED_LABEL
  if (const0_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L136;
    }
 L145: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L146;
    }
  goto ret0;

 L5536: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L245;
    case MULT:
      goto L1184;
    case DIV:
      goto L1413;
    case UDIV:
      goto L1519;
    case UNSPEC:
      goto L5543;
    case NE:
    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case UNGE:
    case UNGT:
    case UNLE:
    case UNLT:
    case LTGT:
      goto L5540;
    case REG:
    case SUBREG:
      goto L5541;
    default:
      goto L135;
   }
 L5540: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L3671;
    }
 L5541: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L3924;
    }
  goto L135;

 L245: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L5544;
    case QImode:
      goto L5545;
    default:
      break;
    }
  goto L135;

 L5544: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L246;
    }
  goto L135;

 L246: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L247;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2071 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)))
    {
      return 35;  /* zero_extendhisi2_and */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L5545: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L292;
    }
  goto L135;

 L292: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L293;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L293: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5546;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L5546: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5548;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L5548: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5550;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L5550: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2183 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)))
    {
      return 40;  /* *zero_extendqisi2_and */
    }
 L5551: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2192 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun)))
    {
      return 41;  /* *zero_extendqisi2_movzbl_and */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L1185;
    }
  goto L135;

 L1185: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1186;
    }
  goto L135;

 L1186: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1187;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4321 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 104;  /* *mulsi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1413: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1414;
    }
  goto L135;

 L1414: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1415;
    }
  goto L135;

 L1415: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1416;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1416: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1417;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1417: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L1418;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1418: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1419;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1419: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 116;  /* *divmodsi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1519: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1520;
    }
  goto L135;

 L1520: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1521;
    }
  goto L135;

 L1521: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1522;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1523;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L1524;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1525;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L1525: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 120;  /* *udivmodsi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L5543: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 12)
    goto L3932;
  goto L135;

 L3932: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  switch (GET_CODE (x3))
    {
    case CONST_INT:
      goto L5552;
    case LABEL_REF:
      goto L3944;
    default:
     break;
   }
  goto L135;

 L5552: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 0L)
    goto L3933;
  goto L135;

 L3933: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3934;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3934: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 290;  /* set_got */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3944: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[1] = x4;
  goto L3945;

 L3945: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3946;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3946: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 291;  /* set_got_labelled */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3671: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L3672;
  goto L135;

 L3672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3673;
  goto L135;

 L3673: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3674;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8972 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)))
    {
      return 261;  /* *setcc_si_1_and */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3924: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC_VOLATILE
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 21)
    goto L3925;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L3925: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 288;  /* vswapmov */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L135;

 L136: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L137;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L145;

 L137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 1083 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 17;  /* *movsi_xor */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L145;

 L146: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L147;
  goto ret0;

 L147: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 1093 "../../gcc/config/i386/i386.md"
(reload_completed
   && recog_data.operand[1] == constm1_rtx))
    {
      return 18;  /* *movsi_or */
    }
  goto ret0;
 ret0:
  return -1;
}

int
recog_6 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L162;
    }
 L5499: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L410;
    }
  goto ret0;

 L162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5554;
  x2 = XEXP (x1, 0);
  goto L5499;

 L5554: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L262;
    case MULT:
      goto L1198;
    case DIV:
      goto L1389;
    case UDIV:
      goto L1495;
    case REG:
    case SUBREG:
      goto L5553;
    default:
      x2 = XEXP (x1, 0);
      goto L5499;
   }
 L5553: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L163;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L262: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L263;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L263: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L264;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L264: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5558;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L5558: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5560;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L5560: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5562;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L5562: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2107 "../../gcc/config/i386/i386.md"
(TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)))
    {
      return 37;  /* *zero_extendqihi2_and */
    }
 L5563: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2116 "../../gcc/config/i386/i386.md"
(!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun)))
    {
      return 38;  /* *zero_extendqihi2_movzbw_and */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1198: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode)
    goto L5565;
  x2 = XEXP (x1, 0);
  goto L5499;

 L5565: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L1263;
    case ZERO_EXTEND:
      goto L1281;
    case REG:
    case SUBREG:
    case MEM:
      goto L5564;
    default:
      x2 = XEXP (x1, 0);
      goto L5499;
   }
 L5564: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1199;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1263: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1264;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L1265;
  x2 = XEXP (x1, 0);
  goto L5499;

 L1265: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1266;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1266: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1267;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1267: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4429 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 109;  /* *mulqihi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1281: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1282;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1282: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L1283;
  x2 = XEXP (x1, 0);
  goto L5499;

 L1283: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1284;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1284: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1285;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4429 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 110;  /* *umulqihi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1200;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1200: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1201;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4359 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 105;  /* *mulhi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1389: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1390;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1391;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1391: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1392;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1392: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1393;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1393: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L1394;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1394: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1395;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1395: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 115;  /* *divmodhi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1496;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1496: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1497;
    }
  x2 = XEXP (x1, 0);
  goto L5499;

 L1497: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1498;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1498: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1499;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1499: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == UMOD)
    goto L1500;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1500: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1501;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L1501: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 119;  /* *udivmodhi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L163: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L164;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L164: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[1]))
    goto L165;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L165: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0])
      && 
//#line 1217 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun)))
    {
      return 21;  /* *swaphi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5499;

 L410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5567;
  goto ret0;

 L5567: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L411;
    case MINUS:
      goto L783;
    case AND:
      goto L1672;
    case IOR:
      goto L1889;
    case XOR:
      goto L1903;
    case NEG:
      goto L2435;
    case ASHIFT:
      goto L2610;
    case ASHIFTRT:
      goto L2871;
    case LSHIFTRT:
      goto L3187;
    case ROTATE:
      goto L3443;
    case ROTATERT:
      goto L3575;
    default:
     break;
   }
  goto ret0;

 L411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L944;
    }
  goto ret0;

 L944: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == PLUS)
    goto L945;
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L413;
    }
  goto ret0;

 L945: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L946;
    }
  goto ret0;

 L946: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L947;
  goto ret0;

 L947: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L948;
  goto ret0;

 L948: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L949;
    }
  goto ret0;

 L949: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L950;
  goto ret0;

 L950: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 88;  /* *addhi3_carry */
    }
  goto ret0;

 L413: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L414;
  goto ret0;

 L414: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5578;
  goto ret0;

 L5578: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5580;
  goto ret0;

 L5580: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5582;
  goto ret0;

 L5582: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2774 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 53;  /* *addhi_1 */
    }
 L5583: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2822 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 54;  /* *addhi_1_lea */
    }
  goto ret0;

 L783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L966;
    }
  goto ret0;

 L966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == PLUS)
    goto L967;
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L785;
    }
  goto ret0;

 L967: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L968;
    }
  goto ret0;

 L968: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L969;
  goto ret0;

 L969: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L970;
  goto ret0;

 L970: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L971;
    }
  goto ret0;

 L971: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L972;
  goto ret0;

 L972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 89;  /* *subhi3_carry */
    }
  goto ret0;

 L785: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L786;
  goto ret0;

 L786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, HImode, recog_data.operand)))
    {
      return 77;  /* *subhi_1 */
    }
  goto ret0;

 L1672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1673;
    }
  goto ret0;

 L1673: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1674;
    }
  goto ret0;

 L1674: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1675;
  goto ret0;

 L1675: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5067 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, HImode, recog_data.operand)))
    {
      return 132;  /* *andhi_1 */
    }
  goto ret0;

 L1889: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1890;
    }
  goto ret0;

 L1890: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1891;
    }
  goto ret0;

 L1891: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1892;
  goto ret0;

 L1892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, HImode, recog_data.operand)))
    {
      return 144;  /* *iorhi_1 */
    }
  goto ret0;

 L1903: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1904;
    }
  goto ret0;

 L1904: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1905;
    }
  goto ret0;

 L1905: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1906;
  goto ret0;

 L1906: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5411 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, HImode, recog_data.operand)))
    {
      return 145;  /* *xorhi_1 */
    }
  goto ret0;

 L2435: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2436;
    }
  goto ret0;

 L2436: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2437;
  goto ret0;

 L2437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, HImode, recog_data.operand)))
    {
      return 175;  /* *neghi2_1 */
    }
  goto ret0;

 L2610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2611;
    }
  goto ret0;

 L2611: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2612;
    }
  goto ret0;

 L2612: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2613;
  goto ret0;

 L2613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5584;
  goto ret0;

 L5584: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5586;
  goto ret0;

 L5586: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5588;
  goto ret0;

 L5588: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6594 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand)))
    {
      return 190;  /* *ashlhi3_1_lea */
    }
 L5589: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6641 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand)))
    {
      return 191;  /* *ashlhi3_1 */
    }
  goto ret0;

 L2871: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L2872;
    }
  goto ret0;

 L2872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2873;
    }
 L2886: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2887;
    }
  goto ret0;

 L2873: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2874;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2886;

 L2874: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7504 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 207;  /* *ashrhi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2886;

 L2887: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2888;
  goto ret0;

 L2888: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7516 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 208;  /* *ashrhi3_1 */
    }
  goto ret0;

 L3187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L3188;
    }
  goto ret0;

 L3188: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3189;
    }
 L3202: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3203;
    }
  goto ret0;

 L3189: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3190;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3202;

 L3190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8057 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 228;  /* *lshrhi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3202;

 L3203: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3204;
  goto ret0;

 L3204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8069 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 229;  /* *lshrhi3_1 */
    }
  goto ret0;

 L3443: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L3444;
    }
  goto ret0;

 L3444: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3445;
    }
 L3458: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3459;
    }
  goto ret0;

 L3445: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3446;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3458;

 L3446: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8404 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, HImode, recog_data.operand)))
    {
      return 245;  /* *rotlhi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3458;

 L3459: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3460;
  goto ret0;

 L3460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8416 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, HImode, recog_data.operand)))
    {
      return 246;  /* *rotlhi3_1 */
    }
  goto ret0;

 L3575: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L3576;
    }
  goto ret0;

 L3576: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3577;
    }
 L3590: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3591;
    }
  goto ret0;

 L3577: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3578;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3590;

 L3578: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8627 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, HImode, recog_data.operand)))
    {
      return 254;  /* *rotrhi3_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3590;

 L3591: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3592;
  goto ret0;

 L3592: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8639 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, HImode, recog_data.operand)))
    {
      return 255;  /* *rotrhi3_1 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_7 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L438;
    }
 L5502: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L1211;
    }
  goto ret0;

 L438: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L5601;
  x2 = XEXP (x1, 0);
  goto L5502;

 L5601: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L439;
    case MINUS:
      goto L769;
    case AND:
      goto L1686;
    case IOR:
      goto L1945;
    case XOR:
      goto L1959;
    case NEG:
      goto L2423;
    case ASHIFT:
      goto L2669;
    case ASHIFTRT:
      goto L2961;
    case LSHIFTRT:
      goto L3277;
    case ROTATE:
      goto L3487;
    case ROTATERT:
      goto L3603;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5502;

 L439: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L900;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L900: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == PLUS)
    goto L901;
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L441;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L901: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L902;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L902: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L903;
  x2 = XEXP (x1, 0);
  goto L5502;

 L903: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L904;
  x2 = XEXP (x1, 0);
  goto L5502;

 L904: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L905;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L905: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L906;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L906: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 86;  /* *addqi3_carry */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L441: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L442;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L442: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5612;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5612: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5614;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5614: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5616;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5616: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2870 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 55;  /* *addqi_1 */
    }
 L5617: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2922 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 56;  /* *addqi_1_lea */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L769: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L922;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L922: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == PLUS)
    goto L923;
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L771;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L923: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ix86_carry_flag_operator (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L924;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L924: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L925;
  x2 = XEXP (x1, 0);
  goto L5502;

 L925: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L926;
  x2 = XEXP (x1, 0);
  goto L5502;

 L926: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L927;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L927: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L928;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L928: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4186 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 87;  /* *subqi3_carry */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L771: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L772;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L772: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4078 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, QImode, recog_data.operand)))
    {
      return 76;  /* *subqi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1686: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1687;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1687: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1688;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1688: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1689;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1689: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5098 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, recog_data.operand)))
    {
      return 133;  /* *andqi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1945: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1946;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1947;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1947: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1948;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1948: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (IOR, QImode, recog_data.operand)))
    {
      return 148;  /* *iorqi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1959: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1960;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1960: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1961;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L1961: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1962;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1962: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5422 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (XOR, QImode, recog_data.operand)))
    {
      return 149;  /* *xorqi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2423: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2424;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L2424: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2425;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5756 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, QImode, recog_data.operand)))
    {
      return 174;  /* *negqi2_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2669: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2670;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L2670: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2671;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L2671: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2672;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2672: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5618;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5618: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5620;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5620: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5622;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L5622: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6797 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand)))
    {
      return 194;  /* *ashlqi3_1_lea */
    }
 L5623: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6862 "../../gcc/config/i386/i386.md"
(TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand)))
    {
      return 195;  /* *ashlqi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2961: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2962;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L2962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2963;
    }
 L2992: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2993;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L2963: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2964;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2992;

 L2964: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7601 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 213;  /* *ashrqi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2992;

 L2993: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2994;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L2994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7626 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 215;  /* *ashrqi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3277: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3278;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3278: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3279;
    }
 L3308: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3309;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3279: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3280;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3308;

 L3280: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8154 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 234;  /* *lshrqi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3308;

 L3309: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3310;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3310: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8178 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 236;  /* *lshrqi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3488;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3488: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3489;
    }
 L3518: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3519;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3489: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3490;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3518;

 L3490: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8457 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATE, QImode, recog_data.operand)))
    {
      return 248;  /* *rotlqi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3518;

 L3519: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3520;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8482 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATE, QImode, recog_data.operand)))
    {
      return 250;  /* *rotlqi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3604;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3605;
    }
 L3634: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3635;
    }
  x2 = XEXP (x1, 0);
  goto L5502;

 L3605: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3606;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3634;

 L3606: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8668 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ROTATERT, QImode, recog_data.operand)))
    {
      return 256;  /* *rotrqi3_1_one_bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3634;

 L3635: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3636;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L3636: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8692 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (ROTATERT, QImode, recog_data.operand)))
    {
      return 258;  /* *rotrqi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5502;

 L1211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L5624;
  goto ret0;

 L5624: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L1212;
    case DIV:
      goto L1348;
    case UDIV:
      goto L1362;
    default:
     break;
   }
  goto ret0;

 L1212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1213;
    }
  goto ret0;

 L1213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1214;
    }
  goto ret0;

 L1214: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1215;
  goto ret0;

 L1215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4378 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 106;  /* *mulqi3_1 */
    }
  goto ret0;

 L1348: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1349;
    }
  goto ret0;

 L1349: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1350;
    }
  goto ret0;

 L1350: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1351;
  goto ret0;

 L1351: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4514 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH))
    {
      return 113;  /* divqi3 */
    }
  goto ret0;

 L1362: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L1363;
    }
  goto ret0;

 L1363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L1364;
    }
  goto ret0;

 L1364: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1365;
  goto ret0;

 L1365: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4514 "../../gcc/config/i386/i386.md"
(TARGET_QIMODE_MATH))
    {
      return 114;  /* udivqi3 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_8 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L484;
    case NEG:
      goto L523;
    case MINUS:
      goto L854;
    case AND:
      goto L1756;
    case IOR:
      goto L2058;
    case XOR:
      goto L2071;
    case NOT:
      goto L2530;
    case ASHIFT:
      goto L2580;
    case ASHIFTRT:
      goto L2810;
    case LSHIFTRT:
      goto L3126;
    case REG:
    case SUBREG:
    case MEM:
      goto L5647;
    default:
      goto ret0;
   }
 L5647: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L574;
    }
  goto ret0;

 L484: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L485;
    }
  goto ret0;

 L485: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L486;
    }
  goto ret0;

 L486: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L487;
  goto ret0;

 L487: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L488;
    case CLOBBER:
      goto L623;
    default:
     break;
   }
  goto ret0;

 L488: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L489;
    }
  goto ret0;

 L489: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L490;
  goto ret0;

 L490: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L491;
  goto ret0;

 L491: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 3021 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (recog_data.operand[2], VOIDmode)))
    {
      return 58;  /* *addsi_2 */
    }
  goto ret0;

 L623: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L624;
    }
  goto ret0;

 L624: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3597 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (recog_data.operand[2], VOIDmode)))
    {
      return 67;  /* *addsi_5 */
    }
  goto ret0;

 L523: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L524;
    }
  goto ret0;

 L524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L525;
    }
  goto ret0;

 L525: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L526;
  goto ret0;

 L526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L527;
    }
  goto ret0;

 L527: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3215 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (recog_data.operand[2], VOIDmode)))
    {
      return 61;  /* *addsi_3 */
    }
  goto ret0;

 L854: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L855;
    }
  goto ret0;

 L855: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L856;
    }
  goto ret0;

 L856: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L857;
  goto ret0;

 L857: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L858;
  goto ret0;

 L858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L859;
    }
  goto ret0;

 L859: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L860;
  goto ret0;

 L860: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L861;
  goto ret0;

 L861: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4114 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)))
    {
      return 82;  /* *subsi_2 */
    }
  goto ret0;

 L1756: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5675;
  goto ret0;

 L5675: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L1810;
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L1757;
    }
  goto ret0;

 L1810: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (ext_register_operand (x5, VOIDmode))
    {
      recog_data.operand[1] = x5;
      goto L1811;
    }
  goto ret0;

 L1811: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1812;
  goto ret0;

 L1812: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1813;
  goto ret0;

 L1813: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L1814;
    }
  goto ret0;

 L1814: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1815;
  goto ret0;

 L1815: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1816;
  goto ret0;

 L1816: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1817;
  goto ret0;

 L1817: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L1818;
    }
  goto ret0;

 L1818: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1819;
  goto ret0;

 L1819: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1820;
  goto ret0;

 L1820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1821;
  goto ret0;

 L1821: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1822;
  goto ret0;

 L1822: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[1]))
    goto L1823;
  goto ret0;

 L1823: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1824;
  goto ret0;

 L1824: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L1825;
  goto ret0;

 L1825: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5285 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return 141;  /* *andqi_ext_0_cc */
    }
  goto ret0;

 L1757: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1758;
    }
  goto ret0;

 L1758: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1759;
  goto ret0;

 L1759: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1760;
  goto ret0;

 L1760: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1761;
    }
  goto ret0;

 L1761: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1762;
  goto ret0;

 L1762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1763;
  goto ret0;

 L1763: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5207 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, recog_data.operand)))
    {
      return 138;  /* *andsi_2 */
    }
  goto ret0;

 L2058: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2059;
    }
  goto ret0;

 L2059: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L2060;
    }
  goto ret0;

 L2060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2061;
  goto ret0;

 L2061: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2062;
    case CLOBBER:
      goto L2188;
    default:
     break;
   }
  goto ret0;

 L2062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2063;
    }
  goto ret0;

 L2063: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L2064;
  goto ret0;

 L2064: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2065;
  goto ret0;

 L2065: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, recog_data.operand)))
    {
      return 156;  /* *iorsi_2 */
    }
  goto ret0;

 L2188: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2189;
    }
  goto ret0;

 L2189: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, recog_data.operand)))
    {
      return 164;  /* *iorsi_3 */
    }
  goto ret0;

 L2071: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5677;
  goto ret0;

 L5677: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L2391;
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2072;
    }
  goto ret0;

 L2391: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (ext_register_operand (x5, VOIDmode))
    {
      recog_data.operand[1] = x5;
      goto L2392;
    }
  goto ret0;

 L2392: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2393;
  goto ret0;

 L2393: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2394;
  goto ret0;

 L2394: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2395;
    }
  goto ret0;

 L2395: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2396;
  goto ret0;

 L2396: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2397;
  goto ret0;

 L2397: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L2398;
  goto ret0;

 L2398: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L2399;
    }
  goto ret0;

 L2399: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2400;
  goto ret0;

 L2400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2401;
  goto ret0;

 L2401: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == XOR)
    goto L2402;
  goto ret0;

 L2402: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L2403;
  goto ret0;

 L2403: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[1]))
    goto L2404;
  goto ret0;

 L2404: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2405;
  goto ret0;

 L2405: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L2406;
  goto ret0;

 L2406: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5715 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 172;  /* *xorqi_cc_ext_1 */
    }
  goto ret0;

 L2072: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L2073;
    }
  goto ret0;

 L2073: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2074;
  goto ret0;

 L2074: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2075;
    case CLOBBER:
      goto L2206;
    default:
     break;
   }
  goto ret0;

 L2075: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2076;
    }
  goto ret0;

 L2076: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == XOR)
    goto L2077;
  goto ret0;

 L2077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2078;
  goto ret0;

 L2078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, recog_data.operand)))
    {
      return 157;  /* *xorsi_2 */
    }
  goto ret0;

 L2206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2207;
    }
  goto ret0;

 L2207: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, recog_data.operand)))
    {
      return 165;  /* *xorsi_3 */
    }
  goto ret0;

 L2530: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2531;
    }
  goto ret0;

 L2531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2532;
  goto ret0;

 L2532: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2533;
  goto ret0;

 L2533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2534;
    }
  goto ret0;

 L2534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L2535;
  goto ret0;

 L2535: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5852 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, recog_data.operand)))
    {
      return 185;  /* *one_cmplsi2_2 */
    }
  goto ret0;

 L2580: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2581;
    }
  goto ret0;

 L2581: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2582;
    }
  goto ret0;

 L2582: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2583;
  goto ret0;

 L2583: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2584;
    case CLOBBER:
      goto L2597;
    default:
     break;
   }
  goto ret0;

 L2584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2585;
    }
  goto ret0;

 L2585: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L2586;
  goto ret0;

 L2586: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2587;
  goto ret0;

 L2587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 6438 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
     || !TARGET_PARTIAL_FLAG_REG_STALL
     || (recog_data.operand[2] == const1_rtx
	 && (TARGET_SHIFT1
	     || (TARGET_DOUBLE_WITH_ADD && REG_P (recog_data.operand[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, recog_data.operand)))
    {
      return 188;  /* *ashlsi3_cmp */
    }
  goto ret0;

 L2597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2598;
    }
  goto ret0;

 L2598: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6488 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, recog_data.operand)))
    {
      return 189;  /* *ashlsi3_cconly */
    }
  goto ret0;

 L2810: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2811;
    }
  goto ret0;

 L2811: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5678;
  goto ret0;

 L5678: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2812;
    }
 L5679: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2843;
    }
  goto ret0;

 L2812: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2813;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2813: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2814;
    case CLOBBER:
      goto L2827;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2814: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2815;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2815: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2816;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2817;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2817: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7404 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 203;  /* *ashrsi3_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2827: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2828;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2828: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7419 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 204;  /* *ashrsi3_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5679;

 L2843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2844;
  goto ret0;

 L2844: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2845;
    case CLOBBER:
      goto L2858;
    default:
     break;
   }
  goto ret0;

 L2845: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2846;
    }
  goto ret0;

 L2846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2847;
  goto ret0;

 L2847: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2848;
  goto ret0;

 L2848: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7455 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 205;  /* *ashrsi3_cmp */
    }
  goto ret0;

 L2858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2859;
    }
  goto ret0;

 L2859: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7469 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, recog_data.operand)))
    {
      return 206;  /* *ashrsi3_cconly */
    }
  goto ret0;

 L3126: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L3127;
    }
  goto ret0;

 L3127: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5680;
  goto ret0;

 L5680: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3128;
    }
 L5681: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3159;
    }
  goto ret0;

 L3128: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3129;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3129: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3130;
    case CLOBBER:
      goto L3143;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3130: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3131;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3131: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3132;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3132: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3133;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3133: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7957 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 224;  /* *lshrsi3_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3144;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3144: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7972 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 225;  /* *lshrsi3_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5681;

 L3159: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3160;
  goto ret0;

 L3160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3161;
    case CLOBBER:
      goto L3174;
    default:
     break;
   }
  goto ret0;

 L3161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3162;
    }
  goto ret0;

 L3162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3163;
  goto ret0;

 L3163: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3164;
  goto ret0;

 L3164: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 8008 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 226;  /* *lshrsi3_cmp */
    }
  goto ret0;

 L3174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3175;
    }
  goto ret0;

 L3175: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8022 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 227;  /* *lshrsi3_cconly */
    }
  goto ret0;

 L574: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L575;
    }
 L889: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L890;
    }
  goto ret0;

 L575: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L576;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L889;

 L576: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L577;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L889;

 L577: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3467 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xffffffff) != 0x80000000))
    {
      return 64;  /* *addsi_4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L889;

 L890: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L891;
  goto ret0;

 L891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L892;
    }
  goto ret0;

 L892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L893;
  goto ret0;

 L893: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L894;
  goto ret0;

 L894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4142 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)))
    {
      return 85;  /* *subsi_3 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_9 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L497;
    case NEG:
      goto L540;
    case MINUS:
      goto L841;
    case AND:
      goto L1743;
    case IOR:
      goto L2032;
    case XOR:
      goto L2045;
    case NOT:
      goto L2519;
    case ASHIFT:
      goto L2639;
    case ASHIFTRT:
      goto L2900;
    case LSHIFTRT:
      goto L3216;
    case REG:
    case SUBREG:
    case MEM:
      goto L5648;
    default:
      goto ret0;
   }
 L5648: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L589;
    }
  goto ret0;

 L497: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L498;
    }
  goto ret0;

 L498: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L499;
    }
  goto ret0;

 L499: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L500;
  goto ret0;

 L500: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L501;
    case CLOBBER:
      goto L641;
    default:
     break;
   }
  goto ret0;

 L501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L502;
    }
  goto ret0;

 L502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == PLUS)
    goto L503;
  goto ret0;

 L503: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L504;
  goto ret0;

 L504: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 3129 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 59;  /* *addhi_2 */
    }
  goto ret0;

 L641: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L642;
    }
  goto ret0;

 L642: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3651 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 68;  /* *addhi_5 */
    }
  goto ret0;

 L540: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L541;
    }
  goto ret0;

 L541: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L542;
    }
  goto ret0;

 L542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L543;
  goto ret0;

 L543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L544;
    }
  goto ret0;

 L544: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3320 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 62;  /* *addhi_3 */
    }
  goto ret0;

 L841: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L842;
    }
  goto ret0;

 L842: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L843;
    }
  goto ret0;

 L843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L844;
  goto ret0;

 L844: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L845;
  goto ret0;

 L845: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L846;
    }
  goto ret0;

 L846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L847;
  goto ret0;

 L847: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L848;
  goto ret0;

 L848: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4114 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, HImode, recog_data.operand)))
    {
      return 81;  /* *subhi_2 */
    }
  goto ret0;

 L1743: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L1744;
    }
  goto ret0;

 L1744: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L1745;
    }
  goto ret0;

 L1745: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1746;
  goto ret0;

 L1746: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1747;
  goto ret0;

 L1747: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1748;
    }
  goto ret0;

 L1748: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == AND)
    goto L1749;
  goto ret0;

 L1749: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1750;
  goto ret0;

 L1750: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5207 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, HImode, recog_data.operand)))
    {
      return 137;  /* *andhi_2 */
    }
  goto ret0;

 L2032: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2033;
    }
  goto ret0;

 L2033: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L2034;
    }
  goto ret0;

 L2034: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2035;
  goto ret0;

 L2035: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2036;
    case CLOBBER:
      goto L2152;
    default:
     break;
   }
  goto ret0;

 L2036: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2037;
    }
  goto ret0;

 L2037: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == IOR)
    goto L2038;
  goto ret0;

 L2038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2039;
  goto ret0;

 L2039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, recog_data.operand)))
    {
      return 154;  /* *iorhi_2 */
    }
  goto ret0;

 L2152: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2153;
    }
  goto ret0;

 L2153: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, recog_data.operand)))
    {
      return 162;  /* *iorhi_3 */
    }
  goto ret0;

 L2045: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2046;
    }
  goto ret0;

 L2046: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L2047;
    }
  goto ret0;

 L2047: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2048;
  goto ret0;

 L2048: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2049;
    case CLOBBER:
      goto L2170;
    default:
     break;
   }
  goto ret0;

 L2049: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2050;
    }
  goto ret0;

 L2050: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == XOR)
    goto L2051;
  goto ret0;

 L2051: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2052;
  goto ret0;

 L2052: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, recog_data.operand)))
    {
      return 155;  /* *xorhi_2 */
    }
  goto ret0;

 L2170: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2171;
    }
  goto ret0;

 L2171: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, recog_data.operand)))
    {
      return 163;  /* *xorhi_3 */
    }
  goto ret0;

 L2519: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2520;
    }
  goto ret0;

 L2520: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2521;
  goto ret0;

 L2521: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2522;
  goto ret0;

 L2522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2523;
    }
  goto ret0;

 L2523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == NOT)
    goto L2524;
  goto ret0;

 L2524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5852 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, HImode, recog_data.operand)))
    {
      return 184;  /* *one_cmplhi2_2 */
    }
  goto ret0;

 L2639: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2640;
    }
  goto ret0;

 L2640: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2641;
    }
  goto ret0;

 L2641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2642;
  goto ret0;

 L2642: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2643;
    case CLOBBER:
      goto L2656;
    default:
     break;
   }
  goto ret0;

 L2643: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2644;
    }
  goto ret0;

 L2644: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFT)
    goto L2645;
  goto ret0;

 L2645: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2646;
  goto ret0;

 L2646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 6690 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (recog_data.operand[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand)))
    {
      return 192;  /* *ashlhi3_cmp */
    }
  goto ret0;

 L2656: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2657;
    }
  goto ret0;

 L2657: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6740 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, recog_data.operand)))
    {
      return 193;  /* *ashlhi3_cconly */
    }
  goto ret0;

 L2900: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2901;
    }
  goto ret0;

 L2901: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5682;
  goto ret0;

 L5682: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2902;
    }
 L5683: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2933;
    }
  goto ret0;

 L2902: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2903;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2903: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2904;
    case CLOBBER:
      goto L2917;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2904: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2905;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2905: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2906;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2906: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2907;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2907: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7534 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 209;  /* *ashrhi3_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2918;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2918: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7549 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 210;  /* *ashrhi3_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5683;

 L2933: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2934;
  goto ret0;

 L2934: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2935;
    case CLOBBER:
      goto L2948;
    default:
     break;
   }
  goto ret0;

 L2935: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2936;
    }
  goto ret0;

 L2936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2937;
  goto ret0;

 L2937: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2938;
  goto ret0;

 L2938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7568 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 211;  /* *ashrhi3_cmp */
    }
  goto ret0;

 L2948: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2949;
    }
  goto ret0;

 L2949: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7582 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, recog_data.operand)))
    {
      return 212;  /* *ashrhi3_cconly */
    }
  goto ret0;

 L3216: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L3217;
    }
  goto ret0;

 L3217: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5684;
  goto ret0;

 L5684: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3218;
    }
 L5685: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3249;
    }
  goto ret0;

 L3218: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3219;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3219: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3220;
    case CLOBBER:
      goto L3233;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L3221;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3222;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3222: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3223;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3223: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 8087 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 230;  /* *lshrhi3_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L3234;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3234: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8102 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 231;  /* *lshrhi3_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5685;

 L3249: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3250;
  goto ret0;

 L3250: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3251;
    case CLOBBER:
      goto L3264;
    default:
     break;
   }
  goto ret0;

 L3251: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L3252;
    }
  goto ret0;

 L3252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3253;
  goto ret0;

 L3253: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3254;
  goto ret0;

 L3254: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 8121 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 232;  /* *lshrhi3_cmp */
    }
  goto ret0;

 L3264: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L3265;
    }
  goto ret0;

 L3265: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8135 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, recog_data.operand)))
    {
      return 233;  /* *lshrhi3_cconly */
    }
  goto ret0;

 L589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L590;
    }
 L878: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L879;
    }
  goto ret0;

 L590: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L591;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L878;

 L591: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L592;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L878;

 L592: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3512 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xffff) != 0x8000))
    {
      return 65;  /* *addhi_4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L878;

 L879: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L880;
  goto ret0;

 L880: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L881;
    }
  goto ret0;

 L881: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L882;
  goto ret0;

 L882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L883;
  goto ret0;

 L883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4142 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, HImode, recog_data.operand)))
    {
      return 84;  /* *subhi_3 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_10 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L510;
    case NEG:
      goto L557;
    case MINUS:
      goto L828;
    case AND:
      goto L1717;
    case IOR:
      goto L2006;
    case XOR:
      goto L2019;
    case NOT:
      goto L2508;
    case ASHIFT:
      goto L2698;
    case ASHIFTRT:
      goto L3022;
    case LSHIFTRT:
      goto L3338;
    case REG:
    case SUBREG:
    case MEM:
      goto L5649;
    default:
      goto ret0;
   }
 L5649: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L604;
    }
  goto ret0;

 L510: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L511;
    }
  goto ret0;

 L511: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L512;
    }
  goto ret0;

 L512: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L513;
  goto ret0;

 L513: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L514;
    case CLOBBER:
      goto L659;
    default:
     break;
   }
  goto ret0;

 L514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L515;
    }
  goto ret0;

 L515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L516;
  goto ret0;

 L516: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L517;
  goto ret0;

 L517: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 3176 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 60;  /* *addqi_2 */
    }
  goto ret0;

 L659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L660;
    }
  goto ret0;

 L660: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3697 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 69;  /* *addqi_5 */
    }
  goto ret0;

 L557: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L558;
    }
  goto ret0;

 L558: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L559;
    }
  goto ret0;

 L559: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L560;
  goto ret0;

 L560: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L561;
    }
  goto ret0;

 L561: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3365 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCZmode)
   && !(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 63;  /* *addqi_3 */
    }
  goto ret0;

 L828: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L829;
    }
  goto ret0;

 L829: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L830;
    }
  goto ret0;

 L830: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L831;
  goto ret0;

 L831: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L832;
  goto ret0;

 L832: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L833;
    }
  goto ret0;

 L833: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MINUS)
    goto L834;
  goto ret0;

 L834: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L835;
  goto ret0;

 L835: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4114 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, QImode, recog_data.operand)))
    {
      return 80;  /* *subqi_2 */
    }
  goto ret0;

 L1717: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L5686;
  goto ret0;

 L5686: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1718;
    }
 L5687: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[0] = x4;
      goto L1770;
    }
  goto ret0;

 L1718: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1719;
    }
  x4 = XEXP (x3, 0);
  goto L5687;

 L1719: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1720;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1720: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1721;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L1722;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1722: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == AND)
    goto L1723;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1723: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1724;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1724: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5183 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (AND, QImode, recog_data.operand)
   && ix86_match_ccmode (insn,
			 CONST_INT_P (recog_data.operand[2])
			 && INTVAL (recog_data.operand[2]) >= 0 ? CCNOmode : CCZmode)))
    {
      return 135;  /* *andqi_2_maybe_si */
    }
 L1737: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5207 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, QImode, recog_data.operand)))
    {
      return 136;  /* *andqi_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5687;

 L1770: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1771;
    }
  goto ret0;

 L1771: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1772;
  goto ret0;

 L1772: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1773;
  goto ret0;

 L1773: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L1774;
  goto ret0;

 L1774: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L1775;
  goto ret0;

 L1775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == AND)
    goto L1776;
  goto ret0;

 L1776: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L1777;
  goto ret0;

 L1777: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5236 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 139;  /* *andqi_2_slp */
    }
  goto ret0;

 L2006: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L5688;
  goto ret0;

 L5688: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2007;
    }
 L5689: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[0] = x4;
      goto L2085;
    }
  goto ret0;

 L2007: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2008;
    }
  x4 = XEXP (x3, 0);
  goto L5689;

 L2008: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2009;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2009: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2010;
    case CLOBBER:
      goto L2116;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2010: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2011;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == IOR)
    goto L2012;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2012: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2013;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2013: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, recog_data.operand)))
    {
      return 152;  /* *iorqi_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2117;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2117: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, recog_data.operand)))
    {
      return 160;  /* *iorqi_3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5689;

 L2085: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2086;
    }
  goto ret0;

 L2086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2087;
  goto ret0;

 L2087: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2088;
  goto ret0;

 L2088: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L2089;
  goto ret0;

 L2089: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2090;
  goto ret0;

 L2090: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == IOR)
    goto L2091;
  goto ret0;

 L2091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2092;
  goto ret0;

 L2092: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5514 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 158;  /* *iorqi_2_slp */
    }
  goto ret0;

 L2019: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L5690;
  goto ret0;

 L5690: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2020;
    }
 L5691: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[0] = x4;
      goto L2099;
    }
  goto ret0;

 L2020: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2021;
    }
  x4 = XEXP (x3, 0);
  goto L5691;

 L2021: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2022;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2022: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2023;
    case CLOBBER:
      goto L2134;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2023: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2024;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2024: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == XOR)
    goto L2025;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2025: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2026;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2026: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 5472 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, recog_data.operand)))
    {
      return 153;  /* *xorqi_2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2134: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2135;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2135: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 5528 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, recog_data.operand)))
    {
      return 161;  /* *xorqi_3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5691;

 L2099: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2100;
    }
  goto ret0;

 L2100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2101;
  goto ret0;

 L2101: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2102;
  goto ret0;

 L2102: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L2103;
  goto ret0;

 L2103: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2104;
  goto ret0;

 L2104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == XOR)
    goto L2105;
  goto ret0;

 L2105: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2106;
  goto ret0;

 L2106: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5514 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCNOmode)
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 159;  /* *xorqi_2_slp */
    }
  goto ret0;

 L2508: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2509;
    }
  goto ret0;

 L2509: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2510;
  goto ret0;

 L2510: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2511;
  goto ret0;

 L2511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2512;
    }
  goto ret0;

 L2512: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == NOT)
    goto L2513;
  goto ret0;

 L2513: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5852 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, QImode, recog_data.operand)))
    {
      return 183;  /* *one_cmplqi2_2 */
    }
  goto ret0;

 L2698: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2699;
    }
  goto ret0;

 L2699: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L2700;
    }
  goto ret0;

 L2700: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2701;
  goto ret0;

 L2701: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2702;
    case CLOBBER:
      goto L2715;
    default:
     break;
   }
  goto ret0;

 L2702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2703;
    }
  goto ret0;

 L2703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFT)
    goto L2704;
  goto ret0;

 L2704: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L2705;
  goto ret0;

 L2705: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 6929 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || (TARGET_DOUBLE_WITH_ADD && REG_P (recog_data.operand[0])))))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand)))
    {
      return 196;  /* *ashlqi3_cmp */
    }
  goto ret0;

 L2715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2716;
    }
  goto ret0;

 L2716: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 6979 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun)
    || !TARGET_PARTIAL_FLAG_REG_STALL
    || (recog_data.operand[2] == const1_rtx
	&& (TARGET_SHIFT1
	    || TARGET_DOUBLE_WITH_ADD)))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, recog_data.operand)))
    {
      return 197;  /* *ashlqi3_cconly */
    }
  goto ret0;

 L3022: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L3023;
    }
  goto ret0;

 L3023: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5692;
  goto ret0;

 L5692: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3024;
    }
 L5693: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3055;
    }
  goto ret0;

 L3024: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3025;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3025: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3026;
    case CLOBBER:
      goto L3039;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3027;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3027: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L3028;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3028: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3029;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3029: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7657 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 217;  /* *ashrqi3_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3039: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3040;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3040: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7672 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 218;  /* *ashrqi3_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5693;

 L3055: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3056;
  goto ret0;

 L3056: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3057;
    case CLOBBER:
      goto L3070;
    default:
     break;
   }
  goto ret0;

 L3057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3058;
    }
  goto ret0;

 L3058: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L3059;
  goto ret0;

 L3059: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3060;
  goto ret0;

 L3060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 7691 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 219;  /* *ashrqi3_cmp */
    }
  goto ret0;

 L3070: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3071;
    }
  goto ret0;

 L3071: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 7705 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 220;  /* *ashrqi3_cconly */
    }
  goto ret0;

 L3338: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L3339;
    }
  goto ret0;

 L3339: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L5694;
  goto ret0;

 L5694: ATTRIBUTE_UNUSED_LABEL
  if (const1_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3340;
    }
 L5695: ATTRIBUTE_UNUSED_LABEL
  if (const_1_to_31_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L3371;
    }
  goto ret0;

 L3340: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3341;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3341: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3342;
    case CLOBBER:
      goto L3355;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3343;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3344;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3344: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3345;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3345: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 8209 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 238;  /* *lshrqi2_one_bit_cmp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3355: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3356;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3356: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8224 "../../gcc/config/i386/i386.md"
((TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 239;  /* *lshrqi2_one_bit_cconly */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5695;

 L3371: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3372;
  goto ret0;

 L3372: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3373;
    case CLOBBER:
      goto L3386;
    default:
     break;
   }
  goto ret0;

 L3373: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3374;
    }
  goto ret0;

 L3374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3375;
  goto ret0;

 L3375: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L3376;
  goto ret0;

 L3376: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 8243 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 240;  /* *lshrqi2_cmp */
    }
  goto ret0;

 L3386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L3387;
    }
  goto ret0;

 L3387: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 8257 "../../gcc/config/i386/i386.md"
((optimize_function_for_size_p (cfun) || !TARGET_PARTIAL_FLAG_REG_STALL)
   && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, recog_data.operand)))
    {
      return 241;  /* *lshrqi2_cconly */
    }
  goto ret0;

 L604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L605;
    }
 L867: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L868;
    }
  goto ret0;

 L605: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L606;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L867;

 L606: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L607;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L867;

 L607: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 3557 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (recog_data.operand[2]) & 0xff) != 0x80))
    {
      return 66;  /* *addqi_4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L867;

 L868: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L869;
  goto ret0;

 L869: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L870;
    }
  goto ret0;

 L870: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MINUS)
    goto L871;
  goto ret0;

 L871: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L872;
  goto ret0;

 L872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4142 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, QImode, recog_data.operand)))
    {
      return 83;  /* *subqi_3 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_11 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5492;
    case HImode:
      goto L5495;
    case SFmode:
      goto L5496;
    case DImode:
      goto L5497;
    case CCmode:
      goto L5498;
    case QImode:
      goto L5500;
    case CCZmode:
      goto L5504;
    default:
      break;
    }
 L177: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case STRICT_LOW_PART:
      goto L178;
    case REG:
      goto L5505;
    default:
     break;
   }
 L1029: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == CCCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L1030;
  if (GET_CODE (x2) == PC)
    goto L3846;
 L3980: ATTRIBUTE_UNUSED_LABEL
  recog_data.operand[0] = x2;
  goto L3981;
 L4043: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5506;
    case XFmode:
      goto L5507;
    default:
      break;
    }
  goto ret0;

 L5492: ATTRIBUTE_UNUSED_LABEL
  tem = recog_5 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L177;

 L5495: ATTRIBUTE_UNUSED_LABEL
  tem = recog_6 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L177;

 L5496: ATTRIBUTE_UNUSED_LABEL
  if (fp_register_operand (x2, SFmode))
    {
      recog_data.operand[0] = x2;
      goto L233;
    }
  goto L177;

 L233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (fp_register_operand (x2, SFmode))
    {
      recog_data.operand[1] = x2;
      goto L234;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L234: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L235;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[1]))
    goto L236;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L236: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0])
      && 
//#line 2019 "../../gcc/config/i386/i386.md"
(reload_completed || TARGET_80387))
    {
      return 33;  /* *swapsf */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5497: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L319;
    }
 L5503: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L1225;
    }
  goto L177;

 L319: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5590;
  x2 = XEXP (x1, 0);
  goto L5503;

 L5590: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L320;
    case PLUS:
      goto L358;
    case MINUS:
      goto L755;
    case NEG:
      goto L2411;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5503;

 L320: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L321;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L321: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L322;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L322: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 43;  /* zero_extendsidi2_32 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L358: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L359;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L359: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L360;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L360: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L361;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 2572 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, DImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return 48;  /* *adddi3_doubleword */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L755: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L756;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L757;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L757: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L758;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4056 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return 75;  /* *subdi3_doubleword */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L2411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L2412;
    }
  x2 = XEXP (x1, 0);
  goto L5503;

 L2412: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2413;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L2413: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 5733 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, DImode, recog_data.operand)) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return 173;  /* *negdi2_doubleword */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5503;

 L1225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5594;
  x2 = XEXP (x1, 0);
  goto L177;

 L5594: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L1226;
    case ASHIFTRT:
      goto L2728;
    case LSHIFTRT:
      goto L3083;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L177;

 L1226: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5597;
  x2 = XEXP (x1, 0);
  goto L177;

 L5597: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L1227;
    case ZERO_EXTEND:
      goto L1245;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L177;

 L1227: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L1228;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L1228: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L1229;
  x2 = XEXP (x1, 0);
  goto L177;

 L1229: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1230;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L1230: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1231;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L1231: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4415 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return 107;  /* *mulsidi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L1245: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L1246;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L1246: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L1247;
  x2 = XEXP (x1, 0);
  goto L177;

 L1247: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1248;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L1248: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1249;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L1249: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4415 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return 108;  /* *umulsidi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2728: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L2729;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L2729: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L2730;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L2730: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2731;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2731: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 198;  /* *ashrdi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L3083: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L3084;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L3084: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3085;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L3085: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3086;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L3086: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 221;  /* *lshrdi3_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5498: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L371;
  goto L177;

 L371: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 35)
    goto L372;
  x2 = XEXP (x1, 0);
  goto L177;

 L372: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L5599;
    case QImode:
      goto L5600;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L5599: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L373;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L373: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L374;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L374: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L375;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L375: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L376;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L377;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L378;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L378: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 2597 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 49;  /* *addsi3_cc */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5600: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L384;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L384: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L385;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L385: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L386;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L387;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L387: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L388;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L388: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L389;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L389: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 2610 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 50;  /* addqi3_cc */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5500: ATTRIBUTE_UNUSED_LABEL
  tem = recog_7 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L177;

 L5504: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L2458;
  goto L177;

 L2458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCZmode
      && GET_CODE (x2) == COMPARE)
    goto L2459;
  x2 = XEXP (x1, 0);
  goto L177;

 L2459: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L5627;
    case HImode:
      goto L5628;
    case SImode:
      goto L5629;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L5627: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L2460;
  x2 = XEXP (x1, 0);
  goto L177;

 L2460: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L2461;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L2461: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2462;
  x2 = XEXP (x1, 0);
  goto L177;

 L2462: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2463;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2463: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L2464;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2464: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == NEG)
    goto L2465;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2465: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5785 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, QImode, recog_data.operand)))
    {
      return 177;  /* *negqi2_cmpz */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5628: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L2471;
  x2 = XEXP (x1, 0);
  goto L177;

 L2471: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L2472;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L2472: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2473;
  x2 = XEXP (x1, 0);
  goto L177;

 L2473: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2474;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L2475;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == NEG)
    goto L2476;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2476: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5785 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, HImode, recog_data.operand)))
    {
      return 178;  /* *neghi2_cmpz */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L5629: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L2482;
  x2 = XEXP (x1, 0);
  goto L177;

 L2482: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L2483;
    }
  x2 = XEXP (x1, 0);
  goto L177;

 L2483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2484;
  x2 = XEXP (x1, 0);
  goto L177;

 L2484: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2485;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L2486;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NEG)
    goto L2487;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L2487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 5785 "../../gcc/config/i386/i386.md"
(ix86_unary_operator_ok (NEG, SImode, recog_data.operand)))
    {
      return 179;  /* *negsi2_cmpz */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L177;

 L178: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode)
    goto L5630;
  goto L3980;

 L5630: ATTRIBUTE_UNUSED_LABEL
  if (q_regs_operand (x3, QImode))
    {
      recog_data.operand[0] = x3;
      goto L179;
    }
 L5631: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[0] = x3;
      goto L467;
    }
  goto L3980;

 L179: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L180;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5631;

 L180: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L181;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5631;

 L181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 1322 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 24;  /* *movstrictqi_xor */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5631;

 L467: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L5632;
  x2 = XEXP (x1, 0);
  goto L3980;

 L5632: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L468;
    case MINUS:
      goto L812;
    case AND:
      goto L1701;
    case IOR:
      goto L1974;
    case XOR:
      goto L1990;
    case ASHIFTRT:
      goto L2976;
    case LSHIFTRT:
      goto L3292;
    case ROTATE:
      goto L3472;
    case ROTATERT:
      goto L3618;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L468: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L469;
  x2 = XEXP (x1, 0);
  goto L3980;

 L469: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L470;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L470: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L471;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L471: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2977 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 57;  /* *addqi_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L812: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L813;
  x2 = XEXP (x1, 0);
  goto L3980;

 L813: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L814;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L814: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L815;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L815: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4099 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 79;  /* *subqi_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1701: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L1702;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1702: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1703;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1703: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1704;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5111 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 134;  /* *andqi_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1974: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L1975;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1975: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1976;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1976: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1977;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1977: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5458 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 150;  /* *iorqi_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1990: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L1991;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L1992;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1992: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1993;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1993: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5458 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 151;  /* *xorqi_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L2976: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L2977;
  x2 = XEXP (x1, 0);
  goto L3980;

 L2977: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L2978;
    }
 L3007: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3008;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L2978: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2979;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3007;

 L2979: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7613 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))
   && ix86_binary_operator_ok (ASHIFTRT, QImode, recog_data.operand)))
    {
      return 214;  /* *ashrqi3_1_one_bit_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3007;

 L3008: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3009;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3009: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7638 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 216;  /* *ashrqi3_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3292: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L3293;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3294;
    }
 L3323: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3324;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3294: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3295;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3323;

 L3295: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8166 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))))
    {
      return 235;  /* *lshrqi3_1_one_bit_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3323;

 L3324: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3325;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3325: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8190 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 237;  /* *lshrqi3_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3472: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L3473;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3474;
    }
 L3503: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3504;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3474: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3475;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3503;

 L3475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8445 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))))
    {
      return 247;  /* *rotlqi3_1_one_bit_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3503;

 L3504: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3505;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3505: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8469 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 249;  /* *rotlqi3_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3618: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L3619;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3619: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const1_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3620;
    }
 L3649: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L3650;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3620: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3621;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3649;

 L3621: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8680 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && (TARGET_SHIFT1 || optimize_function_for_size_p (cfun))))
    {
      return 257;  /* *rotrqi3_1_one_bit_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3649;

 L3650: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3651;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8704 "../../gcc/config/i386/i386.md"
((! TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && !(MEM_P (recog_data.operand[0]) && MEM_P (recog_data.operand[1]))))
    {
      return 259;  /* *rotrqi3_1_slp */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L5505: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L482;
  goto L1029;

 L482: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == COMPARE)
    goto L483;
  x2 = XEXP (x1, 0);
  goto L1029;

 L483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L5641;
    case HImode:
      goto L5642;
    case QImode:
      goto L5643;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L1029;

 L5641: ATTRIBUTE_UNUSED_LABEL
  tem = recog_8 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L1029;

 L5642: ATTRIBUTE_UNUSED_LABEL
  tem = recog_9 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L1029;

 L5643: ATTRIBUTE_UNUSED_LABEL
  tem = recog_10 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L1029;

 L1030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCCmode
      && GET_CODE (x2) == COMPARE)
    goto L1031;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1031: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L5696;
    case HImode:
      goto L5697;
    case SImode:
      goto L5698;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L5696: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1032;
    case MINUS:
      goto L1120;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1032: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1033;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1033: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1034;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1034: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1035;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1035: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1036;
    case SET:
      goto L1111;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1036: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L1037;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1037: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 92;  /* *addqi3_cconly_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L1112;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1112: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L1113;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1113: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1114;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1114: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, QImode, recog_data.operand)))
    {
      return 98;  /* *addqi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1120: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[1] = x4;
      goto L1121;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1121: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      recog_data.operand[2] = x4;
      goto L1122;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1122: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1123;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1123: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1124;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1124: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L1125;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1125: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MINUS)
    goto L1126;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1126: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1127;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1127: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, QImode, recog_data.operand)))
    {
      return 99;  /* *subqi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L5697: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1050;
    case MINUS:
      goto L1146;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1050: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L1051;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1051: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L1052;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1052: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1053;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1053: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1054;
    case SET:
      goto L1137;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1054: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1055;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1055: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 93;  /* *addhi3_cconly_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1138;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1138: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == PLUS)
    goto L1139;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1140;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1140: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, HImode, recog_data.operand)))
    {
      return 100;  /* *addhi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1146: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[1] = x4;
      goto L1147;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1147: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      recog_data.operand[2] = x4;
      goto L1148;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1148: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1149;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1149: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1150;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1150: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1151;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L1152;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1153;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1153: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, HImode, recog_data.operand)))
    {
      return 101;  /* *subhi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L5698: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1068;
    case MINUS:
      goto L1172;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1068: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L1069;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1069: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1070;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1071;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1071: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1072;
    case SET:
      goto L1163;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1073;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1073: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 4232 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 94;  /* *addsi3_cconly_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1164;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1164: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1165;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1165: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1166;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1166: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (PLUS, SImode, recog_data.operand)))
    {
      return 102;  /* *addsi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1172: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L1173;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1173: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L1174;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L1174: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1175;
  x2 = XEXP (x1, 0);
  goto L3980;

 L1175: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1177;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L1178;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1178: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L1179;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L1179: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[2])
      && 
//#line 4258 "../../gcc/config/i386/i386.md"
(ix86_binary_operator_ok (MINUS, SImode, recog_data.operand)))
    {
      return 103;  /* *subsi3_cc_overflow */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3847;
    }
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L3718;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3847: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L3848;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3849;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3849: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[1] = x3;
  return 273;  /* *tablejump_1 */

 L3718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (bt_comparison_operator (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L3719;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3719: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5702;
  x2 = XEXP (x1, 0);
  goto L3980;

 L5702: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTRACT:
      goto L3720;
    case AND:
      goto L3778;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3720: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      recog_data.operand[1] = x5;
      goto L3721;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3721: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3722;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3722: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (GET_MODE (x5) == SImode)
    goto L5704;
  x2 = XEXP (x1, 0);
  goto L3980;

 L5704: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ZERO_EXTEND:
      goto L3723;
    case AND:
      goto L3752;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3723: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, QImode))
    {
      recog_data.operand[2] = x6;
      goto L3724;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3724: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3725;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3725: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L3726;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3726: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[3] = x4;
  goto L3727;

 L3727: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L3728;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3728: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3729;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3729: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 9258 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)))
    {
      return 267;  /* *jcc_btsi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3752: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      recog_data.operand[2] = x6;
      goto L3753;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3753: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      recog_data.operand[3] = x6;
      goto L3754;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3754: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L3755;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3755: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[4] = x4;
  goto L3756;

 L3756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L3757;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3757: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3758;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 9291 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f))
    {
      return 268;  /* *jcc_btsi_mask */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3778: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == LSHIFTRT)
    goto L3779;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3779: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      recog_data.operand[1] = x6;
      goto L3780;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3780: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == QImode)
    goto L5706;
  x2 = XEXP (x1, 0);
  goto L3980;

 L5706: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x6, QImode))
    {
      recog_data.operand[2] = x6;
      goto L3781;
    }
 L5707: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x6) == SUBREG
      && XINT (x6, 1) == 0)
    goto L3810;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3781: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3782;
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3782: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3783;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L3784;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3784: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[3] = x4;
  goto L3785;

 L3785: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L3786;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3786: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3787;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 9320 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)))
    {
      return 269;  /* *jcc_btsi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5707;

 L3810: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (GET_MODE (x7) == SImode
      && GET_CODE (x7) == AND)
    goto L3811;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3811: ATTRIBUTE_UNUSED_LABEL
  x8 = XEXP (x7, 0);
  if (register_operand (x8, SImode))
    {
      recog_data.operand[2] = x8;
      goto L3812;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3812: ATTRIBUTE_UNUSED_LABEL
  x8 = XEXP (x7, 1);
  if (const_int_operand (x8, SImode))
    {
      recog_data.operand[3] = x8;
      goto L3813;
    }
  x2 = XEXP (x1, 0);
  goto L3980;

 L3813: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L3814;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3814: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L3815;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3815: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L3816;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3816: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[4] = x4;
  goto L3817;

 L3817: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L3818;
  x2 = XEXP (x1, 0);
  goto L3980;

 L3818: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3819;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3819: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 9357 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f))
    {
      return 270;  /* *jcc_btsi_mask_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L3980;

 L3981: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L3982;
  x2 = XEXP (x1, 0);
  goto L4043;

 L3982: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MEM)
    goto L3983;
  x2 = XEXP (x1, 0);
  goto L4043;

 L3983: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5708;
  x2 = XEXP (x1, 0);
  goto L4043;

 L5708: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L3984;
    }
 L5709: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L3996;
    }
 L5710: ATTRIBUTE_UNUSED_LABEL
  if (sibcall_insn_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L4009;
    }
  x2 = XEXP (x1, 0);
  goto L4043;

 L3984: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  recog_data.operand[2] = x3;
  goto L3985;

 L3985: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3986;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5709;

 L3986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L3987;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5709;

 L3987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3988;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5709;

 L3988: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L3989;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5709;

 L3989: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      return 295;  /* *call_value_pop_0 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5709;

 L3996: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  recog_data.operand[2] = x3;
  goto L3997;

 L3997: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3998;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L3998: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L3999;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L3999: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4000;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L4000: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L4001;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L4001: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4002;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L4002: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 11065 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn)))
    {
      return 296;  /* *call_value_pop_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5710;

 L4009: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  recog_data.operand[2] = x3;
  goto L4010;

 L4010: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4011;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L4011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4012;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L4012: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4013;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L4013: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L4014;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L4014: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4015;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L4015: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 11080 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn)))
    {
      return 297;  /* *sibcall_value_pop_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4043;

 L5506: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4044;
    }
  goto ret0;

 L4044: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 1)
    goto L4045;
  goto ret0;

 L4045: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4046;
    }
  goto ret0;

 L4046: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4047;
  goto ret0;

 L4047: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4048;
  goto ret0;

 L4048: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L4049;
  goto ret0;

 L4049: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L4050;
  goto ret0;

 L4050: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 11136 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_STACK_PROBE)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 300;  /* allocate_stack_worker_32 */
    }
  goto ret0;

 L5507: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      recog_data.operand[0] = x2;
      goto L4054;
    }
  goto ret0;

 L4054: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      recog_data.operand[1] = x2;
      goto L4055;
    }
  goto ret0;

 L4055: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4056;
  goto ret0;

 L4056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[1]))
    goto L4057;
  goto ret0;

 L4057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, recog_data.operand[0])
      && 
//#line 11146 "../../gcc/config/i386/i386.md"
(TARGET_80387))
    {
      return 301;  /* swapxf */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_12 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case REG:
      goto L5724;
    case MEM:
      goto L4068;
    default:
     break;
   }
 L5715: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L112;
    }
 L5717: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1297;
    }
  goto ret0;

 L5724: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 7)
    goto L3957;
  goto L5715;

 L3957: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3958;
  x2 = XEXP (x1, 0);
  goto L5715;

 L3958: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L3959;
  x2 = XEXP (x1, 0);
  goto L5715;

 L3959: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (4)])
    goto L3960;
  x2 = XEXP (x1, 0);
  goto L5715;

 L3960: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3961;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L3962;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3962: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3963;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3963: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L3964;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3964: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3965;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L3966;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L3966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    {
      return 293;  /* leave */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4068: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4069;
    }
  goto L5715;

 L4069: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4070;
  x2 = XEXP (x1, 0);
  goto L5715;

 L4070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4071;
    }
  x2 = XEXP (x1, 0);
  goto L5715;

 L4071: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4072;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4073;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4073: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4074;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4074: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4075;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4075: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (4)])
    goto L4076;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4076: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4077;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4077: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4078;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4079;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4080;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L4080: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (4)])
    {
      return 303;  /* *strmovsi_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5715;

 L112: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L113;
  x2 = XEXP (x1, 0);
  goto L5717;

 L113: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L114;
  x2 = XEXP (x1, 0);
  goto L5717;

 L114: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L115;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L115: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L116;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L117;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L117: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L118;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (4)])
    goto L119;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L119: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L120;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L120: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L121;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L121: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    {
      return 15;  /* *popsi1_epilogue */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5717;

 L1297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5725;
  goto ret0;

 L5725: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case TRUNCATE:
      goto L1298;
    case DIV:
      goto L1400;
    case UDIV:
      goto L1506;
    case PLUS:
      goto L3971;
    case UNSPEC_VOLATILE:
      goto L5730;
    default:
     break;
   }
  goto ret0;

 L1298: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L1299;
  goto ret0;

 L1299: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L1300;
  goto ret0;

 L1300: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L5731;
  goto ret0;

 L5731: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L1301;
    case ZERO_EXTEND:
      goto L1326;
    default:
     break;
   }
  goto ret0;

 L1301: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      recog_data.operand[1] = x6;
      goto L1302;
    }
  goto ret0;

 L1302: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L1303;
  goto ret0;

 L1303: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      recog_data.operand[2] = x6;
      goto L1304;
    }
  goto ret0;

 L1304: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L1305;
  goto ret0;

 L1305: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1306;
  goto ret0;

 L1306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L1307;
    }
  goto ret0;

 L1307: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1308;
  goto ret0;

 L1308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4482 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 111;  /* *smulsi3_highpart_1 */
    }
  goto ret0;

 L1326: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      recog_data.operand[1] = x6;
      goto L1327;
    }
  goto ret0;

 L1327: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L1328;
  goto ret0;

 L1328: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      recog_data.operand[2] = x6;
      goto L1329;
    }
  goto ret0;

 L1329: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L1330;
  goto ret0;

 L1330: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1331;
  goto ret0;

 L1331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L1332;
    }
  goto ret0;

 L1332: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1333;
  goto ret0;

 L1333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4482 "../../gcc/config/i386/i386.md"
(!(MEM_P (recog_data.operand[1]) && MEM_P (recog_data.operand[2]))))
    {
      return 112;  /* *umulsi3_highpart_1 */
    }
  goto ret0;

 L1400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1401;
    }
  goto ret0;

 L1401: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1402;
    }
  goto ret0;

 L1402: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1403;
  goto ret0;

 L1403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1404;
    }
  goto ret0;

 L1404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L1405;
  goto ret0;

 L1405: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1406;
  goto ret0;

 L1406: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1407;
  goto ret0;

 L1407: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1408;
    case USE:
      goto L1476;
    default:
     break;
   }
  goto ret0;

 L1408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 116;  /* *divmodsi4 */
    }
  goto ret0;

 L1476: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[4] = x2;
      goto L1477;
    }
  goto ret0;

 L1477: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 118;  /* *divmodsi4_noext */
    }
  goto ret0;

 L1506: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1507;
    }
  goto ret0;

 L1507: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1508;
    }
  goto ret0;

 L1508: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1509;
  goto ret0;

 L1509: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1510;
    }
  goto ret0;

 L1510: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L1511;
  goto ret0;

 L1511: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1512;
  goto ret0;

 L1512: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1513;
  goto ret0;

 L1513: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1514;
    case USE:
      goto L1582;
    default:
     break;
   }
  goto ret0;

 L1514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 120;  /* *udivmodsi4 */
    }
  goto ret0;

 L1582: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[4] = x2;
      goto L1583;
    }
  goto ret0;

 L1583: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 122;  /* *udivmodsi4_noext */
    }
  goto ret0;

 L3971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L3972;
    }
  goto ret0;

 L3972: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L3973;
    }
  goto ret0;

 L3973: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3974;
  goto ret0;

 L3974: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3975;
  goto ret0;

 L3975: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3976;
  goto ret0;

 L3976: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L3977;
  goto ret0;

 L3977: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    {
      return 294;  /* pro_epilogue_adjust_stack_1 */
    }
  goto ret0;

 L5730: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 1)
    goto L4033;
  goto ret0;

 L4033: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4034;
    }
  goto ret0;

 L4034: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4035;
  goto ret0;

 L4035: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4036;
  goto ret0;

 L4036: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L4037;
  goto ret0;

 L4037: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L4038;
  goto ret0;

 L4038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[1]))
    goto L4039;
  goto ret0;

 L4039: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4040;
  goto ret0;

 L4040: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 11136 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_STACK_PROBE))
    {
      return 300;  /* allocate_stack_worker_32 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_13 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L103;
    case 3:
      goto L110;
    case 4:
      goto L1421;
    default:
      break;
    }
  goto ret0;

 L103: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L104;
    case CALL:
      goto L3852;
    case RETURN:
      goto L3907;
    default:
     break;
   }
  goto ret0;

 L104: ATTRIBUTE_UNUSED_LABEL
  return recog_11 (x0, insn, pnum_clobbers);

 L3852: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MEM)
    goto L3853;
  goto ret0;

 L3853: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5711;
  goto ret0;

 L5711: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L3854;
    }
 L5712: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L3864;
    }
 L5713: ATTRIBUTE_UNUSED_LABEL
  if (sibcall_insn_operand (x3, SImode))
    {
      recog_data.operand[0] = x3;
      goto L3875;
    }
  goto ret0;

 L3854: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[1] = x2;
  goto L3855;

 L3855: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3856;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5712;

 L3856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L3857;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5712;

 L3857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3858;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5712;

 L3858: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L3859;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5712;

 L3859: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      return 274;  /* *call_pop_0 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5712;

 L3864: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[1] = x2;
  goto L3865;

 L3865: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3866;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3866: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L3867;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3867: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3868;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3868: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L3869;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3869: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L3870;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3870: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9539 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn)))
    {
      return 275;  /* *call_pop_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5713;

 L3875: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  recog_data.operand[1] = x2;
  goto L3876;

 L3876: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3877;
  goto ret0;

 L3877: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L3878;
  goto ret0;

 L3878: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3879;
  goto ret0;

 L3879: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L3880;
  goto ret0;

 L3880: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L3881;
    }
  goto ret0;

 L3881: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9553 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn)))
    {
      return 276;  /* *sibcall_pop_1 */
    }
  goto ret0;

 L3907: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L5714;
    case USE:
      goto L3917;
    default:
     break;
   }
  goto ret0;

 L5714: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 37)
    goto L3908;
  goto ret0;

 L3908: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 9776 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 284;  /* return_internal_long */
    }
  goto ret0;

 L3917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3918;
    }
  if (const_int_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3913;
    }
  goto ret0;

 L3918: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9795 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 286;  /* return_indirect_internal */
    }
  goto ret0;

 L3913: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9786 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 285;  /* return_pop_internal */
    }
  goto ret0;

 L110: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L111;
  goto ret0;

 L111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5720;
    case DImode:
      goto L5716;
    case HImode:
      goto L5722;
    case QImode:
      goto L5723;
    default:
      break;
    }
  goto ret0;

 L5720: ATTRIBUTE_UNUSED_LABEL
  return recog_12 (x0, insn, pnum_clobbers);

 L5716: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L331;
    }
 L5719: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L3398;
    }
  goto ret0;

 L331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L332;
  x2 = XEXP (x1, 0);
  goto L5719;

 L332: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L333;
    }
  x2 = XEXP (x1, 0);
  goto L5719;

 L333: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L334;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5719;

 L334: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L335;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5719;

 L335: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L336;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5719;

 L336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      return 44;  /* *extendsidi2_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5719;

 L3398: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5733;
  goto ret0;

 L5733: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ROTATE:
      goto L3399;
    case ROTATERT:
      goto L3531;
    default:
     break;
   }
  goto ret0;

 L3399: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L3400;
    }
  goto ret0;

 L3400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3401;
    }
  goto ret0;

 L3401: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3402;
  goto ret0;

 L3402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3403;
  goto ret0;

 L3403: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3404;
  goto ret0;

 L3404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      return 242;  /* ix86_rotldi3 */
    }
  goto ret0;

 L3531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L3532;
    }
  goto ret0;

 L3532: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L3533;
    }
  goto ret0;

 L3533: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3534;
  goto ret0;

 L3534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L3535;
  goto ret0;

 L3535: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3536;
  goto ret0;

 L3536: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      return 251;  /* ix86_rotrdi3 */
    }
  goto ret0;

 L5722: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4084;
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1375;
    }
  goto ret0;

 L4084: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4085;
    }
  goto ret0;

 L4085: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MEM)
    goto L4086;
  goto ret0;

 L4086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4087;
    }
  goto ret0;

 L4087: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4088;
  goto ret0;

 L4088: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4089;
    }
  goto ret0;

 L4089: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4090;
  goto ret0;

 L4090: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4091;
  goto ret0;

 L4091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (2)])
    goto L4092;
  goto ret0;

 L4092: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4093;
  goto ret0;

 L4093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4094;
    }
  goto ret0;

 L4094: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4095;
  goto ret0;

 L4095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4096;
  goto ret0;

 L4096: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (2)])
    {
      return 304;  /* *strmovhi_1 */
    }
  goto ret0;

 L1375: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5735;
  goto ret0;

 L5735: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L1376;
    case UDIV:
      goto L1482;
    default:
     break;
   }
  goto ret0;

 L1376: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1377;
    }
  goto ret0;

 L1377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1378;
    }
  goto ret0;

 L1378: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1379;
  goto ret0;

 L1379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1380;
    }
  goto ret0;

 L1380: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L1381;
  goto ret0;

 L1381: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1382;
  goto ret0;

 L1382: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1383;
  goto ret0;

 L1383: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1384;
    case USE:
      goto L1447;
    default:
     break;
   }
  goto ret0;

 L1384: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    {
      return 115;  /* *divmodhi4 */
    }
  goto ret0;

 L1447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[4] = x2;
      goto L1448;
    }
  goto ret0;

 L1448: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 117;  /* *divmodhi4_noext */
    }
  goto ret0;

 L1482: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1483;
    }
  goto ret0;

 L1483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1484;
    }
  goto ret0;

 L1484: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1485;
  goto ret0;

 L1485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1486;
    }
  goto ret0;

 L1486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == UMOD)
    goto L1487;
  goto ret0;

 L1487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1488;
  goto ret0;

 L1488: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1489;
  goto ret0;

 L1489: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1490;
    case USE:
      goto L1553;
    default:
     break;
   }
  goto ret0;

 L1490: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    {
      return 119;  /* *udivmodhi4 */
    }
  goto ret0;

 L1553: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[4] = x2;
      goto L1554;
    }
  goto ret0;

 L1554: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 121;  /* *udivmodhi4_noext */
    }
  goto ret0;

 L5723: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4100;
  goto ret0;

 L4100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4101;
    }
  goto ret0;

 L4101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MEM)
    goto L4102;
  goto ret0;

 L4102: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4103;
    }
  goto ret0;

 L4103: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4104;
  goto ret0;

 L4104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4105;
    }
  goto ret0;

 L4105: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4106;
  goto ret0;

 L4106: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4107;
  goto ret0;

 L4107: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L4108;
  goto ret0;

 L4108: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4109;
  goto ret0;

 L4109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4110;
    }
  goto ret0;

 L4110: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4111;
  goto ret0;

 L4111: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4112;
  goto ret0;

 L4112: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    {
      return 305;  /* *strmovqi_1 */
    }
  goto ret0;

 L1421: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L1422;
  goto ret0;

 L1422: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L5737;
    case SImode:
      goto L5738;
    default:
      break;
    }
  goto ret0;

 L5737: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L1423;
    }
  goto ret0;

 L1423: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5739;
  goto ret0;

 L5739: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L1424;
    case UDIV:
      goto L1530;
    default:
     break;
   }
  goto ret0;

 L1424: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1425;
    }
  goto ret0;

 L1425: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1426;
    }
  goto ret0;

 L1426: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1427;
  goto ret0;

 L1427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1428;
    }
  goto ret0;

 L1428: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L1429;
  goto ret0;

 L1429: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1430;
  goto ret0;

 L1430: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1431;
  goto ret0;

 L1431: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1432;
  goto ret0;

 L1432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[4] = x2;
      goto L1433;
    }
  goto ret0;

 L1433: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L1434;
  goto ret0;

 L1434: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    {
      return 117;  /* *divmodhi4_noext */
    }
  goto ret0;

 L1530: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L1531;
    }
  goto ret0;

 L1531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L1532;
    }
  goto ret0;

 L1532: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1533;
  goto ret0;

 L1533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L1534;
    }
  goto ret0;

 L1534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == UMOD)
    goto L1535;
  goto ret0;

 L1535: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1536;
  goto ret0;

 L1536: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1537;
  goto ret0;

 L1537: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1538;
  goto ret0;

 L1538: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[4] = x2;
      goto L1539;
    }
  goto ret0;

 L1539: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L1540;
  goto ret0;

 L1540: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH))
    {
      return 121;  /* *udivmodhi4_noext */
    }
  goto ret0;

 L5738: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L1452;
    }
  goto ret0;

 L1452: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5741;
  goto ret0;

 L5741: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L1453;
    case UDIV:
      goto L1559;
    default:
     break;
   }
  goto ret0;

 L1453: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1454;
    }
  goto ret0;

 L1454: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1455;
    }
  goto ret0;

 L1455: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1456;
  goto ret0;

 L1456: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1457;
    }
  goto ret0;

 L1457: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L1458;
  goto ret0;

 L1458: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1459;
  goto ret0;

 L1459: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1460;
  goto ret0;

 L1460: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1461;
  goto ret0;

 L1461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[4] = x2;
      goto L1462;
    }
  goto ret0;

 L1462: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L1463;
  goto ret0;

 L1463: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 118;  /* *divmodsi4_noext */
    }
  goto ret0;

 L1559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L1560;
    }
  goto ret0;

 L1560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L1561;
    }
  goto ret0;

 L1561: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1562;
  goto ret0;

 L1562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L1563;
    }
  goto ret0;

 L1563: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L1564;
  goto ret0;

 L1564: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L1565;
  goto ret0;

 L1565: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L1566;
  goto ret0;

 L1566: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1567;
  goto ret0;

 L1567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[4] = x2;
      goto L1568;
    }
  goto ret0;

 L1568: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L1569;
  goto ret0;

 L1569: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 122;  /* *udivmodsi4_noext */
    }
  goto ret0;
 ret0:
  return -1;
}
#endif

int
recog (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;
  //recog_data.insn = 0;
	
  switch (GET_CODE (x0))
    {
    case SET:
      goto L100;
		default:
			goto ret0;
		/*
    case PARALLEL:
      goto L5291;
    case CALL:
      goto L3883;
    case UNSPEC_VOLATILE:
      goto L5294;
    case RETURN:
      goto L5296;
    case CONST_INT:
      goto L5297;
    case EH_RETURN:
      goto L5299;
    default:
			break;*/
   }
  goto ret0;

 L100: ATTRIBUTE_UNUSED_LABEL
  return recog_3 (x0, insn, pnum_clobbers);

#if 0
 L5291: ATTRIBUTE_UNUSED_LABEL
  return recog_13 (x0, insn, pnum_clobbers);

 L3883: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == MEM)
    goto L3884;
  goto ret0;

 L3884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (constant_call_address_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L3885;
    }
 L3888: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == SImode)
    goto L5743;
  goto ret0;

 L3885: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  recog_data.operand[1] = x1;
  return 277;  /* *call_0 */

 L5743: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3889;
    }
 L5744: ATTRIBUTE_UNUSED_LABEL
  if (sibcall_insn_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L3894;
    }
  goto ret0;

 L3889: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  recog_data.operand[1] = x1;
  goto L3890;

 L3890: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9594 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && !SIBLING_CALL_P (insn)))
    {
      return 278;  /* *call_1 */
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L5744;

 L3894: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  recog_data.operand[1] = x1;
  goto L3895;

 L3895: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9605 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && SIBLING_CALL_P (insn)))
    {
      return 279;  /* *sibcall_1 */
    }
  goto ret0;

 L5294: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 1)
    goto L5745;
  goto ret0;

 L5745: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 0L:
      goto L3897;
    case 14L:
      goto L3903;
    case 7L:
      goto L3927;
    default:
      break;
    }
  goto ret0;

 L3897: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 280;  /* blockage */
    }
  goto ret0;

 L3903: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  recog_data.operand[0] = x1;
  return 282;  /* prologue_use */

 L3927: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  recog_data.operand[0] = x1;
  return 289;  /* pad */

 L5296: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9764 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return 283;  /* return_internal */
    }
  goto ret0;

 L5297: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x0, 0) == 0L)
    {
      return 287;  /* nop */
    }
  goto ret0;

 L5299: ATTRIBUTE_UNUSED_LABEL
  return 292;  /* eh_return_internal */
#endif
 ret0:
  return -1;
}

#if 0

static rtx
split_1 (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DImode:
      goto L5751;
    case TImode:
      goto L5753;
    case SFmode:
      goto L5754;
    case SImode:
      goto L5755;
    case QImode:
      goto L5756;
    default:
      break;
    }
 L4328: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case REG:
      goto L5757;
    case STRICT_LOW_PART:
      goto L4600;
    case PC:
      goto L4623;
    default:
     break;
   }
 L4234: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L4235;
    }
  goto ret0;

 L5751: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L4115;
    }
 L5752: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L4119;
    }
  goto L4328;

 L4115: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, DImode))
    {
      recog_data.operand[1] = x1;
      goto L4116;
    }
  x1 = XEXP (x0, 0);
  goto L5752;

 L4116: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1653 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && (! MMX_REG_P (recog_data.operand[1]) && !SSE_REG_P (recog_data.operand[1]))))
    {
      return gen_split_321 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L5752;

 L4119: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, DImode))
    {
      recog_data.operand[1] = x1;
      goto L4120;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4120: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1662 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && (!MMX_REG_P (recog_data.operand[0]) && !SSE_REG_P (recog_data.operand[0]))
   && (!MMX_REG_P (recog_data.operand[1]) && !SSE_REG_P (recog_data.operand[1]))))
    {
      return gen_split_322 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L5753: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TImode))
    {
      recog_data.operand[0] = x1;
      goto L4123;
    }
  goto L4328;

 L4123: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, TImode))
    {
      recog_data.operand[1] = x1;
      goto L4124;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4124: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1847 "../../gcc/config/i386/i386.md"
(reload_completed && !SSE_REG_P (recog_data.operand[0])
   && !SSE_REG_P (recog_data.operand[1])))
    {
      return gen_split_324 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L5754: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SFmode))
    {
      recog_data.operand[0] = x1;
      goto L4127;
    }
  goto L4328;

 L4127: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L5759;
  x1 = XEXP (x0, 0);
  goto L4328;

 L5759: ATTRIBUTE_UNUSED_LABEL
  if (any_fp_register_operand (x1, SFmode))
    {
      recog_data.operand[1] = x1;
      return gen_split_327 (insn, recog_data.operand);
    }
  if (memory_operand (x1, SFmode))
    {
      recog_data.operand[1] = x1;
      goto L4128;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4128: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 1897 "../../gcc/config/i386/i386.md"
(reload_completed
   && MEM_P (recog_data.operand[1])
   && (recog_data.operand[2] = find_constant_src (insn))))
    {
      return gen_split_326 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L5755: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4588;
    }
  goto L4328;

 L4588: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (ix86_comparison_operator (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L4589;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4590;
  x1 = XEXP (x0, 0);
  goto L4328;

 L4590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && (
//#line 8988 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))) && 
//#line 8991 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_460 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L5756: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L4593;
    }
  goto L4328;

 L4593: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L5760;
  x1 = XEXP (x0, 0);
  goto L4328;

 L5760: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NE:
      goto L4594;
    case EQ:
      goto L4609;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4594: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4595;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4595: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4596;
  x1 = XEXP (x0, 0);
  goto L4328;

 L4596: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4597;
  x1 = XEXP (x0, 0);
  goto L4328;

 L4597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return gen_split_461 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4610;
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L4610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4611;
  x1 = XEXP (x0, 0);
  goto L4328;

 L4611: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4612;
  x1 = XEXP (x0, 0);
  goto L4328;

 L4612: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return gen_split_463 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4328;

 L5757: ATTRIBUTE_UNUSED_LABEL
  if (flags_reg_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L4329;
    }
  goto L4234;

 L4329: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (compare_operator (x1, VOIDmode))
    {
      recog_data.operand[1] = x1;
      goto L4330;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4330: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case ZERO_EXTRACT:
      goto L4331;
    case AND:
      goto L4339;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4331: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4332;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4332: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4333;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4333: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[4] = x3;
      goto L4334;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4334: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4854 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return gen_split_386 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4339: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4340;
    }
 L4346: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4347;
    }
 L4765: ATTRIBUTE_UNUSED_LABEL
  if (aligned_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L4766;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4340: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4341;
    }
  x3 = XEXP (x2, 0);
  goto L4346;

 L4341: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4911 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (recog_data.operand[2])
    && GET_MODE (recog_data.operand[2]) != QImode
    && ((ix86_match_ccmode (insn, CCZmode)
    	 && !(INTVAL (recog_data.operand[3]) & ~(255 << 8)))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (recog_data.operand[3]) & ~(127 << 8))))))
    {
      return gen_split_387 (insn, recog_data.operand);
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L4346;

 L4347: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4348;
    }
  x3 = XEXP (x2, 0);
  goto L4765;

 L4348: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 4932 "../../gcc/config/i386/i386.md"
(reload_completed
    && GET_MODE (recog_data.operand[2]) != QImode
    && (!REG_P (recog_data.operand[2]) || ANY_QI_REG_P (recog_data.operand[2]))
    && ((ix86_match_ccmode (insn, CCZmode)
	 && !(INTVAL (recog_data.operand[3]) & ~255))
	|| (ix86_match_ccmode (insn, CCNOmode)
	    && !(INTVAL (recog_data.operand[3]) & ~127)))))
    {
      return gen_split_388 (insn, recog_data.operand);
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L4765;

 L4766: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L4767;
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4767: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10072 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ! TARGET_FAST_PREFIX
   && optimize_insn_for_speed_p ()
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (recog_data.operand[3]) >= 0 ? CCNOmode : CCZmode)))
    {
      return gen_split_493 (insn, recog_data.operand);
    }
  x1 = XEXP (x0, 0);
  goto L4234;

 L4600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[0] = x2;
      goto L4601;
    }
  goto ret0;

 L4601: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L5762;
  goto ret0;

 L5762: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NE:
      goto L4602;
    case EQ:
      goto L4617;
    default:
     break;
   }
  goto ret0;

 L4602: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4603;
    }
  goto ret0;

 L4603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4604;
  goto ret0;

 L4604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4605;
  goto ret0;

 L4605: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return gen_split_462 (insn, recog_data.operand);
    }
  goto ret0;

 L4617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4618;
    }
  goto ret0;

 L4618: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4619;
  goto ret0;

 L4619: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4620;
  goto ret0;

 L4620: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return gen_split_464 (insn, recog_data.operand);
    }
  goto ret0;

 L4623: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == IF_THEN_ELSE)
    goto L4624;
  goto ret0;

 L4624: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case NE:
      goto L4625;
    case EQ:
      goto L4636;
    default:
     break;
   }
  goto ret0;

 L4625: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_comparison_operator (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L4626;
    }
  goto ret0;

 L4626: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L4627;
  goto ret0;

 L4627: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4628;
  goto ret0;

 L4628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4629;
  goto ret0;

 L4629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L4630;
  goto ret0;

 L4630: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[1] = x3;
  goto L4631;

 L4631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return gen_split_465 (insn, recog_data.operand);
    }
  goto ret0;

 L4636: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ix86_comparison_operator (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L4637;
    }
  goto ret0;

 L4637: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L4638;
  goto ret0;

 L4638: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4639;
  goto ret0;

 L4639: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4640;
  goto ret0;

 L4640: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L4641;
  goto ret0;

 L4641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  recog_data.operand[1] = x3;
  goto L4642;

 L4642: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return gen_split_466 (insn, recog_data.operand);
    }
  goto ret0;

 L4235: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L4236;
    case NOT:
      goto L4778;
    case IF_THEN_ELSE:
      goto L4783;
    default:
     break;
   }
  goto ret0;

 L4236: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L4253;
    case MULT:
      goto L4245;
    default:
     break;
   }
  goto ret0;

 L4253: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == MULT)
    goto L4254;
  if (index_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4238;
    }
  goto ret0;

 L4254: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (index_register_operand (x4, VOIDmode))
    {
      recog_data.operand[1] = x4;
      goto L4255;
    }
  goto ret0;

 L4255: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const248_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L4256;
    }
  goto ret0;

 L4256: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4257;
    }
  goto ret0;

 L4257: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      recog_data.operand[4] = x2;
      goto L4258;
    }
  goto ret0;

 L4258: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 3935 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])) && 
//#line 3941 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_352 (insn, recog_data.operand);
    }
  goto ret0;

 L4238: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4239;
    }
  goto ret0;

 L4239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4240;
    }
  goto ret0;

 L4240: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 3831 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[2])
   && (GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])
       || GET_MODE (recog_data.operand[3]) == VOIDmode)) && 
//#line 3839 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_350 (insn, recog_data.operand);
    }
  goto ret0;

 L4245: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (index_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4246;
    }
  goto ret0;

 L4246: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const248_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4247;
    }
  goto ret0;

 L4247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4248;
    }
  goto ret0;

 L4248: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 3884 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode || GET_MODE (recog_data.operand[0]) == HImode
    || (TARGET_64BIT && GET_MODE (recog_data.operand[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[1])
   && (GET_MODE (recog_data.operand[0]) == GET_MODE (recog_data.operand[3])
       || GET_MODE (recog_data.operand[3]) == VOIDmode)) && 
//#line 3891 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_351 (insn, recog_data.operand);
    }
  goto ret0;

 L4778: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4779;
    }
  goto ret0;

 L4779: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10105 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && (GET_MODE (recog_data.operand[0]) == HImode
       || (GET_MODE (recog_data.operand[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ())))))
    {
      return gen_split_495 (insn, recog_data.operand);
    }
  goto ret0;

 L4783: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (comparison_operator (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4784;
    }
  goto ret0;

 L4784: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4785;
  goto ret0;

 L4785: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4786;
  goto ret0;

 L4786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L4787;
    }
  goto ret0;

 L4787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4788;
    }
  goto ret0;

 L4788: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10121 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && TARGET_CMOVE
   && (GET_MODE (recog_data.operand[0]) == HImode
       || (GET_MODE (recog_data.operand[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ())))))
    {
      return gen_split_496 (insn, recog_data.operand);
    }
  goto ret0;
 ret0:
  return 0;
}

static rtx
split_2 (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5764;
    case HImode:
      goto L5765;
    case DImode:
      goto L5766;
    default:
      break;
    }
 L4430: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case REG:
      goto L5768;
    case PC:
      goto L4646;
    default:
     break;
   }
 L4261: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L4262;
    }
 L4359: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L4360;
    }
 L4375: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L4376;
    }
  goto ret0;

 L5764: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4135;
    }
  goto L4430;

 L4135: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5769;
  x2 = XEXP (x1, 0);
  goto L4430;

 L5769: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == ZERO_EXTEND)
    goto L4136;
  if (ix86_comparison_operator (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4582;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4136: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L5771;
    case QImode:
      goto L5772;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L5771: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L4137;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4137: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4138;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4138: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2080 "../../gcc/config/i386/i386.md"
(reload_completed && TARGET_ZERO_EXTEND_WITH_AND
   && optimize_function_for_speed_p (cfun)))
    {
      return gen_split_330 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L5772: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L4165;
    }
 L5773: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L4179;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4165: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4166;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5773;

 L4166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5774;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5773;

 L5774: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5776;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5773;

 L5776: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5778;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5773;

 L5778: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2211 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND || optimize_function_for_size_p (cfun))
   && (!REG_P (recog_data.operand[1]) || ANY_QI_REG_P (recog_data.operand[1]))))
    {
      return gen_split_336 (insn, recog_data.operand);
    }
 L5779: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2223 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (recog_data.operand[0])
   && (ANY_QI_REG_P (recog_data.operand[1]) || MEM_P (recog_data.operand[1]))
   && (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (recog_data.operand[0], recog_data.operand[1])))
    {
      return gen_split_337 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5773;

 L4179: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4180;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2239 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (recog_data.operand[0]) == true_regnum (recog_data.operand[1])))
    {
      return gen_split_338 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4582: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4583;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4583: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4584;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4584: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4585;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4585: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 8972 "../../gcc/config/i386/i386.md"
(!TARGET_PARTIAL_REG_STALL
   && TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun)) && 
//#line 8975 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_459 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L5765: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L4142;
    }
  goto L4430;

 L4142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5780;
  x2 = XEXP (x1, 0);
  goto L4430;

 L5780: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L4143;
    case ROTATE:
      goto L4555;
    case ROTATERT:
      goto L4574;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4143: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode)
    goto L5783;
  x2 = XEXP (x1, 0);
  goto L4430;

 L5783: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L4144;
    }
 L5784: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, QImode))
    {
      recog_data.operand[1] = x3;
      goto L4158;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4144: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5784;

 L4145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5785;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5784;

 L5785: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5787;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5784;

 L5787: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5789;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5784;

 L5789: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2136 "../../gcc/config/i386/i386.md"
(reload_completed
   && (!TARGET_ZERO_EXTEND_WITH_AND
       || optimize_function_for_size_p (cfun))
   && (!REG_P (recog_data.operand[1]) || ANY_QI_REG_P (recog_data.operand[1]))))
    {
      return gen_split_332 (insn, recog_data.operand);
    }
 L5790: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2149 "../../gcc/config/i386/i386.md"
(reload_completed
   && ANY_QI_REG_P (recog_data.operand[0])
   && (TARGET_ZERO_EXTEND_WITH_AND
       && optimize_function_for_speed_p (cfun))
   && !reg_overlap_mentioned_p (recog_data.operand[0], recog_data.operand[1])))
    {
      return gen_split_333 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5784;

 L4158: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4159;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4159: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2165 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (recog_data.operand[0]) == true_regnum (recog_data.operand[1])))
    {
      return gen_split_334 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4555: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4556;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4556: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L4557;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4557: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4558;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8427 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_448 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4574: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4575;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4575: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L4576;
  x2 = XEXP (x1, 0);
  goto L4430;

 L4576: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4577;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4577: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 8650 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_454 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L5766: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L4184;
    }
 L5767: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L4191;
    }
  goto L4430;

 L4184: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5791;
  x2 = XEXP (x1, 0);
  goto L5767;

 L5791: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L4185;
    case ASHIFT:
      goto L4486;
    case ASHIFTRT:
      goto L4519;
    case LSHIFTRT:
      goto L4536;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4185: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4186;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4186: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4187;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2304 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && true_regnum (recog_data.operand[0]) == true_regnum (recog_data.operand[1])))
    {
      return gen_split_340 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4486: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4487;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4488;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4488: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4489;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4489: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 6200 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		     ? epilogue_completed : reload_completed)))
    {
      return gen_split_421 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4519: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4520;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4520: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4521;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4521: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4522;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7249 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		     ? epilogue_completed : reload_completed)))
    {
      return gen_split_432 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4536: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4537;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4537: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4538;
    }
  x2 = XEXP (x1, 0);
  goto L5767;

 L4538: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4539;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4539: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7884 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && ((optimize > 0 && flag_peephole2)
		     ? epilogue_completed : reload_completed)))
    {
      return gen_split_440 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5767;

 L4191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5795;
  x2 = XEXP (x1, 0);
  goto L4430;

 L5795: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L4192;
    case PLUS:
      goto L4229;
    case MINUS:
      goto L4271;
    case NEG:
      goto L4425;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4192: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4193;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4193: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4194;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4194: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 2313 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && reload_completed
   && !SSE_REG_P (recog_data.operand[0]) && !MMX_REG_P (recog_data.operand[0])))
    {
      return gen_split_341 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4229: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4230;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4230: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L4231;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4231: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4232;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4232: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 2574 "../../gcc/config/i386/i386.md"
(reload_completed) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return gen_split_349 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4271: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4272;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4272: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L4273;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4273: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4274;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4274: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4058 "../../gcc/config/i386/i386.md"
(reload_completed) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return gen_split_357 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4425: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4426;
    }
  x2 = XEXP (x1, 0);
  goto L4430;

 L4426: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4427;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L4427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 5735 "../../gcc/config/i386/i386.md"
(reload_completed) && 
//#line 735 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT)))
    {
      return gen_split_411 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4430;

 L5768: ATTRIBUTE_UNUSED_LABEL
  if (flags_reg_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L4431;
    }
  goto L4261;

 L4431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (compare_operator (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L4432;
    }
  x2 = XEXP (x1, 0);
  goto L4261;

 L4432: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L5799;
    case HImode:
      goto L5800;
    case SImode:
      goto L5801;
    default:
      break;
    }
 L4752: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == AND)
    goto L4753;
  x2 = XEXP (x1, 0);
  goto L4261;

 L5799: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L4433;
  goto L4752;

 L4433: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      recog_data.operand[3] = x4;
      goto L4434;
    }
  goto L4752;

 L4434: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4435;
  x3 = XEXP (x2, 0);
  goto L4752;

 L4435: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4436;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4436: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L4437;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == NOT)
    goto L4438;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4438: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && 
//#line 5865 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return gen_split_415 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L5800: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L4444;
  goto L4752;

 L4444: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      recog_data.operand[3] = x4;
      goto L4445;
    }
  goto L4752;

 L4445: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4446;
  x3 = XEXP (x2, 0);
  goto L4752;

 L4446: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4447;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L4448;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == NOT)
    goto L4449;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4449: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && 
//#line 5865 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return gen_split_416 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L5801: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L4455;
  goto L4752;

 L4455: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5802;
  goto L4752;

 L5802: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      recog_data.operand[3] = x4;
      goto L4456;
    }
 L5803: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      recog_data.operand[3] = x4;
      goto L4467;
    }
  goto L4752;

 L4456: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4457;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5803;

 L4457: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4458;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5803;

 L4458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4459;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5803;

 L4459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L4460;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5803;

 L4460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3])
      && 
//#line 5865 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return gen_split_417 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L5803;

 L4467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4468;
  x3 = XEXP (x2, 0);
  goto L4752;

 L4468: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4469;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4469: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L4470;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L4471;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L4472;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4472: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[3])
      && 
//#line 5893 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)))
    {
      return gen_split_418 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4752;

 L4753: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (aligned_operand (x4, VOIDmode))
    {
      recog_data.operand[3] = x4;
      goto L4754;
    }
  x2 = XEXP (x1, 0);
  goto L4261;

 L4754: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, VOIDmode))
    {
      recog_data.operand[4] = x4;
      goto L4755;
    }
  x2 = XEXP (x1, 0);
  goto L4261;

 L4755: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4756;
  x2 = XEXP (x1, 0);
  goto L4261;

 L4756: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4757;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4261;

 L4757: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[1] = x2;
      goto L4758;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4261;

 L4758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == AND)
    goto L4759;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4261;

 L4759: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4760;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4261;

 L4760: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[4])
      && 
//#line 10043 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && optimize_insn_for_speed_p ()
   && ((GET_MODE (recog_data.operand[1]) == HImode && ! TARGET_FAST_PREFIX)
       || (GET_MODE (recog_data.operand[1]) == QImode && TARGET_PROMOTE_QImode))
   /* Ensure that the operand will remain sign-extended immediate.  */
   && ix86_match_ccmode (insn, INTVAL (recog_data.operand[4]) >= 0 ? CCNOmode : CCZmode)))
    {
      return gen_split_492 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4261;

 L4646: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L4647;
  goto ret0;

 L4647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (bt_comparison_operator (x3, VOIDmode))
    {
      recog_data.operand[0] = x3;
      goto L4648;
    }
  goto ret0;

 L4648: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L5804;
  goto ret0;

 L5804: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTRACT:
      goto L4649;
    case AND:
      goto L4681;
    default:
     break;
   }
  goto ret0;

 L4649: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      recog_data.operand[1] = x5;
      goto L4650;
    }
  goto ret0;

 L4650: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L4651;
  goto ret0;

 L4651: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (GET_MODE (x5) == SImode)
    goto L5806;
  goto ret0;

 L5806: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ZERO_EXTEND:
      goto L4652;
    case AND:
      goto L4668;
    default:
     break;
   }
  goto ret0;

 L4652: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, QImode))
    {
      recog_data.operand[2] = x6;
      goto L4653;
    }
  goto ret0;

 L4653: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4654;
  goto ret0;

 L4654: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L4655;
  goto ret0;

 L4655: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[3] = x4;
  goto L4656;

 L4656: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L4657;
  goto ret0;

 L4657: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4658;
  goto ret0;

 L4658: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 9258 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)) && 
//#line 9260 "../../gcc/config/i386/i386.md"
( 1)))
    {
      return gen_split_467 (insn, recog_data.operand);
    }
  goto ret0;

 L4668: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      recog_data.operand[2] = x6;
      goto L4669;
    }
  goto ret0;

 L4669: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      recog_data.operand[3] = x6;
      goto L4670;
    }
  goto ret0;

 L4670: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L4671;
  goto ret0;

 L4671: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[4] = x4;
  goto L4672;

 L4672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L4673;
  goto ret0;

 L4673: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4674;
  goto ret0;

 L4674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 9291 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f) && 
//#line 9294 "../../gcc/config/i386/i386.md"
( 1)))
    {
      return gen_split_468 (insn, recog_data.operand);
    }
  goto ret0;

 L4681: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == LSHIFTRT)
    goto L4682;
  goto ret0;

 L4682: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      recog_data.operand[1] = x6;
      goto L4683;
    }
  goto ret0;

 L4683: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == QImode)
    goto L5808;
  goto ret0;

 L5808: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x6, QImode))
    {
      recog_data.operand[2] = x6;
      goto L4684;
    }
 L5809: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x6) == SUBREG
      && XINT (x6, 1) == 0)
    goto L4700;
  goto ret0;

 L4684: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L4685;
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4685: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4686;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4686: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L4687;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4687: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[3] = x4;
  goto L4688;

 L4688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L4689;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4689: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4690;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 9320 "../../gcc/config/i386/i386.md"
(TARGET_USE_BT || optimize_function_for_size_p (cfun)) && 
//#line 9322 "../../gcc/config/i386/i386.md"
( 1)))
    {
      return gen_split_469 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  x6 = XEXP (x5, 1);
  goto L5809;

 L4700: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (GET_MODE (x7) == SImode
      && GET_CODE (x7) == AND)
    goto L4701;
  goto ret0;

 L4701: ATTRIBUTE_UNUSED_LABEL
  x8 = XEXP (x7, 0);
  if (register_operand (x8, SImode))
    {
      recog_data.operand[2] = x8;
      goto L4702;
    }
  goto ret0;

 L4702: ATTRIBUTE_UNUSED_LABEL
  x8 = XEXP (x7, 1);
  if (const_int_operand (x8, SImode))
    {
      recog_data.operand[3] = x8;
      goto L4703;
    }
  goto ret0;

 L4703: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L4704;
  goto ret0;

 L4704: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4705;
  goto ret0;

 L4705: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L4706;
  goto ret0;

 L4706: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  recog_data.operand[4] = x4;
  goto L4707;

 L4707: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L4708;
  goto ret0;

 L4708: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4709;
  goto ret0;

 L4709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 9357 "../../gcc/config/i386/i386.md"
((TARGET_USE_BT || optimize_function_for_size_p (cfun))
   && (INTVAL (recog_data.operand[3]) & 0x1f) == 0x1f) && 
//#line 9360 "../../gcc/config/i386/i386.md"
( 1)))
    {
      return gen_split_470 (insn, recog_data.operand);
    }
  goto ret0;

 L4262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L4263;
    case AND:
      goto L4353;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L4359;

 L4263: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4264;
    }
  x2 = XEXP (x1, 0);
  goto L4359;

 L4264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4265;
    }
  x2 = XEXP (x1, 0);
  goto L4359;

 L4265: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4266;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4359;

 L4266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4006 "../../gcc/config/i386/i386.md"
(reload_completed && ix86_lea_for_add_ok (PLUS, insn, recog_data.operand)))
    {
      return gen_split_353 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4359;

 L4353: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4354;
  x2 = XEXP (x1, 0);
  goto L4359;

 L4354: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -65536L)
    goto L4355;
  x2 = XEXP (x1, 0);
  goto L4359;

 L4355: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4356;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4359;

 L4356: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5122 "../../gcc/config/i386/i386.md"
((TARGET_FAST_PREFIX && !TARGET_PARTIAL_REG_STALL)
    || optimize_function_for_size_p (cfun)))
    {
      return gen_split_392 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4359;

 L4360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == AND)
    goto L4361;
  x2 = XEXP (x1, 0);
  goto L4375;

 L4361: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4362;
  x2 = XEXP (x1, 0);
  goto L4375;

 L4362: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5810;
  x2 = XEXP (x1, 0);
  goto L4375;

 L5810: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case -256L:
        goto L4363;
      case -65281L:
        goto L4371;
      default:
        break;
      }
  x2 = XEXP (x1, 0);
  goto L4375;

 L4363: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4364;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4375;

 L4364: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5132 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && reload_completed))
    {
      return gen_split_393 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4375;

 L4371: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4372;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4375;

 L4372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5142 "../../gcc/config/i386/i386.md"
((!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
   && reload_completed))
    {
      return gen_split_394 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4375;

 L4376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case AND:
      goto L4377;
    case IOR:
      goto L4393;
    case XOR:
      goto L4401;
    case ASHIFT:
      goto L4494;
    case NEG:
      goto L4772;
    default:
     break;
   }
 L4743: ATTRIBUTE_UNUSED_LABEL
  if (promotable_binary_operator (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4744;
    }
  goto ret0;

 L4377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4378;
    }
 L4385: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4386;
    }
  goto L4743;

 L4378: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4379;
    }
  x3 = XEXP (x2, 0);
  goto L4385;

 L4379: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4380;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4385;

 L4380: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5358 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (recog_data.operand[2]) & ~(255 << 8))
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_395 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4385;

 L4386: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4387;
    }
  goto L4743;

 L4387: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4388;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5379 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(~INTVAL (recog_data.operand[2]) & ~255)
    && !(INTVAL (recog_data.operand[2]) & 128)
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_396 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4393: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4394;
    }
 L4409: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4410;
    }
  goto L4743;

 L4394: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4395;
    }
  x3 = XEXP (x2, 0);
  goto L4409;

 L4395: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4396;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4409;

 L4396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5613 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (recog_data.operand[2]) & ~(255 << 8))
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_403 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4409;

 L4410: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4411;
    }
  goto L4743;

 L4411: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4412;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4412: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5634 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (recog_data.operand[2]) & ~255)
    && (INTVAL (recog_data.operand[2]) & 128)
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_405 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4401: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4402;
    }
 L4417: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4418;
    }
  goto L4743;

 L4402: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4403;
    }
  x3 = XEXP (x2, 0);
  goto L4417;

 L4403: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4404;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4417;

 L4404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5613 "../../gcc/config/i386/i386.md"
(reload_completed
    && QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (recog_data.operand[2]) & ~(255 << 8))
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_404 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4417;

 L4418: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4419;
    }
  goto L4743;

 L4419: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4420;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4420: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 5634 "../../gcc/config/i386/i386.md"
(reload_completed
    && ANY_QI_REG_P (recog_data.operand[0])
    && (!TARGET_PARTIAL_REG_STALL || optimize_function_for_size_p (cfun))
    && !(INTVAL (recog_data.operand[2]) & ~255)
    && (INTVAL (recog_data.operand[2]) & 128)
    && GET_MODE (recog_data.operand[0]) != QImode))
    {
      return gen_split_406 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4494: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (index_register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4495;
    }
 L4502: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4503;
    }
  goto L4743;

 L4495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4496;
    }
  x3 = XEXP (x2, 0);
  goto L4502;

 L4496: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4497;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4502;

 L4497: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 6324 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (recog_data.operand[0]) != true_regnum (recog_data.operand[1])
   && GET_MODE_SIZE (GET_MODE (recog_data.operand[0])) <= 4))
    {
      return gen_split_425 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4502;

 L4503: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4504;
    }
  goto L4743;

 L4504: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4505;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4505: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 6351 "../../gcc/config/i386/i386.md"
(reload_completed
   && true_regnum (recog_data.operand[0]) != true_regnum (recog_data.operand[1])))
    {
      return gen_split_426 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L4743;

 L4772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4773;
    }
  goto ret0;

 L4773: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4774;
  goto ret0;

 L4774: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10091 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && (GET_MODE (recog_data.operand[0]) == HImode
       || (GET_MODE (recog_data.operand[0]) == QImode
	   && (TARGET_PROMOTE_QImode
	       || optimize_insn_for_size_p ())))))
    {
      return gen_split_494 (insn, recog_data.operand);
    }
  goto ret0;

 L4744: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      recog_data.operand[1] = x3;
      goto L4745;
    }
  goto ret0;

 L4745: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (aligned_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4746;
    }
  goto ret0;

 L4746: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4747;
  goto ret0;

 L4747: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10014 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL && reload_completed
   && ((GET_MODE (recog_data.operand[0]) == HImode
	&& ((optimize_function_for_speed_p (cfun) && !TARGET_FAST_PREFIX)
            /* ??? next two lines just !satisfies_constraint_K (...) */
	    || !CONST_INT_P (recog_data.operand[2])
	    || satisfies_constraint_K (recog_data.operand[2])))
       || (GET_MODE (recog_data.operand[0]) == QImode
	   && (TARGET_PROMOTE_QImode || optimize_function_for_size_p (cfun))))))
    {
      return gen_split_491 (insn, recog_data.operand);
    }
  goto ret0;
 ret0:
  return 0;
}

rtx
split_insns (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case SET:
      goto L4114;
    case PARALLEL:
      goto L5748;
    case EH_RETURN:
      goto L5750;
    default:
     break;
   }
  goto ret0;

 L4114: ATTRIBUTE_UNUSED_LABEL
  return split_1 (x0, insn);

 L5748: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L4133;
    case 3:
      goto L4196;
    default:
      break;
    }
  goto ret0;

 L4133: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4134;
  goto ret0;

 L4134: ATTRIBUTE_UNUSED_LABEL
  return split_2 (x0, insn);

 L4196: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4197;
  goto ret0;

 L4197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L5812;
    case HImode:
      goto L5814;
    case SImode:
      goto L5815;
    default:
      break;
    }
  goto ret0;

 L5812: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L4198;
    }
 L5813: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L4218;
    }
  goto ret0;

 L4198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L4199;
  x2 = XEXP (x1, 0);
  goto L5813;

 L4199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4200;
    }
  x2 = XEXP (x1, 0);
  goto L5813;

 L4200: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4201;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5813;

 L4201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4202;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5813;

 L4202: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4203;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5813;

 L4203: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L4204;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5813;

 L4204: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2393 "../../gcc/config/i386/i386.md"
((reload_completed
    && dead_or_set_p (insn, recog_data.operand[1])
    && !reg_mentioned_p (recog_data.operand[1], recog_data.operand[0]))))
    {
      return gen_split_343 (insn, recog_data.operand);
    }
 L4214: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2408 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_344 (insn, recog_data.operand);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5813;

 L4218: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5816;
  goto ret0;

 L5816: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L4219;
    case ROTATE:
      goto L4544;
    case ROTATERT:
      goto L4563;
    default:
     break;
   }
  goto ret0;

 L4219: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4220;
    }
  goto ret0;

 L4220: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4221;
  goto ret0;

 L4221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4222;
  goto ret0;

 L4222: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4223;
  goto ret0;

 L4223: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L4224;
    }
  goto ret0;

 L4224: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 2438 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_345 (insn, recog_data.operand);
    }
  goto ret0;

 L4544: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4545;
    }
  goto ret0;

 L4545: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4546;
    }
  goto ret0;

 L4546: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4547;
  goto ret0;

 L4547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4548;
  goto ret0;

 L4548: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4549;
  goto ret0;

 L4549: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L4550;
    }
  goto ret0;

 L4550: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 8291 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT) && 
//#line 8293 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_445 (insn, recog_data.operand);
    }
  goto ret0;

 L4563: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4564;
    }
  goto ret0;

 L4564: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_1_to_31_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4565;
    }
  goto ret0;

 L4565: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4566;
  goto ret0;

 L4566: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4567;
  goto ret0;

 L4567: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4568;
  goto ret0;

 L4568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L4569;
    }
  goto ret0;

 L4569: ATTRIBUTE_UNUSED_LABEL
  if ((
//#line 8514 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT) && 
//#line 8516 "../../gcc/config/i386/i386.md"
( reload_completed)))
    {
      return gen_split_451 (insn, recog_data.operand);
    }
  goto ret0;

 L5814: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L4278;
    }
  goto ret0;

 L4278: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L5819;
  goto ret0;

 L5819: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L4279;
    case UDIV:
      goto L4305;
    default:
     break;
   }
  goto ret0;

 L4279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L4280;
    }
  goto ret0;

 L4280: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L4281;
    }
  goto ret0;

 L4281: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4282;
  goto ret0;

 L4282: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L4283;
    }
  goto ret0;

 L4283: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L4284;
  goto ret0;

 L4284: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4285;
  goto ret0;

 L4285: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4286;
  goto ret0;

 L4286: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4287;
  goto ret0;

 L4287: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4542 "../../gcc/config/i386/i386.md"
(reload_completed) && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)))
    {
      return gen_split_377 (insn, recog_data.operand);
    }
  goto ret0;

 L4305: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L4306;
    }
  goto ret0;

 L4306: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[3] = x3;
      goto L4307;
    }
  goto ret0;

 L4307: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4308;
  goto ret0;

 L4308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L4309;
    }
  goto ret0;

 L4309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == UMOD)
    goto L4310;
  goto ret0;

 L4310: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4311;
  goto ret0;

 L4311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4312;
  goto ret0;

 L4312: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4313;
  goto ret0;

 L4313: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (
//#line 4601 "../../gcc/config/i386/i386.md"
(reload_completed) && 
//#line 732 "../../gcc/config/i386/i386.md"
(TARGET_HIMODE_MATH)))
    {
      return gen_split_381 (insn, recog_data.operand);
    }
  goto ret0;

 L5815: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4291;
    }
  goto ret0;

 L4291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5821;
  goto ret0;

 L5821: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L4292;
    case UDIV:
      goto L4318;
    default:
     break;
   }
  goto ret0;

 L4292: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4293;
    }
  goto ret0;

 L4293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4294;
    }
  goto ret0;

 L4294: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4295;
  goto ret0;

 L4295: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4296;
    }
  goto ret0;

 L4296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L4297;
  goto ret0;

 L4297: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4298;
  goto ret0;

 L4298: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4299;
  goto ret0;

 L4299: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4300;
  goto ret0;

 L4300: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4542 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_378 (insn, recog_data.operand);
    }
  goto ret0;

 L4318: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4319;
    }
  goto ret0;

 L4319: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4320;
    }
  goto ret0;

 L4320: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4321;
  goto ret0;

 L4321: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4322;
    }
  goto ret0;

 L4322: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L4323;
  goto ret0;

 L4323: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[2]))
    goto L4324;
  goto ret0;

 L4324: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[3]))
    goto L4325;
  goto ret0;

 L4325: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4326;
  goto ret0;

 L4326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 4601 "../../gcc/config/i386/i386.md"
(reload_completed))
    {
      return gen_split_382 (insn, recog_data.operand);
    }
  goto ret0;

 L5750: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 9895 "../../gcc/config/i386/i386.md"
(epilogue_completed))
    {
      return gen_split_488 (insn, recog_data.operand);
    }
  goto ret0;
 ret0:
  return 0;
}

static rtx
peephole2_1 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *_pmatch_len ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L4934;
    case 3:
      goto L5003;
    default:
      break;
    }
  goto ret0;

 L4934: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4935;
  goto ret0;

 L4935: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5849;
    case DImode:
      goto L5850;
    case HImode:
      goto L5853;
    default:
      break;
    }
  goto ret0;

 L5849: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L5029;
  if (memory_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4936;
    }
 L5851: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L5222;
    }
  goto ret0;

 L5029: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5030;
  x2 = XEXP (x1, 0);
  goto L5851;

 L5030: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L5031;
  x2 = XEXP (x1, 0);
  goto L5851;

 L5031: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5854;
  x2 = XEXP (x1, 0);
  goto L5851;

 L5854: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case -4L:
        goto L5032;
      case -8L:
        goto L5041;
      case 4L:
        goto L5086;
      case 8L:
        goto L5095;
      default:
        break;
      }
  x2 = XEXP (x1, 0);
  goto L5851;

 L5032: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5033;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10649 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_531 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5041: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5042;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5042: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10657 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_532 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5086: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5087;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5087: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_536 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5095: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5096;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5096: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5858;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5858: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5860;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5860: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5862;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5862: ATTRIBUTE_UNUSED_LABEL
  *_pmatch_len = 0;
  tem = gen_peephole2_537 (insn, recog_data.operand);
  if (tem != 0)
    return tem;
 L5863: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10731 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ()))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_538 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L4936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_or_logical_operator (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L4937;
    }
  x2 = XEXP (x1, 0);
  goto L5851;

 L4937: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4938;
 L4946: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4947;
    }
  x2 = XEXP (x1, 0);
  goto L5851;

 L4938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4939;
    }
  x3 = XEXP (x2, 0);
  goto L4946;

 L4939: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4940;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4946;

 L4940: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10488 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY_WRITE
   /* Do not split stack checking probes.  */
   && GET_CODE (recog_data.operand[3]) != IOR && recog_data.operand[1] != const0_rtx))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_519 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4946;

 L4947: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4948;
  x2 = XEXP (x1, 0);
  goto L5851;

 L4948: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4949;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L4949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10505 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY_WRITE
   /* Do not split stack checking probes.  */
   && GET_CODE (recog_data.operand[3]) != IOR && recog_data.operand[1] != const0_rtx))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_520 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5851;

 L5222: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MULT)
    goto L5223;
  goto ret0;

 L5223: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5864;
  goto ret0;

 L5864: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L5224;
    }
 L5865: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L5233;
    }
 L5866: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L5251;
    }
 L5867: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L5279;
    }
  goto ret0;

 L5224: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L5225;
    }
  x3 = XEXP (x2, 0);
  goto L5865;

 L5225: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5226;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5865;

 L5226: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10878 "../../gcc/config/i386/i386.md"
(INTVAL (recog_data.operand[2]) == 3
   || INTVAL (recog_data.operand[2]) == 5
   || INTVAL (recog_data.operand[2]) == 9))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_550 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5865;

 L5233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L5234;
    }
  x3 = XEXP (x2, 0);
  goto L5866;

 L5234: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5235;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5866;

 L5235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10892 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && (INTVAL (recog_data.operand[2]) == 3
       || INTVAL (recog_data.operand[2]) == 5
       || INTVAL (recog_data.operand[2]) == 9)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_551 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5866;

 L5251: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L5252;
    }
  x3 = XEXP (x2, 0);
  goto L5867;

 L5252: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5253;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5867;

 L5253: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10955 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()
   && !satisfies_constraint_K (recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_553 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5867;

 L5279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L5280;
    }
  goto ret0;

 L5280: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5281;
  goto ret0;

 L5281: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 11002 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()
   && satisfies_constraint_K (recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_556 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5850: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L5141;
 L5852: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L5240;
    }
  goto ret0;

 L5141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L5142;
  x2 = XEXP (x1, 0);
  goto L5852;

 L5142: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L5143;
  x2 = XEXP (x1, 0);
  goto L5852;

 L5143: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5868;
  x2 = XEXP (x1, 0);
  goto L5852;

 L5868: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case -8L:
        goto L5144;
      case -16L:
        goto L5153;
      case 8L:
        goto L5198;
      case 16L:
        goto L5207;
      default:
        break;
      }
  x2 = XEXP (x1, 0);
  goto L5852;

 L5144: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10782 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_542 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5153: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5154;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5154: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10790 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_543 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5198: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5199;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5199: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_547 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5207: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5208;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5208: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L5872;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5872: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L5874;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5874: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L5876;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5876: ATTRIBUTE_UNUSED_LABEL
  *_pmatch_len = 0;
  tem = gen_peephole2_548 (insn, recog_data.operand);
  if (tem != 0)
    return tem;
 L5877: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10864 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ()))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_549 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5852;

 L5240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5878;
  goto ret0;

 L5878: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L5241;
    case ZERO_EXTEND:
      goto L5259;
    default:
     break;
   }
  goto ret0;

 L5241: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5880;
  goto ret0;

 L5880: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L5242;
    }
 L5881: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L5270;
    }
  goto ret0;

 L5242: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L5243;
    }
  x3 = XEXP (x2, 0);
  goto L5881;

 L5243: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5244;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5881;

 L5244: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10942 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()
   && !satisfies_constraint_K (recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_552 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L5881;

 L5270: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L5271;
    }
  goto ret0;

 L5271: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5272;
  goto ret0;

 L5272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10986 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()
   && satisfies_constraint_K (recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_555 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5259: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L5260;
  goto ret0;

 L5260: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (memory_operand (x4, SImode))
    {
      recog_data.operand[1] = x4;
      goto L5261;
    }
  goto ret0;

 L5261: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (immediate_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L5262;
    }
  goto ret0;

 L5262: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5263;
  goto ret0;

 L5263: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10969 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM32_MEM && optimize_insn_for_speed_p ()
   && !satisfies_constraint_K (recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_554 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5853: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      recog_data.operand[0] = x2;
      goto L5286;
    }
  goto ret0;

 L5286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MULT)
    goto L5287;
  goto ret0;

 L5287: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      recog_data.operand[1] = x3;
      goto L5288;
    }
  goto ret0;

 L5288: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, HImode))
    {
      recog_data.operand[2] = x3;
      goto L5289;
    }
  goto ret0;

 L5289: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5290;
  goto ret0;

 L5290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 11018 "../../gcc/config/i386/i386.md"
(TARGET_SLOW_IMUL_IMM8 && optimize_insn_for_speed_p ()))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_557 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5003: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L5004;
  goto ret0;

 L5004: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5882;
    case DImode:
      goto L5883;
    default:
      break;
    }
  goto ret0;

 L5882: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L5005;
  goto ret0;

 L5005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5006;
  goto ret0;

 L5006: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L5007;
  goto ret0;

 L5007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5884;
  goto ret0;

 L5884: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case -4L:
        goto L5008;
      case -8L:
        goto L5020;
      case 4L:
        goto L5050;
      case 8L:
        goto L5062;
      default:
        break;
      }
  goto ret0;

 L5008: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5009;
  goto ret0;

 L5009: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5010;
  goto ret0;

 L5010: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5011;
  goto ret0;

 L5011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5012;
  goto ret0;

 L5012: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10628 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_529 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5020: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5021;
  goto ret0;

 L5021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5022;
  goto ret0;

 L5022: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5023;
  goto ret0;

 L5023: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5024;
  goto ret0;

 L5024: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10638 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_530 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5050: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5051;
  goto ret0;

 L5051: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5052;
  goto ret0;

 L5052: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5053;
  goto ret0;

 L5053: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5054;
  goto ret0;

 L5054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10668 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_533 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5062: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5063;
  goto ret0;

 L5063: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5064;
  goto ret0;

 L5064: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5065;
  goto ret0;

 L5065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5066;
  goto ret0;

 L5066: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    goto L5888;
  goto ret0;

 L5888: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10682 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_534 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
 L5889: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10695 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ()))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_535 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5883: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L5117;
  goto ret0;

 L5117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L5118;
  goto ret0;

 L5118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L5119;
  goto ret0;

 L5119: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5890;
  goto ret0;

 L5890: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case -8L:
        goto L5120;
      case -16L:
        goto L5132;
      case 8L:
        goto L5162;
      case 16L:
        goto L5174;
      default:
        break;
      }
  goto ret0;

 L5120: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5121;
  goto ret0;

 L5121: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5122;
  goto ret0;

 L5122: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5123;
  goto ret0;

 L5123: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5124;
  goto ret0;

 L5124: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10761 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_540 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5132: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5133;
  goto ret0;

 L5133: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5134;
  goto ret0;

 L5134: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5135;
  goto ret0;

 L5135: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5136;
  goto ret0;

 L5136: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10771 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_SUB_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_541 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5162: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5163;
  goto ret0;

 L5163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5164;
  goto ret0;

 L5164: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5165;
  goto ret0;

 L5165: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5166;
  goto ret0;

 L5166: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && 
//#line 10801 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_4))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_544 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L5174: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5175;
  goto ret0;

 L5175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5176;
  goto ret0;

 L5176: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5177;
  goto ret0;

 L5177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L5178;
  goto ret0;

 L5178: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH)
    goto L5894;
  goto ret0;

 L5894: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10815 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p () || !TARGET_ADD_ESP_8))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_545 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
 L5895: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10828 "../../gcc/config/i386/i386.md"
(optimize_insn_for_size_p ()))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_546 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;
 ret0:
  return 0;
}

rtx
peephole2_insns (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *_pmatch_len ATTRIBUTE_UNUSED)
{
  //rtx * const recog_data.operand ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx x8 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  if (GET_CODE (x0) == PARALLEL
      && XVECLEN (x0, 0) == 2)
    goto L4475;
 L4710: ATTRIBUTE_UNUSED_LABEL
  if (peep2_current_count >= 3)
    goto L4711;
 L4790: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x0))
    {
    case SET:
      goto L4791;
    case PARALLEL:
      goto L5823;
    default:
     break;
   }
 L4910: ATTRIBUTE_UNUSED_LABEL
  if (peep2_current_count >= 2)
    goto L4911;
 L4933: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x0))
    {
    case PARALLEL:
      goto L5824;
    case SET:
      goto L4973;
    default:
     break;
   }
  goto ret0;

 L4475: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4476;
  goto L4710;

 L4476: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      recog_data.operand[0] = x2;
      goto L4477;
    }
  goto L4710;

 L4477: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5826;
  goto L4710;

 L5826: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFT:
      goto L4478;
    case ASHIFTRT:
      goto L4511;
    case LSHIFTRT:
      goto L4528;
    default:
     break;
   }
  goto L4710;

 L4478: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4479;
    }
  goto L4710;

 L4479: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4480;
    }
  goto L4710;

 L4480: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4481;
  goto L4710;

 L4481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 6191 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_CMOVE))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_420 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4710;

 L4511: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4512;
    }
  goto L4710;

 L4512: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4513;
    }
  goto L4710;

 L4513: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4514;
  goto L4710;

 L4514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7240 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_CMOVE))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_431 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4710;

 L4528: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4529;
    }
  goto L4710;

 L4529: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4530;
    }
  goto L4710;

 L4530: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4531;
  goto L4710;

 L4531: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 7875 "../../gcc/config/i386/i386.md"
(!TARGET_64BIT && TARGET_CMOVE))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_439 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4710;

 L4711: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L4712;
  goto L4790;

 L4712: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L4713;
  goto L4790;

 L4713: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  recog_data.operand[0] = x1;
  goto L4714;

 L4714: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4715;
  goto L4790;

 L4715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L4716;
    }
  goto L4790;

 L4716: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (ix86_comparison_operator (x2, QImode))
    {
      recog_data.operand[2] = x2;
      goto L4717;
    }
  goto L4790;

 L4717: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L4718;
  goto L4790;

 L4718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L4719;
  goto L4790;

 L4719: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (2);
  x1 = PATTERN (tem);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L4720;
    case PARALLEL:
      goto L5829;
    default:
     break;
   }
  goto L4790;

 L4720: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (q_regs_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4721;
    }
  goto L4790;

 L4721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == ZERO_EXTEND)
    goto L4722;
  goto L4790;

 L4722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[1])
      && 
//#line 9459 "../../gcc/config/i386/i386.md"
((peep2_reg_dead_p (3, recog_data.operand[1])
    || recog_data.operand_match_p (recog_data.operand[1], recog_data.operand[3]))
   && ! reg_overlap_mentioned_p (recog_data.operand[3], recog_data.operand[0])))
    {
      *_pmatch_len = 2;
      tem = gen_peephole2_473 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4790;

 L5829: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2)
    goto L4733;
  goto L4790;

 L4733: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == SET)
    goto L4734;
  goto L4790;

 L4734: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (q_regs_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4735;
    }
  goto L4790;

 L4735: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == ZERO_EXTEND)
    goto L4736;
  goto L4790;

 L4736: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[1]))
    goto L4737;
  goto L4790;

 L4737: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) == CLOBBER)
    goto L4738;
  goto L4790;

 L4738: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CCmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 17
      && 
//#line 9481 "../../gcc/config/i386/i386.md"
((peep2_reg_dead_p (3, recog_data.operand[1])
    || recog_data.operand_match_p (recog_data.operand[1], recog_data.operand[3]))
   && ! reg_overlap_mentioned_p (recog_data.operand[3], recog_data.operand[0])))
    {
      *_pmatch_len = 2;
      tem = gen_peephole2_474 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4790;

 L4791: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5830;
    case DImode:
      goto L5831;
    case SFmode:
      goto L5832;
    case HImode:
      goto L5833;
    case QImode:
      goto L5834;
    default:
      break;
    }
 L4843: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case REG:
      goto L5842;
    case STRICT_LOW_PART:
      goto L4958;
    default:
     break;
   }
 L4952: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L4953;
    }
  goto L4910;

 L5830: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4792;
    }
 L5835: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4817;
    }
 L5838: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4850;
    }
 L5841: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4967;
    }
  goto L4843;

 L4792: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L4793;
    }
  x1 = XEXP (x0, 0);
  goto L5835;

 L4793: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10141 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_497 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5835;

 L4817: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10195 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ! TARGET_USE_MOV0
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_502 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
 L4829: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L4830;
    }
  x1 = XEXP (x0, 0);
  goto L5838;

 L4830: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10237 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_505 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5838;

 L4850: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == NOT)
    goto L4851;
  x1 = XEXP (x0, 0);
  goto L5841;

 L4851: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4852;
    }
  x1 = XEXP (x0, 0);
  goto L5841;

 L4852: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10292 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (recog_data.operand[0])
            || !memory_displacement_operand (recog_data.operand[0], SImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (recog_data.operand[0], SImode)))
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_509 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5841;

 L4967: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == PLUS)
    goto L4968;
  x1 = XEXP (x0, 0);
  goto L4843;

 L4968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L4969;
  x1 = XEXP (x0, 0);
  goto L4843;

 L4969: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4970;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L4970: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10559 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_524 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L5831: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L4797;
    }
  goto L4843;

 L4797: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, DImode))
    {
      recog_data.operand[1] = x1;
      goto L4798;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L4798: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10151 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_498 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L5832: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SFmode))
    {
      recog_data.operand[0] = x1;
      goto L4802;
    }
  goto L4843;

 L4802: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, SFmode))
    {
      recog_data.operand[1] = x1;
      goto L4803;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L4803: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10163 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_499 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L5833: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L4807;
    }
 L5836: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L4821;
    }
 L5839: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      recog_data.operand[0] = x1;
      goto L4856;
    }
  goto L4843;

 L4807: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, HImode))
    {
      recog_data.operand[1] = x1;
      goto L4808;
    }
  x1 = XEXP (x0, 0);
  goto L5836;

 L4808: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10173 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_500 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5836;

 L4821: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10209 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ! TARGET_USE_MOV0
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_503 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
 L4834: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x1, HImode))
    {
      recog_data.operand[1] = x1;
      goto L4835;
    }
  x1 = XEXP (x0, 0);
  goto L5839;

 L4835: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10248 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_506 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5839;

 L4856: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == NOT)
    goto L4857;
  x1 = XEXP (x0, 0);
  goto L4843;

 L4857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      recog_data.operand[1] = x2;
      goto L4858;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L4858: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10306 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (recog_data.operand[0])
            || !memory_displacement_operand (recog_data.operand[0], HImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (recog_data.operand[0], HImode)))
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_510 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L5834: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L4812;
    }
 L5837: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L4825;
    }
 L5840: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      recog_data.operand[0] = x1;
      goto L4862;
    }
  goto L4843;

 L4812: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L4813;
    }
  x1 = XEXP (x0, 0);
  goto L5837;

 L4813: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10183 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && !TARGET_PUSH_MEMORY
   && !RTX_FRAME_RELATED_P (peep2_next_insn (0))))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_501 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5837;

 L4825: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10223 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ! TARGET_USE_MOV0
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_504 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
 L4839: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x1, QImode))
    {
      recog_data.operand[1] = x1;
      goto L4840;
    }
  x1 = XEXP (x0, 0);
  goto L5840;

 L4840: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10259 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && TARGET_SPLIT_LONG_MOVES
   && get_attr_length (insn) >= ix86_cur_cost ()->large_insn))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_507 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5840;

 L4862: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == NOT)
    goto L4863;
  x1 = XEXP (x0, 0);
  goto L4843;

 L4863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      recog_data.operand[1] = x2;
      goto L4864;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L4864: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10320 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p ()
   && ((TARGET_NOT_UNPAIRABLE
        && (!MEM_P (recog_data.operand[0])
            || !memory_displacement_operand (recog_data.operand[0], QImode)))
       || (TARGET_NOT_VECTORMODE && long_memory_operand (recog_data.operand[0], QImode)))
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_511 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4843;

 L5842: ATTRIBUTE_UNUSED_LABEL
  if (flags_reg_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L4844;
    }
  goto L4952;

 L4844: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (compare_operator (x1, VOIDmode))
    {
      recog_data.operand[1] = x1;
      goto L4845;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4845: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5844;
    case QImode:
      goto L5845;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L5844: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == AND)
    goto L4870;
  if (memory_operand (x2, SImode))
    {
      recog_data.operand[2] = x2;
      goto L4846;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4870: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5847;
  x1 = XEXP (x0, 0);
  goto L4952;

 L5847: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == ZERO_EXTRACT)
    goto L4887;
  if (register_operand (x3, SImode))
    {
      recog_data.operand[2] = x3;
      goto L4871;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4887: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      recog_data.operand[2] = x4;
      goto L4888;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4888: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L4889;
  x1 = XEXP (x0, 0);
  goto L4952;

 L4889: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (8)])
    goto L4890;
  x1 = XEXP (x0, 0);
  goto L4952;

 L4890: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, VOIDmode))
    {
      recog_data.operand[3] = x3;
      goto L4891;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10387 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL
   && ix86_match_ccmode (insn, CCNOmode)
   && true_regnum (recog_data.operand[2]) != AX_REG
   && peep2_reg_dead_p (1, recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_514 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4871: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4872;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4872: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10344 "../../gcc/config/i386/i386.md"
(ix86_match_ccmode (insn, CCNOmode)
   && (true_regnum (recog_data.operand[2]) != AX_REG
       || satisfies_constraint_K (recog_data.operand[3]))
   && peep2_reg_dead_p (1, recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_512 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10273 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ix86_match_ccmode (insn, CCNOmode)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_508 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L5845: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == AND)
    goto L4878;
  x1 = XEXP (x0, 0);
  goto L4952;

 L4878: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, QImode))
    {
      recog_data.operand[2] = x3;
      goto L4879;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4879: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, QImode))
    {
      recog_data.operand[3] = x3;
      goto L4880;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4880: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10365 "../../gcc/config/i386/i386.md"
(! TARGET_PARTIAL_REG_STALL
   && ix86_match_ccmode (insn, CCNOmode)
   && true_regnum (recog_data.operand[2]) != AX_REG
   && peep2_reg_dead_p (1, recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_513 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4952;

 L4958: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[0] = x2;
      goto L4959;
    }
  goto L4910;

 L4959: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
//#line 10532 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == QImode
    || GET_MODE (recog_data.operand[0]) == HImode)
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_522 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4910;

 L4953: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, VOIDmode))
    {
      recog_data.operand[1] = x1;
      goto L4954;
    }
 L4963: ATTRIBUTE_UNUSED_LABEL
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (-1)]
      && 
//#line 10543 "../../gcc/config/i386/i386.md"
((GET_MODE (recog_data.operand[0]) == HImode
    || GET_MODE (recog_data.operand[0]) == SImode
    || (GET_MODE (recog_data.operand[0]) == DImode && TARGET_64BIT))
   && (optimize_insn_for_size_p () || TARGET_MOVE_M1_VIA_OR)
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_523 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4910;

 L4954: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10519 "../../gcc/config/i386/i386.md"
(GET_MODE_SIZE (GET_MODE (recog_data.operand[0])) <= UNITS_PER_WORD
   && (! TARGET_USE_MOV0 || optimize_insn_for_size_p ())
   && GENERAL_REG_P (recog_data.operand[0])
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_521 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 1);
  goto L4963;

 L5823: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 2)
    goto L4894;
  goto L4910;

 L4894: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4895;
  goto L4910;

 L4895: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      recog_data.operand[0] = x2;
      goto L4896;
    }
  goto L4910;

 L4896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_or_logical_operator (x2, SImode))
    {
      recog_data.operand[3] = x2;
      goto L4897;
    }
  goto L4910;

 L4897: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4898;
 L4906: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4907;
    }
  goto L4910;

 L4898: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (memory_operand (x3, SImode))
    {
      recog_data.operand[1] = x3;
      goto L4899;
    }
  x3 = XEXP (x2, 0);
  goto L4906;

 L4899: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4900;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4906;

 L4900: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10419 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_515 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4906;

 L4907: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4908;
  goto L4910;

 L4908: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4909;
  goto L4910;

 L4909: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && 
//#line 10433 "../../gcc/config/i386/i386.md"
(optimize_insn_for_speed_p () && ! TARGET_READ_MODIFY))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_516 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4910;

 L4911: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L4912;
  goto L4933;

 L4912: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4913;
    }
 L4924: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L4925;
    }
  goto L4933;

 L4913: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SImode))
    {
      recog_data.operand[1] = x1;
      goto L4914;
    }
  x1 = XEXP (x0, 0);
  goto L4924;

 L4914: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == PARALLEL
      && XVECLEN (x1, 0) == 2)
    goto L4915;
  x1 = XEXP (x0, 0);
  goto L4924;

 L4915: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == SET)
    goto L4916;
  x1 = XEXP (x0, 0);
  goto L4924;

 L4916: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4917;
  x1 = XEXP (x0, 0);
  goto L4924;

 L4917: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (commutative_operator (x3, SImode))
    {
      recog_data.operand[3] = x3;
      goto L4918;
    }
  x1 = XEXP (x0, 0);
  goto L4924;

 L4918: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, recog_data.operand[0]))
    goto L4919;
  x1 = XEXP (x0, 0);
  goto L4924;

 L4919: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (memory_operand (x4, SImode))
    {
      recog_data.operand[2] = x4;
      goto L4920;
    }
  x1 = XEXP (x0, 0);
  goto L4924;

 L4920: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) == CLOBBER)
    goto L4921;
  x1 = XEXP (x0, 0);
  goto L4924;

 L4921: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CCmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 17
      && 
//#line 10451 "../../gcc/config/i386/i386.md"
(REGNO (recog_data.operand[0]) != REGNO (recog_data.operand[1])
   && GENERAL_REGNO_P (REGNO (recog_data.operand[0]))
   && GENERAL_REGNO_P (REGNO (recog_data.operand[1]))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_517 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L4924;

 L4925: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, VOIDmode))
    {
      recog_data.operand[1] = x1;
      goto L4926;
    }
  goto L4933;

 L4926: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4927;
  goto L4933;

 L4927: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L4928;
  goto L4933;

 L4928: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (commutative_operator (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L4929;
    }
  goto L4933;

 L4929: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, recog_data.operand[0]))
    goto L4930;
  goto L4933;

 L4930: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (memory_operand (x3, VOIDmode))
    {
      recog_data.operand[2] = x3;
      goto L4931;
    }
  goto L4933;

 L4931: ATTRIBUTE_UNUSED_LABEL
  if (
//#line 10467 "../../gcc/config/i386/i386.md"
(REGNO (recog_data.operand[0]) != REGNO (recog_data.operand[1])
   && ((MMX_REG_P (recog_data.operand[0]) && MMX_REG_P (recog_data.operand[1])) 
       || (SSE_REG_P (recog_data.operand[0]) && SSE_REG_P (recog_data.operand[1])))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_518 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto L4933;

 L5824: ATTRIBUTE_UNUSED_LABEL
  return peephole2_1 (x0, insn, _pmatch_len);

 L4973: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5896;
    case DImode:
      goto L5897;
    default:
      break;
    }
 L5108: ATTRIBUTE_UNUSED_LABEL
  if (flags_reg_operand (x1, VOIDmode))
    {
      recog_data.operand[0] = x1;
      goto L5109;
    }
  goto ret0;

 L5896: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      recog_data.operand[0] = x1;
      goto L4974;
    }
  goto L5108;

 L4974: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L5898;
  x1 = XEXP (x0, 0);
  goto L5108;

 L5898: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SUBREG:
      goto L5900;
    case MULT:
      goto L4983;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L5108;

 L5900: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L4975;
  x1 = XEXP (x0, 0);
  goto L5108;

 L4975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L5901;
  x1 = XEXP (x0, 0);
  goto L5108;

 L5901: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L4976;
    case MULT:
      goto L4998;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4976: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4977;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4977: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L4978;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4978: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10568 "../../gcc/config/i386/i386.md"
(peep2_regno_dead_p (0, FLAGS_REG) && REGNO (recog_data.operand[0]) == REGNO (recog_data.operand[1])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_525 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4998: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      recog_data.operand[1] = x3;
      goto L4999;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4999: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, DImode))
    {
      recog_data.operand[2] = x3;
      goto L5000;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L5000: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10597 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (recog_data.operand[2])) >= 0
   && REGNO (recog_data.operand[0]) == REGNO (recog_data.operand[1])
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_528 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L4984;
  x1 = XEXP (x0, 0);
  goto L5108;

 L4984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      recog_data.operand[1] = x2;
      goto L4985;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4985: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10577 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (recog_data.operand[1])) >= 0
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_526 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L5897: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      recog_data.operand[0] = x1;
      goto L4989;
    }
  goto L5108;

 L4989: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == MULT)
    goto L4990;
  x1 = XEXP (x0, 0);
  goto L5108;

 L4990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, recog_data.operand[0]))
    goto L4991;
  x1 = XEXP (x0, 0);
  goto L5108;

 L4991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      recog_data.operand[1] = x2;
      goto L4992;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L4992: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10587 "../../gcc/config/i386/i386.md"
(exact_log2 (INTVAL (recog_data.operand[1])) >= 0
   && peep2_regno_dead_p (0, FLAGS_REG)))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_527 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 0);
  goto L5108;

 L5109: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (compare_operator (x1, VOIDmode))
    {
      recog_data.operand[1] = x1;
      goto L5110;
    }
  goto ret0;

 L5110: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      recog_data.operand[2] = x2;
      goto L5111;
    }
  goto ret0;

 L5111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, VOIDmode))
    {
      recog_data.operand[3] = x2;
      goto L5112;
    }
  goto ret0;

 L5112: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
//#line 10745 "../../gcc/config/i386/i386.md"
((((!TARGET_FUSE_CMP_AND_BRANCH || optimize_insn_for_size_p ())
     && incdec_operand (recog_data.operand[3], GET_MODE (recog_data.operand[3])))
    || (!TARGET_FUSE_CMP_AND_BRANCH
	&& INTVAL (recog_data.operand[3]) == 128))
   && ix86_match_ccmode (insn, CCGCmode)
   && peep2_reg_dead_p (1, recog_data.operand[2])))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_539 (insn, recog_data.operand);
      if (tem != 0)
        return tem;
    }
  goto ret0;
 ret0:
  return 0;
}

#endif
