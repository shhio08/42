/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:45:51 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:18:29 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			cnt;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cnt = 0;
	while (cnt < n)
	{
		if (str1[cnt] != str2[cnt])
			return (str1[cnt] - str2[cnt]);
			cnt++;
	}
	return (0);
}
