cmd_drivers/thermal/intel/x86_pkg_temp_thermal.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/thermal/intel/x86_pkg_temp_thermal.ko drivers/thermal/intel/x86_pkg_temp_thermal.o drivers/thermal/intel/x86_pkg_temp_thermal.mod.o;  true
