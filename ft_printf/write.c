/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:48:53 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/06 19:20:36 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	cnt;
	int	byte;

	cnt = 0;
	byte = 0;
	if (!str)
	{
		byte = write (1, "(null)", 6);
		return (byte);
	}
	while (str[cnt])
	{
		byte = write (1, &str[cnt], 1);
		if (byte == -1)
			return (-1);
		cnt += byte;
	}
	return (cnt);
}

int	put_char(char c)
{
	int	byte;

	byte = write(1, &c, 1);
	return (byte);
}
