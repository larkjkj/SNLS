#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "core/cpu/ricoh.h"
#include "core/dma.h"
#include "emulator/memory.h"
#include "general/tools.h"

#include "emulator/gs.h"

sn_CPU* eCPU;
sn_PPU* ePPU;
sn_DMA* eDMA;

extern void initEmu(rom* rom_Ptr) {
	ePPU = malloc(sizeof(sn_PPU));
	eDMA = malloc(sizeof(sn_DMA));

	mMemory mMemory[rom_Ptr->banks];
	for(unsigned int i = 0; i < rom_Ptr->banks; i ++) {
		attachROM(&mMemory[i], rom_Ptr);
		mapDMA(eDMA, mMemory[i].dma_map, false);
		mapPPU(ePPU, mMemory[i].ppu_map, false);
		for(unsigned int j = 0; j < 0x8000; j ++) {
			mMemory[i].map[0x8000 + j] = &mMemory[i].rom_buffer[j];
		}
		for(unsigned int j = 0; j < 0x3F; j ++) {
			mMemory[i].map[0x2100 + j] = mMemory[i].ppu_map[j];
		}
		for(unsigned int j = 0; j < 0x15; j ++) {
			mMemory[i].map[0x4200 + j] = mMemory[i].dma_map[j];
		}

		/* reserved for APU */
		mMemory[i].map[0x2140] = malloc(sizeof(u8*));
		mMemory[i].map[0x2141] = malloc(sizeof(u8*));
		mMemory[i].map[0x2142] = malloc(sizeof(u8*));
		mMemory[i].map[0x2143] = malloc(sizeof(u8*));

		/* reserved for IO */
		mMemory[i].map[0x4200] = malloc(sizeof(u8*));
		mMemory[i].map[0x4212] = malloc(sizeof(u8*));
		mMemory[i].map[0x4218] = malloc(sizeof(u8*));
		mMemory[i].map[0x421A] = malloc(sizeof(u8*));
		mMemory[i].map[0x421C] = malloc(sizeof(u8*));
		mMemory[i].map[0x421E] = malloc(sizeof(u8*));
		mMemory[i].map[0x4216] = malloc(sizeof(u8*));
		mMemory[i].map[0x4217] = malloc(sizeof(u8*));
		
		mBank[i] = &mMemory[i].map[0x0];
	};

	eCPU = malloc(sizeof(sn_CPU));
	setupCPU(eCPU, rom_Ptr);
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
		free(mMemory[i].rom_buffer);
		free(mMemory[i].dma_map);
		free(mMemory[i].ppu_map);
		for(unsigned int j = 0; j < 0x10000; j ++) {
			if (mMemory[i].map[j] == NULL) {
				if (i == rom_Ptr->banks - 1) {
					printf("no memleak found!\n");
				} else {
					printf("no allocated memory in bank[%d] (that's good) \n", i);
				}
				break;
			} else {
				printf("There's mem leak at %x");
				free(mMemory[i].map[j]);
			}
		}
	}
	return;
};
