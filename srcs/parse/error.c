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
void	ft_notnum(char *str)
{
	int 	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'\
	 || str[i])
		++i;
	// printf("%d   %d\n", i,  (int)ft_strlen(str));
	if (i != (int)ft_strlen(str))
	{
		ft_putstr("letter detected:\n"); 
		ft_exit(str);
	}
}
void	ft_exit(char *line)
{
	ft_putstr("Error on this line : \n");
	ft_putstr(line);
	ft_putstr("\nFile incorrect\n");
	exit(-1);
}