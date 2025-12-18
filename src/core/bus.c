#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "emulator/init.h"
#include "general/types.h"
#include "emulator/memory.h"
#include "emulator/rom.h"
#include "core/cpu/ricoh.h"

extern u8* sn_Mwrite(emGeneral* emulator, u16 offset, u16 address, u32 value) {
	printf("bus_write: storing %X to [0x%X] [0x%X] const\n", value, emulator->cpu->sn_DP, address);
	*emulator->memory->bank[emulator->cpu->sn_DP][address] = value;
	return emulator->memory->bank[emulator->cpu->sn_DP][address];
};


extern u8* sn_Mwrite_ptr(emGeneral* emulator, u16 offset, u8* address, u32 value) {
	printf("bus_write: storing %X to [0x%X] [0x%X]\n", value, emulator->cpu->sn_DP, holdAddr);
	/* TODO:, use holdAddr is a not-safe and shitty way
	 * to get our target address, since it can be changed 
	 * it is only used here as place holder until i fix it */
	*address = value;
	return address;
};

extern u8* sn_Mread_u8(emGeneral* emulator, u16 offset, bool use_pb) {
	/* TODO: use_pb is unecessary here, remember to remove it */
	return emulator->memory->bank[emulator->cpu->sn_DP][*++emulator->cpu->sn_PC];
};

extern u8 sn_Mread_u8_const(emGeneral* emulator, u16 offset) {
	return *++emulator->cpu->sn_PC;
};


extern u8* sn_Mread_u16(emGeneral* emulator, u16 offset, bool use_pb) {
	holdLoAddr = *(++emulator->cpu->sn_PC);
	holdHiAddr = *(++emulator->cpu->sn_PC);
	holdAddr = (holdHiAddr << 8 | holdLoAddr); 
	if (!use_pb) {
		printf("bus_read: returning [0x%02X][%X]\n", emulator->cpu->sn_DP, holdAddr);
		return emulator->memory->bank[emulator->cpu->sn_DP][holdAddr];
	} else {
		printf("bus_read: returning [0x%02X][%X]\n", emulator->cpu->sn_PB, holdAddr);
		return emulator->memory->bank[emulator->cpu->sn_PB][holdAddr];
	}
};

extern u16 sn_Mread_u16_const(emGeneral* emulator, u16 offset) {
	holdLoAddr = *(++emulator->cpu->sn_PC);
	holdHiAddr = *(++emulator->cpu->sn_PC);
	holdAddr = (holdHiAddr << 8 | holdLoAddr); 
	printf("bus_read: returning const [%X] \n", holdAddr); 
	return holdAddr;
};
extern u8* sn_Mread_u24(emGeneral* emulator, u16 offset, bool use_pb) {
	holdLoAddr = *(++emulator->cpu->sn_PC);
	holdHiAddr = *(++emulator->cpu->sn_PC);
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	emulator->cpu->sn_DP = *(++emulator->cpu->sn_PC);
	if (!use_pb) {
		printf("bus_read: returning [0x%02X][%X]\n", emulator->cpu->sn_DP, holdAddr);
		return emulator->memory->bank[emulator->cpu->sn_DP][holdAddr];
	} else {
		printf("bus_read: returning [0x%02X][%X]\n", emulator->cpu->sn_PB, holdAddr);
		return emulator->memory->bank[emulator->cpu->sn_PB][holdAddr];
	}
}


