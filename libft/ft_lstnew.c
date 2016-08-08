/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:50:34 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:50:35 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = (t_list *)ft_memalloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = NULL;
	result->next = NULL;
	if (!content)
		result->content_size = 0;
	else
	{
		result->content = (void *)ft_memalloc(content_size);
		if (result->content)
		{
			ft_memcpy(result->content, content, content_size);
			result->content_size = content_size;
		}
	}
	return (result);
}
