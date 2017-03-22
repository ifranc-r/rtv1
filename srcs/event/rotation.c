/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:03:24 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/22 18:04:08 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"
#define TO_RADIANS(x) (x * PI / 180.0f)

void	rotatex(t_vect *vec, double degree)
{
	double rx;
	double tmpy;
	double tmpz;

	rx = TO_RADIANS(degree);
	tmpy = vec->y;
	tmpz = vec->z;
	vec->y = tmpy * cosf(rx) - tmpz * sinf(rx);
	vec->z = tmpy * sinf(rx) + tmpz * cosf(rx);
}

void	rotatey(t_vect *vec, double degree)
{
	double ry;
	double tmpx;
	double tmpz;

	ry = TO_RADIANS(degree);
	tmpx = vec->x;
	tmpz = vec->z;
	vec->x = tmpz * sin(ry) + tmpx * cos(ry);
	vec->z = tmpz * cos(ry) - tmpx * sin(ry);
}

void	rotatez(t_vect *vec, double degree)
{
	double rz;
	double tmpx;
	double tmpy;

	rz = TO_RADIANS(degree);
	tmpx = vec->x;
	tmpy = vec->y;
	vec->x = tmpx * cos(rz) - tmpy * sin(rz);
	vec->y = tmpx * sin(rz) + tmpy * cos(rz);
}

void	rotatexyz(t_vect *vec, t_vect rot)
{
	if (rot.x > 90)
		rot.x = 90;
	if (rot.x < -90)
		rot.x = -90;
	rotatez(&*vec, rot.z);
	rotatex(&*vec, rot.x);
	rotatey(&*vec, rot.y);
}
