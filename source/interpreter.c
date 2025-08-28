
/* i'm tired. */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <unistd.h>

#include "vars/bus.h"
#include "vars/rom.h"
#include "vars/cpu.h"
#include "rom_funcs.h"
#include "bus_funcs.h"

/* Long are always 24-bit addresses*/

/* Add with carry CPU operations */
extern inline void snADC_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_MFlag) {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = (holdHiAddr << 8 | holdLoAddr);
	} else {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	}
	//memory_vMap[holdAddr] += 1 + (cpuIndex->sn_CFlagg ? 1 : 0);
	cpuIndex->sn_Acc = holdAddr + cpuIndex->sn_CFlag;
}

extern inline void snADC_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	cpuIndex->sn_Acc = memory_vMap[holdAddr] + cpuIndex->sn_CFlag;
}
/*
extern inline void snADC_long(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[cpuIndex->sn_PC + 3];
	holdHiAddr = memory_vMap[cpuIndex->sn_PC + 2];

	holdAddr = holdHiAddr << 8 | holdLoAddr;
	(memory_Bank[memory_vMap[++cpuIndex->sn_PC]] + [holdAddr]);
	cpuIndex -> sn_Acc = cpuIndex->sn_CFlag;
}*/

extern inline void snADC_dp(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc += memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP] + (cpuIndex->sn_CFlag);
}

extern inline void snADC_dpI(sn_CPU* cpuIndex) {

}

extern inline void snADC_dpI_long(sn_CPU* cpuIndex) {

}

extern inline void snADC_srS(sn_CPU* cpuIndex) {

};

extern inline void snADC_dpX(sn_CPU* cpuIndex) {};
extern inline void snADC_dpI_longY(sn_CPU* cpuIndex) {};
extern inline void snADC_addrY(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_Acc = memory_vMap[holdAddr + cpuIndex->sn_Y] + cpuIndex->sn_CFlag;
};

extern inline void snADC_addrX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_Acc = memory_vMap[holdAddr + cpuIndex->sn_X] + cpuIndex->sn_CFlag;
};

/*extern inline void snADC_longX(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;

	cpuIndex->sn_Acc = memory_vMap[((holdAddr % rom_Ptr->size) + rom_Ptr->MapArea)] + cpuIndex->sn_CFlag;
};*/

/* And accumulator with memory operations */
extern void snAND_dpXI(sn_CPU* cpuIndex);
extern void snAND_srS(sn_CPU* cpuIndex);
extern void snAND_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_Acc &= memory_vMap[holdAddr + cpuIndex->sn_DP];
};

extern void snAND_dpI(sn_CPU* cpuIndex);

extern void snAND_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_MFlag) {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = (holdHiAddr << 8 | holdLoAddr); 
	} else {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	};

	cpuIndex->sn_Acc &= holdAddr;
}

extern void snAND_addr(sn_CPU* cpuIndex) {
	if (cpuIndex->sn_MFlag) {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = (holdHiAddr << 8 | holdLoAddr); 
	} else {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	};

	cpuIndex->sn_Acc &= memory_vMap[holdAddr];
}

/*extern void snAND_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr);

	//cpuIndex->sn_Acc &= memory_vMap[(holdAddr % 0x200000) + rom_Ptr->MapArea];
	//cpuIndex->sn_Acc &= memory_vMap[holdAddr - (rom_Ptr->size + rom_Ptr->MapArea)];
	cpuIndex->sn_Acc &= memory_vMap[((holdAddr % rom_Ptr->size) + rom_Ptr->MapArea)];
};*/

extern void snAND_dpIY(sn_CPU* cpuIndex);
extern void snAND_dpI(sn_CPU* cpuIndex);
extern void snAND_srSIY(sn_CPU* cpuIndex);
extern void snAND_dpX(sn_CPU* cpuIndex);
extern void snAND_dpIY(sn_CPU* cpuIndex);
extern void snAND_addrY(sn_CPU* cpuIndex);
extern void snAND_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);

	cpuIndex->sn_Acc &= memory_vMap[holdAddr + cpuIndex->sn_X];
};

/*extern void snAND_longX(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc &= memory_vMap[(holdAddr % rom_Ptr->size) + cpuIndex->sn_X + rom_Ptr->MapArea];
};*/

/* Performs a Bit shift to left */
extern void snASL_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP];
	memory_vMap[holdAddr] <<= 1;
}

extern void snASL_Acc(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc <<= 1;
}

extern void snASL_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	memory_vMap[holdAddr] <<= 1;
}

extern void snASL_dpX(sn_CPU* cpuIndex) {
	memory_vMap[cpuIndex->sn_DP + cpuIndex->sn_X] <<= 1;
}

extern void snASL_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	memory_vMap[holdAddr + cpuIndex->sn_X] <<= 1;
}


/* Branch if the flags are set */
extern void snBCC(sn_CPU* cpuIndex) {
/*	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	if (cpuIndex->sn_CFlag)
		cpuIndex->sn_PC = ((s8) cpuIndex->sn_PC + memory_vMap[holdAddr]);*/
};

extern void snBCS(sn_CPU* cpuIndex) {
/*	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	if (!cpuIndex->sn_CFlag)
		cpuIndex->sn_PC = ((s8) cpuIndex->sn_PC + memory_vMap[holdAddr]);*/
};

extern void snBEQ(sn_CPU* cpuIndex) {
	/*holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_PC = ((s8) cpuIndex->sn_PC + memory_vMap[holdAddr]);
*/
};

/* This opcodes test bits with the corrsponding one */
extern void snBIT_dp(sn_CPU* cpuIndex);
extern void snBIT_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;

	(cpuIndex->sn_NFlag == ((memory_vMap[holdAddr] & cpuIndex->sn_Acc) & 0x80) ? 1 : 0);
	(cpuIndex->sn_VFlag == ((memory_vMap[holdAddr] & cpuIndex->sn_Acc) & 0x60) ? 1 : 0);
	(cpuIndex->sn_ZFlag == (memory_vMap[holdAddr] & cpuIndex->sn_Acc == 0) ? 1 : 0);
};

extern void snBIT_dpX(sn_CPU* cpuIndex);
extern void snBIT_addrX(sn_CPU* cpuIndex);
extern void snBIT_const(sn_CPU* cpuIndex);

/* Branch to a specific address */
extern void snBRA(sn_CPU* cpuIndex) {
	holdAddr = ((s16) cpuIndex->sn_PC) + memory_vMap[cpuIndex->sn_PC + 1];
	cpuIndex->sn_PC += holdAddr;	
}

/* Clear the corresponding flags */
extern void snCLC(sn_CPU* cpuIndex) {
	cpuIndex->sn_CFlag = 0;
};
extern void snCLD(sn_CPU* cpuIndex) {
	cpuIndex->sn_DFlag = 0;
};
extern void snCLI(sn_CPU* cpuIndex) {
	cpuIndex->sn_IFlag = 0;
};
extern void snCLV(sn_CPU* cpuIndex){
	cpuIndex->sn_VFlag = 0;
};

/* Do comparations */
extern void snCMP_dpIX(sn_CPU* cpuIndex);
extern void snCMP_srS(sn_CPU* cpuIndex);

extern void snCMP_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_DP];
//	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_DP];
};

/*extern void snCMP_dpI_long(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC];
	holdAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
//	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};*/

extern void snCMP_const(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
//	cpuIndex->sn_Acc -= holdAddr;
};

extern void snCMP_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	(cpuIndex->sn_NFlag = (cpuIndex->sn_Acc - memory_vMap[holdAddr]) < 0 ? 1 : 0);
	(cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc - memory_vMap[holdAddr]) == 0 ? 1 : 0);

	/* 8-bit */
	if (cpuIndex->sn_MFlag) {
		(cpuIndex->sn_CFlag = ((cpuIndex->sn_Acc - memory_vMap[holdAddr]) & 0x100) ? 1 : 0);
	} else {
		/* 16-bit */
		(cpuIndex->sn_CFlag = ((cpuIndex->sn_Acc - memory_vMap[holdAddr]) & 0x10000) ? 1 : 0);
	}
};
/*
extern void snCMP_long(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	//cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};*/

extern void snCMP_dpIY(sn_CPU* cpuIndex);
extern void snCMP_dpI(sn_CPU* cpuIndex);
extern void snCMP_srSIY(sn_CPU* cpuIndex);
extern void snCMP_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP + cpuIndex->sn_X];
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};

extern void snCMP_dpI_longY(sn_CPU* cpuIndex);
extern void snCMP_addrY(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_Y;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};

extern void snCMP_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};


/*extern void snCMP_longX(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;

	cpuIndex->sn_Acc -= memory_vMap[((holdAddr % rom_Ptr->size) + cpuIndex->sn_X)];
};*/

/* Decrement 1 to registers */
extern void snDEC_Acc(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc -= 1;
};

extern void snDEC_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	("dec, %X$(%X)\n", cpuIndex->sn_DP, holdAddr);
	memory_vMap[holdAddr + cpuIndex->sn_DP] -= 1;
};

extern void snDEC_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	memory_vMap[holdAddr] -= 1;
};

extern void snDEC_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP + cpuIndex->sn_X];
	memory_vMap[holdAddr] -= 1;
};

extern void snDEC_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	memory_vMap[holdAddr + cpuIndex->sn_X] -= 1;
};

extern void snDEX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X -= 1;
};

extern void snDEY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y -= 1;
};

/* Load to Accumulator according to the operation */
extern void snLDA_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_Acc = memory_vMap[holdAddr + cpuIndex->sn_DP];
	("LDA: %X\n", cpuIndex->sn_Acc);
};

extern void snLDA_dpI_long(sn_CPU* cpuIndex);

extern void snLDA_const(sn_CPU* cpuIndex) {
	if (cpuIndex->sn_MFlag) {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	} else {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = holdHiAddr << 8 | holdLoAddr;
		memory_vMap[++cpuIndex->sn_PC];
	}
	cpuIndex->sn_Acc = holdAddr;
	("LDA const: $%04X \n", cpuIndex->sn_Acc);
};

extern void snLDA_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc = memory_vMap[holdAddr];
	("LDA addr: %X\n", memory_vMap[holdAddr]);
};

/*extern void snLDA_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	//cpuIndex->sn_Acc = holdAddr;
	//cpuIndex->sn_Acc &= memory_vMap[holdAddr - (rom_Ptr->size + rom_Ptr->MapArea)];
	cpuIndex->sn_Acc &= memory_vMap[((holdAddr % rom_Ptr->size)) + rom_Ptr->MapArea];
	("LDA long: %X\n", holdAddr);
};*/

extern void snLDA_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP + cpuIndex->sn_X];
	cpuIndex->sn_Acc = memory_vMap[holdAddr];
};

extern void snLDA_addrY(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_Y;
	cpuIndex->sn_Acc = memory_vMap[holdAddr];
};

extern void snLDA_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X;
	cpuIndex->sn_Acc = memory_vMap[holdAddr];
};
/*
extern void snLDA_longX(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X;
	cpuIndex->sn_Acc = memory_vMap[((holdAddr % rom_Ptr->size)) + rom_Ptr->MapArea];
};*/

extern void snLDX_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_XFlag) {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = holdHiAddr << 8 | holdLoAddr;
	} else {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	}
	cpuIndex->sn_X = holdAddr;
};

extern void snLDX_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC] + cpuIndex->sn_DP;
	cpuIndex->sn_X = memory_vMap[holdAddr];
};

extern void snLDX_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_X = memory_vMap[holdAddr];
};

extern void snLDX_dpY(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC] + cpuIndex->sn_Y;
	cpuIndex->sn_X = memory_vMap[holdAddr];
};

extern void snLDX_addrY(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_Y;
	cpuIndex->sn_X = memory_vMap[holdAddr];
};

extern void snINC_Acc(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc += 1;
};

extern void snINC_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP];
	memory_vMap[holdAddr] += 1;
};

extern void snINC_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	memory_vMap[holdAddr] += 1;
};

extern void snINC_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP + cpuIndex->sn_X];
	memory_vMap[holdAddr] += 1;
};

extern void snINC_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X;
	memory_vMap[holdAddr] += 1;
};

extern void snINX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X += 1;
};

extern void snINY(sn_CPU* cpuIndex) {
	cpuIndex->sn_X += 1;
};

extern void snJMP_addr(sn_CPU* cpuIndex) {};
/*
extern void snJMP_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = ((memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr) % (rom_Ptr->size)) + rom_Ptr->MapArea;

	("PC jumped to %X with value: %X\n", holdAddr, memory_vMap[holdAddr]);
	cpuIndex->sn_PC = holdAddr;
	//("%X\n",(holdAddr % rom_Ptr->MapArea));
};*/

extern void snJSR_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_subPC = cpuIndex->sn_PC;
	("Subroutine to 0x%X\n", holdAddr);
	cpuIndex->sn_PC = holdAddr;
	sleep(1);
};

extern void snJSR_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	printf("JSR Long \n");
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = ((memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr) << 8);
	cpuIndex->sn_subPC = cpuIndex->sn_PC;
	cpuIndex->sn_PC = sn_Mread(holdAddr, 3);
	sleep(2);
};


extern void snJSR_addrXI() {};

extern void snORA_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	cpuIndex->sn_Acc |= memory_vMap[holdAddr];
};
/*
extern void snORA_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	holdAddr = ((memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr) % (rom_Ptr->size)) + rom_Ptr->MapArea;
	cpuIndex->sn_Acc |= memory_vMap[holdAddr];
};*/

extern void snORA_const(sn_CPU* cpuIndex) {
	if (cpuIndex->sn_MFlag) {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
	} else {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = (holdHiAddr << 8 | holdLoAddr);
	}
	cpuIndex->sn_Acc |= holdAddr;
	//sleep(1);
};

extern void snORA_addrY(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_Y;
	("OR Acc: %X Memory: %X \n", cpuIndex->sn_Acc, memory_vMap[holdAddr]);
	cpuIndex->sn_Acc |= memory_vMap[holdAddr];
	//sleep(1);
};

extern void snORA_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X;
	("OR Acc: %X Memory: %X\n", cpuIndex->sn_Acc, memory_vMap[holdAddr]);
	cpuIndex->sn_Acc |= memory_vMap[holdAddr];
	//sleep(1);
};

/*
extern void snORA_longX(sn_CPU* cpuIndex,  rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (((memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr) + cpuIndex->sn_X) % rom_Ptr->size) + rom_Ptr->MapArea;
	("OR Acc: %X Memory: %X\n", cpuIndex->sn_Acc, memory_vMap[holdAddr]);
	cpuIndex->sn_Acc |= memory_vMap[holdAddr];
	//sleep(1);
};*/

extern void snREP_const(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_CFlag = (holdAddr & 0x80 ? 0 : 1);
	cpuIndex->sn_VFlag = (holdAddr & 0x40 ? 0 : 1);
	cpuIndex->sn_MFlag = (holdAddr & 0x20 ? 0 : 1);
	cpuIndex->sn_XFlag = (holdAddr & 0x10 ? 0 : 1);
	cpuIndex->sn_DFlag = (holdAddr & 0x08 ? 0 : 1);
	cpuIndex->sn_IFlag = (holdAddr & 0x04 ? 0 : 1);
	cpuIndex->sn_ZFlag = (holdAddr & 0x02 ? 0 : 1);
	cpuIndex->sn_EFlag = (holdAddr & 0x01 ? 0 : 1);
};

extern void snSEC(sn_CPU* cpuIndex) {
	cpuIndex->sn_CFlag = 1;
};

extern void snSED(sn_CPU* cpuIndex) {
	cpuIndex->sn_DFlag = 1;
};

extern void snSEI(sn_CPU* cpuIndex) {
	cpuIndex->sn_IFlag = 1;
};

extern void snSEP(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_CFlag = (holdAddr & 0x80 ? 1 : 0);
	cpuIndex->sn_VFlag = (holdAddr & 0x40 ? 1 : 0);
	cpuIndex->sn_MFlag = (holdAddr & 0x20 ? 1 : 0);
	cpuIndex->sn_XFlag = (holdAddr & 0x10 ? 1 : 0);
	cpuIndex->sn_DFlag = (holdAddr & 0x08 ? 1 : 0);
	cpuIndex->sn_IFlag = (holdAddr & 0x04 ? 1 : 0);
	cpuIndex->sn_ZFlag = (holdAddr & 0x02 ? 1 : 0);
	cpuIndex->sn_EFlag = (holdAddr & 0x01 ? 1 : 0);
}

extern void snSTA_dpXI(sn_CPU* cpuIndex);
extern void snSTA_srS(sn_CPU* cpuIndex);
extern void snSTA_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC] + cpuIndex->sn_DP;
	memory_vMap[holdAddr] = cpuIndex->sn_Acc;
	printf("Storing %X to address $06%X\n", cpuIndex->sn_Acc, holdAddr);
	//sleep(1);
};

extern void snSTA_dpI_long(sn_CPU* cpuIndex);

extern void snSTA_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	memory_vMap[holdAddr] = cpuIndex->sn_Acc;
	printf("Storing %X to address $06%X\n", cpuIndex->sn_Acc, memory_vMap[holdAddr]);
	//sleep(1);
};

/*extern void snSTA_long(sn_CPU* cpuIndex, rom* rom_Ptr) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;

	memory_vMap[(holdAddr % rom_Ptr->size)] = cpuIndex->sn_Acc;
	printf("Storing %X to address $%06X\n", cpuIndex->sn_Acc, (holdAddr % rom_Ptr->size) + rom_Ptr->MapArea);
	//sleep(1);
	//("Storing to memory\n", cpuIndex->sn_Acc);
};*/

extern void snSTA_dpIY(sn_CPU* cpuIndex);
extern void snSTA_dpI(sn_CPU* cpuIndex);
extern void snSTA_dpIY(sn_CPU* cpuIndex);

extern void snSTY_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	memory_vMap[holdAddr] = cpuIndex->sn_Y;
};

extern void snSTY_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP];
	memory_vMap[holdAddr] = cpuIndex->sn_Y;
};

extern void snSTY_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP + cpuIndex->sn_X];
	memory_vMap[holdAddr] = cpuIndex->sn_Y;
};

extern void snSTZ_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP];
	memory_vMap[holdAddr + cpuIndex->sn_DP] = 0;
	("Storing zero at: 0x%06X\n", holdAddr);
};

extern void snSTZ_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	memory_vMap[holdAddr + cpuIndex->sn_DP + cpuIndex->sn_X] = 0;
	("Storing 0 to 0x%06X\n", holdAddr + cpuIndex->sn_DP + cpuIndex->sn_X);
};

extern void snSTZ_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	memory_vMap[holdAddr] = 0;
	printf("Storing 0 to 0x%06X\n", holdAddr);
};

extern void snSTZ_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = (memory_vMap[++cpuIndex->sn_PC]);
	holdHiAddr = (memory_vMap[++cpuIndex->sn_PC]);
	holdAddr = holdHiAddr << 8 | holdLoAddr;

	memory_vMap[holdAddr + cpuIndex->sn_X] = 0;
};

extern void snTAX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X = cpuIndex->sn_Acc;
};

extern void snTAY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y = cpuIndex->sn_Acc;
};

extern void snTCD(sn_CPU* cpuIndex) {
	cpuIndex->sn_DP = cpuIndex->sn_Acc;
};

extern void snTDC(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = ((cpuIndex->sn_DP == 0) ? cpuIndex->sn_Acc : 0);
};

extern void snTXA(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = cpuIndex->sn_X;
};

extern void snTXY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y = cpuIndex->sn_X;
};

extern void snTYA(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = cpuIndex->sn_Y;
};

extern void snTYX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X = cpuIndex->sn_Y;
};

extern void snWAI(sn_CPU* cpuIndex) {
	while (!(cpuIndex->sn_IFlag)) {}
};

extern void snXCE(sn_CPU* cpuIndex) {
	u16 temp_C = cpuIndex->sn_CFlag;
	u16 temp_E = cpuIndex->sn_EFlag;

	cpuIndex->sn_EFlag = temp_C;
	cpuIndex->sn_CFlag = temp_E;
};

