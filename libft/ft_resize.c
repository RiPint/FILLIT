/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:56:07 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:56:09 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_resize1(char **str)
{
	int		i;
	char	**tab;
	int		ok;

	i = 0;
	ok = ft_check_hor_len_high(str);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) - ok + 1)))
		return (NULL);
	while (str[ok])
	{
		if (!(tab[i] = ft_memalloc(ft_strlen(str[0]) + 1)))
			return (NULL);
		tab[i] = ft_strsub(str[ok], 0, ft_strlen(str[i]));
		i++;
		ok++;
	}
	tab[i] = NULL;
	ft_mat_del(str);
	return (tab);
}

char	**ft_resize2(char **str)
{
	int		i;
	int		j;
	char	**tab;
	int		ok;

	i = 0;
	j = 0;
	ok = ft_check_vert_len_right(str);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		j = 0;
		if (!(tab[i] = ft_memalloc(ft_strlen(str[0]) - ok)))
			return (NULL);
		tab[i] = ft_strsub(str[i], j, ft_strlen(str[0]) - ok);
		i++;
	}
	tab[i] = NULL;
	ft_mat_del(str);
	return (tab);
}

char	**ft_resize3(char **str)
{
	int		i;
	char	**tab;
	int		ok;
	int		start;

	start = 0;
	i = 0;
	ok = ft_check_hor_length_down(str);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) *
									(ft_tablen(str) - ok + 1))))
		return (NULL);
	while (str[start] && start < ft_tablen(str) - ok)
	{
		if (!(tab[i] = ft_memalloc(ft_strlen(str[0]) + 1)))
			return (NULL);
		tab[i] = ft_strsub(str[start], 0, ft_strlen(str[start]));
		start++;
		i++;
	}
	tab[i] = NULL;
	ft_mat_del(str);
	return (tab);
}

char	**ft_resize4(char **str)
{
	int		i;
	int		j;
	char	**tab;
	int		ok;
	int		x;

	i = 0;
	ok = ft_check_vert_len_left(str);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		j = ok;
		x = 0;
		if (!(tab[i] = (char *)ft_memalloc(sizeof(char) *
					ft_strlen(str[0]) - ok)))
			return (NULL);
		tab[i] = ft_strsub(str[i], j, ft_strlen(str[0]));
		i++;
	}
	tab[i] = NULL;
	ft_mat_del(str);
	return (tab);
}
