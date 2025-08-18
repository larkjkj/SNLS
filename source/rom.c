#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "types.h"
#include "gs_addr.h"

#include "vars/rom.h"
#include "vars/cpu.h"
#include "vars/memory.h"

#ifdef _EE
#include <debug.h>
#endif

/* Warning, some things here will be moved
 * to another file, called memory.c, this file
 * is intended for ROM usage only */
FILE* rom_file = NULL;
u8* rom_buffer;
u8* memory_vMap;
size_t rom_size;

u32 address_romTypes[3] = {
	0x7FD5,
	0xFFD5,
};

u8 valid_romTypes[7] = {
	0x20, 0x21, 0x23, 0x30, 0x31, 0x32, 0x35
};

extern u16 convertBEtoLE16(u16 address) {
	unsigned x = ((u8) (address));
	unsigned y = ((u8) (address >> 8));
	return (y << 8 | x);
}

extern u8 returnBank(u32 byteSize) {
	u8 x = ((byteSize)) / 32768;
	return x;
}

int BytePerBank(int romSize) {
	int x = ((romSize)) / 32768; // Copy of returnBank
	x = x * (64 * 1024); // 64KB
	printf("Allocating %i Bytes \n", x);
	return x;
}

/* Remember to replace variable calls with struct members */
int splitROM(rom* rom_Ptr) {
	switch (rom_Ptr->type) {
		case 0x20:
			rom_Ptr->header = 0x7FFC + rom_Ptr->offset;
			printf("LoROM \n");
		break;
		case 0x21:
			rom_Ptr->header = 0xFFFC + rom_Ptr->offset;
			printf("HiROM \n");
		break;
		case 0x23:
			rom_Ptr->header = 0x7FFC + rom_Ptr->offset;
			printf("SA-1\n");
		break;
		case 0x30:
			rom_Ptr->header = 0x7FFC + rom_Ptr->offset;
			printf("LoROM + FastROM)\n");
		break;
		case 0x31:
			rom_Ptr->header = 0xFFFC + rom_Ptr->offset;
			printf("HiROM \n");
		break;
		default:
			printf("Unknown ROM type %X", rom_Ptr->type);
			exit(0);
	}
	fseek(rom_file, rom_Ptr->header, SEEK_SET);
	fread(&rom_Ptr->resetV, sizeof(u16), 1, rom_file);
	rom_Ptr->MapArea = 0x8000 + rom_Ptr->resetV;
	return 1;
}

int findROMMap(rom* rom_Ptr) {
	for(int i = 0; i < sizeof(address_romTypes) / sizeof(address_romTypes[0]); i ++) {
		fseek(rom_file, rom_Ptr->offset, SEEK_SET);
		fseek(rom_file, address_romTypes[i], SEEK_CUR);
		fread(&rom_Ptr->type, sizeof(u8), 1, rom_file);
		for(int j = 0; j < sizeof(valid_romTypes) / sizeof(valid_romTypes[0]); j ++) {
			if (memcmp(&rom_Ptr->type, &valid_romTypes[j], sizeof(u8)) == 0) {
				printf("Found: %02X\n", rom_Ptr->type);
				return 1;
			} 
		}
		continue;
	};
	return 0;
}

void openRom(char* rom_name, rom* rom_Ptr) {
	rom_file = fopen(rom_name, "r");
	if (rom_file == NULL) {
		#ifdef _EE
		//Using a generic function here to overdraw
		scr_printf("Error, invalid rom \n");
		#endif
		printf("Error, invalid rom \n");
		return;
	} else {
		/* Tell rom size*/
		printf("Sucess opening the rom \n");
		fseek(rom_file, 0, SEEK_END);
		if (ftell(rom_file) % 1024 == 512) {
			rom_Ptr->offset = 0x200;
		}
		rom_Ptr->size = ftell(rom_file) - rom_Ptr->offset;

		printf("ROM size: %i Offset: %i \n", rom_Ptr->size, rom_Ptr->offset);

		if (rom_Ptr->size - rom_Ptr->offset >= 4194304) {
			/* Wrong address btw */
			//address_romTypes[3] = 0x40FFC0;
		}

		printf("Checking rom type..\n");
		if (findROMMap(rom_Ptr)) {
			splitROM(rom_Ptr);
			memory_vMap = malloc(32767 + BytePerBank(rom_Ptr->size));
		}

		fseek(rom_file, rom_Ptr->offset, SEEK_SET);
		fread(&memory_vMap[0x8000], sizeof(u8), rom_Ptr->size, rom_file);
	}
	printf("Total Banks: %u \n", returnBank(rom_Ptr->size));
	/* This will copy a bank to our "virtual" memory, at 0x8000 Address */
	//printf("%i \n", returnBank(rom_size) * returnBankByte(rom_size));
	//
	fclose(rom_file);
	printf("[1/3] Sucess! \n");
}
