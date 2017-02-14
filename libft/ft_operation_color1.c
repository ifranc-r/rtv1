/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_color1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:40:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/02/14 15:40:53 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	init_color(double r, double g, double b, double a)
{
	t_color tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	tmp.a = a;
	return (tmp);
}

t_color	multi_color_double(t_color color, double b)
{
	t_color tmp;

	tmp.r = color.r * b;
	tmp.b = color.b * b;
	tmp.g = color.g * b;
	return (tmp);
}

t_color	multi_color(t_color color, t_color b)
{
	t_color tmp;

	tmp.r = color.r * b.r;
	tmp.b = color.b * b.b;
	tmp.g = color.g * b.g;
	return (tmp);
}

t_color	devide_color_double(t_color color, double b)
{
	t_color tmp;

	tmp.r = color.r / b;
	tmp.b = color.b / b;
	tmp.g = color.g / b;
	return (tmp);
}

t_color	add_color(t_color a, t_color b)
{
	t_color tmp;

	tmp.r = a.r + b.r;
	tmp.b = a.b + b.b;
	tmp.g = a.g + b.g;
	return (tmp);
}
