> [!NOTE]
> This is a WIP of an emulator, i expect to finish this
in some months, but let's see how it goes...

# SNLS
![AWESOME LOGO](assets/logo/16larks.png)

A SNES emulator focused on perfomance, portability and features.

# What we've got so far?
### Basics
- [x] CPU
- [ ] PPU
- [ ] APU
- [ ] DMA
- [x] Banks
- [x] Memory Mapping
- [x] Functional BUS
- [ ] Special Chips(SA-1, SuperFX, etc...)

### Features 
- [ ] Dynarec
- [ ] Discord RPC
- [ ] Save-states
- [ ] Debug Inspector
- [ ] Memory View
- [ ] UI
- [ ] Dissassembler
### Targets
- [x] PS2
- [x] PC

### Bugfixes 
- [x] Remove unecessary functions like `update_n_flag` and `update_z_flag` they're
complete useless, and i didn't know what i did that, since i could do that in only
one single operation
- [ ] Fix some opcodes logic, some are really wrong, i already fixed some, but probally
there's more
- [ ] Idk, maybe another lib aimed for graphics rendering instead of SDL + OpenGL
- [ ] Fix some order updating flags, some flags are updated before the operation

## Known Problems
In this stage, there's a __100% of chance__ of the emulator gets into a infinite loop, this is due to a mix of __non-implemented__ resources and CPU operations, for example, if you do a __BEQ__ operation to confirm that everything is ok with your APU, PPU, howewer, as they're  not fully implemented, they cannot send info.

In response of the item above, this is already being solved along with mapping and fetch.

```c
extern inline void sn_Mwrite(u8 bank, u8* address, u8 value) {
    **mBank[bank][*address] = value; /* Mapped as PPU->IniDisp */
}

int main() {
    sn_Mwrite(0x00, 0x2100, 0x80);
    printf("%X \n", ppu->IniDisp); /* Will print 0x80 to the console */
}
```

# Roms being tested
### Super Mario RPG ![](https://progress-bar.xyz/05/)
###### (The game is executed but CPU is halted after some time)


### Super Mario World ![](https://progress-bar.xyz/05)
###### (The game is executed and enters in a loop)

### The Legend of Zelda - A Link To The Past ![](https://progress-bar.xyz/05)
###### (The game is executed and enters in a loop)

### [testing roms] ![](https://progress-bar.xyz/un)
###### (Need more resources to a full result)





# idk guys, just makin it, cant take a fuckin shit anmr
