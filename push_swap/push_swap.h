/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:45:22 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/23 15:41:14 by stakimot         ###   ########.fr       */
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

int	*make_data(int argc, char **argv);
int	*make_copy(int len, int *data);
int	*quick_sort(int left, int right, int *src);
int	sort_check(int *data, int *copy, int len);
int	dupli_check(int *data, int len);
int	compress(int num, int *copy, int len);
int	*compression(int len, int *data);
t_stack *make_stack(int *data, int len);
void	error(char *str);
void	swap(t_stack **stack, int flag);
void	rotate(t_stack **stack, int flag);
void	push(t_stack **m_stack, t_stack **s_stack, int flag);
void	reverse(t_stack **stack, int flag);
void	divide(t_stack **a, t_stack **b, int len);
void	three_sort(t_stack **a);
void	others_sort(t_stack **a, t_stack **b, int len);
void	blocking(t_stack **a, t_stack **b, int len);

void	print_stack(t_stack **stack, char *str);

#endif