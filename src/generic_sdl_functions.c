#include "../includes/snake.h"

void			generic_apply_colour_to_renderer(SDL_Color rgba, t_sdl *sdl,
				int clear_renderer)
{
	if ((SDL_SetRenderDrawColor(sdl->renderer, rgba.r, rgba.g, rgba.b, rgba.a))
			!= 0)
		failure_exit_program("Rendering Color", sdl);
	if (clear_renderer == 0)
		return ;
	if ((SDL_RenderClear(sdl->renderer)) != 0)
		failure_exit_program("Clearing renderer with color", sdl);
}

void			generic_fill_rect(SDL_Rect rect, t_sdl *sdl)
{
	if ((SDL_RenderFillRect(sdl->renderer, &rect)) != 0)
		failure_exit_program("Creating Rectangle", sdl);
}

