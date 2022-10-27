/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:12:55 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/28 00:12:34 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if (count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
	{
		tmp = malloc(1);
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, 1);
		return (tmp);
	}
	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	ft_bzero(tmp, count * size);
	return (tmp);
}
