/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:41 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/28 01:48:21 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t cnt;
	int tmp;

	cnt = 0;
	tmp = -1;
	while (s[cnt])
	{
		if (s[cnt] == (char)c)
			tmp = cnt;
		cnt++;
	}
	if (!c)
		return ((char *)&s[cnt]);
	if (tmp < 0)
		return (NULL);
	return ((char *)&s[tmp]);
}


// char	*ft_strrchr(const char *s, int c)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	if (!c)
// 		return ((char *)&s[i]);
// 	while (i >= 0)
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i--;
// 	}
// 	return (0);
// }
