#include "snake.h"

void	sdl_error(void)
{
	fprintf(stderr, "Error initialization SDL (%s)\n", SDL_GetError());
	exit(EXIT_FAILURE);
}

void	first_init_sdl(void)
{
	SDL_Surface		*screen = NULL;		// MAIN DISPLAY


	if (SDL_Init(SDL_INIT_VIDEO) == -1 ||
	((screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE |
	SDL_DOUBLEBUF)) == NULL))
		sdl_error();
	SDL_WM_SetCaption("Super Snake 2000", NULL);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_Flip(screen);
}

int		main(void)
{
	first_init_sdl();
	while (1);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
