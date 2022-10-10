PROGRAM = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

$(PROGRAM):$(OBJS)
	ar rcs $(PROGRAM) $(OBJS)

all:
	$(PROGRAM)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PROGRAM)

re: fclean all
