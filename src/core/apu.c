#include <stdio.h>
#include <stdlib.h>
#include "core/apu.h"

extern void mapAPU(sn_APU* apu, u8** apu_buffer, bool absolute) {
	if (absolute) {
		apu_buffer[0x2140] = &apu->ApuIO0;
		apu_buffer[0x2141] = &apu->ApuIO1;
		apu_buffer[0x2142] = &apu->ApuIO2;
		apu_buffer[0x2143] = &apu->ApuIO3;
	} else {
		apu_buffer[0x00] = &apu->ApuIO0;
		apu_buffer[0x01] = &apu->ApuIO1;
		apu_buffer[0x02] = &apu->ApuIO2;
		apu_buffer[0x03] = &apu->ApuIO3;
	}
	return;
};
