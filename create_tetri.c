/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:56:08 by tduval            #+#    #+#             */
/*   Updated: 2018/11/20 04:02:56 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	***fill_tetri(char ***tetri, char *str)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	l = 0;
	while (tetri[i])
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				tetri[i][j][k] = str[l];
				l++;
			}
			l++;
		}
		l++;
		i++;
	}
	free(str);
	return (tetri);
}

char		***create_tetri(char *str, int t)
{
	char	***tetri;
	int		d;
	int		i;
	int		j;

	d = 0;
	i = 0;
	if (!(tetri = (char ***)malloc(sizeof(char **) * (t + 1))))
		return (0);
	while (i < t)
	{
		j = 0;
		if (!(tetri[i] = (char **)malloc(sizeof(char *) * 4)))
			return (0);
		while (j < 4)
		{
			if (!(tetri[i][j] = (char *)malloc(sizeof(char) * 4)))
				return (0);
			j++;
		}
		i++;
	}
	tetri[i] = 0;
	return (tetri = fill_tetri(tetri, str) ? tetri : 0);
}
