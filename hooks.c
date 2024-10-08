#include "cub3d.h"

int	ft_exit(t_mlx *mlx)
{
	//int	i = 0;
	//while (mlx->map.matrix[i])
	//	free(mlx->map.matrix[i]);
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

/* void	player_move(t_mlx *mlx, double speed, double angle)
{
	//double const	diag_speed = SPEED_MOV / sqrt(2.5);
	double			dx;
	double			dy;

	angle += mlx->player.angle;
	// if (moving_diagonal(mlx))
	// 	speed = diag_speed;
	dx = speed * cos(angle);
	dy = speed * sin(angle);
	// if (can_move(mlx, dx, 0))
	// 	mlx->player.pos.x += dx;
	// if (can_move(mlx, 0, dy))
	// 	mlx->player.pos.y += dy;
	return ;
}

void	update_player(t_mlx *mlx)
{
	//if (mlx->player.rotate_l)
	//	player_rotate(mlx, -SPEED_ROT);
	//if (mlx->player.rotate_r)
	//	player_rotate(mlx, SPEED_ROT);
	if (mlx->player.move_no)
	{
		printf("Update NO\n");
		player_move(mlx, PLAYER_SPEED, 0.0);
	}
	if (mlx->player.move_so)
	{
		printf("Update SO\n");
		player_move(mlx, PLAYER_SPEED, M_PI);
	}
	if (mlx->player.move_we)
	{
		printf("Update WE\n");
		player_move(mlx, PLAYER_SPEED, -M_PI_2);
	}
	if (mlx->player.move_ea)
	{
		printf("Update EA\n");
		player_move(mlx, PLAYER_SPEED, M_PI_2);
	}
	return ;
} */

//DOESNT FUCKING WORK
// Function to check for wall collision based on the player's next position
int is_wall(t_mlx *mlx, float x, float y)
{
	int map_x = (int)(x / BLOCK_SIZE);
	int map_y = (int)(y / BLOCK_SIZE);

	//printf("Checking Wall: World Position (%f, %f) -> Map Position (%d, %d)\n", x, y, map_x, map_y);

	if (map_x < 0 || map_x >= mlx->map.size_x || map_y < 0 || map_y >= mlx->map.size_y)
		return 1; // Out of bounds - treat as a wall

	if (mlx->map.matrix[map_y][map_x] == '1')
		return 1;

	return 0;
}


void update_player_position(t_mlx *mlx)
{
	float move_speed = 0.01; // Speed of movement can be adjusted
	float next_x = mlx->player.plyr_x;
	float next_y = mlx->player.plyr_y;

	if (mlx->player.move_no)
		mlx->player.plyr_y -= move_speed;
	if (mlx->player.move_so)
		mlx->player.plyr_y += move_speed;
	if (mlx->player.move_we)
		mlx->player.plyr_x -= move_speed;
	if (mlx->player.move_ea)
		mlx->player.plyr_x += move_speed;

/* 	if (mlx->player.move_no)
		next_y -= move_speed;
	if (mlx->player.move_so)
		next_y += move_speed;
	if (mlx->player.move_we)
		next_x -= move_speed;
	if (mlx->player.move_ea)
		next_x += move_speed;

	printf("Current Position: (%f, %f)\n", mlx->player.plyr_x, mlx->player.plyr_y);
	printf("Next Position: (%f, %f)\n", next_x, next_y);
	printf("Wall Collision X: %d\n", is_wall(mlx, next_x, mlx->player.plyr_y));
	printf("Wall Collision Y: %d\n", is_wall(mlx, mlx->player.plyr_x, next_y)); */

	if (!is_wall(mlx, next_x, mlx->player.plyr_y))  // Check X movement
		mlx->player.plyr_x = next_x;
	if (!is_wall(mlx, mlx->player.plyr_x, next_y))  // Check Y movement
		mlx->player.plyr_y = next_y;
}


int on_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_exit(mlx);
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

int on_key_release(int keycode, t_mlx *mlx)
{
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
