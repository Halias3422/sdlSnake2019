#include "../includes/snake.h"


void			failure_exit_program(char *error, t_sdl *sdl)
{
	//	CENTRALIZING ERROR MESSAGES AND MAKING SURE SLD ALLOCS ARE CLEANED
	fprintf(stderr, "Error %s --> (%s)\n", error, SDL_GetError());
	if (!sdl)
		exit(EXIT_FAILURE);
	SDL_DestroyWindow(sdl->window);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyTexture(sdl->title);
	SDL_DestroyTexture(sdl->playground);
	SDL_DestroyTexture(sdl->looser);
	SDL_DestroyTexture(sdl->score);
	SDL_Quit();
	exit(EXIT_FAILURE);
}

int				free_snake_list(t_snake *snake)
{
	t_snake		*tmp;
	int			score = 0;

	while (snake)
	{
		tmp = snake;
		snake = snake->next;
		free(tmp);
		tmp = NULL;
		score++;
	}
	return (score);
}

int				main_loop(t_sdl *sdl, t_snake *snake)
{
	int			score = 0;

	apply_general_background_color(sdl);
	snake = (t_snake*)malloc(sizeof(t_snake));
	init_snake_list(snake);

	update_playground_texture(sdl, snake, NULL);
	SDL_Delay(1000);
	snake = game_loop(sdl, snake);
	score = ((free_snake_list(snake) - 4) * 10);

	apply_general_background_color(sdl);
	print_looser_score(sdl, score);
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			else if (sdl->event.key.keysym.sym == SDLK_RETURN)
			{
				main_loop(sdl, NULL);
				return (1);
			}
		}
		SDL_Delay(100);
	}
}

int				main(void)
{
	t_sdl		sdl;
	t_snake		*snake = NULL;

	//	INIT SDL, GAME WINDOW AND SNAKE LIST
	init_sdl_struct(&sdl);
	init_window_and_renderer_sdl(&sdl);

	//	MAIN GAME LOOP
	main_loop(&sdl, snake);

	//	CLEAN SDL ALLOCS
	SDL_DestroyRenderer(sdl.renderer);
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	printf("CLEAN EXIT\n");
	return (EXIT_SUCCESS);
}
