#ifndef __CPUF__
#define __CPUF__

#include "vars/cpu.h"
#include "vars/ppu.h"
#include "vars/rom.h"

extern struct sn_CPU* initCPU(rom* rom_Ptr);
extern void fetchCPU(struct sn_CPU* CPUIndex);

#endif
