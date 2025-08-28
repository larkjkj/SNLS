#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "types.h"
#include "vars/bus.h"
#include "vars/cpu.h"
#include "vars/rom.h"

u8* memory_vMap;
u8** memory_Bank;
u32 holdLoAddr;
u32 holdHiAddr;
u32 holdAddr;

extern inline u32 sn_Mwrite(u32 address, size_t byteCount, u32 value) {

	/* In the future, byteCount may be replaced by reading a global
	 * variable that simple stores the steps that PC did, for example
	 * ADC #$030700 would be equal to (4 - 1) */

	switch (byteCount) {
		case 1:
			//memory_vMap[address] = value;
			printf("8-bit \n");
		break;
		case 2:
			//memory_vMap[address] = value;
			printf("16-bit \n");
		break;
		case 3:
			printf("%X \n", memory_Bank[(address << 16)]); /* Little Check*/
		//	memory_vMap[address << 16] = value;
			printf("24-bit \n");
		break;
	};
};

extern u32 inline sn_Mread(u32 address, size_t byteCount) {
	u32 value;
	printf("BUS read request\n");

	/* Same thing above*/
	
	switch (byteCount) {
		case 1:
			return memory_vMap[address];
		break;
		case 2:
			return memory_vMap[address];
		break;
		case 3:
			u8 bankValue = (address >> 24) & 0xFF;
			holdLoAddr = (u8) (address >> 8);
			holdHiAddr = (u8) (address >> 16);
			holdAddr = (holdHiAddr << 8 | holdLoAddr);
		break;
		default:
			printf("Invalid ByteCount\n");
	};
	return value;
};
