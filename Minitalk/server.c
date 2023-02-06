/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:20:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/04 15:51:00 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	signal_handler(int sig, struct sigaction sa, void *content)
{
	printf("test");
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
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	while (1)
	{
		pause();
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
	}
	return (0);
}