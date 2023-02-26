/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:16:55 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 10:19:28 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	quick_sort(int left, int right, int *src)
{
	int	pivot;
	int tmp;
	int start;
	int	end;

	if (left >= right)
		return ;
	start = left;
	end = right;
	pivot = src[(left + right) / 2];
	while (left < right)
	{
		while (src[left] < pivot)
			left++;
		while (src[right] > pivot)
			right--;
		if (left >= right)
			break ;
		tmp = src[left];
		src[left] = src[right];
		src[right] = tmp;
	}
	// printf("l%d r%d\n", left, right);
	quick_sort(start, left, src);
	quick_sort(left + 1, end, src);
	return ;
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

int	compress(int num, int *copy, int len)
{
	int	cnt;

	cnt = 0;
	while (num != copy[cnt] && cnt < len)
		cnt++;
	return (cnt);
}

int	*compression(int len, int *data)
{
	int *copy;
	int	i;

	if (dupli_check(data, len) == -1)
		error("");
	copy = make_copy(len, data);
	quick_sort(0, len - 1, copy);
	if (sort_check(data, copy, len) == -1)
		error("");
	i = 0;
	while (i < len)
	{
		data[i] = compress(data[i], copy, len);
		i++;
	}
	free(copy);
	copy = NULL;
	return (data);
}