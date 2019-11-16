#include "../includes/snake.h"

// TO DRAW COLOR ON SCREEN ->
//		1. SDL_SetRenderDrawColor: give the renderer the RGBA colour values
//		2. SDL_RenderClear: Clear the renderer with the color
//		3. SDL_RenderPresent: Display the new rendered color

void			apply_general_background_color(t_sdl *sdl)
{
	SDL_Color	bg = {0, 25, 51, 255};
	SDL_Color	rect_border = {0, 76, 153, 255};
	SDL_Rect	border_rect_up = {0, 0, 1200, 5};
	SDL_Rect	border_rect_down = {0, 795, 1200, 5};
	SDL_Rect	border_rect_left = {0, 5, 5, 790};
	SDL_Rect	border_rect_right = {1195, 5, 5, 790};
	SDL_Rect	border2_rect_up = {15, 15, 1170, 5};
	SDL_Rect	border2_rect_down = {15, 780, 1170, 5};
	SDL_Rect	border2_rect_left = {15, 20, 5, 760};
	SDL_Rect	border2_rect_right = {1180, 20, 5, 760};

	// SET GENERIC BACKGROUND COLOR
	generic_apply_colour_to_renderer(bg, sdl, 1);

	// SET DUPPER SUPER BACKGROUND BORDER COLORS
	generic_apply_colour_to_renderer(rect_border, sdl, 0);
	generic_fill_rect(border_rect_up, sdl);
	generic_fill_rect(border_rect_down, sdl);
	generic_fill_rect(border_rect_left, sdl);
	generic_fill_rect(border_rect_right, sdl);
	generic_fill_rect(border2_rect_up, sdl);
	generic_fill_rect(border2_rect_down, sdl);
	generic_fill_rect(border2_rect_left, sdl);
	generic_fill_rect(border2_rect_right, sdl);

	// APPLY NEW COLORS TO SCREEN
	SDL_RenderPresent(sdl->renderer);
}
