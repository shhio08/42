/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:24:02 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/05 00:20:31 by stakimot         ###   ########.fr       */
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

void	count_row(t_map_data **map_data, char *file_name)
{
	char	*str;
	int		cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error("Error open");
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

// void	add_next_line()

void	read_line(t_map_data **map_data, char *file_name)
{
	// char	*line;
	int		cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error("Error open");
	cnt = 0;
	(*map_data)->map = (char **)malloc(sizeof(char) * (*map_data)->row);
	if (!(*map_data)->map)
		error("Error map malloc");
	while (cnt < (*map_data)->row)
	{
		((*map_data)->map[cnt]) = get_next_line(fd);
		printf("%s", (*map_data)->map[cnt]);
		// add_next_line((*map_data)->map[cnt]);
		// free(line);
		cnt++;
	}
}

void	make_map(t_map_data **map_data, char *file_name)
{
	count_row(map_data, file_name);
	read_line(map_data, file_name);
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
	printf("row = %d\n", map_data->row);
	// printf("%s", map_data->map[0]);
	return (0);
}
