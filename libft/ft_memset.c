/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:53:43 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:53:44 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int	i;

	i = 0;
	while (len != 0)
	{
		((unsigned char *)str)[i] = c;
		i++;
		len--;
	}
	return ((void *)str);
}
