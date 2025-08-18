#ifndef __ROM_VARS__
#define __ROM_VARS__
#include "types.h"

extern FILE* rom_file;
//extern u32* rom_mBank[4194304];
extern u8* memory_vMap;
extern u8* rom_buffer;
extern size_t rom_size;

typedef struct rom {
	char*	headername;
	int	size;
	int	offset;
	u8 	type;
	u8	banks;
	u16	header;
	u16	resetV;
	u32	MapArea;
} rom;

#endif
