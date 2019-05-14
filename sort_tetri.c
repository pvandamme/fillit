/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 01:32:11 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/20 05:18:46 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	sort_tetri_right(char ***tetri, int piece, int i, int j)
{
	while (tetri[piece][0][0] != '#' && tetri[piece][1][0] != '#'
				&& tetri[piece][2][0] != '#' && tetri[piece][3][0] != '#')
	{
		i = 0;
		while (i < 4)
		{
			j = 1;
			while (j < 4)
			{
				if (tetri[piece][i][j] == '#')
				{
					tetri[piece][i][j] = '.';
					tetri[piece][i][j - 1] = '#';
				}
				j++;
			}
			i++;
		}
	}
}

static void	sort_tetri_top(char ***tetri, int piece, int i, int j)
{
	while (tetri[piece][0][0] != '#' && tetri[piece][0][1] != '#'
				&& tetri[piece][0][2] != '#' && tetri[piece][0][3] != '#')
	{
		i = 1;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (tetri[piece][i][j] == '#')
				{
					tetri[piece][i][j] = '.';
					tetri[piece][i - 1][j] = '#';
				}
				j++;
			}
			i++;
		}
	}
}

void		sort_tetri(char ***tetri)
{
	int piece;

	piece = 0;
	while (tetri[piece])
	{
		sort_tetri_top(tetri, piece, 0, 0);
		sort_tetri_right(tetri, piece, 0, 0);
		piece++;
	}
}
