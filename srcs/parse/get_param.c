/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:04:43 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 18:26:08 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_cam		get_cam_param(char *line)
{
	t_cam		cam;

	if (ft_strtrue(line, "<camera", 0) == 1 &&\
			ft_strtrue(line, "position=", 0) == 1 &&\
			ft_strtrue(line, "direction=", 0) == 1)
	{
		cam.campos = take_vect(line, ft_strcoord(line, "position=", 0));
		cam.camdir = take_vect(line, ft_strcoord(line, "direction=", 0));
		return (cam);
	}
	else
		ft_exit(line);
	exit(-1);
}

t_sphere	get_sphere_param(char *line)
{
	t_sphere	sphere;

	if (ft_strtrue(line, "<sphere", 0) == 1 &&\
			ft_strtrue(line, "position=", 0) == 1 &&\
			ft_strtrue(line, "radius=", 0) == 1 &&\
			ft_strtrue(line, "color=", 0) == 1)
	{
		sphere.c = take_vect(line, ft_strcoord(line, "position=", 0));
		sphere.r = take_double(line, ft_strcoord(line, "radius=", 0));
		sphere.color = take_color(line, ft_strcoord(line, "color=", 0));
		return (sphere);
	}
	else
		ft_exit(line);
	exit(-1);
}

t_plane		get_plane_param(char *line)
{
	t_plane		plane;

	if (ft_strtrue(line, "<plane", 0) == 1 && \
			ft_strtrue(line, "position=", 0) == 1 && \
			ft_strtrue(line, "normal=", 0) == 1 && \
			ft_strtrue(line, "color=", 0) == 1)
	{
		plane.o = take_vect(line, ft_strcoord(line, "position=", 0));
		plane.d = take_vect(line, ft_strcoord(line, "normal=", 0));
		plane.color = take_color(line, ft_strcoord(line, "color=", 0));
		return (plane);
	}
	else
		ft_exit(line);
	exit(-1);
}

t_vect		get_light(char *line)
{
	t_vect		pos;

	if (ft_strtrue(line, "<light", 0) == 1 && \
			ft_strtrue(line, "position=", 0) == 1)
	{
		pos = take_vect(line, ft_strcoord(line, "position=", 0));
		return (pos);
	}
	else
		ft_exit(line);
	exit(-1);
}
