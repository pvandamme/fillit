/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 02:30:48 by tduval            #+#    #+#             */
/*   Updated: 2018/11/24 03:19:38 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

static void	free_all(char **map, char ***tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (j < 4)
		{
			free(tetri[i][j]);
			j++;
		}
		free(tetri[i]);
		i++;
	}
	free(tetri);
}

static int	print_all(char ***tetri)
{
	int		i;
	char	**map;

	map = 0;
	i = 0;
	sort_tetri(tetri);
	if (!(map = create_map(tetri, map)))
		return (0);
	if (!(map = fill_map(tetri, map)))
		return (0);
	print_map(map);
	free_all(map, tetri);
	return (1);
}

int			main(int ac, char **av)
{
	char	***tetri;
	int		i;
	int		fd;

	tetri = 0;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		if ((tetri = read_tetri(fd)))
		{
			if (!(print_all(tetri)))
				ft_putstr("error\n");
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit description_file\n");
	i = 0;
	close(fd);
	return (0);
}
