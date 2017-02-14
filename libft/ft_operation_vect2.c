/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_vect2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:46:56 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/02/14 15:48:14 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

double	dot(t_vect a, t_vect b)
{
	double tmp;

	tmp = a.x * b.x + a.y * b.y + a.z * b.z;
	return (tmp);
}

double	lengh(t_vect a)
{
	double tmp;

	tmp = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
	return (tmp);
}
