#include <stdio.h>
#include <unistd.h>

#include "types.h"
#include "vars/dma.h"
#include "vars/memory.h"

extern void setupDMA(sn_DMA* initializedDMA, u8* buffer) {
	initializedDMA->MdMaen = &buffer[MDMAEN];
};

extern void fetchDMA(sn_DMA* dmaMain) {
	if (*dmaMain->MdMaen & 1) {
		printf("dma_fetch: DMA enabled \n");
		sleep(1);
	}
};

