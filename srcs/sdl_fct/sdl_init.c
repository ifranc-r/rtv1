/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:05:15 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/09 17:05:17 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	sdl_err()
{
	ft_putendl_fd("ERROR SDL :", -1);
	ft_putendl_fd(SDL_GetError(), -1);
}

void	sdl_close(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	sdl->ren = NULL;
	SDL_FreeSurface(sdl->win_surf);
	sdl->win_surf = NULL;
	SDL_DestroyWindow(sdl->screen);
	sdl->screen = NULL;
	SDL_Quit();
}


void	sdl_init(t_sdl *sdl)
{
	sdl->screen = SDL_CreateWindow("RTV1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	if (sdl->screen == NULL)
		sdl_err();
	sdl->ren = SDL_CreateRenderer(sdl->screen, -1, SDL_RENDERER_SOFTWARE);
	if (sdl->ren == NULL)
		sdl_err();
	sdl->win_surf = SDL_GetWindowSurface(sdl->screen);
	if (sdl->win_surf == NULL)
		sdl_err();
}
