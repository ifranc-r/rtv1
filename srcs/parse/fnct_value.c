#include "../includes/rtv1.h"

t_vect 		ft_vect_pars(char **num)
{
	t_vect	tmp;

	tmp.x = (double)ft_atoi(num[0]); 
	tmp.y = (double)ft_atoi(num[1]); 	
	tmp.z = (double)ft_atoi(num[2]);
	return (tmp); 
}

t_color		ft_color_pars(char **num)
{
	t_color	tmp;

	tmp.r = (double)ft_atoi(num[0]); 
	tmp.g = (double)ft_atoi(num[1]); 	
	tmp.b = (double)ft_atoi(num[2]);
	tmp.a = (double)ft_atoi(num[3]);
	return (tmp); 
}

t_vect		take_vect(char *line ,int start)
{
	int 	i;
	int 	a;
	char	*param = NULL;
	char	**axe = NULL;

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
	ft_notlinenum(param, line);
	if (num_c(param,' ') != 2)
		ft_exit(line);
	axe = ft_strsplit(param, ' ');
	free(param);
	free(axe);
	return (ft_vect_pars(axe));
}

double		take_double(char *line ,int start)
{
	int 	i;
	int 	a;
	char	*param = NULL;
	double 	num;

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

t_color		take_color(char *line ,int start)
{
	int 	i;
	int 	a;
	char	*param = NULL;
	char	**color = NULL;

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
	ft_notlinenum(param, line);
	if (num_c(param,' ') != 3)
		ft_exit(line);
	color = ft_strsplit(param, ' ');
	free(param);
	free(color);
	return (ft_color_pars(color));
}