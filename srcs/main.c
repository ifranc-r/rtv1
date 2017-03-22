/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:00:10 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/22 18:06:36 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_strcmp_end(char *str, char *src)
{
	int		i;
	int		a;

	i = ft_strlen(str);
	a = ft_strlen(src);
	if (str)
	{
		while (str[i] == src[a])
		{
			if (a == 0 || i == 0)
				break ;
			--i;
			--a;
		}
		if (a == 0)
			return (1);
	}
	return (0);
}

void	menu(void)
{
	ft_putstr("	  =========TUTO==========\n\n");
	ft_putstr("   ---------Keys--------\n");
	ft_putendl_fd("  Press the key right, up, down and left ", 2);
	ft_putendl_fd("  plus and minus", 2);
	ft_putendl_fd("        for moving the positions of the objs.\n", 2);
	ft_putstr("   C = cam; D = cam Rotation; 0 = light\n");
	ft_putstr("   1 = sphere; 2 = pos plane || 5 = Rotation plane\n");
	ft_putstr("   3 = cylinder; 8 = Rotation cylinder;");
	ft_putstr(" 4 = cone || 9 = Rotation cone\n");
}

void	sdl_and_draw(t_all *all, int file)
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

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		all.obj = parse_map(fd, ft_strcmp_end(argv[1], ".xml"));
		sdl_and_draw(&all, 1);
	}
	else if (argc < 2)
	{
		ft_putstr("usage: [./rtv1 filename.xml]\n");
		return (-1);
	}
	else if (argc == 1)
		sdl_and_draw(&all, 0);
	return (0);
}
