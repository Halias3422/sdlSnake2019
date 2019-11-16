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
}						t_sdl;

//		MAIN_C

void			failure_exit_program(char *error, t_sdl *sdl);

//		GENEREIC_SDL_FUNCTIONS_C

void			generic_fill_rect(SDL_Rect rect, t_sdl *sdl);
void			generic_apply_colour_to_renderer(SDL_Color rgba, t_sdl *sdl,
				int clear_renderer);

//		INIT_PLAYGROUND_COLORS_C

void			apply_general_background_color(t_sdl *sdl);

#endif

