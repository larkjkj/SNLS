#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memory_funcs.h"
#include "gs_funcs.h"
#include "bus_funcs.h"
#include "ppu_funcs.h"

#include "cpu_opcodes.h"
#include "interpreter.h"

#include "vars/memory.h"
#include "vars/rom.h"
#include "vars/cpu.h"

//#include "interpreter.h"
extern struct sn_CPU* initCPU(rom* rom_Ptr) {
	struct sn_CPU* newCPU;

	newCPU = malloc(sizeof(sn_CPU));
	/* Emulation Mode */
	newCPU->sn_EFlag = 1;
	newCPU->sn_MFlag = 1;
	newCPU->sn_XFlag = 1;

	newCPU->sn_DP = 0;
	newCPU->sn_PB = 0;
	printf("Basic CPU created(8B-M) \n");
	printf("Reset Vector: %X\n", rom_Ptr->resetV);

	newCPU->sn_PC = &mBank[newCPU->sn_DP][rom_Ptr->resetV];
	return newCPU;
}

extern void fetchCPU(sn_CPU* cpuIndex) {
	printf("Fetching ..\n");
	while (1) {
		//printf("%X \n", emuMemory.memory_rPPU[0x2140]);
		switch (*(cpuIndex->sn_PC)) {
			case _bmi:
				sn_OpBMI(cpuIndex);
				break;
			case _bpl:
				sn_OpBPL(cpuIndex);
				break;
			case _bra:
				sn_OpBRA(cpuIndex);
				break;
			case _clc:
				sn_OpCLC(cpuIndex);
				break;
			case _cld:
				sn_OpCLD(cpuIndex);
				break;
			case _cli:
				sn_OpCLI(cpuIndex);
				break;
			case _clv:
				sn_OpCLV(cpuIndex);
				break;
			case _dea:
				sn_OpDEA(cpuIndex);
				break;
			case _dex:
				sn_OpDEX(cpuIndex);
				break;
			case _dey:
				sn_OpDEY(cpuIndex);
				break;
			case _inc_a:
				sn_OpINA(cpuIndex);
				break;
			case _inc_dp:
				sn_OpINC_dp(cpuIndex);
				break;
			case _inc_addr:
				sn_OpINC_addr(cpuIndex);
				break;
			case _inc_dp_x:
				sn_OpINC_dpX(cpuIndex);
				break;
			case _inc_addr_x:
				sn_OpINC_addrX(cpuIndex);
				break;
			case _jmp_addr:
				sn_OpJMP_addr(cpuIndex);
				break;
			case _lda_const:
				sn_OpLDA_const(cpuIndex);
				break;
			case _ldx_const:
				sn_OpLDX_const(cpuIndex);
				break;
			case _sec:
				sn_OpSEC(cpuIndex);
				break;
			case _sed:
				sn_OpSED(cpuIndex);
				break;
			case _sei:
				sn_OpSEI(cpuIndex);
				break;
			case _rep:
				sn_OpREP(cpuIndex);
				break;
			case _sep:
				sn_OpSEP(cpuIndex);
				break;
			case _sta_addr:
				sn_OpSTA_addr(cpuIndex);
				break;
			case _sta_l:
				sn_OpSTA_long(cpuIndex);
				break;
			case _sta_l_x:
				sn_OpSTA_longX(cpuIndex);
				break;
			case _stz_dp:
				sn_OpSTZ_dp(cpuIndex);
				break;
			case _stz_dp_x:
				sn_OpSTZ_dpX(cpuIndex);
				break;
			case _stz_addr:
				sn_OpSTZ_addr(cpuIndex);
				break;
			case _stz_addr_x:
				sn_OpSTZ_addrX(cpuIndex);
				break;
			case _tax:
				sn_OpTAX(cpuIndex);
				break;
			case _tay:
				sn_OpTAY(cpuIndex);
				break;
			case _tcd:
				sn_OpTCD(cpuIndex);
				break;
			case _txy:
				sn_OpTXY(cpuIndex);
				break;
			case _tya:
				sn_OpTYA(cpuIndex);
				break;
			case _tyx:
				sn_OpTYX(cpuIndex);
				break;
			case _xce:
				sn_OpXCE(cpuIndex);
				break;
			default:
				printf("Unknown opcode %X \n",*(cpuIndex->sn_PC));
				break;
		};

		break;
	}
		usleep(1000000);
	++cpuIndex->sn_PC;
}
