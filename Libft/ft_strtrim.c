/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:57 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/13 14:24:40 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int k;
	int count;
	char *dest;

	i = 0;
	k = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				count++;
				break;
			}
			j++;
		}
		i++;
		j = 0;
	}
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				dest[k] = s1[i];
				break;
			}
			j++;
		}
		i++;
		j = 0;
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char s1[] = "1234AAA23A";
	char set[] = "1234";
	printf("%s", ft_strtrim(s1, set));
}