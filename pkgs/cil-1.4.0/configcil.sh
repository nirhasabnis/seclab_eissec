#!/bin/sh

cd ${TOP}/pkgs/cil-1.4.0
make distclean
./configure EXTRASRCDIRS=${TOP}/src/transformer EXTRAFEATURES=symAsm2RTL --no-recursion

