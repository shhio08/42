/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:24:02 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/28 21:03:17 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *file_name)
{
	int		cnt;
	int		i;
	char	*ber = ".ber";

	cnt = 0;
	while (file_name[cnt])
		cnt++;
	cnt--;
	i = 0;
	while (i < 4)
	{
		if (file_name[cnt - i] != ber[3 - i])
			return (-1);
		i++;
	}
	return (0);
}

void	count_row(t_map_data **map_data, int fd)
{
	char	*str;
	int		cnt;

	cnt = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		cnt++;
		free(str);
	}
	(*map_data)->row = cnt;
}

// void	read_line(t_map_data **map_data, int fd)
// {
// 	char	*line;
// 	int		cnt;

// 	cnt = 0;
// 	(*map_data)->map = (char **)malloc(sizeof(char) * (*map_data)->row);
// 	if (!(*map_data)->map)
// 		error("Error map malloc");
// 	while (cnt < (*map_data)->row)
// 	{
// 		line = get_next_line(fd);
// 		add_next_line((*map_data)->map[cnt]);
// 		cnt++;
// 	}
// }

void	make_map(t_map_data **map_data, char *file_name)
{
	// char	*line;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error("Error open");
	count_row(map_data, fd);
	// read_line(map_data, fd);
}

t_map_data	*read_map(char *file_name)
{
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (check_name(file_name))
		error("Error file name");
	make_map(&map_data, file_name);
	return (map_data);
}

int	main(int argc, char **argv)
{
	t_map_data	*map_data;

	if (argc != 2)
		return (0);
	map_data = read_map(argv[1]);
	return (0);
}
