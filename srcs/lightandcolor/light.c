#include "../includes/rtv1.h"

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
	final_color =  multi_color_double(diff_color, 0.0038);
	final_color = add_color(final_color, ambiant);
	color_condition(&final_color);
	return (final_color);
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
