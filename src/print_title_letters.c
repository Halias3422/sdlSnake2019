#include "../includes/snake.h"

void			print_s_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};
	SDL_Rect	vert_bar = {0, 20, 20, 20};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 25;
		vert_bar.y += 40;
	}
}

void			print_u_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 80, 45, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 80};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 25;
	}
}

void			print_p_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {15, 0, 15, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 60};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 30;
		if (i == 0)
		vert_bar.w -= 5;
	}
	vert_bar.x = 0 + offset_x;;
	vert_bar.y += 60;
	vert_bar.h = 40;
	vert_bar.w += 5;
	generic_fill_rect(vert_bar, sdl);
}

void			print_e_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {20, 0, 25, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
}

void			print_r_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {10, 60, 20, 2};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	print_p_title(sdl, offset_x, offset_y);
	for (int i = 0; i < 30; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.x += 1;
		hor_bar.y += 2;
	}
}

void			print_n_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 20, 2};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 25;
	}
	for (int i = 0; i < 50; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		if (i % 2 == 0)
		hor_bar.x += 1;
		hor_bar.y += 2;
	}
}

void			print_a_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {20, 0, 5, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		generic_fill_rect(vert_bar, sdl);
		hor_bar.y += 40;
		vert_bar.x += 25;
	}

}

void			print_k_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	vert_bar = {0, 0, 20, 100};
	SDL_Rect	diag_up = {0, 60, 20, 2};
	SDL_Rect	diag_down = {0, 40, 20, 2};

	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	diag_up.x += offset_x;
	diag_up.y += offset_y;
	diag_down.x += offset_x;
	diag_down.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 35; i++)
	{
		generic_fill_rect(diag_up, sdl);
		generic_fill_rect(diag_down, sdl);
		diag_up.x += 1;
		diag_up.y -= 2;
		diag_down.x += 1;
		diag_down.y += 2;
	}
}

void			print_2_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};
	SDL_Rect	vert_bar = {25, 20, 20, 20};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.y += 40;
		vert_bar.x -= 25;
	}
}

void			print_0_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	print_u_title(sdl, offset_x, offset_y);
}

void			print_1_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 80, 45, 20};
	SDL_Rect	vert_bar = {15, 0, 20, 80};
	SDL_Rect	diag_bar = {15, 0, 10, 2};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	diag_bar.x += offset_x;
	diag_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 15; i++)
	{
		generic_fill_rect(diag_bar, sdl);
		if (i == 4)
			diag_bar.w += 5;
		diag_bar.x -= 1;
		diag_bar.y += 2;
	}
}

void			print_3_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 25, 20};
	SDL_Rect	vert_bar = {25, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
}

void			print_4_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 40, 45, 20};
	SDL_Rect	vert_bar = {25, 0, 20, 100};
	SDL_Rect	diag_bar = {0, 40, 20, 2};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	diag_bar.x += offset_x;
	diag_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 21; i++)
	{
		generic_fill_rect(diag_bar, sdl);
		diag_bar.x += 1;
		diag_bar.y -= 2;
	}
}


void			print_5_title(t_sdl *sdl, int offset_x, int offset_y)
{
	print_s_title(sdl, offset_x, offset_y);
}

void			print_6_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {20, 0, 25, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
	vert_bar.y += 60;
	vert_bar.x += 25;
	vert_bar.h = 20;
	generic_fill_rect(vert_bar, sdl);
}

void			print_7_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};
	SDL_Rect	vert_bar = {25, 20, 20, 3};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(hor_bar, sdl);
	for (int i = 0; i < 30; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x -= 1;
		vert_bar.y += 3;
	}
}

void			print_8_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(vert_bar, sdl);
		vert_bar.x += 25;
	}
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
}

void			print_9_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {0, 0, 45, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 40};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	vert_bar.h = 100;
	vert_bar.x += 25;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 3; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 40;
	}
}

void			print_c_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	hor_bar = {20, 0, 25, 20};
	SDL_Rect	vert_bar = {0, 0, 20, 100};

	hor_bar.x += offset_x;
	hor_bar.y += offset_y;
	vert_bar.x += offset_x;
	vert_bar.y += offset_y;
	generic_fill_rect(vert_bar, sdl);
	for (int i = 0; i < 2; i++)
	{
		generic_fill_rect(hor_bar, sdl);
		hor_bar.y += 80;
	}
}

void			print_db_points_title(t_sdl *sdl, int offset_x, int offset_y)
{
	SDL_Rect	square = {15, 20, 20, 20};

	square.x += offset_x;
	square.y += offset_y;
	generic_fill_rect(square, sdl);
	square.y += 40;
	generic_fill_rect(square, sdl);
}
