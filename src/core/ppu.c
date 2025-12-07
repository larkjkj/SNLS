#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vars/memory.h"
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/ppu.h"

/* Basically i need to setup tiles*/
/* Make it run along with the CPU */
extern struct sn_PPU* setupPPU(sn_PPU* newPPU, str_Buffer* map_Buf){
	newPPU->IniDisp = &map_Buf->buffer[INIDISP];
	newPPU->ObjSel = &map_Buf->buffer[OBJSEL];
	newPPU->OamADDL = &map_Buf->buffer[OAMADDL];
	newPPU->OamADDH = &map_Buf->buffer[OAMADDH];
	newPPU->OamData = &map_Buf->buffer[OAMDATA];
	newPPU->BgMode = &map_Buf->buffer[BGMODE];
	newPPU->Mosaic = &map_Buf->buffer[MOSAIC];

	newPPU->Bg1SC = &map_Buf->buffer[BG1SC];
	newPPU->Bg2SC = &map_Buf->buffer[BG2SC];
	newPPU->Bg3SC = &map_Buf->buffer[BG3SC];
	newPPU->Bg4SC = &map_Buf->buffer[BG4SC];
	newPPU->Bg12NBA = &map_Buf->buffer[BG12NBA];
	newPPU->Bg34NBA = &map_Buf->buffer[BG34NBA];

	newPPU->Bg1HOFS = &map_Buf->buffer[BG1HOFS];
	newPPU->Bg1VOFS = &map_Buf->buffer[BG1VOFS];
	newPPU->Bg2HOFS = &map_Buf->buffer[BG2HOFS];
	newPPU->Bg2VOFS = &map_Buf->buffer[BG2VOFS];
	newPPU->Bg3HOFS = &map_Buf->buffer[BG3HOFS];
	newPPU->Bg3VOFS = &map_Buf->buffer[BG3VOFS];
	newPPU->Bg4HOFS = &map_Buf->buffer[BG4HOFS];
	newPPU->Bg4VOFS = &map_Buf->buffer[BG4VOFS];
	newPPU->vMAIN = &map_Buf->buffer[VMAIN];

	newPPU->vMADDL = &map_Buf->buffer[VMADDL];
	newPPU->vMADDH = &map_Buf->buffer[VMADDH];
	newPPU->vMDATAL = &map_Buf->buffer[VMDATAL];
	newPPU->vMDATAH = &map_Buf->buffer[VMDATAH];

	*newPPU->IniDisp = 0x0;
	printf("[Mapped PPU %X - PPU: %X]\n", map_Buf->buffer[INIDISP], *newPPU->IniDisp);
	return newPPU;
}

extern void fetchPPU(sn_PPU* PPU_index) {
	printf("[PPU - %p] -> %X \n", PPU_index, *PPU_index->IniDisp);
	return;
}
