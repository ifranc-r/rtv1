//colors operator

#include "../includes/rtv1.h"

void	init_white(t_color *white)
{
	white->a = 40;
	white->r = 255;
	white->b = 255;
	white->g = 255;
}

void	init_color_sphere(t_color *color)
{
	color->a = 40;
	color->r = 0;
	color->b = 151;
	color->g = 151;
}

t_color	multi_color_double(t_color color, double b)
{
	t_color tmp;

	tmp.a = color.a * b;
	tmp.r = color.r * b;
	tmp.b = color.b * b;
	tmp.g = color.g * b;
	return (tmp);
}

t_color	add_color(t_color a, t_color b)
{
	t_color tmp;

	//tmp.a = a.a + b.a;
	tmp.r = a.r + b.r;
	tmp.b = a.b + b.b;
	tmp.g = a.g + b.g;
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