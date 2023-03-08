# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:22:25 by stakimot          #+#    #+#              #
#    Updated: 2023/03/08 11:00:39 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

SRC		=	main.c map.c check.c mlx_setup.c image.c move.c utils.c
OBJ		=	$(SRC:.c=.o)
MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C get_next_line
	make -C ft_printf
	$(CC) $(CLFAGS) -o $@ $^ get_next_line/gnl.a ft_printf/libftprintf.a $(MLXFLAG)

clean:
	make clean -C get_next_line
	make clean -C ft_printf
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C get_next_line
	make fclean -C ft_printf
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
