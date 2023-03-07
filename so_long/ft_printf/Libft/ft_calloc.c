/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:12:55 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 14:32:09 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == 0 || size == 0)
	{
		tmp = (void *)malloc(sizeof(void) * 1);
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, 1);
		return (tmp);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	tmp = (void *)malloc(sizeof(void) * count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
