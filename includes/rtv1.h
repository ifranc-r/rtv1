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
# define WIN_X 800
# define WIN_Y 600
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

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect

typedef struct		s_ray
{
	t_vect			o; // origin
	t_vect			d; // direction
}					t_ray

typedef struct		s_sphere
{
	t_vect			c; // centre
	float			r; // rayon de la sphere
}					t_sphere



typedef struct		s_all
{
	t_sphere		sphere;
	SDL_Surface		*win_surf;
	SDL_Window		*screen;
	SDL_Event		event;
	SDL_Renderer 	*ren;
	const Uint8 	*state;

}					t_all;

void 				sdl(t_all *all);
void				draw(t_all *all);
void				event(t_all *all);
void				sdl_close(t_all *all);
#endif