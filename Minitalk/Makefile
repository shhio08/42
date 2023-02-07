# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:59:33 by stakimot          #+#    #+#              #
#    Updated: 2023/02/07 14:31:38 by stakimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

S_SRC	=	server.c
SERVER	=	server

C_SRC	=	client.c
CLIENT	=	client

LIBFT	=	Libft/libft.a

all:	libft server client

libft:
	make -C Libft

server:	$(S_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

client:	$(C_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	make clean -C Libft

fclean:
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C Libft

re: fclean all

.PHONY:	all libft server client clean fclean re