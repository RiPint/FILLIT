/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_toolbox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:56:20 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:56:22 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_approx_root(int nb)
{
	int		result;

	result = 1;
	while (result * result < nb)
		result++;
	return (result);
}

char	**ft_init_mat(int size)
{
	char	**result;
	int		len;

	len = size;
	result = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	result[size] = NULL;
	size--;
	while (size >= 0)
	{
		result[size] = (char *)ft_strnew(len);
		ft_memset(result[size], '.', len);
		size--;
	}
	return (result);
}

char	**ft_matcopy(char **src)
{
	int		i;
	char	**dst;

	i = 0;
	dst = (char **)ft_memalloc(sizeof(char *) * (ft_strlen(*src) + 1));
	if (dst)
	{
		while (src[i] != NULL)
		{
			dst[i] = ft_strdup(src[i]);
			i++;
		}
	}
	return (dst);
}

int		ft_is_piece_fits(char **mat, char **tetra, t_off *offset)
{
	int		x;
	int		y;
	int		size;

	x = 0;
	y = 0;
	size = ft_strlen(*mat);
	while (tetra[x] != 0)
	{
		if (x + offset->x >= size)
			return (-1);
		while (tetra[x][y])
		{
			if (y + offset->y >= size)
				return (1);
			if (tetra[x][y] != '.' && mat[x + offset->x][y + offset->y] != '.')
				return (2);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

void	ft_insert_piece(char **mat, char **tetra, t_off *offset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (tetra[x] != 0)
	{
		while (tetra[x][y])
		{
			if (ft_isalpha(tetra[x][y]) &&
								mat[x + offset->x][y + offset->y] == '.')
				mat[x + offset->x][y + offset->y] = tetra[x][y];
			y++;
		}
		y = 0;
		x++;
	}
}
