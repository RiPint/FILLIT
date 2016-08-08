/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:00:28 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:00:29 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	size_t	len;

	len = ft_strlen(to_find);
	if (!n)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)src);
	while (*src && n >= len)
	{
		if (*src == *to_find && ft_strncmp(src, to_find, len) == 0)
			return ((char *)src);
		src++;
		n--;
	}
	return (NULL);
}
