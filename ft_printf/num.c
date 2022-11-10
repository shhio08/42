/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:43:03 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/10 11:11:09 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	u_get_digit(unsigned int num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*u_ft_itoa(unsigned int num)
{
	char	*str;
	int		digit;

	digit = u_get_digit(num);
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
