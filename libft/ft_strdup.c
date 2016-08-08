/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:57:53 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:57:54 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;

	result = (char *)ft_memalloc(sizeof(char) * ft_strlen(s) + 1);
	if (result)
		ft_strcpy(result, s);
	return (result);
}
