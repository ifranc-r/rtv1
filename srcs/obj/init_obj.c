#include "../includes/rtv1.h"



void		init_ray(t_ray *ray, int x, int y)
{
	ray->o.x = (double)x;
	ray->o.y = (double)y;
	ray->o.z = 0;

	ray->d.x = 0;
	ray->d.y = 0;
	ray->d.z = 1;
}

void		init_sphere_light(t_sphere *sphere_light)
{
	sphere_light->c.x = 0;
	sphere_light->c.y = 0;
	sphere_light->c.z = 0;
	sphere_light->r = 0;
}

void		init_sphere(t_sphere *sphere)
{
	sphere->c.x = WIN_X/2;
	sphere->c.y = WIN_Y/2;
	sphere->c.z = 50;

	sphere->r = 50;
	init_color_sphere(&sphere->color_sphere);
}

void		init_plane(t_plane *plane)
{
	plane->n.x = 0;
	plane->n.y = 0;
	plane->n.z = 2;

	plane->p1.x = WIN_X;
	plane->p1.y = WIN_Y;
	plane->p1.z = 50;

	plane->p2.x = WIN_X;
	plane->p2.y = WIN_Y;
	plane->p2.z = 50;

	plane->p3.x = WIN_X;
	plane->p3.y = 0;
	plane->p3.z = 50;

	plane->p4.x = 0;
	plane->p4.y = WIN_X;
	plane->p4.z = 50;

	init_color_plane(&plane->color_plane);
}