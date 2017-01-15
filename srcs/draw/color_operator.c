//colors operator

#include "../includes/rtv1.h"

void	init_white(t_color *white)
{
	white->a = 40;
	white->r = 255;
	white->b = 255;
	white->g = 255;
}

t_color	multi_color_double(t_color color, double b)
{
	t_color tmp;

	tmp.a = color.a * (int)b;
	tmp.r = color.r * (int)b;
	tmp.b = color.b * (int)b;
	tmp.g = color.g * (int)b;
	return (tmp);
}

t_color	add_color(t_color a, t_color b)
{
	t_color tmp;

	tmp.a = a.a + b.a;
	tmp.r = a.r + b.r;
	tmp.b = a.b + b.b;
	tmp.g = a.g + b.g;
	return (tmp);
}

void	color_condition(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	else if (color->g > 255)
		color->g = 255;
	else if (color->b > 255)
		color->b = 255;
	else if (color->r < 0)
		color->r = 0;
	else if (color->b < 0)
		color->b = 0;
	else if (color->g < 0)
		color->g = 0;
}