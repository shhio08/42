/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/23 17:52:22 by stakimot         ###   ########.fr       */
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
	else if(first < second && second > third && first > third)
		reverse(a, 1);
}

void	five_sort(t_stack **a, t_stack **b, int len)
{
	int	cnt;
	int num;
	t_stack	*tmp;

	num = -1;
	while (len > 3)
	{
		cnt = 0;
		num++;
		tmp = *a;
		while ((*a)->num != num)
		{
			cnt++;
			*a = (*a)->next;
		}
		if (cnt == 0)
			push(a, b, 2);
		else
		{
			if ((len == 5 && cnt <= 2) || (len == 4 && cnt < 2))
			{
				while(cnt--)
					rotate(&tmp, 1);
			}
			else
			{
				while(cnt++ < len)
					reverse(&tmp, 1);
			}
			push(a, b, 2);
		}
		len--;
	}
	three_sort(a);
	while(num-- >= 0)
		push(b, a, 1);
}

int	blocking(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	b_size;
	int	init;
	int	size;

	b_size = len / 6;
	init = b_size;
	size = len - 1;
	while (1)
	{
		i = 0;
		while (i <= len)
		{
			if ((*a)->num <= b_size && (*a)->num != size)
			{
				push(a, b, 2);
				if ((*a)->next->top == 1)
					return (init);
				rotate(b, 2);
			}
			else if ((*a)->num <= b_size + init && (*a)->num != size)
				push(a, b, 2);
			else if ((*a)->next->top != 1)
				rotate(a, 1);
			if ((*a)->next->top == 1)
				return (init);
			i++;
		}
		b_size = b_size + (init * 2);
		len = len - (init * 2);
	}
	return (init);
}

void	others_sort(t_stack **a, t_stack **b, int len)
{
	int	cnt;
	int	middle;
	t_stack	*tmp;
	int	b_size;

	b_size = blocking(a, b, len);
	cnt = 0;
	len = len - 2;
	while (len > 0)
	{
		middle = len / 2;
		tmp = *b;
		while ((*b)->num != len && cnt <= middle && cnt < b_size * 2)
		{
			*b = (*b)->next;
			cnt++;
		}
		if ((*b)->num == len)
		{
			while (cnt--)
				rotate(&tmp, 2);
		}
		else
		{
			*b = tmp->prev;
			while ((*b)->num != len)
			{
				reverse(&tmp, 2);
				*b = (*b)->prev;
			}
			reverse(&tmp, 2);
		}
		push(b, a, 1);
		cnt = 0;
		len--;
	}
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