/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:00:49 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:00:50 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int			count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			count++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (count);
}

static int	ft_strlenc(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	int			words;
	int			i;
	char		**result;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_count_words(s, c);
	result = (char **)ft_memalloc(sizeof(result) * (words + 1));
	if (result && words)
	{
		while (*s != '\0')
		{
			while (*s == c && *s != '\0')
				s++;
			result[i++] = ft_strsub(s, 0, ft_strlenc(s, c));
			s += ft_strlenc(s, c);
			while (*s == c && *s != '\0')
				s++;
		}
	}
	if (result)
		result[i] = 0;
	return (result);
}
