#ifndef RTV1_H
# define RTV1_H
# define FRACT_OL_H
# include "../libft/libft.h"
# include <SDL2/SDL.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# define WIN_X 600
# define WIN_Y 600
# define Z_CAM 300
# define I_X 600
# define I_Y 600
# define PI 3.14159265359
# define N_CALL 9
# define ARROW_UP 125
# define ARROW_DOWN 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define PLUS_RED 15
# define LESS_RED 17
# define PLUS_BLUE 11
# define LESS_BLUE 45
# define PLUS_GREEN 5
# define LESS_GREEN 4


typedef struct		s_color
{
	double			a;
	double			r;
	double			g;
	double			b;
}					t_color;


typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_axe
{
	t_vect			x;
	t_vect			y;
	t_vect			z;
}					t_axe;

typedef struct		s_plane
{
	t_vect			d; //vector derector
	t_vect			o; //origin
	t_vect			in; //inclinaison
	double 			di;
	t_vect			inter;
	t_color			color_plane;
}					t_plane;

typedef struct		s_ray
{
	t_vect			o; // origin
	t_vect			d; // direction
	double			t;
}					t_ray;

typedef struct		s_cam
{
	t_vect			campos; // camposition
	t_vect			camdir; // cam direction vecto
	t_vect			camup; // cam axis Y 
	t_vect			camright; 
}					t_cam;

typedef struct		s_sphere
{
	t_vect			c; // centre
	double			r; // rayon de la sphere
	t_vect			inter;// position of intersection
	t_color			color_sphere;
}					t_sphere;


typedef struct		s_all
{
	t_ray			ray;
	t_sphere		sphere;
	t_sphere		sphere_light;
	t_plane			plane;
	SDL_Surface		*win_surf;
	SDL_Window		*screen;
	SDL_Event		event;
	SDL_Renderer 	*ren;
	const Uint8 	*state;

}					t_all;

void				draw(t_all *all);
//sdl
void 				sdl(t_all *all);
void				event(t_all *all);
void				sdl_close(t_all *all);
//operation
t_vect				add_vect(t_vect a, t_vect b);
t_vect				minus_vect(t_vect a, t_vect b);
t_vect				multi_vect(t_vect a, t_vect b);
t_vect				devide_vect_double(t_vect a, double b);
t_vect				multi_vect_double(t_vect a, double b);
t_vect				normalize_vect(t_vect a);
t_vect				add_vect_double(t_vect a, double b);
t_vect				negative_vect(t_vect a);
double 				magintude(t_vect a);
double 				dot(t_vect a, t_vect b);
double 				minus_double(t_vect a, t_vect b);
double 				triangle_area(t_vect p1, t_vect p2, t_vect p3);
t_vect				cross_prod(t_vect a, t_vect b);
double 				neg_dot(t_vect a, t_vect b);
//color
void				init_color_background(t_color *color_background);
t_color				multi_color_double(t_color color, double b);
t_color				add_color(t_color a, t_color b);
void				color_condition(t_color *color);
void				init_color_sphere(t_color *color);
void				init_color_plane(t_color *color);
//obj
void				init_vect(t_vect *vect, double x, double y, double z);
void				init_axe(t_axe *axe);
void				init_plane(t_plane *plane);
void				init_sphere(t_sphere *sphere);
void				init_sphere_light(t_sphere *sphere_light);
void				compute_ray(t_cam cam, t_ray *ray, int x, int y);
void				init_cam(t_cam *cam);
#endif