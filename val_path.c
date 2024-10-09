/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:51 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/09 13:21:58 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_loop_in_mlx(t_map *map, int y, int x)
{
	map->matrix[y][x] = PLAYER_mlx;
	if (!ft_str(MAP_mlx, map->matrix[y][x + 1]))
		ft_char_error_wall(map, y + 1, x + 2, map->matrix[y][x + 1]);
	if (!ft_str(MAP_mlx, map->matrix[y][x - 1]))
		ft_char_error_wall(map, y + 1, x - 2, map->matrix[y][x - 1]);
	if (y < map->size_y - 1 && !ft_str(MAP_mlx, map->matrix[y + 1][x]))
		ft_char_error_wall(map, y + 2, x + 1, map->matrix[y + 1][x]);
	if (y != 0 && !ft_str(MAP_mlx, map->matrix[y - 1][x]))
		ft_char_error_wall(map, y - 2, x + 1, map->matrix[y - 1][x]);
	if (y < map->size_y - 1 && map->matrix[y + 1][x] == '0')
		ft_loop_in_mlx(map, y + 1, x);
	if (map->matrix[y][x - 1] == '0')
		ft_loop_in_mlx(map, y, x - 1);
	if (map->matrix[y][x + 1] == '0')
		ft_loop_in_mlx(map, y, x + 1);
	if (y != 0 && map->matrix[y - 1][x] == '0')
		ft_loop_in_mlx(map, y - 1, x);
}

void	ft_loop_out_mlx(t_map *map, int y, int x)
{
	map->matrix[y][x] = 'X';
	if (!ft_str(OPEN_WALL, map->matrix[y][x + 1]))
		ft_char_error_wall(map, y + 1, x + 2, map->matrix[y][x + 1]);
	//printf("AAAAAAAAAAAAA\n");
	if (x != 0 && !ft_str(OPEN_WALL, map->matrix[y][x - 1]))
		ft_char_error_wall(map, y + 1, x - 2, map->matrix[y][x - 1]);
	//printf("BBBBBBBBBBBB\n");
	if (y < map->size_y - 1 && !ft_str(OPEN_WALL, map->matrix[y + 1][x]))
		ft_char_error_wall(map, y + 2, x + 1, map->matrix[y + 1][x]);
	//printf("CCCCCCCCCCCCC\n");
	if (y != 0 && !ft_str(OPEN_WALL, map->matrix[y - 1][x]))
		ft_char_error_wall(map, y - 2, x + 1, map->matrix[y - 1][x]);
	//printf("DDDDDDDDDDDDD\n");
	if (y < map->size_y - 1 && map->matrix[y + 1][x] == ' ')
		ft_loop_out_mlx(map, y + 1, x);
	//printf("WTF?!1\n");
	if (x != 0 && map->matrix[y][x - 1] == ' ')
		ft_loop_out_mlx(map, y, x - 1);
	//printf("WTF?!2\n");
	if (map->matrix[y][x + 1] == ' ')
		ft_loop_out_mlx(map, y, x + 1);
	//printf("WTF?!3\n");
	if (y != 0 && map->matrix[y - 1][x] == ' ')
		ft_loop_out_mlx(map, y - 1, x);
	//printf("WTF?!4\n");
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

void	ft_validate(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		//printf("LINE: %s", map->matrix[y]);
		x = 0;
		while (map->matrix[y][x] != '\0')
		{
			if (map->matrix[y][x] == ' ')
			{
				//printf("IN LOOP AT LINE %d\n", y);
				ft_loop_out_mlx(map, y, x);
			}
			x++;
		}
		y++;
	}
	//printf("OUT?\n");
	ft_get_player(map, &y, &x);
	ft_loop_in_mlx(map, y, x);
}
