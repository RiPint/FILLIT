/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 02:14:19 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/13 02:14:22 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

void	ft_tetra_del(t_tetra **alst)
{
	t_tetra	*temp;
	t_tetra	*next_one;

	if (alst != NULL)
	{
		temp = *alst;
		while (temp != NULL)
		{
			next_one = temp->next;
			free(temp);
			temp = next_one;
		}
		*alst = NULL;
	}
}

int		ft_mat_del(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		ft_strdel(&mat[i]);
		i++;
	}
	free(*mat);
	return (1);
}

t_off	*ft_init_offset(void)
{
	t_off	*result;

	result = (t_off *)ft_memalloc(sizeof(t_off));
	if (result)
	{
		result->x = 0;
		result->y = 0;
	}
	return (result);
}

int		ft_get_offset(char **mat, char **tetra, t_off *offset)
{
	int		ret;

	ret = 0;
	while ((ret = ft_is_piece_fits(mat, tetra, offset)) != -1)
	{
		if (ret == 1)
		{
			offset->x += 1;
			offset->y = 0;
		}
		else if (ret == 2)
			offset->y += 1;
		else if (ret == -1)
			return (0);
		else
			return (1);
	}
	return (0);
}

char	**ft_resolve_fillit(char **mat, t_tetra *tetra)
{
	t_off	*off;
	char	**temp;
	char	**solution;

	if (tetra == NULL)
		return (ft_matcopy(mat));
	off = ft_init_offset();
	solution = NULL;
	while (ft_get_offset(mat, tetra->pos, off) && solution == NULL)
	{
		temp = ft_matcopy(mat);
		ft_insert_piece(temp, tetra->pos, off);
		solution = ft_resolve_fillit(temp, tetra->next);
		ft_mat_del(temp);
		off->y += 1;
	}
	free(off);
	return (solution);
}
