#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cpu_funcs.h"
#include "gs_funcs.h"
#include "rom_funcs.h"

#include "vars/cpu.h"
#include "vars/rom.h"

char path_buf[255];

int main() {
	//init_scr();

	/* Just a check to make sure we're on the correct path */
	getcwd(path_buf, sizeof(path_buf));
	sn_CPU mainCPU;
	rom rom_Ptr;

	/* SMC é uma rom que contém header, +0x200 de offset */
	openRom("roms/smrpg.smc", &rom_Ptr);

	/* This only works on PS2 btw, since it directly
	change Memory/GS virtual memory */
	gsInit();

	printf("path_buf: %s \n", path_buf);
	printf("ROM size: %i\nROM reset: %X\nROM offset: %i\nROM header: %X\n", \
		rom_Ptr.size, rom_Ptr.resetV, rom_Ptr.offset, rom_Ptr.type);
	rcCPU(&mainCPU, &rom_Ptr);
	free(memory_vMap);
	//sleep(10);
	return 0;
}
