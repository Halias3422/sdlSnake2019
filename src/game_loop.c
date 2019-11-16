#include "../includes/snake.h"

void			update_playground_texture(t_sdl *sdl, t_snake *snake)
{
	SDL_Color	playground_color = {0, 76, 153, 255};
	SDL_Rect	dst = {150, 225, 0, 0};
	SDL_Color	snake_color = {255, 255, 0, 255};
	SDL_Rect	square = {0, 0, 20, 20};

	if ((SDL_SetRenderTarget(sdl->renderer, sdl->playground)) != 0)
		failure_exit_program("Setting playground as render target", sdl);
	generic_apply_colour_to_renderer(playground_color, sdl, 1);
	generic_apply_colour_to_renderer(snake_color, sdl, 0);
	while (snake)
	{
		square.x = snake->x;
		square.y = snake->y;
		generic_fill_rect(square, sdl);
		snake = snake->next;
	}
	SDL_SetRenderTarget(sdl->renderer, NULL);
	SDL_QueryTexture(sdl->playground, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(sdl->renderer, sdl->playground, NULL, &dst);
	SDL_RenderPresent(sdl->renderer);
}

void			get_updated_direction(t_sdl *sdl, int *direction)
{
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
		failure_exit_program("JE QUITTE", sdl);
	else if ((sdl->event.key.keysym.sym == SDLK_w ||
				sdl->event.key.keysym.sym == SDLK_UP) && *direction != 3)
		*direction = 1;
	else if ((sdl->event.key.keysym.sym == SDLK_d ||
				sdl->event.key.keysym.sym == SDLK_RIGHT) && *direction != 4)
		*direction = 2;
	else if ((sdl->event.key.keysym.sym == SDLK_s ||
				sdl->event.key.keysym.sym == SDLK_DOWN) && *direction != 1)
		*direction = 3;
	else if ((sdl->event.key.keysym.sym == SDLK_a ||
				sdl->event.key.keysym.sym == SDLK_LEFT) && *direction != 2)
		*direction = 4;
}

void			game_loop(t_sdl *sdl, t_snake *snake)
{
	int			direction = 1;
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
			get_updated_direction(sdl, &direction);
		SDL_Delay(150);
		snake = snake_update_position(snake, direction);
		update_playground_texture(sdl, snake);
	}
}
