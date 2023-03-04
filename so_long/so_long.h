/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:18:56 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/05 01:57:31 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct s_map_data
{
	char	**map;
	int		col;
	int		row;
	int		x;
	int		y;
}	t_map_data;

void	error(char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
t_map_data	*read_map(char *file_name);
void	make_map(t_map_data **map_data, char *file_name);
void	count_row(t_map_data **map_data, char *file_name);
int	check_name(char *file_name);

#endif
