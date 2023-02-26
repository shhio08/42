/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:19:10 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 18:19:20 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	*stack = (*stack)->next;
	while ((*stack)->top != 1)
	{
		tmp = (*stack);
		free(*stack);
		*stack = tmp->next;
	}
	free(*stack);
}

char	**ft_free(char **dest)
{
	size_t	cnt;

	cnt = 0;
	while (dest[cnt])
		free(dest[cnt++]);
	free(dest);
	return (NULL);
}

static void	check_long(long num, char c, int minus)
{
	int	flag;

	flag = 0;
	if (INT_MAX / 10 < num && c && minus == 1)
		flag = 1;
	else if (INT_MAX / 10 == num && INT_MAX % 10 < c - '0' && minus == 1)
		flag = 1;
	else if (INT_MIN / 10 > -num && c && minus == -1)
		flag = 1;
	else if (INT_MIN / 10 == -num && INT_MIN % 10 > -(c - '0') && minus == -1)
		flag = 1;
	if (flag == 1)
		error("Error\n");
}

int	ps_atoi(const char *str)
{
	long	num;
	size_t	cnt;
	int		minus;

	num = 0;
	cnt = 0;
	minus = 1;
	while ((str[cnt] >= '\t' && str[cnt] <= '\r') || str[cnt] == ' ')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
	{
		if (str[cnt++] == '-')
			minus = -1;
	}
	if (!str[cnt])
		error("Error\n");
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = num * 10 + (str[cnt++] - '0');
		check_long(num, str[cnt], minus);
	}
	if (str[cnt])
		error("Error\n");
	num *= minus;
	return ((int)num);
}
