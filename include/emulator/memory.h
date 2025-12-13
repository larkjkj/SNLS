#ifndef SNLS_MEMORY_HEADER 
#define SNLS_MEMORY_HEADER

#include "general/types.h"
#include "core/ppu.h"
#include "core/dma.h"
#include "emulator/rom.h"

typedef struct mMemory {
	u8*	rom_buffer;
	u8*	ppu_map[0x3F];
	u8*	dma_map[0x15];

	/* i'm hella mind confusing about using
	 * . normal pointer
	 * . double pointer
	 * . array of pointers */

	u8*	map[0x10000];
} mMemory;

extern u16* holdPtrAddr;
extern u16 holdAddr;
extern u32 reset_snV;
extern u16 holdLoAddr;
extern u16 holdHiAddr;


extern u8** mBank[0xFF];
extern void attachROM(mMemory* mMemory, rom* rom_Ptr);

#define brk_eAddr (u8) rom_buffer[0x00FFFF];

#endif
