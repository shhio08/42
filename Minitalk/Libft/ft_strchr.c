/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:32:36 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 14:48:09 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == (char)c)
			return ((char *)&s[cnt]);
		cnt++;
	}
	if (!c)
		return ((char *)&s[cnt]);
	return (0);
}
