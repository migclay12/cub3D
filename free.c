/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:24:06 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/24 14:24:15 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_path(t_mlx *mlx)
{
	free(mlx->path.NO_path);
	free(mlx->path.EA_path);
	free(mlx->path.SO_path);
	free(mlx->path.WE_path);
	free(mlx->path.F_color);
	free(mlx->path.C_color);
}

void	ft_destroy_images(t_mlx *mlx)
{
	if (!mlx->ptr)
		return ;
	if (mlx->ray.wall_no.ptr)
		mlx_destroy_image(mlx->ptr, mlx->ray.wall_no.ptr);
	if (mlx->ray.wall_ea.ptr)
		mlx_destroy_image(mlx->ptr, mlx->ray.wall_ea.ptr);
	if (mlx->ray.wall_so.ptr)
		mlx_destroy_image(mlx->ptr, mlx->ray.wall_so.ptr);
	if (mlx->ray.wall_we.ptr)
		mlx_destroy_image(mlx->ptr, mlx->ray.wall_we.ptr);
}

int	ft_exit(t_mlx *mlx)
{
	ft_free_matrix(mlx->map.matrix);
	ft_free_path(mlx);
	ft_destroy_images(mlx);
	mlx_clear_window(mlx->ptr, mlx->win);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	printf("Game closed\n");
	exit(0);
}