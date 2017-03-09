#include "../includes/rtv1.h"

t_cylinder 	get_cylinder_param(char *line)
{
	t_cylinder 	cylinder;

	cylinder.c = take_vect(line,ft_strcoord(line,"position=", 0));
	cylinder.end = take_vect(line,ft_strcoord(line,"endpos=", 0));
	cylinder.r = take_double(line,ft_strcoord(line,"radius=", 0));
	cylinder.color = take_color(line,ft_strcoord(line,"color=", 0));
	return (cylinder);
}

t_disc 	get_disc_param(char *line)
{
	t_disc 	disc;

	disc.o = take_vect(line,ft_strcoord(line,"position=", 0));
	disc.d = take_vect(line,ft_strcoord(line,"normal=", 0));
	disc.r = take_double(line,ft_strcoord(line,"radius=", 0));
	disc.color = take_color(line,ft_strcoord(line,"color=", 0));
	return (disc);
}

t_cone 	get_cone_param(char *line)
{
	t_cone 	cone;

	cone.c = take_vect(line,ft_strcoord(line,"position=", 0));
	cone.axe = take_vect(line,ft_strcoord(line,"normal=", 0));
	cone.r = take_double(line,ft_strcoord(line,"radius=", 0));
	cone.color = take_color(line,ft_strcoord(line,"color=", 0));
	return (cone);
}