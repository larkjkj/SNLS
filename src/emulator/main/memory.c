#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "general/types.h"

#include "core/dma.h"
#include "core/apu.h"
#include "emulator/rom.h"
#include "emulator/memory.h"
#include "core/ppu.h"

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

extern void attachROM(emMap* mMap, rom* rom_Ptr) {
	mMap->rom_buffer = malloc(0x8000);
	fread(mMap->rom_buffer, sizeof(u8), 0x8000, rom_File);
	return;
}

extern void assignToMap(u8** dest, u8** src, unsigned int offset, unsigned int count, unsigned int type) {
	/* don't misunderstand with a memcpy alternative 
	 * this references a map to another one */
	/* double is used here 'cause of rom buffer that uses
	 * a single pointer */

	/* source[0x8000]  ->  destination[0x133]
	 * source[0x8001]  ->  destination[0x134]*/
	/* 2 = u8 */
	for(unsigned int i = 0; i < count; i ++) {
		dest[offset + i] = src[i];
	};
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


