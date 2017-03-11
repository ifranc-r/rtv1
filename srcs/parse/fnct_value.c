/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:04:35 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/11 18:20:56 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vect		ft_vect_pars(char **num)
{
	t_vect		tmp;

	tmp.x = (double)ft_atoi(num[0]);
	tmp.y = (double)ft_atoi(num[1]);
	tmp.z = (double)ft_atoi(num[2]);
	return (tmp);
}

t_color		ft_color_pars(char **num)
{
	t_color		tmp;

	tmp.r = (double)ft_atoi(num[0]);
	tmp.g = (double)ft_atoi(num[1]);
	tmp.b = (double)ft_atoi(num[2]);
	tmp.a = (double)ft_atoi(num[3]);
	return (tmp);
}

t_vect		take_vect(char *line, int start)
{
	int			i;
	int			a;
	char		*param;
	char		**axe;

	i = 0;
	axe = NULL;
	a = start + 1;
	param = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[a] != '\"' && line[a])
	{
		param[i] = line[a];
		++i;
		++a;
	}
	param[i] = '\0';
	ft_notlinenum(param, line);
	if (num_c(param, ' ') != 2 || param[0] == ' ')
		ft_exit(line);
	axe = ft_strsplit(param, ' ');
	free(param);
	free(axe);
	return (ft_vect_pars(axe));
}

double		take_double(char *line, int start)
{
	int			i;
	int			a;
	char		*param;
	double		num;

	i = 0;
	a = start + 1;
	param = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[a] != '\"' && line[a])
	{
		param[i] = line[a];
		++i;
		++a;
	}
	param[i] = '\0';
	ft_notnum(param, line);
	num = (double)ft_atoi(param);
	free(param);
	return (num);
}

t_color		take_color(char *line, int start)
{
	int			i;
	int			a;
	char		*param;
	char		**color;

	i = 0;
	color = NULL;
	a = start + 1;
	param = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[a] != '\"' && line[a])
	{
		param[i] = line[a];
		++i;
		++a;
	}
	param[i] = '\0';
	ft_notlinenum(param, line);
	if (num_c(param, ' ') != 3 || param[0] == ' ')
		ft_exit(line);
	color = ft_strsplit(param, ' ');
	free(param);
	free(color);
	return (ft_color_pars(color));
}
