#include "libft.h"
void *ft_memcpy(void *buf1, const void *buf2, size_t n)
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
int main()
{
	char str1[128] = {1,1,1,1,1,1,1};
	char str2[] = "asdfgh";
	for (int i=0; i<7; i++)
		printf("%#x ",str1[i]);
    printf("\n");
	ft_memcpy(str1, str2, 4);
	for (int j=0; j<7; j++)
		printf("%#x ",str1[j]);
    printf("\n");
}