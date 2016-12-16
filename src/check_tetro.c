/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:45:02 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 16:07:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		check_body_nb(char tab[4][4])
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (i < 16)
	{
		if (tab[i % 4][i / 4] == '#')
			nb++;
		i++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

static int		check_link(char tab[4][4])
{
	int i;
	int link;

	link = 0;
	i = 0;
	while (i < 16)
	{
		if (tab[i % 4][i / 4] == '#')
		{
			if (i / 4 != 0 && tab[i % 4][(i / 4) - 1] == '#')
				link++;
			if (i / 4 != 3 && tab[i % 4][(i / 4) + 1] == '#')
				link++;
			if (i % 4 != 0 && tab[(i % 4) - 1][i / 4] == '#')
				link++;
			if (i % 4 != 3 && tab[(i % 4) + 1][i / 4] == '#')
				link++;
		}
		i++;
	}
	if (link >= 6)
		return (1);
	return (0);
}

int				check_tetro(char *buff, size_t size)
{
	int		i;
	int		j;
	int		line;
	char	tab[4][4];

	j = 0;
	i = 0;
	line = 1;
	while (i < (int)size)
	{
		if (j < 21 && buff[i] != '\n')
			tab[j % 5][j / 5] = buff[i];
		j++;
		i++;
		if (j == 20)
		{
			if (!check_body_nb(tab) || !check_link(tab))
				return (0);
			j = 0;
			i++;
		}
	}
	return (1);
}
