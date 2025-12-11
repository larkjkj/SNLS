#ifndef __MEMORY_VARS__
#define __MEMORY_VARS__
#include "rom.h"
#include "types.h"

extern u16* holdPtrAddr;
extern u16 holdAddr;
extern u32 reset_snV;
extern u16 holdLoAddr;
extern u16 holdHiAddr;

typedef struct mMemory {
	u8*	rom;
	u8*	ppu_map[0x3F];
	u8*	dma_map[0x00];

	/* i'm hella mind confusing about using
	 * . normal pointer
	 * . double pointer
	 * . array of pointers */

	u8*	map[0x10000];
} mMemory;

extern u8** mBank[0xFF];

#endif
