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

SUBDIRS = . tests

interface_generator_files = \
ppl_interface_generator_ocaml_procedure_generators.m4 \
ppl_interface_generator_ocaml_hh_files.m4 \
ppl_interface_generator_ocaml_cc_files.m4 \
ppl_interface_generator_ocaml_hh_code.m4 \
ppl_interface_generator_ocaml_cc_code.m4 \
ppl_interface_generator_ocaml_ml.m4 \
ppl_interface_generator_ocaml_ml_code.m4 \
ppl_interface_generator_ocaml_mli.m4 \
ppl_interface_generator_ocaml_mli_code.m4

ml_source_files = \
ppl_ocaml_globals.mli \
ppl_ocaml_globals.ml

EXTRA_DIST = \
$(interface_generator_files) \
$(ml_source_files) \
OCaml_interface.dox \
README.ocaml

ocamldir = $(pkglibdir)

ocaml_DATA = \
libppl_ocaml.a \
ppl_ocaml.cma \
ppl_ocaml.cmi \
ppl_ocaml.mli \
ppl_ocaml_globals.cmi

BUILT_SOURCES = \
ppl_ocaml_domains.hh \
ppl_ocaml_domains_cc_files.stamp

noinst_LIBRARIES = libppl_ocaml.a

libppl_ocaml_a_SOURCES = \
ppl_ocaml_common.defs.hh \
ppl_ocaml_common.inlines.hh \
ppl_ocaml_common.cc

nodist_EXTRA_libppl_ocaml_a_SOURCES = \
ppl_ocaml_Int8_Box.cc \
ppl_ocaml_Int16_Box.cc \
ppl_ocaml_Int32_Box.cc \
ppl_ocaml_Int64_Box.cc \
ppl_ocaml_Uint8_Box.cc \
ppl_ocaml_Uint16_Box.cc \
ppl_ocaml_Uint32_Box.cc \
ppl_ocaml_Uint64_Box.cc \
ppl_ocaml_Float_Box.cc \
ppl_ocaml_Double_Box.cc \
ppl_ocaml_Long_Double_Box.cc \
ppl_ocaml_Rational_Box.cc \
ppl_ocaml_Z_Box.cc \
ppl_ocaml_BD_Shape_int8_t.cc \
ppl_ocaml_BD_Shape_int16_t.cc \
ppl_ocaml_BD_Shape_int32_t.cc \
ppl_ocaml_BD_Shape_int64_t.cc \
ppl_ocaml_BD_Shape_float.cc \
ppl_ocaml_BD_Shape_double.cc \
ppl_ocaml_BD_Shape_long_double.cc \
ppl_ocaml_BD_Shape_mpq_class.cc \
ppl_ocaml_BD_Shape_mpz_class.cc \
ppl_ocaml_Octagonal_Shape_int8_t.cc \
ppl_ocaml_Octagonal_Shape_int16_t.cc \
ppl_ocaml_Octagonal_Shape_int32_t.cc \
ppl_ocaml_Octagonal_Shape_int64_t.cc \
ppl_ocaml_Octagonal_Shape_float.cc \
ppl_ocaml_Octagonal_Shape_double.cc \
ppl_ocaml_Octagonal_Shape_long_double.cc \
ppl_ocaml_Octagonal_Shape_mpq_class.cc \
ppl_ocaml_Octagonal_Shape_mpz_class.cc \
ppl_ocaml_Polyhedron.cc \
ppl_ocaml_Grid.cc \
ppl_ocaml_Pointset_Powerset_Int8_Box.cc \
ppl_ocaml_Pointset_Powerset_Int16_Box.cc \
ppl_ocaml_Pointset_Powerset_Int32_Box.cc \
ppl_ocaml_Pointset_Powerset_Int64_Box.cc \
ppl_ocaml_Pointset_Powerset_Uint8_Box.cc \
ppl_ocaml_Pointset_Powerset_Uint16_Box.cc \
ppl_ocaml_Pointset_Powerset_Uint32_Box.cc \
ppl_ocaml_Pointset_Powerset_Uint64_Box.cc \
ppl_ocaml_Pointset_Powerset_Float_Box.cc \
ppl_ocaml_Pointset_Powerset_Double_Box.cc \
ppl_ocaml_Pointset_Powerset_Long_Double_Box.cc \
ppl_ocaml_Pointset_Powerset_Rational_Box.cc \
ppl_ocaml_Pointset_Powerset_Z_Box.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_int8_t.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_int16_t.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_int32_t.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_int64_t.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_float.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_double.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_long_double.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_mpq_class.cc \
ppl_ocaml_Pointset_Powerset_BD_Shape_mpz_class.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_int8_t.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_int16_t.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_int32_t.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_int64_t.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_float.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_double.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_long_double.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_mpq_class.cc \
ppl_ocaml_Pointset_Powerset_Octagonal_Shape_mpz_class.cc \
ppl_ocaml_Pointset_Powerset_C_Polyhedron.cc \
ppl_ocaml_Pointset_Powerset_NNC_Polyhedron.cc \
ppl_ocaml_Pointset_Powerset_Grid.cc \
ppl_ocaml_Constraints_Product_C_Polyhedron_Grid.cc \
ppl_ocaml_Constraints_Product_NNC_Polyhedron_Grid.cc \
ppl_ocaml_Constraints_Product_Grid_C_Polyhedron.cc \
ppl_ocaml_Constraints_Product_Grid_NNC_Polyhedron.cc

libppl_ocaml_a_LIBADD = \
@required_instantiations_ocaml_cxx_objects@

libppl_ocaml_a_DEPENDENCIES = \
@required_instantiations_ocaml_cxx_objects@

OCAMLC_ENV = OCAMLRUNPARAM='l=1M'

OCAMLC_COMPILE_FLAGS = \
-I +gmp -I .. -ccopt -g

OCAMLC_LINK_FLAGS = \
`echo " $(extra_libraries) " | $(SED) -e "s/ -R[^ ]*//g" -e "s/ -/ -cclib -/g"`

OCAMLC_ROOT = @ocamlc_root@

AM_CPPFLAGS = \
-I$(OCAMLC_ROOT) \
-I$(top_srcdir)/interfaces \
-I$(top_srcdir)/src \
-I$(top_builddir)/src \
@extra_includes@

interface_generator_dependencies = \
$(top_builddir)/interfaces/ppl_interface_instantiations.m4 \
../ppl_interface_generator_common.m4 \
../ppl_interface_generator_common_dat.m4 \
../ppl_interface_generator_copyright \
$(interface_generator_files)

ppl_ocaml.cma: ppl_ocaml_globals.cmo ppl_ocaml.cmo libppl_ocaml.a
	$(OCAMLC_ENV) ocamlc -o $@ -a -custom \
		ppl_ocaml_globals.cmo ppl_ocaml.cmo \
		$(OCAMLC_COMPILE_FLAGS) -cclib -lppl_ocaml \
		$(OCAMLC_LINK_FLAGS)

ppl_ocaml.cmo: ppl_ocaml.ml ppl_ocaml.cmi ppl_ocaml_globals.cmi
	$(OCAMLC_ENV) ocamlc -o $@ -g -c $(OCAMLC_COMPILE_FLAGS) ppl_ocaml.ml

ppl_ocaml.cmi: ppl_ocaml.mli
	$(OCAMLC_ENV) ocamlc -o $@ -g -c $(OCAMLC_COMPILE_FLAGS) $<

ppl_ocaml_globals.cmo: ppl_ocaml_globals.ml ppl_ocaml_globals.cmi
	$(OCAMLC_ENV) ocamlc -o $@ -g -c $(OCAMLC_COMPILE_FLAGS) \
		$(srcdir)/ppl_ocaml_globals.ml

ppl_ocaml_globals.cmi: ppl_ocaml_globals.mli
	$(OCAMLC_ENV) ocamlc -o $@ -g -c $(OCAMLC_COMPILE_FLAGS) $<

ppl_ocaml.ml: $(interface_generator_dependencies)
	m4 --prefix-builtin -I.. -I$(srcdir) -I$(srcdir)/.. \
           $(srcdir)/ppl_interface_generator_ocaml_ml.m4 > $@

ppl_ocaml.mli: $(interface_generator_dependencies)
	m4 --prefix-builtin -I.. -I$(srcdir) -I$(srcdir)/.. \
           $(srcdir)/ppl_interface_generator_ocaml_mli.m4 > $@

ppl_ocaml_domains_cc_files.stamp: $(interface_generator_dependencies)
	m4 --prefix-builtin -I.. -I$(srcdir) -I$(srcdir)/.. \
           $(srcdir)/ppl_interface_generator_ocaml_cc_files.m4 \
                > ppl_ocaml_cc_blob
	$(top_srcdir)/utils/cm_cleaner.sh < ppl_ocaml_cc_blob
	$(top_srcdir)/utils/cm_splitter.sh < ppl_ocaml_cc_blob
	rm -f ppl_ocaml_cc_blob
	echo timestamp >$@

ppl_ocaml_domains.hh: $(interface_generator_dependencies)
	m4 --prefix-builtin -I.. -I$(srcdir) -I$(srcdir)/.. \
           $(srcdir)/ppl_interface_generator_ocaml_hh_files.m4 \
                > ppl_ocaml_hh_blob
	$(top_srcdir)/utils/cm_cleaner.sh < ppl_ocaml_hh_blob
	$(top_srcdir)/utils/cm_splitter.sh < ppl_ocaml_hh_blob
	rm -f ppl_ocaml_hh_blob

MOSTLYCLEANFILES = \
@required_instantiations_ocaml_cxx_objects@ \
ppl_ocaml.cma \
ppl_ocaml.cmi \
ppl_ocaml.cmo \
ppl_ocaml_globals.cmi \
ppl_ocaml_globals.cmo

CLEANFILES = \
@required_instantiations_ocaml_cxx_sources@ \
@required_instantiations_ocaml_cxx_headers@ \
ppl_ocaml_domains.hh \
ppl_ocaml.ml \
ppl_ocaml.mli \
ppl_ocaml_domains_cc_files.stamp
