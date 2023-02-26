/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:45:22 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/26 16:23:00 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				top;
}	t_stack;

typedef struct s_init
{
	int	max;
	int	range;
	int	block;
}	t_init;

int		*check_two(char *str, int *argc);
int		*make_data(int argc, char **argv);
int		*make_copy(int len, int *data);
t_stack	*make_stack(int *data, int len);
int		*compression(int len, int *data);
void	divide(t_stack **a, t_stack **b, int len);
void	three_sort(t_stack **a);
void	five_sort(t_stack **a, t_stack **b, int len);
void	others_sort(t_stack **a, t_stack **b, int len);
void	front_check(t_stack **a, t_stack **b, int block, int len);
void	back_check(t_stack **a, t_stack **b, int len);
int		swap_check(t_stack **a);
void	error(char *str);
void	stack_free(t_stack **stack);
char	**ft_free(char **dest);
int		ps_atoi(const char *str);
void	swap(t_stack **stack, int flag);
void	rotate(t_stack **stack, int flag);
void	rr(t_stack **a, t_stack **b);
void	reverse(t_stack **stack, int flag);
void	push(t_stack **m_stack, t_stack **s_stack, int flag);

#endif
