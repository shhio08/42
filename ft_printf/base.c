/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:38 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/10 11:10:52 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_get_digit(unsigned int num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		digit++;
	}
	return (digit);
}

int	change_base(unsigned int num, int n)
{
	char	*str;
	int		digit;
	int		cnt;

	digit = base_get_digit(num);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	str[digit--] = '\0';
	while (digit >= 0)
	{
		str[digit] = num % 16;
		if (str[digit] < 10)
			str[digit] += '0';
		else if (str[digit] > 9 && n == 0)
			str[digit] += 'a' - 10;
		else if (str[digit] > 9 && n == 1)
			str[digit] += 'A' - 10;
		digit--;
		num /= 16;
	}
	cnt = put_str(str);
	free(str);
	return (cnt);
}

static int	pointer_get_digit(unsigned long long num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		digit++;
	}
	return (digit);
}

int	put_pointer(unsigned long long num)
{
	char	*str;
	int		digit;
	int		cnt;

	digit = pointer_get_digit(num);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (-1);
	str[digit--] = '\0';
	while (digit >= 0)
	{
		str[digit] = num % 16;
		if (str[digit] < 10)
			str[digit--] += '0';
		else if (str[digit] > 9)
			str[digit--] += 'a' - 10;
		num /= 16;
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	cnt = put_str(str);
	if (cnt == -1)
		return (-1);
	free(str);
	return (cnt + 2);
}
