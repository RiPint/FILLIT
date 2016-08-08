/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:43:54 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:43:57 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree **root, void (*f)(void *))
{
	if ((*root)->left)
		ft_btree_apply_infix(&(*root)->left, f);
	f((*root)->content);
	if ((*root)->right)
		ft_btree_apply_infix(&(*root)->right, f);
}
