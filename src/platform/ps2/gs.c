/* This is to prevent usage on host (x86-64) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gs_addr.h"
#include "types.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_video.h"

#ifdef _USESDL
void gsInit() {
    Surface = malloc(sizeof(SDL_Surface));
    Window = SDL_CreateWindow("SNLS", 0, 0, 640, 480, 0);
    Renderer = SDL_CreateRenderer(Window, 0, 0);

    return;
};
#else

void gsInit() {
    sleep(5);
/* 	gs_disp_address = 0x80000001;
	int vku = 4; // Using a fix value because i'm too lazy,
		     // this is documented on GS Documents btw
		     // i'm really just lazy

	*gs_disp_pmode = 0x21;
	//*gs_disp_displ1 = ((u64) 0 | (u64) (640 * vku) << 32 | (u64) 480 << 44);
	*gs_disp_displ1 = ((u64) 0 | (640 << 32) | (480 << 44));
	*gs_disp_dispf1 = (((0 | (gs_disp_address / 2048) | ((640 / 64) << 9) | (0x27 << 15))));
	*gs_disp_color = 0xFFFFFFFF;*/
	return;
}
#endif
