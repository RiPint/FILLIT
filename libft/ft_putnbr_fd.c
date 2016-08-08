/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flourme <flourme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:22:05 by flourme           #+#    #+#             */
/*   Updated: 2015/12/04 14:45:10 by flourme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	temp;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		temp = (long)nb * -1;
	}
	else
		temp = (long)nb;
	if (temp > 9)
		ft_putnbr_fd((temp / 10), fd);
	ft_putchar_fd((temp % 10) + '0', fd);
}
