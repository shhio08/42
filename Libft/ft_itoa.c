/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:46 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/23 13:49:45 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *str;
	int num;
	int digit;
	int i;

	num = n;
	digit = 0;
	i = 0;
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	num = n;
	if (n < 0)
	{
		num *= -1;
		digit++;
	}
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[digit--] = '\0';
	while (digit >= 0)
	{
		// printf("%d %d\n", digit, num);
		str[digit--] = num % 10 + '0';
		num /= 10; 
	}
	return (str);
}
