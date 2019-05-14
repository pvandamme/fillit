# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/26 19:29:41 by tduval            #+#    #+#              #
#    Updated: 2018/11/20 04:48:05 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

HEADER		=	libft.h

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_strlen.c				\
				ft_strdup.c				\
				ft_strnew.c				\
				ft_strjoin.c			\
				ft_putchar.c			\
				ft_putstr.c				\
				ft_putendl.c

OBJ			=	$(SRC:.c=.o)

all : $(NAME)

$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

call	: all clean

re : fclean all

.PHONY : all clean fclean call re
