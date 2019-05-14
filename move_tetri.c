/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:32:39 by tduval            #+#    #+#             */
/*   Updated: 2018/11/20 04:57:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_place(char ***tetri, char **map, int size, int piece)
{
	int pos;
	int j;

	pos = 0;
	j = 0;
	while (pos < size * size)
	{
		if (map[pos / size][pos % size] == 'A' + piece)
		{
			while (tetri[piece][0][j] != '#')
				j++;
			return (pos + 1 - j);
		}
		pos++;
	}
	return (0);
}

static void	split_fun(char ***tetri, char **map, int piece, int *kl)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[piece][i][j] == '#')
			{
				if (map[i + kl[0]][j + kl[1]] == '.')
					map[i + kl[0]][j + kl[1]] = 'A' + piece;
			}
			j++;
		}
		i++;
	}
}

void		reset(char **map, int piece)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'A' + piece)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			move_tetri(char ***tetri, char **map, int size, int piece)
{
	int kl[2];
	int pos;

	kl[0] = 0;
	kl[1] = 0;
	if ((pos = check_place(tetri, map, size, piece)))
	{
		kl[0] = pos / size;
		kl[1] = pos % size;
		reset(map, piece);
	}
	while (!(check_pos(map, piece)))
	{
		reset(map, piece);
		if (kl[1] > size)
		{
			kl[1] = 0;
			kl[0]++;
		}
		if (get_bot(tetri, piece) + kl[0] == size)
			return (0);
		split_fun(tetri, map, piece, kl);
		kl[1]++;
	}
	return (1);
}
