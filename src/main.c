#include "../includes/snake.h"

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
void			print_window_borders_rectangles(t_sdl *sdl)
{
	if ((SDL_SetRenderDrawColor(sdl->renderer, sdl->border.r, sdl->border.g,
					sdl->border.b, sdl->border.a)) != 0)
		failure_exit_program("Rendering Borderline1 Color", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border_rect_up)) != 0)
		failure_exit_program("Creating Up Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border_rect_down)) != 0)
		failure_exit_program("Creating Down Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border_rect_left)) != 0)
		failure_exit_program("Creating Left Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border_rect_right)) != 0)
		failure_exit_program("Creating Right Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border2_rect_up)) != 0)
		failure_exit_program("Creating Up2 Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border2_rect_down)) != 0)
		failure_exit_program("Creating Down2 Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border2_rect_left)) != 0)
		failure_exit_program("Creating Left2 Rectangle", sdl);
	if ((SDL_RenderFillRect(sdl->renderer, &sdl->border2_rect_right)) != 0)
		failure_exit_program("Creating Right2 Rectangle", sdl);
}

void			init_window_sdl(t_sdl *sdl)
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

	//	ADD COLOR TO WINDOW BACKGROUND
		//	SET THE COLOR
	if ((SDL_SetRenderDrawColor(sdl->renderer, sdl->bg.r, sdl->bg.g, sdl->bg.b,
					sdl->bg.a)) != 0)
		failure_exit_program("Rendering Background Color", sdl);
		//	CLEAR RENDERING TARGET WITH DRAWING COLOR
	if ((SDL_RenderClear(sdl->renderer)) != 0)
		failure_exit_program("Clearing renderer with drawing color", sdl);
	print_window_borders_rectangles(sdl);
		//	DISPLAY NEW COLOR
	SDL_RenderPresent(sdl->renderer);

}

int				main(void)
{
	t_sdl		sdl;

	init_sdl_struct(&sdl);
	init_window_sdl(&sdl);
	SDL_Delay(4000);

	//	CLEAN SDL ALLOCS
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
