#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "vars/cpu.h"
#include "vars/dma.h"
#include "vars/memory.h"

#include "gs_funcs.h"
#include "cpu_funcs.h"
#include "ppu_funcs.h"
#include "dma_funcs.h"
#include "memory_funcs.h"
#include "tools_funcs.h"

sn_CPU* eCPU;
sn_PPU* ePPU;
sn_DMA* eDMA;

static void freeROM(mMemory mMemory) {
	free(mMemory.rom);
};

static void freeMemory() {
	free(mBank);
	free(eCPU);
	free(ePPU);
	free(eDMA);
};

extern void initEmu(rom* rom_Ptr) {
	ePPU = malloc(sizeof(sn_PPU));
	eDMA = malloc(sizeof(sn_DMA));

	setupPPU(ePPU);
	mMemory mMemory[rom_Ptr->banks];

	for(unsigned int i = 0; i < rom_Ptr->banks; i ++) {
		mMemory[i].rom = malloc(0x8000);
		attachROM(mMemory[i].rom, rom_Ptr);
		mapPPU(ePPU, mMemory[i].map);

		/* make a function for this */
		/* these two only allocate memory for our buffers */
		populateBuffer(mMemory[i].map, 0x10000, sizeof(u8));
		populateBuffer(mBank, 0xFF, sizeof(u8*));
		for(unsigned int j = 0; j < 0x8000; j ++) {
			memcpy(mMemory[i].map[0x8000 + j], &mMemory[i].rom[j], sizeof(u8));
		}
	};

	eCPU = malloc(sizeof(sn_CPU));
	setupCPU(eCPU, rom_Ptr);
	while (1) {
		pollWindow();
		fetchCPU(eCPU);
		fetchPPU(ePPU);
		fetchDMA(eDMA);
	}

	for(unsigned int i = 0; i < rom_Ptr->banks; i ++)
		freeROM(mMemory[i]);

		freeMemory();
	return;
};
