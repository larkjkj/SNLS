#include <stdlib.h>
#include <unistd.h>

#include "emulator/memory.h"
#include "emulator/init.h"
#include "core/bus.h"

/* Syntax it's basically use the corresponding byte read and
 * pass the following argumetns:
 * CPU pointer -> emulator->cpu
 * Offset -> 0 / emulator->cpu->sn_DP / emulator->cpu->sn_X
 * (There's a reason to bus have 2 differents offset, 'cause
 * SNES have X indexed addresses or DP indexed, or indirect acesses)
 */

extern void sn_OpBMI(emGeneral* emulator) {
	if (emulator->cpu->sn_NFlag)
		emulator->cpu->sn_PC += (s8) sn_Mread_u8_const(emulator->cpu, 0);
	return;
};

extern void sn_OpBPL(emGeneral* emulator) {
	if (!emulator->cpu->sn_NFlag) {
		emulator->cpu->sn_PC = emulator->cpu->sn_PC + (s8) sn_Mread_u8_const(emulator->cpu, 0) + 1;
		usleep(10000);
	} else {
		printf("exiting \n");
		sleep(3);
	}
	return;
};

extern void sn_OpBRA(emGeneral* emulator) {
	emulator->cpu->sn_PC = emulator->cpu->sn_PC + (*emulator->cpu->sn_PC - (s8) sn_Mread_u8_const(emulator->cpu, 0));
	return;
};

extern void sn_OpCLC(emGeneral* emulator) {
	emulator->cpu->sn_CFlag = 0;
	return;
};

extern void sn_OpCLD(emGeneral* emulator) {
	emulator->cpu->sn_DFlag = 0;
	return;
};

extern void sn_OpCLI(emGeneral* emulator) {
	emulator->cpu->sn_IFlag = 0;
	return;
};

extern void sn_OpCLV(emGeneral* emulator) {
	emulator->cpu->sn_VFlag = 0;
	return;
};

extern void sn_OpDEA(emGeneral* emulator) {
	emulator->cpu->sn_Acc -= 1;
	return;
};

extern void sn_OpDEX(emGeneral* emulator) {
	emulator->cpu->sn_X -= 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_X < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpDEY(emGeneral* emulator) {
	emulator->cpu->sn_Y -= 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Y < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpJSR_addr(emGeneral* emulator) {
	emulator->cpu->sn_PC = sn_Mread_u16(emulator->cpu, 0, true);
	return;
};

extern void sn_OpINA(emGeneral* emulator) {
	emulator->cpu->sn_Acc += 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Acc < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_dp(emGeneral* emulator) {
	emulator->cpu->sn_DP += 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_DP < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_DP == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_addr(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, 0, sn_Mread_u16(emulator->cpu, 0, false), +1);
	emulator->cpu->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_dpX(emGeneral* emulator) {
	holdAddr = *sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_X, sn_Mread_u8(emulator->cpu, emulator->cpu->sn_DP), +1);
	emulator->cpu->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINC_addrX(emGeneral* emulator) {
	holdAddr = *sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_X, sn_Mread_u16(emulator->cpu, 0, false), +1);
	emulator->cpu->sn_NFlag = ((s16) holdAddr < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (holdAddr == 0 ? 1 : 0);
	return;
};

extern void sn_OpINX(emGeneral* emulator) {
	emulator->cpu->sn_X += 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_X < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpINY(emGeneral* emulator) {
	emulator->cpu->sn_Y += 1;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Y < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpJMP_addr(emGeneral* emulator) {
	emulator->cpu->sn_PC = (u8*) sn_Mread_u16(emulator->cpu, 0, false) - 1;
	return;
};

extern void sn_OpJMP_long(emGeneral* emulator) {
	emulator->cpu->sn_PC = sn_Mread_u24(emulator->cpu, 0, true) - 1;
	return;
};

extern void sn_OpLDA_const(emGeneral* emulator) {
	if (!emulator->cpu->sn_MFlag) {
		emulator->cpu->sn_Acc = sn_Mread_u16_const(emulator->cpu, 0);
	} else {
		emulator->cpu->sn_Acc = sn_Mread_u8_const(emulator->cpu, 0);
	}
	emulator->cpu->sn_NFlag = (s16) emulator->cpu->sn_Acc < 0 ? 1 : 0;
	emulator->cpu->sn_ZFlag = emulator->cpu->sn_Acc == 0 ? 1 : 0;
	return;
};

extern void sn_OpLDX_const(emGeneral* emulator) {
	if (!emulator->cpu->sn_XFlag) {
		emulator->cpu->sn_X = sn_Mread_u16_const(emulator->cpu, 0);
	} else {
		emulator->cpu->sn_X = sn_Mread_u8_const(emulator->cpu, 0);
	}
	emulator->cpu->sn_NFlag = (s16) emulator->cpu->sn_X < 0 ? 1 : 0;
	emulator->cpu->sn_ZFlag = emulator->cpu->sn_X == 0 ? 1 : 0;
	return;
};

extern void sn_OpLDY_addr(emGeneral* emulator) {
	/*TODO: make new functions for replacing
	 * pointer dereference of u16 addresses */
	emulator->cpu->sn_Y = *sn_Mread_u16(emulator->cpu, 0, false);
	emulator->cpu->sn_NFlag = (s16) emulator->cpu->sn_Y < 0 ? 1 : 0;
	emulator->cpu->sn_ZFlag = emulator->cpu->sn_Y == 0 ? 1 : 0;
	return;
};
extern void sn_OpLDY_const(emGeneral* emulator) {
	if (!emulator->cpu->sn_XFlag) {
		emulator->cpu->sn_Y = sn_Mread_u16_const(emulator->cpu, 0);
	} else {
		emulator->cpu->sn_Y = sn_Mread_u8_const(emulator->cpu, 0);
	}
	emulator->cpu->sn_NFlag = (s16) emulator->cpu->sn_Y < 0 ? 1 : 0;
	emulator->cpu->sn_ZFlag = emulator->cpu->sn_Y == 0 ? 1 : 0;
	return;
};

extern void sn_OpSTA_addr(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, 0, sn_Mread_u16(emulator->cpu, 0, false), emulator->cpu->sn_Acc);
	return;
};

extern void sn_OpSTA_long(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, 0, sn_Mread_u24(emulator->cpu, 0, false), emulator->cpu->sn_Acc);
	return;
};

extern void sn_OpSTA_longX(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_X, sn_Mread_u24(emulator->cpu, 0, false), emulator->cpu->sn_Acc);
	return;
};

extern void sn_OpSTZ_dp(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_DP, sn_Mread_u8(emulator->cpu, 0), 0);
	return;
};
extern void sn_OpSTZ_dpX(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_X, sn_Mread_u8(emulator->cpu, emulator->cpu->sn_DP), 0);
	return;
};
extern void sn_OpSTZ_addr(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, 0, sn_Mread_u16(emulator->cpu, 0, false), 0);
	return;
};
extern void sn_OpSTZ_addrX(emGeneral* emulator) {
	sn_Mwrite_ptr(emulator->cpu, emulator->cpu->sn_X, sn_Mread_u16(emulator->cpu, 0, false), 0);
	return;
};

extern void sn_OpSEC(emGeneral* emulator) {
	emulator->cpu->sn_CFlag = 1;
	return;
};

extern void sn_OpSED(emGeneral* emulator) {
	emulator->cpu->sn_DFlag = 1;
	return;
};

extern void sn_OpSEI(emGeneral* emulator) {
	emulator->cpu->sn_IFlag = 1;
	return;
};

extern void sn_OpREP(emGeneral* emulator) {
	sn_Mread_u8_const(emulator->cpu, 0);
	emulator->cpu->sn_CFlag = (*emulator->cpu->sn_PC & 0x80 ? 0 : emulator->cpu->sn_CFlag);
	emulator->cpu->sn_VFlag = (*emulator->cpu->sn_PC & 0x40 ? 0 : emulator->cpu->sn_VFlag);
	emulator->cpu->sn_MFlag = (*emulator->cpu->sn_PC & 0x20 ? 0 : emulator->cpu->sn_MFlag);
	emulator->cpu->sn_XFlag = (*emulator->cpu->sn_PC & 0x10 ? 0 : emulator->cpu->sn_XFlag);
	emulator->cpu->sn_DFlag = (*emulator->cpu->sn_PC & 0x08 ? 0 : emulator->cpu->sn_DFlag);
	emulator->cpu->sn_IFlag = (*emulator->cpu->sn_PC & 0x04 ? 0 : emulator->cpu->sn_IFlag);
	emulator->cpu->sn_ZFlag = (*emulator->cpu->sn_PC & 0x02 ? 0 : emulator->cpu->sn_ZFlag);
	emulator->cpu->sn_EFlag = (*emulator->cpu->sn_PC & 0x01 ? 0 : emulator->cpu->sn_EFlag);
	return;
};

extern void sn_OpSBC_const(emGeneral* emulator) {
	if (!emulator->cpu->sn_MFlag) {
		emulator->cpu->sn_Acc = emulator->cpu->sn_Acc - sn_Mread_u16_const(emulator->cpu, 0) + (!emulator->cpu->sn_CFlag ? 1 : 0);
	} else {
		emulator->cpu->sn_Acc = emulator->cpu->sn_Acc - sn_Mread_u8_const(emulator->cpu, 0) + (!emulator->cpu->sn_CFlag ? 1 : 0);
	}
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Acc < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Acc == 0 ? 1 : 0);
	emulator->cpu->sn_VFlag = ((emulator->cpu->sn_Acc) > 0xFFFF ? 1 : 0);
	emulator->cpu->sn_CFlag = ((s16) emulator->cpu->sn_Acc == 0 ? 1 : 0);
};

extern void sn_OpSEP(emGeneral* emulator) {
	sn_Mread_u8_const(emulator->cpu, 0);
	emulator->cpu->sn_CFlag = (*emulator->cpu->sn_PC & 0x80 ? 1 : emulator->cpu->sn_CFlag);
	emulator->cpu->sn_VFlag = (*emulator->cpu->sn_PC & 0x40 ? 1 : emulator->cpu->sn_VFlag);
	emulator->cpu->sn_MFlag = (*emulator->cpu->sn_PC & 0x20 ? 1 : emulator->cpu->sn_MFlag);
	emulator->cpu->sn_XFlag = (*emulator->cpu->sn_PC & 0x10 ? 1 : emulator->cpu->sn_XFlag);
	emulator->cpu->sn_DFlag = (*emulator->cpu->sn_PC & 0x08 ? 1 : emulator->cpu->sn_DFlag);
	emulator->cpu->sn_IFlag = (*emulator->cpu->sn_PC & 0x04 ? 1 : emulator->cpu->sn_IFlag);
	emulator->cpu->sn_ZFlag = (*emulator->cpu->sn_PC & 0x02 ? 1 : emulator->cpu->sn_ZFlag);
	emulator->cpu->sn_EFlag = (*emulator->cpu->sn_PC & 0x01 ? 1 : emulator->cpu->sn_EFlag);
	printf("sep \n");
	sleep(1);
	return;
};

extern void sn_OpTAX(emGeneral* emulator) {
	emulator->cpu->sn_X = emulator->cpu->sn_Acc;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_X < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_X == 0 ? 1 : 0);
	return;
};

extern void sn_OpTAY(emGeneral* emulator) {
	emulator->cpu->sn_Y = emulator->cpu->sn_Acc;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Y < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Y == 0 ? 1 : 0);
	return;
};

extern void sn_OpTCD(emGeneral* emulator) {
	emulator->cpu->sn_DP = emulator->cpu->sn_Acc;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_DP < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_DP == 0 ? 1 : 0);
	return;
};

extern void sn_OpTXY(emGeneral* emulator) {
	emulator->cpu->sn_Acc = emulator->cpu->sn_Y;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Acc < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpTYA(emGeneral* emulator) {
	emulator->cpu->sn_Acc = emulator->cpu->sn_Y;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Acc < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Acc == 0 ? 1 : 0);
	return;
};
extern void sn_OpTYX(emGeneral* emulator) {
	emulator->cpu->sn_Acc = emulator->cpu->sn_Y;
	emulator->cpu->sn_NFlag = ((s16) emulator->cpu->sn_Acc < 0 ? 1 : 0);
	emulator->cpu->sn_ZFlag = (emulator->cpu->sn_Acc == 0 ? 1 : 0);
	return;
};

extern void sn_OpXCE(emGeneral* emulator) {
	u16 temp_C = emulator->cpu->sn_CFlag;
	u16 temp_E = emulator->cpu->sn_EFlag;

	emulator->cpu->sn_EFlag = temp_C;
	emulator->cpu->sn_CFlag = temp_E;
	return;
};
