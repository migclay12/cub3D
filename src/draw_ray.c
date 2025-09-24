/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:09:24 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:24 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	is_wall_ray(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK_SIZE);
	map_y = (int)(y / BLOCK_SIZE);
	if (map_x < mlx->map.size_x || map_x > 0 || map_y > 0 \
		|| map_y < mlx->map.size_y)
	{
		if (mlx->map.matrix[map_y][map_x] == '1')
			return (1);
		else if (mlx->map.matrix[map_y][map_x] == '0')
			return (0);
	}
	return (1);
}

void	calculate_step_x(t_mlx *mlx)
{
	if (mlx->ray.dir_x < 0)
	{
		mlx->ray.step_x = -1;
		mlx->ray.side_dist_x = (mlx->player.x
				- (int)mlx->player.x) * mlx->ray.delta_dist_x;
	}
	else
	{
		mlx->ray.step_x = 1;
		mlx->ray.side_dist_x = ((int)mlx->player.x + 1.0
				- mlx->player.x) * mlx->ray.delta_dist_x;
	}
}

void	calculate_step_y(t_mlx *mlx)
{
	if (mlx->ray.dir_y < 0)
	{
		mlx->ray.step_y = -1;
		mlx->ray.side_dist_y = (mlx->player.y
				- (int)mlx->player.y) * mlx->ray.delta_dist_y;
	}
	else
	{
		mlx->ray.step_y = 1;
		mlx->ray.side_dist_y = ((int)mlx->player.y
				+ 1.0 - mlx->player.y) * mlx->ray.delta_dist_y;
	}
}

int	perform_dda(t_mlx *mlx, int rays)
{
	int	side;
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (mlx->ray.side_dist_x < mlx->ray.side_dist_y)
		{
			mlx->ray.side_dist_x += mlx->ray.delta_dist_x;
			mlx->ray.ray_x[rays] += mlx->ray.step_x;
			side = 0;
		}
		else
		{
			mlx->ray.side_dist_y += mlx->ray.delta_dist_y;
			mlx->ray.ray_y[rays] += mlx->ray.step_y;
			side = 1;
		}
		if (is_wall_ray(mlx, mlx->ray.ray_x[rays], mlx->ray.ray_y[rays]))
			hit = 1;
	}
	return (side);
}

void	get_final_distance(t_mlx *mlx, int rays)
{
	if (perform_dda(mlx, rays) == 0)
	{
		mlx->ray.distances[rays] = (mlx->ray.ray_x[rays] - mlx->player.x
				+ (1 - mlx->ray.step_x) / 2) / mlx->ray.dir_x;
		mlx->ray.vertical_hit[rays] = 1;
	}
	else
	{
		mlx->ray.distances[rays] = (mlx->ray.ray_y[rays] - mlx->player.y
				+ (1 - mlx->ray.step_y) / 2) / mlx->ray.dir_y;
		mlx->ray.vertical_hit[rays] = 0;
	}
}
