#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vars/memory.h"
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/ppu.h"


/* Basically i need to setup tiles*/
/* Make it run along with the CPU */
extern struct sn_PPU* setupPPU(sn_PPU* initializedPPU, str_Buffer* map_Buf){
	initializedPPU->IniDisp = &map_Buf->buffer[INIDISP];

	/* Just a test, it does nothing
	 * only sets IniDisp to a random
	 * value for mapping tests */
	*initializedPPU->IniDisp = 0x0;
	printf("[Mapped PPU %X - PPU: %X]\n", map_Buf->buffer[INIDISP], *initializedPPU->IniDisp);
	return initializedPPU;
}

extern void fetchPPU(sn_PPU* PPU_index) {
	printf("[PPU - %p] -> %X \n", PPU_index, *PPU_index->IniDisp);
	return;
}
