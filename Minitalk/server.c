/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:20:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/06 10:35:56 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	signal_handler(int sig, siginfo_t *sa, void *content)
{
	ft_putstr_fd("test", 1);
	return;
}

int main()
{
	struct sigaction	sa;

	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (sigemptyset(&sa.sa_mask) == -1)
		exit(1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
		pause();
	}
	return (0);
}