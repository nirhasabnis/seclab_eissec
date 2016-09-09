/*
 * tstrlen.c
 * tstrlen, x86 implementation
 *
 * Copyright (c) 2009-2011 Jan Seiffert
 *
 * This file is part of g2cd.
 *
 * g2cd is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * g2cd is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with g2cd.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id: $
 */

/*
 * Intel has a good feeling how to create incomplete and
 * unsymetric instruction sets, so sometimes there is a
 * last "missing link".
 * Hammering on multiple integers was to be implemented with
 * MMX, but SSE finaly brought usefull comparison, but not
 * for 128 Bit SSE datatypes, only the old 64 Bit MMX...
 * SSE2 finaly brought fun for 128Bit.
 *
 * I would have a pure MMX version, but it is slower than the
 * generic version (58000ms vs. 54000ms), MMX was a really
 * braindead idea without a MMX->CPU-Reg move instruction
 * to do things not possible with MMX.
 */
/*
 * Sometimes you need a new perspective, like the altivec
 * way of handling things.
 * Lower address bits? Totaly overestimated.
 *
 * We don't precheck for alignment, 16 or 8 is very unlikely
 * instead we "align hard", do one load "under the address",
 * mask the excess info out and afterwards we are fine to go.
 */
/*
 * Normaly we could generate this with the gcc vector
 * __builtins, but since gcc whines when the -march does
 * not support the operation and we want to always provide
 * them and switch between them...
 * And near by, sorry gcc, your bsf handling sucks.
 * bsf generates flags, no need to test beforehand,
 * but AFTERWARDS!!!
 * But bsf can be slow, and thanks to the _new_ Atom, which
 * again needs 17 clock cycles, the P4 also isn't very
 * glorious...
 * On the other hand, the bsf HAS to happen at some point.
 * Since most strings are short, the first is a hit, and
 * we can save all the other handling, jumping, etc.
 * I think i measured that at one point...
 * Hmmm, but not on the offenders...
 */

//#include "x86_features.h"
//

#include <unistd.h>
#include <sys/types.h>

#define tchar_t char

#define SOV32	32
#define SOV16	16
#define SOV8	8

#define HAVE_BINUTILS 224

#ifdef HAVE_BINUTILS
# if HAVE_BINUTILS >= 222
static size_t tstrlen_AVX2(const tchar_t *s)
{
	size_t len;
	const tchar_t *p;
	asm volatile ("prefetcht0 (%0)" : : "r" (s));
	asm (
		"vpxor	%%ymm1, %%ymm1, %%ymm1\n\t"
		"vmovdqa	(%1), %%ymm0\n\t"
		"vpcmpeqw	%%ymm0, %%ymm1, %%ymm0\n\t"
		"vpmovmskb	%%ymm0, %0\n\t"
		"shr	%b3, %0\n\t"
		"bsf	%0, %0\n\t"
		"jnz	2f\n\t"
		".p2align 1\n"
		"1:\n\t"
		"vmovdqa	32(%1), %%ymm0\n\t"
		"add	$32, %1\n\t"
		"prefetcht0	64(%1)\n\t"
		"vpcmpeqw	%%ymm0, %%ymm1, %%ymm0\n\t"
		"vptest	%%ymm0, %%ymm1\n\t"
		"jc	1b\n\t"
		"vpmovmskb	%%ymm0, %0\n\t"
		"bsf	%0, %0\n\t"
		"add	%1, %0\n\t"
		"sub	%2, %0\n\t"
		"2:"
		: /* %0 */ "=&r" (len),
		  /* %1 */ "=&r" (p)
#  ifdef __i386__
		: /* %2 */ "m" (s),
#  else
		: /* %2 */ "r" (s),
#  endif
		  /* %3 */ "c" (ALIGN_DOWN_DIFF(s, SOV32)),
		  /* %4 */ "1" (ALIGN_DOWN(s, SOV32))
#  ifdef __AVX__
		: "ymm0", "ymm1"
#  elif defined(__SSE__)
		: "xmm0", "xmm1"
#  endif
	);
	return len / sizeof(tchar_t);
}
# endif

# if 0
# if HAVE_BINUTILS >= 218
static size_t tstrlen_SSE42(const tchar_t *s)
{
	size_t len, t;
	const tchar_t *p;
	asm volatile ("prefetcht0 (%0)" : : "r" (s));
	/*
	 * even if nehalem can handle unaligned load much better
	 * (so they promised), we still align hard to get in
	 * swing with the page boundery.
	 */
	asm (
		"pxor	%%xmm0, %%xmm0\n\t"
		"movdqa	(%1), %%xmm1\n\t"
		"pcmpeqw	%%xmm0, %%xmm1\n\t"
		"pmovmskb	%%xmm1, %0\n\t"
		"shr	%b2, %0\n\t"
		"bsf	%0, %0\n\t"
		"jnz	2f\n\t"
		"mov	$0xFFFF0001, %k0\n\t"
		"movd	%k0, %%xmm0\n\t"
		".p2align 1\n"
		"1:\n\t"
		"add	$16, %1\n\t"
		"prefetcht0	64(%1)\n\t"
		/* LSB,Invert,Range,Words */
		/*             6543210 */
		"pcmpistri	$0b0010101, (%1), %%xmm0\n\t"
		"jnz	1b\n\t"
		"lea	(%1,%2,2),%0\n\t"
		"sub	%3, %0\n"
		"2:"
		: /* %0 */ "=&r" (len),
		  /* %1 */ "=&r" (p),
		  /* %2 */ "=&c" (t)
#  ifdef __i386__
		: /* %3 */ "m" (s),
#  else
		: /* %3 */ "r" (s),
#  endif
		  /* %4 */ "2" (ALIGN_DOWN_DIFF(s, SOV16)),
		  /* %5 */ "1" (ALIGN_DOWN(s, SOV16))
#  ifdef __SSE2__
		: "xmm0", "xmm1"
#  endif
	);
	return len/sizeof(tchar_t);
}
# endif
#endif

static size_t tstrlen_SSE2(const tchar_t *s)
{
	size_t len;
	const tchar_t *p;
	asm volatile ("prefetcht0 (%0)" : : "r" (s));
	asm (
		"pxor	%%xmm1, %%xmm1\n\t"
		"movdqa	(%1), %%xmm0\n\t"
		"pcmpeqw	%%xmm1, %%xmm0\n\t"
		"pmovmskb	%%xmm0, %0\n\t"
		"shr	%b3, %0\n\t"
		"bsf	%0, %0\n\t"
		"jnz	2f\n\t"
		".p2align 1\n"
		"1:\n\t"
		"movdqa	16(%1), %%xmm0\n\t"
		"add	$16, %1\n\t"
		"prefetcht0	64(%1)\n\t"
		"pcmpeqw	%%xmm1, %%xmm0\n\t"
		"pmovmskb	%%xmm0, %0\n\t"
		"test	%0, %0\n\t"
		"jz	1b\n\t"
		"bsf	%0, %0\n\t"
		"add	%1, %0\n\t"
		"sub	%2, %0\n\t"
		"2:"
		: /* %0 */ "=&r" (len),
		  /* %1 */ "=&r" (p)
#ifdef __i386__
		: /* %2 */ "m" (s),
#else
		: /* %2 */ "r" (s),
#endif
		  /* %3 */ "c" (ALIGN_DOWN_DIFF(s, SOV16)),
		  /* %4 */ "1" (ALIGN_DOWN(s, SOV16))
#ifdef __SSE2__
		: "xmm0", "xmm1"
#endif
	);
	return len / sizeof(tchar_t);
}

#ifndef __x86_64__
static size_t tstrlen_SSE(const tchar_t *s)
{
	size_t len;
	const tchar_t *p;
	asm volatile ("prefetcht0 (%0)" : : "r" (s));
	asm (
		"pxor	%%mm1, %%mm1\n\t"
		"movq	(%1), %%mm0\n\t"
		"pcmpeqw	%%mm1, %%mm0\n\t"
		"pmovmskb	%%mm0, %0\n\t"
		"shr	%b3, %0\n\t"
		"bsf	%0, %0\n\t"
		"jnz	2f\n\t"
		".p2align 1\n"
		"1:\n\t"
		"movq	8(%1), %%mm0\n\t"
		"add	$8, %1\n\t"
		"prefetcht0	64(%1)\n\t"
		"pcmpeqw	%%mm1, %%mm0\n\t"
		"pmovmskb	%%mm0, %0\n\t"
		"test	%0, %0\n\t"
		"jz	1b\n\t"
		"bsf	%0, %0\n\t"
		"add	%1, %0\n\t"
		"sub	%2, %0\n\t"
		"2:\n\t"
		: /* %0 */ "=&r" (len),
		  /* %1 */ "=r" (p)
		: /* %2 */ "m" (s),
		  /* %3 */ "c" (ALIGN_DOWN_DIFF(s, SOV8)),
		  /* %4 */ "1" (ALIGN_DOWN(s, SOV8))
#ifdef __SSE__
		: "mm0", "mm1"
#endif
	);
	return len / sizeof(tchar_t);
}
#endif

static size_t tstrlen_x86(const tchar_t *s)
{
	const tchar_t *p;
	size_t t, len;
	asm (
#ifndef __x86_64__
		"push	%2\n\t"
#endif
		"mov	(%1), %2\n\t"
#ifndef __x86_64__
		"lea	-0x10001(%2),%0\n\t"
#else
		"mov	%2, %0\n\t"
		"add	%8, %0\n\t"
#endif
		"not	%2\n\t"
		"and	%2, %0\n\t"
#ifndef __x86_64__
		"pop	%2\n\t"
#endif
		"and	%7, %0\n\t"
		"shr	%b5, %0\n\t"
		"shl	%b5, %0\n\t"
		"test	%0, %0\n\t"
		"jnz	2f\n\t"
		".p2align 1\n"
		"1:\n\t"
		"add	%4, %1\n\t"
		"mov	(%1), %2\n\t"
#ifndef __x86_64__
		"lea	-0x10001(%2),%0\n\t"
#else
		"mov	%2, %0\n\t"
		"add	%8, %0\n\t"
#endif
		"not	%2\n\t"
		"and	%2, %0\n\t"
		"and	%7, %0\n\t"
		"jz	1b\n"
		"2:\n\t"
		"bsf	%0, %0\n\t"
		"shr	$3, %0\n\t"
		"add	%1, %0\n\t"
		"sub	%6, %0"
	: /* %0 */ "=&a" (len),
	  /* %1 */ "=&r" (p),
#ifndef __x86_64__
	  /* %2 */ "=c" (t)
#else
	  /* %2 */ "=&r" (t)
#endif
	: /* %3 */ "1" (ALIGN_DOWN(s, SOST)),
	  /* %4 */ "K" (SOST),
#ifndef __x86_64__
	  /* %5 */ "2" (ALIGN_DOWN_DIFF(s, SOST) * BITS_PER_CHAR),
	  /*
	   * 386 should keep it on stack to prevent
	   * register spill and a frame
	   */
	  /* %6 */ "m" (s),
	  /* %7 */ "e" (0x80008000)
#else
	  /*
	   * amd64 has more register and a regcall abi
	   * so keep in reg.
	   */
	  /* %5 */ "c" (ALIGN_DOWN_DIFF(s, SOST) * BITS_PER_CHAR),
	  /* %6 */ "r" (s),
	  /* %7 */ "r" ( 0x8000800080008000LL),
	  /* %8 */ "r" (-0x0001000100010001LL)
#endif
	);
	return len/sizeof(tchar_t);
}


static __init_cdata const struct test_cpu_feature tfeat_tstrlen[] =
{
#ifdef HAVE_BINUTILS
# if HAVE_BINUTILS >= 222
	{.func = (void (*)(void))tstrlen_AVX2,  .features = {[4] = CFB(CFEATURE_AVX2)} .flags = CFF_AVX_TST},
# endif
# if HAVE_BINUTILS >= 218
	{.func = (void (*)(void))tstrlen_SSE42, .features = {[1] = CFB(CFEATURE_SSE4_2)}},
# endif
#endif
	{.func = (void (*)(void))tstrlen_SSE2,  .features = {[0] = CFB(CFEATURE_SSE2)}},
#ifndef __x86_64__
	{.func = (void (*)(void))tstrlen_SSE,   .features = {[0] = CFB(CFEATURE_SSE)}},
	{.func = (void (*)(void))tstrlen_SSE,   .features = {[2] = CFB(CFEATURE_MMXEXT)}},
#endif
	{.func = (void (*)(void))tstrlen_x86,   .features = {}, .flags = CFF_DEFAULT},
};

DYN_JMP_DISPATCH(size_t, tstrlen, (const tchar_t *s), (s))

/*@unused@*/
static char const rcsid_tsl[] GCC_ATTR_USED_VAR = "$Id: $";

#endif
/* EOF */
