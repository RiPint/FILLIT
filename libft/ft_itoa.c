/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:49:10 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:49:12 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*result;
	int		temp_n;
	size_t	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = 2 + (n < 0);
	temp_n = n;
	while ((temp_n = temp_n / 10))
		size++;
	result = (char *)ft_strnew(sizeof(char) * --size);
	if (result)
	{
		if (n < 0)
			result[0] = '-';
		n = (n < 0) ? -n : n;
		result[size--] = '\0';
		result[size--] = n % 10 + '0';
		while ((n = n / 10))
			result[size--] = n % 10 + '0';
	}
	return (result);
}
