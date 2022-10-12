int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}

#include <stdio.h>
int main()
{
	printf("%c", (char)ft_toupper('a'));
}