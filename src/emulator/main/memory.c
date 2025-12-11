#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "rom_funcs.h"
#include "ppu_funcs.h"
#include "dma_funcs.h"

#include "vars/dma.h"
#include "vars/rom.h"
#include "vars/memory.h"
#include "vars/ppu.h"

u8* mBank[0xFF];

/*u8* memory_vMap = NULL;
u8* memory_wRAM = NULL;
u8* memory_sPPU = NULL;
u8* memory_iCPU = NULL;
u8* memory_rDMA = NULL;*/

u16 holdAddr;
u16 holdLoAddr;
u16 holdHiAddr;

/* TODO: Make a new function unifying PPU, APU
 * DMA, and buffer setup, something like this
 * setupSystem(sn_PPU, mainDMA, ...) so we can
 * stop using #include all the time for 2 functions
 * only */

extern void attachROM(u8* buffer, rom* rom_Ptr) {
	fread(buffer, sizeof(u8), 0x8000, rom_File);
	printf("%X \n", *buffer);
	return;
}

extern void setupSystem(u8* buffer, sn_PPU* ppu, sn_DMA* dma) {
	/*for(unsigned int i = 0; i < 0xFF; i ++) {
		mBank[i] = malloc(sizeof(u8));
	};
	
	for(unsigned int i = 0; i < rom_Ptr->banks; i ++) {
		mMemory_ptr[i] = malloc(sizeof(u8));
		mMemory_ptr[i]->buffer = malloc(0x10000);
		//attachROM(mMemory_ptr[i]->buffer, rom_Ptr);
		mapPPU(ePPU, mMemory_ptr[i]->buffer);
		
		mBank[i] = *mMemory_ptr[i]->buffer;
	}*/
};


