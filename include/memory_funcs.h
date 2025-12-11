#include <stdio.h>
#include "types.h"

#include "vars/memory.h"
#include "vars/dma.h"
#include "vars/rom.h"
#include "vars/ppu.h"

extern void attachROM(u8* buffer, rom* rom_Ptr);
extern void setupSystem(sn_PPU* ppu, sn_DMA* dma); 

