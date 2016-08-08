/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:00:56 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:00:58 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)src);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == to_find[j] && src[i + j] && to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
