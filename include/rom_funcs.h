#ifndef __ROM_FUNCS__
#define __ROM_FUNCS__
#include "vars/rom.h"

extern void openRom(char* rom_name, rom* rom_Ptr);
extern u8 returnBank(size_t byteSize);

#define dtoHEX(x) printf("%X\n", x)

#endif

