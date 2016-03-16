/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_cutter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emihoubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:26:05 by emihoubi          #+#    #+#             */
/*   Updated: 2016/01/27 14:26:14 by emihoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*static void	tetri_def(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}*/

 static int	check(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		i++;
		if (str[i] == '\n' && str[i + 1] != '\n' && str[i + 1])
			j++;
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] != '\n'
		    && str[i + 1] && str[i + 2])
			j = 0;
		if (j > 3)
			return (-1);
		if (str[i] == '\n' && i != 3 + k * 5)
			return (-1);
		k++;
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n' &&
		    str[i + 1] && str[i + 2])
			return (-1);
	}
	return (1);
	}

char	**ft_tetri_cutter(char *str)
{
	char	**tab;
	int	i;
	int	j;
	int	k;

	if (check(str) != 1)
		return (NULL);
	printf("%s\n", "check ok");
	i = 0;
	j = 0;
	k = 0;
       	while (str[i] != '\n' && str[i])
       	{
       		i++;
		if (str[i] == '\n' && str[i + 1] == '\n')
			j++;
       	}
	printf("%s\n", "1st loop ok");
	if (!(tab = (char**)malloc(sizeof(char*) * j)))
		return (NULL);
	i = 0;
	while (k < j)
	{
		if (!(tab[k] = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		tab[k][20] = '\0';
		k++;
	}
	printf("%s\n", "malloc ok");
       	i = -1;
	j = 0;
	k = 0;
	while (str[i])
	{
		i++;
		while (str[i] != '\n')
		{
			tab[j][k] = str[i];
			i++;
			k++;
			if (str[i] == '\n' && str[i + 1] == '\n')
			{
				j++;
				k = 0;
			}
		}
	}
	return (tab);
}


int	main()
{
  int i;
  int j;
  int k;
  char **tab;

  i = 0;
  j = 0;
  k = 0;
  tab = ft_tetri_cutter("...#\n...#\n...#\n...#\n....\n....\n....\n####\n\n\n.###\n...#\n....\n....\n\n....\n..##\n.##.\n....\n\n");
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
}
