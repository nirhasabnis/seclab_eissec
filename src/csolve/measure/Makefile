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
 

CFLAGS= -m32 -O2 -g -I .. -I measure/

libcons_solve.so: measure.o cons_solve.o
	gcc -Wl,-shared -fPIC -shared -o $@ measure.c cons_solve.c -ldl -lrt

proccnt.o: proccnt.c
	gcc $(CFLAGS) -c proccnt.c

measure.o: measure.h cons_solve.h measure.c
	gcc $(CFLAGS) -c measure.c

cons_solve.o: cons_solve.h cons_solve.c
	gcc $(CFLAGS) -c cons_solve.c

t1:	t1.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o t1 t1.c -L . cons_solve.o

t2:	t2.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o t2 t2.c -L . cons_solve.o

t3:	t3.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o t3 t3.c cons_solve.o

t4:	t4.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o t4 t4.c cons_solve.o

t5:	t5.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o t5 t5.c cons_solve.o

replaycs: replaycs.c cons_solve.h cons_solve.o
	gcc $(CFLAGS) -o replaycs replaycs.c cons_solve.o

cons_solve: cons_solve.P
	swipl -o cons_solve -c cons_solve.P

all: cons_solve libcons_solve.so cons_dummy tperf t1 t2 t3 t4 t5 replaycs

clean:
	rm -f t1 t2 t3 t4 t5 tperf replaycs cons_solve cons_dummy *.{,s}o

cons_dummy:	cons_dummy.c
	gcc $(CFLAGS) -std=gnu99 -g -o cons_dummy cons_dummy.c

tperf: tperf.c cons_solve.o
	gcc -std=gnu99 $(CFLAGS) -o tperf tperf.c cons_solve.o -lm
