/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:09:39 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:39 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	is_wall(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK_SIZE);
	map_y = (int)(y / BLOCK_SIZE);
	if (map_x < 0 || map_x > mlx->map.size_x || map_y < 0 \
		|| map_y > mlx->map.size_y)
		return (1);
	if (mlx->map.matrix[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	player_rotate(t_mlx *mlx, double angle)
{
	double		dir;

	dir = angle + mlx->player.angle;
	if (dir < 0.0)
		mlx->player.angle = dir + 2 * M_PI;
	else if (dir >= 2 * M_PI)
		mlx->player.angle = dir - 2 * M_PI;
	else
		mlx->player.angle = dir;
	return ;
}

void	player_move(t_mlx *mlx, double speed, double angle)
{
	double	dx;
	double	dy;
	int		size_x;
	int		size_y;

	angle += mlx->player.angle;
	dx = speed * cos(angle);
	dy = speed * sin(angle);
	if (dx < 0)
		size_x = -16;
	else
		size_x = 16;
	if (dy < 0)
		size_y = -16;
	else
		size_y = 16;
	if (!is_wall(mlx, mlx->player.x + dx + size_x,
			mlx->player.y + dy + size_y))
	{
		mlx->player.x += dx;
		mlx->player.y += dy;
	}
	return ;
}
