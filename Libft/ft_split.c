/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:00 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 17:09:09 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **dest)
{
	int	cnt;

	cnt = 0;
	while (dest[cnt])
		free(dest[cnt++]);
	free(dest);
}

int	get_word(char const *s, char c)
{
	size_t	cnt;
	int		word;

	cnt = 0;
	word = 0;
	while (s[cnt])
	{
		if (s[cnt] != c && (s[cnt + 1] == c || s[cnt + 1] == '\0'))
			word++;
		cnt++;
	}
	return (word);
}

void	set_word(int start, int end, char const *s, char *dest)
{
	int cnt;

	cnt = 0;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!dest)
			return ;
	while (start < end)
		dest[cnt++] = s[start++];
	dest[cnt] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	word = get_word(s, c);
	dest = (char **)malloc(sizeof(char *) * (word + 1));
	if (!dest)
		return (NULL);
	while (k < word)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		set_word(j, i, s, dest[k]);
		if (!dest)
		{
			ft_free(dest);
			return (dest);
		}
		k++;
		// dest[k] = (char *)malloc(sizeof(char) * (i - j + 1));
		// if (!dest[k])
		// {
		// 	ft_free(dest);
		// 	return (dest);
		// }
		// l = 0;
		// while (j < i)
		// 	dest[k][l++] = s[j++];
		// dest[k++][l] = '\0';
	}
	dest[k] = NULL;
	return (dest);
}
