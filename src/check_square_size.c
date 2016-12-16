/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:14:09 by lchety            #+#    #+#             */
/*   Updated: 2016/12/11 21:34:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_top(char **grid, int grid_size)
{
	int x;
	int y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			if (grid[x][y] != '\0')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int		check_bottom(char **grid, int grid_size)
{
	int x;
	int y;

	y = grid_size - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < grid_size)
		{
			if (grid[x][y] != '\0')
				return (y + 1);
			x++;
		}
		y--;
	}
	return (grid_size);
}

int		check_left(char **grid, int grid_size)
{
	int x;
	int y;

	x = 0;
	while (x < grid_size)
	{
		y = 0;
		while (y < grid_size)
		{
			if (grid[x][y] != '\0')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int		check_right(char **grid, int grid_size)
{
	int x;
	int y;

	x = grid_size - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < grid_size)
		{
			if (grid[x][y] != '\0')
				return (x + 1);
			y++;
		}
		x--;
	}
	return (grid_size);
}

int		check_square_size(char **grid, int grid_size)
{
	t_point	size;

	size.y = check_bottom(grid, grid_size) - check_top(grid, grid_size);
	size.x = check_right(grid, grid_size) - check_left(grid, grid_size);
	return ((size.x > size.y) ? size.x : size.y);
}
