#ifndef SNLS_CPU_HEADER
#define SNLS_CPU_HEADER
#include "general/types.h"
#include "emulator/rom.h"

/*ですただ */
typedef struct sn_CPU {
	u8*		sn_PC;
	u32		sn_BC;
	u32*		sn_subPC;	/* Subroutine */

	u16		sn_S;
	u16		sn_Acc;
	u16		sn_X;
	u16		sn_Y;
	u16		sn_DP;
	u8		sn_DBR;
	u8		sn_PB;
	u16		sn_P;

	u8		sn_Flags;

	bool 		sn_NFlag;
	bool 		sn_VFlag;
	bool 		sn_MFlag;
	bool 		sn_XFlag;
	bool 		sn_DFlag;
	bool 		sn_IFlag;
	bool 		sn_ZFlag;
	bool 		sn_CFlag;
	bool 		sn_EFlag;
	bool 		sn_BFlag;
} sn_CPU;

extern void setupCPU(sn_CPU* cpu, rom* rom_Ptr);
extern void fetchCPU(sn_CPU* cpu);


#endif
