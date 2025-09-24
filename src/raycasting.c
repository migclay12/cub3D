/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:22 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 13:02:01 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	save_info_rays(t_mlx *mlx, int rays, double dir_x, double dir_y)
{
	mlx->ray.ray_x[rays] = mlx->player.x;
	mlx->ray.ray_y[rays] = mlx->player.y;
	mlx->ray.ray_dir_x[rays] = dir_x;
	mlx->ray.ray_dir_y[rays] = dir_y;
}

void	draw_ray(t_mlx *mlx)
{
	int		rays;
	double	angle;

	rays = 0;
	angle = mlx->player.angle - (FOV / 2.0);
	ft_init_malloc_ray(mlx);
	while (rays < S_W)
	{
		mlx->ray.dir_x = cos(angle);
		mlx->ray.dir_y = sin(angle);
		mlx->ray.delta_dist_x = fabs(1 / mlx->ray.dir_x);
		mlx->ray.delta_dist_y = fabs(1 / mlx->ray.dir_y);
		save_info_rays(mlx, rays, mlx->ray.dir_x, mlx->ray.dir_y);
		calculate_step_x(mlx);
		calculate_step_y(mlx);
		get_final_distance(mlx, rays);
		angle += (FOV / S_W);
		rays++;
	}
}

void	draw_wall_ew(t_mlx *mlx, int start_x, int wall_start, int num)
{
	t_img	*img;
	int		dx;
	int		dy;
	int		tx;
	int		ty;

	dx = 0;
	if (mlx->ray.ray_dir_x[num] > 0)
		img = &mlx->colors.wall_ea;
	else
		img = &mlx->colors.wall_we;
	while (dx < (S_W / S_W))
	{
		dy = 0;
		while (dy < mlx->ray.draw_h)
		{
			tx = (int)((int)mlx->ray.ray_y[num] % img->w);
			ty = (int)(((double)dy / mlx->ray.draw_h) * img->h);
			put_px(start_x + dx, wall_start + dy,
				get_pixel_img(img, tx, ty), &mlx->img);
			dy++;
		}
		dx++;
	}
}

void	draw_wall_ns(t_mlx *mlx, int start_x, int wall_start, int num)
{
	t_img	*img;
	int		dx;
	int		dy;
	int		tx;
	int		ty;

	dx = 0;
	if (mlx->ray.ray_dir_y[num] > 0)
		img = &mlx->colors.wall_so;
	else
		img = &mlx->colors.wall_no;
	while (dx < (S_W / S_W))
	{
		dy = 0;
		while (dy < mlx->ray.draw_h)
		{
			tx = (int)((int)mlx->ray.ray_x[num] % img->w);
			ty = (int)(((double)dy / mlx->ray.wall_h) * img->h);
			put_px(start_x + dx, wall_start + dy,
				get_pixel_img(img, tx, ty), &mlx->img);
			dy++;
		}
		dx++;
	}
}

void	draw_walls(t_mlx *mlx)
{
	int		i;
	int		s_y;
	double	ray_angle;

	i = 0;
	ray_angle = mlx->player.angle - (FOV / 2.0);
	draw_ray(mlx);
	while (i < S_W)
	{
		if (mlx->ray.distances[i] > 0)
		{
			mlx->ray.wall_h = (BLOCK_SIZE * (S_H)) / \
				(mlx->ray.distances[i] * cos(ray_angle - mlx->player.angle));
			s_y = (S_H / 2) - (mlx->ray.wall_h / 2);
			mlx->ray.draw_h = ((S_H / 2) + (mlx->ray.wall_h / 2)) - s_y;
			paint_fc(mlx, i);
			if (mlx->ray.vertical_hit[i] == 1)
				draw_wall_ew(mlx, i * (S_W / S_W), s_y, i);
			else
				draw_wall_ns(mlx, i * (S_W / S_W), s_y, i);
		}
		i++;
		ray_angle += (FOV / S_W);
	}
	ft_free_rays(mlx);
}
