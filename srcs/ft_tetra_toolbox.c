/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_toolbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 02:16:32 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/13 02:16:34 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetra	*ft_tetra_create(char **pos)
{
	t_tetra		*result;

	result = (t_tetra *)ft_memalloc(sizeof(t_tetra));
	if (result)
	{
		result->pos = pos;
		result->next = NULL;
	}
	return (result);
}

int		ft_tetra_len(t_tetra **tetra_list)
{
	t_tetra		*list;
	int			i;

	list = *tetra_list;
	i = 0;
	if (list)
	{
		while ((list)->next != NULL)
		{
			list = (list)->next;
			i++;
		}
		i++;
	}
	return (i);
}

char	**ft_transform_elem(char **elem, char a)
{
	t_off		pos;

	pos.x = 0;
	while (elem[pos.x])
	{
		pos.y = 0;
		while (elem[pos.x][pos.y])
		{
			if (elem[pos.x][pos.y] == '#')
				elem[pos.x][pos.y] = a;
			pos.y++;
		}
		pos.x++;
	}
	return (elem);
}

void	ft_tetra_add(t_tetra **tetra_list, char **element)
{
	t_tetra		*list;
	char		display;

	list = *tetra_list;
	display = 65 + ft_tetra_len(tetra_list);
	element = ft_transform_elem(element, display);
	if (list)
	{
		while ((list)->next != NULL)
			list = (list)->next;
		(list)->next = ft_tetra_create(element);
	}
	else
		*tetra_list = ft_tetra_create(element);
}
