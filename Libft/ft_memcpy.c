/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:36:49 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/12 18:22:37 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t		cnt;
	char		*dest;
	const char	*src;

	cnt = 0;
	dest = (char *)buf1;
	src = (const char *)buf2;
	if (!buf1 && !buf2)
		return (NULL);
	while (cnt < n)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	return (dest);
}
