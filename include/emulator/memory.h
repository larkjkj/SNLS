#ifndef SNLS_MEMORY_HEADER 
#define SNLS_MEMORY_HEADER

#include "general/types.h"
#include "core/ppu.h"
#include "core/dma.h"
#include "emulator/rom.h"

typedef struct emMemory {
	u16	bank_target;
	u16	address_target;
	u8	bank_count;
	u8*	bank_array[];
} emMemory;

typedef struct snRAM {
	u8*	wRAM;
	u8*	vRAM;
	u8*	aRAM;
} snRAM;

typedef struct emROM {
	u8*	buffer;
} emROM;

typedef struct emMap {
	u8*	ppu_addr;
	u8*	apu_addr;
	u8*	dma_addr;
} emMap;


extern u16 holdAddr;
extern u8 holdBankAddr;
extern u16 holdLoAddr;
extern u16 holdHiAddr;

#endif
