#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "types.h"
#include "vars/memory.h"
#include "vars/cpu.h"
#include "vars/rom.h"

extern inline u8* sn_Mwrite_u8(sn_CPU* cpuIndex, u16 offset, u8* address, u32 value) {
    printf("Storing <%X> to [%X] [%X]\n", value, cpuIndex->sn_DP, *address);
    *(*mBank[cpuIndex->sn_DP]+ *address) = value;
};

extern inline u8* sn_Mwrite_u16(sn_CPU* cpuIndex, u16 offset, u16* address, u32 value) {
    printf("Storing <%X> to [%X] [%X]\n", value, cpuIndex->sn_DP, *address);
    *(*mBank[cpuIndex->sn_DP] + *address) = value;
};

extern inline u8* sn_Mread_u8(sn_CPU* cpuIndex, u16 offset) {
	return ++cpuIndex->sn_PC;
};

extern inline u16* sn_Mread_u16(sn_CPU* cpuIndex, u16 offset) {
	holdLoAddr = *(++cpuIndex->sn_PC);
	holdHiAddr = *(++cpuIndex->sn_PC);
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	return &holdAddr;
	//return ((memory_Bank[cpuIndex->sn_DBR]) + holdAddr);
};

extern inline u16* sn_Mread_u24(sn_CPU* cpuIndex, u16 offset, bool jumpBank) {
	holdLoAddr = *(++cpuIndex->sn_PC);
	holdHiAddr = *(++cpuIndex->sn_PC);
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	cpuIndex->sn_DBR = *(++cpuIndex->sn_PC);

	if (jumpBank) {
		cpuIndex->sn_PB = cpuIndex->sn_DBR;
	}
	return &holdAddr;
}
