#include "../includes/snake.h"

static void		init_border2_rect(t_sdl *sdl)
{
	sdl->border2_rect_up.x = 15;
	sdl->border2_rect_up.y = 15;
	sdl->border2_rect_up.w = 1170;
	sdl->border2_rect_up.h = 5;
	sdl->border2_rect_down.x = 15;
	sdl->border2_rect_down.y = 780;
	sdl->border2_rect_down.w = 1170;
	sdl->border2_rect_down.h = 5;
	sdl->border2_rect_left.x = 15;
	sdl->border2_rect_left.y = 20;
	sdl->border2_rect_left.w = 5;
	sdl->border2_rect_left.h = 760;
	sdl->border2_rect_right.x = 1180;
	sdl->border2_rect_right.y = 20;
	sdl->border2_rect_right.w = 5;
	sdl->border2_rect_right.h = 760;
}

static void		init_border_rect(t_sdl *sdl)
{
	sdl->border_rect_up.x = 0;
	sdl->border_rect_up.y = 0;
	sdl->border_rect_up.w = 1200;
	sdl->border_rect_up.h = 5;
	sdl->border_rect_down.x = 0;
	sdl->border_rect_down.y = 795;
	sdl->border_rect_down.w = 1200;
	sdl->border_rect_down.h = 5;
	sdl->border_rect_left.x = 0;
	sdl->border_rect_left.y = 5;
	sdl->border_rect_left.w = 5;
	sdl->border_rect_left.h = 790;
	sdl->border_rect_right.x = 1195;
	sdl->border_rect_right.y = 5;
	sdl->border_rect_right.w = 5;
	sdl->border_rect_right.h = 790;
}

void			init_sdl_struct(t_sdl *sdl)
{
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->bg.r = 0;
	sdl->bg.g = 25;
	sdl->bg.b = 51;
	sdl->bg.a = 255;
	sdl->border.r = 0;
	sdl->border.g = 76;
	sdl->border.b = 153;
	sdl->border.a = 255;
	init_border_rect(sdl);
	init_border2_rect(sdl);
}
