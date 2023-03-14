/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:23:19 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/14 18:00:23 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	window_close(t_data *data)
{
	exit_map("close", data);
	(void)data;
	return (0);
}

static int	escape(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_map("escape", data);
	else
		move_player(keycode, data);
	return (0);
}

static void	window_setup(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->pix_size * data->map_data->col,
			data->pix_size * data->map_data->row + 32, "so_long");
	if (!data->win)
		exit_map("xpm error", data);
	data->space_image = mlx_xpm_file_to_image(data->mlx,
			"textures/space.xpm", &data->pix_size, &data->pix_size);
	if (!data->space_image)
		exit_map("xpm error", data);
	data->wall_image = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &data->pix_size, &data->pix_size);
	if (!data->wall_image)
		exit_map("xpm error", data);
	data->player_image = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &data->pix_size, &data->pix_size);
	if (!data->player_image)
		exit_map("xpm error", data);
	data->collect_image = mlx_xpm_file_to_image(data->mlx,
			"textures/collect.xpm", &data->pix_size, &data->pix_size);
	if (!data->collect_image)
		exit_map("xpm error", data);
	data->exit_image = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &data->pix_size, &data->pix_size);
	if (!data->exit_image)
		exit_map("xpm error", data);
}

void	mlx_setup(t_data *data, t_map_data *map_data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error("malloc error", map_data);
	data->map_data = map_data;
	data->step = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_map("mlx error", data);
	data->pix_size = 32;
	window_setup(data);
	mlx_hook(data->win, 17, 0, window_close, data);
	mlx_hook(data->win, 2, 0, escape, data);
	mlx_loop_hook(data->mlx, show_image, data);
	mlx_loop(data->mlx);
}
