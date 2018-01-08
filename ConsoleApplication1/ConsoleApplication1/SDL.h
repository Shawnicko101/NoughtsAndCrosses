#pragma once
#include <iostream>
#include <stdio.h>
#include <SDL.h>

int main(int argc, char *argv[]) {

	//Creating an object for the window
	SDL_Window* window = NULL;
	//Creating a surface for rendering the game
	SDL_Surface* renderFrame = NULL;

	//Surfaces for graphics which are loaded
	SDL_Surface* image_hello = NULL;
	SDL_Surface* image_world = NULL;

	//Setting up the SDL Window
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		return 0;

	}

	window = SDL_CreateWindow("Noughts and Crosses", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	renderFrame = SDL_GetWindowSurface(window);

	if (renderFrame == NULL) {
		printf("Render frame could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	image_hello = SDL_LoadBMP("hello.bmp");
	if (image_hello == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	image_world = SDL_LoadBMP("world.bmp");
	if (image_world == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	while (true) {
		//Clear screen to blue
		SDL_FillRect(renderFrame, NULL, 0x6495ed);
		//Apply graphic to the frame
		SDL_BlitSurface(image_hello, NULL, renderFrame, NULL);
		//Apply world graphic to screen
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 200;
		rect.w = 640;
		rect.h = 169;

		SDL_BlitSurface(image_world, NULL, renderFrame, NULL);
		SDL_UpdateWindowSurface(window);

		SDL_Delay(0);


	}




	return 0;
}