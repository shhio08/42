/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:09:17 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/28 20:41:34 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return ;
	while (s[cnt])
	{
		write(fd, &s[cnt], 1);
		cnt++;
	}
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	cnt;

// 	cnt = 0;
// 	while (str[cnt])
// 		cnt++;
// 	return (cnt);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*dest;
// 	char	*src;
// 	size_t	cnt;

// 	src = (char *)s1;
// 	cnt = ft_strlen(s1);
// 	dest = (char *)malloc(sizeof(char) * (cnt + 1));
// 	if (!dest)
// 		return (NULL);
// 	cnt = 0;
// 	while (src[cnt])
// 	{
// 		dest[cnt] = src[cnt];
// 		cnt++;
// 	}
// 	dest[cnt] = '\0';
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t	cnt;

// 	cnt = 0;
// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!dest)
// 		return (NULL);
// 	while (*s1)
// 		dest[cnt++] = *s1++;
// 	while (*s2)
// 		dest[cnt++] = *s2++;
// 	dest[cnt] = '\0';
// 	return (dest);
// }

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
