/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:18:56 by stakimot          #+#    #+#             */
/*   Updated: 2023/03/08 13:05:54 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_map_data
{
	char	**map;
	int		col;
	int		row;
	int		x;
	int		y;
	int		collectible;
	int		check_collect;
	int		check_exit;
}	t_map_data;

typedef struct s_data
{
	t_map_data	*map_data;
	void		*mlx;
	void		*win;
	void		*space_image;
	void		*wall_image;
	void		*player_image;
	void		*collect_image;
	void		*exit_image;
	int			pix_size;
	int			step;
}	t_data;

t_map_data	*read_map(char *file_name);
void		element_check(t_map_data **map_data);
void		playable_check(t_map_data **map_data);
void		mlx_setup(t_data *data, t_map_data *map_data);
int			show_image(t_data *data);
void		error(char *str, t_map_data *map_data);
void		error1(char *str, t_map_data *map_data);
int			check_name(char *file_name);
void		map_free(char **map);
void		exit_map(char *str, t_data *data);
int			move_player(int keycode, t_data *data);

#endif
