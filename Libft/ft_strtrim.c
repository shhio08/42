/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:57 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/27 12:51:06 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	int cnt;
	char *dest;

	start = 0;
	cnt = 0;
	while (1)
	{
		if(check_set(s1[start], set) == 0)
			break;
		start++;
	}
	end = ft_strlen(s1);
	while (1)
	{
		if(check_set(s1[end], set) == 0)
			break;
		end--;
	}
	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (NULL);
	while (start < end + 1)
		dest[cnt++] = s1[start++];
	dest[cnt] = '\0';
	return (dest);
}
