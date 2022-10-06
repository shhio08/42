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

#include <stdio.h>
int main()
{
	char str[] = "01234567";
	ft_memset(str+1, '*', 3);
	printf("%s", str);
}



// #include <string.h>
// int main()
// {
// 	char str[] = "01234567";
// 	memset(str+3, '*', 4);
// 	printf("%s", str);
// }