#include <stdio.h>
#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* argv[])
{
	// window to render to
	SDL_Window* pWindow;

	// surface of window
	SDL_Surface* pSurface;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL not initialized! Error: %s\n", SDL_GetError());
	}

	else
	{
		pWindow = SDL_CreateWindow(
			"Natural Engine",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (!pWindow)
		{
			printf("Window could not be created! Error: %s\n", SDL_GetError());

			return 101;
		}

		pSurface = SDL_GetWindowSurface(pWindow);

		if (!pSurface)
		{
			printf("Surface could not be created! Error: %s\n", SDL_GetError());

			return 102;
		}

		SDL_FillRect(
			pSurface,
			nullptr,
			SDL_MapRGB(
				pSurface->format,
				0x00,
				0x00,
				0x00));
	}
	
	return 0;
}