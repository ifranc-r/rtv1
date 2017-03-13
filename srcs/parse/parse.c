/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:05:04 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 18:47:30 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int			ft_strcoord(char *str, char *src, int loop)
{
	int i;
	int a;

	a = 0;
	i = loop;
	while (str[i])
	{
		if (str[i] == src[a])
		{
			while (str[++i] == src[++a])
				;
			if (src[a] != '\0')
				return (ft_strcoord(str, src, i));
			break ;
		}
		i++;
	}
	return (i);
}

t_obj		parse_map(int fd, int i)
{
	t_fd	val;

	val.i = -1;
	while (++val.i != 8 && (val.oct = get_next_line(fd, &val.line)) > 0)
	{
		if (val.i == 1)
			val.obj.cam = get_cam_param(val.line);
		else if (val.i == 2)
			val.obj.light.ray.o = get_light(val.line);
		else if (val.i == 3)
			val.obj.sphere = get_sphere_param(val.line);
		else if (val.i == 4)
			val.obj.plane = get_plane_param(val.line);
		else if (val.i == 5)
			val.obj.cylinder = get_cylinder_param(val.line);
		else if (val.i == 6)
			val.obj.disc = get_disc_param(val.line);
		else if (val.i == 7)
			val.obj.cone = get_cone_param(val.line);
	}
	val.oct == -1 ? exit(-1) : 0;
	i == 1 ? menu() : exit(-1);
	return (val.obj);
}
