/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:52:42 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:52:45 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	int		result;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (--n > 0 && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		result = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		return (result);
	}
}
