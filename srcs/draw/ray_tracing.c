#include "../includes/rtv1.h"

void		compute_ray(t_cam cam, t_ray *ray, int x, int y)
{
	double 	screen_pix_x;
	double 	screen_pix_y;
	t_vect 	image_point;
	double 	img_p_x;
	double 	img_p_y;
	double 	img_p_z;

	screen_pix_x = ((double)x / WIN_X) - 0.5;
  	screen_pix_y = ((double)y / WIN_Y) - 0.5;
	img_p_x = (screen_pix_x * cam.camright.x) + (screen_pix_y * cam.camup.x) + (cam.campos.x + cam.camdir.x);
	img_p_y = (screen_pix_x * cam.camright.y) + (screen_pix_y * cam.camup.y) + (cam.campos.y + cam.camdir.y);
	img_p_z = (screen_pix_x * cam.camright.z) + (screen_pix_y * cam.camup.z) + (cam.campos.z + cam.camdir.z);
	image_point = init_vect(img_p_x, img_p_y, img_p_z);
	ray->o = cam.campos;
	ray->d = minus_vect(image_point, cam.campos);
}

int 		intersect_obj(t_all *all, int a, int i)
{
	if (intersect_sphere(&all->ray, &all->obj.sphere, a, i) || \
		intersect_plane(&all->ray, &all->obj.plane, a, i) || \
		intersect_cylinder(&all->ray, &all->obj.cylinder, a , i) || \
		intersect_cone(&all->ray, &all->obj.cone, a, i) || \
		intersect_disc(&all->ray, &all->obj.cylinder.disc, a, i) || \
		intersect_disc(&all->ray, &all->obj.cylinder.disc2, a, i))
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

	x = -1;
	while (x++ < WIN_X)
	{
		y = -1;
		while (y++ < WIN_Y)
		{
			compute_ray(all->cam,&all->ray,x,y);
			if (intersect_obj(&*all,0 , 1))
			{
				num_obj = get_close_inter(&all->ray, &all->obj);
				if (shadow(call_obj_inter(all->obj, num_obj), all->light.ray, all->obj)){
					color = add_color(call_obj_color(all->obj, num_obj), init_color(-130,-130,-130,0));
					color = color_phong(color, all->light, \
						call_obj_n(all->obj, num_obj),all->ray,\
						call_obj_inter(all->obj, num_obj));
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