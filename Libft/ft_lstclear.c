/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:24:35 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/29 10:30:16 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while(*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
	}
	tmp->next = NULL;
}
