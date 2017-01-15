// operation 

#include "../includes/rtv1.h"

t_vect	add_vect(t_vect a, t_vect b)
{
	t_vect		tmp;

	tmp.x = a.x + b.x;
	tmp.y = a.y + b.y;
	tmp.z = a.z + b.z;
	return (tmp);
}

t_vect	minus_vect(t_vect a, t_vect b) 
{
	t_vect		tmp;

	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	tmp.z = a.z - b.z;
	return (tmp);
}

t_vect	devide_vect_double(t_vect a, double b)
{
	t_vect		tmp;

	tmp.x = a.x / b;
	tmp.y = a.y / b;
	tmp.z = a.z / b;
	return (tmp);
}

t_vect	multi_vect_double(t_vect a, double b)
{
	t_vect		tmp;

	tmp.x = a.x * b;
	tmp.y = a.y * b;
	tmp.z = a.z * b;
	return (tmp);
}

double 	dot(t_vect a, t_vect b)
{
	double tmp;
	tmp = a.x * b.x+a.y * b.y+a.z * b.z;
	return (tmp);
}

t_vect	normalize_vect(t_vect a)
{
	double 		mg;
	t_vect 		tmp;

	mg = sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
	tmp = devide_vect_double(a,mg);
	return (tmp);
}