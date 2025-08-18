#ifndef __ROM_FUNCS__
#define __ROM_FUNCS__
#include "vars/rom.h"

extern void openRom(char* rom_name, rom* rom_Ptr);
extern u8 returnBank(u32 byteSize);
extern u16 convertBEtoLE16(u16 address);

#endif

