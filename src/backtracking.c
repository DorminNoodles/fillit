/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 01:25:41 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 11:58:51 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		**small_square(t_list *tetro_list)
{
	int		i;
	size_t	grid_size;
	char	**grid;
	t_grid	*grid_new;

	i = 0;
	while ((i * i) < (int)lst_count(tetro_list) * 4)
		i++;
	grid_size = i;
	init_t_grid(&grid_new, grid_size);
	grid = (char**)malloc(sizeof(char*) * grid_size);
	i = 0;
	while (i < (int)grid_size)
	{
		*(grid + i) = (char*)malloc(sizeof(char) * grid_size);
		i++;
	}
	while (!check_result(grid_new))
	{
		init_t_grid(&grid_new, grid_size);
		backtracking(grid_new, tetro_list, 0);
		grid_size++;
	}
	show_grid(grid_new->save, grid_new->size);
	return (NULL);
}

int			check_result(t_grid *grid)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < grid->size)
	{
		j = 0;
		while (j < grid->size)
		{
			if (grid->save[j][i] >= 'A' && grid->save[j][i] <= 'Z')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		insert_tetro(t_grid *grid, t_blocklist *block, int pos, int ltr)
{
	int		x;
	int		y;

	if (block)
	{
		x = (pos % grid->size) + block->vector.x;
		y = (pos / grid->size) + block->vector.y;
		grid->grid[x][y] = ltr + 'A';
		block = block->next;
		insert_tetro(grid, block, pos, ltr);
	}
}

void		extract_tetro(t_grid *grid, t_blocklist *block, int pos)
{
	int	x;
	int	y;

	if (block)
	{
		x = (pos % grid->size) + block->vector.x;
		y = (pos / grid->size) + block->vector.y;
		grid->grid[x][y] = '\0';
		block = block->next;
		extract_tetro(grid, block, pos);
	}
}

int			backtracking(t_grid *grid, t_list *tetro_list, int ltr)
{
	t_blocklist	*tmp;
	int			i;

	i = 0;
	tmp = (t_blocklist*)tetro_list->content;
	while (i < grid->size * grid->size)
	{
		if (check_pos(grid->grid, tmp, i, grid->size))
		{
			insert_tetro(grid, tmp, i, ltr);
			if (tetro_list->next)
				grid->best_size = backtracking(grid, tetro_list->next, ltr + 1);
			else
			{
				if (grid_compare(grid))
					save_grid(grid);
			}
			extract_tetro(grid, tmp, i);
		}
		i++;
	}
	return (grid->best_size);
}
