/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:45:46 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:45:49 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *content,
								size_t content_size, int (*f)(void *, void *))
{
	if (*root == NULL)
		ft_btree_create_node(content, content_size);
	else if ((*f)(content, (*root)->content) < 0)
		ft_btree_insert_data(&(*root)->left, content, content_size, f);
	else
		ft_btree_insert_data(&(*root)->right, content, content_size, f);
}
