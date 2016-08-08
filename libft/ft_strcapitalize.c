/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:56:31 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:56:33 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int i;

	i = 1;
	if (s)
	{
		ft_strtodowncase(s);
		s[0] = ft_toupper(s[0]);
		while (s[i])
		{
			if (ft_iswhitespace(s[i - 1]))
				s[i] = ft_toupper(s[i]);
			else
				s[i] = ft_tolower(s[i]);
			i++;
		}
	}
	return (s);
}
