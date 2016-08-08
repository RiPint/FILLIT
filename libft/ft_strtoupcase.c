/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupcase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:02:06 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:02:08 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupcase(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	}
	return (s);
}