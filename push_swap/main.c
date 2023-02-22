/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/23 01:39:35 by stakimot         ###   ########.fr       */
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
	a = make_stack(data, argc - 1);
	b = NULL;
	divide(&a, &b, argc - 1);
	printf("a:%d ", a->num);
	a = a->next;
	while (a ->top != 1)
	{
		printf("%d ", a->num);
		a = a->next;
	}
	printf("\nb:%d ", b->num);
	b = b->next;
	while (b ->top != 1)
	{
		printf("%d ", b->num);
		b = b->next;
	}
	return (0);
}
