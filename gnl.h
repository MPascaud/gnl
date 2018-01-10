/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:09:45 by mpascaud          #+#    #+#             */
/*   Updated: 2018/01/10 16:32:58 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 65
# define MAX_FD 4865
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/ft_strcpy.c"
# include "libft/ft_strlen.c"
# include "libft/ft_strncat.c"
# include "libft/ft_strnew.c"

int		get_next_line(const int fd, char **line);

#endif
