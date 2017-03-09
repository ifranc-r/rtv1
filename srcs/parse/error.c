#include "../includes/rtv1.h"

int		num_c(char *str, char c)
{
	int		i;
	int 	a;

	a = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] && str[i] == c)
				++i;
			++a;
		}
		++i;
	}
	return (a);
}

void	ft_notnum(char *str, char *line)
{
	int 	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		++i;
	if (i != (int)ft_strlen(str))
	{
		ft_putstr("letter detected:\n"); 
		ft_exit(line);
	}
}

void	ft_notlinenum(char *str, char *line)
{
	int 	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' ||
		str[i] == ' ')
		++i;
	if (i != (int)ft_strlen(str))
	{
		ft_putstr("letter detected:\n"); 
		ft_exit(line);
	}
}
void	ft_exit(char *line)
{
	ft_putstr("Error on this line : \n");
	ft_putstr(line);
	ft_putstr("\nFile incorrect\n");
	exit(-1);
}