/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:38:15 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:49:02 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	cnt;

	if (!dst && src && !size)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len >= size)
		return (ft_strlen(src) + size);
	cnt = 0;
	while (len + cnt + 1 < size && src[cnt])
	{
		dst[len + cnt] = src[cnt];
		cnt++;
	}
	dst[len + cnt] = '\0';
	return (len + ft_strlen(src));
}
