/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:59:31 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:59:33 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		dest_end;

	dest_end = ft_strlen(dest);
	i = dest_end;
	while (src[i - dest_end] && i - dest_end < n)
	{
		dest[i] = src[i - dest_end];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
