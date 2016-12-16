/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 02:16:58 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 17:30:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

size_t				lst_count(t_list *t)
{
	size_t i;

	i = 0;
	while (t->next)
	{
		t = t->next;
		i++;
	}
	return (i + 1);
}

static void			add_bl_link(t_blocklist *parent, int pos, t_point orig)
{
	t_blocklist *new;

	while (parent->next != NULL)
	{
		parent = parent->next;
	}
	new = (t_blocklist*)malloc(sizeof(t_blocklist));
	if (new)
	{
		new->vector.x = (pos % 5) - orig.x;
		new->vector.y = (pos / 5) - orig.y;
		new->next = NULL;
		parent->next = new;
	}
}

static t_blocklist	*new_blocklist(char *buff)
{
	int				i;
	t_point			origin;
	t_blocklist		*new;

	new = NULL;
	i = 0;
	while (buff[i] != '#')
		i++;
	origin.x = i % 5;
	origin.y = i / 5;
	new = (t_blocklist*)malloc(sizeof(t_blocklist));
	new->vector.x = 0;
	new->vector.y = 0;
	new->next = NULL;
	i++;
	while (i < 21)
	{
		if (buff[i] == '#')
			add_bl_link(new, i, origin);
		i++;
	}
	return (new);
}

t_list				*convert_to_list(char *buff, size_t size)
{
	t_list	*list_tetro;
	t_list	*tmp_list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	list_tetro = (t_list*)malloc(sizeof(t_list));
	list_tetro->next = NULL;
	list_tetro->content = (void*)new_blocklist(buff);
	tmp_list = list_tetro;
	i += 21;
	while (i < (int)size)
	{
		tmp_list->next = (t_list*)malloc(sizeof(t_list));
		tmp_list = tmp_list->next;
		tmp_list->next = NULL;
		tmp_list->content = (void*)new_blocklist(buff + i);
		i += 21;
	}
	return (list_tetro);
}
