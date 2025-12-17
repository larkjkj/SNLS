#include <stdlib.h>
#include <unistd.h>

#include "emulator/memory.h"
#include "core/cpu/ricoh.h"
#include "core/bus.h"

/* Syntax it's basically use the corresponding byte read and
 * pass the following argumetns:
 * CPU pointer -> cpuIndex
 * Offset -> 0 / cpuIndex->sn_DP / cpuIndex->sn_X
 * (There's a reason to bus have 2 differents offset, 'cause
 * SNES have X indexed addresses or DP indexed, or indirect acesses)
 */

extern void sn_OpBMI(sn_CPU* cpuIndex) {
	if (cpuIndex->sn_NFlag)
		cpuIndex->sn_PC += (s8) sn_Mread_u8_const(cpuIndex, 0);
	return;
};

extern void sn_OpBPL(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_NFlag) {
		cpuIndex->sn_PC = cpuIndex->sn_PC + (s8) sn_Mread_u8_const(cpuIndex, 0) + 1;
		usleep(10000);
	} else {
		printf("exiting \n");
		sleep(3);
	}
	return;
};

extern void sn_OpBRA(sn_CPU* cpuIndex) {
	cpuIndex->sn_PC = cpuIndex->sn_PC + (*cpuIndex->sn_PC - (s8) sn_Mread_u8_const(cpuIndex, 0));
	return;
};

extern void sn_OpCLC(sn_CPU* cpuIndex) {
	cpuIndex->sn_CFlag = 0;
	return;
};

extern void sn_OpCLD(sn_CPU* cpuIndex) {
	cpuIndex->sn_DFlag = 0;
	return;
};

extern void sn_OpCLI(sn_CPU* cpuIndex) {
	cpuIndex->sn_IFlag = 0;
	return;
};

extern void sn_OpCLV(sn_CPU* cpuIndex) {
	cpuIndex->sn_VFlag = 0;
	return;
};

extern void sn_OpDEA(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc -= 1;
	return;
};

extern void sn_OpDEX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X -= 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_X < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpDEY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y -= 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Y < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpJSR_addr(sn_CPU* cpuIndex) {
	cpuIndex->sn_PC = sn_Mread_u16(cpuIndex, 0, true);
	return;
};

extern void sn_OpINA(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc += 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Acc < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_dp(sn_CPU* cpuIndex) {
	cpuIndex->sn_DP += 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_DP < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_DP == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_addr(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, 0, sn_Mread_u16(cpuIndex, 0, false), +1);
	cpuIndex->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_dpX(sn_CPU* cpuIndex) {
	holdAddr = *sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_X, sn_Mread_u8(cpuIndex, cpuIndex->sn_DP), +1);
	cpuIndex->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_addrX(sn_CPU* cpuIndex) {
	holdAddr = *sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_X, sn_Mread_u16(cpuIndex, 0, false), +1);
	cpuIndex->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X += 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_X < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpINY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y += 1;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Y < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpJMP_addr(sn_CPU* cpuIndex) {
	cpuIndex->sn_PC = (u8*) sn_Mread_u16(cpuIndex, 0, false) - 1;
	return;
};

extern void sn_OpJMP_long(sn_CPU* cpuIndex) {
	cpuIndex->sn_PC = sn_Mread_u24(cpuIndex, 0, true) - 1;
	return;
};

extern void sn_OpLDA_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_MFlag) {
		cpuIndex->sn_Acc = sn_Mread_u16_const(cpuIndex, 0);
	} else {
		cpuIndex->sn_Acc = sn_Mread_u8_const(cpuIndex, 0);
	}
	cpuIndex->sn_NFlag = (s16) cpuIndex->sn_Acc < 0 ? 1 : 0;
	cpuIndex->sn_ZFlag = cpuIndex->sn_Acc == 0 ? 1 : 0;
	return;
};

extern void sn_OpLDX_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_XFlag) {
		cpuIndex->sn_X = sn_Mread_u16_const(cpuIndex, 0);
	} else {
		cpuIndex->sn_X = sn_Mread_u8_const(cpuIndex, 0);
	}
	cpuIndex->sn_NFlag = (s16) cpuIndex->sn_X < 0 ? 1 : 0;
	cpuIndex->sn_ZFlag = cpuIndex->sn_X == 0 ? 1 : 0;
	return;
};

extern void sn_OpLDY_addr(sn_CPU* cpuIndex) {
	/*TODO: make new functions for replacing
	 * pointer dereference of u16 addresses */
	cpuIndex->sn_Y = *sn_Mread_u16(cpuIndex, 0, false);
	cpuIndex->sn_NFlag = (s16) cpuIndex->sn_Y < 0 ? 1 : 0;
	cpuIndex->sn_ZFlag = cpuIndex->sn_Y == 0 ? 1 : 0;
	return;
};
extern void sn_OpLDY_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_XFlag) {
		cpuIndex->sn_Y = sn_Mread_u16_const(cpuIndex, 0);
	} else {
		cpuIndex->sn_Y = sn_Mread_u8_const(cpuIndex, 0);
	}
	cpuIndex->sn_NFlag = (s16) cpuIndex->sn_Y < 0 ? 1 : 0;
	cpuIndex->sn_ZFlag = cpuIndex->sn_Y == 0 ? 1 : 0;
	return;
};

extern void sn_OpSTA_addr(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, 0, sn_Mread_u16(cpuIndex, 0, false), cpuIndex->sn_Acc);
	return;
};

extern void sn_OpSTA_long(sn_CPU *cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, 0, sn_Mread_u24(cpuIndex, 0, false), cpuIndex->sn_Acc);
	return;
};

extern void sn_OpSTA_longX(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_X, sn_Mread_u24(cpuIndex, 0, false), cpuIndex->sn_Acc);
	return;
};

extern void sn_OpSTZ_dp(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_DP, sn_Mread_u8(cpuIndex, 0), 0);
	return;
};
extern void sn_OpSTZ_dpX(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_X, sn_Mread_u8(cpuIndex, cpuIndex->sn_DP), 0);
	return;
};
extern void sn_OpSTZ_addr(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, 0, sn_Mread_u16(cpuIndex, 0, false), 0);
	return;
};
extern void sn_OpSTZ_addrX(sn_CPU* cpuIndex) {
	sn_Mwrite_ptr(cpuIndex, cpuIndex->sn_X, sn_Mread_u16(cpuIndex, 0, false), 0);
	return;
};

extern void sn_OpSEC(sn_CPU* cpuIndex) {
	cpuIndex->sn_CFlag = 1;
	return;
};

extern void sn_OpSED(sn_CPU* cpuIndex) {
	cpuIndex->sn_DFlag = 1;
	return;
};

extern void sn_OpSEI(sn_CPU* cpuIndex) {
	cpuIndex->sn_IFlag = 1;
	return;
};

extern void sn_OpREP(sn_CPU* cpuIndex) {
	sn_Mread_u8_const(cpuIndex, 0);
	cpuIndex->sn_CFlag = (*cpuIndex->sn_PC & 0x80 ? 0 : cpuIndex->sn_CFlag);
	cpuIndex->sn_VFlag = (*cpuIndex->sn_PC & 0x40 ? 0 : cpuIndex->sn_VFlag);
	cpuIndex->sn_MFlag = (*cpuIndex->sn_PC & 0x20 ? 0 : cpuIndex->sn_MFlag);
	cpuIndex->sn_XFlag = (*cpuIndex->sn_PC & 0x10 ? 0 : cpuIndex->sn_XFlag);
	cpuIndex->sn_DFlag = (*cpuIndex->sn_PC & 0x08 ? 0 : cpuIndex->sn_DFlag);
	cpuIndex->sn_IFlag = (*cpuIndex->sn_PC & 0x04 ? 0 : cpuIndex->sn_IFlag);
	cpuIndex->sn_ZFlag = (*cpuIndex->sn_PC & 0x02 ? 0 : cpuIndex->sn_ZFlag);
	cpuIndex->sn_EFlag = (*cpuIndex->sn_PC & 0x01 ? 0 : cpuIndex->sn_EFlag);
	return;
};

extern void sn_OpSBC_const(sn_CPU* cpuIndex) {
	if (!cpuIndex->sn_MFlag) {
		cpuIndex->sn_Acc = cpuIndex->sn_Acc - sn_Mread_u16_const(cpuIndex, 0) + (!cpuIndex->sn_CFlag ? 1 : 0);
	} else {
		cpuIndex->sn_Acc = cpuIndex->sn_Acc - sn_Mread_u8_const(cpuIndex, 0) + (!cpuIndex->sn_CFlag ? 1 : 0);
	}
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Acc < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc == 0 ? 1 : 0);
	cpuIndex->sn_VFlag = ((cpuIndex->sn_Acc) > 0xFFFF ? 1 : 0);
	cpuIndex->sn_CFlag = ((s16) cpuIndex->sn_Acc == 0 ? 1 : 0);
};

extern void sn_OpSEP(sn_CPU* cpuIndex) {
	sn_Mread_u8_const(cpuIndex, 0);
	cpuIndex->sn_CFlag = (*cpuIndex->sn_PC & 0x80 ? 1 : cpuIndex->sn_CFlag);
	cpuIndex->sn_VFlag = (*cpuIndex->sn_PC & 0x40 ? 1 : cpuIndex->sn_VFlag);
	cpuIndex->sn_MFlag = (*cpuIndex->sn_PC & 0x20 ? 1 : cpuIndex->sn_MFlag);
	cpuIndex->sn_XFlag = (*cpuIndex->sn_PC & 0x10 ? 1 : cpuIndex->sn_XFlag);
	cpuIndex->sn_DFlag = (*cpuIndex->sn_PC & 0x08 ? 1 : cpuIndex->sn_DFlag);
	cpuIndex->sn_IFlag = (*cpuIndex->sn_PC & 0x04 ? 1 : cpuIndex->sn_IFlag);
	cpuIndex->sn_ZFlag = (*cpuIndex->sn_PC & 0x02 ? 1 : cpuIndex->sn_ZFlag);
	cpuIndex->sn_EFlag = (*cpuIndex->sn_PC & 0x01 ? 1 : cpuIndex->sn_EFlag);
	printf("sep \n");
	sleep(1);
	return;
};

extern void sn_OpTAX(sn_CPU* cpuIndex) {
	cpuIndex->sn_X = cpuIndex->sn_Acc;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_X < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpTAY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Y = cpuIndex->sn_Acc;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Y < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpTCD(sn_CPU* cpuIndex) {
	cpuIndex->sn_DP = cpuIndex->sn_Acc;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_DP < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_DP == 0 ? 1 : 0);
	return;
};

extern void sn_OpTXY(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = cpuIndex->sn_Y;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Acc < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpTYA(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = cpuIndex->sn_Y;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Acc < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc == 0 ? 1 : 0);
	return;
};
extern void sn_OpTYX(sn_CPU* cpuIndex) {
	cpuIndex->sn_Acc = cpuIndex->sn_Y;
	cpuIndex->sn_NFlag = ((s16) cpuIndex->sn_Acc < 0 ? 1 : 0);
	cpuIndex->sn_ZFlag = (cpuIndex->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpXCE(sn_CPU* cpuIndex) {
	u16 temp_C = cpuIndex->sn_CFlag;
	u16 temp_E = cpuIndex->sn_EFlag;

	cpuIndex->sn_EFlag = temp_C;
	cpuIndex->sn_CFlag = temp_E;
	return;
};
