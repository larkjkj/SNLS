#include <stdio.h>
#include <unistd.h>

#include "vars/memory.h"

#include "GL/glew.h"
#include "GL/gl.h"
#include "GLFW/glfw3.h"
#include <ft2build.h>

#include FT_FREETYPE_H

GLFWwindow* glWin;
GLuint glTex;

int glWinWidth;
int glWinHeight;

GLuint emuFB[256 * 224];

extern void initGS() {
	glfwInit();

	/* WARNING: Setting this flag cause bugs on
	 * Hyprland, if you're a normal user, you probally
	 * shouldn't care about this, but if you are like me
	 * enable this or add a rule to fix */
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	glWin = glfwCreateWindow(256, 224, "SNLS", NULL, NULL);

	if (glWin == NULL) {
		printf("Failed to create glWin \n");
		sleep(1);
	}

	glfwMakeContextCurrent(glWin);
	glewInit();

	glGenTextures(1, &glTex);
	glBindTexture(GL_TEXTURE_2D, glTex);	
	glCreateTextures(GL_TEXTURE_2D, 1, &glTex);
	emuFB[256] = 255;
	emuFB[806] = 255;
	emuFB[236] = 255;
	emuFB[636] = 255;

	/* This one is just to make our first update */
	//glViewport(0, 0, glWinWidth / 2, glWinHeight / 2);
	return;
}

static void printKeyPressed(GLFWwindow* window, int key, int b, int c, int d) {
	/* Only a exit-handler */
	if (key == GLFW_KEY_ESCAPE) {
		printf("Exiting.. \n");
		exit(1);
	}
	if (key == GLFW_KEY_C) {
		printf("C pressionado \n");
	}
	return;
}

extern void renderGS() {
	/* TODO: change function name to pollEvents*/

	glTextureSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 256, 224, GL_RGBA, GL_UNSIGNED_BYTE, emuFB);
	glDrawArrays(GL_TRIANGLES, 0, 0);
	glfwSwapBuffers(glWin);

	glfwSetKeyCallback(glWin, printKeyPressed);
	glfwPollEvents();
	return;
}
