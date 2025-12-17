#ifndef SNLS_ROM_HEADER 
#define SNLS_ROM_HEADER
#include <stdio.h>
#include "general/types.h"

extern FILE* rom_File;
extern size_t rom_size;

static u32 address_romTypes[3] = {
	0x7FD5,
	0xFFD5,
};

static u8 valid_romTypes[7] = {
	0x20, 0x21, 0x23, 0x30, 0x31, 0x32, 0x35
};

typedef struct rom {
	char*	headername;
	size_t	size;
	size_t	offset;
	u8	type;
	u8	banks;
	u32	banksize;
	u16 	header;
	u16	resetV;
} rom;

extern void openRom(char* rom_name, rom* rom_Ptr);
extern u8 returnBank(size_t byteSize);

#endif
