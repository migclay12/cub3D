
#include "cub3d.h"

/* void	ft_reles(int keydata, t_mlx *mlx)	// release the key
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->player.l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->player.l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->player.u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->player.u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->player.rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->player.rot = 0;
}

// key press
void mlx_key(int keydata, void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
		ft_exit(mlx);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS)) // move left
		mlx->player.l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS)) // move right
		mlx->player.l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS)) // move down
		mlx->player.u_d = -1;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS)) // move up
		mlx->player.u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) // rotate left
		mlx->player.rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) // rotate right
		mlx->player.rot = 1;
	//printf("KEY: %d\n", keydata.key);
	//ft_reles(keydata, mlx);
}

void	move_player(t_mlx *mlx, double move_x, double move_y)	// move the player
{
	//int		map_grid_y;
	//int		map_grid_x; 
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->player.plyr_x + move_x); // get the new x position
	new_y = roundf(mlx->player.plyr_y + move_y); // get the new y position
 	//map_grid_x = (new_x / BLOCK_SIZE); // get the x position in the map
	//map_grid_y = (new_y / BLOCK_SIZE); // get the y position in the map
		mlx->player.plyr_x = new_x; // move the player
		mlx->player.plyr_y = new_y; // move the player
}

void	rotate_player(t_mlx *mlx, int i)	// rotate the player
{
	if (i == 1)
	{
		mlx->player.angle += ROTATION_SPEED; // rotate right
		if (mlx->player.angle > 2 * M_PI)
			mlx->player.angle -= 2 * M_PI;
	}
	else
	{
		mlx->player.angle -= ROTATION_SPEED; // rotate left
		if (mlx->player.angle < 0)
			mlx->player.angle += 2 * M_PI;
	}
}

void	hook(t_mlx *mlx, double move_x, double move_y)	// hook the player
{
	if (mlx->player.rot == 1) //rotate right
		rotate_player(mlx, 1);
	if (mlx->player.rot == -1) //rotate left
		rotate_player(mlx, 0);
	if (mlx->player.l_r == 1) //move right
	{
		move_x = -cos(mlx->player.angle) * PLAYER_SPEED;
		move_y = -sin(mlx->player.angle) * PLAYER_SPEED;		
	}
	if (mlx->player.l_r == -1) //move left
	{
		move_x = cos(mlx->player.angle) * PLAYER_SPEED;
		move_y = sin(mlx->player.angle) * PLAYER_SPEED;
	}
	if (mlx->player.u_d == 1) //move up
	{
		move_x = -sin(mlx->player.angle) * PLAYER_SPEED;
		move_y = cos(mlx->player.angle) * PLAYER_SPEED;
	}
	if (mlx->player.u_d == -1) //move down
	{
		move_x = sin(mlx->player.angle) * PLAYER_SPEED;
		move_y = -cos(mlx->player.angle) * PLAYER_SPEED;
	}
	move_player(mlx, move_x, move_y); // move the player
} */
