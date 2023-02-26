/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 11:47:14 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **dest)
{
	size_t	cnt;

	cnt = 0;
	while (dest[cnt])
		free(dest[cnt++]);
	free(dest);
	return (NULL);
}

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	*stack = (*stack)->next;
	while ((*stack)->top != 1)
	{
		tmp = (*stack);
		free(*stack);
		*stack = tmp->next;
	}
	free(*stack);
}

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
	data = (int *)malloc(sizeof(int) * (len));
	if (!data)
		return (0);
	i = 0;
	while (i < len)
	{
		data[i] = ft_atoi(lst[i]);
		i++;
	}
	*argc = len + 1;
	ft_free(lst);
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
	stack_free(&a);
	return (0);
}

	__attribute__((destructor)) static void destructor()
{
    system("leaks -q push_swap");
}
