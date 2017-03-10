/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:03:10 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/10 20:49:36 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			get_close(t_ray *ray, t_vect inter)
{
	double		tmp_lengh;

	tmp_lengh = lengh(minus_vect(ray->o, inter));
	if (tmp_lengh < ray->lengh)
	{
		ray->lengh = tmp_lengh;
		return (1);
	}
	return (0);
}

int			get_close_inter(t_ray *ray, t_obj *obj)
{
	int			num_obj;

	ray->lengh = 999999.9;
	if (intersect_sphere(&*ray, &obj->sphere, 0, 1))
		get_close(&*ray, obj->sphere.inter) == 1 ? num_obj = 1 : 0;
	if (intersect_plane(&*ray, &obj->plane, 0, 1))
		get_close(&*ray, obj->plane.inter) == 1 ? num_obj = 2 : 0;
	if (intersect_cylinder(&*ray, &obj->cylinder, 0, 1))
		get_close(&*ray, obj->cylinder.inter) == 1 ? num_obj = 3 : 0;
	if (intersect_cone(&*ray, &obj->cone, 0, 1))
		get_close(&*ray, obj->cone.inter) == 1 ? num_obj = 4 : 0;
	if (intersect_disc(&*ray, &obj->cylinder.disc, 0, 1))
		get_close(&*ray, obj->cylinder.disc.inter) == 1 ? num_obj = 5 : 0;
	if (intersect_disc(&*ray, &obj->cylinder.disc2, 0, 1))
		get_close(&*ray, obj->cylinder.disc2.inter) == 1 ? num_obj = 6 : 0;
	return (num_obj);
}

t_vect		call_obj_n(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = normalize_vect(minus_vect(obj.sphere.inter, obj.sphere.c));
	if (num_obj == 2)
		tmp = negative_vect(obj.plane.n);
	if (num_obj == 3)
		tmp = obj.cylinder.n;
	if (num_obj == 4)
		tmp = (obj.cone.n);
	if (num_obj == 5)
		tmp = negative_vect(obj.cylinder.disc.n);
	if (num_obj == 6)
		tmp = negative_vect(obj.cylinder.disc2.n);
	return (tmp);
}

t_color		call_obj_color(t_obj obj, int num_obj)
{
	t_color		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.color);
	if (num_obj == 2)
		tmp = (obj.plane.color);
	if (num_obj == 3)
		tmp = (obj.cylinder.color);
	if (num_obj == 4)
		tmp = (obj.cone.color);
	if (num_obj == 5)
		tmp = (obj.cylinder.disc.color);
	if (num_obj == 6)
		tmp = (obj.cylinder.disc2.color);
	return (tmp);
}

t_vect		call_obj_inter(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.inter);
	if (num_obj == 2)
		tmp = (obj.plane.inter);
	if (num_obj == 3)
		tmp = (obj.cylinder.inter);
	if (num_obj == 4)
		tmp = (obj.cone.inter);
	if (num_obj == 5)
		tmp = (obj.cylinder.disc.inter);
	if (num_obj == 6)
		tmp = (obj.cylinder.disc2.inter);
	return (tmp);
}
