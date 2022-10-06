#include "libft.h"
size_t ft_strlen(const char *str)
{
	size_t cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

#include <stdio.h>
int main()
{
	printf("%zu", ft_strlen("asdfgh"));
}