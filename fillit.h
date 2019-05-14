/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:06:45 by tduval            #+#    #+#             */
/*   Updated: 2018/11/20 05:16:50 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 21

int		move_tetri(char ***tetri, char **map, int size, int piece);
char	**fill_map(char ***tetri, char **map);
int		check_pos(char **map, int piece);
int		check_buf(char *str, int r);
int		count_size(char ***tetri);
int		get_max(char ***tetri, int nb_tetri);
char	**init_map(int size);
void	print_map(char **map);
char	***create_tetri(char *str, int t);
void	sort_tetri(char ***tetri);
void	print_tetri(char ***tetri);
char	**create_map(char ***tetri, char **map);
char	***read_tetri(const int fd);
int		get_bot(char ***tetri, int piece);
void	reset(char **map, int piece);

#endif
