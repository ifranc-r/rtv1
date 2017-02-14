/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_vect3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:49:02 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/02/14 15:53:05 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	neg_dot(t_vect a, t_vect b)
{
	double		tmp;

	tmp = -(a.x * b.x) - (a.y * b.y) - (a.z * b.z);
	return (tmp);
}

double	minus_double(t_vect a, t_vect b)
{
	double		tmp;

	tmp = -a.x * b.x - a.y * b.y - a.z * b.z;
	return (tmp);
}

t_vect	normalize_vect(t_vect a)
{
	double		dist;
	t_vect		tmp;

	dist = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
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

double	magintude(t_vect a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
