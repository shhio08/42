/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:45:22 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/18 16:52:20 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	num;
	struct s_stack *next;
	struct s_stack *prev;
	int	top;
}	t_stack;

void	rotate(t_stack **stack);
void	push(t_stack **m_stack, t_stack **s_stack);

#endif