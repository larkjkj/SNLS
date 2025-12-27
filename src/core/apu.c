#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "general/references.h"
#include "emulator/main.h"
#include "core/apu.h"
#include "core/spc/opcodes.h"

void (*snAPU_opcodes[])(emGeneral* emulator);

void generic(emGeneral* emulator) {
	printf("generic\n");
	return;
};

static void setupIPL(emGeneral* emulator) {
	memcpy(&emulator->apu->internalRAM[0xFFC0], IPL_NTSC, 0x3F);
	for(unsigned int i = 0; i < 0x3F; i ++ ) {
		printf("%X \n", emulator->apu->internalRAM[0xFFC0 + i]);
	}
	return;
};

static void fetchSPC(emGeneral* emulator) {
	*emulator->active |= 0x04;
	(snAPU_opcodes[(*emulator->apu->spc->PC)])(emulator);
	printf("apu fetch: %X %X %X %X %X \n", *emulator->apu->spc->PC, emulator->apu->spc->X, emulator->apu->spc->Y, emulator->apu->spc->SP, emulator->apu->spc->X);
	emulator->endfetch(emulator);
	return;
}

extern void setupAPU(emGeneral* emulator, snSPC* spc_ptr, u8** buffer, bool absolute) {
	/* APU != SPC 
	 * SPC-700 is a completely separated Processor 
	 * APU is the communicate interface
	 * DSL produces AUDIO */
	emulator->apu->spc = spc_ptr;
	emulator->apu->spc->fetch = fetchSPC;	
	emulator->apu->spc->PC = &emulator->apu->internalRAM[0xFFC0];

	buffer[0x00] = &emulator->apu->internalRAM[0xF4];
	buffer[0x01] = &emulator->apu->internalRAM[0xF5];
	buffer[0x02] = &emulator->apu->internalRAM[0xF6];
	buffer[0x03] = &emulator->apu->internalRAM[0xF7];

	setupIPL(emulator);

	snAPU_opcodes[0xCD] = snAPU_MOV_X_const;
	snAPU_opcodes[0xBD] = snAPU_MOV_SP_X;
	snAPU_opcodes[0xE8] = generic;

	return;
};

