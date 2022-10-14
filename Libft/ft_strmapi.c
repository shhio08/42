/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:25:02 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/14 14:56:42 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char f(unsigned int i, char c)
{
	char a;
	a = c + 1;
	return (a);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	int len;
	int i;

	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>
int main()
{
	char str[] = "ABC";
	printf("%s", ft_strmapi(str, *f));
}