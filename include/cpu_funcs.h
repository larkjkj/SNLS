#ifndef __CPUF__
#define __CPUF__

#include "vars/cpu.h"
#include "vars/ppu.h"
#include "vars/rom.h"

extern void setupCPU(sn_CPU* cpu, rom* rom_Ptr);
extern void fetchCPU(sn_CPU* cpu);

#endif
