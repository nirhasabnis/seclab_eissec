# Automake source file for the Parma Polyhedra Library.
# Copyright (C) 2001-2008 Roberto Bagnara <bagnara@cs.unipr.it>
#
# This file is part of the Parma Polyhedra Library (PPL).
#
# The PPL is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at your
# option) any later version.
#
# The PPL is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111-1307, USA.
#
# For the most up-to-date information see the Parma Polyhedra Library
# site: http://www.cs.unipr.it/ppl/ .

CHECKER =
#CHECKER = valgrind --tool=memcheck -q --trace-children=yes --leak-check=yes --num-callers=100 --leak-resolution=high --suppressions=$(top_srcdir)/tests/valgrind_suppressions

TESTS_ENVIRONMENT = $(CHECKER)

AM_CPPFLAGS = \
-I$(top_builddir)/interfaces/C \
-I$(top_builddir)/src \
@extra_includes@ \
@debug_flag@

if GCC

AM_CFLAGS = -pedantic -std=c89 -Werror

endif GCC

check_LIBRARIES = libppl_c_tests.a

libppl_c_tests_a_SOURCES = \
ppl_c_test.cc

LDADD = \
$(top_builddir)/src/libppl.la \
$(top_builddir)/interfaces/C/libppl_c.la \
libppl_c_tests.a \
@extra_libraries@

NORMAL_TESTS = \
cxxoutput

#
# Sources for the tests
#

cxxoutput_SOURCES = cxxoutput.c print_to_buffer.h print_to_buffer.cc

#watchdog1_SRCS = watchdog1.cc

noinst_HEADERS = \
ppl_c_test.h

if BUILD_WATCHDOG_LIBRARY
WATCHDOG_TESTS =
# watchdog1

# watchdog1_SOURCES = $(watchdog1_SRCS)

# watchdog1_CPPFLAGS = \
# $(AM_CPPFLAGS) \
# -I$(top_builddir)/Watchdog \
# -I$(top_builddir)/Watchdog/src

# watchdog1_LDADD = \
# $(LDADD) \
# $(top_builddir)/Watchdog/src/libpwl.la

endif BUILD_WATCHDOG_LIBRARY

TESTS = $(NORMAL_TESTS) $(WATCHDOG_TESTS)

XFAIL_TESTS =

check_PROGRAMS = $(TESTS) $(BUGS)

EXTRA_DIST = $(watchdog1_SRCS)

BUGS =
