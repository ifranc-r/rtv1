#include "../includes/rtv1.h"

void	draw(t_all *all)
{
	int 	i;
	int		j;

	i = 0;
	SDL_SetRenderDrawColor(all->ren, 0, 51, 51, 40); //couleur fond vert
	while (++i < WIN_X)
	{
		j = 0;
		while (++j < WIN_Y)
			SDL_RenderDrawPoint(all->ren, i, j);
	}
	SDL_RenderPresent(all->ren);
}