#include "../includes/rtv1.h"

void 	sdl_and_draw(t_all *all)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdl_err();
	else
	{
		sdl_init(&all->sdl);
		event(&*all, &all->sdl);
	}
	sdl_close(&all->sdl);
}

int main(void)
{
	t_all	all;

	sdl_and_draw(&all);
	return(0);
}
