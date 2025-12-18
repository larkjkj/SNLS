#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "emulator/init.h"
#include "emulator/gs.h"
#include "emulator/rom.h"
#include "emulator/memory.h"
#include "general/functions.h"

#ifdef for_ps2
#include "debug.h"
#include "ps2_filesystem_driver.h"
#endif

char path_buf[255];
emMemory memory;

int main() {
	rom rom_Ptr;

	initWindow();
	/* Just a check to make sure we're on the correct path */
	getcwd(path_buf, sizeof(path_buf));

	/* Yea, i know this is bad
	 * but this is used until
	 * i make a file explorer */
	//openRom("roms/cputest/cputest-full.sfc", &rom_Ptr);
	openRom("roms/mariow.sfc", &rom_Ptr);
	
	initEmu(&rom_Ptr);

	/* Yea i know this is bad
	 * but i was kidna lazy to implement
		* a better fix like a double pointer
		* or even some more simple
	 */
		//free(m_Buf->mMap);
		//free(m_Buf->mROM);

	return 0;
}
