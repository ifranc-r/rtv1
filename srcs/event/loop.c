#include "../includes/rtv1.h"

void	mod_vect(t_vect	*vect, const Uint8 	*state, t_all *all)
{
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_UP] || \
		state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_KP_PLUS] || state[SDL_SCANCODE_KP_MINUS])
	{
		if (state[SDL_SCANCODE_RIGHT])
			vect->x+= 1;
		else if (state[SDL_SCANCODE_LEFT])
			vect->x-= 1;
		else if (state[SDL_SCANCODE_UP])
			vect->y+= 1;
		else if (state[SDL_SCANCODE_DOWN])
			vect->y-= 1;
		else if (state[SDL_SCANCODE_KP_PLUS])
			vect->z+= 1;
		else if (state[SDL_SCANCODE_KP_MINUS])
			vect->z-= 1;
		all->chg++;
	}
}

int		key_event(t_sdl	*sdl, t_all *all)
{
	if (sdl->event.type == SDL_QUIT || sdl->state[SDL_SCANCODE_ESCAPE])
	{
		sdl_close(&*sdl);
		return (0);
	}
	if (sdl->state)
	{
		if (sdl->state[SDL_SCANCODE_0])
			mod_vect(&all->light.ray.o, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_1])
			mod_vect(&all->obj.sphere.c, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_2])
			mod_vect(&all->obj.plane.o, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_5])
			mod_vect(&all->obj.plane.d, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_3])
			mod_vect(&all->obj.cylinder.c, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_6])
			mod_vect(&all->obj.cylinder.axe, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_4])
			mod_vect(&all->obj.cone.c, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_7])
			mod_vect(&all->obj.cone.axe, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_1])
			init_sceen(&*all);
	}
	return (1);
}

void	event(t_all *all, t_sdl *sdl)
{
	int 	isrunning;
	int 	check_all;

	all->chg = 0;
	isrunning = 1;
	check_all = all->chg;
	init_sceen(&*all);
	draw(&*all, &*sdl);
	while (isrunning == 1)
	{
		sdl->state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&sdl->event) != 0)
		{
			if (all->chg != check_all)
			{
				check_all = all->chg;
				// printf("merddde");
				draw(&*all, &*sdl);
			}
			isrunning = key_event(&all->sdl, &*all);
			key_event(&all->sdl, &*all);
		}
	}
		SDL_UpdateWindowSurface(sdl->screen);
}
