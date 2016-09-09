#ifndef _PPL_CONFIG_H
#define _PPL_CONFIG_H 1
 
/* ppl-config.h. Generated automatically at end of configure. */
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
/* #undef PPL_ABI_BREAKING_EXTRA_DEBUG */

/* Define if building universal (internal helper macro) */
/* #undef PPL_AC_APPLE_UNIVERSAL_BUILD */

/* Not zero if the FPU can be controlled. */
#ifndef PPL_CAN_CONTROL_FPU 
#define PPL_CAN_CONTROL_FPU  1 
#endif

/* Defined if the integral type to be used for coefficients is a checked one.
   */
/* #undef PPL_CHECKED_INTEGERS */

/* The number of bits of coefficients; 0 if unbounded. */
#ifndef PPL_COEFFICIENT_BITS 
#define PPL_COEFFICIENT_BITS  0 
#endif

/* The integral type used to represent coefficients. */
#ifndef PPL_COEFFICIENT_TYPE 
#define PPL_COEFFICIENT_TYPE  mpz_class 
#endif

/* This contains the options with which `configure' was invoked. */
#ifndef PPL_CONFIGURE_OPTIONS 
#define PPL_CONFIGURE_OPTIONS  " '--prefix=/media/work_stonybrook/labwork/gcc-4.5.1/ppl-0.10/installdir'" 
#endif

/* The unique code of the binary format of C++ doubles, if supported;
   undefined otherwise. */
#ifndef PPL_CXX_DOUBLE_BINARY_FORMAT 
#define PPL_CXX_DOUBLE_BINARY_FORMAT  PPL_FLOAT_IEEE754_DOUBLE 
#endif

/* Not zero if C++ supports exact output for doubles. */
#ifndef PPL_CXX_DOUBLE_EXACT_OUTPUT 
#define PPL_CXX_DOUBLE_EXACT_OUTPUT  1 
#endif

/* The binary format of C++ floats, if supported; undefined otherwise. */
#ifndef PPL_CXX_FLOAT_BINARY_FORMAT 
#define PPL_CXX_FLOAT_BINARY_FORMAT  PPL_FLOAT_IEEE754_SINGLE 
#endif

/* Not zero if C++ supports exact output for floats. */
#ifndef PPL_CXX_FLOAT_EXACT_OUTPUT 
#define PPL_CXX_FLOAT_EXACT_OUTPUT  1 
#endif

/* Not zero if the C++ compiler has the remainder bug. */
#ifndef PPL_CXX_HAS_REMAINDER_BUG 
#define PPL_CXX_HAS_REMAINDER_BUG  1 
#endif

/* The unique code of the binary format of C++ long doubles, if supported;
   undefined otherwise. */
#ifndef PPL_CXX_LONG_DOUBLE_BINARY_FORMAT 
#define PPL_CXX_LONG_DOUBLE_BINARY_FORMAT  PPL_FLOAT_INTEL_DOUBLE_EXTENDED 
#endif

/* Not zero if C++ supports exact output for long doubles. */
#ifndef PPL_CXX_LONG_DOUBLE_EXACT_OUTPUT 
#define PPL_CXX_LONG_DOUBLE_EXACT_OUTPUT  1 
#endif

/* Not zero if the C++ compiler provides long double numbers that have bigger
   range or precision than double. */
#ifndef PPL_CXX_PROVIDES_PROPER_LONG_DOUBLE 
#define PPL_CXX_PROVIDES_PROPER_LONG_DOUBLE  1 
#endif

/* Not zero if the C++ compiler supports __attribute__ ((weak)). */
#ifndef PPL_CXX_SUPPORTS_ATTRIBUTE_WEAK 
#define PPL_CXX_SUPPORTS_ATTRIBUTE_WEAK  1 
#endif

/* Not zero if the C++ compiler supports flexible arrays. */
#ifndef PPL_CXX_SUPPORTS_FLEXIBLE_ARRAYS 
#define PPL_CXX_SUPPORTS_FLEXIBLE_ARRAYS  1 
#endif

/* Not zero if the the IEEE inexact flag is supported in C++. */
#ifndef PPL_CXX_SUPPORTS_IEEE_INEXACT_FLAG 
#define PPL_CXX_SUPPORTS_IEEE_INEXACT_FLAG  1 
#endif

/* Not zero if it is possible to limit memory using setrlimit(). */
#ifndef PPL_CXX_SUPPORTS_LIMITING_MEMORY 
#define PPL_CXX_SUPPORTS_LIMITING_MEMORY  1 
#endif

/* Defined if floating point arithmetics may use the 387 unit. */
#ifndef PPL_FPMATH_MAY_USE_387 
#define PPL_FPMATH_MAY_USE_387  1 
#endif

/* Defined if floating point arithmetics may use the SSE instruction set. */
#ifndef PPL_FPMATH_MAY_USE_SSE 
#define PPL_FPMATH_MAY_USE_SSE  1 
#endif

/* Defined if GLPK provides glp_term_hook(). */
/* #undef PPL_GLPK_HAS_GLP_TERM_HOOK */

/* Defined if GLPK provides glp_term_out(). */
/* #undef PPL_GLPK_HAS_GLP_TERM_OUT */

/* Defined if GLPK provides lib_set_print_hook(). */
/* #undef PPL_GLPK_HAS_LIB_SET_PRINT_HOOK */

/* Defined if GLPK provides _glp_lib_print_hook(). */
/* #undef PPL_GLPK_HAS__GLP_LIB_PRINT_HOOK */

/* Defined if the integral type to be used for coefficients is GMP's one. */
#ifndef PPL_GMP_INTEGERS 
#define PPL_GMP_INTEGERS  1 
#endif

/* Not zero if GMP has been compiled with support for exceptions. */
#ifndef PPL_GMP_SUPPORTS_EXCEPTIONS 
#define PPL_GMP_SUPPORTS_EXCEPTIONS  0 
#endif

/* Define to 1 if you have the declaration of `ffs', and to 0 if you don't. */
#ifndef PPL_HAVE_DECL_FFS 
#define PPL_HAVE_DECL_FFS  1 
#endif

/* Define to 1 if you have the declaration of `fma', and to 0 if you don't. */
#ifndef PPL_HAVE_DECL_FMA 
#define PPL_HAVE_DECL_FMA  1 
#endif

/* Define to 1 if you have the declaration of `fmaf', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_FMAF 
#define PPL_HAVE_DECL_FMAF  1 
#endif

/* Define to 1 if you have the declaration of `fmal', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_FMAL 
#define PPL_HAVE_DECL_FMAL  1 
#endif

/* Define to 1 if you have the declaration of `getenv', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_GETENV 
#define PPL_HAVE_DECL_GETENV  1 
#endif

/* Define to 1 if you have the declaration of `getrusage', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_GETRUSAGE 
#define PPL_HAVE_DECL_GETRUSAGE  1 
#endif

/* Define to 1 if you have the declaration of `rintf', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_RINTF 
#define PPL_HAVE_DECL_RINTF  1 
#endif

/* Define to 1 if you have the declaration of `rintl', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_RINTL 
#define PPL_HAVE_DECL_RINTL  1 
#endif

/* Define to 1 if you have the declaration of `RLIMIT_AS', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_RLIMIT_AS 
#define PPL_HAVE_DECL_RLIMIT_AS  1 
#endif

/* Define to 1 if you have the declaration of `RLIMIT_DATA', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_RLIMIT_DATA 
#define PPL_HAVE_DECL_RLIMIT_DATA  1 
#endif

/* Define to 1 if you have the declaration of `RLIMIT_RSS', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_RLIMIT_RSS 
#define PPL_HAVE_DECL_RLIMIT_RSS  1 
#endif

/* Define to 1 if you have the declaration of `RLIMIT_VMEM', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_RLIMIT_VMEM 
#define PPL_HAVE_DECL_RLIMIT_VMEM  0 
#endif

/* Define to 1 if you have the declaration of `strtod', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_STRTOD 
#define PPL_HAVE_DECL_STRTOD  1 
#endif

/* Define to 1 if you have the declaration of `strtof', and to 0 if you don't.
   */
#ifndef PPL_HAVE_DECL_STRTOF 
#define PPL_HAVE_DECL_STRTOF  1 
#endif

/* Define to 1 if you have the declaration of `strtold', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_STRTOLD 
#define PPL_HAVE_DECL_STRTOLD  1 
#endif

/* Define to 1 if you have the declaration of `strtoll', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_STRTOLL 
#define PPL_HAVE_DECL_STRTOLL  1 
#endif

/* Define to 1 if you have the declaration of `strtoull', and to 0 if you
   don't. */
#ifndef PPL_HAVE_DECL_STRTOULL 
#define PPL_HAVE_DECL_STRTOULL  1 
#endif

/* Define to 1 if you have the <dlfcn.h> header file. */
#ifndef PPL_HAVE_DLFCN_H 
#define PPL_HAVE_DLFCN_H  1 
#endif

/* Define to 1 if you have the <fenv.h> header file. */
#ifndef PPL_HAVE_FENV_H 
#define PPL_HAVE_FENV_H  1 
#endif

/* Define to 1 if you have the <getopt.h> header file. */
#ifndef PPL_HAVE_GETOPT_H 
#define PPL_HAVE_GETOPT_H  1 
#endif

/* Define to 1 if you have the <glpk/glpk.h> header file. */
/* #undef PPL_HAVE_GLPK_GLPK_H */

/* Define to 1 if you have the <glpk.h> header file. */
/* #undef PPL_HAVE_GLPK_H */

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef PPL_HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef PPL_HAVE_INTTYPES_H 
#define PPL_HAVE_INTTYPES_H  1 
#endif

/* Define to 1 if the system has the type `int_fast16_t'. */
#ifndef PPL_HAVE_INT_FAST16_T 
#define PPL_HAVE_INT_FAST16_T  1 
#endif

/* Define to 1 if the system has the type `int_fast32_t'. */
#ifndef PPL_HAVE_INT_FAST32_T 
#define PPL_HAVE_INT_FAST32_T  1 
#endif

/* Define to 1 if the system has the type `int_fast64_t'. */
#ifndef PPL_HAVE_INT_FAST64_T 
#define PPL_HAVE_INT_FAST64_T  1 
#endif

/* Define to 1 if you have the <memory.h> header file. */
#ifndef PPL_HAVE_MEMORY_H 
#define PPL_HAVE_MEMORY_H  1 
#endif

/* Define to 1 if you have the <signal.h> header file. */
#ifndef PPL_HAVE_SIGNAL_H 
#define PPL_HAVE_SIGNAL_H  1 
#endif

/* Define to 1 if you have the <stdint.h> header file. */
#ifndef PPL_HAVE_STDINT_H 
#define PPL_HAVE_STDINT_H  1 
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#ifndef PPL_HAVE_STDLIB_H 
#define PPL_HAVE_STDLIB_H  1 
#endif

/* Define to 1 if you have the <strings.h> header file. */
#ifndef PPL_HAVE_STRINGS_H 
#define PPL_HAVE_STRINGS_H  1 
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef PPL_HAVE_STRING_H 
#define PPL_HAVE_STRING_H  1 
#endif

/* Define to 1 if you have the <sys/resource.h> header file. */
#ifndef PPL_HAVE_SYS_RESOURCE_H 
#define PPL_HAVE_SYS_RESOURCE_H  1 
#endif

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef PPL_HAVE_SYS_STAT_H 
#define PPL_HAVE_SYS_STAT_H  1 
#endif

/* Define to 1 if you have the <sys/time.h> header file. */
#ifndef PPL_HAVE_SYS_TIME_H 
#define PPL_HAVE_SYS_TIME_H  1 
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef PPL_HAVE_SYS_TYPES_H 
#define PPL_HAVE_SYS_TYPES_H  1 
#endif

/* Define to 1 if the system has the type `timeval'. */
#ifndef PPL_HAVE_TIMEVAL 
#define PPL_HAVE_TIMEVAL  1 
#endif

/* Define to 1 if typeof works with your compiler. */
#ifndef PPL_HAVE_TYPEOF 
#define PPL_HAVE_TYPEOF  1 
#endif

/* Define to 1 if the system has the type `uint_fast16_t'. */
#ifndef PPL_HAVE_UINT_FAST16_T 
#define PPL_HAVE_UINT_FAST16_T  1 
#endif

/* Define to 1 if the system has the type `uint_fast32_t'. */
#ifndef PPL_HAVE_UINT_FAST32_T 
#define PPL_HAVE_UINT_FAST32_T  1 
#endif

/* Define to 1 if the system has the type `uint_fast64_t'. */
#ifndef PPL_HAVE_UINT_FAST64_T 
#define PPL_HAVE_UINT_FAST64_T  1 
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef PPL_HAVE_UNISTD_H 
#define PPL_HAVE_UNISTD_H  1 
#endif

/* Define to 1 if `_mp_alloc' is member of `__mpz_struct'. */
#ifndef PPL_HAVE___MPZ_STRUCT__MP_ALLOC 
#define PPL_HAVE___MPZ_STRUCT__MP_ALLOC  1 
#endif

/* Define to 1 if `_mp_d' is member of `__mpz_struct'. */
#ifndef PPL_HAVE___MPZ_STRUCT__MP_D 
#define PPL_HAVE___MPZ_STRUCT__MP_D  1 
#endif

/* Define to 1 if `_mp_size' is member of `__mpz_struct'. */
#ifndef PPL_HAVE___MPZ_STRUCT__MP_SIZE 
#define PPL_HAVE___MPZ_STRUCT__MP_SIZE  1 
#endif

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#ifndef PPL_LT_OBJDIR 
#define PPL_LT_OBJDIR  ".libs/" 
#endif

/* Defined if the integral type to be used for coefficients is a native one.
   */
/* #undef PPL_NATIVE_INTEGERS */

/* Assertions are disabled when this is defined. */
#ifndef PPL_NDEBUG 
#define PPL_NDEBUG  1 
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef PPL_PACKAGE_BUGREPORT 
#define PPL_PACKAGE_BUGREPORT  "ppl-devel@cs.unipr.it" 
#endif

/* Define to the full name of this package. */
#ifndef PPL_PACKAGE_NAME 
#define PPL_PACKAGE_NAME  "the Parma Polyhedra Library" 
#endif

/* Define to the full name and version of this package. */
#ifndef PPL_PACKAGE_STRING 
#define PPL_PACKAGE_STRING  "the Parma Polyhedra Library 0.10" 
#endif

/* Define to the one symbol short name of this package. */
#ifndef PPL_PACKAGE_TARNAME 
#define PPL_PACKAGE_TARNAME  "ppl" 
#endif

/* Define to the version of this package. */
#ifndef PPL_PACKAGE_VERSION 
#define PPL_PACKAGE_VERSION  "0.10" 
#endif

/* The size of `char', as computed by sizeof. */
#ifndef PPL_SIZEOF_CHAR 
#define PPL_SIZEOF_CHAR  1 
#endif

/* The size of `double', as computed by sizeof. */
#ifndef PPL_SIZEOF_DOUBLE 
#define PPL_SIZEOF_DOUBLE  8 
#endif

/* The size of `float', as computed by sizeof. */
#ifndef PPL_SIZEOF_FLOAT 
#define PPL_SIZEOF_FLOAT  4 
#endif

/* The size of `fp', as computed by sizeof. */
#ifndef PPL_SIZEOF_FP 
#define PPL_SIZEOF_FP  4 
#endif

/* The size of `int', as computed by sizeof. */
#ifndef PPL_SIZEOF_INT 
#define PPL_SIZEOF_INT  4 
#endif

/* The size of `int*', as computed by sizeof. */
#ifndef PPL_SIZEOF_INTP 
#define PPL_SIZEOF_INTP  4 
#endif

/* The size of `long', as computed by sizeof. */
#ifndef PPL_SIZEOF_LONG 
#define PPL_SIZEOF_LONG  4 
#endif

/* The size of `long double', as computed by sizeof. */
#ifndef PPL_SIZEOF_LONG_DOUBLE 
#define PPL_SIZEOF_LONG_DOUBLE  12 
#endif

/* The size of `long long', as computed by sizeof. */
#ifndef PPL_SIZEOF_LONG_LONG 
#define PPL_SIZEOF_LONG_LONG  8 
#endif

/* The size of `mp_limb_t', as computed by sizeof. */
#ifndef PPL_SIZEOF_MP_LIMB_T 
#define PPL_SIZEOF_MP_LIMB_T  4 
#endif

/* The size of `short', as computed by sizeof. */
#ifndef PPL_SIZEOF_SHORT 
#define PPL_SIZEOF_SHORT  2 
#endif

/* The size of `size_t', as computed by sizeof. */
#ifndef PPL_SIZEOF_SIZE_T 
#define PPL_SIZEOF_SIZE_T  4 
#endif

/* Define to 1 if you have the ANSI C header files. */
#ifndef PPL_STDC_HEADERS 
#define PPL_STDC_HEADERS  1 
#endif

/* Not zero if doubles are supported. */
#ifndef PPL_SUPPORTED_DOUBLE 
#define PPL_SUPPORTED_DOUBLE  1 
#endif

/* Not zero if floats are supported. */
#ifndef PPL_SUPPORTED_FLOAT 
#define PPL_SUPPORTED_FLOAT  1 
#endif

/* Not zero if long doubles are supported. */
#ifndef PPL_SUPPORTED_LONG_DOUBLE 
#define PPL_SUPPORTED_LONG_DOUBLE  1 
#endif

/* Defined if the Parma Watchdog Library is enabled. */
#ifndef PPL_WATCHDOG_LIBRARY_ENABLED 
#define PPL_WATCHDOG_LIBRARY_ENABLED  1 
#endif

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
/* #undef PPL__GLIBCXX_DEBUG */

/* When defined and libstdc++ is used, it is used in pedantic debug mode. */
/* #undef PPL__GLIBCXX_DEBUG_PEDANTIC */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef _ppl_const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef _ppl_inline */
#endif

/* Define to __typeof__ if your compiler spells it that way. */
/* #undef _ppl_typeof */


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

 
/* once: _PPL_CONFIG_H */
#endif
