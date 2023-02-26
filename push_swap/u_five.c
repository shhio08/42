/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_five.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:30:17 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 16:20:10 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third)
		swap(a, 1);
	else if (first > second && second > third && first > third)
	{
		swap(a, 1);
		reverse(a, 1);
	}
	else if (first > second && second < third && first > third)
		rotate(a, 1);
	else if (first < second && second > third && first < third)
	{
		swap(a, 1);
		rotate(a, 1);
	}
	else if (first < second && second > third && first > third)
		reverse(a, 1);
}

static void	five_spin(t_stack **a, t_stack **b, int cnt, int len)
{
	if ((len == 5 && cnt <= 2) || (len == 4 && cnt <= 1))
	{
		while (cnt--)
			rotate(a, 1);
	}
	else
	{
		while (cnt++ < len)
			reverse(a, 1);
	}
	push(a, b, 2);
}

void	five_sort(t_stack **a, t_stack **b, int len)
{
	int		cnt;
	int		num;
	t_stack	*tmp;

	num = 0;
	while (len-- > 3)
	{
		cnt = 0;
		tmp = *a;
		while (tmp->num != num)
		{
			cnt++;
			tmp = tmp->next;
		}
		if (cnt == 0)
			push(a, b, 2);
		else
			five_spin(a, b, cnt, len + 1);
		num++;
	}
	three_sort(a);
	while (num-- >= 0)
		push(b, a, 1);
}

void	divide(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		swap(a, 1);
	else if (len == 3)
		three_sort(a);
	else if (len == 4 || len == 5)
		five_sort(a, b, len);
	else
		others_sort(a, b, len);
}
