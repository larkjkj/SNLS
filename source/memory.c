#include <stdio.h>
#include <string.h>

#include "types.h"

/* This file is not interesting at all, it just starts things
 * Maybe it be used for memory mapping, for now it's just this */
/* Initializer for memory */
u32 v_memory[65536] = {};
u32 w_memory[131072] = {};
u32 w_memory_buf[131072] = {};
u32 reset_snV = 0;
u32 holdAddr = 0;
u32 holdLoAddr = 0;
u32 holdHiAddr = 0;
