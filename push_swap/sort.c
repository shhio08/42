/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/22 15:40:03 by stakimot         ###   ########.fr       */
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

// int	find_min(t_stack **stack)
// {
// 	int	num;

// 	num = (*stack)->num;
// 	stack = (*stack)->next;
// 	while ((*stack)->top != 1)
// 	{
// 		if (num > (*stack)->num)
// 			num = (*stack)->num;
// 		*stack = (*stack)->next;
// 	}
// 	return (num);
// }
// printf("%d %d %d %d %d\n", (*a)->num, (*a)->next->num, (*a)->next->next->num, (*a)->next->next->next->num, (*a)->next->next->next->next->num);

void	five_sort(t_stack **a, t_stack **b, int len)
{
	int	cnt;
	int num;

	num = -1;
	while (len > 3)
	{
		cnt = 0;
		num++;
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
					rotate(a, 1);
			}
			else
			{
				while(cnt++ < len)
					reverse(a, 1);
			}
			push(a, b, 2);
		}
		len--;
	}
	three_sort(a);
	while(num-- >= 0)
		push(b, a, 1);
}

void	blocking(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	cnt;
	int	b_size;
	int	init;

	cnt = 1;
	b_size = len / 6;
	init = b_size;
	while (cnt < 4)
	{
		i = 0;
		while (i <= len)
		{
			if ((*a)->num <= b_size)
			{
				push(a, b, 2);
				rotate(b, 2);
			}
			else if ((*a)->num <= b_size + init)
				push(a, b, 2);
			else
				rotate(a, 1);
			if ((*a)->next->top == 1)
				return ;
			i++;
		}
		b_size = b_size + (init * 2);
		len = len - (init * 2);
		cnt++;
		// printf("len:%d\n", len);
		// printf("a:%d %d %d %d %d %d\n", (*a)->num, (*a)->next->num, (*a)->next->next->num, (*a)->next->next->next->num, (*a)->next->next->next->next->num, (*a)->next->next->next->next->next->num);
		// printf("b:%d %d %d %d %d %d\n", (*b)->num, (*b)->next->num, (*b)->next->next->num, (*b)->next->next->next->num, (*b)->next->next->next->next->num, (*b)->next->next->next->next->next->num);
	}
}

void	others_sort(t_stack **a, t_stack **b, int len)
{
	int	cnt;
	int	middle;

	blocking(a, b, len);
	cnt = 0;
	len = len - 2;
	middle = len / 2;
	while (len > 0)
	{
		printf("len:%d\n", len);
		printf("b:%d %d %d %d %d %d\n", (*b)->num, (*b)->next->num, (*b)->next->next->num, (*b)->next->next->next->num, (*b)->next->next->next->next->num, (*b)->next->next->next->next->next->num);
		while ((*b)->num != len)
		{
			*b = (*b)->next;
			cnt++;
		}
		if (cnt++ <= middle)
		{
			while (cnt--)
				rotate(b, 2);
		}
		else
		{
			while (cnt--)
				reverse(b, 2);
		}
		push(b, a, 1);
		len--;
	}
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