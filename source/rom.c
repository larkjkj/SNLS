#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "types.h"
#include "gs_addr.h"
#include "memory_funcs.h"

#include "vars/rom.h"
#include "vars/cpu.h"
#include "vars/memory.h"

#ifdef _EE
#include <debug.h>
#endif

FILE* rom_File = NULL;

static u32 address_romTypes[3] = {
	0x7FD5,
	0xFFD5,
};

static u8 valid_romTypes[7] = {
	0x20, 0x21, 0x23, 0x30, 0x31, 0x32, 0x35
};

extern u16 convertBEtoLE16(u16 address) {
	unsigned x = ((u8) (address));
	unsigned y = ((u8) (address >> 8));
	return (y << 8 | x);
}

extern u8 returnBank(size_t byteSize) {
	u8 x = ((byteSize)) / 32768;
	return x;
}


//extern char decimalToHEX(int decNumb) {
/*	char recNumb;
	char hexMap[6] = {
		'A', 'B', 'C', 'D', 'E', 'F'
	};

	while (decNumb | 16 == 1) {
		decNumb /= 16;
		recNumb = ((decNumb % 16) << 8);

		//u8 recNumb = (decNumb %= 16);

		printf("%i => %c\n", decNumb, recNumb);
	}
*/
//	return printf("%X", decNumb);


/* Remember to replace variable calls with struct members */
int splitROM(rom* rom_Ptr) {
	fseek(rom_File, rom_Ptr->offset, SEEK_SET);
	if (rom_Ptr->type & 0x01) {
		rom_Ptr->banksize = 0x8000;
	} else if (rom_Ptr->type & 0x00) {
		rom_Ptr->banksize = 0x10000;
	}

	switch (rom_Ptr->type) {
		case 0x20:
			rom_Ptr->header = 0x7FFC + rom_Ptr->offset;
			rom_Ptr->banksize = 0x8000;
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
			//rom_Ptr->resetV += 0x8000;
			printf("HiROM \n");
		break;
		default:
			printf("Unknown ROM type %X", rom_Ptr->type);
			exit(0);
	}
	fseek(rom_File, rom_Ptr->header, SEEK_SET);
	fread(&rom_Ptr->resetV, sizeof(u16), 1, rom_File);
	splitBanks(rom_Ptr);
//	fseek(rom_File, 0, SEEK_SET);
	/* remanescent code */
	//rom_Ptr->MapArea = 0x8000;
	return 1;
}

int findROMMap(rom* rom_Ptr) {
	for(int i = 0; i < sizeof(address_romTypes) / sizeof(address_romTypes[0]); i ++) {
		fseek(rom_File, rom_Ptr->offset, SEEK_SET);
		fseek(rom_File, address_romTypes[i], SEEK_CUR);
		fread(&rom_Ptr->type, sizeof(u8), 1, rom_File);
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
	rom_File = fopen(rom_name, "r");
	if (rom_File == NULL) {
		#ifdef _EE
		//Using a generic function here to overdraw
		scr_printf("Error, invalid rom \n");
		#endif
		printf("Error, invalid rom \n");
		return;
	} else {
		/* Tell rom size*/
		printf("Sucess opening the rom \n");
		fseek(rom_File, 0, SEEK_END);
		/*if (ftell(rom_File) % 1024 == 512) {
			rom_Ptr->offset = 0x200;
		}*/
		rom_Ptr->offset = (ftell(rom_File) % 1024);
		rom_Ptr->size = ftell(rom_File) - rom_Ptr->offset;
		rom_Ptr->banks = returnBank(rom_Ptr->size);

		printf("ROM size: %zu Offset: %zu \n", rom_Ptr->size, rom_Ptr->offset);

		if (rom_Ptr->size - rom_Ptr->offset >= 4194304) {
			/* Wrong address btw */
			//address_romTypes[3] = 0x40FFC0;
		}

		printf("Checking rom type..\n");
		if (findROMMap(rom_Ptr)) {
			//memory_vMap = malloc(0x7FFF + BytePerBank(rom_Ptr->size));
			//memory_vMap = malloc(0x7FFF + rom_Ptr->size);
			splitROM(rom_Ptr);
		}
	};

	fclose(rom_File);

	return;
};
