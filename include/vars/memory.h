#ifndef __MEMORY_VARS__
#define __MEMORY_VARS__
#include "rom.h"
#include "types.h"

extern u16* holdPtrAddr;
extern u16 holdAddr;
extern u32 reset_snV;
extern u16 holdLoAddr;
extern u16 holdHiAddr;

typedef struct reg_Mem {
    u8*     PPU_reg;
} reg_Mem;

typedef struct map_Buf {
    u8**    mMap;
} map_Buf;

extern u8** mBank[0xFF];

extern map_Buf m_Buf[];

#endif
