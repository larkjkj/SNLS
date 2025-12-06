#ifndef __PPUF__
#define __PPUF__

#include "vars/memory.h"
#include "vars/ppu.h"

extern struct sn_PPU* setupPPU(sn_PPU* initializedPPU, str_Buffer* map_Buf);
extern void fetchPPU(struct sn_PPU* PPU_index);
#endif
