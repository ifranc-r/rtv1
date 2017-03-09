#include "../includes/rtv1.h"

char	*parse(char *file)
{
	char	*line;

	if (ft_strstr(file, ".xml") == NULL)
	{
		ft_putendl_fd("the file have to ending with <.xml>", 2);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(file, O_RDONLY)) > 2)
	{
		while ((get_next_line(fd, &(line++))) > 0)
			;
		*tmp = NULL;
		close(fd);
	}
	return (tab);
}