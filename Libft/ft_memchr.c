/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:31:18 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:17:53 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*tmp;

	cnt = 0;
	tmp = (unsigned char *)s;
	while (cnt < n)
	{
		if (tmp[cnt] == (unsigned char)c)
			return ((void *)&s[cnt]);
		cnt++;
	}
	return (0);
}
