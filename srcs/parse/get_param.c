#include "../includes/rtv1.h"

t_cam 	get_cam_param(char *line)
{
	t_cam	cam;

	cam.campos = take_vect(line,ft_strcoord(line,"position=", 0));
	cam.camdir = take_vect(line,ft_strcoord(line,"direction=", 0));
	return (cam);
}

t_sphere 	get_sphere_param(char *line)
{
	t_sphere 	sphere;
	if (ft_strcmp(line,))
	{
		sphere.c = take_vect(line,ft_strcoord(line,"position=", 0));
		sphere.r = take_double(line,ft_strcoord(line,"radius=", 0));
		sphere.color = take_color(line,ft_strcoord(line,"color=", 0));
	}
	return (sphere);
}

t_plane 	get_plane_param(char *line)
{
	t_plane 	plane;

	plane.o = take_vect(line,ft_strcoord(line,"position=", 0));
	plane.d = take_vect(line,ft_strcoord(line,"normal=", 0));
	plane.color = take_color(line,ft_strcoord(line,"color=", 0));
	return (plane);
}