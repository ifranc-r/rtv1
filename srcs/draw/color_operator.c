//colors operator

#include "../includes/rtv1.h"

t_color init_color(double r, double g, double b, double a)
{
	t_color tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	tmp.a = a;
	return (tmp);
}

void	init_color_background(t_color *color_background)
{
	color_background->a = 40;
	color_background->r = 255;
	color_background->b = 255;
	color_background->g = 255;
}

void	init_color_plane(t_color *color)
{
	color->a = 40;
	color->r = 0;
	color->b = 50;
	color->g = 0;
}

void	init_color_sphere(t_color *color)
{
	color->a = 40;
	color->r = 40;
	color->b = 0;
	color->g = 0;
}

t_color	multi_color_double(t_color color, double b)
{
	t_color tmp;

	//tmp.a = color.a * b;
	tmp.r = color.r * b;
	tmp.b = color.b * b;
	tmp.g = color.g * b;
	return (tmp);
}

t_color	multi_color(t_color color, t_color b)
{
	t_color tmp;

	//tmp.a = color.a * b;
	tmp.r = color.r * b.r;
	tmp.b = color.b * b.b;
	tmp.g = color.g * b.g;
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

t_color	minus_color(t_color a, t_color b)
{
	t_color tmp;

	//tmp.a = a.a + b.a;
	tmp.r = a.r - b.r;
	tmp.b = a.b - b.b;
	tmp.g = a.g - b.g;
	return (tmp);
}

void	color_max(t_color *color)
{
	color->r = fmax(color->r, 0);
	color->b = fmax(color->b, 0);
	color->g = fmax(color->g, 0);
}

double clamp(double x, double upper, double lower)
{
    return fmin(upper, fmax(x, lower));
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