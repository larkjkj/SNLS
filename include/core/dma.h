#ifndef SNLS_DMA_HEADER
#define SNLS_DMA_HEADER

#define MDMAEN 0x420B
#define HDMAEN 0x420C

typedef struct sn_DMA {
	u8	MdMaen;
	u8	HdMaen;
} sn_DMA;


extern void mapDMA(sn_DMA* dma, u8** dma_buffer, bool absolute);
extern void allocDMA(sn_DMA* dma);
extern void fetchDMA(sn_DMA* dma);
#endif
