/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:32:36 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/10 15:06:16 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

#include <stdio.h>
int main()
{
	char str[] = "ABCDEFG";
	printf("%s", ft_strchr(str, 'C'));
}