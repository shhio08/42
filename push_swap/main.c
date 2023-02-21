/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/19 18:43:53 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*data;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	data = make_data(argc, argv);
	data = compression(argc - 1, data);
	a = make_stack(data, argc - 1);
	b = NULL;
	ft_sort(&a, &b, argc - 1);
	printf("last%d %d %d %d %d\n", a->num, a->next->num, a->next->next->num, a->next->next->next->num, a->next->next->next->next->num);
	return (0);
}
