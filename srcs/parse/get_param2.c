/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:04:57 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 18:29:53 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_cylinder		get_cylinder_param(char *line)
{
	t_cylinder		cylinder;

	if (ft_strtrue(line, "<cylinder", 0) == 1 &&\
			ft_strtrue(line, "position=", 0) == 1 && \
		ft_strtrue(line, "endpos=", 0) == 1 && \
		ft_strtrue(line, "color=", 0) == 1 && \
		ft_strtrue(line, "radius=", 0) == 1)
	{
		cylinder.c = take_vect(line, ft_strcoord(line, "position=", 0));
		cylinder.end = take_vect(line, ft_strcoord(line, "endpos=", 0));
		cylinder.r = take_double(line, ft_strcoord(line, "radius=", 0));
		cylinder.color = take_color(line, ft_strcoord(line, "color=", 0));
		return (cylinder);
	}
	else
		ft_exit(line);
	exit(-1);
}

t_disc			get_disc_param(char *line)
{
	t_disc			disc;

	if (ft_strtrue(line, "<disk", 0) == 1 &&\
		ft_strtrue(line, "position=", 0) == 1 && \
		ft_strtrue(line, "normal=", 0) == 1 && \
		ft_strtrue(line, "color=", 0) == 1 && \
		ft_strtrue(line, "radius=", 0) == 1)
	{
		disc.o = take_vect(line, ft_strcoord(line, "position=", 0));
		disc.d = take_vect(line, ft_strcoord(line, "normal=", 0));
		disc.r = take_double(line, ft_strcoord(line, "radius=", 0));
		disc.color = take_color(line, ft_strcoord(line, "color=", 0));
		return (disc);
	}
	else
		ft_exit(line);
	exit(-1);
}

t_cone			get_cone_param(char *line)
{
	t_cone			cone;

	if (ft_strtrue(line, "<cone", 0) == 1 &&\
		ft_strtrue(line, "position=", 0) == 1 && \
		ft_strtrue(line, "normal=", 0) == 1 &&\
		ft_strtrue(line, "color=", 0) == 1 && \
		ft_strtrue(line, "radius=", 0) == 1)
	{
		cone.c = take_vect(line, ft_strcoord(line, "position=", 0));
		cone.axe = take_vect(line, ft_strcoord(line, "normal=", 0));
		cone.r = take_double(line, ft_strcoord(line, "radius=", 0));
		cone.color = take_color(line, ft_strcoord(line, "color=", 0));
		return (cone);
	}
	else
		ft_exit(line);
	exit(-1);
}
