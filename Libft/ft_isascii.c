int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main(int c, char* v[])
{
	printf("%d", ft_isascii('v[1]'));
}