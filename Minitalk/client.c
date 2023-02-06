/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:19:31 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/06 11:56:14 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Libft/libft.h"

void sent_signal(pid_t pid, char *str)
{
	int	i;
	int	cnt;

	i = 0;
	while (str[i])
	{
		cnt = 7;
		while (cnt-- >= 0)
		{
			if(str[i] >> cnt & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
				usleep(100);
		}
		i++;
	}
	return ;
	// while (cnt++ < 11)
	// 	kill(pid, SIGUSR2);
	// kill(pid, SIGUSR1);
	// while (cnt++ < 13)
	// 	kill(pid, SIGUSR2);
}



int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2)
		return (0);
	pid = ft_atoi((const char *)argv[1]);
	sent_signal(pid, argv[2]);
	return (0);
}