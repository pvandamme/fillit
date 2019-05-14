/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:26:41 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/20 04:15:31 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_size(char ***tetri)
{
	int		nb_tetri;
	int		i;

	i = 2;
	nb_tetri = 0;
	while (tetri[nb_tetri])
		nb_tetri++;
	while (i * i < (nb_tetri * 4))
		i++;
	return (i);
}

int		get_bot(char ***tetri, int piece)
{
	int	i;
	int	j;

	i = 3;
	while (i > -1)
	{
		j = 3;
		while (j > -1)
		{
			if (tetri[piece][i][j] == '#')
				return (i);
			j--;
		}
		i--;
	}
	return (0);
}
