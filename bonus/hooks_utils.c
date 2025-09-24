/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:28 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 17:42:28 by pc               ###   ########.fr       */
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
	if (mlx->map.matrix[map_y][map_x] == '1'\
		|| mlx->map.matrix[map_y][map_x] == 'D')
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

int	toggle_door_util(t_mlx *mlx, int nx, int ny)
{
	if (nx >= 0 && nx < mlx->map.size_x && ny >= 0 && ny < mlx->map.size_y)
	{
		if (mlx->map.matrix[ny][nx] == 'D')
		{
			mlx->map.matrix[ny][nx] = 'O';
			return (0);
		}
		else if (mlx->map.matrix[ny][nx] == 'O')
		{
			mlx->map.matrix[ny][nx] = 'D';
			return (0);
		}
	}
	return (1);
}

void	toggle_door(t_mlx *mlx)
{
	int	player_x;
	int	player_y;
	int	dx;
	int	dy;

	player_x = (int)(mlx->player.x / BLOCK_SIZE);
	player_y = (int)(mlx->player.y / BLOCK_SIZE);
	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			if (!toggle_door_util(mlx, player_x + dx, player_y + dy))
				return ;
			dy++;
		}
		dx++;
	}
}
