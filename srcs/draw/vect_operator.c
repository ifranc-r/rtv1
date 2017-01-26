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

t_vect	cross_prod(t_vect a, t_vect b) 
{
	t_vect		tmp;

	tmp.x = a.y * b.z - a.z * b.y;
	tmp.y = a.z * b.x - a.x * b.z;
	tmp.z = a.x * b.y - a.y * b.x;
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

double 	lengh(t_vect a)
{
	double tmp;
	tmp = sqrt(pow(a.x, 2)+ pow(a.y, 2) + pow(a.z, 2));
	return (tmp);
}

double 	neg_dot(t_vect a, t_vect b)
{
	double tmp;
	tmp = -(a.x * b.x) - (a.y * b.y) - (a.z * b.z);
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
	double 		dist;
	t_vect 		tmp;

	dist = sqrt(a.x *a.x +a.y * a.y + a.z * a.z);
	tmp = devide_vect_double(a, dist);
	return (tmp);
}

t_vect	negative_vect(t_vect a)
{
	t_vect		tmp;

	tmp.x = -a.x;
	tmp.y = -a.y;
	tmp.z = -a.z;
	return (tmp);
}

double magintude(t_vect a)
{
	return (sqrt(a.x *a.x +a.y * a.y + a.z * a.z));
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

double		solveQuadratic(double a, double b, double c)
{
	double 		discriminant;
	double 		t;
	double 		t0;
	double 		t1;

    discriminant = b * b -  4*a * c;
	if (discriminant < 0) // no intersection
		return (0);
	else if (discriminant == 0) 
	{
		t = - 0.5 * b / a;
		return (t);
	}
	else if (discriminant > 0)  // ray->is tangent to sphere
	{
		discriminant = sqrt(discriminant);
		t0 = ((-b + discriminant)/(2*a));
		t1 = ((-b - discriminant)/(2*a));
		t = (t0 < t1) ? t0 : t1;
		return (t);
	}
    return (0);
}






























