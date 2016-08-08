/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrabox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:03:05 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/23 16:03:09 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_off	ft_find_first_sharp(char **str)
{
	t_off pos;

	pos.x = 0;
	pos.y = 0;
	while (str[pos.x])
	{
		while (str[pos.x][pos.y])
		{
			if (str[pos.x][pos.y] == '#')
				return (pos);
			pos.y++;
		}
		pos.y = 0;
		pos.x++;
	}
	return (pos);
}

int		ft_count_sharp(char **str)
{
	t_off	pos;
	int		nb;

	nb = 0;
	pos.x = 0;
	pos.y = 0;
	while (str[pos.x])
	{
		pos.y = 0;
		while (str[pos.x][pos.y])
		{
			if (str[pos.x][pos.y] != '#' && str[pos.x][pos.y] != '.' &&
					str[pos.x][pos.y] != '\0')
				return (-1);
			if (str[pos.x][pos.y] == '#')
				nb++;
			pos.y++;
		}
		pos.x++;
	}
	if (nb != 4)
		return (-1);
	else
		return (0);
}

void	ft_dup_line(char **tab, char **line)
{
	*tab = ft_strdup(*line);
	free(*line);
	*line = NULL;
}

int		ft_file_parser(int fd, t_tetra **list)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * 5)))
		return (-1);
	tab[4] = NULL;
	while (i != -1 && i != -2)
	{
		i = (get_next_line(fd, &line) != 0 ? i : -2);
		if (ft_strlen(line) == 4 && i >= 0)
			tab[i++] = ft_strdup(line);
		else if (ft_strlen(line) == 0 && (i == 4 || i == -2))
		{
			i = (i == -2 ? -2 : 0);
			if (ft_check_error(list, tab) < 0)
				i = -1;
		}
		else
			i = -1;
	}
	return (i == -1 ? i : 0);
}
