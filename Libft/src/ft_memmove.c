#include "libft.h"
void *ft_memmove(void *buf1, const void *buf2, size_t n)
{
	int i;
	char *dest;
	const char *src;

	i = 0;
	dest = buf1;
	src = buf2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>
int main(void)
{
        char str[] = "abcdefghijklmnopqrstu";
        
        printf("移動前：%s\n",str);
		
        ft_memmove(str+5, str, 10);

        printf("移動後：%s\n",str);

        return 0;
}