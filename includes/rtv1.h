#ifndef RTV1_H
# define RTV1_H
# define FRACT_OL_H
# include "../libft/libft.h"
# include <SDL.h>
//# include <SDL2/SDL.h>
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

typedef struct		s_ray
{
	t_vect			o; // origin
	t_vect			d; // direction
	t_vect			inter;
}					t_ray;

typedef struct		s_light
{
	t_ray			ray;
	t_color			color;
}					t_light;

typedef struct		s_plane
{
	t_vect			d; // axe
	t_vect			n; //vector derector
	t_vect			o; //origin
	t_vect			inter;
	t_color			color;
}					t_plane;

typedef struct		s_disc
{
	t_vect			d; // axe
	t_vect			n; //vector derector
	t_vect			o; //origin
	double 			r;
	t_vect			inter;
	t_color			color;
}					t_disc;

typedef struct		s_sphere
{
	t_vect			c; // centre
	double			r; // rayon de la sphere
	double 			t;
	double 			t0;
	double 			t1;
	t_vect			n; // normal surface
	t_vect			inter;// position of intersection
	t_color			color;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vect			c; // centre
	t_vect			axe;
	t_vect			v;
	double			m;
	t_vect			n;
	double			r; // rayon du disc
	double			h; // hauteur
	double 			t;
	t_vect 			end;
	t_disc			disc;
	t_disc			disc2;
	t_vect			inter;
	t_color			color;
}					t_cylinder;

typedef struct		s_cone
{
	t_vect			c; // centre
	t_vect			axe;
	t_vect			v;
	double			m;
	t_vect			n;
	double			r; // rayon du disc
	double			h; // hauteur
	double 			k;
	double 			t;
	t_vect			inter;
	t_color			color;
}					t_cone;



typedef struct		s_cam
{
	t_vect			campos; // camposition
	t_vect			camdir; // cam direction vecto
	t_vect			camup; // cam axis Y 
	t_vect			camright; 
}					t_cam;

typedef struct		s_sdl
{
	SDL_Surface		*win_surf;
	SDL_Window		*screen;
	SDL_Event		event;
	SDL_Renderer 	*ren;
	const Uint8 	*state;
}					t_sdl;

typedef struct		s_obj
{
	t_cam			cam;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_cone			cone;
	t_disc 			disc;
	t_light 		light;
}					t_obj;

typedef struct		s_parse
{
	char			*num;
	t_vect			pos;
	t_vect			direct;
	int 			radius;
	t_color			color;			
}					t_parse;

typedef struct		s_all
{
	t_ray			ray;
	t_obj 			obj;
	t_light			light;
	t_sdl			sdl;
	t_cam 			cam;
	int 			chg;
}					t_all;


void 				sdl_and_funct(t_all *all);

// parse
int					num_c(char *str, char c);
void				ft_exit(char *line);
void				ft_notnum(char *str, char *line);
void				ft_notlinenum(char *str, char *line);
int 				ft_strtrue(char *str, char *src, int loop);

t_vect 				ft_vect_pars(char **num);
t_color				ft_color_pars(char **num);
t_vect				take_vect(char *line ,int start);
double				take_double(char *line ,int start);
t_color				take_color(char *line ,int start);
t_cam 				get_cam_param(char *line);
t_sphere 			get_sphere_param(char *line);
t_plane 			get_plane_param(char *line);
t_cylinder 			get_cylinder_param(char *line);
t_disc 				get_disc_param(char *line);
t_cone 				get_cone_param(char *line);
int 				ft_strcoord(char *str, char *src, int loop);
void				draw(t_all *all, t_sdl *sdl);
t_obj				parse_map(int fd);

// intersection
int					intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double shadowlengh, int i);
int 				intersect_cone(t_ray *ray, t_cone *cone, double shadowlengh, int i);
int 				intersect_plane(t_ray *ray, t_plane *plane, double shadowlengh, int i);
int					intersect_sphere(t_ray *ray, t_sphere *sphere, double shadowlengh, int i);
int 				intersect_disc(t_ray *ray, t_disc *disc, double shadowlengh, int i);
//sdl
void				event(t_all *all, t_sdl *sdl, int file);
void				sdl_close(t_sdl *sdl);
void				sdl_err();
void				sdl_init(t_sdl *sdl);
//operation
double 				triangle_area(t_vect p1, t_vect p2, t_vect p3);
double				solveQuadratic(double a, double b, double c, int i);

//obj and sceen
void				init_sceen(t_all *all, int file);
void				init_cam(t_cam *cam, int file);
void				init_light(t_light *light, int file);
t_disc				init_disc(t_vect o, t_vect n, double r, t_color color);
void				init_sceen(t_all *all, int file);
t_vect				init_vect(double x, double y, double z);
void				init_plane(t_plane *plane);
void				init_sphere(t_sphere *sphere);
void				init_cylinder(t_cylinder *cylinder, int file);
void				init_light(t_light *light, int file);
void				init_cone(t_cone *cone, int file);
void				compute_ray(t_cam cam, t_ray *ray, int x, int y);
void				init_cam(t_cam *cam, int file);

int 				get_close_inter(t_ray *ray,t_obj *obj);
t_vect				call_obj_n(t_obj obj, int num_obj);
t_color				call_obj_color(t_obj obj, int num_obj);
t_vect				call_obj_inter(t_obj obj, int num_obj);

t_color				color_phong(t_color objct_color, t_light light, t_vect n,t_ray ray, t_vect inter);
int 				shadow(t_vect inter, t_ray light, t_obj obj);

#endif