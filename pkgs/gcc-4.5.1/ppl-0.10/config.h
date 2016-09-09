/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


/* Unique (nonzero) code for the IEEE 754 Single Precision
   floating point format.  */
# define PPL_FLOAT_IEEE754_SINGLE 1

/* Unique (nonzero) code for the IEEE 754 Double Precision
   floating point format.  */
# define PPL_FLOAT_IEEE754_DOUBLE 2

/* Unique (nonzero) code for the IEEE 754 Quad Precision
   floating point format.  */
# define PPL_FLOAT_IEEE754_QUAD 3

/* Unique (nonzero) code for the Intel Double-Extended
   floating point format.  */
# define PPL_FLOAT_INTEL_DOUBLE_EXTENDED 4


/* ABI-breaking extra assertions are enabled when this is defined. */
/* #undef ABI_BREAKING_EXTRA_DEBUG */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Not zero if the FPU can be controlled. */
#define CAN_CONTROL_FPU 1

/* Defined if the integral type to be used for coefficients is a checked one.
   */
/* #undef CHECKED_INTEGERS */

/* The number of bits of coefficients; 0 if unbounded. */
#define COEFFICIENT_BITS 0

/* The integral type used to represent coefficients. */
#define COEFFICIENT_TYPE mpz_class

/* This contains the options with which `configure' was invoked. */
#define CONFIGURE_OPTIONS " '--prefix=/media/work_stonybrook/labwork/gcc-4.5.1/ppl-0.10/installdir'"

/* The unique code of the binary format of C++ doubles, if supported;
   undefined otherwise. */
#define CXX_DOUBLE_BINARY_FORMAT PPL_FLOAT_IEEE754_DOUBLE

/* Not zero if C++ supports exact output for doubles. */
#define CXX_DOUBLE_EXACT_OUTPUT 1

/* The binary format of C++ floats, if supported; undefined otherwise. */
#define CXX_FLOAT_BINARY_FORMAT PPL_FLOAT_IEEE754_SINGLE

/* Not zero if C++ supports exact output for floats. */
#define CXX_FLOAT_EXACT_OUTPUT 1

/* Not zero if the C++ compiler has the remainder bug. */
#define CXX_HAS_REMAINDER_BUG 1

/* The unique code of the binary format of C++ long doubles, if supported;
   undefined otherwise. */
#define CXX_LONG_DOUBLE_BINARY_FORMAT PPL_FLOAT_INTEL_DOUBLE_EXTENDED

/* Not zero if C++ supports exact output for long doubles. */
#define CXX_LONG_DOUBLE_EXACT_OUTPUT 1

/* Not zero if the C++ compiler provides long double numbers that have bigger
   range or precision than double. */
#define CXX_PROVIDES_PROPER_LONG_DOUBLE 1

/* Not zero if the C++ compiler supports __attribute__ ((weak)). */
#define CXX_SUPPORTS_ATTRIBUTE_WEAK 1

/* Not zero if the C++ compiler supports flexible arrays. */
#define CXX_SUPPORTS_FLEXIBLE_ARRAYS 1

/* Not zero if the the IEEE inexact flag is supported in C++. */
#define CXX_SUPPORTS_IEEE_INEXACT_FLAG 1

/* Not zero if it is possible to limit memory using setrlimit(). */
#define CXX_SUPPORTS_LIMITING_MEMORY 1

/* Defined if floating point arithmetics may use the 387 unit. */
#define FPMATH_MAY_USE_387 1

/* Defined if floating point arithmetics may use the SSE instruction set. */
#define FPMATH_MAY_USE_SSE 1

/* Defined if GLPK provides glp_term_hook(). */
/* #undef GLPK_HAS_GLP_TERM_HOOK */

/* Defined if GLPK provides glp_term_out(). */
/* #undef GLPK_HAS_GLP_TERM_OUT */

/* Defined if GLPK provides lib_set_print_hook(). */
/* #undef GLPK_HAS_LIB_SET_PRINT_HOOK */

/* Defined if GLPK provides _glp_lib_print_hook(). */
/* #undef GLPK_HAS__GLP_LIB_PRINT_HOOK */

/* Defined if the integral type to be used for coefficients is GMP's one. */
#define GMP_INTEGERS 1

/* Not zero if GMP has been compiled with support for exceptions. */
#define GMP_SUPPORTS_EXCEPTIONS 0

/* Define to 1 if you have the declaration of `ffs', and to 0 if you don't. */
#define HAVE_DECL_FFS 1

/* Define to 1 if you have the declaration of `fma', and to 0 if you don't. */
#define HAVE_DECL_FMA 1

/* Define to 1 if you have the declaration of `fmaf', and to 0 if you don't.
   */
#define HAVE_DECL_FMAF 1

/* Define to 1 if you have the declaration of `fmal', and to 0 if you don't.
   */
#define HAVE_DECL_FMAL 1

/* Define to 1 if you have the declaration of `getenv', and to 0 if you don't.
   */
#define HAVE_DECL_GETENV 1

/* Define to 1 if you have the declaration of `getrusage', and to 0 if you
   don't. */
#define HAVE_DECL_GETRUSAGE 1

/* Define to 1 if you have the declaration of `rintf', and to 0 if you don't.
   */
#define HAVE_DECL_RINTF 1

/* Define to 1 if you have the declaration of `rintl', and to 0 if you don't.
   */
#define HAVE_DECL_RINTL 1

/* Define to 1 if you have the declaration of `RLIMIT_AS', and to 0 if you
   don't. */
#define HAVE_DECL_RLIMIT_AS 1

/* Define to 1 if you have the declaration of `RLIMIT_DATA', and to 0 if you
   don't. */
#define HAVE_DECL_RLIMIT_DATA 1

/* Define to 1 if you have the declaration of `RLIMIT_RSS', and to 0 if you
   don't. */
#define HAVE_DECL_RLIMIT_RSS 1

/* Define to 1 if you have the declaration of `RLIMIT_VMEM', and to 0 if you
   don't. */
#define HAVE_DECL_RLIMIT_VMEM 0

/* Define to 1 if you have the declaration of `strtod', and to 0 if you don't.
   */
#define HAVE_DECL_STRTOD 1

/* Define to 1 if you have the declaration of `strtof', and to 0 if you don't.
   */
#define HAVE_DECL_STRTOF 1

/* Define to 1 if you have the declaration of `strtold', and to 0 if you
   don't. */
#define HAVE_DECL_STRTOLD 1

/* Define to 1 if you have the declaration of `strtoll', and to 0 if you
   don't. */
#define HAVE_DECL_STRTOLL 1

/* Define to 1 if you have the declaration of `strtoull', and to 0 if you
   don't. */
#define HAVE_DECL_STRTOULL 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <fenv.h> header file. */
#define HAVE_FENV_H 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the <glpk/glpk.h> header file. */
/* #undef HAVE_GLPK_GLPK_H */

/* Define to 1 if you have the <glpk.h> header file. */
/* #undef HAVE_GLPK_H */

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if the system has the type `int_fast16_t'. */
#define HAVE_INT_FAST16_T 1

/* Define to 1 if the system has the type `int_fast32_t'. */
#define HAVE_INT_FAST32_T 1

/* Define to 1 if the system has the type `int_fast64_t'. */
#define HAVE_INT_FAST64_T 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `timeval'. */
#define HAVE_TIMEVAL 1

/* Define to 1 if typeof works with your compiler. */
#define HAVE_TYPEOF 1

/* Define to 1 if the system has the type `uint_fast16_t'. */
#define HAVE_UINT_FAST16_T 1

/* Define to 1 if the system has the type `uint_fast32_t'. */
#define HAVE_UINT_FAST32_T 1

/* Define to 1 if the system has the type `uint_fast64_t'. */
#define HAVE_UINT_FAST64_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if `_mp_alloc' is member of `__mpz_struct'. */
#define HAVE___MPZ_STRUCT__MP_ALLOC 1

/* Define to 1 if `_mp_d' is member of `__mpz_struct'. */
#define HAVE___MPZ_STRUCT__MP_D 1

/* Define to 1 if `_mp_size' is member of `__mpz_struct'. */
#define HAVE___MPZ_STRUCT__MP_SIZE 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Defined if the integral type to be used for coefficients is a native one.
   */
/* #undef NATIVE_INTEGERS */

/* Assertions are disabled when this is defined. */
#define NDEBUG 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "ppl-devel@cs.unipr.it"

/* Define to the full name of this package. */
#define PACKAGE_NAME "the Parma Polyhedra Library"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "the Parma Polyhedra Library 0.10"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ppl"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.10"

/* The size of `char', as computed by sizeof. */
#define SIZEOF_CHAR 1

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of `fp', as computed by sizeof. */
#define SIZEOF_FP 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `int*', as computed by sizeof. */
#define SIZEOF_INTP 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `long double', as computed by sizeof. */
#define SIZEOF_LONG_DOUBLE 12

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `mp_limb_t', as computed by sizeof. */
#define SIZEOF_MP_LIMB_T 4

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 4

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Not zero if doubles are supported. */
#define SUPPORTED_DOUBLE 1

/* Not zero if floats are supported. */
#define SUPPORTED_FLOAT 1

/* Not zero if long doubles are supported. */
#define SUPPORTED_LONG_DOUBLE 1

/* Defined if the Parma Watchdog Library is enabled. */
#define WATCHDOG_LIBRARY_ENABLED 1

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* When defined and libstdc++ is used, it is used in debug mode. */
/* #undef _GLIBCXX_DEBUG */

/* When defined and libstdc++ is used, it is used in pedantic debug mode. */
/* #undef _GLIBCXX_DEBUG_PEDANTIC */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to __typeof__ if your compiler spells it that way. */
/* #undef typeof */


#ifdef PPL_NDEBUG
# define NDEBUG 1
#endif

/* In order for the definition of `int64_t' to be seen by Comeau C/C++,
   we must make sure <stdint.h> is included before <sys/types.hh> is
   (even indirectly) included.  Moreover we need to define
   __STDC_LIMIT_MACROS before the first inclusion of <stdint.h>
   in order to have the macros defined also in C++.  */

#ifdef PPL_HAVE_STDINT_H
# ifndef __STDC_LIMIT_MACROS
#  define __STDC_LIMIT_MACROS 1
# endif
# include <stdint.h>
#endif

#ifdef PPL_HAVE_INTTYPES_H
# include <inttypes.h>
#endif

