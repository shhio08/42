/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:18:22 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/09 13:03:41 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n && (s1[cnt] != '\0' || s2[cnt] != '\0'))
	{
		if (s1[cnt] != s2[cnt])
			return ((int)(s1[cnt] - (unsigned char)s2[cnt]));
		cnt++;
	}
	return (0);
}
