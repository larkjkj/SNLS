#include "emulator/rom.h"
#include "emulator/memory.h"
#include "emulator/init.h"
#include "general/types.h"
#include "core/cpu/ricoh.h"

extern void mapDMA(sn_DMA* dma, u8** dma_buffer, bool absolute);
extern void allocDMA(sn_DMA* dma);
extern void fetchDMA(sn_DMA* dma);
extern void setupCPU(emGeneral* emulator, rom* rom_Ptr);
extern void fetchCPU(emGeneral* emulator);
extern void mapPPU(sn_PPU* ppu, u8** ppu_buffer, bool absolute);
extern void fetchPPU(sn_PPU* ppu);
extern void allocPPU(sn_PPU* ppu);

extern void mapAPU(sn_APU* apu, u8** apu_buffer, bool absolute);

extern void initWindow();
extern void pollWindow();

extern void openRom(char* rom_name, rom* rom_Ptr);
extern void attachROM(emMap* mMap, rom* rom_Ptr);
extern void assignToMap(u8** dest, u8** src, unsigned int offset, unsigned int count, unsigned int type);


extern void initEmu(rom* rom_Ptr);

