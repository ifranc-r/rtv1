#include "../includes/rtv1.h"


// vecteur x y z
// ray	vecteur origin et vecteur direction
// sphere centre rayon 
// intersec

int 	intersect_plane(t_ray *ray, t_plane *plane)
{
	double 		a;
	double 		t;
	double 		v_tri;
	double 		v_tri_tmp;

	a = dot(ray->d, plane->n);
	if (a == 0) // plane parallel to the ray
		return (0);
	t = (plane->p1.x * plane->n.x +plane->p1.y * plane->n.y +plane->p1.z * plane->n.z) -(plane->n.x * ray->o.x -plane->n.y * ray->o.y -plane->n.z * ray->o.z);
	// ((dot(plane->p1, plane->n)+(minus_double(plane->n,ray->o)))/a);
	if (t < 0)
		return (0);
	//plane->inter = add_vect(ray->o, multi_vect_double(ray->d, t));
	plane->inter.x = ray->o.x + (ray->d.x * t);
	plane->inter.y = ray->o.y + (ray->d.y * t);
	plane->inter.z = ray->o.z + (ray->d.z * t);
	v_tri = fabs(triangle_area(plane->p1,plane->p2,plane->p4) - \
		triangle_area(plane->p1,plane->p4,plane->inter) - \
		triangle_area(plane->p1,plane->p3,plane->inter) - \
		triangle_area(plane->p3,plane->p4,plane->inter));
	v_tri_tmp = fabs(triangle_area(plane->p1,plane->p2,plane->p3) - \
		triangle_area(plane->p1,plane->p2,plane->inter) - \
		triangle_area(plane->p2,plane->p3,plane->inter) - \
		triangle_area(plane->p1,plane->p3,plane->inter));
	if ((v_tri - (int)v_tri) || (v_tri_tmp -(int)v_tri_tmp))
		return (1);
	return (0);
}

int		intersect_sphere(t_ray *ray, t_sphere sphere)
{
	//t_vect		inter;
	double		distriminant;

	double		dx; // origin
	double		dy; // direction
	double		dz;

	//double		a;
	double		b;
	double		c;

	double		R;

	double		t0, t1;
	double		cx, cy, cz; // centre spher
	double		x0, y0, z0; // directtion
	double		x1, y1, z1; // origin

	//initie les parametre de la sphere
	cx = sphere.c.x; // centre sphere
	cy = sphere.c.y;
	cz = sphere.c.z;

	R = sphere.r; // rayon sphere

	x0 = ray->o.x; // orgine
	y0 = ray->o.y; 
	z0 = ray->o.z;

	x1 = ray->d.x; //direction
	y1 = ray->d.y;
	z1 = ray->d.z;// probleme avec la gestion de l'axe z
	
	dx = ray->o.x - cx; // origin - direction = distance
	dy = ray->o.y - cy;
	dz = ray->o.z - cz;

	b = 2 * (dx*x1 + dy*y1 + dz*z1);
	c = (dx*dx+dy*dy+dz*dz) - R*R;
	//a = pow(x1,2) + pow(y1,2) + pow(z1,2);
	//b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))
	//c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2
	//c = pow((x0 - cx),2) + pow((y0 - cy),2) + pow((z0 - cz),2) - R*R;
	//a = dx*dx + dy*dy + dz*dz;
	//b = 2*(dx*(x0-cx) + dy*(y0-cy) + dz*(z0-cz));
	//c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 -2*(cx*x0 + cy*y0 + cz*z0) - R*R;
	distriminant = pow(b,2) - (4/**a*/*c);
	//else if (a == 1/4)
	//	return (0);
	if (distriminant < 0) // no intersection
		return (0);
	else  // ray->is tangent to sphere
	{
		distriminant = sqrt(distriminant);
		t0 = ((-b - distriminant) /*/ 2*a*/);
		t1 = ((-b + distriminant) /*/ 2*a*/);
		//t0 = -b - distriminant;
		//t1 = -b + distriminant;
		ray->t = (t0 < t1) ? t0 : t1;
		return (1);
	}
	return (0);
}

void		draw(t_all *all)
{
	int 		x;
	int			y;
	t_vect		l;	// light 
	t_vect		n;
	double		dt;
	t_color		color;
	t_color		color_background;

	x = -1;
	//couleur fond vert
	init_sphere(&all->sphere);
	init_sphere_light(&all->sphere_light);
	init_plane(&all->plane);
	init_color_background(&color_background);
	//Boucle pour chaque pixel
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			init_ray(&all->ray, x, y);
			// checker pour intersection
			if (intersect_sphere(&all->ray, all->sphere))// probleme avec la gestion de l'axe z
			{
				//all->sphere.inter = multi_vect_double(all->ray.d, all->ray.t);
				//all->sphere.inter = add_vect(all->ray.o, all->sphere.inter);
				all->sphere.inter.x = all->ray.o.x + (all->ray.d.x * all->ray.t);
				all->sphere.inter.y = all->ray.o.y + (all->ray.d.y * all->ray.t);
				all->sphere.inter.z = all->ray.o.z + (all->ray.d.z * all->ray.t);

				l = minus_vect(all->sphere_light.c, all->sphere.inter);
				// l = spherelight - all->sphere.inter

				n = minus_vect(all->sphere.inter, all->sphere.c);
				n = devide_vect_double(n, all->sphere.r);
				//n.x = (all->sphere.c.x - all->sphere.inter.x) / all->sphere.r;
				////n.y = (all->sphere.c.y - all->sphere.inter.y) / all->sphere.r;
				//n.z = (all->sphere.c.z - all->sphere.inter.z) / all->sphere.r;

				dt  = dot(normalize_vect(l), normalize_vect(n));

				color = multi_color_double(color_background, dt);
				color = add_color(all->sphere.color_sphere, color);
				color = multi_color_double(color, 0.5);
				color_condition(&color);
				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
				//printf("rouge :%f\nbleue :%f\nvert :%f\n\n dt : %f\n\n", color.r, color.g, color.b, dt );
			}
			else if (intersect_plane(&all->ray, &all->plane))
			{
				l = minus_vect(all->sphere_light.c, all->plane.inter);
				n = minus_vect(all->plane.inter, all->plane.n);
				dt  = dot(normalize_vect(n), normalize_vect(l));
				color = multi_color_double(color_background, dt);
				color = add_color(all->plane.color_plane, color);
				color = multi_color_double(color, 0.5);
			//	color = all->plane.color_plane;
				color_condition(&color);
				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			}
			else 
				SDL_SetRenderDrawColor(all->ren, 0, 0, 0, 40);
			// envoyer ray par chaque pixel		
			SDL_RenderDrawPoint(all->ren, x, y);
		}
	}
	SDL_RenderPresent(all->ren);
}