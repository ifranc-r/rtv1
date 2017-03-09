
#include "../includes/rtv1.h"

void 	sdl_and_draw(t_all *all, int file)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdl_err();
	else
	{
		sdl_init(&all->sdl);
		event(&*all, &all->sdl, file);
	}
	sdl_close(&all->sdl);
}

int 	main(int argc, char **argv)
{
	t_all	all;
	int 	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		all.obj = parse_map(fd);
		sdl_and_draw(&all, 1);
	}
	else if (argc == 1)
		sdl_and_draw(&all, 0);
	return(0);
}
