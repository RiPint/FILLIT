/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:54:36 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 15:54:38 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr_fd(void *ptr, int fd)
{
	unsigned long int	addr;
	unsigned long int	div;
	char				temp;

	addr = (unsigned long int)ptr;
	div = 1;
	ft_putstr_fd("0x", fd);
	while (addr / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + addr / div;
		if (temp > '9')
			temp += 39;
		ft_putchar_fd(temp, fd);
		addr %= div;
		div /= 16;
	}
}
