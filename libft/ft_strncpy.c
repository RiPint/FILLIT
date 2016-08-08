/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:59:53 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:59:54 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*temp;

	temp = dest;
	while (n > 0 && *src != '\0')
	{
		*temp++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*temp++ = '\0';
		--n;
	}
	return (dest);
}
