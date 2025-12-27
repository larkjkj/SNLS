#ifndef SNLS_APU_HEADER
#define SNLS_APU_HEADER

#include <stdbool.h>
#include "general/references.h"
#include "general/types.h"

static u8 IPL_NTSC[64] = {
	0xCD, 0xEF, /* load 0xEF */
	0xBD,	    /* copy X to SP */
	0xE8, 0xAA, /* load 0xAA */
	0xC5, 0xF4, /* store */
	0xE8, 0xBB, /* load 0xBB */
	0xC5, 0xF5, /* store */
};


typedef struct snSPC {
	u8*	PC;
	u8	A;
	u8	X;
	u8	Y;
	u16*	YA; /* A << 8 | Y*/
	u8	SP; /* Stack Pointer */
	u8	Flags; /* Same as CPU flags or PSW if you prefer */

	void		(*fetch)(emGeneral* emulator);
} snSPC;

typedef struct snDSL {
	/* this is really responsible for SNES AUDIO */
	u8*	buffer[];
} snDSL;

typedef struct snAPU {
	u8	located;
	u8	internalRAM[0xFFFF];
	snSPC*	spc;
} snAPU;

#endif
