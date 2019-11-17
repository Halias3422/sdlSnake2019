#include "../includes/snake.h"

void			init_sdl_struct(t_sdl *sdl)
{
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->title = NULL;
	sdl->playground = NULL;
}

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

void			create_playground_texture(t_sdl *sdl)
{
	if ((sdl->playground = SDL_CreateTexture(sdl->renderer,
					SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 900, 500))
			== NULL)
		failure_exit_program("Creating Playground Texture", sdl);
}


void			init_snake_list(t_snake *snake)
{
	t_snake		*tmp;
	int			x = 440;
	int			y = 360;

	snake->prev = NULL;
	snake->x = x;
	snake->y = y;
	snake->next = NULL;
	for (int i = 0; i < 3; i++)
	{
		y -= 20;
		tmp = (t_snake*)malloc(sizeof(t_snake));
		tmp->prev = snake;
		tmp->next = NULL;
		tmp->x = x;
		tmp->y = y;
		snake->next = tmp;
		snake = snake->next;
	}
}
