/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:00:38 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:00:40 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		len;

	len = ft_strlen((char *)src);
	while (len != 0 && src[len] != (char)c)
		len--;
	if (src[len] == (char)c)
		return ((char *)&src[len]);
	return (NULL);
}
