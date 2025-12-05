#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "rom_funcs.h"
#include "ppu_funcs.h"

#include "vars/rom.h"
#include "vars/memory.h"
#include "vars/ppu.h"

u8 mapP = 0x00;
u8** mBank[0xFF];

/*u8* memory_vMap = NULL;
u8* memory_wRAM = NULL;
u8* memory_sPPU = NULL;
u8* memory_iCPU = NULL;
u8* memory_rDMA = NULL;*/

u16 holdAddr;
u16 holdLoAddr;
u16 holdHiAddr;

static void setupMemory(rom *rom_Ptr) {
    return;
};
