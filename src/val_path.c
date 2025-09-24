/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:51 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 14:49:50 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_loop_in_map(t_mlx *mlx, t_map *map, int y, int x)
{
	map->matrix[y][x] = PLAYER_MLX;
	if (!ft_str(MAP_MLX, map->matrix[y][x + 1]))
		ft_print_error(mlx, "there is an open wall in the map");
	if (x - 1 < 0 || !ft_str(MAP_MLX, map->matrix[y][x - 1]))
		ft_print_error(mlx, "there is an open wall in the map");
	if (y < map->size_y - 1 && !ft_str(MAP_MLX, map->matrix[y + 1][x]))
		ft_print_error(mlx, "there is an open wall in the map");
	if (y != 0 && !ft_str(MAP_MLX, map->matrix[y - 1][x]))
		ft_print_error(mlx, "there is an open wall in the map");
	if (y < map->size_y - 1 && map->matrix[y + 1][x] == '0')
		ft_loop_in_map(mlx, map, y + 1, x);
	if (map->matrix[y][x - 1] == '0')
		ft_loop_in_map(mlx, map, y, x - 1);
	if (map->matrix[y][x + 1] == '0')
		ft_loop_in_map(mlx, map, y, x + 1);
	if (y != 0 && map->matrix[y - 1][x] == '0')
		ft_loop_in_map(mlx, map, y - 1, x);
}

void	ft_loop_out_map(t_mlx *mlx, t_map *map, int y, int x)
{
	map->matrix[y][x] = 'X';
	if (!ft_str(OPEN_WALL, map->matrix[y][x + 1]))
		ft_print_error(mlx, "there is an open wall in the map");
	if (x != 0 && !ft_str(OPEN_WALL, map->matrix[y][x - 1]))
		ft_print_error(mlx, "there is an open wall in the map");
}

void	ft_get_player(t_map *map, int *y, int *x)
{
	*y = 0;
	while (map->matrix[*y])
	{
		*x = 0;
		while (map->matrix[*y][*x] != '\n')
		{
			if (ft_str(P_STARTS, map->matrix[*y][*x]))
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	ft_check_walls(t_mlx *mlx, t_map *map)
{
	int	x;

	x = 0;
	while (map->matrix[0][x] != '\n')
	{
		if (!ft_str("1 ", map->matrix[0][x]))
			ft_print_error(mlx, "there is an open wall at the top");
		x++;
	}
	x = 0;
	while (map->matrix[map->size_y - 1][x] != '\n')
	{
		if (!ft_str("1 ", map->matrix[map->size_y - 1][x]))
			ft_print_error(mlx, "there is an open wall at the bottom");
		x++;
	}
}

void	ft_validate(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	ft_check_walls(mlx, map);
	y = 0;
	x = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x] != '\0')
		{
			if (map->matrix[y][x] == ' ' || map->matrix[y][x] == '\t')
				ft_loop_out_map(mlx, map, y, x);
			x++;
		}
		y++;
	}
	ft_get_player(map, &y, &x);
	ft_loop_in_map(mlx, map, y, x);
}
