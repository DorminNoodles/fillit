/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 01:25:31 by lchety            #+#    #+#             */
/*   Updated: 2016/12/11 21:34:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_pos(char **grid, t_blocklist *block, int pos, int grid_size)
{
	t_point p;

	p.x = pos % grid_size;
	p.y = pos / grid_size;
	if (!block)
		return (1);
	if (p.x + block->vector.x < 0 || p.x + block->vector.x >= grid_size)
		return (0);
	if (p.y + block->vector.y < 0 || p.y + block->vector.y >= grid_size)
		return (0);
	if (grid[p.x + block->vector.x][p.y + block->vector.y] != '\0')
		return (0);
	if (check_pos(grid, block->next, pos, grid_size))
		return (1);
	return (0);
}
