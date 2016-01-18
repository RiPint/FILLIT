/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recognize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emihoubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:42:24 by emihoubi          #+#    #+#             */
/*   Updated: 2016/01/18 17:20:26 by emihoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../libft/ft_strsplit.c"
#include "../libft/ft_strcmp.c"
void	recognize_def(int *i, int *y, int *x)
{
	*i = 0;
	*y = 0;
	*x = 0;
}

int		ft_add_tab(int *tab)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		res += tab[i];
		i++;
	}
	return (res);
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
	if(!(tmp = malloc(sizeof(int) * 4 + 1)))
		return (0);
	tab = ft_strsplit(str, '\n');
	while (y < 4)
	{
		if (ft_strcmp(tab[y], "####") == 0)
			return (1);
		y++;
	}
	y = 0;
	while (y < 4)
	{
		while (tab[y][x] == '#')
		{
			i++;
			y++;
		}
		if (i == 3)
			return (1);
		x++;
		i = 0;
	}
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
		while (i < 4)
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
			if (tmp[i] == 3)
			{
				printf("%s\n", "5 if");
				return (1);
			}
			printf("%s\n", "2eme boucle ope");
			i++;
			break ;
		}
	}
	i = 0;
	if (tmp[i] && tmp[i + 1] && tmp[i + 2] && tmp[i + 3] &&
		tmp[i] == 2 && (tmp[i + 1] == 2 || tmp[i + 2] == 2 || tmp[i + 3] == 2))
	{
		printf("%s\n", "1 if");
		return (1);
	}
	if (tmp[i + 1] && tmp[i + 2] && tmp[i + 3] &&
		tmp[i + 1] == 2 && (tmp[i + 2] == 2 || tmp[i + 3] == 2))
	{
		printf("%s\n", "1 if");
		return (1);
	}
	if (tmp[i + 2] && tmp[i + 3] && tmp[i + 2] == 2 && tmp[i + 3] == 2)
	{
		printf("%s\n", "1 if");
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

int	main()
{
	printf("%d\n", ft_recognize(".#..\n.#..\n.#..\n.#..\n"));
}
