/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:57 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/18 17:20:03 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
}

void	push(t_stack **m_stack, t_stack **s_stack)
{
	t_stack	*tmp;

	tmp = (*m_stack)->next;
	(*m_stack)->next->prev = (*m_stack)->prev;
	(*m_stack)->prev->next = (*m_stack)->next;
	(*m_stack)->next->top = 1;
	if (!*s_stack)
	{
		(*m_stack)->next = *m_stack;
		(*m_stack)->prev = *m_stack;
	}
	else
	{
		(*m_stack)->next = *s_stack;
		(*m_stack)->prev = (*s_stack)->prev;
		(*s_stack)->prev->next = *m_stack;
		(*s_stack)->prev = *m_stack;
		(*s_stack)->top = 0;
	}
	*s_stack = *m_stack;
	*m_stack = tmp;
}

void	rotate(t_stack **stack)
{
	(*stack)->top = 0;
	(*stack)->next->top = 1;
	*stack = (*stack)->next;
}

void	reverse(t_stack **stack)
{
	(*stack)->top = 0;
	(*stack)->prev->top = 1;
	*stack = (*stack)->prev;
}
