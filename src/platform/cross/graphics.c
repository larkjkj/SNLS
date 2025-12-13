#include <stdio.h>
#include <unistd.h>

#include "emulator/memory.h"

#include "GL/gl.h"
#include "SDL2/SDL.h"

#include <ft2build.h>

#include FT_FREETYPE_H

uint emuFBmtx[256 * 224];
uint emuFBtex;
uint emuFB;

SDL_Window* mWindow;
SDL_GLContext mContext;
SDL_Event mEvent;


extern void initWindow() {
	SDL_Init(SDL_INIT_VIDEO);
	mWindow = SDL_CreateWindow("SNLS", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	mContext = SDL_GL_CreateContext(mWindow);
	if (mWindow == NULL) {
		printf("Error: %s\n", SDL_GetError());
		sleep(1);
	}
	SDL_GL_MakeCurrent(mWindow, mContext);
	return;
}

/* Not used caused by the change of SDL+openGL
static void keyHandler(GLFWwindow* window, int key, int b, int c, int d) {
	Only a exit-handler 
	if (key == GLFW_KEY_ESCAPE) {
		printf("Exiting.. \n");
		exit(1);
	}
	return;
}
*/

extern void pollWindow() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(mWindow);
	/* TODO: change function name to pollEvents*/
	while (SDL_PollEvent(&mEvent)) {
		switch (mEvent.type) {
			case SDL_QUIT:
				exit(1);
			break;
		}
	}

	return;
}
