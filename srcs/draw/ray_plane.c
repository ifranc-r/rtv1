#include "../includes/rtv1.h"


// vecteur x y z
// ray	vecteur origin et vecteur direction
// sphere centre rayon 
// intersect
void		init_sphere(t_sphere *sphere)
{
	sphere.c.x = 2/WIN_X;
	sphere.c.y = 2/WIN_X;
	sphere.c.z = 50;
	sphere.r = 30;
}

t_vect		intersect_sphere(t_ray ray, t_all *all)
{
	t_vect		inter;
	float		dx; // origin
	float		dy; // direction
	float		dz;

	float		a;
	float		b;
	float		c;

	float		cx, cy, cz; // centre spher
	float		x0, y0, z0; // directtion
	float		x1, y1, z1; // origin

	//initie les parametre de la sphere
	cx = all->sphere.c.x;
	cy = all->sphere.c.x;
	cz = all->sphere.c.x;

	x0, y0, z0;

	x1, y1, z1;
	
	dx = ray.d.x - ray.o.x;
	dy = ray.d.y - ray.o.y;
	dz = ray.d.z - ray.o.z;

	a = dx*dx + dy*dy + dz*dz;
	b = 2*dx*(x0-cx) +  2*dy*(y0-cy) +  2*dz*(z0-cz);
	c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 -2*(cx*x0 + cy*y0 + cz*z0) - R*R;
	init_sphere(&all->sphere);

}

void		draw(t_all *all)
{
	int 		x;
	int			y;

	i = 0;
	//couleur fond vert
	SDL_SetRenderDrawColor(all->ren, 0, 51, 51, 40);
	
	
	//Boucle pour chaque pixel
	while (++x < WIN_X)
	{
		y = 0;
		while (++y < WIN_Y)
		{	
			// envoyer ray par chaque pixel		
			SDL_RenderDrawPoint(all->ren, x, y);
			// checker pour intersection
		}
	}
	SDL_RenderPresent(all->ren);
}