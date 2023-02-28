# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:22:25 by stakimot          #+#    #+#              #
#    Updated: 2023/02/28 20:44:39 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

SRC		=	main.c utils.c
OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C get_next_line
	$(CC) $(CLFAGS) -o $@ $^ get_next_line/gnl.a

clean:
	make clean -C get_next_line
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C get_next_line
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
