#EXTRACTING INSTRUCTION SEMANTICS VIA SYMBOLIC EXECUTION OF CODE GENERATORS

EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
Generators) is a symbolic execution based system for automatically extracting
assembly to IR translators from code generators of modern compilers.

Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
Lab, Stony Brook University, Stony Brook, NY 11794.

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation; either version 2 of the License, or 
(at your option) any later version. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details. 

You should have received a copy of the GNU General Public License 
along with this program; if not, write to the Free Software 
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

## Directory structure

eissec - 
  |-- src - 
      | - csolve - Interface code to connect to constraint solver for EISSEC
      | - symhelper - Support code used by EISSEC while executing transformed
                        code generator
      | - transformer - OCaml code to transform code generator source code
                        for symbolic execution
  |-- pkgs -
      | - cil-1.4.0 - CIL source package for source-to-source transformation
      | - gcc-4.5.1 - GCC's source code (code generator) used for symbolic 
                      execution
  |-- test/x86 - code for GCC's x86 code generator and a driver to extract x86 
                 model

## Required packages

  The system has been tested on 32-bit Ubuntu-14.04 for x86. It has not been
  tested on any other processor-OS combination.  LISC might work on other
  processor-OS combinations also (though we have not tested it). If it works,
  then please let us know. (See contacts below).

 - EISSEC requirements:
    * Ocaml related: ocaml, ocamlopt, ocamlc, ocamllex, ocamlyacc
    * bison, yacc, flex
    * gcc, g++
    * Constraint solver: swipl

  Docker image has been tested on 64-bit Ubuntu-14.04 for x86_64. It has not been
	tested on any other processor-OS combination. Docker supports other OSes such
	as Windows and MacOS. So the images should work on Windows-x86_64 and MacOS-x86_64.
	
## How to use the system for X86 architecture

In the instructions below, variable TOP is used to refer to the top level
directory of this source code. In other words, it is the directory where this
README file is. $ is a command prompt.

### Quick test (Building from source)
 `$ source env_setup.sh`

 `$ make`
  (make should succeed and produce `test/x86/fullmodel` and `test/x86/testmodel`)

 `$ cd test/x86`
 
 `$ ./testmodel dummy.c`
 
 (This command will dump assembly to RTL mapping for a sample code generator.)
  One of the dumped rules can look like:
  
	```
   _G2101 in 21..28,

   _G653 in 36..138, _G653 #>= _G588, _G184 #>= _G653, 

   _G462 in -1..32, _G462 + 10 #= _G494, 

   _G494 in 9..42, _G494 + _G543 #= _G588, _G462 + 10 #= _G494, _G494 * 3 #= _G543, 

   _G543 in 27..126, _G494 + _G543 #= _G588, _G494 * 3 #= _G543, 

   _G588 in 36..137, _G653 #>= _G588, _G588 #=< _G184 + -1, _G494 + _G543 #= _G588, 

   _G184 in 37..138, _G184 #>= _G653, _G588 #=< _G184 + -1, 

    map: 	cmpb	%_G2101 ->

    insn(_G9,rtl(15,_G27,union_u([rtl(_G184,_G191,_G198,_G205),rtl(_G462,_G469,_G470,_G471),rtl(_G653,_G660,_G667,_G668)|_G393],_G39,_G46,_G53,_G54),_G73))

    Q_425 	_G2101 in 21..28,

   ```

    Here `_G` are Prolog variables. As can be seen, above rule is for `cmpb x86`
    instruction and the operand is represented by a variable `_G2101`. It is
    register (recognized by the fact that % is dumped before `_G2101`). RTL
    corresponding to the assembly specifies how it maps `_G2101` in RTL variables.
    For variables in assembly instruction, RTL variables are obtained by solving
    constraints dumped for RTL variables. Conceptually, rules are functions (say 
    `f`), where `f(x,y,z)=o`, where `x`, `y`, and `z` are variables in assembly and `o` is
    output produced by `f` (RTL). Relations between `x`, `y`, `z` and `o` is captured by
    the set of constraints for every rule. There could be more than one possible
    instantiations that solve a set of constraints for a single rule. These
    instantiations correspond to different operands that a rule will support.
    For instance, for above rules, value of `_G2101` is between 21 and 28. So this
    rule maps cmpb for 8 different registers.

 `$ ./fullmodel dummy.c`
 (This command will dump assembly to RTL mapping for a part of x86 code generator.
  It will run for a long period of time (few hours to days). Numbers reported in
  the paper are in days.)

### Quick test (Using Docker image)

EISSEC is also shipped as a Docker image which makes pre-installing all its
required dependencies easy. So a user need not install any package to test the
software. Before one uses EISSEC Docker image, please install Docker by
referring to [link](https://docs.docker.com/engine/installation/). Once Docker is
installed, steps below pull EISSEC Docker image, create a container from it and
enable terminal access to the container.

`$ docker pull seclab/eissec`
`$ docker create -it --name eissec seclab/eissec`
`$ docker exec -it eissec bash`

Once inside the container, execute following commands to build the binaries and
test them on x86 code generator.

`# cd eissec`
`# source env_setup.sh`
`# make`
`# cd test/x86`
`# ./testmodel dummy.c`
`# ./fullmodel dummy.c`

#### Detailed steps

Steps involved in extracting the model are:

.1. Transform GCC's code generator code for symbolic execution
     
      EISSEC uses CIL-based source-to-source transformation. Transformed code
      when executed perform symbolic executions of the code generator.
      `pkgs/cil-1.4.0/bin/cilly` is the source-to-source transformer. The
      transformer transforms `insn-recog.c` (from `test/x86`) while compiling
      (`test/x86`). Transformed version of `insn-recog.c` can be found in
      `/tmp/insn-recog.cil.c`. Reading `insn-recog.cil.c` may not be easy, but
      if you are curious to know, the transformed code for `insn-recog.c` is found
      in this file.

.2. Constraints sent to Constraint solver

      When testmodel or fullmodel is executed, constraints sent to `cons_solve`
      are dumped in `/tmp/logcs` file. If you would like to change the location,
      please modify `driver.c` in `test/x86` and recompile. `/tmp/logcs` dumps all the
      constraints sent to the constraint solver and the solver's response to
      those constraints.

## Contact

Thank you for trying out EISSEC. If you found EISSEC interesting and useful for
your work, we would love to hear it. Please let us know at
nirhasabnis@gmail.com/sekar@cs.stonybrook.edu.

