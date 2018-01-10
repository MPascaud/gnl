/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:26:23 by mpascaud          #+#    #+#             */
/*   Updated: 2018/01/10 16:24:25 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		ft_ft2(char **line, char *tmp)
{
	char	*tmp2;
	int		n;
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	n = 1;
	if (tmp[i] != '\n')
		n = 0;
	tmp2 = ft_strnew(ft_strlen(*line) + i);
	ft_strcpy(tmp2, *line);
	ft_strncat(tmp2, tmp, i);
	free(*line);
	ft_strcpy(tmp, &tmp[i + n]);
	*line = tmp2;
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static char		tmp[MAX_FD][BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (read(fd, &ret, 0)) == -1)
		return (-1);
	*line = NULL;
	ret = 0;
	if (ft_ft2(line, tmp[fd]) == 1)
		return (1);
	while ((ret = read(fd, tmp[fd], BUFF_SIZE)) > 0)
	{
		tmp[fd][ret] = '\0';
		if (ft_ft2(line, tmp[fd]) == 1)
			return (1);
	}
	if (**line != '\0')
		return (1);
	return (0);
}

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
