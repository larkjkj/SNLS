#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "memory_funcs.h"
#include "cpu_opcodes.h"
#include "vars/memory.h"
#include "vars/rom.h"
#include "vars/cpu.h"

#include "interpreter.h"

void rcCPU(sn_CPU* cpuIndex, rom* rom_Ptr) {
	/* This is just the start of the ROM Title 
	 * Nothing interesting at all */
	printf("What we've got? 0x%X \n", memory_vMap[rom_Ptr->MapArea]);

	cpuIndex->sn_PC = rom_Ptr->MapArea;

	/*  This line forces emulation-mode to be off (Disables 6502 compatibility) */
	// cpuIndex->sn_EFlag = 0;
	while (1) {
		switch (memory_vMap[cpuIndex->sn_PC]) {
			case _adc_const:
				snADC_const(cpuIndex);
			break;

			case _and_const:
				snAND_const(cpuIndex);
			break;

			case _and_addr:
				snAND_addr(cpuIndex);
			break;
			
			/* ASL right here */
			case _asl_dp:
				snASL_dp(cpuIndex);
			break;

			case _asl_a:
				snASL_acc(cpuIndex);
			break;
			
			case _asl_dp_x:
				snASL_dpX(cpuIndex);
			break;

			case _asl_addr_x:
				snASL_addrX(cpuIndex);
			break;
			
			case _clc:
				snCLC(cpuIndex);
			break;

			case _cld:
				snCLD(cpuIndex);
			break;

			case _cli:
				snCLI(cpuIndex);
			break;

			case _clv:
				snCLV(cpuIndex);
			break;

			case _cmp_dp:
				snCMP_dp(cpuIndex);
			break;
		
			case _cmp_const:
				snCMP_const(cpuIndex);
			break;
			
			case _cmp_addr:
				snCMP_addr(cpuIndex);
			break;
			
			case _cmp_l:
				snCMP_long(cpuIndex);
			break;
			
			case _cmp_dp_indr_y:
			break;

			case _cmp_dp_indr:
			break;

			case _cmp_sr_s_indr_y:
			break;

			case _cmp_dp_x:
				snCMP_dpX(cpuIndex);
			break;

			case _cmp_dp_indr_l_y:
			break;

			case _cmp_addr_y:
				snCMP_addrY(cpuIndex);
			break;
			case _cmp_addr_x:
				snCMP_addrX(cpuIndex);
			break;
			case _cmp_l_x:
				snCMP_longX(cpuIndex);
			break;

			case _dec_a:
				snDEC_Acc(cpuIndex);
			break;

			case _dec_dp:
				snDEC_dp(cpuIndex);
			break;

			case _dec_addr:
				snDEC_addr(cpuIndex);
			break;

			case _dec_addr_x:
				snDEC_addrX(cpuIndex);
			break;

			case _dec_dp_x:
				snDEC_dpX(cpuIndex);
			break;

			case _lda_dp:
				snLDA_dp(cpuIndex);
			break;

			case _lda_const:
				snLDA_const(cpuIndex);
			break;

			case _lda_addr:
				snLDA_addr(cpuIndex);
			break;

			case _sec:
				snSEC(cpuIndex);
			break;

			case _sed:
				snSED(cpuIndex);
			break;

			case _sei:
				snSEI(cpuIndex);
			break;

			case _sep:
			break;

			case _sta_addr:
				snSTA_addr(cpuIndex);
				printf("STA, %X, %X");
			break;

			case _stz_dp:
				snSTZ_dp(cpuIndex);
			break;

			case _stz_dp_x:
			break;

			case _stz_addr:
				snSTZ_addr(cpuIndex);
			break;

			case _stz_addr_x:
			break;

			case _tcd:
				snTCD(cpuIndex);
			break;
			case _wai:
				snWAI(cpuIndex);
			break;
		};
		usleep(100000);
		++cpuIndex->sn_PC;
		printf("PC: %02X A: %04X X: %04X Y: %04X DP: %04X I: %i D: %i E: %i V: %i\n", \
			memory_vMap[cpuIndex->sn_PC], cpuIndex->sn_Acc, cpuIndex->sn_X, \
			cpuIndex->sn_Y, cpuIndex->sn_DP, cpuIndex->sn_IFlag, 
			cpuIndex->sn_DFlag, cpuIndex->sn_EFlag, cpuIndex->sn_VFlag);
	
		memory_vMap[++cpuIndex->sn_PC];
	}

	return;
}
