#include "../includes/rtv1.h"


// vecteur x y z
// ray	vecteur origin et vecteur direction
// sphere centre rayon 
// intersec
// int		intersect_cylinder(t_ray *ray, t_cylinder cylinder)
// {
// 	double		discriminant;
// 	double		b;
// 	double		c;

// 	double		R;
// 	double		a;

// 	double		t0, t1;
// 	double		cx, cy, cz; // centre spher
// 	double		x0, y0, z0; // directtion
// 	double		x1, y1, z1; // origin

// 	//initie les parametre de la sphere
// 	cx = sphere.c.x; // centre sphere
// 	cy = sphere.c.y;
// 	cz = sphere.c.z;

// 	R = sphere.r; // rayon sphere

// 	x0 = ray->o.x; // orgine
// 	y0 = ray->o.y; 
// 	z0 = ray->o.z;

// 	x1 = ray->d.x; //direction
// 	y1 = ray->d.y;
// 	z1 = ray->d.z;// probleme avec la gestion de l'axe z


// 	a = pow(x1,2)+pow(y1,2)+pow(z1,2);
// 	b = 2 * (x1*x0+y1*y0+ z1*z0);
// 	c = (pow(x0,2)+pow(y0,2)+pow(z0,2)) - R*R;
// 	discriminant = pow(b,2) - (4*a*c);
// 	if (discriminant < 0) // no intersection
// 		return (0);
// 	else if (discriminant == 0) 
// 	{
// 		//basic algo
// 		//ray->t = - 0.5 * b;

// 		//scratchapixel
// 		ray->t = - 0.5 * b / a;

// 		return (1);
// 	}
// 	else if (discriminant > 0)  // ray->is tangent to sphere
// 	{
// 		discriminant = sqrt(discriminant);
// 		t0 = ((-b + discriminant)/(2*a));
// 		t1 = ((-b - discriminant)/(2*a));
// 		ray->t = (t0 < t1) ? t0 : t1;
// 		return (1);
// 	}
// 	return (0);
// }
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

int		intersect_sphere(t_ray *ray, t_sphere sphere)
{
	//t_vect		inter;
	double		discriminant;

	// double		dx; // origin
	// double		dy; // direction
	// double		dz;

	double		b;
	double		c;

	//double 		q;
	double		R;

	double		t0, t1;
	double		cx, cy, cz; // centre spher
	double		x0, y0, z0; // directtion
	double		x1, y1, z1; // origin
	// double		ox, oy, oz;
	// double		thcx, thcy, thcz;

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
	double		lx, ly, lz;
	lx = (cx - x0);//(centresphere - origin ) = distance du centre sphere ou triangle hypothenuse
	ly = (cy - y0);
	lz = (cz - z0);
	b = 2 * (x1*lx+y1*ly+ z1*lz);	

	// dx =  lx*x1; // cote hypothenus * ray direction = distance de la droite adjacente triangle
	// dy =  ly*y1;
	// dz =  lz*z1;

	// ox =	sqrt(pow(lx, 2) - pow(dx, 2));//   (hypo^2 - adj^2)^1/2 = opposite
	// oy =	sqrt(pow(ly, 2) - pow(dy, 2));
	// oz =	sqrt(pow(lz, 2) - pow(dz, 2));

	// thcx =  sqrt(pow(R, 2) - pow(ox, 2)); // rayon * cote oposee = adjacente du point intersection au opposite
	// thcy =  sqrt(pow(R, 2) - pow(oy, 2));
	// thcz =  sqrt(pow(R, 2) - pow(oz, 2));

//scratchapixel
	double		a;
	a = pow(x1,2)+pow(y1,2)+pow(z1,2);
	//b = 2 * (x1*x0+y1*y0+ z1*z0);
	c = (pow(x0,2)+pow(y0,2)+pow(z0,2)) - R*R;
	discriminant = pow(b,2) - (4*a*c);

//basic algo
	//double		lx, ly, lz;
	//lx = (cx - x0);//(centresphere - origin ) = distance du centre sphere ou triangle hypothenuse
	//ly = (cy - y0);
	//lz = (cz - z0);
	//b = 2 * (x1*lx+y1*ly+ z1*lz);
	//c = (pow(lx,2)+pow(ly,2)+pow(lz,2)) - pow(R,2);
	//discriminant = pow(b,2) - (4*c);

	//a = pow(x1,2) + pow(y1,2) + pow(z1,2);
	//b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))
	//c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2
	//c = pow((x0 - cx),2) + pow((y0 - cy),2) + pow((z0 - cz),2) - R*R;
	//a = dx*dx + dy*dy + dz*dz;
	//b = 2*(dx*(x0-cx) + dy*(y0-cy) + dz*(z0-cz));
	//c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 -2*(cx*x0 + cy*y0 + cz*z0) - R*R;
	//else if (a == 1/4)
	//	return (0);
	if (discriminant < 0) // no intersection
		return (0);
	else if (discriminant == 0) 
	{
		//basic algo
		//ray->t = - 0.5 * b;

		//scratchapixel
		ray->t = - 0.5 * b / a;

		return (1);
	}
	else if (discriminant > 0)  // ray->is tangent to sphere
	{
		discriminant = sqrt(discriminant);
		//scratchapixel
		t0 = ((-b + discriminant)/(2*a));
		t1 = ((-b - discriminant)/(2*a));

		//basic algo
		//t0 = -b - discriminant;
		//t1 = -b + discriminant;
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
			if (intersect_sphere(&all->ray, all->sphere))
			{
				//all->sphere.inter = multi_vect_double(all->ray.d, all->ray.t);
				//all->sphere.inter = add_vect(all->ray.o, all->sphere.inter);
				all->sphere.inter.x = all->ray.o.x + (all->ray.d.x * all->ray.t);
				all->sphere.inter.y = all->ray.o.y + (all->ray.d.y * all->ray.t);
				all->sphere.inter.z = all->ray.o.z + (all->ray.d.z * all->ray.t);

				l = minus_vect(all->sphere_light.c, all->sphere.inter);
				// l = spherelight - all->sphere.inter

				n = minus_vect(all->sphere.c, all->sphere.inter);
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
				//SDL_SetRenderDrawColor(all->ren, 255, 0, 0, 40);
			}
			else if (intersect_plane(&all->ray, &all->plane))
			{
				l = minus_vect(all->sphere_light.c, all->plane.inter);
				n = minus_vect(all->plane.d, normalize_vect(all->plane.inter));
				dt  = dot(n, normalize_vect(l));

					//basic algo
				//l = minus_vect(all->sphere_light.c, all->plane.inter);
				//n = minus_vect(all->plane.n, all->plane.inter);
				//dt  = dot(normalize_vect(n), normalize_vect(l));
				//color = multi_color_double(all->plane.color_plane, dt*4);
				color = multi_color_double(color_background, dt);
				color = add_color(all->plane.color_plane, color);
				color = multi_color_double(color, 0.5);
				//color = all->plane.color_plane;
				color_condition(&color);
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