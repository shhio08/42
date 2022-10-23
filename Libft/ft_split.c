/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:00 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/23 13:56:07 by stakimot         ###   ########.fr       */
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
		while (s[i] != '\0' && s[i] != c)
			i++;
		dest[k] = (char *)malloc(sizeof(char) * (i - j + 1));
		int l = 0;
		while (j < i)
		{
			dest[k][l] = s[j];
			l++;
			j++;
		}
		dest[k][l] = '\0';
		k++;
	}
	dest[k] = NULL;
	return (dest);
}
