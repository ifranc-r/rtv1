#include "../includes/rtv1.h"


// vecteur x y z
// ray	vecteur origin et vecteur direction
// sphere centre rayon 
// intersect


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
	t_vect		inter;	// position of intersection
	t_vect		l;	// light 
	t_vect		n;
	double		dt;
	t_color		color;
	t_color		white;
	t_color		color_sphere;

	x = 0;
	//couleur fond vert
	init_sphere(&all->sphere);
	init_sphere_light(&all->sphere_light);
	init_white(&white);
	init_color_sphere(&color_sphere);
	//Boucle pour chaque pixel
	while (++x < WIN_X)
	{
		y = 0;
		while (++y < WIN_Y)
		{
			init_ray(&all->ray, x, y);
			// checker pour intersection
			if (intersect_sphere(&all->ray, all->sphere))// probleme avec la gestion de l'axe z
			{
				inter = multi_vect_double(all->ray.d, all->ray.t);
				inter = add_vect(all->ray.o, inter);
				//inter.x = all->ray.o.x + (all->ray.d.x * all->ray.t);
				////inter.y = all->ray.o.y + (all->ray.d.y * all->ray.t);
				//inter.z = all->ray.o.z + (all->ray.d.z * all->ray.t);

				l = minus_vect(all->sphere_light.c, inter);
				// l = spherelight - inter

				n = minus_vect(inter, all->sphere.c);
				n = devide_vect_double(n, all->sphere.r);
				//n.x = (all->sphere.c.x - inter.x) / all->sphere.r;
				////n.y = (all->sphere.c.y - inter.y) / all->sphere.r;
				//n.z = (all->sphere.c.z - inter.z) / all->sphere.r;

				dt  = dot(normalize_vect(l), normalize_vect(n));

				color = multi_color_double(white, dt);
				color = add_color(color_sphere, color);
				color = multi_color_double(color, 0.5);
				color_condition(&color);
				SDL_SetRenderDrawColor(all->ren, color.r, color.g, color.b, color.a);
				printf("rouge :%f\nbleue :%f\nvert :%f\n\n dt : %f\n\n", color.r, color.g, color.b, dt );
			}
			else 
				SDL_SetRenderDrawColor(all->ren, 0, 0, 0, 40);
			// envoyer ray par chaque pixel		
			SDL_RenderDrawPoint(all->ren, x, y);
		}
	}
	SDL_RenderPresent(all->ren);
}