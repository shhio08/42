/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:38:41 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 18:06:05 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sub_push(t_stack **m_stack, t_stack **s_stack)
{
	t_stack	*tmp;

	if (!*s_stack)
	{
		*s_stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*s_stack)
			error("Error\n");
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
}

void	push(t_stack **m_stack, t_stack **s_stack, int flag)
{
	t_stack	*tmp;

	if (!*m_stack)
		return ;
	sub_push(m_stack, s_stack);
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
