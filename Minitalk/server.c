/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:20:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/07 15:45:47 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	signal_handler(int sig, siginfo_t *sa, void *content)
{
	static int	bit;
	static char	c;

	(void)content;
	if (sig == SIGUSR1)
		c += 1;
	bit++;
	if (bit == 8)
	{
		if (c == 4)
			kill(sa->si_pid, SIGUSR2);
		else
			kill(sa->si_pid, SIGUSR1);
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
		return ;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (sigemptyset(&sa.sa_mask) == -1)
		exit(1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
	while (1)
	{
		pause();
	}
	return (0);
}
