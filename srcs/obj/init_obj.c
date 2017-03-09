#include "../includes/rtv1.h"

t_disc	init_disc(t_vect o, t_vect n, double r, t_color color)
{
	t_disc tmp;

	tmp.o = o;
	tmp.d = n;
	tmp.r = r;
	tmp.color = color;
	return (tmp);
}

void		init_sphere(t_sphere *sphere)
{
	sphere->c = init_vect(0, 10, 40);
	sphere->r = 10;
	sphere->color = init_color(255, 0, 0, 40);
}

void		init_cylinder(t_cylinder *cylinder, int file)
{
	if (file == 0)
	{
		cylinder->c = init_vect(0, -10, -30);
		cylinder->end = init_vect(40, 10, 30); 
		cylinder->r = 10;
		cylinder->color = init_color(0, 0, 255, 40);
	}
	cylinder->v = minus_vect(cylinder->end, cylinder->c);
	cylinder->h = sqrt(dot(cylinder->v, cylinder->v));
	cylinder->v = normalize_vect(cylinder->v);
	cylinder->disc = init_disc(cylinder->c, \
								minus_vect(cylinder->end, \
								cylinder->c), \
								cylinder->r+0.1, \
								cylinder->color);
	cylinder->disc2 = init_disc(cylinder->end, \
								negative_vect(cylinder->v),\
								cylinder->r+0.07, \
								cylinder->color);
}

void		init_cone(t_cone *cone, int file)
{
	if (file == 0)
	{
		cone->c = init_vect(-40, 30, 30);
		cone->axe = init_vect(0, -1, 0);
		cone->color = init_color(200, 40, 40, 40);
		cone->r = 10;
	}
	cone->k = 0.5;
}

void		init_plane(t_plane *plane)
{
	plane->d = init_vect(0, -5, 1);
	plane->o = init_vect(0, -10, 30);
	plane->color = init_color(0, 255, 0, 40);
}
