#include "../includes/rtv1.h"

void	event(t_all *all)
{
	int isrunning;

	isrunning = 1;
	draw(&*all);
	while (isrunning == 1)
	{
		all->state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&all->event) != 0)
		{
			if (all->event.type == SDL_QUIT || all->state[SDL_SCANCODE_ESCAPE])
			{
				sdl_close(&*all);
				--isrunning;
			}
		}
	}
		SDL_UpdateWindowSurface(all->screen);
}