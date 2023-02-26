/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:33:40 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 15:56:50 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_check(t_stack **a)
{
	if ((*a)->num > (*a)->next->next->num)
	{
		swap(a, 1);
		rotate(a, 1);
		swap(a, 1);
		reverse(a, 1);
		return (1);
	}
	else
		swap(a, 1);
	return (0);
}

void	back_check(t_stack **a, t_stack **b, int len)
{
	t_stack	*tmp;
	int		flag;

	flag = 0;
	tmp = (*b)->prev;
	while (tmp->num != len)
	{
		reverse(b, 2);
		if (tmp->num == len - 1)
		{
			push(b, a, 1);
			flag = 1;
		}
		else if (flag == 1 && tmp->num == len - 2)
			push(b, a, 1);
		tmp = tmp->prev;
	}
	reverse(b, 2);
	return ;
}

static void	front_push(t_stack **a, t_stack **b, int cnt, int len)
{
	int		flag;

	flag = 0;
	while (cnt-- > 0)
	{
		if ((*b)->num == len - 1)
		{
			push(b, a, 1);
			flag = 1;
			cnt--;
		}
		if (flag == 1 && (*b)->num == len - 2)
		{
			push(b, a, 1);
			cnt--;
		}
		rotate(b, 2);
	}
}

void	front_check(t_stack **a, t_stack **b, int block, int len)
{
	t_stack	*tmp;
	int		cnt;
	int		middle;

	tmp = *b;
	cnt = 0;
	middle = (len + 1) / 2;
	while (tmp->num != len && cnt < middle && cnt < block * 2)
	{
		tmp = tmp->next;
		cnt++;
	}
	if (tmp->num == len && cnt != 0)
		front_push(a, b, cnt, len);
	return ;
}
