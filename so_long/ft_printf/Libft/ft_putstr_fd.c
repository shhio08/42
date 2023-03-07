/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:35:17 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/30 11:23:55 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return ;
	while (s[cnt])
	{
		ft_putchar_fd(s[cnt], fd);
		cnt++;
	}
}
