/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:02:36 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/09 17:02:38 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vect		init_vect(double x, double y, double z)
{
	t_vect		tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
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

double		solvequadratic(double a, double b, double c, int i)
{
	double 		discriminant;
	double 		t;
	double 		t0;
	double 		t1;

	t = 0;
	if ((discriminant = b*b-4*a*c) < 0)
		return (0);
	else if (discriminant == 0) 
		t = -0.5 * b / a;
	else if (discriminant >= 0)
	{
		discriminant = sqrt(discriminant);
		t0 = ((-b + discriminant)/(2*a));
		t1 = ((-b - discriminant)/(2*a));
		if (i == 0)
			t = (t0 > t1) ? t0 : t1;
		else if (i == 2)
			t = (t0 < t1) ? t0 : t1;
		else
			t = (t0 < t1) ? t0 : t1;
	}
	return (t);    
}






























