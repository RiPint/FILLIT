/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:44:20 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:44:23 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree **root, void (*f)(void *))
{
	if ((*root)->left)
		ft_btree_apply_suffix(&(*root)->left, f);
	if ((*root)->right)
		ft_btree_apply_suffix(&(*root)->right, f);
	f((*root)->content);
}
