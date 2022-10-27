/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:41 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/28 01:34:35 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (!c)
		return ((char *)&s[i]);
	if (!j)
		return (NULL);
	return ((char *)&s[j]);
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
