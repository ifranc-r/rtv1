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



t_color color_phong(t_color objct_color, t_light light, t_vect n,t_ray ray, t_vect inter)
{
	t_color		final_color;
	t_color		diff_color;
	t_color		spect_color;
	t_vect		light_dir;
	t_color		ambiant;
	double 		diff;
	t_vect 		h;

	ambiant = init_color(10,10,20,40);
	light_dir = negative_vect(normalize_vect(minus_vect(inter, light.ray.o)));
	diff = fmax(dot(n,light_dir),0);
	h = normalize_vect(minus_vect(ray.d,light_dir));
	spect_color = multi_color_double(multi_color(light.color, light.color), (diff > 0 ? pow(dot(h,n),30) : 0));
	diff_color =  multi_color_double(multi_color(objct_color, light.color), diff);
	
	final_color = add_color(spect_color, diff_color);
	final_color =  multi_color_double(final_color, 0.0038);
	final_color = add_color(final_color, ambiant);
	color_condition(&final_color);
	return (final_color);
}
	// Le mec
// 	t_color color_phong(t_color objct_color, t_sphere light, t_vect n,t_vect inter){
// 	t_color		light_c;
// 	t_color		final_color;
// 	t_color		diff_color;
// 	t_color		spect_color;
// 	t_color		ambiant;
// 	t_vect		light_dir;
// 	double 		diff;
// 	// t_vect 		n;
// 	t_vect 		h;

// 	light_c = init_color(255,255,255,40);
// 	ambiant = init_color(70,22,22,40);

// 	light_dir = negative_vect(normalize_vect(minus_vect(inter, light.c)));
// 	// n = normalize_vect(minus_vect(inter, all.sphere.c));
// 	diff = fmax(dot(n,normalize_vect(light.c)),0);
// 	h = normalize_vect(add_vect(negative_vect(light_dir),multi_vect_double(n, 2.0 * dot(light_dir, n))));
// 	double spect = (diff > 0 ? pow(dot(h, negative_vect(light_dir)),30) : 0);
// 	spect = (spect > 0 ? spect : 0);
// 	spect_color = multi_color_double(multi_color(light_c, light_c), spect);
// 	diff_color =  multi_color_double(multi_color(objct_color, light_c), diff);
	
// 	final_color = add_color(spect_color, diff_color);
// 	final_color =  multi_color_double(final_color, 0.0038);
// 	final_color = add_color(final_color, ambiant);
// 	color_condition(&final_color);
// 	// if (final_color.r  == 255 )
// 		// printf("spect = %f        diff = %f            \n     ",spect, diff);
// 	return (final_color);
// }+---------





int		intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double shadowlengh, int i)
{
	double t;
	cylinder->v = normalize_vect(cylinder->axe);
	t_vect x = minus_vect(ray->o, cylinder->c);
	double a = dot(ray->d,ray->d) - pow(dot(ray->d,cylinder->v),2);
	double b = 2*(dot(ray->d, x) - dot(ray->d, cylinder->v)* dot(x, cylinder->v));
	double c = dot(x,x) - pow(dot(x,cylinder->v), 2) - pow(cylinder->r,2);
	if ((t = solveQuadratic(a, b, c)) > 0.0001)
	{
		if (i == 0 && (shadowlengh < t))
				return (0);
		cylinder->t = solveQuadratic(a, b, c);
		cylinder->inter = add_vect(ray->o, multi_vect_double(ray->d, cylinder->t));
		cylinder->m = dot(ray->d, cylinder->v) * cylinder->t + dot(x,cylinder->v);
		cylinder->n = normalize_vect(multi_vect_double(minus_vect(minus_vect(cylinder->inter, cylinder->c),cylinder->v),cylinder->m));
		if (fmax(cylinder->m, 0) > 0 && fmax(cylinder->m, 0) < cylinder->h)
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
	if ((t = solveQuadratic(a, b, c)) > 0.0001)
	{
		if (i == 0 && (shadowlengh < t))
				return (0);
		cone->t = solveQuadratic(a, b, c);
		cone->inter = add_vect(ray->o, multi_vect_double(ray->d, cone->t));
		cone->m = dot(ray->d, cone->v) * cone->t + dot(x,cone->v);
		cone->n = normalize_vect(minus_vect(minus_vect(cone->inter,cone->c),multi_vect_double(cone->v, cone->m * pow(cone->k,2))));
		if (fmax(cone->m,0) > 0 && fmax(cone->m,0) < 50)
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
			// t_vect v = minus_vect(plane->inter, plane->o);
			// double d2 = dot(v,v);
			// if (sqrt(d2) <= 50)
			if (i == 1)
				plane->inter = inter;
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
	if ((t = solveQuadratic(a, b, c)) > 0.0001)
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





int		get_close_inter(t_ray *ray,t_obj *obj)
{
	t_vect		tmpinter;
	double 		le = 999999.9;
	double 		tmp_lengh;
	int 		num_obj;

	if (intersect_sphere(&*ray, &obj->sphere, 0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->sphere.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->sphere.inter;
			num_obj = 1;
		}
	}
	if (intersect_plane(&*ray, &obj->plane, 0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->plane.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->plane.inter;
			num_obj = 2;
		}
	}
	if (intersect_cylinder(&*ray, &obj->cylinder,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cylinder.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cylinder.inter;
			num_obj = 3;
		}
	}
	if (intersect_cone(&*ray, &obj->cone,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cone.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cone.inter;
			num_obj = 4;
		}
	}
	return (num_obj);
}

t_vect	call_obj_n(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = normalize_vect(minus_vect(obj.sphere.inter, obj.sphere.c));
	if (num_obj == 2)
		tmp = negative_vect(obj.plane.n);
	if (num_obj == 3)
		tmp = obj.cylinder.n;
	if (num_obj == 4)
		tmp = (obj.cone.n);
	return (tmp);
}

t_color	 call_obj_color(t_obj obj, int num_obj)
{
	t_color		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.color);
	if (num_obj == 2)
		tmp = (obj.plane.color);
	if (num_obj == 3)
		tmp = (obj.cylinder.color);
	if (num_obj == 4)
		tmp = (obj.cone.color);
	return (tmp);
}

t_vect	 call_obj_inter(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.inter);
	if (num_obj == 2)
		tmp = (obj.plane.inter);
	if (num_obj == 3)
		tmp = (obj.cylinder.inter);
	if (num_obj == 4)
		tmp = (obj.cone.inter);
	return (tmp);
}

int 	shadow(t_vect inter, t_ray light, t_obj obj) // les rayon intersepte les objet de l'autre cote de la lumiere
{
	t_ray	shadow;
	double 	r2;

	shadow.o = inter;
	shadow.d = minus_vect(light.o,shadow.o);
	r2 = sqrt(dot(shadow.d, shadow.d));
	shadow.d = normalize_vect(shadow.d);
	if (intersect_sphere(&shadow, &obj.sphere, r2, 0) || \
		intersect_plane(&shadow, &obj.plane, r2, 0) || \
		intersect_cylinder(&shadow, &obj.cylinder, r2, 0) || \
		intersect_cone(&shadow, &obj.cone, r2, 0))
		return (1);
	else
		return (0);
}


void		draw(t_all *all, t_sdl *sdl)
{
	int 				num_obj;
	int 				x;
	int					y;
	t_color				color;
	t_color				color_background;
	t_cam 				cam;
	t_axe				axe;

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
			// envoyer ray par chaque pixel
	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			compute_ray(cam,&all->ray,x,y);
			if (intersect_sphere(&all->ray, &all->obj.sphere,0 , 1) || \
				intersect_plane(&all->ray, &all->obj.plane,0, 1) || \
				intersect_cylinder(&all->ray, &all->obj.cylinder,0 , 1) || \
				intersect_cone(&all->ray, &all->obj.cone,0,1))
			{
				num_obj = get_close_inter(&all->ray, &all->obj);
				if (shadow(call_obj_inter(all->obj, num_obj), all->light.ray, all->obj))
					color = init_color(10,10,20,40);
				else
					// color = call_obj_color(all->obj, num_obj);
					color = color_phong(call_obj_color(all->obj, num_obj), all->light, \
						call_obj_n(all->obj, num_obj),all->ray,call_obj_inter(all->obj, num_obj));
				SDL_SetRenderDrawColor(sdl->ren, color.r, color.g, color.b, color.a);

			}
			else
				SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 40);
			SDL_RenderDrawPoint(sdl->ren, x, y);
		}
	}
	SDL_RenderPresent(sdl->ren);
}
