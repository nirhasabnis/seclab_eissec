#ifndef _PWL_CONFIG_H
#define _PWL_CONFIG_H 1
 
/* pwl-config.h. Generated automatically at end of configure. */
/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if you have the declaration of `getenv', and to 0 if you don't.
   */
#ifndef PWL_HAVE_DECL_GETENV 
#define PWL_HAVE_DECL_GETENV  0 
#endif

/* Define to 1 if you have the <dlfcn.h> header file. */
#ifndef PWL_HAVE_DLFCN_H 
#define PWL_HAVE_DLFCN_H  1 
#endif

/* Define to 1 if you have the <fenv.h> header file. */
#ifndef PWL_HAVE_FENV_H 
#define PWL_HAVE_FENV_H  1 
#endif

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef PWL_HAVE_INTTYPES_H 
#define PWL_HAVE_INTTYPES_H  1 
#endif

/* Define to 1 if you have the <memory.h> header file. */
#ifndef PWL_HAVE_MEMORY_H 
#define PWL_HAVE_MEMORY_H  1 
#endif

/* Define to 1 if you have the `setitimer' function. */
#ifndef PWL_HAVE_SETITIMER 
#define PWL_HAVE_SETITIMER  1 
#endif

/* Define to 1 if you have the <stdint.h> header file. */
#ifndef PWL_HAVE_STDINT_H 
#define PWL_HAVE_STDINT_H  1 
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#ifndef PWL_HAVE_STDLIB_H 
#define PWL_HAVE_STDLIB_H  1 
#endif

/* Define to 1 if you have the <strings.h> header file. */
#ifndef PWL_HAVE_STRINGS_H 
#define PWL_HAVE_STRINGS_H  1 
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef PWL_HAVE_STRING_H 
#define PWL_HAVE_STRING_H  1 
#endif

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef PWL_HAVE_SYS_STAT_H 
#define PWL_HAVE_SYS_STAT_H  1 
#endif

/* Define to 1 if you have the <sys/time.h> header file. */
#ifndef PWL_HAVE_SYS_TIME_H 
#define PWL_HAVE_SYS_TIME_H  1 
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef PWL_HAVE_SYS_TYPES_H 
#define PWL_HAVE_SYS_TYPES_H  1 
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef PWL_HAVE_UNISTD_H 
#define PWL_HAVE_UNISTD_H  1 
#endif

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#ifndef PWL_LT_OBJDIR 
#define PWL_LT_OBJDIR  ".libs/" 
#endif

/* Assertions are disabled when this is defined */
#ifndef PWL_NDEBUG 
#define PWL_NDEBUG  1 
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef PWL_PACKAGE_BUGREPORT 
#define PWL_PACKAGE_BUGREPORT  "bagnara@cs.unipr.it" 
#endif

/* Define to the full name of this package. */
#ifndef PWL_PACKAGE_NAME 
#define PWL_PACKAGE_NAME  "the Parma Watchdog Library" 
#endif

/* Define to the full name and version of this package. */
#ifndef PWL_PACKAGE_STRING 
#define PWL_PACKAGE_STRING  "the Parma Watchdog Library 0.5" 
#endif

/* Define to the one symbol short name of this package. */
#ifndef PWL_PACKAGE_TARNAME 
#define PWL_PACKAGE_TARNAME  "pwl" 
#endif

/* Define to the version of this package. */
#ifndef PWL_PACKAGE_VERSION 
#define PWL_PACKAGE_VERSION  "0.5" 
#endif

/* Define to 1 if you have the ANSI C header files. */
#ifndef PWL_STDC_HEADERS 
#define PWL_STDC_HEADERS  1 
#endif

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#ifndef PWL_TIME_WITH_SYS_TIME 
#define PWL_TIME_WITH_SYS_TIME  1 
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef _pwl_const */


#ifdef PWL_NDEBUG
# define NDEBUG 1
#endif

 
/* once: _PWL_CONFIG_H */
#endif
