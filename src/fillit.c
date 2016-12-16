/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:51:59 by lchety            #+#    #+#             */
/*   Updated: 2016/12/15 15:57:31 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_blocklist		*tmp;
	t_list			*tetro_list;
	char			*buff;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	buff = check_file(argv[1]);
	if (!buff)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		tetro_list = convert_to_list(buff, filelen(open(argv[1], O_RDONLY)));
		tmp = (t_blocklist*)tetro_list->content;
		small_square(tetro_list);
	}
	return (0);
}
