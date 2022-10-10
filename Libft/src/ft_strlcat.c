#include "libft.h"

int	count(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

size_t ft_strlcat (char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = count(dst);
	if (len >= size)
	{
		j = count((char *)src);
		return (j + size);
	}
	i = len;
	j = 0;
	while (i < (size - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + count((char *)src));
}

#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = "ABC";
	char str2[] = "12\0a34567890";
	char str3[100] = "ABC";
	char str4[] = "12\0a34567890";
	size_t size = 10;
	size_t len2 = strlcat(str3, str4, size);
	printf("ft_strlcat: %zu: %s\n", ft_strlcat(str1, str2, size), str1);
	printf("   strlcat: %zu: %s\n", len2, str3);
	return 0;
}
