#include "../includes/rtv1.h"

int		intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double shadowlengh, int i)
{
	double t;
	t_vect x = minus_vect(ray->o, cylinder->c);
	double a = dot(ray->d,ray->d) - pow(dot(ray->d, cylinder->v),2);
	double b = 2*(dot(ray->d, x) - dot(ray->d, cylinder->v)* dot(x, cylinder->v));
	double c = dot(x,x) - pow(dot(x,cylinder->v), 2) - pow(cylinder->r,2);
	cylinder->v = normalize_vect(cylinder->axe);
	if ((t = solveQuadratic(a, b, c, i)) > 0.0001)
	{
		if (i == 0 && (shadowlengh <= t))
				return (0);
		cylinder->t = t;
		cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
		cylinder->m = dot(ray->d, cylinder->v) * cylinder->t + dot(x,cylinder->v);
		cylinder->n = normalize_vect(multi_vect_double(minus_vect(minus_vect(cylinder->inter, cylinder->c),cylinder->v),cylinder->m));
		if (fmax(cylinder->m, 0) > 0)
			return (1);
	}
	return (0);}

int 	intersect_cone(t_ray *ray, t_cone *cone, double shadowlengh, int i)
{
	double t;
	cone->v = normalize_vect(cone->axe);
	t_vect x = minus_vect(ray->o, cone->c);
	double a = dot(ray->d,ray->d) - ((1+(cone->k*cone->k))*pow(dot(ray->d,cone->v),2));
	double b = 2*(dot(ray->d,x) - ((1+(cone->k*cone->k)) * (dot(ray->d,cone->v) * dot(x,cone->v))));
	double c = dot(x,x) - ((1+(cone->k*cone->k)) * pow(dot(x,cone->v),2));
	if ((t = solveQuadratic(a, b, c, i)) > 0.0001)
	{
		if (i == 0 && (shadowlengh <= t))
				return (0);
		cone->t = t;
		cone->inter = add_vect(ray->o, multi_vect_double(ray->d, cone->t));
		cone->m = dot(ray->d, cone->v) * cone->t + dot(x,cone->v);
		cone->n = normalize_vect(minus_vect(minus_vect(cone->inter,cone->c),multi_vect_double(cone->v, cone->m * pow(cone->k,2))));
		if (fmax(cone->m,0) > 0)
			return (1);
	}
	return (0);
}

int 	intersect_plane(t_ray *ray, t_plane *plane, double shadowlengh, int i)
{
	t_vect		L;
	double 		a;
	double 		t;
	t_vect 		inter;

	plane->n = normalize_vect(plane->d);
	a = dot(ray->d, plane->n);
	L = minus_vect(ray->o, plane->o);
	if (a > 0) //paralle
	{
		double b = dot(L, plane->n);
		if (a != b) // behind
		{
			t = dot(negative_vect(L), plane->n) / a;
			if (i == 0 && (shadowlengh < t))
				return (0);
			inter = add_vect(ray->o, multi_vect_double(ray->d, t));
			if (i == 1)
				plane->inter = inter;
			return (1);
		}
	}
	return (0);
}

int 	intersect_disc(t_ray *ray, t_disc *disc, double shadowlengh, int i)
{
	t_vect		L;
	double 		a;
	double 		t;
	t_vect 		inter;
	t_vect 		v;

	disc->n = normalize_vect(disc->d);
	a = dot(ray->d, disc->n);
	L = minus_vect(ray->o, disc->o);
	if (a > 0)
	{
		double b = dot(L, disc->n);
		if (a != b)
		{
			t = dot(negative_vect(L), disc->n) / a;
			if (i == 0 && (shadowlengh < t))
				return (0);
			inter = add_vect(ray->o, multi_vect_double(ray->d, t));
			v = minus_vect(disc->inter, disc->o);
			if (i == 1)
				disc->inter = inter;
			if (sqrt(dot(v,v)) <= 50)
				return (1);
		}
	}
	return (0);
}

int		intersect_sphere(t_ray *ray, t_sphere *sphere, double shadowlengh, int i)
{
	t_vect		L;
	double 		a;
	double 		b;
	double 		c;
	double 		t;
	t_vect		inter;

	L = minus_vect(ray->o, sphere->c);
	a = dot(ray->d,ray->d);
	b = dot(ray->d, L) *2;
	c = dot(L, L) - pow(sphere->r, 2);
	if ((t = solveQuadratic(a, b, c, i)) > 0.0001)
	{
		if ((i == 0) && (shadowlengh < t))
			return (0);
		inter = add_vect(ray->o, multi_vect_double(ray->d, t));
		if (i == 1)
			sphere->inter = inter;
		return (1);
	}
	return (0);
}