/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:37:50 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 15:38:23 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack, int flag)
{
	(*stack)->top = 0;
	(*stack)->prev->top = 1;
	*stack = (*stack)->prev;
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rrb\n", 1);
}
