/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:22 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/17 22:11:21 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_ray(t_mlx *mlx, double x, double y)
{
	//printf("IS_RAY START\n");
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK_SIZE);
	map_y = (int)(y / BLOCK_SIZE);
	//printf("IS_RAY BUCLE\n");
	if (map_x < mlx->map.size_x || map_x > 0 || map_y > 0 \
		|| map_y < mlx->map.size_y)
		{
			//printf("IS_RAY %c\n", mlx->map.matrix[map_y][map_x]);
			if (mlx->map.matrix[map_y][map_x] == '1')
				return (1);
			else if (mlx->map.matrix[map_y][map_x] == '0')
				return (0);
		}
	//printf("IS_RAY RETURN\n");
	return (1);
}

void draw_vertical_line(t_mlx *mlx, int x, int start_y, int end_y, int color)
{
/* 	if (start_y > end_y)
	{
		int tmp = start_y;
		start_y = end_y;
		end_y = tmp;
	}

	if (x < 0 || start_y < 0 || end_y >= S_H || x >= S_W)
		return ; */

	for (int y = start_y; y <= end_y; y++)
		put_px(x, y, color, &mlx->img);
		//mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
}

double *draw_ray(t_mlx *mlx)
{
	float ray_step = 0.5;
	float angle = mlx->player.angle - (VIEW_ANGLE_120 / 2.0);  // Correct initial angle
	int rays = 0;
	double *distances = (double *)malloc(sizeof(double) * 1920);

	while (rays < 1920)
	{
		float dir_x = cos(angle);
		float dir_y = sin(angle);
		float ray_x = mlx->player.plyr_x;
		float ray_y = mlx->player.plyr_y;
		float prev_x = ray_x;
		float prev_y = ray_y;

		while (is_wall_ray(mlx, ray_x, ray_y) == 0)
		{
			prev_x = ray_x;
			prev_y = ray_y;
			ray_x += dir_x * ray_step;
			ray_y += dir_y * ray_step;
			mlx->ray.x = ray_x;
			mlx->ray.y = ray_y;

			line(mlx, (int)prev_x, (int)prev_y, (int)ray_x, (int)ray_y, 0xff2955);
		}

		distances[rays] = sqrt(pow(ray_x - mlx->player.plyr_x, 2) + pow(ray_y - mlx->player.plyr_y, 2));
		angle += (VIEW_ANGLE_120 / 1920);
		rays++;
	}
	return (distances);
}

int	create_tgrb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void draw_walls(t_mlx *mlx)
{
	int i = 0;
	int j = 0;
	double *distances = draw_ray(mlx);
	double ray_angle = mlx->player.angle - (VIEW_ANGLE_120 / 2.0);

	mlx->ray.flo = create_tgrb(mlx->ray.f_r, mlx->ray.f_g, mlx->ray.f_b);
	mlx->ray.cei = create_tgrb(mlx->ray.c_r, mlx->ray.c_g, mlx->ray.c_b);
	
	while (i < S_W)
	{
		double dist = distances[i];
		if (dist > 0)
		{
			double corrected_dist = dist * cos(ray_angle - mlx->player.angle);
			mlx->ray.wall_height = ((BLOCK_SIZE * 1200) / corrected_dist);

			int wall_start = (S_H / 2) - (mlx->ray.wall_height / 2);
			int wall_end = (S_H / 2) + (mlx->ray.wall_height / 2);

			if (wall_start < 0) wall_start = 0;
			if (wall_end > S_H) wall_end = S_H;
			
			j = 0;
			while (j < S_H / 2)
			{
				put_px(i, j, mlx->ray.cei, &mlx->img);
				//put_px(x, WIN_Y - 1 - y, game->flo, &game->scr);
				j++;
			}
			j = S_H / 2;
			while (j < S_H)
			{
				put_px(i, j, mlx->ray.flo, &mlx->img);
				//put_px(x, WIN_Y - 1 - y, game->flo, &game->scr);
				j++;
			}
			
			draw_vertical_line(mlx, i, wall_start, wall_end, 0xff2955);
		}
		
		i += 1;
		ray_angle += (VIEW_ANGLE_120 / 1920);
	}
	free(distances);
}

/* void	draw_screen(t_game *game, t_ray *rays)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < N_RAYS)
	{
		rays[i].wall_dist *= cos(game->p.dir - rays[i].angle_abs);
		rays[i].wall_height = (int)(WIN_Y / rays[i].wall_dist);
		rays[i].draw_height = rays[i].wall_height;
		if (rays[i].draw_height > WIN_Y)
			rays[i].draw_height = WIN_Y;
		y = -1;
		while (++y < (WIN_Y - rays[i].draw_height) / 2)
		{
			x = i * (WIN_X / N_RAYS) - 1;
			while (++x < (i + 1) * (WIN_X / N_RAYS))
			{
				put_px(x, y, game->cei, &game->scr);
				put_px(x, WIN_Y - 1 - y, game->flo, &game->scr);
			}
		}
		draw_wall(game, &rays[i], i * (WIN_X / N_RAYS), y);
	}
	return ;
} */
