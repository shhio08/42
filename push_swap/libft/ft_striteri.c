/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:37:00 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:36:14 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	cnt;

	cnt = 0;
	if (!s || !f)
		return ;
	while (s[cnt])
	{
		f(cnt, &s[cnt]);
		cnt++;
	}
}
