
/* i'm tired. */

#include <stdio.h>
#include <unistd.h>

#include "vars/memory.h"
#include "vars/rom.h"
#include "vars/cpu.h"

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
	//memory_vMap[holdAddr] += 1 + (cpuIndex->sn_CFlag == 1 ? 1 : 0);
	cpuIndex->sn_Acc = holdAddr + cpuIndex->sn_CFlag;
}

extern inline void snADC_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = (holdHiAddr << 8 | holdLoAddr);
	cpuIndex->sn_Acc = memory_vMap[holdAddr] + cpuIndex->sn_CFlag;
}

extern inline void snADC_long(sn_CPU* cpuIndex) {

}

extern inline void snADC_dp(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc += memory_vMap[++cpuIndex->sn_PC + cpuIndex->sn_DP] + (cpuIndex->sn_CFlag);
}

extern inline void snADC_dpI(sn_CPU* cpuIndex) {

}

extern inline void snADC_dpI_long(sn_CPU* cpuIndex) {

}

extern inline void snADC_dpXI(sn_CPU* cpuIndex) {
	//cpuIndex->sn_Acc = x + (cpuIndex->sn_CFlag == 1 ? 1 : 0);
}

extern inline void snADC_srS(sn_CPU* cpuIndex) {

}
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

extern void snAND_long(sn_CPU* cpuIndex);
extern void snAND_dpIY(sn_CPU* cpuIndex);
extern void snAND_dpI(sn_CPU* cpuIndex);
extern void snAND_srSIY(sn_CPU* cpuIndex);
extern void snAND_dpX(sn_CPU* cpuIndex);
extern void snAND_dpIY(sn_CPU* cpuIndex);
extern void snAND_addrY(sn_CPU* cpuIndex);
extern void snAND_addrX(sn_CPU* cpuIndex);
extern void snAND_longX(sn_CPU* cpuIndex);

/* Performs a Bit shift to left */
extern void snASL_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[cpuIndex->sn_PC + cpuIndex->sn_DP];
	memory_vMap[holdAddr] <<= 1;
}

extern void snASL_acc(sn_CPU* cpuIndex) {
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

/* This opcodes test bits with the corrsponding one */

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
	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_DP];
};

extern void snCMP_dpI_long(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC];
	holdAddr = memory_vMap[cpuIndex->sn_DP + ++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};

extern void snCMP_const(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= holdAddr;
};

extern void snCMP_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};
extern void snCMP_long(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr];
};

extern void snCMP_dpIY(sn_CPU* cpuIndex);
extern void snCMP_dpI(sn_CPU* cpuIndex);
extern void snCMP_srSIY(sn_CPU* cpuIndex);
extern void snCMP_dpX(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_DP + cpuIndex->sn_X];
};

extern void snCMP_dpI_longY(sn_CPU* cpuIndex);
extern void snCMP_addrY(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_Y];
};

extern void snCMP_addrX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_X];
};


extern void snCMP_longX(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = memory_vMap[++cpuIndex->sn_PC] << 16 | holdHiAddr << 8 | holdLoAddr;

	cpuIndex->sn_Acc -= memory_vMap[holdAddr + cpuIndex->sn_X];
};

/* Decrement 1 to registers */
extern void snDEC_Acc(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc -= 1;
};

extern void snDEC_dp(sn_CPU* cpuIndex){};
extern void snDEC_addr(sn_CPU* cpuIndex){};
extern void snDEC_dpX(sn_CPU* cpuIndex){};
extern void snDEC_addrX(sn_CPU* cpuIndex){};

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
};

extern void snLDA_dpI_long(sn_CPU* cpuIndex);

extern void snLDA_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_MFlag) {
		holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
		holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
		holdAddr = holdHiAddr << 8 | holdLoAddr;
	} else {
		holdAddr = memory_vMap[++cpuIndex->sn_PC];
		if (!cpuIndex->sn_MFlag) {
			++cpuIndex->sn_PC;
		}
	}
	cpuIndex->sn_Acc = holdAddr;
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
	/*
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	for(s8 i = 0; i < sizeof(s8); i ++) {
		u8 x << i;
	}*/
}



extern void snLDA_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	cpuIndex->sn_Acc = memory_vMap[holdAddr];
};

extern void snSTA_dpXI(sn_CPU* cpuIndex);
extern void snSTA_srS(sn_CPU* cpuIndex);
extern void snSTA_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[cpuIndex->sn_PC];
	memory_vMap[holdAddr + cpuIndex->sn_DP] = cpuIndex->sn_Acc;
};

extern void snSTA_dpI_long(sn_CPU* cpuIndex);

extern void snSTA_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	memory_vMap[holdAddr] = cpuIndex->sn_Acc;
	printf("disasm: sta, %X, 0$(%X)\n", cpuIndex->sn_Acc, memory_vMap[holdAddr]);
};

extern void snSTA_long(sn_CPU* cpuIndex);
extern void snSTA_dpIY(sn_CPU* cpuIndex);
extern void snSTA_dpI(sn_CPU* cpuIndex);

extern void snSTZ_dp(sn_CPU* cpuIndex) {
	holdAddr = memory_vMap[++cpuIndex->sn_PC];
	printf("Storing zero at: %X\n", holdAddr + cpuIndex->sn_DP);
	memory_vMap[holdAddr + cpuIndex->sn_DP] = 0;
	printf("disasm: stz, %X$(%X)\n", cpuIndex->sn_Acc, cpuIndex->sn_DP);
};

extern void snSTZ_dpX(sn_CPU* cpuIndex);
extern void snSTZ_addr(sn_CPU* cpuIndex) {
	holdLoAddr = memory_vMap[++cpuIndex->sn_PC];
	holdHiAddr = memory_vMap[++cpuIndex->sn_PC];
	holdAddr = holdHiAddr << 8 | holdLoAddr;
	printf("Turning 0x%04X to zero \n", holdAddr);
	printf("Old 0x%04X value \n", memory_vMap[holdAddr]);
	memory_vMap[holdAddr] = 0;
	printf("New 0x%04X value \n", memory_vMap[holdAddr]);
};

extern void snSTZ_addrX(sn_CPU* cpuIndex);

extern void snTCD(sn_CPU* cpuIndex) {
	cpuIndex->sn_DP = cpuIndex->sn_Acc;
};

extern void snWAI(sn_CPU* cpuIndex) {
	while (!(cpuIndex->sn_IFlag)) {
		usleep(10000);
	}
}
