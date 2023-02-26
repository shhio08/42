/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:17:56 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 10:16:03 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *make_stack(int *data, int len)
{
	t_stack *a;
	t_stack *tmp;
	int		i;

	i = 0;
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		error("error");
	a->num = data[i++];
	a->next = NULL;
	a->prev = NULL;
	a->top = 1;
	tmp = a;
	while (i < len)
	{
		a->next = (t_stack *)malloc(sizeof(t_stack));
		if (!a->next)
			error("error");
		a->next->num = data[i++];
		a->next->prev = a;
		a->next->top = 0;
		a = a->next;
	}
	a->next = tmp;
	tmp->prev = a;
	free(data);
	data = NULL;
	return (tmp);
}