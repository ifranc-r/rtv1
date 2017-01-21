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
	//t = (((plane->p1.x * plane->n.x +plane->p1.y * plane->n.y +plane->p1.z * plane->n.z) -(plane->n.x * ray->o.x) -(plane->n.y * ray->o.y) -(plane->n.z * ray->o.z)) / a);
	t = ((dot(plane->p1, plane->n)+(minus_double(plane->n,ray->o)))/a);
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
	if (((v_tri - (int)v_tri) > 0.00001) || ((v_tri_tmp -(int)v_tri_tmp) > 0.00001))
		return (1);
	return (0);
}

int		intersect_sphere(t_ray *ray, t_sphere sphere)
{
	//t_vect		inter;
	double		discriminant;

	// double		dx; // origin
	// double		dy; // direction
	// double		dz;

	double		a;
	double		b;
	double		c;

	//double 		q;
	double		R;

	double		t0, t1;
	double		cx, cy, cz; // centre spher
	double		x0, y0, z0; // directtion
	double		x1, y1, z1; // origin
	// double		lx, ly, lz;
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
	
	// lx =	(cx - x0);//(centresphere - origin ) = distance du centre sphere ou triangle hypothenuse
	// ly =	(cy - y0);
	// lz =	(cz - z0);

	// dx =  lx*x1; // cote hypothenus * ray direction = distance de la droite adjacente triangle
	// dy =  ly*y1;
	// dz =  lz*z1;

	// ox =	sqrt(pow(lx, 2) - pow(dx, 2));//   (hypo^2 - adj^2)^1/2 = opposite
	// oy =	sqrt(pow(ly, 2) - pow(dy, 2));
	// oz =	sqrt(pow(lz, 2) - pow(dz, 2));

	// thcx =  sqrt(pow(R, 2) - pow(ox, 2)); // rayon * cote oposee = adjacente du point intersection au opposite
	// thcy =  sqrt(pow(R, 2) - pow(oy, 2));
	// thcz =  sqrt(pow(R, 2) - pow(oz, 2));

	a = pow(x1,2)+pow(y1,2)+pow(z1,2);
	b = 2 * (x1*x0+y1*y0+ z1*z0);
	c = (pow(x0,2)+pow(y0,2)+pow(z0,2)) - R*R;
	//a = pow(x1,2) + pow(y1,2) + pow(z1,2);
	//b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))
	//c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2
	//c = pow((x0 - cx),2) + pow((y0 - cy),2) + pow((z0 - cz),2) - R*R;
	//a = dx*dx + dy*dy + dz*dz;
	//b = 2*(dx*(x0-cx) + dy*(y0-cy) + dz*(z0-cz));
	//c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 -2*(cx*x0 + cy*y0 + cz*z0) - R*R;
	discriminant = pow(b,2) - (4*a*c);
	//else if (a == 1/4)
	//	return (0);
	if (discriminant < 0) // no intersection
		return (0);
	else if (discriminant == 0) 
	{
		ray->t = - 0.5 * b / a;
		return (1);
	}
	else if (discriminant > 0)  // ray->is tangent to sphere
	{
		discriminant = sqrt(discriminant);
		t0 = c / ((-b + discriminant)/2);
		t1 = ((-b - discriminant)/2)/a;
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
	t_axe		axe;
	t_cam 		cam;
	t_vect		look_at;
	t_vect		diff_btw;

	init_vect(&look_at, 1, 0, 0);
	init_cam(&cam);
	init_vect(&diff_btw, cam.campos.x - look_at.x, cam.campos.y - look_at.y, cam.campos.z - look_at.z);
	cam.camdir = normalize_vect(negative_vect(diff_btw));
	cam.camright = normalize_vect(cross_prod(axe.y, cam.camdir));
	cam.camdown = cross_prod(cam.camright, cam.camdir); 
	init_axe(&axe);
	init_sphere(&all->sphere);
	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			init_ray(cam,&all->ray,x,y);
			if (intersect_sphere(&all->ray, all->sphere))
				SDL_SetRenderDrawColor(all->ren, 255, 255, 255, 40);
			// envoyer ray par chaque pixel
			else
				SDL_SetRenderDrawColor(all->ren, 200, 0, 0, 40);
			SDL_RenderDrawPoint(all->ren, x, y);
		}
	}
	SDL_RenderPresent(all->ren);
}