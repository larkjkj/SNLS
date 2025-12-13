#ifndef SNLS_GS_HEADER 
#define SNLS_GS_HEADER 
#include "general/types.h"

static u64 gs_disp_address = 0;

volatile static u64* gs_disp_pmode = (u64*) 0x12000000;
volatile static u64* gs_disp_displ1 = (u64*) 0x12000080;
volatile static u64* gs_disp_dispf1 = (u64*) 0x12000070;
volatile static u32* gs_disp_color = (u32*) 0x120000E0;

extern void initWindow();
extern void pollWindow();

#endif
