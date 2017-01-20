#include "../includes/rtv1.h"

void	sdl_err()
{
	ft_putendl_fd("ERROR SDL :", -1);
	ft_putendl_fd(SDL_GetError(), -1);
}

void	sdl_close(t_all *all)
{
	SDL_DestroyRenderer(all->ren);
	all->ren = NULL;
	SDL_FreeSurface(all->win_surf);
	all->win_surf = NULL;
	SDL_DestroyWindow(all->screen);
	all->screen = NULL;
	SDL_Quit();
}


void	sdl_init(t_all *all)
{
	all->screen = SDL_CreateWindow("RTV1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	if (all->screen == NULL)
		sdl_err();
	all->ren = SDL_CreateRenderer(all->screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (all->ren == NULL)
		sdl_err();
	all->win_surf = SDL_GetWindowSurface(all->screen);
	if (all->win_surf == NULL)
		sdl_err();
}

void 	sdl(t_all *all)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdl_err();
	else
	{
		sdl_init(&*all);
		event(&*all);
	}
	sdl_close(&*all);
}