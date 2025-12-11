#ifndef __PPUF__
#define __PPUF__

#include "vars/memory.h"
#include "vars/ppu.h"

extern void mapPPU(sn_PPU* ppu, u8** ppu_buffer);
extern void setupPPU(sn_PPU* ppu);
extern void fetchPPU(sn_PPU* ppu);
#endif
