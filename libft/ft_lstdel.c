/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:49:39 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:49:40 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next_one;

	if (alst != NULL)
	{
		temp = *alst;
		while (temp != NULL)
		{
			if (del != NULL)
				del(temp->content, temp->content_size);
			next_one = temp->next;
			free(temp);
			temp = next_one;
		}
		*alst = NULL;
	}
}
