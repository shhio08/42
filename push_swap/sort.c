/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:37 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 16:12:07 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sub_block_judge(t_stack **a, t_stack **b, t_init *init)
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
	return (0);
}

static int	block_judge(t_stack **a, t_stack **b, t_init *init)
{
	int	flag;

	if ((*a)->num != init->max)
	{
		if ((*a)->num <= init->block)
		{
			flag = sub_block_judge(a, b, init);
			if (flag == 1)
				return (1);
			if (flag == -1)
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

static int	return_init(t_init *init)
{
	int	range;

	range = init->range;
	free(init);
	return (range);
}

static int	blocking(t_stack **a, t_stack **b, int len)
{
	int		i;
	t_init	*init;
	int		flag;

	init = (t_init *)malloc(sizeof(t_init));
	init->block = len / (len / 50 + 6);
	init->range = init->block;
	init->max = len - 1;
	while (1)
	{
		i = -1;
		while (++i < len)
		{
			flag = block_judge(a, b, init);
			if (flag == -1)
				return (return_init(init));
			else if (flag == 1)
				i++;
		}
		init->block += (init->range * 2);
		len = len - (init->range * 2);
	}
	return (return_init(init));
}

void	others_sort(t_stack **a, t_stack **b, int len)
{
	int	block;

	block = blocking(a, b, len);
	len = len - 2;
	while (len > 0)
	{
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
