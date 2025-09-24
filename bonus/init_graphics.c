/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:51:22 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 16:42:46 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	update_mouse(t_mlx *mlx)
{
	int			mouse_x;
	int			mouse_y;
	const float	sensitivity = 0.1f;
	float		new_angle;
	int			delta_x;

	mlx_mouse_get_pos(mlx->ptr, mlx->win, &mouse_x, &mouse_y);
	delta_x = mouse_x - (S_W / 2);
	new_angle = mlx->player.angle + delta_x * sensitivity;
	new_angle = fmod(new_angle + ANGLE_MAX, ANGLE_MAX);
	mlx->player.angle += (new_angle - mlx->player.angle) * SMOOTHING_FACTOR;
	mlx_mouse_move(mlx->ptr, mlx->win, S_W / 2, mouse_y);
}

int	on_loop(t_mlx	*mlx)
{
	int		*pixels;
	int		i;

	i = 0;
	update_player(mlx);
	pixels = (int *)mlx->img.addr;
	while (i < (S_W * S_H))
	{
		pixels[i] = 0x000000;
		i++;
	}
	draw_walls(mlx);
	draw_minimap(mlx);
	update_mouse(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	return (0);
}

void	hook_events(t_mlx *mlx)
{
	mlx_loop_hook(mlx->ptr, on_loop, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, on_key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, on_key_release, mlx);
	return ;
}

void	init_graphics(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		ft_print_error(mlx, "Game not initialized properly");
	mlx->win = mlx_new_window(mlx->ptr, S_W, S_H, "cub3D");
	if (!mlx->win)
		ft_print_error(mlx, "Window not initialized properly");
	mlx->img.ptr = mlx_new_image(mlx->ptr, S_W, S_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.line, &mlx->img.end);
	if (!mlx->img.ptr)
		ft_print_error(mlx, "Image pointer not initalized properly");
	save_xpm(mlx);
	ft_save_colors(mlx);
	hook_events(mlx);
	mlx_loop(mlx->ptr);
	return ;
}
