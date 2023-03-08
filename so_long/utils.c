/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:09:17 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/08 12:15:05 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str, t_map_data *map_data)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	map_free(map_data->map);
	free(map_data);
	exit(0);
}

void	error1(char *str, t_map_data *map_data)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(map_data);
	exit(0);
}

int	check_name(char *file_name)
{
	int		cnt;
	int		i;
	char	*ber;

	cnt = 0;
	ber = ft_strdup(".ber");
	while (file_name[cnt])
		cnt++;
	cnt--;
	i = 0;
	while (i < 4)
	{
		if (file_name[cnt - i] != ber[3 - i])
		{
			free(ber);
			return (-1);
		}
		i++;
	}
	free(ber);
	return (0);
}

void	map_free(char **map)
{
	size_t	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	exit_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	map_free(data->map_data->map);
	free(data->map_data);
	mlx_destroy_window(data->mlx, data->win);
	if (data->space_image)
		mlx_destroy_image(data->mlx, data->space_image);
	if (data->wall_image)
		mlx_destroy_image(data->mlx, data->wall_image);
	if (data->player_image)
		mlx_destroy_image(data->mlx, data->player_image);
	if (data->collect_image)
		mlx_destroy_image(data->mlx, data->collect_image);
	if (data->exit_image)
		mlx_destroy_image(data->mlx, data->exit_image);
	free(data);
	exit(0);
}
