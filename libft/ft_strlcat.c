/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:58:55 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:58:56 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	s1_end;

	i = 0;
	while (dst[i] && i < n)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < n - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < n)
		dst[i] = '\0';
	return (s1_end + ft_strlen(src));
}
