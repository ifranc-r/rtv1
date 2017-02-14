/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_color2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:44:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/02/14 15:44:21 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	minus_color(t_color a, t_color b)
{
	t_color tmp;

	tmp.r = a.r - b.r;
	tmp.b = a.b - b.b;
	tmp.g = a.g - b.g;
	return (tmp);
}

void	color_condition(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->b < 0)
		color->b = 0;
	if (color->g < 0)
		color->g = 0;
}
