/* */
#include <stdio.h>
#include "vars/cpu.h"
#include "vars/rom.h"
#include "vars/ppu.h"

#define INIDISP		rom_vMemory[0x2100];

#define OBJSEL		0x2101

#define OAMADDL		0x2102
#define	OAMADDH		0x2103

#define OAMDATA		0x2104

#define BGMODE		0x2105

#define MOSAIC		0x2106

#define BG1SC		0x2107
#define BG2SC		0x2108
#define BG3SC		0x2109
#define BG4SC		0x210A

#define BG12NBA		0x210B
#define BG34NBA		0x210C

#define BG1HOFS		0x210D
#define M7HOFS		//check this again
#define BG1VOFS		0x210E
#define M7VOFS		//check this again

#define BG2HOFS 0x210F
#define BG2VOFS 0x2110
#define BG3HOFS 0x2111
#define BG3VOFS 0x2112
#define BG4HOFS 0x2113
#define BG4VOFS 0x2114

#define VMAIN	0x2115
#define VMADDL	0x2116
#define VMADDH	0x2117

#define VMDATAL 0x2118
#define VMDATAH 0x2119

#define M7SEL 0x211A

#define M7A 0x211B
#define M7B 0x211C
#define M7C 0x211D
#define M7D 0x211E
#define M7X 0x211F
#define M7Y 0x2120

#define CGADD 0x2121
#define CGDATA 0x2122
#define W12SEL 0x2123
#define W34SEL 0x2124
#define WOBJSEL 0x2125

#define WH0 0x2126
#define WH1 0x2127
#define WH2 0x2128
#define WH3 0x2129
#define WBGLOG 0x212A
#define WOBJLOG 0x212B
#define TM 0x212C
#define TS 0x212D
#define TMW 0x212E
#define TSW 0x212F

#define CGWSEL 0x2130

#define CGADSUB 0x2131

#define COLDATA 0x2132

#define SETINIT 0x2133

#define MPYL 0x2134
#define MPYM 0x2135
#define MPYH 0x2136

#define SLHV 0x2137
#define OAMDATAREAD 0x2138
#define VMDATALREAD 0x2139
#define VMDATAHREAD 0x213A
#define CGDAATAREAD 0x213B

#define OPHCT 0x213C
#define OPVCT 0x213D
#define STAT77 0x213E
#define STAT78 0x213F

