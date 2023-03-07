/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:40:38 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/07 19:22:22 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	top_bottom_check(char *str, int col)
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

static int	middle_check(t_map_data **map, int row, int *player, int *exit)
{
	int		col;
	int		collectible;

	col = 0;
	collectible = 0;
	while (col < (*map)->col)
	{
		if ((col == 0 && (*map)->map[row][col] != '1') || \
			(col == (*map)->col - 1 && (*map)->map[row][col] != '1'))
			error("Error element4");
		if ((*map)->map[row][col] == 'P')
		{
			*player += 1;
			(*map)->y = row;
			(*map)->x = col;
		}
		else if ((*map)->map[row][col] == 'E')
			*exit += 1;
		else if ((*map)->map[row][col] == 'C')
			collectible += 1;
		else if ((*map)->map[row][col] != '1' && (*map)->map[row][col] != '0')
			error("Error element2");
		col++;
	}
	return (collectible);
}

void	element_check(t_map_data **map_data)
{
	int	row;
	int	player;
	int	exit;
	int	collectible;

	row = 0;
	player = 0;
	exit = 0;
	collectible = 0;
	while (row < (*map_data)->row)
	{
		if (row == 0 || row == (*map_data)->row - 1)
			top_bottom_check((*map_data)->map[row], (*map_data)->col);
		else
			collectible += middle_check(map_data, row, &player, &exit);
		row++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		error("Error element3");
	(*map_data)->collectible = collectible;
}

static void	mark_map(t_map_data **map_data, char **copy, int y, int x)
{
	if (y < 1 || x < 1)
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'T';
		(*map_data)->check_exit -= 1;
		return ;
	}
	if (copy[y][x] == 'P' || copy[y][x] == '0' || copy[y][x] == 'C')
	{
		if (copy[y][x] == 'C')
			(*map_data)->check_collect -= 1;
		copy[y][x] = 'T';
		mark_map(map_data, copy, y - 1, x);
		mark_map(map_data, copy, y + 1, x);
		mark_map(map_data, copy, y, x - 1);
		mark_map(map_data, copy, y, x + 1);
	}
}

void	playable_check(t_map_data **map_data)
{
	char	**copy;
	int		cnt;

	cnt = 0;
	copy = (char **)malloc(sizeof(char *) * (*map_data)->row + 1);
	if (!copy)
		error("Error malloc");
	while (cnt < (*map_data)->row)
	{
		copy[cnt] = ft_strdup((*map_data)->map[cnt]);
		cnt++;
	}
	copy[cnt] = NULL;
	(*map_data)->check_exit = 1;
	(*map_data)->check_collect = (*map_data)->collectible;
	mark_map(map_data, copy, (*map_data)->y, (*map_data)->x);
	if ((*map_data)->check_collect != 0 || (*map_data)->check_exit != 0)
		error("Error not playable");
	map_free(copy);
}
