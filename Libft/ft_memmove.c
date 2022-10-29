/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:37:16 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 14:46:27 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (const char *)src;
	if (tmp_dest > tmp_src)
	{
		while (n > 0)
		{
			tmp_dest[n - 1] = tmp_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
