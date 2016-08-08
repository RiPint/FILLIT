/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:43:37 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:43:39 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isctrlchar(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r' || c == '\t') ? 1 : 0);
}

int			ft_atoi(const char *str)
{
	int			result;
	int			neg;

	neg = 1;
	result = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (ft_isctrlchar(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (result * neg);
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * neg);
}
