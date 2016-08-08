/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:47:40 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:47:44 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_is_l_second(char **str, t_off pos)
{
	if (pos.x < 3 && pos.y < 2 && str[pos.x][pos.y + 1] == '#' &&
			str[pos.x][pos.y + 2] == '#' && str[pos.x + 1][pos.y] == '#')
		return (1);
	if (pos.x < 2 && pos.y > 0 && str[pos.x + 1][pos.y] == '#' &&
			str[pos.x + 2][pos.y] == '#' && str[pos.x + 2][pos.y - 1] == '#')
		return (1);
	if (pos.x < 3 && pos.y < 2 && str[pos.x][pos.y + 1] == '#' &&
			str[pos.x][pos.y + 2] == '#' && str[pos.x + 1][pos.y + 2] == '#')
		return (1);
	if (pos.x < 2 && pos.y < 3 && str[pos.x][pos.y + 1] == '#' &&
			str[pos.x + 1][pos.y] == '#' && str[pos.x + 2][pos.y] == '#')
		return (1);
	if (pos.x < 3 && pos.y < 2 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 1][pos.y + 2] == '#')
		return (1);
	return (0);
}
