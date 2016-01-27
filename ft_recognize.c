/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recognize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emihoubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:42:24 by emihoubi          #+#    #+#             */
/*   Updated: 2016/01/21 15:24:08 by emihoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "../libftverif/libft.h"
#include "../libftverif/ft_strsplit.c"
#include "../libftverif/ft_strcmp.c"

void	recognize_def(int *i, int *y, int *x)
{
	*i = 0;
	*y = 0;
	*x = 0;
}

int		ft_recognize(char *str)
{
	char **tab;
	int x;
	int y;
	int i;
	int *tmp;

	/*recognize_def(&i, &y, &x);*/
	x = 0;
	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '\n')
			i++;
		if (str[i] == '#')
		{
			x++;
			i++;
		}
	}
	if (x != 4)
		return (-1);
	if(!(tmp = malloc(sizeof(int) * 5)))
		return (0);
	tab = ft_strsplit(str, '\n');
	while (y < 4)
	{
		if (ft_strcmp(tab[y], "####") == 0)
			return (1);
		if (ft_strcmp(tab[y], "....") == 0)
			i++;
		if (i == 4)
			return (-1);
		y++;
	}
	if (ft_strcmp(tab[0], tab[1]) == 0 && ft_strcmp(tab[2], tab[3]) == 0
		&& ft_strcmp(tab[0], tab[3]) == 0)
		return (1);
	y = 0;
	x = 0;
	i = 0;
	while (str && i < 4)
	{
		while (tab[y][x] == '.')
		{
			x++;
			if (tab[y][x] == '\0')
			{
				y++;
				x = 0;
			}
		}
		while (i < 4 && x < 4 && y < 4)
		{
			if (tab[y][x] == '#' && x > 0 && y > 0)
			{
				if (tab[y][x - 1] == '#')
				{
					printf("%s\n", "2 if");
					tmp[i] += 1;
				}
				if (tab[y - 1][x] == '#' && tab[y - 1][x] && (y - 1 != -1))
				{
					printf("%s\n", "4 if");
					tmp[i] += 1;
				}
			}
			if (tab[y][x] == '#' && x < 4)
				{
					if (tab[y][x + 1] == '#' && tab[y][x + 1] && (x + 1 < 4))
					{
						printf("%s\n", "1 if");
						tmp[i] += 1;
					}
					if (tab[y + 1][x] == '#' && tab[y + 1][x] && (y + 1 < 4))
					{
						printf("%s\n", "3 if");
						tmp[i] += 1;
					}
				}
			/*if (tmp[i] == 3)

			{
				printf("%s\n", "5 if");
				return (1);
				}*/
			printf("%d\n", tmp[i]);
			/*if (x < 4)
				x++;*/
			if (tmp[i] != 1)
				i++;
			break ;
		}
	}
	if (tmp[0] == 3 || tmp[1] == 3 || tmp[2] == 3 || tmp[3] == 3)
	{
		printf("%s\n", "New if");
		return (1);
	}
	if (tmp[0] && tmp[1] && tmp[2] && tmp[3] &&
		tmp[0] == 2 && (tmp[1] == 2 || tmp[2] == 2 || tmp[3] == 2))
	{
		printf("%s\n", "6 if");
		return (1);
	}
	if (tmp[1] && tmp[2] && tmp[3] &&
		tmp[1] == 2 && (tmp[2] == 2 || tmp[3] == 2))
	{
		printf("%s\n", "7 if");
		return (1);
	}
	if (tmp[2] && tmp[3] && tmp[2] == 2 && tmp[3] == 2)
	{
		printf("%s\n", "8 if");
		return (1);
	}
	return (-1);
}
/*	if (tab[y][x] == '#')
	{
		if (tab[y + 1][x] == '#')
		{
			if (tab[y + 2][x] == '#')
			{
				if (tab[y + 3][x] == '#')
					return (1);
				if (tab[y + 2][x + 1] == '#')
					return (1);
				if (tab[y + 2][x - 1] == '#')
					return (1);
			}
		}
	}
	return (-1);
}
*/

int	main(void)
{
	printf("%d\n", ft_recognize(".#..\n.#..\n.#..\n.#..\n"));
}
