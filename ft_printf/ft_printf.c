/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:29 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/05 16:25:15 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	put_str(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[cnt])
	{
		write (1, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	put_num(int n)
{
	char	*num;
	int		cnt;

	num = ft_itoa(n);
	cnt = put_str(num);
	free(num);
	return (cnt);
}

int	u_put_num(unsigned int n)
{
	char	*num;
	int		cnt;

	num = u_ft_itoa(n);
	cnt = put_str(num);
	free(num);
	return (cnt);
}

char	*u_ft_itoa(unsigned int n)
{
	char	*str;
	long	num;
	int		digit;

	digit = get_digit(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit--] = '\0';
	while (digit >= 0)
	{
		str[digit--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}


int	check_type(char c, va_list lst)
{
	int	cnt;

	cnt = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(lst, int), 1);
	else if (c == 's')
		cnt = put_str(va_arg(lst, char *));
	// else if (c == 'p')
	// 	cnt = va_arg(lst, void *);
	else if (c == 'd' || c == 'i')
		cnt = put_num(va_arg(lst, int));
	else if (c == 'u')
		cnt = u_put_num(va_arg(lst, unsigned int));
	// printf("%u\n", va_arg(lst, unsigned int));
	// else if (c == 'x')
	// 	cnt = va_arg(lst, int);
	// else if (c == 'X')
	// 	cnt = va_arg(lst, int);
	else if (c == '%')
		ft_putchar_fd(c, 1);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int	cnt;
	int	num;

	cnt = 0;
	num = 0;
	va_start(lst, format);
	while (format[cnt])
	{
		if (format[cnt] == '%')
		{
			cnt++;
			num += check_type(format[cnt], lst);
			cnt++;
		}
		else
		{
			write(1, &format[cnt], 1);
			cnt++;
			num++;
		}
	}
	va_end(lst);
	return (num);
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a = ft_printf("%c %s %d %%\n", 'c', NULL, 30);
	int b = printf("%c %s %d %%\n", 'c', NULL, 30);
	printf("%d %d\n", a, b);
	return 0;
}
