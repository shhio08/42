# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 16:41:32 by stakimot          #+#    #+#              #
#    Updated: 2023/02/26 15:54:26 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

LIBFT	=	libft/libft.a

SRC		=	main.c stack.c compress.c sort.c u_five.c check.c utils.c swap.c rotate.c reverse.c push.c
OBJ		= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)
	make clean -C libft
	$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
