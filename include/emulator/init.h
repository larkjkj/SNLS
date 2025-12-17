#ifndef SNLS_INIT_HEADER
#define SNLS_INIT_HEADER

#include "rom.h"

/* this is our MAIN struct, everything component 
 * can be accessible and acess everything by
 * themselves */
typedef struct emGeneral {
	sn_CPU*		cpu;
	sn_APU*		apu;
	emMemory*	memory;
};

extern void initEmu(rom* rom_Ptr);
#endif

