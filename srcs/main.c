/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 02:11:50 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/13 02:11:55 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

char	**ft_launch_fillit(t_tetra **list)
{
	int			size;
	char		**board;
	char		**solution;

	board = NULL;
	solution = NULL;
	size = ft_approx_root(ft_tetra_len(list) * 4);
	while (!solution)
	{
		board = ft_init_mat(size);
		solution = ft_resolve_fillit(board, *list);
		ft_mat_del(board);
		size++;
	}
	ft_tetra_del(list);
	return (solution);
}

void	ft_tetra_print(t_tetra **list)
{
	t_tetra		*temp;

	temp = *list;
	while (temp != NULL)
	{
		ft_putab(temp->pos);
		ft_putendl("");
		temp = temp->next;
	}
}

int		main(int ac, char **av)
{
	t_tetra		*list;
	int			fd;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
		fd = open(av[1], O_RDONLY);
	if (ft_file_parser(fd, &list) < 0 || ((ft_tetra_len(&list)) > 26))
		ft_putstr("error\n");
	else
		ft_putab(ft_launch_fillit(&list));
	close(fd);
	return (0);
}
