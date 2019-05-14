# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 20:08:30 by tduval            #+#    #+#              #
#    Updated: 2019/05/15 00:17:35 by pvandamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	check_pos.c		\
			main.c			\
			fill_map.c		\
			move_tetri.c		\
			read_tetri.c		\
			sort_tetri.c		\
			util.c			\
			create_map.c		\
			check_buf.c		\
			create_tetri.c

OBJS	=	$(SRCS:.c=.o)

LIBFTA	=	libft/libft.a

CFLAGS	=	-Wall -Werror -Wextra

all			: $(NAME)

$(NAME) 	:	$(OBJS)
	$(MAKE) -C libft/
	gcc -o $(NAME) $(OBJS) $(LIBFTA)

clean 		:
	$(MAKE) -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
