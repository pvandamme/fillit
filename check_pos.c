/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:17:09 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/20 05:01:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_pos(char **map, int piece)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	piece++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '.')
				count++;
			j++;
		}
		i++;
	}
	if (count < piece * 4)
		return (0);
	return (1);
}
