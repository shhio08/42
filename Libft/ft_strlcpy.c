#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

#include <stdio.h>
int main(){
	char str1[] = "ABCDEFGHIJKLMN";
 	char str2[] = "12345678";
	printf("%s %s\n", str1, str2);
	printf("%zu\n", ft_strlcpy(str1, str2, 6));
	printf("%s %s\n", str1, str2);
	return 0;
}