#ifndef SNLS_MEMORY_HEADER 
#define SNLS_MEMORY_HEADER

#include "general/types.h"
#include "core/ppu.h"
#include "core/dma.h"
#include "emulator/rom.h"

typedef struct emMemory {
	u8**	bank[0xFF];
} emMemory;

typedef struct snRAM {
	u8	wRAM_low[0x8000];
	u8	wRAM_high[0x8000];
	u8*	wRAM_exp1[0x8000];
	u8*	wRAM_exp2[0x8000];
	u8*	wRAM_exp;
} snRAM;

typedef struct emMap {
	u8*	rom_buffer;
	u8*	ppu_map[0x3F];
	u8*	dma_map[0x15];
	u8*	apu_map[0x04];
	u8*	map[0x10000];
} emMap;

extern u16* holdPtrAddr;
extern u16 holdAddr;
extern u32 reset_snV;
extern u16 holdLoAddr;
extern u16 holdHiAddr;

#define brk_eAddr (u8) rom_buffer[0x00FFFF];

#endif
