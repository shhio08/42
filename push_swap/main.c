/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/13 20:32:55 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

int	*make_data(int argc, char **argv)
{
	int	*data;
	int	i;

	data = (int *)malloc(sizeof(int) * argc);
	if (!data)
		return 0;
	i = 1;
	while (i < argc)
	{
		data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data[i] = 0;
	return (data);
}

int	*make_copy(int argc, int *data)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * argc);
	if (!copy)
		return (0);
	i = -1;
	while(i++ < argc)
		copy[i] = data[i];
	return (copy);
}

int	*quick_sort(int top, int argc, int *src)
{
	int	i;
	int	pivot;
	int	start;
	int tmp;

	if (start > argc)
		return (src);
	i = top;
	pivot = src[i];
	while (src[i] > pivot)
		i++;
	start = i;
	i = argc;
	while (src[i] < pivot)
		i++;
	tmp = src[start];
	src[start] = src[i];
	src[i] = tmp;
	quick_sort(start, i, src);
}

int	*compression(int argc, int *data)
{
	int *copy;

	copy = make_copy(argc, data);
	copy = quick_sort(0, argc, copy);

	return (copy);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*data;
	int	*copy;

	data = make_data(argc, argv);
	copy = compression(argc, data);
	int i = 0;
	while (i < argc - 1)
		printf("%d\n", copy[i++]);
	return (0);
}
