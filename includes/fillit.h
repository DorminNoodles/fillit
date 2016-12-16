/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:40:47 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 15:57:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

struct		s_point
{
	int	x;
	int	y;
};
typedef struct s_point		t_point;

struct		s_blocklist
{
	char				letter;
	t_point				vector;
	struct s_blocklist	*next;

};
typedef struct s_blocklist	t_blocklist;

struct		s_grid
{
	char	**grid;
	char	**save;
	int		size;
	int		best_size;
};
typedef struct s_grid		t_grid;

char		*check_file(char *filename);
int			check_tetro(char *buff, size_t size);
t_list		*convert_to_list(char *buff, size_t size);
size_t		filelen(int fd);
size_t		lst_count(t_list *t);
int			backtracking(t_grid *grid, t_list *tetro_list, int letter);
void		insert_tetro(t_grid *grid, t_blocklist	*block, int pos, int ltr);
int			check_pos(char **grid, t_blocklist *block, int pos, int grid_size);
char		**small_square(t_list *tetro_list);
void		extract_tetro(t_grid *grid, t_blocklist	*block, int pos);
int			check_square_size(char **grid, int grid_size);
void		show_grid(char **grid, int grid_size);
void		init_t_grid(t_grid **grid, size_t size);
int			check_result(t_grid *grid);
int			grid_compare(t_grid *grid);
void		save_grid(t_grid *grid);

#endif
