#ifndef SNLS_APU_HEADER
#define SNLS_APU_HEADER

#include <stdbool.h>
#include "general/types.h"

typedef struct sn_APU {
	u8	located;
	u8	ApuIO0;
	u8	ApuIO1;
	u8	ApuIO2;
	u8	ApuIO3;
} sn_APU;


#endif
