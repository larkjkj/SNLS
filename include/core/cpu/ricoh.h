#ifndef SNLS_CPU_HEADER
#define SNLS_CPU_HEADER

#include "general/types.h"
/*ですただ */
typedef struct sn_CPU {
	u8		currentPtrBank;
	u8*		sn_PC;
	u8*		sn_subPC;	/* Subroutine */

	u16		sn_S;
	u16		sn_Acc;
	u16		sn_X;
	u16		sn_Y;
	u16		sn_DP;
	u8		sn_DBR;
	u8		sn_PB;
	u16		sn_P;

	u8		sn_Flags;

	/* in the future, i want
	 * to implement an idea
	 * that i had in the project
	 * s starting phase, 
	 * a single u8 value
	 * acting all the sn_Flags 
	 * like the OG hardware */
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

#endif
