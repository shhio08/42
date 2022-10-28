/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:51:34 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/28 15:06:34 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	cnt;
	
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt++);
}