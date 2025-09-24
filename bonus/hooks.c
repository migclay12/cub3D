/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:49:06 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 13:42:17 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	update_player(t_mlx *mlx)
{
	if (mlx->player.rot_l)
		player_rotate(mlx, -ROTATION_SPEED);
	if (mlx->player.rot_r)
		player_rotate(mlx, ROTATION_SPEED);
	if (mlx->player.move_no)
		player_move(mlx, MOVE_SPEED, 0);
	if (mlx->player.move_so)
		player_move(mlx, MOVE_SPEED, M_PI);
	if (mlx->player.move_we)
		player_move(mlx, MOVE_SPEED, -M_PI_2);
	if (mlx->player.move_ea)
		player_move(mlx, MOVE_SPEED, M_PI_2);
	return ;
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_exit(mlx);
	if (keycode == KEY_E)
		toggle_door(mlx);
	if (keycode == KEY_LEFT)
		mlx->player.rot_l = 1;
	if (keycode == KEY_RIGHT)
		mlx->player.rot_r = 1;
	if (keycode == KEY_W)
		mlx->player.move_no = 1;
	if (keycode == KEY_S)
		mlx->player.move_so = 1;
	if (keycode == KEY_A)
		mlx->player.move_we = 1;
	if (keycode == KEY_D)
		mlx->player.move_ea = 1;
	return (0);
}

int	on_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_LEFT)
		mlx->player.rot_l = 0;
	if (keycode == KEY_RIGHT)
		mlx->player.rot_r = 0;
	if (keycode == KEY_W)
		mlx->player.move_no = 0;
	if (keycode == KEY_S)
		mlx->player.move_so = 0;
	if (keycode == KEY_A)
		mlx->player.move_we = 0;
	if (keycode == KEY_D)
		mlx->player.move_ea = 0;
	return (0);
}
