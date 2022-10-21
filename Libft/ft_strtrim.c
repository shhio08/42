/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:57 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/21 16:43:03 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (0);
	}
	return (1);
}


char *ft_strtrim(char const *s1, char const *set)
{
	int start;
	int end;
	int count;
	char *dest;

	start = 0;
	end = 0;
	count = 0;
	while (!check_set(s1[start++], set));
	end = ft_strlen(s1);
	while (!check_set(s1[end--], set));
	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (0);
	while (start < end + 1)
		dest[count++] = s1[start++];
	dest[count] = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char s1[] = "1234AAA23A";
	char set[] = "1234";
	printf("%s", ft_strtrim(s1, set));
}