/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:03:37 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 17:12:53 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_color		color_phong(t_color objct_color, t_light light, t_vect n, t_ray ray)
{
	t_phong		phong;
	double		diff;
	t_vect		h;

	phong.ambiant = init_color(10, 10, 20, 40);
	diff = fmax(dot(n, light.dir), 0);
	h = normalize_vect(minus_vect(ray.d, light.dir));
	phong.spect = multi_color_double(multi_color(light.color, light.color),\
										(diff > 0 ? pow(dot(h, n), 30) : 0));
	phong.diff = multi_color_double(multi_color(objct_color, light.color),\
											diff);
	phong.final = add_color(phong.spect, phong.diff);
	phong.final = multi_color_double(phong.diff, 0.0038);
	phong.final = add_color(phong.final, phong.ambiant);
	color_condition(&phong.final);
	return (phong.final);
}

int			shadow(t_vect inter, t_ray light, t_obj obj)
{
	t_ray	shadow;
	double	r2;

	shadow.o = inter;
	shadow.d = minus_vect(light.o, shadow.o);
	r2 = sqrt(dot(shadow.d, shadow.d));
	shadow.d = normalize_vect(shadow.d);
	if (intersect_sphere(&shadow, &obj.sphere, r2, 0) || \
		intersect_plane(&shadow, &obj.plane, r2, 0) || \
		intersect_cylinder(&shadow, &obj.cylinder, r2, 0) || \
		intersect_cone(&shadow, &obj.cone, r2, 0) || \
		intersect_disc(&shadow, &obj.cylinder.disc, r2, 0) || \
		intersect_disc(&shadow, &obj.cylinder.disc2, r2, 0) || \
		intersect_sphere(&shadow, &obj.sphere, r2, 2) || \
		intersect_plane(&shadow, &obj.plane, r2, 2) || \
		intersect_cylinder(&shadow, &obj.cylinder, r2, 2) || \
		intersect_cone(&shadow, &obj.cone, r2, 2) || \
		intersect_disc(&shadow, &obj.cylinder.disc, r2, 2) || \
		intersect_disc(&shadow, &obj.cylinder.disc2, r2, 2))
		return (1);
	else
		return (0);
}
