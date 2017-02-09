#include "../includes/rtv1.h"

void		init_sceen(t_all *all)
{
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
}

void		init_axe(t_axe *axe)
{
	axe->x = init_vect(1,0,0);
	axe->y = init_vect(0,1,0);
	axe->z = init_vect(0,0,1);
}

t_vect		init_vect(double x, double y, double z)
{
	t_vect		tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
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
	
	//screen_pix_x = ((0.5 + (double)x) / WIN_X * (WIN_X/WIN_Y)) -(((WIN_X - WIN_Y)/WIN_Y)/2);
	//screen_pix_y = ((WIN_Y - (double)y) + 0.5)/WIN_Y;


	img_p_x = (screen_pix_x * cam.camright.x) + (screen_pix_y * cam.camup.x) + (cam.campos.x + cam.camdir.x);
	img_p_y = (screen_pix_x * cam.camright.y) + (screen_pix_y * cam.camup.y) + (cam.campos.y + cam.camdir.y);
	img_p_z = (screen_pix_x * cam.camright.z) + (screen_pix_y * cam.camup.z) + (cam.campos.z + cam.camdir.z);
	image_point = init_vect(img_p_x, img_p_y, img_p_z);

	ray->o = cam.campos;
	ray->d = minus_vect(image_point, cam.campos);
	//video scrach c++
	// double 		aspectratio;
	// t_vect 		cam_r;
	// t_vect 		cam_do;
	// double 		cam_pix_x;
	// double 		cam_pix_y;
	// double 		pix_x;
	// double 		pix_y;

	// pix_x = (double)x;
	// pix_y = (double)y;
	// aspectratio = WIN_X / WIN_Y;
	// cam_pix_x = ((0.5 + pix_x) / WIN_X * aspectratio) -(((WIN_X - WIN_Y)/WIN_Y)/2);
	// cam_pix_y = ((WIN_Y - pix_y) + 0.5)/WIN_Y;
	// cam_do = multi_vect_double(cam.camdown, (cam_pix_y - 0.5));
	// cam_r = multi_vect_double(cam.camright, (cam_pix_x - 0.5)) ;
	// init_vect(&ray->o,cam.campos.x,cam.campos.y,cam.campos.z);
	// ray->d =  normalize_vect(add_vect(cam.camdir, add_vect(cam_r, cam_do)));
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

void		init_cylinder(t_cylinder *cylinder)
{
	cylinder->c = init_vect(40, 30, 30); // extramité 1
	cylinder->axe = init_vect(0, -1, 0);
	cylinder->h = 40;
	cylinder->r = 10; // rayon du disc
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
