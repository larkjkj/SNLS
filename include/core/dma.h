#ifndef SNLS_DMA_HEADER
#define SNLS_DMA_HEADER

#define MDMAEN 0x420B
#define HDMAEN 0x420C

#include "general/references.h"

typedef struct snDMA {
	u8	located;
	u8	MdMaen;
	u8	HdMaen;
	void	(*fetch)(emGeneral* emulator);
} snDMA;

#endif
