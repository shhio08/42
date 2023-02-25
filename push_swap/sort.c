/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/25 01:51:23 by stakimot         ###   ########.fr       */
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

int	block_judge(t_stack **a, t_stack **b, int b_size, int init)
{
	if ((*a)->num <= b_size)
	{
		push(a, b, 2);
		if ((*a)->next->top == 1)
			return (-1);
		rotate(b, 2);
	}
	else if((*a)->num <= b_size + init)
		push(a, b, 2);
	else if ((*a)->next->top != 1)
		rotate(a, 1);
	else
		return (-1);
	return (0);
}

// int	go_block(t_stack **a, t_stack **b, int border)
// {
// 	if ((*a)->num < border)
// 	{
// 		push(a, b, 2);
// 		if ((*a)->next->top == 1)
// 			return (-1);
// 		rotate(b, 2);
// 	}
// 	else
// 		push(a, b, 2);
// 	return (0);
// }

// int no_block(t_stack **a)
// {
// 	if ((*a)->next->top != 1)
// 		rotate(a, 1);
// 	else
// 		return (-1);
// 	return (0);
// }

int	blocking(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	b_size;
	int	init;
	int	size;

	b_size = len / (len / 50 + 4);
	init = b_size;
	size = len - 1;
	while (1)
	{
		i = -1;
		while (++i < len)
		{
			// print_stack(a, "a ");
			// print_stack(b, "b ");
			if ((*a)->num != size)
			{
				if (block_judge(a, b, b_size, init) != 0)
					return (init);
			}
			// else if ((*a)->next->top != 1)
			// 	rotate(a, 1);
			else if ((*a)->next->top != 1)
				rotate(a, 1);
			else
				return (init);
				// return (init);
			// if ((*a)->num <= b_size + init && (*a)->num != size)
			// {
			// 	if (go_block(a, b, b_size) != 0)
			// 		return (init);
			// }
			// else if (no_block(a) != 0)
			// 	return (init);
		}
		b_size = b_size + (init * 2);
		len = len - (init * 2);
	}
	return (init);
}

int	next_sort(t_stack **a, t_stack **b, int cnt, int *middle)
{
	while (cnt > 0)
	{
		rotate(b, 2);
		cnt--;
	}
	push(b, a, 1);
	return (cnt - 1);
	*middle -= 1;
}

void	back_check(t_stack **a, t_stack **b, int len)
{
	t_stack *tmp;

	tmp = (*b)->prev;
	while (tmp->num != len)
	{
		reverse(b, 2);
		if (tmp->num == len - 1)
			push(b, a, 1);
		tmp = tmp->prev;
	}
	reverse(b, 2);
	return ;
}

void	front_check(t_stack **a, t_stack **b, int b_size, int len)
{
	t_stack *tmp;
	int		cnt;
	int		middle;

	tmp = *b;
	cnt = 0;
	middle = (len + 1) / 2;
	while (tmp->num != len && cnt < middle && cnt < b_size * 2)
	{
		if (tmp->num == len - 1)
			cnt = next_sort(a, b, cnt, &middle);
		tmp = tmp->next;
		cnt++;
	}
	if (tmp->num == len && cnt != 0)
		while (cnt--)
			rotate(b, 2);
	return ;
}

void	others_sort(t_stack **a, t_stack **b, int len)
{
	int	b_size;

	b_size = blocking(a, b, len);
	len = len - 2;
	while (len > 0)
	{
		// print_stack(a, "a ");
		// print_stack(b, "b ");
		front_check(a, b, b_size, len);
		if ((*b)->num != len)
			back_check(a, b, len);
		push(b, a, 1);
		if ((*a)->num > (*a)->next->num)
		{
			swap(a, 1);
			len--;
		}
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