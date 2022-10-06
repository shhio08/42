#include "libft.h"
void *ft_memset(void *buf, int ch, size_t n)
{
	int i = 0;
	char *str;

	str = (char *)buf;
	while (i < n)
	{
		str[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

#include <stdio.h>
int main()
{
	char str[] = "012345";
	ft_bzero(str+5, 2);
	printf("%s", str);
}