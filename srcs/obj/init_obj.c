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
	sphere_light->r = 1;
}

void		init_sphere(t_sphere *sphere)
{
	sphere->c.x = WIN_X/2;
	sphere->c.y = WIN_Y/2;
	sphere->c.z = 50;

	sphere->r = 50;
}