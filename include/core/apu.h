#ifndef SNLS_APU_HEADER
#define SNLS_APU_HEADER

#include <stdbool.h>
#include "general/types.h"

typedef struct sn_APU {
	u8	ApuIO0;
	u8	ApuIO1;
	u8	ApuIO2;
	u8	ApuIO3;
} sn_APU;

extern void mapAPU(sn_APU* apu, u8** apu_buffer, bool absolute);

#endif
