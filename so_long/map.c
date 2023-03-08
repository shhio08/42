/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:38:34 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/08 12:42:53 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	form_check(t_map_data **map_data, int cnt)
{
	int	col;

	col = 0;
	while ((*map_data)->map[cnt][col] != '\n')
	{
		col++;
	}
	if (cnt == 0)
	{
		if ((*map_data)->row * col < 15)
			error("map error", *map_data);
	}
	else if (col != (*map_data)->col)
		error("map error", *map_data);
	(*map_data)->col = col;
}

static void	read_line(t_map_data **map_data, char *file_name)
{
	int		cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error1("read map error", *map_data);
	cnt = 0;
	(*map_data)->map = (char **)malloc(sizeof(char *) * (*map_data)->row + 1);
	if (!(*map_data)->map)
		error1("read map error", *map_data);
	while (cnt < (*map_data)->row)
	{
		((*map_data)->map[cnt]) = get_next_line(fd);
		(*map_data)->map[cnt + 1] = NULL;
		form_check(map_data, cnt++);
	}
	(*map_data)->map[cnt] = NULL;
	close(fd);
}

static void	count_row(t_map_data **map_data, char *file_name)
{
	char	*str;
	int		cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error1("read map error", *map_data);
	cnt = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		cnt++;
		free(str);
	}
	close(fd);
	(*map_data)->row = cnt;
}

static void	make_map(t_map_data **map_data, char *file_name)
{
	count_row(map_data, file_name);
	if ((*map_data)->row < 3)
		error1("map error", *map_data);
	read_line(map_data, file_name);
}

t_map_data	*read_map(char *file_name)
{
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		exit(1);
	if (check_name(file_name))
		error1("file name error", map_data);
	make_map(&map_data, file_name);
	element_check(&map_data);
	playable_check(&map_data);
	return (map_data);
}
