/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:46 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 14:56:15 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_digit(int n)
{
	long	num;
	int		digit;

	num = n;
	digit = 0;
	if (n <= 0)
	{
		num *= -1;
		digit++;
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		digit;

	digit = get_digit(n);
	num = n;
	if (n < 0)
		num *= -1;
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit--] = '\0';
	while (digit >= 0)
	{
		str[digit--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
