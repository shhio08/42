/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:57 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 11:16:13 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int flag)
{
	int	tmp;

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

void	push(t_stack **m_stack, t_stack **s_stack, int flag)
{
	t_stack	*tmp;

	if (!*m_stack)
		return ;
	if (!*s_stack)
	{
		*s_stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*s_stack)
			error("error");
		(*s_stack)->num = (*m_stack)->num;
		(*s_stack)->top = 1;
		(*s_stack)->prev = *s_stack;
		(*s_stack)->next = *s_stack;
	}
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->num = (*m_stack)->num;
		tmp->next = *s_stack;
		tmp->prev = (*s_stack)->prev;
		tmp->top = 1;
		(*s_stack)->top = 0;
		(*s_stack)->prev = tmp;
		tmp->prev->next = tmp;
		*s_stack = tmp;
	}
	if ((*m_stack)->next->top == 1)
	{
		free(*m_stack);
		*m_stack = NULL;
	}
	else
	{
		tmp = *m_stack;
		*m_stack = (*m_stack)->next;
		(*m_stack)->prev = tmp->prev;
		tmp->prev->next = *m_stack;
		(*m_stack)->top = 1;
		free(tmp);
	}
	if (flag == 1)
		ft_putstr_fd("pa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("pb\n", 1);
}
