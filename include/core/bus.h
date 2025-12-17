#include <stdbool.h>
#include "core/cpu/ricoh.h"
#include "emulator/memory.h"

extern u8* sn_Mread_u8(sn_CPU* cpuIndex, u16 offset);
extern u8 sn_Mread_u8_const(sn_CPU* cpuIndex, u16 offset);
extern u8* sn_Mread_u16(sn_CPU* cpuIndex, u16 offset, bool use_pb);
extern u16 sn_Mread_u16_const(sn_CPU* cpuIndex, u16 offset);
extern u8* sn_Mread_u24(sn_CPU* cpuIndex, u16 offset, bool use_pb);

extern u8* sn_Mwrite(sn_CPU* cpuIndex, u16 offset, u16 address, u32 value);
extern u8* sn_Mwrite_ptr(sn_CPU* cpuIndex, u16 offset, u8* address, u32 value);
