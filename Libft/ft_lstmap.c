/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:43:22 by stakimot          #+#    #+#             */
/*   Updated: 2022/10/28 16:08:02 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*tmp;

	dest = (t_list *)malloc(sizeof(t_list) * (ft_lstsize(lst)));
	if (!dest)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		dest = ft_lstadd_back(&dest, tmp);
		lst = lst->next;
	}
	return (dest);
}