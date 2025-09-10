#ifndef __ROM_VARS__
#define __ROM_VARS__
#include <stdio.h>
#include "types.h"

extern FILE* rom_File;
//extern u32* rom_mBank[4194304];
extern size_t rom_size;

typedef struct rom {
	FILE*		file;
	char*		headername;
	size_t		size;
	size_t		offset;
	u8 		    type;
	u8		    banks;
	u32		    banksize;
	u16 		header;
	u16		    resetV;
} rom;

#endif
