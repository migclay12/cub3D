/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:04 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 17:43:04 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_pixel_img(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0xFF0000);
	return (*(unsigned int *)(img->addr + (y * img->line)
		+ (x * img->bpp / 8)));
}

void	ft_free_rays(t_mlx *mlx)
{
	free(mlx->ray.distances);
	free(mlx->ray.ray_x);
	free(mlx->ray.ray_y);
	free(mlx->ray.vertical_hit);
	free(mlx->ray.ray_dir_x);
	free(mlx->ray.ray_dir_y);
	free(mlx->ray.door);
}

void	paint_fc(t_mlx *mlx, int i)
{
	int	j;

	j = 0;
	while (j <= S_H)
	{
		if (j > S_H / 2)
			put_px(i, j, mlx->colors.flo, &mlx->img);
		else if (j <= S_H / 2)
			put_px(i, j, mlx->colors.cei, &mlx->img);
		j++;
	}
}

void	ft_init_malloc_ray(t_mlx *mlx)
{
	mlx->ray.distances = (double *)malloc(sizeof(double) * S_W);
	if (!mlx->ray.distances)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.ray_x = (double *)malloc(sizeof(double) * S_W);
	if (!mlx->ray.ray_x)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.ray_y = (double *)malloc(sizeof(double) * S_W);
	if (!mlx->ray.ray_y)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.vertical_hit = (int *)malloc(sizeof(int) * S_W);
	if (!mlx->ray.vertical_hit)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.ray_dir_x = (double *)malloc(sizeof(double) * S_W);
	if (!mlx->ray.ray_dir_x)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.ray_dir_y = (double *)malloc(sizeof(double) * S_W);
	if (!mlx->ray.ray_dir_y)
		ft_print_error(mlx, "Malloc error in raycasting");
	mlx->ray.door = (bool *)malloc(sizeof(bool) * S_W);
	if (!mlx->ray.door)
		ft_print_error(mlx, "Malloc error in raycasting");
}
