/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:58:31 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 13:44:53 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes_bonus/cub3d_bonus.h"
#include "includes/cub3d.h"

void	draw_floor_minimap(t_mlx *mlx, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	shape.width = BLOCK_SIZE_MAP;
	shape.height = BLOCK_SIZE_MAP;
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (mlx->map.matrix[y][x])
		{
			shape.x = y * BLOCK_SIZE_MAP + sx;
			shape.y = x * BLOCK_SIZE_MAP + sy;
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '0')
				rect(mlx, shape, 0xFFFFFF);
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == 'O')
				rect(mlx, shape, 0x008000);
			x++;
		}
		y++;
	}
	return ;
}

void	draw_walls_minimap(t_mlx *mlx, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (mlx->map.matrix[y][x])
		{
			shape.x = y * BLOCK_SIZE_MAP + sx;
			shape.y = x * BLOCK_SIZE_MAP + sy;
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '1')
				rect(mlx, shape, 0xBB4211);
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == 'D')
				rect(mlx, shape, 0xFF0000);
			x++;
		}
		y++;
	}
	return ;
}

void	draw_player_minimap(t_mlx *mlx, t_shape s, int sx, int sy)
{
	s.width = BLOCK_SIZE_MAP / 2;
	s.height = BLOCK_SIZE_MAP / 2;
	s.x = (int)(mlx->player.y / (BLOCK_SIZE_MAP / 4) + sx - s.width / 2);
	s.y = (int)(mlx->player.x / (BLOCK_SIZE_MAP / 4) + sy - s.height / 2);
	circle(mlx, s, 0x1630BE);
}

void	draw_minimap(t_mlx *mlx)
{
	t_shape	shape;
	int		starty;
	int		startx;

	ft_memset(&shape, 0, sizeof(t_shape));
	shape.x = 0;
	shape.y = 0;
	shape.width = BLOCK_SIZE_MAP;
	shape.height = BLOCK_SIZE_MAP;
	starty = 0;
	startx = 0;
	draw_floor_minimap(mlx, startx, starty, shape);
	draw_walls_minimap(mlx, startx, starty, shape);
	draw_player_minimap(mlx, shape, startx, starty);
}
