/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:49:06 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/09 17:51:03 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_mlx *mlx)
{
	ft_free_matrix(mlx->map.matrix);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	//mlx_close_window(mlx->ptr);
	//mlx_terminate(mlx->ptr);
	printf("Game closed\n");
	exit(0);
}

//DOESNT FUCKING WORK
// Function to check for wall collision based on the player's next position
int	is_wall(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK_SIZE);
	map_y = (int)(y / BLOCK_SIZE);
	//printf("Checking Wall: World Position (%f, %f) -> Map Position (%d, %d)\n",
		//x, y, map_x, map_y);
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

void player_move(t_mlx *mlx, double speed, double angle)
{
    double dx;
    double dy;

    // Calculate the direction of movement based on player angle
    angle += mlx->player.angle;
    dx = speed * cos(angle);
    dy = speed * sin(angle);

	//printf("Current Position: (%f, %f)\n", mlx->player.plyr_x, mlx->player.plyr_y);
	//printf("Next Position: (%f, %f)\n", dx, dy);
	//printf("Wall Collision X: %d\n", is_wall(mlx, dx, mlx->player.plyr_y));
	//printf("Wall Collision Y: %d\n", is_wall(mlx, mlx->player.plyr_x, dy));

    // Check if the new position (current position + movement) hits a wall
    if (!is_wall(mlx, mlx->player.plyr_x + dx, mlx->player.plyr_y + dy))
    {
        // If there's no collision, update the player's position
        mlx->player.plyr_x += dx;
        mlx->player.plyr_y += dy;
    }
    return;
}

void	update_player(t_mlx *mlx)
{
	if (mlx->player.rot_l)
		player_rotate(mlx, -ROTATION_SPEED);
	if (mlx->player.rot_r)
		player_rotate(mlx, ROTATION_SPEED);
	if (mlx->player.move_no)
		player_move(mlx, MOVE_SPEED, -M_PI_2);
	if (mlx->player.move_so)
		player_move(mlx, MOVE_SPEED, M_PI_2);
	if (mlx->player.move_we)
		player_move(mlx, MOVE_SPEED, M_PI);
	if (mlx->player.move_ea)
		player_move(mlx, MOVE_SPEED, 0.0);
	return ;
}

int	on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_exit(mlx);
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
