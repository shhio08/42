/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:57 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:58:17 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, char const *set)
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
	size_t	start;
	size_t	end;
	int		cnt;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (check_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && check_set(s1[end], set))
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (NULL);
	cnt = 0;
	while (start < end + 1)
		dest[cnt++] = s1[start++];
	dest[cnt] = '\0';
	return (dest);
}
