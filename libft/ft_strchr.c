/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:56:52 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:56:53 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != '\0')
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (*src == (char)c)
		return ((char *)src);
	return (NULL);
}
