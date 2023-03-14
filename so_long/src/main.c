/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:24:02 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/14 18:08:38 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_data	*map_data;
	t_data		*data;

	if (argc != 2)
	{
		ft_putendl_fd("args error", 1);
		return (0);
	}
	map_data = read_map(argv[1]);
	data = NULL;
	mlx_setup(data, map_data);
	return (0);
}

// 	__attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }
