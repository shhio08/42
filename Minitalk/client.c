/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:19:31 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/12 14:41:57 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

size_t	g_len;

void	send_signal(pid_t pid, char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = -1;
	while (str[++i])
	{
		cnt = 8;
		while (cnt--)
		{
			if (str[i] >> cnt & 1)
				flag = kill(pid, SIGUSR1);
			else
				flag = kill(pid, SIGUSR2);
			if (flag == -1)
				exit(1);
			usleep(100);
		}
	}
	while (++cnt < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(100);
	}
}

void	recieve_signal(int sig)
{
	static size_t	cnt;

	if (sig == SIGUSR1)
		cnt++;
	if (sig == SIGUSR2)
	{
		if (cnt == g_len)
			ft_putendl_fd("Success", 1);
		else
			ft_putendl_fd("Error", 1);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !argv[2] || argv[1][0] == '-')
		exit(1);
	g_len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		exit(1);
	signal(SIGUSR1, recieve_signal);
	signal(SIGUSR2, recieve_signal);
	send_signal(pid, argv[2]);
	return (0);
}
