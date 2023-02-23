/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:57 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/23 16:24:11 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int flag)
{
	int	tmp;

	while ((*stack)->top != 1)
		*stack = (*stack)->next;
	if (!stack || (*stack)->next->top == 1)
		return;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("sb\n", 1);
}

void	push(t_stack **m_stack, t_stack **s_stack, int flag)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!m_stack)
		return;
	if ((*m_stack)->next->top == 1)
	{
		(*m_stack)->next = (*s_stack);
		(*m_stack)->prev = (*s_stack)->prev;
		(*s_stack)->prev->next = (*m_stack);
		(*s_stack)->prev = (*m_stack);
		(*s_stack)->top = 0;
		*s_stack = *m_stack;
		*m_stack = NULL;
	}
	else
	{
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
	if (flag == 1)
		ft_putstr_fd("pa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("pb\n", 1);
}

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
