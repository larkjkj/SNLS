#ifndef SNLS_DMA_HEADER
#define SNLS_DMA_HEADER

#define MDMAEN 0x420B
#define HDMAEN 0x420C

typedef struct sn_DMA {
	u8	located;
	u8	MdMaen;
	u8	HdMaen;
} sn_DMA;

#endif
