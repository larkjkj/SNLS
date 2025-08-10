> [!NOTE]
> This is a WIP of an emulator, i expect to finish this
in some months, but let's see.

# 16larks
[AWESOME LOGO](logo/16larks.png)
A 16-bit emulator (SNES)

## What we've got so far? 
- [ ]  Dynarec
- [x]  ~memory duh~
- [ ]  Memory Mapping
- [ ]  DMA

__**Btw DMA and Memory Mapping are 
related so... they're both being
made in parallel**__

- [ ]  UI (on works :P)
- [ ]  PPU1
- [ ]  PPU2
- [ ]  SFX
- [ ]  Special Chips(SA-1 SuperFX)
- [ ]  Make it run on PS2(already runs, but without support for filesystem)

-- Planned --
- [ ] Remove unecessary functions like `update_n_flag` and `update_z_flag` they're
complete useless, and i didn't know what i did that, since i could do that in only
one single operation
- [ ] Fix some opcodes logic, some are really wrong, i already fixed some, but probally
there's more
- [ ] Idk, maybe another lib?
- [ ] Fix some order updating flags, some flags are updated before the operation

## Roms being tested
- *Super Mario RPG* ![](https://progress-bar.xyz/05/)
  - (The game is executed but CPU is halted after some time)
   
- *Super Mario World* ![](https://progress-bar.xyz/05)
  - (The game is executed and enters in a loop)
  
- *Zelda ALTTP* ![](https://progress-bar.xyz/05)
  - (Same thing above)
  
- *Super Metroid* ![](https://progress-bar.xyz/05)
  - (Same thing above)
  
- *CPU Rom Tests* ![](https://progress-bar.xyz/00)
  - (The rom simply executes, at some time, it stops..)

# idk guys, just makin it, cant take a fuckin shit anmr

