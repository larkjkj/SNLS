#ifndef SNLS_INIT_HEADER
#define SNLS_INIT_HEADER

#include "core/cpu/ricoh.h"
#include "core/apu.h"
#include "core/dma.h"
#include "core/ppu.h"

/* this is our MAIN struct, everything component 
 * can be accessible and acess everything by
 * themselves */

typedef struct emGeneral {
	sn_CPU*		cpu;
	sn_PPU*		ppu;
	sn_APU*		apu;
	sn_DMA*		dma;
	emMemory*	memory;
} emGeneral;

#endif

