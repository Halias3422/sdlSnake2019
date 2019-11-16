#include "../includes/snake.h"

void			init_sdl_struct(t_sdl *sdl)
{
	sdl->window = NULL;
	sdl->renderer = NULL;
}

void			failure_exit_program(char *error, t_sdl *sdl)
{
	//	CENTRALIZING ERROR MESSAGES AND MAKING SURE SLD ALLOCS ARE CLEANED
	fprintf(stderr, "Error %s --> (%s)\n", error, SDL_GetError());
	if (!sdl)
		exit(EXIT_FAILURE);
	if (sdl->window != NULL)
		SDL_DestroyWindow(sdl->window);
	if (sdl->renderer != NULL)
		SDL_DestroyRenderer(sdl->renderer);
	SDL_Quit();
	exit(EXIT_FAILURE);
}

//	ADD ULTRA COOL BORDER LINES FOR FUTURISTIC STYLING

void			init_window_and_renderer_sdl(t_sdl *sdl)
{
	//	INIT SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		failure_exit_program("initialization SDL", sdl);
	printf("SDL Successfully initialized\n");

	//	CREATE WINDOW FOR GAME
	if ((sdl->window = SDL_CreateWindow("SUPER OVER THE TOP SNAKE 2000",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 800,
	SDL_WINDOW_SHOWN)) == NULL)
		failure_exit_program("creating sdl->window", sdl);
	printf("Window '%s' successfully created\n", SDL_GetWindowTitle(sdl->window));

	//	CREATE RENDERER FOR WINDOW
	if ((sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
	SDL_RENDERER_ACCELERATED)) == NULL)
		failure_exit_program("creating renderer", sdl);
}

int				main(void)
{
	t_sdl		sdl;

	init_sdl_struct(&sdl);
	init_window_and_renderer_sdl(&sdl);
	apply_general_background_color(&sdl);
	SDL_Delay(4000);
	//	CLEAN SDL ALLOCS
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
