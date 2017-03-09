/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:05:04 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/09 17:05:06 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int 	ft_strcoord(char *str, char *src, int loop)
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
				return(ft_strcoord(str, src, i));
			break;
		}
		i++;
	}
	return (i);
}

t_obj		parse_map(int fd)
{
	int 		i = 0;
	char		*line = NULL;
	t_obj		obj;

	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
			obj.cam = get_cam_param(line);
		else if (i == 2)
			obj.light.ray.o = take_vect(line,ft_strcoord(line,"position=", 0));
		else if (i == 3)
			obj.sphere = get_sphere_param(line);
		else if (i == 4)
			obj.plane = get_plane_param(line);
		else if (i == 5)
			obj.cylinder = get_cylinder_param(line);
		else if (i == 6)
		 	obj.disc = get_disc_param(line);
		else if (i == 7)
			obj.cone = get_cone_param(line);
		++i;
	}
	return (obj);
}
