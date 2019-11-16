#include "../includes/snake.h"

// TO DRAW COLOR ON SCREEN ->
//		1. SDL_SetRenderDrawColor: give the renderer the RGBA colour values
//		2. SDL_RenderClear: Clear the renderer with the color
//		3. SDL_RenderPresent: Display the new rendered color

// TO DRAW INSIDE TEXTURE
//		1.SDL_SetRenderTarget: makes the texture become the renderer target
//		2.Draw
//		3.SDL_SetRenderTarget (renderer, NULL): make renderer target again once done

void			apply_window_borders_colors(t_sdl *sdl)
{
	SDL_Color	rect_border = {0, 76, 153, 255};
	SDL_Rect	border_rect_up = {0, 0, 1200, 5};
	SDL_Rect	border_rect_down = {0, 795, 1200, 5};
	SDL_Rect	border_rect_left = {0, 5, 5, 790};
	SDL_Rect	border_rect_right = {1195, 5, 5, 790};
	SDL_Rect	border2_rect_up = {15, 15, 1170, 5};
	SDL_Rect	border2_rect_down = {15, 780, 1170, 5};
	SDL_Rect	border2_rect_left = {15, 20, 5, 760};
	SDL_Rect	border2_rect_right = {1180, 20, 5, 760};

	generic_apply_colour_to_renderer(rect_border, sdl, 0);
	generic_fill_rect(border_rect_up, sdl);
	generic_fill_rect(border_rect_down, sdl);
	generic_fill_rect(border_rect_left, sdl);
	generic_fill_rect(border_rect_right, sdl);
	generic_fill_rect(border2_rect_up, sdl);
	generic_fill_rect(border2_rect_down, sdl);
	generic_fill_rect(border2_rect_left, sdl);
	generic_fill_rect(border2_rect_right, sdl);
}

void			create_title_texture(t_sdl *sdl)
{
	SDL_Color	texture_color = {0, 25, 51, 255};
	SDL_Color	title_color = {0, 76, 153, 255};
	SDL_Rect	dst = {200, 60, 0, 0};

	if ((sdl->title = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, 800, 100)) == NULL)
		failure_exit_program("Creating Title Texture", sdl);
	if ((SDL_SetRenderTarget(sdl->renderer, sdl->title)) != 0)
		failure_exit_program("Setting title as render target", sdl);

	generic_apply_colour_to_renderer(texture_color, sdl, 1);
	generic_apply_colour_to_renderer(title_color, sdl, 0);

	print_s_title(sdl, 0, 0);
	print_u_title(sdl, 50, 0);
	print_p_title(sdl, 100, 0);
	print_e_title(sdl, 150, 0);
	print_r_title(sdl, 200, 0);

	print_s_title(sdl, 300, 0);
	print_n_title(sdl, 350, 0);
	print_a_title(sdl, 400, 0);
	print_k_title(sdl, 450, 0);
	print_e_title(sdl, 500, 0);

	print_2_title(sdl, 600, 0);
	print_0_title(sdl, 650, 0);
	print_0_title(sdl, 700, 0);
	print_0_title(sdl, 750, 0);

	SDL_SetRenderTarget(sdl->renderer, NULL);
	SDL_QueryTexture(sdl->title, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(sdl->renderer, sdl->title, NULL, &dst);
}

void			apply_general_background_color(t_sdl *sdl)
{
	SDL_Color	bg = {0, 25, 51, 255};

	// SET GENERIC BACKGROUND COLOR
	generic_apply_colour_to_renderer(bg, sdl, 1);

	apply_window_borders_colors(sdl);
	create_title_texture(sdl);

	// APPLY NEW COLORS TO SCREEN
	SDL_RenderPresent(sdl->renderer);
}
