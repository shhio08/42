/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:19:31 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/08 15:22:32 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Libft/libft.h"

size_t	g_len;

void	send_signal(pid_t pid, char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	while (str[i])
	{
		cnt = 8;
		while (cnt--)
		{
			if (str[i++] >> cnt & 1)
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
			ft_putendl_fd("成功だよ〜^^", 1);
		else
			ft_putendl_fd("失敗だよ〜^^;", 1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	g_len = ft_strlen(argv[2]);
	if (argc != 3 || !g_len || argv[1][0] == '-')
		exit(1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, recieve_signal);
	signal(SIGUSR2, recieve_signal);
	send_signal(pid, argv[2]);
	return (0);
}
