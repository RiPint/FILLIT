/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:50:22 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:50:23 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;

	result = (t_list *)ft_memalloc(sizeof(result));
	if (!lst || !result)
		return (NULL);
	result = f(lst);
	result->next = ft_lstmap(lst->next, f);
	return (result);
}
