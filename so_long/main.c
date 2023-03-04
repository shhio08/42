/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:24:02 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/05 03:03:51 by stakimot         ###   ########.fr       */
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

void	form_check(t_map_data **map_data, int cnt)
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
			error("Error form");
	}
	else if(col != (*map_data)->col)
		error("Error form");
	(*map_data)->col = col;
}

void	read_line(t_map_data **map_data, char *file_name)
{
	int		cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error("Error open");
	cnt = 0;
	(*map_data)->map = (char **)malloc(sizeof(char *) * (*map_data)->row + 1);
	if (!(*map_data)->map)
		error("Error map malloc");
	while (cnt < (*map_data)->row)
	{
		((*map_data)->map[cnt]) = get_next_line(fd);
		form_check(map_data, cnt++);
	}
	(*map_data)->map[cnt] = NULL;
}

void	make_map(t_map_data **map_data, char *file_name)
{
	count_row(map_data, file_name);
	if ((*map_data)->row < 3)
		error("Error row");
	read_line(map_data, file_name);
}

void	top_bottom_check(char *str, int col)
{
	int	cnt;

	cnt = 0;
	while (cnt < col)
	{
		if (str[cnt] != '1')
			error("Error element1");
		cnt++;
	}
}

void	middle_check(char *str, int col, int *pflg, int *eflg)
{
	int	cnt;

	cnt = 0;
	while (cnt < col)
	{
		if (str[cnt] == 'P')
			*pflg += 1;
		else if (str[cnt] == 'E')
			*eflg += 1;
		else if (str[cnt] != '1' && str[cnt] != 'C' && str[cnt] != '0')
			error("Error element2");
		cnt++;
	}
}

void	element_check(t_map_data **map_data)
{
	int	row;
	int	pflg;
	int	eflg;

	row = 0;
	pflg = 0;
	eflg = 0;
	while (row < (*map_data)->row)
	{
		if (row == 0 || row == (*map_data)->row - 1)
			top_bottom_check((*map_data)->map[row], (*map_data)->col);
		else
			middle_check((*map_data)->map[row], (*map_data)->col, &pflg, &eflg);
		row++;
	}
	if (pflg != 1 || eflg != 1)
		error("Error element3");
}

t_map_data	*read_map(char *file_name)
{
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (check_name(file_name))
		error("Error file name");
	make_map(&map_data, file_name);
	element_check(&map_data);

	return (map_data);
}

int	main(int argc, char **argv)
{
	t_map_data	*map_data;

	if (argc != 2)
		return (0);
	map_data = read_map(argv[1]);

	printf("row = %d\n", map_data->row);
	printf("%s", map_data->map[0]);
	printf("%s", map_data->map[1]);
	printf("%s", map_data->map[2]);
	printf("%s", map_data->map[3]);
	return (0);
}
