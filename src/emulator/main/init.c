#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "core/cpu/ricoh.h"
#include "core/dma.h"
#include "core/apu.h"
#include "emulator/memory.h"
#include "emulator/gs.h"
#include "general/tools.h"

#include "SDL2/SDL.h"

sn_CPU* eCPU;
sn_PPU* ePPU;
sn_DMA* eDMA;
sn_APU* eAPU;
snRAM* eRAM;

extern void initEmu(rom* rom_Ptr) {
	ePPU = malloc(sizeof(sn_PPU));
	eDMA = malloc(sizeof(sn_DMA));
	eAPU = malloc(sizeof(sn_APU));
	eRAM = malloc(sizeof(snRAM));

	emMap mMap[rom_Ptr->banks];
	emMemory memory;

	for(unsigned int i = 0; i < 0x8000; i ++) {
		eRAM->wRAM_exp1[i] = calloc(1, sizeof(u8*));
		eRAM->wRAM_exp2[i] = calloc(1, sizeof(u8*));
	}

	for(unsigned int i = 0; i < rom_Ptr->banks; i ++) {
		attachROM(&mMap[i], rom_Ptr);

		mapPPU(ePPU, mMap[i].ppu_map, false);
		mapAPU(eAPU, mMap[i].apu_map, false);
		mapDMA(eDMA, mMap[i].dma_map, false);

		assignToMap(mMap[i].map, mMap[i].ppu_map, 0x2100, 0x3F, 2);
		assignToMap(mMap[i].map, mMap[i].apu_map, 0x2140, 0x04, 2);
		assignToMap(mMap[i].map, mMap[i].dma_map, 0x4200, 0x15, 2);
		assignToMap(mMap[i].map, &mMap[i].rom_buffer, 0x8000, 0x8000, 2);
	
		/* reserved for IO */
		mMap[i].map[0x4200] = malloc(0x1);

		memory.bank[i] = mMap[i].map;
		printf("done\n");
		/* check to confirm that our buffers are really being mapped */	
		#ifdef DEBUG
		if (*mMap[i].map[0x8000] != *(&mMap[i].rom_buffer[0x0]) || (mMap[i].map[0x8000] != &mMap[i].rom_buffer[0x0])) {
			printf("error, rom not matching\n");
			exit(1);
		} else {
		}
		#endif
		printf("%X \n", *memory.bank[i][0x8000]);
	};
/*	sleep(2);
		printf("ram\n");
		mBank[0x7F] = eRAM->wRAM_exp;
		printf("ram2\n");
*/
	eCPU = malloc(sizeof(sn_CPU));
	setupCPU(eCPU, rom_Ptr, &memory);
	while (1) {
		pollWindow();
		fetchCPU(eCPU);
		fetchPPU(ePPU);
		fetchDMA(eDMA);
	}

	free(eCPU);
	free(ePPU);
	free(eDMA);

	for(unsigned int i = 0; i < rom_Ptr->banks; i ++) {
		free(mMap[i].map);
	}
	for(unsigned int i = 0; i < 0xFF; i ++) {
		free(mBank[i]);
	}

	SDL_Quit();
	return;
};
