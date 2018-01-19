
#include "get_next_line.h"
#include <stdio.h>

//main simple
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open (argv[1], O_RDONLY);
	if (argc == 2)
	{
		while (get_next_line(fd, &line) == 1)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
		free(line);
	}
	return (0);
}

//main multi-fd
/*int     main(int ac, char **av)
{
	    int     i;
		int     *fd;
		char    *line;

		i = 0;
		fd = ft_memalloc(ac - 1);
		while (i < ac)
		{
			(ac == 1) ? (fd[i] = 0) : (fd[i] = open(av[i + 1], O_RDONLY));
			while (get_next_line(fd[i], &line) == 1)
				printf("%s\n", line);
				close(fd[i++]);
		}
		return (0);
}*/
