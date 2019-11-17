#include "../includes/snake.h"

void			print_l_looser(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 300, 140, 100};
	SDL_Rect	vert_bar = {0, 0, 70, 400};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	generic_fill_rect(vert_bar, sdl);
}

void			print_o_looser(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {60, 0, 20, 100};
	SDL_Rect	vert_bar = {0, 0, 60, 400};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		generic_fill_rect(hor_bar, sdl);
		vert_bar.x += 80;
		hor_bar.y += 300;
	}
}

void			print_s_looser(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 140, 100};
	SDL_Rect	vert_bar = {0, 100, 60, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 150;
	}
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 80;
		vert_bar.y += 150;
	}
}

void			print_e_looser(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {70, 0, 70, 100};
	SDL_Rect	vert_bar = {0, 0, 70, 400};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 150;
	}
}

void			print_r_looser(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {60, 0, 80, 100};
	SDL_Rect	vert_bar = {0, 0, 60, 400};
	SDL_Rect	diag_bar = {40, 250, 60, 2};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	diag_bar.x += offset_x;
	diag_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 150;
		if (i == 0)
			generic_fill_rect(vert_bar, sdl);
	}
	vert_bar.x += 80;
	vert_bar.y += 100;
	vert_bar.h = 50;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 80; i++)
	{
		generic_fill_rect(diag_bar, sdl);
		diag_bar.x += 1;
		diag_bar.y += 2;
	}
}

void			print_number_score(t_sdl *sdl, char num, int *offset_x)
{
	if (num == '0')
		print_0_title(sdl, *offset_x, 0);
	if (num == '1')
		print_1_title(sdl, *offset_x, 0);
	if (num == '2')
		print_2_title(sdl, *offset_x, 0);
	if (num == '3')
		print_3_title(sdl, *offset_x, 0);
	if (num == '4')
		print_4_title(sdl, *offset_x, 0);
	if (num == '5')
		print_5_title(sdl, *offset_x, 0);
	if (num == '6')
		print_6_title(sdl, *offset_x, 0);
	if (num == '7')
		print_7_title(sdl, *offset_x, 0);
	if (num == '8')
		print_8_title(sdl, *offset_x, 0);
	if (num == '9')
		print_9_title(sdl, *offset_x, 0);
	*offset_x -= 50;

}

void			print_game_score(t_sdl *sdl, int score)
{
	SDL_Color	score_bg = {0, 25, 51, 255};
	SDL_Color	score_color = {255, 0, 0, 255};
	SDL_Rect	dst = {150, 650, 0, 0};
	char		*str_score = NULL;
	int			i = 0;
	int			offset_x = 850;

	if ((sdl->score = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, 900, 100)) == NULL)
		failure_exit_program("Creating Score Texture", sdl);
	if ((SDL_SetRenderTarget(sdl->renderer, sdl->score)) != 0)
		failure_exit_program("Setting Score as render target", sdl);

	generic_apply_colour_to_renderer(score_bg, sdl, 1);
	generic_apply_colour_to_renderer(score_color, sdl, 0);

	print_s_title(sdl, 0, 0);
	print_c_title(sdl, 50, 0);
	print_0_title(sdl, 100, 0);
	print_r_title(sdl, 150, 0);
	print_e_title(sdl, 200, 0);
	print_db_points_title(sdl, 300, 0);
	str_score = ft_itoa_base_uns(score, 10);
	i = strlen(str_score) - 1;
	while (i >= 0)
	{
		print_number_score(sdl, str_score[i], &offset_x);
		i--;
	}
	free(str_score);
	while (offset_x > 300)
	{
		print_0_title(sdl, offset_x, 0);
		offset_x -= 50;
	}
	SDL_SetRenderTarget(sdl->renderer, NULL);
	SDL_QueryTexture(sdl->score, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(sdl->renderer, sdl->score, NULL, &dst);
	SDL_RenderPresent(sdl->renderer);
}

void			print_looser_score(t_sdl *sdl, int score)
{
	SDL_Color	looser_bg = {0, 25, 51, 255};
	SDL_Color	looser_color = {255, 0, 0, 255};
	SDL_Rect	dst = {150, 225, 0, 0};
	(void)sdl;
	(void)score;

	if ((sdl->looser = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, 900, 400)) == NULL)
		failure_exit_program("Creating Looser Texture", sdl);
	if ((SDL_SetRenderTarget(sdl->renderer, sdl->looser)) != 0)
		failure_exit_program("Setting looser as render target", sdl);

	generic_apply_colour_to_renderer(looser_bg, sdl, 1);
	generic_apply_colour_to_renderer(looser_color, sdl, 0);

	print_l_looser(sdl, 0, 0);
	print_o_looser(sdl, 150, 0);
	print_o_looser(sdl, 300, 0);
	print_s_looser(sdl, 450, 0);
	print_e_looser(sdl, 600, 0);
	print_r_looser(sdl, 750, 0);

	SDL_SetRenderTarget(sdl->renderer, NULL);
	SDL_QueryTexture(sdl->looser, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(sdl->renderer, sdl->looser, NULL, &dst);
	SDL_RenderPresent(sdl->renderer);
	print_game_score(sdl, score);
}
