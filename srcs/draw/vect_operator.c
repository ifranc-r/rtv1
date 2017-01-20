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

t_vect	add_vect_double(t_vect a, double b)
{
	t_vect		tmp;

	tmp.x = a.x + b;
	tmp.y = a.y + b;
	tmp.z = a.z + b;
	return (tmp);
}

double 	dot(t_vect a, t_vect b)
{
	double tmp;
	tmp = a.x * b.x + a.y * b.y + a.z * b.z;
	return (tmp);
}

double 	minus_double(t_vect a, t_vect b)
{
	double tmp;
	tmp = - a.x * b.x - a.y * b.y - a.z * b.z;
	return (tmp);
}

t_vect	normalize_vect(t_vect a)
{
	double 		mg;
	t_vect 		tmp;

	mg = sqrt(a.x *a.x +a.y * a.y + a.z * a.z);
	tmp = devide_vect_double(a, mg);
	return (tmp);
}

double triangle_area(t_vect p1, t_vect p2, t_vect p3)
{
	double 		a;
	double 		b;
	double 		c;
	double 		s;

	a = sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.x),2) + pow((p2.z - p1.z),2));
	b = sqrt(pow((p3.x - p2.x),2) + pow((p3.y - p2.x),2) + pow((p3.z - p2.z),2));
	c = sqrt(pow((p3.x - p1.x),2) + pow((p3.y - p1.x),2) + pow((p3.z - p1.z),2));
	s = (a+b+c)/2;
	return (sqrt(s*(s - a)*(s - b)*(s - c)));
}





























