/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:46:46 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:46:47 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	ft_check_error_second(char **str, int erret)
{
	if ((erret = ft_is_l(str)) && erret == 1)
		return (1);
	else if (erret == -1)
		return (-1);
	if ((erret = ft_is_sharp(str)) && erret == 1)
		return (1);
	else if (erret == -1)
		return (-1);
	if ((erret = ft_is_t(str)) && erret == 1)
		return (1);
	else if (erret == -1)
		return (-1);
	if ((erret = ft_is_square(str)) && erret == 1)
		return (1);
	else if (erret == -1)
		return (-1);
	if ((erret = ft_is_stick(str)) && erret == 1)
		return (1);
	else if (erret == -1)
		return (-1);
	return (0);
}

int	ft_check_error(t_tetra **list, char **str)
{
	int erret;

	erret = 0;
	if ((erret = ft_count_sharp(str)) && erret == -1)
		return (-1);
	if ((erret = ft_check_error_second(str, erret)) && erret == 1)
	{
		str = ft_resize1(str);
		str = ft_resize2(str);
		str = ft_resize3(str);
		str = ft_resize4(str);
		ft_tetra_add(list, str);
		return (1);
	}
	else if (erret == -1)
		return (-1);
	if (erret == 0)
		return (-1);
	return (-1);
}
