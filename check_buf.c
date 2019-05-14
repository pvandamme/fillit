/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:58:37 by tduval            #+#    #+#             */
/*   Updated: 2018/11/22 11:25:18 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static int	count_pattern(const char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i > 0)
				if (str[i - 1] == '#')
					k++;
			if (i < 19)
				if (str[i + 1] == '#')
					k++;
			if (i < 15)
				if (str[i + 5] == '#')
					k++;
			if (i > 4)
				if (str[i - 5] == '#')
					k++;
		}
		i++;
	}
	return (k);
}

static int	check_pattern(char *buf)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (20))))
		return (0);
	while (i < 20 && buf[i])
	{
		tmp[i] = buf[i];
		i++;
	}
	i = 0;
	k = count_pattern(tmp);
	free(tmp);
	return (k == 6 || k == 8);
}

static int	check_diezes(const char *str, int *j)
{
	int	d;

	d = 0;
	while (*j < 20)
	{
		if (str[*j] == '#')
			d++;
		if (str[*j] != '#' && str[*j] != '.' && ((*j + 1) % 5) != 0)
			return (0);
		if (str[*j] != '\n' && !((*j + 1) % 5))
			return (0);
		(*j)++;
	}
	return (d);
}

int			check_buf(char *str, int r)
{
	char	*tmp;
	char	*free_tmp;
	int		d;
	int		j;
	int		i;

	tmp = ft_strdup(str);
	free_tmp = tmp;
	i = 0;
	while (i < r)
	{
		j = 0;
		d = check_diezes(tmp, &j);
		if (d != 4 || (tmp[j] != '\n' && i + 1 < r) || (tmp[j] == '\n' && \
				!tmp[j + 1]) || !check_pattern(tmp))
		{
			free(free_tmp);
			return (0);
		}
		tmp += 21;
		i++;
	}
	free(free_tmp);
	return (1);
}
