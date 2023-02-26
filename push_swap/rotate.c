/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:37:01 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 15:37:14 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int flag)
{
	(*stack)->top = 0;
	(*stack)->next->top = 1;
	*stack = (*stack)->next;
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 3);
	ft_putstr_fd("rr\n", 1);
}
