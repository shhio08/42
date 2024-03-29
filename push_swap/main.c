/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/28 10:35:59 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*data;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		data = check_two(argv[1], &argc);
	else
		data = make_data(argc, argv);
	data = compression(argc - 1, data);
	a = make_stack(data, argc - 1);
	b = NULL;
	divide(&a, &b, argc - 1);
	stack_free(&a);
	return (0);
}

// 	__attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }
