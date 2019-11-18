#include "../includes/snake.h"

void			update_playground_texture(t_sdl *sdl, t_snake *snake,
				t_apple *apple)
{
	SDL_Color	playground_color = {0, 76, 153, 255};
	SDL_Rect	dst = {150, 225, 0, 0};
	SDL_Color	snake_color = {255, 255, 0, 255};
	SDL_Color	apple_color = {255, 0, 0, 255};
	SDL_Rect	square = {0, 0, 20, 20};

	create_playground_texture(sdl);
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
	if (apple)
	{
		generic_apply_colour_to_renderer(apple_color, sdl, 0);
		square.x = apple->x;
		square.y = apple->y;
		generic_fill_rect(square, sdl);
	}
	SDL_SetRenderTarget(sdl->renderer, NULL);
	SDL_QueryTexture(sdl->playground, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(sdl->renderer, sdl->playground, NULL, &dst);
	SDL_RenderPresent(sdl->renderer);
	SDL_DestroyTexture(sdl->playground);
}

t_snake			*snake_update_position(t_snake *snake, int direction,
				int *old_x, int *old_y)
{
	t_snake		*tmp;

	if (!snake || !snake->next)
		failure_exit_program("PLUS DE SNAKE", NULL);
	*old_x = snake->x;
	*old_y = snake->y;
	tmp = snake;
	snake = snake->next;
	free(tmp);
	snake->prev = NULL;
	while (snake->next)
		snake = snake->next;
	tmp = (t_snake*)malloc(sizeof(t_snake));
	if (direction == 1 || direction == 3)
		tmp->x = snake->x;
	else if (direction == 2 || direction == 4)
		tmp->y = snake->y;
	if (direction == 1)
		tmp->y = snake->y - 20;
	else if (direction == 2)
		tmp->x = snake->x + 20;
	else if (direction == 3)
		tmp->y = snake->y + 20;
	else if (direction == 4)
		tmp->x = snake->x - 20;
	tmp->prev = snake;
	tmp->next = NULL;
	snake->next = tmp;
	while (snake->prev)
		snake = snake->prev;
	return (snake);
}

void			get_updated_direction(t_sdl *sdl, int *direction)
{
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
		failure_exit_program("Quitting in middle of game", sdl);
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

int				check_if_snake_is_dead(t_snake *snake)
{
	t_snake		*head;

	head = snake;
	while (head->next)
		head = head->next;
	if (head->x >= 900 || head->x < 0 || head->y >= 500 || head->y < 0)
		return (1);
	while (snake->next && snake->next->next)
	{
		if (head->x == snake->x && head->y == snake->y)
			return (1);
		snake = snake->next;
	}
	return (0);
}

void			place_random_apple(t_apple *apple, t_snake *snake)
{
	t_snake		*head = snake;

	srand(time(NULL));
	apple->x = rand() % 880;
	apple->y = rand() % 480;
	while (apple->x % 20 != 0)
		apple->x++;
	while (apple->y % 20 != 0)
		apple->y++;
	while (snake->next)
	{
		if (snake->x == apple->x && snake->y == apple->y)
			place_random_apple(apple, head);
		snake = snake->next;
	}
	if (apple->prev_x == apple->x && apple->prev_y == apple->y)
		place_random_apple(apple, head);
	apple->prev_y = apple->y;
	apple->prev_x = apple->x;
}

t_snake			*check_eaten_apple(t_snake *snake, t_apple *apple,
				int old_x, int old_y)
{
	t_snake		*head = snake;
	t_snake		*new = NULL;

	while (snake->next)
		snake = snake->next;
	if (snake->x == apple->x && snake->y == apple->y)
	{
		place_random_apple(apple, snake);
		new = (t_snake*)malloc(sizeof(t_snake));
		new->x = old_x;
		new->y = old_y;
		new->prev = NULL;
		new->next = head;
		return (new);
	}
	return (head);
}

t_snake			*game_loop(t_sdl *sdl, t_snake *snake)
{
	int			n_frames_mod = 0;
	int			last_movement_drawn = 1;
	int			direction = 1;
	t_apple		*apple;
	int			old_x = 0;
	int			old_y = 0;

	apple = (t_apple*)malloc(sizeof(t_apple));
	apple->prev_x = -1;
	apple->prev_y = -1;
	place_random_apple(apple, snake);
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_KEYDOWN && last_movement_drawn)
			{
				get_updated_direction(sdl, &direction);
				last_movement_drawn = 0;
			}
			else
				break ;
		}
		if (n_frames_mod == 0)
		{
			snake = snake_update_position(snake, direction, &old_x, &old_y);
			update_playground_texture(sdl, snake, apple);
			last_movement_drawn = 1;
			SDL_Delay(40);
		}
		snake = check_eaten_apple(snake, apple, old_x, old_y);
		n_frames_mod = (n_frames_mod + 1) % 60;
		if (check_if_snake_is_dead(snake) == 1)
		{
			free(apple);
			break ;
		}
	}
	return (snake);
}
