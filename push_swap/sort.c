/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/25 15:28:39 by stakimot         ###   ########.fr       */
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

void	five_spin(t_stack **a, t_stack **b, int cnt, int len)
{
	if ((len == 5 && cnt <= 2) || (len == 4 && cnt <= 1))
	{
		while(cnt--)
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
	int	cnt;
	int num;
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
	while(num-- >= 0)
		push(b, a, 1);
	// print_stack(a, "a ");
}

int	block_judge(t_stack **a, t_stack **b, t_init *init)
{
	if ((*a)->num != init->max)
	{
		if ((*a)->num <= init->block)
		{
			push(a, b, 2);
			if ((*a)->next->top == 1)
				return (-1);
			if ((*a)->num > init->block + init->range)
			{
				rr(a, b);
				return (1);
			}
			rotate(b, 2);
			if ((*a)->next->top == 1)
				return (-1);
		}
		else if ((*a)->num <= init->block + init->range)
			push(a, b, 2);
		else if ((*a)->next->top != 1)
			rotate(a, 1);
		else
			return (-1);
	}
	else if ((*a)->next->top != 1)
		rotate(a, 1);
	else
		return (-1);
	return (0);
}

int	blocking(t_stack **a, t_stack **b, int len)
{
	int	i;
	t_init	*init;
	int	flag;

	init = (t_init *)malloc(sizeof(t_init));
	init->block = len / (len / 50 + 8);
	init->range = init->block;
	init->max = len - 1;
	while (1)
	{
		// printf("----------------------\n");
		i = -1;
		while (++i < len)
		{
			// print_stack(a, "a ");
			// print_stack(b, "b ");
			flag = block_judge(a, b, init);
			if (flag == -1)
				return (init->range);
			else if (flag == 1)
				i++;
		}
		init->block += (init->range * 2);
		len = len - (init->range * 2);
	}
	return (init->range);
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
	t_stack *tmp;
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
		else if(flag == 1 && tmp->num == len - 2)
			push(b, a, 1);
		tmp = tmp->prev;
	}
	reverse(b, 2);
	return ;
}

void	front_push(t_stack **a, t_stack **b, int cnt, int len)
{
	int		flag;

	flag = 0;
	// printf("cnt %d\n", cnt);
	while (cnt-- > 0)
	{
		// print_stack(a, "a ");
		// print_stack(b, "b ");
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
	t_stack *tmp;
	int		cnt;
	int		flag;
	int		middle;

	tmp = *b;
	cnt = 0;
	flag = 0;
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

void	others_sort(t_stack **a, t_stack **b, int len)
{
	int	block;

	block = blocking(a, b, len);
	len = len - 2;
	// printf("=============================\n\n\n");
	while (len > 0)
	{
	// 	print_stack(a, "a ");
	// 	print_stack(b, "b ");
		front_check(a, b, block, len);
		if ((*b)->num != len)
			back_check(a, b, len);
		push(b, a, 1);
		if ((*a)->num > (*a)->next->num)
		{
			if (swap_check(a))
				len--;
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