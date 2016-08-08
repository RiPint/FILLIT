/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:45:58 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:46:08 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_level_count(t_btree **root)
{
	int		left;
	int		right;

	if (!*root)
		return (0);
	if ((*root)->left || (*root)->right)
	{
		left = ft_btree_level_count(&(*root)->left);
		right = ft_btree_level_count(&(*root)->right);
		return (1 + ((left > right) ? left : right));
	}
	else
		return (1);
}
