/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:17:56 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 18:09:39 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_two(char *str, int *argc)
{
	char	**lst;
	int		*data;
	int		len;
	int		i;

	lst = ft_split(str, ' ');
	len = 0;
	while (lst[len])
		len++;
	if (len == 0)
		error("Error\n");
	data = (int *)malloc(sizeof(int) * (len));
	if (!data)
		return (0);
	i = 0;
	while (i < len)
	{
		data[i] = ps_atoi(lst[i]);
		i++;
	}
	*argc = len + 1;
	ft_free(lst);
	return (data);
}

int	*make_data(int argc, char **argv)
{
	int	*data;
	int	i;

	data = (int *)malloc(sizeof(int) * argc);
	if (!data)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		data[i - 1] = ps_atoi(argv[i]);
		i++;
	}
	printf("%d %d %d\n", data[0], data[1], data[2]);
	data[i] = 0;
	return (data);
}

int	*make_copy(int len, int *data)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * len);
	if (!copy)
		return (0);
	i = -1;
	while (i++ < len)
		copy[i] = data[i];
	return (copy);
}

static t_stack	*make_node(int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error("Error\n");
	stack->num = num;
	stack->next = NULL;
	stack->prev = NULL;
	stack->top = 1;
	return (stack);
}

t_stack	*make_stack(int *data, int len)
{
	t_stack	*a;
	t_stack	*tmp;
	int		i;

	i = 0;
	a = make_node(data[i++]);
	tmp = a;
	while (i < len)
	{
		a->next = (t_stack *)malloc(sizeof(t_stack));
		if (!a->next)
			error("Error\n");
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
