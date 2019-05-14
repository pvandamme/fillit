/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 04:28:22 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/21 14:22:44 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

char		**init_map(int size)
{
	char	**new;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (size) + 1)))
		return (0);
	new[size] = 0;
	while (j < size)
	{
		if (!(new[j] = (char *)malloc(sizeof(char) * (size) + 1)))
			return (0);
		new[j][size] = 0;
		j++;
	}
	while (new[i])
	{
		j = 0;
		while (j < size)
			new[i][j++] = '.';
		i++;
	}
	return (new);
}

char		**create_map(char ***tetri, char **map)
{
	int		size;
	int		i;

	i = 0;
	size = count_size(tetri);
	while (tetri[i])
	{
		if (get_bot(tetri, i) > size)
			size = get_bot(tetri, i) + 1;
		i++;
	}
	if (!(map = init_map(size)))
		return (0);
	return (map);
}
