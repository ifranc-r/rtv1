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
	// int 	i= -1;

	(void)all;
	if (argc == 2) // if(str_dir(argv[1]) == ".xml")
	{
		fd = open(argv[1], O_RDONLY);
		all.obj = parse_map(fd);
		// printf("%f %f %f\n", parse.pos.x, parse.pos.y, parse.pos.z);
		//all = parse(fd);
		sdl_and_draw(&all, 1);
	}
	else if (argc == 1)
		sdl_and_draw(&all, 0);
	return(0);
}
