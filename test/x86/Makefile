# EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
# Generators) is a symbolic execution based system for automatically extracting
# assembly to IR translators from code generators of modern compilers.
# 
# Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
# Lab, Stony Brook University, Stony Brook, NY 11794.
# 
# This program is free software; you can redistribute it and/or modify 
# it under the terms of the GNU General Public License as published by 
# the Free Software Foundation; either version 2 of the License, or 
# (at your option) any later version. 
#  
# This program is distributed in the hope that it will be useful, 
# but WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
# GNU General Public License for more details. 
#  
# You should have received a copy of the GNU General Public License 
# along with this program; if not, write to the Free Software 
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

###############################################################################

CC=$(TOP)/pkgs/cil-1.4.0/bin/cilly 
GCC=gcc
GXX=g++
BISON=bison
YACC=yacc
FLEX=flex
TARGET=x86

###############################################################################

#SOURCE_FILES= insn-output.c gcc-support-funcs.c insn-attrtab.c i386.c insn-preds.c rtl-accessors.c
#SOURCE_FILES=insn-recog1to15.c insn-recog16to31.c insn-recog32.c insn-recog33to39.c insn-recog40to48.c insn-recog.c gcc-support-funcs.c rtl-accessors.c 
SOURCE_FILES=insn-recog.c insn-preds.c gcc-support-funcs.c rtl-accessors.c utility.c
#SOURCE_FILES=insn-recog.c insn-preds.c utility.c rtl-accessors.c 
TEST_SOURCE_FILES=insn-test-recog.c rtl-accessors.c utility.c gcc-support-funcs.c insn-preds.c
OBJECT_FILES= $(patsubst %.c,%.o,$(SOURCE_FILES))
TEST_OBJECT_FILES= $(patsubst %.c,%.o,$(TEST_SOURCE_FILES))
GCCPLUGINS_DIR:= $(shell $(GCC) -print-file-name=plugin)

CURR_DIR=$(TOP)
SYMHELPER_DIR=$(TOP)/src/symhelper
GCC_INCLUDES=includes/
CONS_SOLVE_DIR=$(TOP)/src/csolve
GCC_DIR=$(TOP)/pkgs/gcc-4.5.1/
GCC_TOP=$(TOP)/pkgs/gcc-4.5.1/
GCC_OBJDIR=$(GCC_DIR)/objdir/

GCCINC_DIR:=$(GCC_TOP)/gcc/
GCC45PLUGINS_DIR:=$(GCC_TOP)/installdir/lib/gcc/i686-pc-linux-gnu/4.5.1/plugin
GCC_OBJDIR_GCC:=$(GCC_TOP)/objdir/gcc/
#GCC_OBJDIR:=$(GCC_TOP)/objdir/
GMP_DIR:=$(GCC_TOP)/gmp-4.3.2/installdir
MPFR_DIR:=$(GCC_TOP)/mpfr-3.0.0/installdir/
MPC_DIR:=$(GCC_TOP)/mpc-0.8.2/installdir/
PPL_DIR:=$(GCC_TOP)/ppl-0.10/installdir/
ZLIB_DIR:=$(GCC_TOP)/zlib/installdir/
LIBELF_DIR:=$(GCC_TOP)/libelf-0.8.12/installdir/
EXTRA_INCLUDE_DIR:= .

DEP_LIBS_ASM2RTL:=$(GCC_OBJDIR_GCC)/build/rtl.o $(GCC_OBJDIR_GCC)/build/read-rtl.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/build/mygensupport.o $(GCC_OBJDIR_GCC)/build/vec.o $(GCC_OBJDIR_GCC)/genrtl.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-lang.o $(GCC_OBJDIR_GCC)/stub-objc.o $(GCC_OBJDIR_GCC)/attribs.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-errors.o $(GCC_OBJDIR_GCC)/c-lex.o $(GCC_OBJDIR_GCC)/c-pragma.o $(GCC_OBJDIR_GCC)/c-decl.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-typeck.o $(GCC_OBJDIR_GCC)/c-convert.o $(GCC_OBJDIR_GCC)/c-aux-info.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-common.o $(GCC_OBJDIR_GCC)/c-opts.o $(GCC_OBJDIR_GCC)/c-format.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-semantics.o $(GCC_OBJDIR_GCC)/c-ppoutput.o $(GCC_OBJDIR_GCC)/c-cppbuiltin.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-objc-common.o $(GCC_OBJDIR_GCC)/c-dump.o $(GCC_OBJDIR_GCC)/c-pch.o $(GCC_OBJDIR_GCC)/c-parser.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/i386-c.o $(GCC_OBJDIR_GCC)/c-gimplify.o $(GCC_OBJDIR_GCC)/tree-mudflap.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/c-pretty-print.o $(GCC_OBJDIR_GCC)/c-omp.o $(GCC_OBJDIR_GCC)/dummy-checksum.o 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/toplev.o
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR_GCC)/libbackend.a $(GCC_OBJDIR)/libcpp/libcpp.a $(GCC_OBJDIR)/libdecnumber/libdecnumber.a 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR)/libcpp/libcpp.a  $(GCC_OBJDIR)/build-i686-pc-linux-gnu/libiberty/libiberty.a 
DEP_LIBS_ASM2RTL+=$(GCC_OBJDIR)/libdecnumber/libdecnumber.a 
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${ZLIB_DIR}/lib -L$(ZLIB_DIR)/lib -lz 
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${PPL_DIR}/lib -L$(PPL_DIR)/lib -lppl_c -lppl 
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${GMP_DIR}/lib -L$(GMP_DIR)/lib -lgmp
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${MPFR_DIR}/lib -L$(MPFR_DIR)/lib -lmpfr
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${MPC_DIR}/lib -L$(MPC_DIR)/lib -lmpc 
DEP_LIBS_ASM2RTL+=-rdynamic -ldl 
DEP_LIBS_ASM2RTL+=-Wl,-rpath=${LIBELF_DIR}/lib -L$(LIBELF_DIR)/lib -lelf 

###############################################################################

GCCI_CFLAGS+= -I $(GCC45PLUGINS_DIR)/include -I $(GMP_DIR)/include 
GCCI_CFLAGS+= -I $(MPFR_DIR)/include -I $(MPC_DIR)/include 
GCCI_CFLAGS+= -I $(EXTRA_INCLUDE_DIR) -I $(GCCINC_DIR) -I $(GCC_OBJDIR_GCC)
GCCI_CFLAGS+= -Wall -std=c99 -O0 -m32

CIL_FLAGS=--dosymAsm2RTL --symFunctionsFile=cons_functions.list --sysDirsFile=sysdirs.list --funcRetProcFile=funcret.list --dontTransFunccallFile=dont_trans_fcall.list --dosimplify --no-convert-field-offsets --noInsertImplicitCasts --nokeepunused --noPrintLn -w --save-temps=/tmp
INCLUDE_FLAGS=-I$(CURR_DIR) -I$(SYMHELPER_DIR) -I$(GCC_INCLUDES) -I$(CONS_SOLVE_DIR)
STD_CFLAGS= -rdynamic -w -D$(TARGET) -O0 -m32
CFLAGS=$(INCLUDE_FLAGS) $(CIL_FLAGS) $(STD_CFLAGS)
CXXFLAGS=-Wall -DARCH_X86 -std=c++11 -I. -I /tmp -m32

###############################################################################

clean:
	rm -f *.o testmodel fullmodel

all: fullmodel testmodel

driver.o: driver.c
	gcc -o $@ $(STD_CFLAGS) -I$(CONS_SOLVE_DIR) -I . -I includes/ -I $(SYMHELPER_DIR) -c $^ 

testdriver.o: driver.c
	gcc -o $@ -DTEST_MODE $(STD_CFLAGS) -I$(CONS_SOLVE_DIR) -I . -I includes/ -I $(SYMHELPER_DIR) -c $^ 

utility.o: utility.c
	gcc -o $@ $(STD_CFLAGS) -I$(CONS_SOLVE_DIR) -I . -I includes/ -I $(SYMHELPER_DIR) -c $^ 

rtl-accessors.o: rtl-accessors.c $(CONS_SOLVE_DIR)/cons_solve.h
	gcc -o $@ $(STD_CFLAGS) -I$(CONS_SOLVE_DIR) -I . -I includes/ -I $(SYMHELPER_DIR) -c rtl-accessors.c

insn-output.o: insn-output.c
	gcc -D_GNUCC -E $(INCLUDE_FLAGS) -w -DCIL=1 insn-output.c -o /tmp/insn-output.i
	$(TOP)/pkgs/cil-1.4.0/obj/x86_LINUX/cilly.asm.exe --out /tmp/insn-output.cil.c --dosymAsm2RTL --symFunctionsFile ../../cons_functions.list --sysDirsFile ../../sysdirs.list --funcRetProcFile funcret.list --dosimplify --no-convert-field-offsets --noInsertImplicitCasts --nokeepunused --noPrintLn /tmp/insn-output.i
	head -n -5449 /tmp/insn-output.cil.c > /tmp/tt
	echo "#include \"insn-output-trans.h\"" >> /tmp/tt
	tail -n 5449 /tmp/insn-output.cil.c >> /tmp/tt
	mv /tmp/tt /tmp/insn-output.cil.c
	gcc -D_GNUCC -E $(INCLUDE_FLAGS) -w /tmp/insn-output.cil.c -o /tmp/insn-output.cil.i
	gcc -D_GNUCC $(STD_CFLAGS) -c $(INCLUDE_FLAGS) -w -w -o insn-output.o /tmp/insn-output.cil.i

fullmodel: driver.o $(OBJECT_FILES)
	gcc -m32 -o $@ $^ $(GCC_OBJDIR)gcc//build/rtl.o $(GCC_OBJDIR)gcc//build/read-rtl.o \
	$(GCC_OBJDIR)gcc//build/mygensupport.o $(GCC_OBJDIR)gcc//build/vec.o \
	$(GCC_OBJDIR)gcc//genrtl.o $(GCC_OBJDIR)gcc//c-lang.o \
	$(GCC_OBJDIR)gcc//stub-objc.o $(GCC_OBJDIR)gcc//attribs.o \
	$(GCC_OBJDIR)gcc//c-errors.o $(GCC_OBJDIR)gcc//c-lex.o \
	$(GCC_OBJDIR)gcc//c-pragma.o $(GCC_OBJDIR)gcc//c-decl.o \
	$(GCC_OBJDIR)gcc//c-typeck.o $(GCC_OBJDIR)gcc//c-convert.o \
	$(GCC_OBJDIR)gcc//c-aux-info.o $(GCC_OBJDIR)gcc//c-common.o \
	$(GCC_OBJDIR)gcc//c-opts.o  $(GCC_OBJDIR)gcc//c-format.o \
	$(GCC_OBJDIR)gcc//c-semantics.o $(GCC_OBJDIR)gcc//c-ppoutput.o \
	$(GCC_OBJDIR)gcc//c-cppbuiltin.o $(GCC_OBJDIR)gcc//c-objc-common.o \
	$(GCC_OBJDIR)gcc//c-dump.o $(GCC_OBJDIR)gcc//c-pch.o \
	$(GCC_OBJDIR)gcc//c-parser.o $(GCC_OBJDIR)gcc//i386-c.o \
	$(GCC_OBJDIR)gcc//c-gimplify.o $(GCC_OBJDIR)gcc//tree-mudflap.o \
	$(GCC_OBJDIR)gcc//c-pretty-print.o $(GCC_OBJDIR)gcc//c-omp.o \
	$(GCC_OBJDIR)gcc//dummy-checksum.o $(GCC_OBJDIR)gcc//toplev.o \
	$(GCC_OBJDIR)gcc//libbackend.a $(GCC_OBJDIR)/libcpp/libcpp.a \
	$(GCC_OBJDIR)/libdecnumber/libdecnumber.a $(GCC_OBJDIR)/libcpp/libcpp.a \
	$(GCC_OBJDIR)/build-i686-pc-linux-gnu/libiberty/libiberty.a \
	$(GCC_OBJDIR)/libdecnumber/libdecnumber.a \
	-L$(GCC_OBJDIR)/zlib/ -Wl,-rpath=$(GCC_OBJDIR)/zlib/ -lz \
	-L$(GCC_DIR)/ppl-0.10/installdir/lib -Wl,-rpath=$(GCC_DIR)/ppl-0.10/installdir/lib -lppl \
	-L$(GCC_DIR)/gmp-4.3.2/installdir/lib -Wl,-rpath=$(GCC_DIR)/gmp-4.3.2/installdir/lib -lgmp \
	-L$(GCC_DIR)/mpfr-3.0.0/installdir/lib -Wl,-rpath=$(GCC_DIR)/mpfr-3.0.0/installdir/lib -lmpfr \
	-L$(GCC_DIR)/mpc-0.8.2/installdir/lib -Wl,-rpath=$(GCC_DIR)/mpc-0.8.2/installdir/lib -lmpc \
  -L$(GCC_DIR)/libelf-0.8.12/lib -Wl,-rpath=$(GCC_DIR)/libelf-0.8.12/lib -lelf \
  -rdynamic -ldl  -L/lib \
	-L$(SYMHELPER_DIR) -Wl,-rpath=$(SYMHELPER_DIR) -lsymvarlib \
	-L $(CONS_SOLVE_DIR) -Wl,-rpath=$(CONS_SOLVE_DIR) -lcons_solve \
	-L$(SYMHELPER_DIR) -Wl,-rpath=$(SYMHELPER_DIR) -lobjcow \

testmodel: testdriver.o $(OBJECT_FILES)
	gcc -m32 -o $@ $^ $(GCC_OBJDIR)gcc//build/rtl.o $(GCC_OBJDIR)gcc//build/read-rtl.o \
	$(GCC_OBJDIR)gcc//build/mygensupport.o $(GCC_OBJDIR)gcc//build/vec.o \
	$(GCC_OBJDIR)gcc//genrtl.o $(GCC_OBJDIR)gcc//c-lang.o \
	$(GCC_OBJDIR)gcc//stub-objc.o $(GCC_OBJDIR)gcc//attribs.o \
	$(GCC_OBJDIR)gcc//c-errors.o $(GCC_OBJDIR)gcc//c-lex.o \
	$(GCC_OBJDIR)gcc//c-pragma.o $(GCC_OBJDIR)gcc//c-decl.o \
	$(GCC_OBJDIR)gcc//c-typeck.o $(GCC_OBJDIR)gcc//c-convert.o \
	$(GCC_OBJDIR)gcc//c-aux-info.o $(GCC_OBJDIR)gcc//c-common.o \
	$(GCC_OBJDIR)gcc//c-opts.o  $(GCC_OBJDIR)gcc//c-format.o \
	$(GCC_OBJDIR)gcc//c-semantics.o $(GCC_OBJDIR)gcc//c-ppoutput.o \
	$(GCC_OBJDIR)gcc//c-cppbuiltin.o $(GCC_OBJDIR)gcc//c-objc-common.o \
	$(GCC_OBJDIR)gcc//c-dump.o $(GCC_OBJDIR)gcc//c-pch.o \
	$(GCC_OBJDIR)gcc//c-parser.o $(GCC_OBJDIR)gcc//i386-c.o \
	$(GCC_OBJDIR)gcc//c-gimplify.o $(GCC_OBJDIR)gcc//tree-mudflap.o \
	$(GCC_OBJDIR)gcc//c-pretty-print.o $(GCC_OBJDIR)gcc//c-omp.o \
	$(GCC_OBJDIR)gcc//dummy-checksum.o $(GCC_OBJDIR)gcc//toplev.o \
	$(GCC_OBJDIR)gcc//libbackend.a $(GCC_OBJDIR)/libcpp/libcpp.a \
	$(GCC_OBJDIR)/libdecnumber/libdecnumber.a $(GCC_OBJDIR)/libcpp/libcpp.a \
	$(GCC_OBJDIR)/build-i686-pc-linux-gnu/libiberty/libiberty.a \
	$(GCC_OBJDIR)/libdecnumber/libdecnumber.a \
  -L$(GCC_OBJDIR)/zlib/ -Wl,-rpath=$(GCC_OBJDIR)/zlib/ -lz \
	-L$(GCC_DIR)/ppl-0.10/installdir/lib -Wl,-rpath=$(GCC_DIR)/ppl-0.10/installdir/lib -lppl \
	-L$(GCC_DIR)/gmp-4.3.2/installdir/lib -Wl,-rpath=$(GCC_DIR)/gmp-4.3.2/installdir/lib -lgmp \
	-L$(GCC_DIR)/mpfr-3.0.0/installdir/lib -Wl,-rpath=$(GCC_DIR)/mpfr-3.0.0/installdir/lib -lmpfr \
	-L$(GCC_DIR)/mpc-0.8.2/installdir/lib -Wl,-rpath=$(GCC_DIR)/mpc-0.8.2/installdir/lib -lmpc \
  -L$(GCC_DIR)/libelf-0.8.12/lib -Wl,-rpath=$(GCC_DIR)/libelf-0.8.12/lib -lelf \
  -rdynamic -ldl  -L/lib \
	-L$(SYMHELPER_DIR) -Wl,-rpath=$(SYMHELPER_DIR) -lsymvarlib \
	-L $(CONS_SOLVE_DIR) -Wl,-rpath=$(CONS_SOLVE_DIR) -lcons_solve \
	-L$(SYMHELPER_DIR) -Wl,-rpath=$(SYMHELPER_DIR) -lobjcow \

