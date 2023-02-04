/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:45:01 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:35:28 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*src;
	size_t	cnt;

	src = (char *)s1;
	cnt = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!dest)
		return (NULL);
	cnt = 0;
	while (src[cnt])
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);
}
