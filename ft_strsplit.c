/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emihoubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:20:08 by emihoubi          #+#    #+#             */
/*   Updated: 2016/01/14 13:23:28 by emihoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			nwords(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != c)
		{
			i++;
			if (str[i] == c || str[i] == '\0')
			{
				count++;
				break ;
			}
		}
		while (str[i] == c)
			i++;
	}
	return (count);
}

static void			splitdef(int *j, int *k, int *i)
{
	*j = 0;
	*k = -1;
	*i = -1;
}

static	int			*nchar(char const *str, char c)
{
	int		i;
	int		j;
	int		*k;
	int		count;

	i = 0;
	j = 0;
	if (!(k = (int*)malloc(sizeof(*k) * (nwords(str, c) + 1))))
		return (NULL);
	while (str[i] && j < nwords(str, c))
	{
		count = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] && ++count >= 0)
		{
			i++;
			if (str[i] == c || str[i] == '\0')
				break ;
		}
		k[j] = count;
		j++;
	}
	k[j] = 0;
	return (k);
}

static char			**malloc_tab(char const *s, char c)
{
	char	**tab;
	int		*mtab;
	int		j;
	int		k;

	j = 0;
	k = -1;
	mtab = nchar(s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * nwords(s, c) + 1)))
		return (NULL);
	while (++k < nwords(s, c))
	{
		if (!(tab[j] = (char*)malloc(sizeof(char) * mtab[j] + 1)))
			return (NULL);
		j++;
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		i;
	int		k;

	splitdef(&j, &k, &i);
	j = 0;
	if (!(tab = malloc_tab(s, c)))
		return (NULL);
	while (s[i + 1] && j < nwords(s, c))
	{
		k = -1;
		while (s[i + 1] == c && s[i + 1])
			i++;
		while (s[i + 1] != c && s[i + 1])
			tab[j][++k] = s[++i];
		tab[j][k + 1] = '\0';
		j++;
	}
	tab[nwords(s, c)] = NULL;
	return (tab);
}
