#ifndef __PPUH__
#define __PPUH__
#include "types.h"


typedef struct sn_PPU {
	u8             p_Buf[0x2A];
	u8             p_vRAM[65536];
	 u8*	IniDisp;
	 u8*	ObjSel;

	/* These two are basically the same thing
	 * but splitted in two, L -> Low, H -> High
	 * We can use one u16 buta i wanna see how
	 * thing will go this these one */

	 u8*	OamADDL;
	 u8*	OamADDH;

	 u8*	OamData;
	 u8*	BgMode;
	 u8*	Mosaic;

	 u8*	Bg1SC;
	 u8*	Bg2SC;
	 u8*	Bg3SC;
	 u8*	Bg4SC;

	 u8*	Bg12NBA;
	 u8*	Bg34NBA;

	 u8*    Bg1HOFS;
	 u8*    Bg1VOFS;
	 u8*    Bg2HOFS;
	 u8*    Bg2VOFS;
	 u8*    Bg3HOFS;
	 u8*    Bg3VOFS;
	 u8*    Bg4HOFS;
	 u8*    Bg4VOFS;
	 u8*    vMAIN;

	 u8*    vmADDL;
	 u8*    vmADDH;
	 u8*    vmDATAL;
	 u8*    vmDATAH;

	 u8*    ApuIO0;
	 u8*    ApuIO1;
	 u8*    ApuIO2;
	 u8*    ApuIO3;

	 u8*    WmDATA;
	 u8*    WmADDL;
	 u8*    WmADDH;
	 u8*    WmADDM;
} sn_PPU;

typedef struct p_Tile {
    u8          type;
} p_Tile;

/*
	nothing to see here
	 * クラピカ
	 * ちすじゃぱねせ！！
*/
#endif
