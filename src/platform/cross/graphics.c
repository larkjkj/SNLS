#include <stdio.h>
#include <unistd.h>

#include "emulator/memory.h"
#include "emulator/gs.h"

#include "GL/gl.h"
#include "png.h"
#include "SDL2/SDL.h"
#include <ft2build.h>

#include FT_FREETYPE_H

FT_Library ftLib;
FT_Face ftFace;
FT_UInt ftGlyph;

SDL_Window* sWindow = NULL;
SDL_Renderer* sRender = NULL;
SDL_Texture* sTexture = NULL;
SDL_Surface* sSurface = NULL;
SDL_Event mEvent;

SDL_Rect sRect;
char* teste = "pinto duro e grosso porra teste teste teste peins";

extern void initWindow() {
	/* This part only setup stuff */
	SDL_GL_SetAttribute(GL_BLEND, 1);
	sWindow = SDL_CreateWindow("SNLS", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS | SDL_WINDOW_MINIMIZED);
	sRender = SDL_CreateRenderer(sWindow, 0, SDL_RENDERER_ACCELERATED); 

	if (sWindow == NULL) {
		printf("Error: %s\n", SDL_GetError());
		sleep(1);
	} else {
		printf("window sucessfully created \n");
	}

	sRect.x = 0;
	sRect.y = 0;
	sRect.w = SCREEN_WIDTH / 2;
	sRect.h = SCREEN_HEIGHT / 2;


	if (!FT_Init_FreeType(&ftLib)) {
		printf("freetype initialized \n");
	}
	if (!FT_New_Face(ftLib, "assets/fonts/upheavtt.ttf", 0, &ftFace)) {
		printf("face added\n");
	}
	FT_Select_Charmap(ftFace, FT_ENCODING_UNICODE);
	//FT_Set_Char_Size(ftFace, 0, 16*64, 300, 300);
	FT_Set_Pixel_Sizes(ftFace, 0, 16);
	ftGlyph = FT_Get_Char_Index(ftFace, 'C');
	FT_Load_Glyph(ftFace, ftGlyph, 0);
	FT_Render_Glyph(ftFace->glyph, FT_RENDER_MODE_NORMAL);

	int* buffer = malloc(ftFace->glyph->bitmap.width * ftFace->glyph->bitmap.rows * 4);
	sSurface = SDL_CreateRGBSurfaceWithFormatFrom(buffer, ftFace->glyph->bitmap.width, ftFace->glyph->bitmap.rows, 4, ftFace->glyph->bitmap.pitch, SDL_PIXELFORMAT_ARGB32);

	sTexture = SDL_CreateTextureFromSurface(sRender, sSurface);
	SDL_SetTextureBlendMode(sTexture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureColorMod(sTexture, 128, 128, 128);
	SDL_SetTextureAlphaMod(sTexture, *ftFace->glyph->bitmap.buffer);

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
	SDL_RenderClear(sRender);
	SDL_RenderCopy(sRender, sTexture, NULL, &sRect);
	SDL_RenderPresent(sRender);
	/* TODO: change function name to pollEvents*/
	while (SDL_PollEvent(&mEvent)) {
		switch (mEvent.type) {
			case SDL_QUIT:
				exit(1);
			break;
			case SDL_MOUSEMOTION:
				printf("mouse X: %d Y: %d \n", mEvent.motion.x, mEvent.motion.y);
			break;
		}
	}

	return;
}
