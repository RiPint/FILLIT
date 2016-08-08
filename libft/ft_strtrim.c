/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:02:18 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:02:19 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	lenght;
	char	*result;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s);
	while (ft_iswhitespace(s[i]) && s[i] != '\0')
		i++;
	if ((s[i]) == '\0')
		return (ft_strdup(""));
	while (ft_iswhitespace(s[lenght - 1]))
		lenght--;
	lenght -= i;
	result = ft_strnew(lenght);
	if (result && lenght > 1)
		result = ft_strsub(s, (unsigned int)i, lenght);
	return (result);
}
