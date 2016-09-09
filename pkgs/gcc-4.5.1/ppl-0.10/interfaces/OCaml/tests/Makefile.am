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

if VALGRIND_TESTS_ENABLED

CHECKER = \
$(VALGRIND) --tool=memcheck -q --trace-children=yes --leak-check=yes \
--num-callers=100 --leak-resolution=high \
--suppressions=$(srcdir)/valgrind_suppressions

else !VALGRIND_TESTS_ENABLED

CHECKER =

endif !VALGRIND_TESTS_ENABLED

TESTS_ENVIRONMENT = \
	$(LIBTOOL) --mode=execute \
		 -dlopen ../../../src/libppl.la $(WATCHDOG_DLOPEN) $(CHECKER)

interface_generator_files = \
ppl_interface_generator_ocaml_test_ml.m4 \
ppl_interface_generator_ocaml_test_ml_code.m4

interface_generator_dependencies = \
$(top_builddir)/interfaces/ppl_interface_instantiations.m4 \
../../ppl_interface_generator_common.m4 \
../../ppl_interface_generator_common_dat.m4 \
../../ppl_interface_generator_copyright \
../../ppl_interface_generator_common_procedure_generators.m4 \
../ppl_interface_generator_ocaml_procedure_generators.m4 \
ppl_interface_generator_ocaml_test_ml.m4 \
ppl_interface_generator_ocaml_test_ml_code.m4 \
ppl_ocaml_tests_common

# Even if the OCaml sources are not really needed, they are built by m4,
# we need to include them to invoke the Automake OCaml build system.
EXTRA_DIST = \
ppl_interface_generator_ocaml_test_ml_code.m4 \
ppl_interface_generator_ocaml_test_ml.m4 \
ppl_ocaml_tests_common

OCAMLC_ENV = OCAMLRUNPARAM='l=1M'

OCAMLC_COMPILE_FLAGS = \
-I +gmp -I .. -ccopt -g

if ENABLE_SHARED

BUILT_PPL = \
$(top_builddir)/src/.libs/libppl$(SHREXT)

else !ENABLE_SHARED

BUILT_PPL = \
$(top_builddir)/src/.libs/libppl.$(LIBEXT)

endif !ENABLE_SHARED

OCAMLC_LINK_FLAGS = \
-cclib -lmlgmp -cclib -lmpfr \
`echo " $(extra_libraries) " | $(SED) -e "s/ -R[^ ]*//g" -e "s/ -/ -cclib -/g"`

.ml.cmo:
	$(OCAMLC_ENV) ocamlc -o $@ -g -c $(OCAMLC_COMPILE_FLAGS) $<

TESTS = \
test1 \
ppl_ocaml_generated_test

check_PROGRAMS = $(TESTS)

test1_SOURCES = test1.ml

test1$(EXEEXT): test1.cmo ../ppl_ocaml.cma
	$(OCAMLC_ENV) ocamlc -o $@ \
		-cc "$(CXX)" -g -custom $(OCAMLC_COMPILE_FLAGS) \
		-cclib $(BUILT_PPL) $(OCAMLC_LINK_FLAGS) \
		ppl_ocaml.cma $<


nodist_ppl_ocaml_generated_test_SOURCES = ppl_ocaml_generated_test.ml

ppl_ocaml_generated_test.ml: $(interface_generator_dependencies)
	m4 --prefix-builtin -I../.. \
		-I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../.. \
		$(srcdir)/ppl_interface_generator_ocaml_test_ml.m4 \
			> $@

ppl_ocaml_generated_test$(EXEEXT): \
ppl_ocaml_generated_test.cmo ../ppl_ocaml.cma
	$(OCAMLC_ENV) ocamlc -o $@ \
		-cc "$(CXX)" -g -custom $(OCAMLC_COMPILE_FLAGS) \
		-cclib $(BUILT_PPL) $(OCAMLC_LINK_FLAGS) \
		ppl_ocaml.cma $<

CLEANFILES = \
test1.cmi \
test1.cmo \
test1 \
ppl_ocaml_generated_test.ml \
ppl_ocaml_generated_test.cmi \
ppl_ocaml_generated_test.cmo \
ppl_ocaml_generated_test
