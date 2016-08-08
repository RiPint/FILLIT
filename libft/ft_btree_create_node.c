/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:44:35 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:44:37 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *content, size_t content_size)
{
	t_btree	*result;

	result = (t_btree *)ft_memalloc(sizeof(t_btree));
	if (result)
	{
		result->content = NULL;
		result->left = NULL;
		result->right = NULL;
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
	}
	return (result);
}
