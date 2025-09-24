/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:24:06 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 12:39:08 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_free_path(t_mlx *mlx)
{
	free(mlx->path.no_path);
	free(mlx->path.ea_path);
	free(mlx->path.so_path);
	free(mlx->path.we_path);
	free(mlx->path.f_color);
	free(mlx->path.c_color);
}

void	ft_destroy_images(t_mlx *mlx)
{
	if (!mlx->ptr)
		return ;
	if (mlx->colors.wall_no.ptr)
		mlx_destroy_image(mlx->ptr, mlx->colors.wall_no.ptr);
	if (mlx->colors.wall_ea.ptr)
		mlx_destroy_image(mlx->ptr, mlx->colors.wall_ea.ptr);
	if (mlx->colors.wall_so.ptr)
		mlx_destroy_image(mlx->ptr, mlx->colors.wall_so.ptr);
	if (mlx->colors.wall_we.ptr)
		mlx_destroy_image(mlx->ptr, mlx->colors.wall_we.ptr);
	if (mlx->colors.door.ptr)
		mlx_destroy_image(mlx->ptr, mlx->colors.door.ptr);
	if (mlx->img.ptr)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
}

int	ft_exit(t_mlx *mlx)
{
	ft_free_matrix(mlx->map.matrix);
	ft_free_path(mlx);
	ft_destroy_images(mlx);
	if (mlx->ptr && mlx->win)
		mlx_clear_window(mlx->ptr, mlx->win);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	exit(0);
}
