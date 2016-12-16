/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:05:12 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 11:57:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		show_grid(char **grid, int grid_size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			ft_putchar(grid[j][i]);
			if (grid[j][i] == '\0')
				ft_putstr(".");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

void		init_t_grid(t_grid **grid, size_t size)
{
	int i;

	i = 0;
	*grid = (t_grid*)malloc(sizeof(t_grid));
	(*grid)->size = size;
	(*grid)->best_size = size + 2;
	(*grid)->grid = (char**)malloc(sizeof(char*) * (*grid)->size);
	(*grid)->save = (char**)malloc(sizeof(char*) * (*grid)->size);
	while (i < (*grid)->size)
	{
		(*grid)->grid[i] = (char*)malloc(sizeof(char) * (*grid)->size);
		ft_bzero((*grid)->grid[i], (*grid)->size);
		(*grid)->save[i] = (char*)malloc(sizeof(char) * (*grid)->size);
		ft_bzero((*grid)->save[i], (*grid)->size);
		i++;
	}
}

void		save_grid(t_grid *grid)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			grid->save[x][y] = grid->grid[x][y];
			x++;
		}
		y++;
	}
}

int			grid_compare(t_grid *grid)
{
	int		size_tmp;

	size_tmp = check_square_size(grid->grid, grid->size);
	if (size_tmp < grid->best_size)
	{
		grid->best_size = size_tmp;
		return (1);
	}
	return (0);
}
