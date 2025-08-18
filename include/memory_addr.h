volatile u32 ppu_stAddr = rom_buffer[0x2000];
volatile u32 con_stAddr = rom_buffer[0x4000];

volatile u32 cop_nAddr = rom_buffer[0x00FFE4];
volatile u32 brk_nAddr = rom_buffer[0x00FFE6];
volatile u32 nmi_nAddr = rom_buffer[0x00FFFA];
volatile u32 irq_nAddr = rom_buffer[0x00FFEE];

volatile u32 cop_eAddr = (u8) cop_nAddr;
volatile u32 nmi_eAddr = (u8) nmi_nAddr;

volatile u32 irq_eAddr = (u8) rom_buffer[0x00FFFE];

extern u16* rom_mMemory[65536];
extern u16* rom_startPPU[8192];
extern u16* rom_startIO[16384];
extern u16* rom_startDMA[16896];
extern u16* rom_startROM[32768];

#define brk_eAddr (u8) rom_buffer[0x00FFFF];
