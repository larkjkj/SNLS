#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "core/cpu/opcodes.h"
#include "core/cpu/interpreter.h"
#include "core/cpu/ricoh.h"

#include "emulator/memory.h"
#include "emulator/rom.h"
#include "core/bus.h"

//#include "interpreter.h"
extern void setupCPU(sn_CPU *cpu, rom* rom_Ptr) {
	/* Emulation Mode */
	cpu->sn_EFlag = 1;
	cpu->sn_MFlag = 1;
	cpu->sn_XFlag = 1;
	cpu->sn_DP = 0;
	cpu->sn_PB = 0;

	cpu->sn_PC = mBank[cpu->sn_DP][rom_Ptr->resetV];
	printf("cpu_setup: starting at %p \n", cpu->sn_PC);
	//cpu->sn_PC = &mBank[cpu->sn_DP][0x8000];
}

extern void fetchCPU(sn_CPU* cpu) {
	printf("cpu_fetch: reading opcode %X \n", *cpu->sn_PC);
	switch (*(cpu->sn_PC)) {
		case _bmi:
			sn_OpBMI(cpu);
			break;
		case _bpl:
			sn_OpBPL(cpu);
			break;
		case _bra:
			sn_OpBRA(cpu);
			break;
		case _clc:
			sn_OpCLC(cpu);
			break;
		case _cld:
			sn_OpCLD(cpu);
			break;
		case _cli:
			sn_OpCLI(cpu);
			break;
		case _clv:
			sn_OpCLV(cpu);
			break;
		case _dea:
			sn_OpDEA(cpu);
			break;
		case _dex:
			sn_OpDEX(cpu);
			break;
		case _dey:
			sn_OpDEY(cpu);
			break;
		case _inc_a:
			sn_OpINA(cpu);
			break;
		case _inc_dp:
			sn_OpINC_dp(cpu);
			break;
		case _inc_addr:
			sn_OpINC_addr(cpu);
			break;
		case _inc_dp_x:
			sn_OpINC_dpX(cpu);
			break;
		case _inc_addr_x:
			sn_OpINC_addrX(cpu);
			break;
		case _jmp_addr:
			sn_OpJMP_addr(cpu);
			break;
		case _lda_const:
			sn_OpLDA_const(cpu);
			break;
		case _ldx_const:
			sn_OpLDX_const(cpu);
			break;
		case _sec:
			sn_OpSEC(cpu);
			break;
		case _sed:
			sn_OpSED(cpu);
			break;
		case _sei:
			sn_OpSEI(cpu);
			break;
		case _rep:
			sn_OpREP(cpu);
			break;
		case _sep:
			sn_OpSEP(cpu);
			break;
		case _sta_addr:
			sn_OpSTA_addr(cpu);
			break;
		case _sta_l:
			sn_OpSTA_long(cpu);
			break;
		case _sta_l_x:
			sn_OpSTA_longX(cpu);
			break;
		case _stz_dp:
			sn_OpSTZ_dp(cpu);
			break;
		case _stz_dp_x:
			sn_OpSTZ_dpX(cpu);
			break;
		case _stz_addr:
			sn_OpSTZ_addr(cpu);
			break;
		case _stz_addr_x:
			sn_OpSTZ_addrX(cpu);
			break;
		case _tax:
			sn_OpTAX(cpu);
			break;
		case _tay:
			sn_OpTAY(cpu);
			break;
		case _tcd:
			sn_OpTCD(cpu);
			break;
		case _txy:
			sn_OpTXY(cpu);
			break;
		case _tya:
			sn_OpTYA(cpu);
			break;
		case _tyx:
			sn_OpTYX(cpu);
			break;
		case _xce:
			sn_OpXCE(cpu);
			break;
		default:
			printf("cpu_fetch: unknown opcode %X \n",*(cpu->sn_PC));
			break;
	};

	//usleep(1000000);*/
	++cpu->sn_PC;
}
