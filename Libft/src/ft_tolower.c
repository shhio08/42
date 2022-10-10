int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

#include <stdio.h>
int main()
{
	printf("%c", (char)ft_tolower('D'));
}