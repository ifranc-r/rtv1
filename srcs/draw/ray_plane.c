#include "../includes/rtv1.h"



void		draw(t_all *all, t_sdl *sdl)
{
	int 				num_obj;
	int 				x;
	int					y;
	t_color				color;
	t_color				color_background;
	t_cam 				cam;

	cam = all->cam;
	color_background = init_color(255, 255, 255, 40);
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
				if (shadow(call_obj_inter(all->obj, num_obj), all->light.ray, all->obj)){
					color = add_color(call_obj_color(all->obj, num_obj), init_color(-130,-130,-130,0));
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
