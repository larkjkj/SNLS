#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "vars/memory.h"
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/ppu.h"

extern void setupPPU(sn_PPU* ppu) {
	ppu->IniDisp = malloc(sizeof(u8*));
	//ppu->ObjSel = malloc(sizeof(u8*));
};

extern void mapPPU(sn_PPU* ppu, u8** ppu_buffer) {
	ppu_buffer[INIDISP] = ppu->IniDisp;
	ppu_buffer[OBJSEL] = ppu->ObjSel;
	return;
}

extern void fetchPPU(sn_PPU* ppu) {
	printf("ppu_fetch: ppu-> %X \n", *ppu->IniDisp);
	return;
}
