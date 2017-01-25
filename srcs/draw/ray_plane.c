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
	h = add_vect(normalize_vect(all.ray.d),normalize_vect(sphere_light.c));
	spect_color = multi_color(light_c ,multi_color_double(light_c, pow(dot(normalize_vect(h), normalize_vect(n)), 4)));
	diff_color =  multi_color(light_c, multi_color_double(objct_color, diff));
	//color_condition(&diff_color);
	//color_condition(&spect_color);
	final_color = add_color(spect_color, objct_color);
	if (spect_color.r < 0 || spect_color.g < 0 || spect_color.b < 0)
		printf("r=%f\n g=%f\n  b=%f\n",spect_color.r,spect_color.g,spect_color.b);
	printf("r=%f\n g=%f\n  b=%f\n",diff_color.r,diff_color.g,diff_color.b);

	//color_condition(&final_color);
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
	h = add_vect(normalize_vect(all.ray.d),normalize_vect(sphere_light.c));
	spect_color = multi_color_double(light_c, pow((dot(normalize_vect(h), normalize_vect(inter))), 4));
	diff_color = multi_color(light_c, multi_color_double(objct_color, diff));
	//color_condition(&diff_color);
	//color_max(&diff_color);
	//color_max(&spect_color);
	//printf("%f\n", pow((dot(normalize_vect(h), normalize_vect(inter))),1));

	final_color = add_color(spect_color, objct_color);
	// color_condition(&final_color);
	return (final_color);
}

int 	intersect_plane(t_ray *ray, t_plane *plane)
{
	double 		a;
	double 		t;


	a = dot(ray->d, plane->d); // calcule angle of the vect
	if (a == 0) // plane parallel to the ray no intersection
		return (0);
	//sratchc++ vide
	//t = (((plane->p1.x * plane->n.x +plane->p1.y * plane->n.y +plane->p1.z * plane->n.z) -(plane->n.x * ray->o.x) -(plane->n.y * ray->o.y) -(plane->n.z * ray->o.z)) / a);
	// myself
	//t = (((neg_dot(plane->d,ray->o) + dot(plane->o, plane->d))* plane->di)/a); // problem hereeeee ,<<<<<<<<<<<<<<<<<
	//scratchapixel wedsite
	t  = dot(add_vect(plane->o,negative_vect(ray->o)), plane->d)/a;
	if (t < 0)
		return (0);
	//plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
	plane->inter.x = ray->o.x + (ray->d.x * t);
	plane->inter.y = ray->o.y + (ray->d.y * t);
	plane->inter.z = ray->o.z + (ray->d.z * t);
	return (1);
}

int		intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vect		L;
	double 		a;
	double 		b;
	double 		c;

	L = minus_vect(sphere->c, ray->o);
	a = dot(ray->d,ray->d);
	b = 2 * dot(ray->d, L);
	c = dot(L, L) - pow(sphere->r, 2);
	if (solveQuadratic(a, b, c, &*sphere) == 1)
	{
		sphere->inter = add_vect(ray->o, multi_vect_double(ray->d, sphere->t));
		return (1);
	}
	return (0);
}

void		draw(t_all *all)
{
	int 		x;
	int			y;
	t_vect		n;
	double		dt;
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
			if (intersect_sphere(&all->ray, &all->sphere))
			{
				//l = minus_vect(normalize_vect(all->sphere_light.c), normalize_vect(all->sphere.inter));
				//n = minus_vect(all->sphere.inter, all->sphere.c);
				//dt  = dot(normalize_vect(n), normalize_vect(all->sphere_light.c));

				// normal light
				//color = multi_color_double(color_background, dt*100);
				//color = add_color(all->sphere.color_sphere, color);
				//color = multi_color_double(color, 0.5);
				//color_condition(&color);

				// phong light
				color = sphere_color_phong(all->sphere.color_sphere, all->sphere.inter, all->sphere_light, *all);
				//color_condition(&color);

				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			}
			else if (intersect_plane(&all->ray, &all->plane))
			{
				// l = minus_vect(normalize_vect(all->sphere_light.c), normalize_vect(all->plane.inter));
				n  = minus_vect(all->plane.inter, all->sphere_light.c);
				dt  = dot(normalize_vect(n), normalize_vect(all->sphere_light.c));

					//basic algo
				//l = minus_vect(all->sphere_light.c, all->plane.inter);
				//n = minus_vect(all->plane.n, all->plane.inter);
				//dt  = dot(normalize_vect(n), normalize_vect(l));
				//printf("%f\n", dt);
				color = multi_color_double(all->plane.color_plane, dt*1000);
				color = multi_color_double(color_background, dt);
				color = add_color(all->plane.color_plane, color);
				color = multi_color_double(color, 0.5);
				//color = all->plane.color_plane;
				color = color_phong(all->plane.color_plane, all->plane.inter, all->sphere_light, *all);
				//color_condition(&color);
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