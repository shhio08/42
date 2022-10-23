/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:07:46 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/23 13:57:40 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *dest;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)start)
			break;
		i++;
	}
	dest = malloc(len);
	if (!dest)
		return (0);
	while (j < len)
	{
		dest[j] = s[i + j];
		j++;
	}
	return (dest);
}
