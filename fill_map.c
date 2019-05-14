/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:14:26 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/21 14:20:40 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		backtrack(char ***tetri, char **map, int size, int piece)
{
	int	i;

	i = 0;
	while (tetri[i])
		i++;
	if (piece == i)
		return (1);
	while (move_tetri(tetri, map, size, piece) > 0)
	{
		if (backtrack(tetri, map, size, piece + 1))
			return (1);
	}
	reset(map, piece);
	return (0);
}

char			**fill_map(char ***tetri, char **map)
{
	int		size;
	int		pos;
	int		i;

	pos = 0;
	size = count_size(tetri);
	while (backtrack(tetri, map, size, 0) == 0)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		size++;
		if (!(map = init_map(size)))
			return (0);
	}
	return (map);
}
