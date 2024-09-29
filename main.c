/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:35 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/29 14:04:17 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Hay un leak al liberar la matriz wtf
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// exit the game
void	ft_exit(t_mlx *mlx)
{
	int	i = 0;
	while (mlx->map.matrix[i])
		free(mlx->map.matrix[i]);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p); 
	mlx_terminate(mlx->mlx_p); 
	printf("Game closed\n"); 
	exit(0); 
}

// key press
void mlx_key(mlx_key_data_t keydata, void *ml)	
{
	t_mlx	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
		ft_exit(mlx);
}

// game loop
void	game_loop(void *ml)	
{
	t_mlx	*mlx;

	mlx = ml;	
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); 
}

// start the game
void	start_the_game(t_mlx mlx)
{
	printf("AAAAAAAAAAAA\n");
	mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0);	
	printf("BBBBBBBBBBBB\n");
	mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx);
	printf("CCCCCCCCCCCC\n");
	mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx);
	printf("DDDDDDDDDDDD\n");
	//Con flecha peta, understand why
	mlx_loop(mlx.mlx_p);
	printf("EEEEEEEEEEEE\n");
}


int main(int argc, char **argv)
{
	t_map		map;
	t_mlx		mlx;
	t_wall_path path;

    ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&mlx, 0, sizeof(t_mlx));
	ft_memset(&path, 0, sizeof(t_wall_path));
	
	if (argc != 2)
		ft_print_error("A map name has not been provided");
	if (argc == 2)
	{
		map.name = argv[1];
		mlx.map.name = argv[1];
	}
	ft_all_map(&map, &mlx, &path);

	start_the_game(mlx);
	
	printf("BEFORE FREE\n");
	ft_free_matrix(map.matrix);
	printf("BEFORE FREE2\n");
	ft_free_matrix(mlx.map.matrix);
	//printf("OFFICIAL END\n");
}