/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:57:36 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:57:09 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1_cnt;
	size_t	s2_cnt;

	if (!ft_strlen(s2))
		return ((char *)s1);
	if (!len)
		return (NULL);
	s1_cnt = 0;
	s2_cnt = 0;
	while (s1[s1_cnt] != '\0' && s1_cnt + ft_strlen(s2) <= len)
	{
		s2_cnt = 0;
		while (s1[s1_cnt + s2_cnt] == s2[s2_cnt])
		{
			if (s2[s2_cnt + 1] == '\0')
				return ((char *)&s1[s1_cnt]);
			s2_cnt++;
		}
		s1_cnt++;
	}
	return (NULL);
}
