/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:50:44 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:50:45 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstqueue(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst)
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}
