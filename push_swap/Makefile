# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 16:41:32 by stakimot          #+#    #+#              #
#    Updated: 2023/02/19 14:35:19 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

LIBFT	=	libft/libft.a

SRC		=	main.c swap.c stack.c utils.c compress.c sort.c
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