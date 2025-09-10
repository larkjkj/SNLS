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
map_Buf m_Buf[];

u16 holdAddr;
u16 holdLoAddr;
u16 holdHiAddr;

extern void setupMemory(rom *rom_Ptr) {
    return;
};

extern void splitBanks(rom *rom_Ptr) {
    fseek(rom_File, rom_Ptr->offset, SEEK_SET);
    m_Buf[rom_Ptr->banks];

    for(unsigned int i = 0; i <= rom_Ptr->banks; i ++) {
	*m_Buf[i].mMap = malloc(sizeof(u8*));
	m_Buf[i].mMap = malloc(0x10000);
        fread(&(m_Buf[i].mMap[0x8000]), sizeof(u8), 0x8000, rom_File);
	printf("%X \n", (m_Buf[i].mMap[0x8000]));
        mBank[i] = m_Buf[i].mMap;
    	setupPPU(m_Buf[i].mMap[0x2000]);
    }
    // SETUP PPU

    //fwrite((void*) buffer, unsigned long, sizeof(u8), FILE *)
    printf("Done \n");
    return;
}
