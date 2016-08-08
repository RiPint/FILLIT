/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 02:12:22 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/13 02:13:13 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_check_hor_len_high(char **str)
{
	int i;
	int j;
	int stop;
	int ok;

	ok = 0;
	stop = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '#')
				stop = 1;
			j++;
		}
		if (stop == 1)
			break ;
		ok = stop == 1 ? ok : ok + 1;
		j = 0;
		i++;
	}
	return (ok);
}

int		ft_check_vert_len_right(char **str)
{
	int i;
	int j;
	int stop;
	int ok;

	i = 0;
	j = ft_strlen(str[0]) - 1;
	stop = 0;
	ok = 0;
	while (stop != 1)
	{
		while (str[i])
		{
			if (str[i][j] == '#')
				stop = 1;
			i++;
		}
		if (stop == 1)
			break ;
		ok = stop == 1 ? ok : ok + 1;
		j--;
		i = 0;
	}
	return (ok);
}

int		ft_check_hor_length_down(char **str)
{
	int i;
	int j;
	int stop;
	int ok;

	ok = 0;
	stop = 0;
	i = ft_tablen(str) - 1;
	while (i >= 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#')
				stop = 1;
			j++;
		}
		ok = stop == 1 ? ok : ok + 1;
		if (stop == 1)
			break ;
		i--;
	}
	return (ok);
}

int		ft_check_vert_len_left(char **str)
{
	int i;
	int j;
	int stop;
	int ok;

	i = 0;
	j = 0;
	stop = 0;
	ok = 0;
	while (stop != 1)
	{
		while (str[i])
		{
			if (str[i][j] == '#')
				stop = 1;
			i++;
		}
		if (stop == 1)
			break ;
		ok = stop == 1 ? ok : ok + 1;
		j++;
		i = 0;
	}
	return (ok);
}
