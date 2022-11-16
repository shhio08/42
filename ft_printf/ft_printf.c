/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:29 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/10 19:09:11 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char c, va_list lst)
{
	int	cnt;

	cnt = 1;
	if (c == 'c')
		cnt = put_char(va_arg(lst, int));
	else if (c == 's')
		cnt = put_str(va_arg(lst, char *));
	else if (c == 'p')
		cnt = put_pointer(va_arg(lst, unsigned long long));
	else if (c == 'd' || c == 'i')
		cnt = put_num(va_arg(lst, int));
	else if (c == 'u')
		cnt = u_put_num(va_arg(lst, unsigned int));
	else if (c == 'x')
		cnt = change_base(va_arg(lst, unsigned int), 0);
	else if (c == 'X')
		cnt = change_base(va_arg(lst, unsigned int), 1);
	else if (c == '%')
		cnt = put_char(c);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		cnt;
	int		num;
	int		byte;

	cnt = 0;
	num = 0;
	va_start(lst, format);
	while (format[cnt])
	{
		if (format[cnt] == '%')
			byte = check_type(format[++cnt], &lst);
		else
			byte = write(1, &format[cnt], 1);
		if (byte == -1)
			return (0);
		num += byte;
		cnt++;
	}
	va_end(lst);
	return (num);
}
