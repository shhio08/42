/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:00 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/21 19:40:03 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	int		word;
	char	**dest;
	int		i;
	int		j;
	int		k;

	cnt = 0;
	word = 0;
	i = 0;
	j = 0;
	k = 0;
	while (s[cnt])
	{
		if (s[cnt] != c && (s[cnt + 1] == c || s[cnt + 1] == '\0'))
			word++;
		cnt++;
	}
	dest = (char **)malloc(sizeof(char *) * (word + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c)
			i++;
		*dest = (char *)malloc(sizeof(char) * (i - j + 1));
		while (j < i)
			**dest++ = s[j++];
		**dest = '\0';
		*dest++;
	}
	*dest = NULL;
	*dest -= word;
	return (dest);
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	char str[] = "AAbBBbbCCC";
	char **lst = ft_split(str, 'c');
	printf("%s\n", *lst);
	// while (*lst)
	// {
	// 	printf("%s\n", *lst++);
	// }
	return 0;
}
