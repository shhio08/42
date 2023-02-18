/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/18 17:18:43 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	*data;
	t_stack	*a;
	t_stack	*b;

	data = make_data(argc, argv);
	data = compression(argc - 1, data);
	a = make_stack(data, argc - 1);
	b = NULL;
	int i = 15;
	push(&a, &b);
	push(&a, &b);
	while (i--)
	{
		printf("%d, %d, %d, %d\n", a->top, a->num, b->top, b->num);
		a = a->next;
		b = b->next;
	}
	return (0);
}
