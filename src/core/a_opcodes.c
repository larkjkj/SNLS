#include <unistd.h>

#include "core/bus.h"
#include "emulator/main.h"

extern void snAPU_MOV_A_const(emGeneral* emulator) {
	emulator->apu->spc->A = *++emulator->apu->spc->PC;
	++emulator->apu->spc->PC;
};

extern void snAPU_MOV_X_const(emGeneral* emulator) {
	emulator->apu->spc->X = *++emulator->apu->spc->PC;
	++emulator->apu->spc->PC;
}

extern void snAPU_MOV_SP_X(emGeneral* emulator) {
	emulator->apu->spc->SP = emulator->apu->spc->X;
	++emulator->apu->spc->PC;
}
