#include "emulator/rom.h"
#include "emulator/memory.h"
#include "emulator/general.h"
#include "general/types.h"
#include "core/cpu/ricoh.h"

extern void mapDMA(sn_DMA* dma, u8** buffer, bool absolute);
extern void mapAPU(sn_APU* apu, u8** buffer, bool absolute);
extern void mapPPU(sn_PPU* ppu, u8** buffer, bool absolute);

extern void allocDMA(sn_DMA* dma);
extern void allocPPU(sn_PPU* ppu);

extern void fetchDMA(sn_DMA* dma);
extern void fetchPPU(sn_PPU* ppu);
extern void fetchCPU(emGeneral* emulator);

extern void setupCPU(emGeneral* emulator, rom* rom_Ptr);

extern void initWindow();
extern void pollWindow();

extern void openRom(char* rom_name, rom* rom_Ptr);
extern void attachROM(u8* buffer);
extern void assignToMap(u8** dest, u8** src, unsigned int offset, unsigned int count, unsigned int type);

extern u8 getMappedBank(u8 index, u16 address, emGeneral* emulator);
extern void initEmu(rom* rom_Ptr);

