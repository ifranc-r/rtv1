#include "../includes/rtv1.h"

// pseudo algo de degrader

// find point dot = 0 (angle droit)

// t_vect		find_brigter_point(t_vect inter, t_vect light)
// {
// 	t_vect l = l.c-inter;
// 	double nl = normalize_vect(l);
// 	double n = normalize_vect(inter);
// 	if (dot(nl,n)== 0){
// 		t_vect brighter_pixel = inter;
// 		return (brighter_pixel);
// 	}
// 	else 
// 		return (0)
// }

// t_vect		degrader()
// {

// }


 // pseudo algo de phong

t_color sphere_color_phong(t_color objct_color, t_vect inter, t_sphere sphere_light, t_all all)
{
	t_color		light_c;
	t_color		final_color;
	t_color		diff_color;
	t_color		spect_color;
	double 		diff;
	t_vect 		n;
	t_vect 		h;

	light_c = init_color(255,255,255,40);

	n = minus_vect(inter, all.sphere.c);
	diff = fmax(dot(normalize_vect(n),normalize_vect(sphere_light.c)),0);

	h = add_vect(negative_vect(normalize_vect(all.ray.d)),normalize_vect(sphere_light.c));

	spect_color = multi_color_double(multi_color(light_c, light_c), pow(dot(normalize_vect(h), normalize_vect(n)),30));

	diff_color =  multi_color_double(multi_color(objct_color, light_c), diff);
	final_color = add_color(spect_color, diff_color);
	final_color =  multi_color_double(final_color, 0.0038);
	color_condition(&final_color);
	return (final_color);
}

t_color color_phong(t_color objct_color, t_vect inter, t_sphere sphere_light, t_all all)
{
	t_color		light_c;
	t_color		final_color;
	t_color		diff_color;
	t_color		spect_color;
	double 		diff;
	t_vect 		h;

	light_c = init_color(255,255,255,40);

	diff = fmax(dot(normalize_vect(inter),normalize_vect(sphere_light.c)),0);
	h = add_vect(negative_vect(normalize_vect(all.ray.d)),normalize_vect(sphere_light.c));
	spect_color = multi_color_double(multi_color(light_c, light_c), pow((dot(normalize_vect(h), normalize_vect(inter))), 1));
	diff_color =  multi_color_double(multi_color(objct_color, light_c), diff);
	//diff_color =  multi_color_double(diff_color, 0.003);
	//spect_color =  multi_color_double(spect_color, 0.0039);
	//color_condition(&diff_color);
	//color_max(&diff_color);
	//color_condition(&spect_color);
	//printf("%f\n", pow((dot(normalize_vect(h), normalize_vect(inter))),1));

	final_color = add_color(spect_color, diff_color);
	final_color =  multi_color_double(final_color, 0.0038);
	color_condition(&final_color);
	return (final_color);
}

int 	intersect_plane(t_ray *ray, t_plane *plane)
{
	double 		a;
	double 		t;


	a = dot(ray->d, normalize_vect(plane->d)); // calcule angle of the vect
	if (a == 0) // plane parallel to the ray no intersection
		return (0);
	//sratchc++ vide
	//t = (((plane->p1.x * plane->n.x +plane->p1.y * plane->n.y +plane->p1.z * plane->n.z) -(plane->n.x * ray->o.x) -(plane->n.y * ray->o.y) -(plane->n.z * ray->o.z)) / a);
	// myself
	//t = (((neg_dot(plane->d,ray->o) + dot(plane->o, plane->d))* plane->di)/a); // problem hereeeee ,<<<<<<<<<<<<<<<<<
	//scratchapixel wedsite
	t  = dot(minus_vect(plane->o,ray->o), normalize_vect(plane->d))/a;
	if (t < 0)
		return (0);
	//plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
	plane->inter.x = ray->o.x + (ray->d.x * t);
	plane->inter.y = ray->o.y + (ray->d.y * t);
	plane->inter.z = ray->o.z + (ray->d.z * t);
	return (1);
}

int		intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	// algo shading toy
	// t_vect		L;
	// t_vect		center_p1;
	// double 		height;	
	// double 		a;
	// double 		b;
	// double 		c;

	// cylinder->c = multi_vect_double(add_vect(cylinder->p1, ray->o), 0.5);
	// height = lengh(minus_vect(cylinder->p2,cylinder->p1));
	// center_p1 = devide_vect_double(minus_vect(cylinder->p2,cylinder->p1), height);

	// L = minus_vect(ray->o, cylinder->c);
	// double card = dot(center_p1,ray->d);
	// double caoc = dot(center_p1, ray->o);

	// a = pow(card, 2) - 1 ;
	// b = dot(L, ray->d) - caoc * card;
	// c = dot(L, L) - pow(caoc,2) - pow(cylinder->r,2);
	// if (solveQuadratic(a, b, c))
	// {
	// 	cylinder->t = solveQuadratic(a, b, c);
	// 	cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
	// 	return (1);
	// }
	// return (0);

	// algo http://www.freesteel.co.uk/wpblog/2012/10/31/line-intersecting-a-finite-cylinder/

	// t_vect v = minus_vect(cylinder->p2,cylinder->p1);
	// double vsq = dot(v, v)

	// algo mathworks
	t_vect e = minus_vect(ray->d, multi_vect_double(cylinder->p2,(dot(ray->d, cylinder->p2) / dot(cylinder->p2, cylinder->p2))));
	t_vect f = minus_vect(minus_vect(ray->o,cylinder->p1), multi_vect_double(cylinder->p2,(dot(ray->o, cylinder->p1) / dot(cylinder->p2, cylinder->p2))));
	double a = dot(e, e);
	double b = 2 * dot(e,f);
	double c = dot(f,f) - pow(cylinder->r,2);
	if (solveQuadratic(a, b, c))
	{
		printf("dfsfds");
		cylinder->t = solveQuadratic(a, b, c);
		cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
		return (1);
	}
	return (0);
}

int		intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vect		L;
	double 		a;
	double 		b;
	double 		c;

	L = minus_vect(ray->o, sphere->c);
	a = dot(ray->d,ray->d);
	b = 2 * dot(ray->d, L);
	c = dot(L, L) - pow(sphere->r, 2);
	if (solveQuadratic(a, b, c))
	{
		sphere->t = solveQuadratic(a, b, c);
		sphere->inter = add_vect(ray->o, multi_vect_double(ray->d, sphere->t));
		return (1);
	}
	return (0);
}

void		draw(t_all *all)
{
	int 		x;
	int			y;
	t_color		color;
	t_color		color_background;
	t_cam 		cam;
	t_axe		axe;
	// bymyself

	//t_vect		look_at; //option = point where the camera is look_at center instead of giving a directio axe
	//init_vect(&look_at, 0, 0, 0);
	init_cam(&cam);
	init_axe(&axe);
	cam.camdir = normalize_vect(cam.camdir);
	cam.camup = normalize_vect(cam.camup);
	cam.camright = normalize_vect(cam.camright);

	// video scratch c++
	// t_axe		axe;
	// t_cam 		cam;
	// t_vect		look_at;
	// t_vect		diff_btw;

	// init_vect(&look_at, 0, 0, 0);
	// init_cam(&cam);
	// init_axe(&axe);
	// init_vect(&diff_btw, cam.campos.x - look_at.x, cam.campos.y - look_at.y, cam.campos.z - look_at.z);
	// cam.camdir = normalize_vect(negative_vect(diff_btw));
	// cam.camright = normalize_vect(cross_prod(axe.y, cam.camdir));
	// cam.camdown = cross_prod(cam.camright, cam.camdir); 
	init_cylinder(&all->cylinder);
	init_sphere_light(&all->sphere_light);
	init_plane(&all->plane);
	init_color_background(&color_background);
	init_sphere(&all->sphere);
	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			compute_ray(cam,&all->ray,x,y);
			// if (intersect_sphere(&all->ray, &all->sphere))
			// {
			// 	color = sphere_color_phong(all->sphere.color_sphere, all->sphere.inter, all->sphere_light, *all);
			// 	SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			// }
			// else if (intersect_plane(&all->ray, &all->plane))
			// {
			// 	color = color_phong(all->plane.color_plane, all->plane.inter, all->sphere_light, *all);
			// 	SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			// }
			if (intersect_cylinder(&all->ray, &all->cylinder))
			{
				//color = color_phong(all->cylinder.color_cylind, all->cylinder.inter, all->sphere_light, *all);
				color = all->cylinder.color_cylind;
				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			}
			// envoyer ray par chaque pixel
			else
				SDL_SetRenderDrawColor(all->ren, 0, 0, 0, 40);
			SDL_RenderDrawPoint(all->ren, x, y);
		}
	}
	SDL_RenderPresent(all->ren);
}