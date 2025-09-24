/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:49:47 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/29 16:15:30 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	cardinal_player(t_mlx *mlx, int *y, int *x)
{
	if (mlx->map.matrix[*y - 1][*x - 1] == PLAYER_N)
		mlx->player.angle = 3 * M_PI / 2;
	else if (mlx->map.matrix[*y - 1][*x - 1] == PLAYER_E)
		mlx->player.angle = 0;
	else if (mlx->map.matrix[*y - 1][*x - 1] == PLAYER_S)
		mlx->player.angle = M_PI_2;
	else
		mlx->player.angle = M_PI;
}

void	init_the_player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	x = 0;
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
	mlx->player.x = (double)(x - 1) *BLOCK_SIZE + BLOCK_SIZE / 2;
	mlx->player.y = (double)(y - 1) *BLOCK_SIZE + BLOCK_SIZE / 2;
	cardinal_player(mlx, &y, &x);
	mlx->map.matrix[y - 1][x - 1] = '0';
	return ;
}

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
	init_the_player(&mlx);
	init_graphics(&mlx);
	return (NULL);
}
