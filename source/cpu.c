#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "memory_funcs.h"
#include "cpu_opcodes.h"
#include "vars/bus.h"
#include "vars/rom.h"
#include "vars/cpu.h"

#include "interpreter.h"

void rcCPU(sn_CPU* cpuIndex, rom* rom_Ptr) {
	printf("CPU started \n");
	/* This is just the start of the ROM Title 
	 * Nothing interesting at all */
//	printf("What we've got? 0x%X \n", memory_vMap[rom_Ptr->MapArea]);
		
	cpuIndex->sn_PC = 0;
	cpuIndex->sn_EFlag = 1;
	printf("EMULATION MODE\n");
	cpuIndex->sn_PC = (0x8203);

	/*  This line forces emulation-mode to be off (Disables 6502 compatibility) */
	while (1) {
		switch ((memory_vMap[cpuIndex->sn_PC])) {
			case _adc_dp:
				snADC_dp(cpuIndex);
			break;

			case _adc_const:
				snADC_const(cpuIndex);
			break;

			case _adc_addr:
				snADC_addr(cpuIndex);
			break;

			case _adc_l:
				snADC_long(cpuIndex, rom_Ptr);
			break;

			case _adc_addr_y:
				snADC_addrY(cpuIndex);
			break;

			case _adc_addr_x:
				snADC_addrX(cpuIndex);
			break;

			case _adc_long_x:
				snADC_longX(cpuIndex, rom_Ptr);
			break;
	
			case _and_const:
				snAND_const(cpuIndex);
			break;

			case _and_addr:
				snAND_addr(cpuIndex);
			break;
			
			case _and_l:
				snAND_long(cpuIndex, rom_Ptr);
			break;

			case _and_addr_y:
			break;
			case _and_addr_x:
				snAND_addrX(cpuIndex);
			break;

			/* ASL right here */
			case _asl_dp:
				snASL_dp(cpuIndex);
			break;

			case _asl_a:
				snASL_Acc(cpuIndex);
			break;
			
			case _asl_dp_x:
				snASL_dpX(cpuIndex);
			break;

			case _asl_addr_x:
				snASL_addrX(cpuIndex);
			break;
			
			case _bcc:
				snBCC(cpuIndex);
			break;

			case _bcs:
				snBCS(cpuIndex);
			break;

			case _beq:
				snBEQ(cpuIndex);
			break;

			case _bit_addr:
				snBIT_addr(cpuIndex);
			break;

			case _bra:
				snBRA(cpuIndex);
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
				snCMP_long(cpuIndex, rom_Ptr);
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
				snCMP_longX(cpuIndex, rom_Ptr);
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

			case _dex:
				snDEX(cpuIndex);
			break;

			case _dey:
				snDEY(cpuIndex);
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
			
			case _lda_l:
				snLDA_long(cpuIndex, rom_Ptr);
			break;

			case _lda_dp_x:
				snLDA_dpX(cpuIndex);
			break;

			case _lda_addr_y:
				snLDA_addrY(cpuIndex);
			break;

			case _lda_addr_x:
				snLDA_addrX(cpuIndex);
			break;
			
			case _lda_l_x:
				snLDA_longX(cpuIndex, rom_Ptr);
			break;

			case _ldx_const:
				snLDX_const(cpuIndex);
			break;

			case _ldx_dp:
				snLDX_dp(cpuIndex);
			break;

			case _ldx_addr:
				snLDX_addr(cpuIndex);
			break;

			case _ldx_dp_y:
				snLDX_dpY(cpuIndex);
			break;

			case _ldx_addr_y:
				snLDX_addrY(cpuIndex);
			break;

			case _inc_a:
				snINC_Acc(cpuIndex);
			break;

			case _jmp_addr:
				snJMP_addr(cpuIndex);
			break;

			case _jmp_l:
				snJMP_long(cpuIndex, rom_Ptr);
			break;

			case _jsr_addr:
				snJSR_addr(cpuIndex);
			break;

			case _jsr_l:
				snJSR_long(cpuIndex, rom_Ptr);
			break;

			case _jsr_addr_x_indr:
				snJSR_addrXI(cpuIndex);
			break;

			case _ora_const:
				snORA_const(cpuIndex);
			break;

			case _ora_addr:
				snORA_addr(cpuIndex);
			break;

			case _ora_l:
				snORA_long(cpuIndex, rom_Ptr);
			break;

			case _ora_l_x:
				snORA_longX(cpuIndex, rom_Ptr);
			break;

			case _ora_addr_y:
				snORA_addrY(cpuIndex);
			break;
			
			case _ora_addr_x:
				snORA_addrX(cpuIndex);
			break;

			case _rep:
				snREP_const(cpuIndex);
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
				snSEP(cpuIndex);
			break;

			case _sta_dp:
				snSTA_dp(cpuIndex);
			break;

			case _sta_addr:
				snSTA_addr(cpuIndex);
			break;

			case _sta_l:
				snSTA_long(cpuIndex, rom_Ptr);
			break;

			case _sty_addr:
				snSTY_addr(cpuIndex);
			break;

			case _sty_dp:
				snSTY_dp(cpuIndex);
			break;

			case _sty_dp_x:
				snSTY_dpX(cpuIndex);
			break;

			case _stz_dp:
				snSTZ_dp(cpuIndex);
			break;

			case _stz_dp_x:
				snSTZ_dpX(cpuIndex);
			break;

			case _stz_addr:
				snSTZ_addr(cpuIndex);
			break;

			case _stz_addr_x:
				snSTZ_addrX(cpuIndex);
			break;

			case _tax:
				snTAX(cpuIndex);
			break;
			
			case _tay:
				snTAY(cpuIndex);
			break;

			case _tcd:
				snTCD(cpuIndex);
			break;

			case _tdc:
				snTDC(cpuIndex);
			break;

			case _txa:
				snTXA(cpuIndex);
			break;
	
			case _txy:
				snTXY(cpuIndex);
			break;

			case _tya:
				snTYA(cpuIndex);
			break;

			case _tyx:
				snTYX(cpuIndex);
			break;

			case _wai:
				snWAI(cpuIndex);
			break;
			case _xce:
				snXCE(cpuIndex);
			break;
			default:
		};

		printf("PC: $%04X\n", memory_vMap[cpuIndex->sn_PC]);
		printf("DP: $%04X\n", cpuIndex->sn_DP);
		printf("A:  %X\n", cpuIndex->sn_Acc);
		printf("X:  %X\n", cpuIndex->sn_X);
		printf("Y:  %X\n", cpuIndex->sn_Y);
		printf("C:  %d\n", cpuIndex->sn_CFlag);
		printf("D:  %d\n", cpuIndex->sn_DFlag);
		printf("V:  %d\n", cpuIndex->sn_VFlag);
		printf("M:  %d\n", cpuIndex->sn_MFlag);
		printf("E:  %d\n", cpuIndex->sn_EFlag);
		printf("I:  %d\n", cpuIndex->sn_IFlag);
		memory_vMap[++cpuIndex->sn_PC];
		usleep(100000);

	}
	return;
}
