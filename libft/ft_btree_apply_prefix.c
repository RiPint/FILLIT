/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:44:07 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:44:09 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix(t_btree **root, void (*f)(void *))
{
	f((*root)->content);
	if ((*root)->left)
		ft_btree_apply_prefix(&(*root)->left, f);
	if ((*root)->right)
		ft_btree_apply_prefix(&(*root)->right, f);
}
