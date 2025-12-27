#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "core/cpu/opcodes.h"
#include "core/cpu/ricoh.h"
#include "emulator/main.h"
#include "emulator/memory.h"
#include "emulator/rom.h"
#include "core/bus.h"

//#include "interpreter.h"
static void fetchCPU(emGeneral* emulator) {
	*emulator->active |= 0x01;
	printf("cpu_fetch: a: %X x: %X y: %X eF: %X mF: %X \n", emulator->cpu->sn_Acc, emulator->cpu->sn_X, emulator->cpu->sn_Y, emulator->cpu->sn_EFlag, emulator->cpu->sn_MFlag);
	printf("cpu_opcode: %X \n", *emulator->cpu->sn_PC);
	printf("cpu_steps: %d\n", emulator->cpu->steps);
	switch (*(emulator->cpu->sn_PC)) {
		case _bmi:
			sn_OpBMI(emulator);
			break;
		case _bne:
			sn_OpBNE(emulator);
			break;
		case _bpl:
			sn_OpBPL(emulator);
			break;
		case _bra:
			sn_OpBRA(emulator);
			break;
		case _clc:
			sn_OpCLC(emulator);
			break;
		case _cld:
			sn_OpCLD(emulator);
			break;
		case _cli:
			sn_OpCLI(emulator);
			break;
		case _clv:
			sn_OpCLV(emulator);
			break;
		case _cmp_addr:
			sn_OpCMP_addr(emulator);
			break;
		case _dea:
			sn_OpDEA(emulator);
			break;
		case _dex:
			sn_OpDEX(emulator);
			break;
		case _dey:
			sn_OpDEY(emulator);
			break;
		case _inc_a:
			sn_OpINA(emulator);
			break;
		case _inc_dp:
			sn_OpINC_dp(emulator);
			break;
		case _inc_addr:
			sn_OpINC_addr(emulator);
			break;
		case _inc_dp_x:
			sn_OpINC_dpX(emulator);
			break;
		case _inc_addr_x:
			sn_OpINC_addrX(emulator);
			break;
		case _jmp_addr:
			sn_OpJMP_addr(emulator);
			break;
		case _jsr_addr:
			sn_OpJSR_addr(emulator);
			break;
		case _lda_addr:
			sn_OpLDA_addr(emulator);
			break;
		case _lda_const:
			sn_OpLDA_const(emulator);
			break;
		case _ldx_const:
			sn_OpLDX_const(emulator);
			break;
		case _ldy_addr:
			sn_OpLDY_addr(emulator);
			break;
		case _ldy_const:
			sn_OpLDY_const(emulator);
			break;
		case _sec:
			sn_OpSEC(emulator);
			break;
		case _sed:
			sn_OpSED(emulator);
			break;
		case _sbc_const:
			sn_OpSBC_const(emulator);
			break;
		case _sei:
			sn_OpSEI(emulator);
			break;
		case _rep:
			sn_OpREP(emulator);
			break;
		case _sep:
			sn_OpSEP(emulator);
			break;
		case _sta_addr:
			sn_OpSTA_addr(emulator);
			break;
		case _sta_l:
			sn_OpSTA_long(emulator);
			break;
		case _sta_l_x:
			sn_OpSTA_longX(emulator);
			break;
		case _stz_dp:
			sn_OpSTZ_dp(emulator);
			break;
		case _stz_dp_x:
			sn_OpSTZ_dpX(emulator);
			break;
		case _stz_addr:
			sn_OpSTZ_addr(emulator);
			break;
		case _stz_addr_x:
			sn_OpSTZ_addrX(emulator);
			break;
		case _tax:
			sn_OpTAX(emulator);
			break;
		case _tay:
			sn_OpTAY(emulator);
			break;
		case _tcd:
			sn_OpTCD(emulator);
			break;
		case _txy:
			sn_OpTXY(emulator);
			break;
		case _tya:
			sn_OpTYA(emulator);
			break;
		case _tyx:
			sn_OpTYX(emulator);
			break;
		case _xce:
			sn_OpXCE(emulator);
			break;
		case 0x00:
			printf("cpu_fetch: cpu crossed at zero, something wrong? \nlast byte: %02X current byte: %02X next byte: %02X at address: %X\n", *(emulator->cpu->sn_PC - 1), *emulator->cpu->sn_PC, *(emulator->cpu->sn_PC + 1), emulator->memory->address_target);
			emulator->cpu->sn_PC++;
			//sleep(2);
			break;
		default:
			printf("cpu_fetch: unknown opcode %X \n",*(emulator->cpu->sn_PC));
			++emulator->cpu->sn_PC;
			break;
	};
	*emulator->active ^= 0x01;
	emulator->endfetch(emulator);
}

extern void setupCPU(emGeneral *emulator, rom* rom_Ptr) {
	printf("cpu_setup: init\n");
	/* Emulation Mode */
	emulator->cpu->sn_EFlag = 1;
	emulator->cpu->sn_MFlag = 1;
	emulator->cpu->sn_XFlag = 1;

	/* this sets registers to zero
	 * this is only made for debugging
	 * the real SNES can point these
	 * values to every thing */
	emulator->cpu->sn_P = 0;
	emulator->cpu->sn_PB = 0;
	emulator->cpu->sn_DBR = 0;
	emulator->cpu->fetch = fetchCPU;

	printf("cpu_setup: done\n");
	emulator->cpu->sn_PC = &emulator->memory->bank_array[emulator->cpu->sn_DBR][rom_Ptr->resetV - 0x8000];
	printf("cpu_setup: starting at %X %X \n", emulator->memory->bank_array[emulator->cpu->sn_DBR][0], emulator->cpu->sn_PC);
}


