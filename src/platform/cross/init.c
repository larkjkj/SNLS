#include <stdio.h>
#include "SDL2/SDL.h"

SDL_Renderer* Renderer = NULL;
SDL_Window* Window = NULL;
SDL_Surface* Surface = NULL;

SDL_Event Event;
extern void renderGS() {
    while (SDL_PollEvent(&Event)) {
        switch (Event.type) {
            case SDL_QUIT:
                exit(1);
            break;
        }
        /* MAKE A FUNCTION TO PROPERLY EXIT */
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 128);

        SDL_RenderDrawPoint(Renderer, 640, 480);

        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 128);
        SDL_RenderPresent(Renderer);
        SDL_RenderClear(Renderer);
    };
}

