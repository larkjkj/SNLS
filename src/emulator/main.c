#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "cpu_funcs.h"
#include "memory_funcs.h"
#include "gs_funcs.h"
#include "rom_funcs.h"
#include "ppu_funcs.h"

#include "vars/ppu.h"
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/memory.h"

#ifdef _EE
#include "debug.h"
#include "ps2_filesystem_driver.h"
#endif

char path_buf[255];

int main() {
	//init_scr();
	/* Just a check to make sure we're on the correct path */
	getcwd(path_buf, sizeof(path_buf));
	sn_CPU* mainCPU = malloc(sizeof(sn_CPU));
	rom rom_Ptr;

	/* Yea, i know this is bad
	 * but this is used until
	 * i make a file explorer */
	openRom("roms/mariow.sfc", &rom_Ptr);
	printf("path_buf: %s \n", path_buf);
	
	printf("CPU PB: %X \nROM size: %u\nROM reset: %X\nROM offset: %u\nROM header: %X\n", \
	mainCPU->sn_PB, rom_Ptr.size, rom_Ptr.resetV, rom_Ptr.offset, rom_Ptr.type);
	rcCPU(mainCPU, &rom_Ptr);
	/* Yea i know this is bad
	 * but i was kidna lazy to implement
		* a better fix like a double pointer
		* or even some more simple
	 */
		//free(m_Buf->mMap);
		//free(m_Buf->mROM);
	free(mainCPU);
	free(mBank);

	return 0;
}
