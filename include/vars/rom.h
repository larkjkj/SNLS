#ifndef __ROM_VARS__
#define __ROM_VARS__
#include "types.h"

extern FILE* rom_File;
//extern u32* rom_mBank[4194304];
extern u8* rom_buffer;
extern size_t rom_size;

typedef struct rom_Banks {
	u8*		buffer;
} rom_Banks;

typedef struct rom {
	FILE*		file;
	char*		headername;
	size_t		size;
	size_t		offset;
	u8 		type;
	u16		banks;
	u16		header;
	u16		resetV;
} rom;

#endif
