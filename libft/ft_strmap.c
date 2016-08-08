/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:59:14 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:59:15 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (result)
	{
		while (s[i] != '\0')
		{
			result[i] = f(s[i]);
			i++;
		}
	}
	return (result);
}
