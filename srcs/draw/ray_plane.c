#include "../includes/rtv1.h"

int 		intersection(t_ray *ray, t_obj *obj)
{
	if (intersect_sphere(&*ray, &obj->sphere,0 , 1) || \
	intersect_plane(&*ray, &obj->plane,0, 1) || \
	intersect_cylinder(&*ray, &obj->cylinder,0 , 1) || \
	intersect_cone(&*ray, &obj->cone,0,1))
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
	t_cam 				cam;

	cam = all->cam;
	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			compute_ray(cam,&all->ray,x,y);
			if (intersection(&all->ray, &all->obj))
			{
				num_obj = get_close_inter(&all->ray, &all->obj);
				if (shadow(call_obj_inter(all->obj, num_obj), all->light.ray, all->obj)){
					color = devide_color_double(call_obj_color(all->obj, num_obj), 2);
					color = color_phong(color, all->light, \
						call_obj_n(all->obj, num_obj),all->ray,call_obj_inter(all->obj, num_obj));
				}
				else
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
