/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:04:10 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 18:11:27 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		intersect_disc(t_ray *ray, t_disc *disc, double shadowlengh, int i)
{
	t_vect		l;
	t_vect		v;
	double		t;

	disc->n = normalize_vect(disc->d);
	l = minus_vect(ray->o, disc->o);
	if (dot(ray->d, disc->n) > 0)
	{
		if (dot(ray->d, disc->n) != dot(l, disc->n))
		{
			t = dot(negative_vect(l), disc->n) / dot(ray->d, disc->n);
			if ((i == 0 || i == 2) && (shadowlengh > t))
				return (0);
			disc->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
			v = minus_vect(disc->inter, disc->o);
			if (sqrt(dot(v, v)) <= disc->r)
				return (1);
		}
	}
	return (0);
}

int		intersect_cylinder(t_ray *ray, t_cylinder *cylder, double shd, int p)
{
	double		t;
	t_inter		i;

	i.x = minus_vect(ray->o, cylder->c);
	i.a = dot(ray->d, ray->d) - pow(dot(ray->d, cylder->v), 2);
	i.b = 2 * (dot(ray->d, i.x) - dot(ray->d, cylder->v) * dot(i.x, cylder->v));
	i.c = dot(i.x, i.x) - pow(dot(i.x, cylder->v), 2) - pow(cylder->r, 2);
	if ((t = solvequadratic(i.a, i.b, i.c, p)) > 0.0001)
	{
		if ((p == 0 || p == 2) && (shd <= t))
			return (0);
		cylder->t = t;
		cylder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylder->t));
		cylder->m = dot(ray->d, cylder->v) * cylder->t + dot(i.x, cylder->v);
		cylder->n = normalize_vect(devide_vect_double(multi_vect_double(\
			minus_vect(minus_vect(cylder->inter, cylder->c),\
						cylder->v), cylder->m), 2));
		if (fmax(cylder->m, 0) > 0 && fmax(cylder->m, 0) < cylder->h)
			return (1);
	}
	return (0);
}

int		intersect_cone(t_ray *r, t_cone *c, double shadowlengh, int i)
{
	t_inter		p;

	c->v = normalize_vect(c->axe);
	p.x = minus_vect(r->o, c->c);
	p.a = dot(r->d, r->d) - ((1 + (c->k * c->k)) * \
			pow(dot(r->d, c->v), 2));
	p.b = 2 * (dot(r->d, p.x) - ((1 + (c->k * c->k)) * \
				(dot(r->d, c->v) * dot(p.x, c->v))));
	p.c = dot(p.x, p.x) - ((1 + (c->k * c->k)) * pow(dot(p.x, c->v), 2));
	if ((p.t = solvequadratic(p.a, p.b, p.c, i)) > 0.0001)
	{
		if ((i == 0 || i == 2) && (shadowlengh <= p.t))
			return (0);
		c->t = p.t;
		c->inter = add_vect(r->o, multi_vect_double(r->d, c->t));
		c->m = dot(r->d, c->v) * c->t + dot(p.x, c->v);
		c->n = normalize_vect(minus_vect(minus_vect(c->inter, c->c),\
					multi_vect_double(c->v, c->m * pow(c->k, 2))));
		if (fmax(c->m, 0) > 0 && fmax(c->m, 0) < 50)
			return (1);
	}
	return (0);
}

int		intersect_plane(t_ray *ray, t_plane *plane, double shadowlengh, int i)
{
	t_vect		l;
	double		a;
	double		t;

	plane->n = normalize_vect(plane->d);
	a = dot(ray->d, plane->n);
	l = minus_vect(ray->o, plane->o);
	if (a > 0)
	{
		if (a != dot(l, plane->n))
		{
			t = dot(negative_vect(l), plane->n) / a;
			if ((i == 0 || i == 2) && (shadowlengh < t))
				return (0);
			if (i == 1)
				plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
			return (1);
		}
	}
	return (0);
}

int		intersect_sphere(t_ray *ray, t_sphere *sphere, double shwle, int i)
{
	t_vect		l;
	double		a;
	double		b;
	double		c;
	double		t;

	l = minus_vect(ray->o, sphere->c);
	a = dot(ray->d, ray->d);
	b = dot(ray->d, l) * 2;
	c = dot(l, l) - pow(sphere->r, 2);
	if ((t = solvequadratic(a, b, c, i)) > 0.0001)
	{
		if ((i == 0 || i == 2) && (shwle < t))
			return (0);
		if (i == 1)
			sphere->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
		return (1);
	}
	return (0);
}
