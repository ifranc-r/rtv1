/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_vect1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:45:31 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/02/14 15:45:34 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_vect	devide_vect(t_vect a, t_vect b)
{
	t_vect		tmp;

	tmp.x = a.x / b.x;
	tmp.y = a.y / b.y;
	tmp.z = a.z / b.z;
	return (tmp);
}

t_vect	multi_vect(t_vect a, t_vect b)
{
	t_vect		tmp;

	tmp.x = a.x * b.x;
	tmp.y = a.y * b.y;
	tmp.z = a.z * b.z;
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
