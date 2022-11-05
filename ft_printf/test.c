#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	// void *a = "3";
	// int addr = (int)&a;
	// printf("%p\n", a);
	// write(1, addr, 1);

	// printf("%u", -10);

	char c = 'A';
	write(1, &c, 1);
}