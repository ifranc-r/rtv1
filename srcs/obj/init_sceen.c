/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sceen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:03:58 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 17:15:03 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		init_sceen(t_all *all, int file)
{
	all->light = all->obj.light;
	all->cam = all->obj.cam;
	init_cam(&all->cam, file);
	init_cylinder(&all->obj.cylinder, file);
	init_light(&all->light, file);
	init_cone(&all->obj.cone, file);
	if (file == 0)
	{
		init_plane(&all->obj.plane);
		init_sphere(&all->obj.sphere);
	}
	all->chg++;
}

void		init_cam(t_cam *cam, int file)
{
	if (file == 0)
	{
		cam->campos = init_vect(0, 0, -80);
		cam->camdir = init_vect(0, 0, 1);
	}
	cam->camup = init_vect(0, -1, 0);
	cam->camright = init_vect(1, 0, 0);
	cam->camdir = normalize_vect(cam->camdir);
	cam->camup = normalize_vect(cam->camup);
	cam->camright = normalize_vect(cam->camright);
}

void		init_light(t_light *light, int file)
{
	if (file == 0)
	{
		light->ray.o = init_vect(0, 0, 0);
	}
	light->color = init_color(255, 255, 255, 40);
}
