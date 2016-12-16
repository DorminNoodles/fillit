/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:25:24 by lchety            #+#    #+#             */
/*   Updated: 2016/12/11 21:34:30 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

size_t		filelen(int fd)
{
	size_t		size;
	char		buff[1];

	size = 0;
	while (read(fd, buff, 1))
	{
		if (buff[0] != '\0')
			size++;
	}
	return (size);
}
