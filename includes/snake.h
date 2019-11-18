#ifndef SNAKE_H
# define SNAKE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <SDL2/SDL.h>
# include <time.h>

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Color			border;
	SDL_Texture			*title;
	SDL_Texture			*playground;
	SDL_Texture			*looser;
	SDL_Texture			*score;
	SDL_Event			event;
}						t_sdl;

typedef struct			s_snake
{
	int					x;
	int					y;
	struct s_snake		*prev;
	struct s_snake		*next;
}						t_snake;

typedef struct			s_apple
{
	int					x;
	int					y;
	int					prev_x;
	int					prev_y;
}						t_apple;

char			*ft_itoa_base_uns(unsigned long long nb, int base);
char			*ft_strdup(char *str);
char			*ft_strrev(char *str);

//		MAIN_C

void			failure_exit_program(char *error, t_sdl *sdl);
int				free_snake_list(t_snake *snake);

//		INIT_GAME_C

void			init_sdl_struct(t_sdl *sdl);
void			init_window_and_renderer_sdl(t_sdl *sdl);
void			create_playground_texture(t_sdl *sdl);
void			init_snake_list(t_snake *snake);

//		GENERIC_SDL_FUNCTIONS_C

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
void			print_0_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_1_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_2_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_3_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_4_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_5_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_6_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_7_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_8_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_9_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_c_title(t_sdl *sdl, int offset_x, int offset_y);
void			print_db_points_title(t_sdl *sdl, int offset_x, int offset_y);

//		GAME_LOOP_C

t_snake			*game_loop(t_sdl *sdl, t_snake *snake);
void			update_playground_texture(t_sdl *sdl, t_snake *snake,
				t_apple *apple);

//		PRINT_LOOSER_SCORE_C

void			print_looser_score(t_sdl *sdl, int score);

//		DEBUG_C

void			print_snake_list(t_snake *snake);

#endif

