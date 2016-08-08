/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:46:21 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:46:23 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree **root, void *data_ref,
											int (*cmpf)(void *, void *))
{
	t_btree	*result;

	result = NULL;
	if ((*root)->left)
		if ((result = ft_btree_search_item(&(*root)->left, data_ref, cmpf)))
			return (result);
	if (cmpf(data_ref, (*root)->content) == 0)
		return (*root);
	if ((*root)->right)
		if ((result = ft_btree_search_item(&(*root)->right, data_ref, cmpf)))
			return (result);
	return (NULL);
}
