/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:48:38 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/09 11:05:19 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	put_image(t_data *data, int row, int col)
{
	char	*num;

	num = ft_itoa(data->step);
	if (data->map_data->map[row][col] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->space_image, col * data->pix_size, row * data->pix_size + 32);
	else if (data->map_data->map[row][col] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall_image, col * data->pix_size, row * data->pix_size + 32);
	else if (data->map_data->map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player_image,
			col * data->pix_size, row * data->pix_size + 32);
	else if (data->map_data->map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect_image,
			col * data->pix_size, row * data->pix_size + 32);
	else if (data->map_data->map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_image, col * data->pix_size, row * data->pix_size + 32);
	mlx_string_put(data->mlx, data->win, 10, 5, 0xFFECE1, num);
	free(num);
	return (0);
}

void	put_step(t_data *data, int col)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->space_image, col * data->pix_size, 0);
}

int	show_image(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (col < data->map_data->col)
		put_step(data, col++);
	while (row < data->map_data->row)
	{
		col = 0;
		while (col < data->map_data->col)
			put_image(data, row, col++);
		row++;
	}
	return (0);
}
