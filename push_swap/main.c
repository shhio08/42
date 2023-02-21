/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/21 15:27:25 by stakimot         ###   ########.fr       */
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
	while(lst[len])
		len++;
	// printf("%d\n", len);
	data = (int *)malloc(sizeof(int) * (len + 1));
	if (!data)
		return 0;
	i = 0;
	while (i < len)
	{
		data[i] = ft_atoi(lst[i]);
		i++;
	}
	*argc = len + 1;
	return (data);
}

int	main(int argc, char **argv)
{
	int	*data;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		data = check_two(argv[1], &argc);
	else
		data = make_data(argc, argv);
	data = compression(argc - 1, data);
	printf("!%d %d %d\n", data[0], data[1], data[2]);
	a = make_stack(data, argc - 1);
	b = NULL;
	ft_sort(&a, &b, argc - 1);
	printf("%d %d %d %d %d\n", a->num, a->next->num, a->next->next->num, a->next->next->next->num, a->next->next->next->next->num);
	return (0);
}
