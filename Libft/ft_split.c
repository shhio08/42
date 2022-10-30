/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:00 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:31:48 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **dest)
{
	size_t	cnt;

	cnt = 0;
	while (dest[cnt])
		free(dest[cnt++]);
	free(dest);
	return (NULL);
}

static size_t	get_word(char const *s, char c)
{
	size_t	cnt;
	size_t	word;

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

static char	*set_word(int start, int end, char const *s)
{
	size_t	cnt;
	char	*dest;

	cnt = 0;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
		dest[cnt++] = s[start++];
	dest[cnt] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	s_cnt;
	size_t	start;
	size_t	d_cnt;

	s_cnt = 0;
	d_cnt = 0;
	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!dest)
		return (NULL);
	while (d_cnt < get_word(s, c))
	{
		while (s[s_cnt] == c)
			s_cnt++;
		start = s_cnt;
		while (s[s_cnt] != '\0' && s[s_cnt] != c)
			s_cnt++;
		dest[d_cnt] = set_word(start, s_cnt, s);
		if (!dest[d_cnt++])
			return (ft_free(dest));
	}
	dest[d_cnt] = NULL;
	return (dest);
}
