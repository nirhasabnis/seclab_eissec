#
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
#
 
CC = gcc
CONS_SOLVE_DIR=$(TOP)/src/csolve/
CFLAGS = -Wall -I . -I $(CONS_SOLVE_DIR) -g -std=c99 -m32 #-DDEBUG
LIBS = -lpthread
INCLUDE = -I . -I $(CONS_SOLVE_DIR)

all: libsymvarlib.so libobjcow.so

symVarList.o : symVarList.c symVarList.h

symVarStack.o : symVarStack.c symVarStack.h symVarList.h

symRTL.o: symRTL.c symRTL.h

libobjcow.so: objcow.o
	g++ -m32 -Wl,-shared -fPIC -shared -o $@ objcow.o

objcow.o: objcow.cpp objcow.h common.h
	g++ -m32 -std=c++0x -g -I . -I $(CONS_SOLVE_DIR) -c -o objcow.o objcow.cpp

libsymvarlib.so : symVarList.o symVarStack.o symRTL.o
	$(CC) -m32 -fPIC -shared -Wl,-soname=$@ $^ -o $@ $(LIBS)


clean:
	rm -f *.o *.so
