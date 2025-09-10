#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memory_funcs.h"
#include "bus_funcs.h"
#include "ppu_funcs.h"

#include "cpu_opcodes.h"
#include "interpreter.h"

#include "vars/memory.h"
#include "vars/rom.h"
#include "vars/cpu.h"

//#include "interpreter.h"

void rcCPU(sn_CPU* cpuIndex, rom* rom_Ptr) {

	/* POWERON */
	cpuIndex->sn_PB = 0x00;
	cpuIndex->sn_DBR = 0x00;
	cpuIndex->sn_EFlag = 1;
	if (cpuIndex->sn_EFlag) {
		cpuIndex->sn_XFlag = 1;
		cpuIndex->sn_MFlag = 1;
	}

	//cpuIndex->sn_PC = (rom_Ptr->resetV - 0x8000);cpuIndex->sn_PC = (u32*)(memory_Bank[cpuIndex->sn_PB] + 0x203);
	//cpuIndex->sn_PC = (memory_Bank[cpuIndex->sn_PB] + 0x203);
	//cpuIndex->sn_PC = (memory_Bank[cpuIndex->sn_PB] + (rom_Ptr->resetV));
	//cpuIndex->sn_PC = *(mBank[cpuIndex->sn_PB] + rom_Ptr->resetV);
	cpuIndex->sn_PC = m_Buf[0x0].mMap[0x8000];
	if (cpuIndex->sn_PC == NULL) {
	    printf("Error, PC is null, something gone wrong with mapping? \n");
		exit(1);
	}
	printf("CPU started with %X \n", *cpuIndex->sn_PC);


	//printf("%X \n", *(sn_Mread_u16(cpuIndex)+15));
	while (1) {
		printf("PC: $%02X DP: %04X A: %04X X: %X\n",*cpuIndex->sn_PC, cpuIndex->sn_DP, cpuIndex->sn_Acc, cpuIndex->sn_X);
		printf("E: %d N: %d V: %d M: %d X: %d D: %d I: %d Z: %d C: %d \n", \
			cpuIndex->sn_EFlag, cpuIndex->sn_NFlag, cpuIndex->sn_VFlag, cpuIndex->sn_MFlag, cpuIndex->sn_XFlag, cpuIndex->sn_DFlag, cpuIndex->sn_IFlag, cpuIndex->sn_ZFlag, cpuIndex->sn_CFlag);

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
		};

		++cpuIndex->sn_PC;
		//usleep(100000);
	}
	return;
}
