NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	ft_printf.c num.c write.c base.c
SRCS_OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(SRCS_OBJS)
	make -C Libft
	cp Libft/libft.a ./
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(SRCS_OBJS)

all:	$(NAME)

clean:
		rm -rf $(SRCS_OBJS)
		make clean -C Libft

fclean:	clean
		rm -rf $(NAME)
		rm -rf Libft/libft.a

re:		fclean $(NAME)

.PFONY:	all clean fclean re