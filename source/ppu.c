#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vars/memory.h"
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/ppu.h"

sn_PPU PPU_index;

extern inline int setupPPU(u8** m_Buf) {
    /* I feel this is not a too-safe code */
    /* But basically they are pointers to a specific address */

	PPU_index.IniDisp   = m_Buf[0x00];
	PPU_index.ObjSel    = m_Buf[0x01];
	PPU_index.OamADDL   = m_Buf[0x02];
	PPU_index.OamADDH  = m_Buf[0x03];
	PPU_index.OamData  = m_Buf[0x04];
	PPU_index.BgMode   = m_Buf[0x05];
	PPU_index.Mosaic   = m_Buf[0x06];
	PPU_index.Bg1SC    = m_Buf[0x07];
	PPU_index.Bg2SC    = m_Buf[0x08];
	PPU_index.Bg3SC    = m_Buf[0x09];
	PPU_index.Bg4SC    = m_Buf[0x0A];
	PPU_index.Bg12NBA  = m_Buf[0x0B];
	PPU_index.Bg34NBA  = m_Buf[0x0C];
	PPU_index.Bg1HOFS  = m_Buf[0x0D];
	PPU_index.Bg1VOFS  = m_Buf[0x0E];
	PPU_index.Bg2HOFS  = m_Buf[0x0F];
	PPU_index.Bg2VOFS  = m_Buf[0x10];
	PPU_index.Bg3HOFS  = m_Buf[0x11];
	PPU_index.Bg3VOFS  = m_Buf[0x12];
	PPU_index.Bg4HOFS  = m_Buf[0x13];
	PPU_index.Bg4VOFS  = m_Buf[0x14];
	PPU_index.vMAIN    = m_Buf[0x15];

	PPU_index.vmADDL   = m_Buf[0x16];
	PPU_index.vmADDH   = m_Buf[0x17];
	PPU_index.vmDATAL   = m_Buf[0x18];
	PPU_index.vmDATAH   = m_Buf[0x19];

	/* Reserved to MODE-7 0x1A - 0x20

	PPU_index.ApuIO0   = &m_Buf[0x2140];
	PPU_index.ApuIO1   = &m_Buf[0x2141];
	PPU_index.ApuIO2   = &m_Buf[0x2142];
	PPU_index.ApuIO3   = &m_Buf[0x2143];
	PPU_index.WmDATA   = &m_Buf[0x2180];
	PPU_index.WmADDL   = &m_Buf[0x2181];
	PPU_index.WmADDM   = &m_Buf[0x2182];
	PPU_index.WmADDH   = &m_Buf[0x2183];*/
	//testPPU(PPU_index);
	return 1;
}

#define INIDISP     0x00
#define OBJSEL		0x01

#define OAMADDL		0x02
#define	OAMADDH		0x03

#define OAMDATA		0x04

#define BGMODE		0x05

#define MOSAIC		0x06

#define BG1SC		0x07
#define BG2SC		0x08
#define BG3SC		0x09
#define BG4SC		0x0A

#define BG12NBA		0x0B
#define BG34NBA		0x0C

#define BG1HOFS		0x0D
#define M7HOFS		//check this again
#define BG1VOFS		0x0E
#define M7VOFS		//check this again

#define BG2HOFS 0x0F
#define BG2VOFS 0x10
#define BG3HOFS 0x11
#define BG3VOFS 0x12
#define BG4HOFS 0x13
#define BG4VOFS 0x14

#define VMAIN	0x15
#define VMADDL	0x16
#define VMADDH	0x17

#define VMDATAL 0x18
#define VMDATAH 0x19

#define M7SEL 0x1A

#define M7A 0x1B
#define M7B 0x1C
#define M7C 0x1D
#define M7D 0x1E
#define M7X 0x1F
#define M7Y 0x20

#define CGADD 0x21
#define CGDATA 0x22
#define W12SEL 0x23
#define W34SEL 0x24
#define WOBJSEL 0x25

#define WH0 0x26
#define WH1 0x27
#define WH2 0x28
#define WH3 0x29
#define WBGLOG 0x2A
#define WOBJLOG 0x2B
#define TM 0x2C
#define TS 0x2D
#define TMW 0x2E
#define TSW 0x2F

#define CGWSEL 0x30

#define CGADSUB 0x31

#define COLDATA 0x32

#define SETINIT 0x33

#define MPYL 0x34
#define MPYM 0x35
#define MPYH 0x36

#define SLHV 0x37
#define OAMDATAREAD 0x38
#define VMDATALREAD 0x39
#define VMDATAHREAD 0x3A
#define CGDAATAREAD 0x3B

#define OPHCT 0x3C
#define OPVCT 0x3D
#define STAT77 0x3E
#define STAT78 0x3F
