#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "emulator/memory.h"
#include "emulator/rom.h"
#include "core/cpu/ricoh.h"
#include "core/ppu.h"

extern void allocPPU(sn_PPU* ppu) {
/*	ppu->IniDisp = malloc(sizeof(u8));
	ppu->ObjSel = malloc(sizeof(u8));
	ppu->OamADDL = malloc(sizeof(u8));
	ppu->OamADDH = malloc(sizeof(u8));
	ppu->BgMode = malloc(sizeof(u8));
	ppu->Mosaic = malloc(sizeof(u8));
	ppu->Bg1SC = malloc(sizeof(u8));
	ppu->Bg2SC = malloc(sizeof(u8));
	ppu->Bg3SC = malloc(sizeof(u8));
	ppu->Bg4SC = malloc(sizeof(u8));
*/
};

extern void mapPPU(sn_PPU* ppu, u8** buffer, bool absolute) {
	/* don't use absolute if you don't know what you're doing. */
	/* it was here 'cause of a direct mapping method using Map
	 * instead of PPU_map, it's here for future reasons... 
	 * also if you use, keep in mind that you will need a bigger
	 * malloc */

	if (absolute) {
		buffer[INIDISP] = &ppu->IniDisp;
		buffer[OBJSEL] = &ppu->ObjSel;
		buffer[OAMADDL] = &ppu->OamADDL;
		buffer[OAMADDH] = &ppu->OamADDH;
		buffer[BGMODE] = &ppu->BgMode;
	} else {
		buffer[0x00] = &ppu->IniDisp;
		buffer[0x01] = &ppu->ObjSel;
		buffer[0x02] = &ppu->OamADDL;
		buffer[0x03] = &ppu->OamADDH;
		buffer[0x04] = &ppu->OamData;
		buffer[0x05] = &ppu->BgMode;
		buffer[0x06] = &ppu->Mosaic;
		buffer[0x07] = &ppu->Bg1SC;
		buffer[0x08] = &ppu->Bg2SC;
		buffer[0x09] = &ppu->Bg3SC;
		buffer[0x0A] = &ppu->Bg4SC;
	}
	return;
}

extern void fetchPPU(sn_PPU* ppu) {
	/* this doesn't "fetch" the ppu, it just prints a value
	 * of a register to check if mapping is working */
	printf("ppu_fetch: ppu-> %X \n", ppu->IniDisp);
	return;
}
