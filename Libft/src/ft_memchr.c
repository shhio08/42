/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:31:18 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/10 16:45:29 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		if (tmp[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
int main()
{
	char str[] = "AB\0CDEFG";
	printf("%s", ft_memchr(str, 'C', 5));
}