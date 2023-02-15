/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:43 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/15 15:49:12 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

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

int	*make_copy(int len, int *data)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * len);
	if (!copy)
		return (0);
	i = -1;
	while(i++ < len)
		copy[i] = data[i];
	return (copy);
}

int	*quick_sort(int left, int right, int *src)
{
	int	pivot;
	int tmp;
	int	end;

	if (left >= right)
		return (src);
	end = right;
	pivot = src[left];
	while (left < right)
	{
		while (src[left] < pivot)
			left++;
		while (left < right && src[right] > pivot)
			right--;
		if (left >= right)
			break;
		tmp = src[left];
		src[left] = src[right];
		src[right] = tmp;
	}
	quick_sort(0, left, src);
	quick_sort(left + 1, end, src);
	return (src);
}

int	sort_check(int *data, int *copy, int len)
{
	int	flag;
	int i;

	flag = 0;
	i = len;
	while (i--)
	{
		if (*data++ == *copy++)
			flag++;
	}
	if (flag == len)
		return (-1);
	return (0);
}

int	dupli_check(int *data, int len)
{
	int	i;
	int	j;

	i = 0;
	while(i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if (data[i] == data[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*compression(int len, int *data)
{
	int *copy;

	if (dupli_check(data, len) == -1)
		error("error1");
	copy = make_copy(len, data);
	copy = quick_sort(0, len - 1, copy);
	if (sort_check(data, copy, len) == -1)
		error("error2");
	return (copy);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*data;
	int	*copy;

	data = make_data(argc, argv);
	copy = compression(argc - 1, data);

	int i = 0;
	while (i < argc - 1)
		printf("%d\n", copy[i++]);
	return (0);
}


