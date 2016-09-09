all:
	sh -c "${TOP}/pkgs/cil-1.4.0/configcil.sh"
	cd ${TOP}
	make -C pkgs/cil-1.4.0
	make -C src/csolve
	make -C src/symhelper
	make all -C test/x86/

clean:
	make -C pkgs/cil-1.4.0 clean
	make -C src/csolve clean
	make -C src/symhelper clean
	make -C test/x86/ clean

