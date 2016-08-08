/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:47:29 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:47:31 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_is_stick(char **str)
{
	t_off	pos;

	pos = ft_find_first_sharp(str);
	if (str[pos.x][pos.y] == '\0')
		return (-1);
	if (pos.y == 0 && str[pos.x][pos.y + 1] == '#' &&
			str[pos.x][pos.y + 2] == '#' && str[pos.x][pos.y + 3] == '#')
		return (1);
	if (pos.x == 0 && str[pos.x + 1][pos.y] == '#' &&
			str[pos.x + 2][pos.y] == '#' && str[pos.x + 3][pos.y] == '#')
		return (1);
	return (0);
}

int		ft_is_square(char **str)
{
	t_off pos;

	pos = ft_find_first_sharp(str);
	if (str[pos.x][pos.y] == '\0')
		return (-1);
	if (pos.x < 3 && pos.y < 3 && str[pos.x][pos.y + 1] == '#' &&
			str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y + 1] == '#')
		return (1);
	return (0);
}

int		ft_is_l(char **str)
{
	t_off pos;

	pos = ft_find_first_sharp(str);
	if (str[pos.x][pos.y] == '\0')
		return (-1);
	if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 2][pos.y] == '#' && str[pos.x + 2][pos.y + 1] == '#')
		return (1);
	if (pos.x < 3 && pos.y > 1 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 1][pos.y - 2] == '#')
		return (1);
	if (pos.x < 2 && pos.y < 3 && str[pos.x][pos.y + 1] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y + 1] == '#')
		return (1);
	if (ft_is_l_second(str, pos) == 1)
		return (1);
	return (0);
}

int		ft_is_t(char **str)
{
	t_off pos;

	pos = ft_find_first_sharp(str);
	if (str[pos.x][pos.y] == '\0')
		return (-1);
	if (pos.x < 3 && pos.y > 0 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 1][pos.y - 1] == '#')
		return (1);
	if (pos.x < 2 && pos.y > 0 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 2][pos.y] == '#')
		return (1);
	if (pos.x < 3 && pos.x > 0 && pos.y < 2 && str[pos.x][pos.y + 1] == '#' &&
		str[pos.x][pos.y + 2] == '#' && str[pos.x + 1][pos.y + 1] == '#')
		return (1);
	if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y] == '#')
		return (1);
	return (0);
}

int		ft_is_sharp(char **str)
{
	t_off pos;

	pos = ft_find_first_sharp(str);
	if (str[pos.x][pos.y] == '\0')
		return (-1);
	if (pos.y < 3 && pos.x < 3 && str[pos.x][pos.y + 1] == '#' &&
		str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y] == '#')
		return (1);
	if (pos.y < 2 && pos.x < 3 && str[pos.x][pos.y + 1] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 1][pos.y + 2] == '#')
		return (1);
	if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y + 1] == '#')
		return (1);
	if (pos.y > 0 && pos.x < 2 && str[pos.x + 1][pos.y] == '#' &&
		str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 2][pos.y - 1] == '#')
		return (1);
	return (0);
}
