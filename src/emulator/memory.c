#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "rom_funcs.h"
#include "ppu_funcs.h"

#include "vars/rom.h"
#include "vars/memory.h"
#include "vars/ppu.h"

u8 mapP = 0x00;
u8* mBank[0xFF];

/*u8* memory_vMap = NULL;
u8* memory_wRAM = NULL;
u8* memory_sPPU = NULL;
u8* memory_iCPU = NULL;
u8* memory_rDMA = NULL;*/

u16 holdAddr;
u16 holdLoAddr;
u16 holdHiAddr;

extern void splitBanks(rom *rom_Ptr) {
	fseek(rom_File, rom_Ptr->offset, SEEK_SET);
	sn_PPU* new_PPU = malloc(sizeof(sn_PPU));

	for(unsigned int i = 0; i <= rom_Ptr->banks; i ++) {
		/* Makes 
		 * ROM -> Buffer 
		 * PPU -> Buffer 
		 * ... -> Buffer 
		 * Buffer -> Bank[x]*/

		str_Buffer* mapROM[i];
		mapROM[i] = malloc(sizeof(u8*));
		mapROM[i]->buffer = malloc(0x10000);
		fread(&mapROM[i]->buffer[0x8000], sizeof(u8), 0x8000, rom_File);

		/* Overrides our PPU pointer with a fully-mapped to buffer PPU */
		new_PPU = setupPPU(new_PPU, mapROM[i]); 
		mBank[i] = mapROM[i]->buffer;
		fetchPPU(new_PPU);

		printf("%X \n", mBank[i][0x8000]);
	}
	// This one acts like rom mirroring
	printf("Done \n");
	return;
}
