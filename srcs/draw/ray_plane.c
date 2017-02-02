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
	t_color		ambiant;
	t_vect		light_dir;
	double 		diff;
	t_vect 		n;
	t_vect 		h;

	light_c = init_color(255,255,255,40);
	ambiant = init_color(70,22,22,40);

	light_dir = negative_vect(normalize_vect(minus_vect(inter, sphere_light.c)));
	n = minus_vect(inter, all.sphere.c);
	diff = fmax(dot(normalize_vect(n),normalize_vect(sphere_light.c)),0);
	h = normalize_vect(add_vect(light_dir,multi_vect_double(n, 2.0 * dot(light_dir, n))));
	double spect = (diff > 0 ? pow(dot(h, negative_vect(light_dir)),30) : 0);
	spect = (spect > 0 ? spect : 0);
	spect_color = multi_color_double(multi_color(light_c, light_c), spect);
	diff_color =  multi_color_double(multi_color(objct_color, light_c), diff);
	
	final_color = add_color(spect_color, diff_color);
	final_color =  multi_color_double(final_color, 0.0038);
	final_color = add_color(final_color, ambiant);
	color_condition(&final_color);
	return (final_color);
}

t_color color_phong(t_color objct_color, t_vect inter, t_sphere sphere_light, t_all all)
{
	t_color		light_c;
	t_color		final_color;
	t_color		diff_color;
	t_color		spect_color;
	t_color		ambiant;
	// double 		diff;
	t_vect		n;
	t_vect		light_dir;

	light_c = init_color(255,255,255,40);
	ambiant = init_color(0,0,70,40);
	
	n = normalize_vect(all.ray.d); //ou direction de la camera
	light_dir = normalize_vect(minus_vect(inter, sphere_light.c));
	t_vect L = minus_vect(inter, sphere_light.c);
	double dist = fmax(lengh(L), 0);
	double dgr = dist /5;

	t_vect T = add_vect(all.ray.d,multi_vect_double(all.plane.n,dot(negative_vect(all.ray.d), all.plane.n)));
	t_vect Tn = normalize_vect(add_vect(all.ray.d,multi_vect_double(all.plane.n,dot(negative_vect(all.ray.d), all.plane.n))));
	T = devide_vect(T,Tn);
	// diff = sqrt(1- pow(dot(L,T),2));
	// if (diff < 0)
		// return (ambiant);
	

	// diff = fmax(dot(normalize_vect(n),normalize_vect(sphere_light.c)),0);
	// t_vect h = add_vect(negative_vect(normalize_vect(all.ray.d)),light_dir);
	// double anglespect = fmax((dot(normalize_vect(h), normalize_vect(n))), 0);
	// diff = fmax(dot(normalize_vect(L),normalize_vect(sphere_light.c)),0);

	// double spect = pow(dot(normalize_vect(L), normalize_vect(all.plane.n)),3);
	spect_color = devide_color_double(multi_color(light_c, light_c), dgr);
	diff_color =  devide_color_double(multi_color(objct_color, light_c), dgr);
	//diff_color =  multi_color_double(diff_color, 0.004);
	// spect_color =  multi_color_double(spect_color, 0.0039);
	//color_condition(&diff_color);
	//color_max(&diff_color);
	//color_condition(&spect_color);
	// printf("red = %f             green = %f           bleue = %f \n", diff_color.r, diff_color.g,diff_color.b);

	final_color = add_color(spect_color, diff_color);
	final_color =  multi_color_double(final_color, 0.0038);
	final_color = add_color(final_color, ambiant);
	color_condition(&final_color);
	return (final_color);

	// t_color		light_c;
	// t_color		final_color;
	// t_color		diff_color;
	// t_color		spect_color;
	// t_color		ambiant;
	// double 		diff;
	// t_vect		n;
	// t_vect		light_dir;

	// light_c = init_color(255,255,255,40);
	// ambiant = init_color(0,0,30,40);
	
	// n = normalize_vect(all.ray.d); //ou direction de la camera
	// light_dir = normalize_vect(minus_vect(inter, sphere_light.c));
	// diff = fmax(dot(light_dir,n), 0);
	// // if (diff < 0)
	// 	// return (ambiant);
	

	// // diff = fmax(dot(normalize_vect(n),normalize_vect(sphere_light.c)),0);
	// t_vect h = add_vect(negative_vect(normalize_vect(all.ray.d)),light_dir);
	// double anglespect = fmax((dot(normalize_vect(h), normalize_vect(n))), 0);
	// double spect = pow(anglespect, 30);
	// spect_color = multi_color_double(multi_color(light_c, light_c), spect);
	// diff_color =  multi_color_double(multi_color(objct_color, light_c), diff);
	// // diff_color =  multi_color_double(diff_color, 0.003);
	// // spect_color =  multi_color_double(spect_color, 0.0039);
	// //color_condition(&diff_color);
	// //color_max(&diff_color);
	// //color_condition(&spect_color);
	// //printf("%f\n", pow((dot(normalize_vect(h), normalize_vect(inter))),1));

	// final_color = add_color(spect_color, diff_color);
	// final_color =  multi_color_double(final_color, 0.0038);
	// final_color = add_color(final_color, ambiant);
	// color_condition(&final_color);
	// return (final_color);
}

int 	intersect_plane(t_ray *ray, t_plane *plane)
{
	t_vect		L;
	double 		a;
	double 		t;

	a = dot(ray->d, plane->n);
	L = minus_vect(ray->o, plane->o);
	if (a != 0) //paralle
	{
		double b = dot(L, plane->n);
		if (a != b) // behind
		{
			t = dot(negative_vect(L), plane->n) / a;
			plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
		}
	}
	return (0);









	// double 		a;
	// double 		t;
	// t_vect 		v;
	// double 		d2;
	// a = dot(ray->d, plane->n); // calcule angle of the vect
	// if (a != 0) // plane parallel to the ray no intersection
	// {
	// //sratchc++ vide
	// //t = (((plane->p1.x * plane->n.x +plane->p1.y * plane->n.y +plane->p1.z * plane->n.z) -(plane->n.x * ray->o.x) -(plane->n.y * ray->o.y) -(plane->n.z * ray->o.z)) / a);
	// // myself
	// //t = (((neg_dot(plane->d,ray->o) + dot(plane->o, plane->d))* plane->di)/a); // problem hereeeee ,<<<<<<<<<<<<<<<<<
	// //scratchapixel wedsite
	// 	t  = dot(minus_vect(normalize_vect(plane->o),ray->o), plane->n)/a;
	// 	if (t >= 0)
	// 	{
	// //plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
	// 		plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
	// 		v = minus_vect(plane->inter, plane->o);
	// 		d2 = dot(v,v);
	// 		if (sqrt(d2) <= 50)
	// 			return (1);
	// 	}

	// }
	// return (0);
}

int		intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	// algo Real-Time Collision Detection, Volume 1

	t_vect 		m = minus_vect(ray->o, cylinder->p1);
	t_vect 		n = minus_vect(ray->d, ray->o);
	t_vect 		d = minus_vect(cylinder->p2, cylinder->p1);
	double 		a = (dot(d,d)*dot(n,n))-(pow(dot(n,d),2));
	double 		b = (dot(d,d)*dot(m,n))-(dot(n,d)*dot(m,d));
	double 		c = (dot(d,d)*(dot(m,m)-pow(cylinder->r,2)))- dot(m,d);
	if (solveQuadratic(a, b, c))
	{
		cylinder->t = solveQuadratic(a, b, c);
		cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
		return (1);
	}
	return (0);

	// algo shading toy
	// t_vect		L;
	// t_vect		center_p1;
	// double 		height;	
	// double 		a;
	// double 		b;
	// double 		c;

	// cylinder->c = multi_vect_double(add_vect(cylinder->p1, cylinder->p2), 0.5);
	// height = lengh(minus_vect(cylinder->p2,cylinder->p1));
	// center_p1 = devide_vect_double(minus_vect(cylinder->p2,cylinder->p1), height);

	// L = minus_vect(ray->o, cylinder->c);
	// double card = dot(center_p1,ray->d);
	// double caoc = dot(center_p1, ray->o);

	// a = 1 - pow(card, 2);
	// b = dot(L, ray->d) - caoc * card;
	// c = dot(L, L) - pow(caoc,2) - pow(cylinder->r,2);
	// double h = b*b - a*c;
	//  if( h < 0 ) 
	//  	return (0);
	// else if (h > 0)  // ray->is tangent to sphere
	// {
	// 	h = sqrt(h);
	// 	cylinder->t0 = ((-b + h)/(a));
	// 	cylinder->t1 = ((-b - h)/(a));
	// 	cylinder->t = (cylinder->t0 < cylinder->t1) ? cylinder->t0 : cylinder->t1;
	// }
    // double y = caoc + cylinder->t1*card;

    // body
    //if( abs(y)<ch ) return vec4( t1, normalize( oc+t1*rd - ca*y ) );
    
    // caps
    // float sy = sign(y);
    // float tp = (sy*ch - caoc)/card;
    //if( tp>t1 && tp<t2 )
    // if( abs(b+a*tp)<h )
    // {
    //     return vec4( tp, ca*sy );
    // }

    // return vec4(-1.0);
    // mysellf
	// if (solveQuadratic(a, b, c))
	// {
	// 	cylinder->t = solveQuadratic(a, b, c);
	// 	cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
	// 	return (1);
	// }
	return (0);

	// algo http://www.freesteel.co.uk/wpblog/2012/10/31/line-intersecting-a-finite-cylinder/

	// t_vect v = minus_vect(cylinder->p2,cylinder->p1);
	// double vsq = dot(v, v)

	// algo mathworks
	// t_vect e = minus_vect(ray->d, multi_vect_double(cylinder->p2,(dot(ray->d, cylinder->p2) / dot(cylinder->p2, cylinder->p2))));
	// t_vect f = minus_vect(minus_vect(ray->o,cylinder->p1), multi_vect_double(cylinder->p2,(dot(ray->o, cylinder->p1) / dot(cylinder->p2, cylinder->p2))));
	// double a = dot(e, e);
	// double b = 2 * dot(e,f);
	// double c = dot(f,f) - pow(cylinder->r,2);
	// if (solveQuadratic(a, b, c))
	// {
	// 	printf("dfsfds");
	// 	cylinder->t = solveQuadratic(a, b, c);
	// 	cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
	// 	return (1);
	// }
	// return (0);
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

void		draw(t_all *all, t_sdl *sdl)
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
	color_background = init_color(255, 255, 255, 40);
	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			compute_ray(cam,&all->ray,x,y);
			if (intersect_sphere(&all->ray, &all->sphere))
			{
				color = sphere_color_phong(all->sphere.color_sphere, all->sphere.inter, all->sphere_light, *all);
				SDL_SetRenderDrawColor(sdl->ren, color.r, color.g, color.b, color.a);
			}
			else if (intersect_plane(&all->ray, &all->plane))
			{
				color = color_phong(all->plane.color_plane, all->plane.inter, all->sphere_light, *all);
				//color = all->plane.color_plane;
				SDL_SetRenderDrawColor(sdl->ren, color.r, color.g, color.b, color.a);
			}
			// if (intersect_cylinder(&all->ray, &all->cylinder))
			// {
			// 	//color = color_phong(all->cylinder.color_cylind, all->cylinder.inter, all->sphere_light, *all);
			// 	color = all->cylinder.color_cylind;
			// 	SDL_SetRenderDrawColor(sdl->ren, color.r, color.g, color.b, color.a);
			// }
			// envoyer ray par chaque pixel
			else
				SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 40);
			SDL_RenderDrawPoint(sdl->ren, x, y);
		}
	}
	SDL_RenderPresent(sdl->ren);
}