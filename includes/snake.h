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
	SDL_Color			bg;
	SDL_Color			border;
	SDL_Rect			border_rect_up;
	SDL_Rect			border_rect_down;
	SDL_Rect			border_rect_left;
	SDL_Rect			border_rect_right;
	SDL_Rect			border2_rect_up;
	SDL_Rect			border2_rect_down;
	SDL_Rect			border2_rect_left;
	SDL_Rect			border2_rect_right;
}						t_sdl;

/*
**	INIT_SDL_STRUCT_C
*/

void			init_sdl_struct(t_sdl *sdl);

#endif

