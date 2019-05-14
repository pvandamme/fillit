/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:13:29 by tduval            #+#    #+#             */
/*   Updated: 2018/11/22 11:26:01 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

static char	*big_read(const int fd, int *ret, int *i)
{
	char	*tmp;
	char	*str;
	char	buf[22];

	str = 0;
	while ((*ret = read(fd, buf, 21)))
	{
		buf[*ret] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
		{
			if (!(tmp = ft_strjoin(str, buf)))
			{
				free(str);
				free(tmp);
				return (0);
			}
			free(str);
			str = tmp;
		}
		(*i)++;
	}
	return (str);
}

char		***read_tetri(const int fd)
{
	char	*str;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!(str = big_read(fd, &ret, &i)))
		return (0);
	if ((ret == 0 && i == 0) || ret == -1 || !check_buf(str, i))
	{
		free(str);
		return (0);
	}
	return (create_tetri(str, i));
}
