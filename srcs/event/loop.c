#include "../includes/rtv1.h"

void	mod_vect(t_vect	*vect, const Uint8 	*state, t_all *all)
{
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_UP] || \
		state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_KP_MINUS] || state[SDL_SCANCODE_KP_PLUS])
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

int		key_event2(t_sdl	*sdl, t_all *all)
{
	if (sdl->state[SDL_SCANCODE_KP_6])
	{
		mod_vect(&all->obj.cylinder.c, sdl->state, &*all);
		mod_vect(&all->obj.cylinder.end, sdl->state, &*all);
	}
	else if (sdl->state[SDL_SCANCODE_KP_3])
		mod_vect(&all->obj.cylinder.c, sdl->state, &*all);
	else if (sdl->state[SDL_SCANCODE_KP_9])
		mod_vect(&all->obj.cylinder.end, sdl->state, &*all);
	else if (sdl->state[SDL_SCANCODE_KP_4])
		mod_vect(&all->obj.cone.c, sdl->state, &*all);
	else if (sdl->state[SDL_SCANCODE_KP_7])
		mod_vect(&all->obj.cone.axe, sdl->state, &*all);
	return (1);
}

int		key_event(t_sdl	*sdl, t_all *all, int file)
{
	if (sdl->event.type == SDL_QUIT || sdl->state[SDL_SCANCODE_ESCAPE])
	{
		sdl_close(&*sdl);
		return (0);
	}
	if (sdl->state)
	{
		key_event2(&*sdl, &*all);
		if (sdl->state[SDL_SCANCODE_KP_0])
			mod_vect(&all->light.ray.o, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_1])
			mod_vect(&all->obj.sphere.c, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_2])
			mod_vect(&all->obj.plane.o, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_KP_5])
			mod_vect(&all->obj.plane.d, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_C])
			mod_vect(&all->cam.campos, sdl->state, &*all);
		else if (sdl->state[SDL_SCANCODE_1])
			init_sceen(&*all, file);
	}
	return (1);
}

void	event(t_all *all, t_sdl *sdl, int file)
{
	int 	isrunning;
	int 	check_all;

	all->chg = 0;
	isrunning = 1;
	check_all = all->chg;
	init_sceen(&*all, file);
	draw(&*all, &*sdl);
	while (isrunning == 1)
	{
		sdl->state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&sdl->event) != 0)
		{
			if (all->chg != check_all)
			{
				check_all = all->chg;
				draw(&*all, &*sdl);
			}
			isrunning = key_event(&all->sdl, &*all, file);
			key_event(&all->sdl, &*all, file);
		}
	}
		SDL_UpdateWindowSurface(sdl->screen);
}
