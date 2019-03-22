
#pragma once

//screen dimension
const int SCREEN_WIDTH = 637;
const int SCREEN_HEIGHT = 477;


//Initialization
	//window
SDL_Window* gWindow = NULL;
//Surfaces
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gGameSurface = NULL;
SDL_Texture* gSprite = NULL;
//Textures
SDL_Texture* Background = NULL;
//Renderer
SDL_Renderer* gRenderer;

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); success = false;
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("Pac Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Game Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			
		}
	}
	return success;
}

bool loadBackgroundImage() {
	bool success = true;
		gGameSurface = SDL_LoadBMP("Background.bmp");
		if (gGameSurface == NULL) {
			printf("SDL could not load Background! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		gSprite = SDL_LoadBMP("Pacman.bmp");
		SDL_RenderCopy(gRenderer, gSprite, NULL, NULL);
	return success;
}


void close() {
	SDL_FreeSurface(gScreenSurface);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}