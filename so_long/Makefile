# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:22:25 by stakimot          #+#    #+#              #
#    Updated: 2023/03/21 19:28:26 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
AR			=	ar rcs

INC			=	-I inc/ -I $(GNL_DIR) -I $(PRT_DIR)
MLXFLAG		=	-lmlx -framework OpenGL -framework AppKit

SRC_DIR		=	src/
OBJ_DIR		=	objs/
GNL_DIR		=	get_next_line/
PRT_DIR		=	ft_printf/

SRC_NAME	=	main.c map.c check.c mlx_setup.c image.c move.c utils.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(GNL_DIR)
	make -C $(PRT_DIR)
	$(CC) $(CLFAGS) -o $@ $^ $(GNL_DIR)gnl.a $(PRT_DIR)libftprintf.a $(MLXFLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CLFAGS) $(INC) -Imlx -c $^ -o $@

clean:
	make clean -C $(GNL_DIR)
	make clean -C $(PRT_DIR)
	$(RM) $(OBJ_DIR)

fclean:	clean
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRT_DIR)
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
