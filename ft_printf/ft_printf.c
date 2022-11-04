/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:29 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/04 14:48:22 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char *input, va_list lst)
{
	int	cnt;
	char	*str;

	while (*input++)
	{
		if (*input == "%")
			cnt += check_type(input[cnt], lst);
		else
		{
			cnt++;
			write(1, input[cnt], 1);
		}
	}
	return (cnt);
}

int	put_str(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		write (1, str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	put_void(void *a)
{
	
}

int	put_num(int n)
{
	char	num;
	int	cnt;
	
	num = ft_itoa(n);
	cnt = put_str(num);
	return (cnt);
}

int	check_type(char c, va_list lst)
{
	int	cnt;

	cnt = 1;
	if (c == "c")
		ft_putchar_fd(va_arg(lst, char), 1);
	else if (c == "s")
		cnt = put_str(va_arg(lst, char *));
	else if (c == "p")
		cnt = va_arg(lst, void *);
	else if (c == "d")
		cnt = put_num(va_arg(lst, int));
	else if (c == "i")
		cnt = va_arg(lst, int);
	else if (c == "u")
		cnt = va_arg(lst, unsigned int);
	else if (c == "x")
		cnt = va_arg(lst, int);
	else if (c == "X")
		cnt = va_arg(lst, int);
	else if (c == "%")
		cnt = 1;
	return (cnt);
}

int	ft_printf(const char *input, ...)
{
	va_list	lst;

	va_start(lst, input);
	check_format(input, lst);
}