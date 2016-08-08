/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:58:43 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:58:45 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	result = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!result)
		return (NULL);
	ft_strncpy(result, s1, ft_strlen(s1));
	ft_strncat(result, s2, ft_strlen(s2));
	return (result);
}
