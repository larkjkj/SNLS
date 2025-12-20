#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "emulator/general.h"
#include "emulator/memory.h"
#include "emulator/gs.h"
#include "general/tools.h"
#include "general/functions.h"

#include "SDL2/SDL.h"

sn_CPU* eCPU = NULL;
sn_PPU* ePPU = NULL;
sn_DMA* eDMA = NULL;
sn_APU* eAPU = NULL;
snRAM* eRAM = NULL;

emGeneral general;
emMemory memory;
emMap mMap;

static void mapPtrBank(uint index, u8* bank_array[]) {
	/* this is loROM only */
	/* target, make 17 pointers, assuming the rom
	 * have 16 banks, so that would be 
	 * 32KB * 16 + 32KB => 544KB*/
	emROM rom[index];
	/* this is where our fun beggins */
	for(uint i = 0; i < index; i ++) {
		bank_array[i] = malloc(0x8000);
		rom[i].buffer = malloc(0x8000);
		fread(rom[i].buffer, sizeof(u8), 0x8000, rom_File);
		bank_array[i] = rom[i].buffer;
		free(rom[i].buffer);
	}

	general.ppu = ePPU;
	//bank_array[index] = mMap.ppu_addr;
	general.ppu->located = index;
	mapPPU(ePPU, &bank_array[general.ppu->located], false);

	general.apu = eAPU;
	//bank_array[index + 1] = mMap.apu_addr;
	general.apu->located = index + 1;
	mapAPU(eAPU, &bank_array[general.apu->located], false);

	general.dma = eDMA;
	//bank_array[index + 2] = mMap.dma_addr;
	general.dma->located = index + 2;
	mapDMA(eDMA, &bank_array[general.dma->located], false);

	general.memory->bank_count = index;
	bank_array[index + 3] = eRAM->wRAM;

}

extern void initEmu(rom* rom_Ptr) {
	/*TODO: move all this to memory.c, where they belong*/
/*	for(unsigned int i = 0; i < 0x8000; i ++) {
		eRAM->wRAM_exp1[i] = calloc(1, sizeof(u8*));
		eRAM->wRAM_exp2[i] = calloc(1, sizeof(u8*));
	}
*/
	
	ePPU = malloc(sizeof(sn_PPU));
	eDMA = malloc(sizeof(sn_DMA));
	eAPU = malloc(sizeof(sn_APU));
	eCPU = malloc(sizeof(sn_CPU));
	eRAM = malloc(sizeof(snRAM));

	general.memory = &memory;
	eRAM->wRAM = malloc(0x8000 * 4);
	mapPPU(ePPU, &mMap.ppu_addr, false);

	mapPtrBank(rom_Ptr->banks, memory.bank_array);

	fclose(rom_File);


	general.cpu = eCPU;
	setupCPU(&general, rom_Ptr);

	while (1) {
		pollWindow();
		fetchCPU(&general);
		fetchPPU(ePPU);
		fetchDMA(eDMA);
	}

	free(eCPU);
	free(ePPU);
	free(eDMA);

	SDL_Quit();
	return;
};
