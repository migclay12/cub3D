/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:51:22 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/17 20:23:21 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_loop(t_mlx	*mlx)
{
	update_player(mlx);
	//printf("ON_LOOP1\n");
	//mlx_clear_window(mlx->ptr, mlx->win); //Epileptic function

	//Esto sirve para que se actualize la imagen
	//Clear the image buffer (set all pixels to a background color, e.g., black)
	int *pixels = (int *)mlx->img.addr;
	for (int i = 0; i < (S_W * S_H); i++)
		pixels[i] = 0x000000;  // Set all pixels to black
		
	//printf("ON_LOOP2\n");
	draw_minimap(mlx);
	//printf("ON_LOOP3\n");
	draw_walls(mlx);
	//printf("ON_LOOP4\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	//printf("ON_LOOP5\n");
	return (0);
}

static inline void	hook_events(t_mlx *mlx)
{
	//printf("HOOK_EVENTS\n");
	mlx_loop_hook(mlx->ptr, on_loop, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, on_key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, on_key_release, mlx);
	return ;
}

char	*init_graphics(t_mlx *mlx)
{
	//printf("INIT_GRAPHICS\n");
	mlx->ptr = mlx_init();
	//printf("INIT_GRAPHICS1\n");
	mlx->win = mlx_new_window(mlx->ptr, S_W, S_H, "work you little fuck");
	//printf("INIT_GRAPHICS2\n");
	mlx->img.ptr = mlx_new_image(mlx->ptr, S_W, S_H);
	//printf("INIT_GRAPHICS3\n");
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.line, &mlx->img.end);
	//printf("INIT_GRAPHICS4\n");
	hook_events(mlx);
	printf("INIT_GRAPHICS5\n");
	mlx_loop(mlx->ptr);
	printf("la locuraaaaaaaaaaaaaaaaaaaaaaaa\n");
	return (NULL);
}

void	init_the_player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (flag == 0 && mlx->map.matrix[y])
	{
		x = 0;
		while (flag == 0 && mlx->map.matrix[y][x] != '\0')
		{
			if (ft_str(P_STARTS, mlx->map.matrix[y][x]))
				flag = 1;
			x++;
		}
		y++;
	}
	mlx->player.plyr_x = (double)(x - 1) * BLOCK_SIZE + BLOCK_SIZE / 2;
	mlx->player.plyr_y = (double)(y - 1) * BLOCK_SIZE + BLOCK_SIZE / 2;
	if (mlx->map.matrix[y - 1][x - 1] == PLAYER_N)
		mlx->player.angle = 3 * M_PI / 2;
	else if (mlx->map.matrix[y - 1][x - 1] == PLAYER_E)
		mlx->player.angle = 0;
	else if (mlx->map.matrix[y - 1][x - 1] == PLAYER_S)
		mlx->player.angle = M_PI_2;
	else
		mlx->player.angle = M_PI;
	mlx->map.matrix[y - 1][x - 1] = '0';
	return ;
}

/* void	save_xpm(t_mlx *mlx)
{
	//mlx->path.NO_path
	mlx->ray.wall_no = mlx_xpm_file_to_image(mlx->ptr,
				"textures/purplestone.xpm", BLOCK_SIZE, BLOCK_SIZE);
} */

char	*init_game(t_mlx mlx)
{
	t_img		img;
	t_player	player;
	t_ray		ray;

	ft_memset(&img, 0, sizeof(t_img));
	ft_memset(&player, 0, sizeof(t_player));
	ft_memset(&ray, 0, sizeof(t_ray));
	img.h = S_H;
	img.w = S_W;
	mlx.img.h = img.h;
	mlx.img.w = img.w;
	//printf("INIT_GAME\n");
	init_the_player(&mlx);

	//save_xpm(&mlx);
	
	//printf("INIT_GAME1\n");

	init_graphics(&mlx);
	
	//printf("INIT_GAME2\n");
	return (NULL);
}
