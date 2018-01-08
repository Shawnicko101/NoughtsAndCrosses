/* Noughts and Crosses Game for C++
Shawn Hickens S16151719
Lecturer: Carlo Harvey





*/

//Inclusion of SDL Libraries
#include <iostream>
#include <SDL.h>
#include <stdio.h>

//Defining SDL main function
int main(int argc, char *argv[]) {

	bool running = true;

	//Creating an object for the window
	SDL_Window* window = NULL;
	//Creating a surface for rendering the game
	SDL_Surface* renderFrame = NULL;

	//Surfaces for graphics which are loaded
	SDL_Surface* image_grid = NULL;
	SDL_Surface* image_noughts = NULL;
	SDL_Surface* image_crosses = NULL;

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
	image_grid = SDL_LoadBMP("grid.bmp");
	if (image_grid == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	image_crosses = SDL_LoadBMP("Cross.bmp");
	if (image_crosses == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
	}
	image_noughts = SDL_LoadBMP("Noughts.bmp");
	if (image_noughts == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
	}

	while (running = true) {
		//Clear screen to blue
		SDL_FillRect(renderFrame, NULL, 0x6495ed);
		//Apply grid graphic to the frame
		SDL_BlitSurface(image_grid, NULL, renderFrame, NULL);
		/*//Apply cross graphic to screen
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 200;
		rect.w = 640;
		rect.h = 169;
		SDL_BlitSurface(image_crosses, NULL, renderFrame, &rect);

		SDL_Rect nought;
		rect.x = 250;
		rect.y = 200;
		rect.w = 640;
		rect.h = 169;
		SDL_BlitSurface(image_noughts, NULL, renderFrame, &rect);

		SDL_Rect nought2;
		rect.x = 500;
		rect.y = 200;
		rect.w = 640;
		rect.h = 169;
		SDL_BlitSurface(image_noughts, NULL, renderFrame, &rect);
		
		*/

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				SDL_Rect nought;
				SDL_BlitSurface(image_noughts, NULL, renderFrame, &nought);
				break;
				SDL_UpdateWindowSurface(window);
				
			}
		}
		SDL_UpdateWindowSurface(window);

		SDL_Delay(5);


	}


	SDL_FreeSurface(image_grid);
	image_grid = NULL;
	SDL_FreeSurface(image_crosses);
	image_crosses = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();



	return 0;
}
