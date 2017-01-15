#include "../includes/rtv1.h"


// vecteur x y z
// ray	vecteur origin et vecteur direction
// sphere centre rayon 
// intersect

void		init_sphere(t_sphere *sphere)
{
	sphere->c.x = WIN_X/2;
	sphere->c.y = WIN_Y/2;
	sphere->c.z = 50;

	sphere->r = 50;
}

void		init_ray(t_ray *ray, int x, int y)
{
	ray->t = 200;

	ray->o.x = (double)x;
	ray->o.y = (double)y;
	ray->o.z = 0;

	ray->d.x = 0;
	ray->d.y = 0;
	ray->d.z = 1;
}
void		init_sphere_light(t_sphere *sphere_light)
{
	sphere_light->c.x = WIN_X/2;
	sphere_light->c.y = 0;
	sphere_light->c.z = 50;
	sphere_light->r = 1;
}

int		intersect_sphere(t_ray *ray, t_sphere sphere)
{
	//t_vect		inter;
	double		distriminant;

	double		dx; // origin
	double		dy; // direction
	double		dz;

//	double		a;
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
	z1 = ray->d.z;
	
	dx = ray->o.x - cx; // origin - direction = distance
	dy = ray->o.y - cy;
	dz = ray->o.z - cz;

	b = 2 * (dx*x1 + dy*y1 + dz*z1);
	c = (dx*dx+dy*dy+dz*dz) - R*R;
	//a = dx*dx + dy*dy + dz*dz;
	//b = 2*dx*(x0-cx) +  2*dy*(y0-cy) +  2*dz*(z0-cz);
	//c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 -2*(cx*x0 + cy*y0 + cz*z0) - R*R;
	distriminant = pow(b,2) - (4*c);
	//t = ((-b-sqrt(pow(b,2)-4*a*c)) / (2*a));
	if (distriminant < 0) // no intersection
		return (0);
	else  // ray->is tangent to sphere
	{
		distriminant = sqrt(distriminant);
		t0 = -b - distriminant;
		t1 = -b + distriminant;
		ray->t = (t0 < t1) ? t0 : t1;
		return (1);
	}
	return (0);
}

void		draw(t_all *all)
{
	int 		x;
	int			y;
	t_vect		inter;	// position of intersection
	t_vect		l;	// light 
	t_vect		n;
	double		dt;
	t_color		color;
	t_color		white;

	x = 0;
	//couleur fond vert
	init_sphere(&all->sphere);
	init_sphere_light(&all->sphere_light);
	init_white(&white);
	//Boucle pour chaque pixel
	while (++x < WIN_X)
	{
		y = 0;
		while (++y < WIN_Y)
		{
			init_ray(&all->ray, x, y);
			// checker pour intersection
			if (intersect_sphere(&all->ray, all->sphere))
			{
				inter = add_vect(all->ray.o, all->ray.d); 
				inter = multi_vect_double(inter, all->ray.t); // inter =all->ray.o + all->ray.d * all->ray.t;

				l = minus_vect(all->sphere_light.c, inter);// l = spherelight - inter

				n = minus_vect(all->sphere.c, inter);
				n = devide_vect_double(n, all->sphere.r);//n.z = all->sphere.c.z - inter.z / all->sphere.r; // (centre - inter )/ rayon

				dt  = dot(normalize_vect(l), normalize_vect(n));
				//
				// 
				//
				color = multi_color_double(white, dt);
				//color_condition(&color);
				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
			}
			else 
				SDL_SetRenderDrawColor(all->ren, 0, 51, 51, 40);
			// envoyer ray par chaque pixel		
			SDL_RenderDrawPoint(all->ren, x, y);
		}
	}
	SDL_RenderPresent(all->ren);
}