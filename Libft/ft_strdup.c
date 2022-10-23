/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:45:01 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/23 13:47:23 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;
	char *src;
	int i;
	int j;

	src = (char *)s1;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i);
	if (!dest)
		return (0);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
