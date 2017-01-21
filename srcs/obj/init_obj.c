#include "../includes/rtv1.h"

void		init_cam(t_cam *cam)
{
	init_vect(&cam->campos,5,1.5,-4);
	init_vect(&cam->camdir,0,0,1);
	init_vect(&cam->camdown,0,0,0);
	init_vect(&cam->camright,0,0,0);
}

void		init_axe(t_axe *axe)
{
	init_vect(&axe->x,1,0,0);
	init_vect(&axe->y,0,1,0);
	init_vect(&axe->z,0,0,1);
}

void		init_vect(t_vect *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void		init_ray(t_cam cam, t_ray *ray, int x, int y)
{
	t_vect 		cam_r;
	t_vect 		cam_do;
	double 		xd;
	double 		yd;

	xd = (double)x;
	yd = (double)y;
	cam_do = multi_vect_double(cam.camdown, (yd - 0.5));
	cam_r = multi_vect_double(cam.camright, (xd - 0.5)) ;
	init_vect(&ray->o,cam.campos.x,cam.campos.y,cam.campos.z);
	ray->d =  normalize_vect(add_vect(cam.camdir, add_vect(cam_r, cam_do)));
}

void		init_sphere_light(t_sphere *sphere_light)
{
	sphere_light->c.x = WIN_X/2;
	sphere_light->c.y = 0;
	sphere_light->c.z = 0;
	sphere_light->r = 0;
}

void		init_sphere(t_sphere *sphere)
{
	sphere->c.x = WIN_X/2;
	sphere->c.y = WIN_Y/2;
	sphere->c.z = -50;

	sphere->r = 50;
	init_color_sphere(&sphere->color_sphere);
}

void		init_plane(t_plane *plane)
{
	plane->n.x = 0;
	plane->n.y = 0;
	plane->n.z = 0;

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