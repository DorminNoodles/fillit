/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:54:41 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 15:54:59 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	check_file_struct(const char *buff, size_t size)
{
	int line;
	int i;

	i = 0;
	line = 1;
	while (i < (int)size)
	{
		if (line != 1 && !(line % 5))
		{
			if (buff[i] != '\n')
				return (0);
			i++;
		}
		else
		{
			if (buff[i + 4] != '\n')
				return (0);
			i += 5;
		}
		line++;
	}
	if (line % 5 != 0 || buff[i] == '\n')
		return (0);
	return (1);
}

static int	check_char(const char *buff, size_t size)
{
	int i;

	i = 0;
	while (i < (int)size)
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char		*check_file(char *filename)
{
	int		fd;
	char	*buff;

	buff = (char*)malloc(sizeof(char) * 1024);
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		fd = read(fd, buff, 1024);
		close(fd);
		if (fd >= 546 || !check_char(buff, fd) || !check_file_struct(buff, fd))
			return (NULL);
		if (!check_tetro(buff, fd))
			return (NULL);
	}
	else
		return (NULL);
	return (buff);
}
