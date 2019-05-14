/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 04:10:12 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 16:54:09 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*me;
	size_t	i;

	i = 0;
	if (!(me = ft_memalloc(sizeof(char) * (size + 1))))
		return (0);
	while (size--)
	{
		i++;
		me[i] = '\0';
	}
	return (me);
}
