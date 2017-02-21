#include "../includes/rtv1.h"

void		init_sceen(t_all *all)
{
	init_cam(&all->cam);
	init_cylinder(&all->obj.cylinder);
	init_light(&all->light);
	init_plane(&all->obj.plane);
	init_sphere(&all->obj.sphere);
	init_cone(&all->obj.cone);
	all->chg++;
}

void		init_cam(t_cam *cam)
{
	cam->campos = init_vect( 0,0, -80);
	cam->camdir = init_vect(0,0,1);
	cam->camup = init_vect(0,-1,0);
	cam->camright = init_vect(1,0,0);
	cam->camdir = normalize_vect(cam->camdir);
	cam->camup = normalize_vect(cam->camup);
	cam->camright = normalize_vect(cam->camright);
}

void		compute_ray(t_cam cam, t_ray *ray, int x, int y)
{
	double 	screen_pix_x;
	double 	screen_pix_y;

	t_vect 	image_point;
	double 	img_p_x;
	double 	img_p_y;
	double 	img_p_z;

	screen_pix_x = ((double)x / WIN_X) - 0.5;
  	screen_pix_y = ((double)y / WIN_Y) - 0.5;

	img_p_x = (screen_pix_x * cam.camright.x) + (screen_pix_y * cam.camup.x) + (cam.campos.x + cam.camdir.x);
	img_p_y = (screen_pix_x * cam.camright.y) + (screen_pix_y * cam.camup.y) + (cam.campos.y + cam.camdir.y);
	img_p_z = (screen_pix_x * cam.camright.z) + (screen_pix_y * cam.camup.z) + (cam.campos.z + cam.camdir.z);
	image_point = init_vect(img_p_x, img_p_y, img_p_z);

	ray->o = cam.campos;
	ray->d = minus_vect(image_point, cam.campos);
}

void		init_light(t_light *light)
{
	light->ray.o = init_vect(0, 0, 0);
	light->color = init_color(255,255,255,40);
}

void		init_sphere(t_sphere *sphere)
{
	sphere->c = init_vect(0, 10, 40);

	sphere->r = 10;
	sphere->color = init_color(255, 0, 0, 40);
}

t_disc	init_disc(t_vect o, t_vect n, double r, t_color color)
{
	t_disc tmp;

	tmp.o = o;
	tmp.d = n;
	tmp.r = r;
	tmp.color = color;
	return (tmp);
}

void		init_cylinder(t_cylinder *cylinder)
{
	cylinder->c = init_vect(0, -10, -30); // extramité 1
	cylinder->end = init_vect(40, 10, 30); 
	cylinder->v = minus_vect(cylinder->end, cylinder->c);
	cylinder->h = sqrt(dot(cylinder->v, cylinder->v));
	cylinder->r = 10; // rayon du disc
	cylinder->v = normalize_vect(cylinder->v);
	cylinder->disc = init_disc(cylinder->c, minus_vect(cylinder->end, cylinder->c), cylinder->r+0.1, cylinder->color);
	cylinder->disc2 = init_disc(cylinder->end, negative_vect(cylinder->v), cylinder->r+0.07, cylinder->color);
	cylinder->color = init_color(0, 0, 255, 40);
	
}

void		init_cone(t_cone *cone)
{
	cone->c = init_vect(-40, 30, 30); // extramité 1
	cone->axe = init_vect(0, -1, 0);

	cone->k = 0.5;
	cone->r = 10; // rayon du disc
	cone->color = init_color(200, 40, 40, 40);

}

void		init_plane(t_plane *plane)
{
	plane->d =init_vect(0, -5, 1);
	plane->o = init_vect(0, -10, 30);
	plane->color = init_color(0, 255, 0, 40);
}
