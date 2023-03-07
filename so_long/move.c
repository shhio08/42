/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:47:08 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/07 18:54:52 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_check(t_data *data, int row, int col)
{
	char	c;

	c = data->map_data->map[row][col];
	if (c == '1')
		return ;
	else if (c == 'C')
		data->map_data->collectible -= 1;
	else if (c == 'E')
	{
		if (data->map_data->collectible != 0)
			return ;
		else if (data->map_data->collectible == 0)
			exit_map("clear!", data);
	}
	data->step += 1;
	ft_printf("step:%d\n", data->step);
	data->map_data->map[row][col] = 'P';
	data->map_data->map[data->map_data->y][data->map_data->x] = '0';
	data->map_data->x = col;
	data->map_data->y = row;
}

int	move_player(int keycode, t_data *data)
{
	if (keycode == 126 || keycode == 13)
		move_check(data, data->map_data->y - 1, data->map_data->x);
	else if (keycode == 125 || keycode == 1)
		move_check(data, data->map_data->y + 1, data->map_data->x);
	else if (keycode == 123 || keycode == 0)
		move_check(data, data->map_data->y, data->map_data->x - 1);
	else if (keycode == 124 || keycode == 2)
		move_check(data, data->map_data->y, data->map_data->x + 1);
	return (0);
}
