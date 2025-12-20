#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "general/types.h"
#include "emulator/memory.h"
#include "core/dma.h"

extern void mapDMA(sn_DMA* dma, u8* buffer, bool absolute) {
	if (absolute) {
		buffer[MDMAEN] = dma->MdMaen;
		buffer[HDMAEN] = dma->HdMaen;
	} else {
		buffer[0x0B] = dma->MdMaen;
		buffer[0x0C] = dma->HdMaen;
	}
	return;
};

extern void fetchDMA(sn_DMA* dma) {
	printf("dma_fetch: %d \n", dma->MdMaen);
	/* setup 7 channels*/
	if (dma->MdMaen & 0x01) {
		//sleep(1);
		printf("channel 0 enabled \n");
	}  if (dma->MdMaen & 0x02) {
		//sleep(1);
		printf("channel 1 enabled \n");
	}  if (dma->MdMaen & 0x04) {
		//sleep(1);
		printf("channel 2 enabled \n");
	}  if (dma->MdMaen & 0x08) {
		//sleep(1);
		printf("channel 3 enabled \n");
	}  if (dma->MdMaen & 0x10) {
		//sleep(1);
		printf("channel 4 enabled \n");
	}  if (dma->MdMaen & 0x20) {
		//sleep(1);
		printf("channel 5 enabled \n");
	}  if (dma->MdMaen & 0x40) {
		//sleep(1);
		printf("channel 6 enabled \n");
	}  if (dma->MdMaen & 0x80)
		printf("channel 7 enabled \n");;
};

