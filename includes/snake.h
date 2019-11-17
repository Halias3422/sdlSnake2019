#ifndef SNAKE_H
# define SNAKE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <SDL2/SDL.h>

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Color			border;
	SDL_Texture			*title;
	SDL_Texture			*playground;
	SDL_Event			event;
}						t_sdl;

typedef struct			s_snake
{
	int					x;
	int					y;
	struct s_snake		*prev;
	struct s_snake		*next;
}						t_snake;

typedef struct			s_keys
{
	int					direction;
	struct s_keys		*next;
}						t_keys;

//		MAIN_C

void			failure_exit_program(char *error, t_sdl *sdl);
void			free_snake_list(t_snake *snake);

//		GENEREIC_SDL_FUNCTIONS_C

void			generic_fill_rect(SDL_Rect rect, t_sdl *sdl);
void			generic_apply_colour_to_renderer(SDL_Color rgba, t_sdl *sdl,
				int clear_renderer);

//		INIT_PLAYGROUND_COLORS_C

void			apply_general_background_color(t_sdl *sdl);

//		PRINT_TITLE_LETTERS_C

void			print_s_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_u_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_p_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_e_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_r_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_n_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_a_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_k_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_2_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_0_title(t_sdl *sdl, int offset_x, int offset_y);

//		GAME_LOOP_C

void			game_loop(t_sdl *sdl, t_snake *snake);
void			update_playground_texture(t_sdl *sdl, t_snake *snake);

//		UPDATE_SNAKE_POSITION_C


t_snake			*snake_update_position(t_snake *snake, int direction);
t_snake			*snake_going_up(t_snake *snake);
t_snake			*snake_going_right(t_snake *snake);
t_snake			*snake_going_down(t_snake *snake);
t_snake			*snake_going_left(t_snake *snake);

//		DEBUG_C

void			print_snake_list(t_snake *snake);

#endif

