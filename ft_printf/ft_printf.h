/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:19 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/05 16:09:45 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

int	put_str(char *str);
int	put_void(void *a);
int	put_num(int n);
int	check_type(char c, va_list lst);
int	ft_printf(const char *input, ...);
int	get_digit(int n);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
int	u_put_num(unsigned int n);
char	*u_ft_itoa(unsigned int n);

#endif