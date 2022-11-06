/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:19 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/06 18:58:47 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

int		ft_printf(const char *format, ...);
int		change_base(unsigned int num, int n);
int		put_pointer(unsigned long long num);
int		put_char(char c);
int		put_str(char *str);
char	*u_ft_itoa(unsigned int num);
int		u_put_num(unsigned int n);
int		put_num(int n);

#endif