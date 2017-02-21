#include "../includes/rtv1.h"

int		get_close_inter(t_ray *ray,t_obj *obj)
{
	t_vect		tmpinter;
	double 		le = 999999.9;
	double 		tmp_lengh;
	int 		num_obj;

	if (intersect_sphere(&*ray, &obj->sphere, 0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->sphere.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->sphere.inter;
			num_obj = 1;
		}
	}
	if (intersect_plane(&*ray, &obj->plane, 0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->plane.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->plane.inter;
			num_obj = 2;
		}
	}
	if (intersect_cylinder(&*ray, &obj->cylinder,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cylinder.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cylinder.inter;
			num_obj = 3;
		}
	}
	if (intersect_cone(&*ray, &obj->cone,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cone.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cone.inter;
			num_obj = 4;
		}
	}
	if (intersect_disc(&*ray, &obj->cylinder.disc,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cylinder.disc.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cylinder.disc.inter;
			num_obj = 5;
		}
	}
		if (intersect_disc(&*ray, &obj->cylinder.disc2,0, 1))
	{
		tmp_lengh = lengh(minus_vect(ray->o, obj->cylinder.disc2.inter));
		if (tmp_lengh < le)
		{
			le = tmp_lengh;
			tmpinter = obj->cylinder.disc2.inter;
			num_obj = 6;
		}
	}
	return (num_obj);
}

t_vect	call_obj_n(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = normalize_vect(minus_vect(obj.sphere.inter, obj.sphere.c));
	if (num_obj == 2)
		tmp = negative_vect(obj.plane.n);
	if (num_obj == 3)
		tmp = obj.cylinder.n;
	if (num_obj == 4)
		tmp = (obj.cone.n);
	if (num_obj == 5)
		tmp = negative_vect(obj.cylinder.disc.n);
	if (num_obj == 6)
		tmp = negative_vect(obj.cylinder.disc2.n);
	return (tmp);
}

t_color	 call_obj_color(t_obj obj, int num_obj)
{
	t_color		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.color);
	if (num_obj == 2)
		tmp = (obj.plane.color);
	if (num_obj == 3)
		tmp = (obj.cylinder.color);
	if (num_obj == 4)
		tmp = (obj.cone.color);
	if (num_obj == 5)
		tmp = (obj.cylinder.disc.color);
	if (num_obj == 6)
		tmp = (obj.cylinder.disc2.color);
	return (tmp);
}

t_vect	 call_obj_inter(t_obj obj, int num_obj)
{
	t_vect		tmp;

	if (num_obj == 1)
		tmp = (obj.sphere.inter);
	if (num_obj == 2)
		tmp = (obj.plane.inter);
	if (num_obj == 3)
		tmp = (obj.cylinder.inter);
	if (num_obj == 4)
		tmp = (obj.cone.inter);
	if (num_obj == 5)
		tmp = (obj.cylinder.disc.inter);
	if (num_obj == 6)
		tmp = (obj.cylinder.disc2.inter);
	return (tmp);
}