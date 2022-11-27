#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif