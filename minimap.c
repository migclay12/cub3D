/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:58:31 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/09 17:59:21 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rect(t_mlx *mlx, t_shape shape, int color)
{
	//printf("RECT\n");
	int	i;
	int	j;

	i = shape.y;
	while (i < shape.y + shape.height && i < S_W)
	{
		j = shape.x;
		while (j < shape.x + shape.width && j < S_H)
		{
			put_px(i, j, color, &mlx->img);
			++j;
		}
		++i;
	}
	return ;
}

void	draw_minimap_floor(t_mlx *mlx, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	shape.width = BLOCK_SIZE;
	shape.height = BLOCK_SIZE;
	//printf("DRAW_FLOOR: %d\n", mlx->map.size_y);
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (x <= mlx->map.size_x)
		{
			shape.x = y * BLOCK_SIZE + sx;
			shape.y = x * BLOCK_SIZE + sy;
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '0')
				rect(mlx, shape, 0xFFFFFFFF);
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
	//printf("DRAW_WALLS\n");
	y = 0;
	x = 0;
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (x <= mlx->map.size_x)
		{
			shape.x = y * BLOCK_SIZE + sx;
			shape.y = x * BLOCK_SIZE + sy;
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '1')
				rect(mlx, shape, 0xBB4211); //RED
			x++;
		}
		y++;
	}
	return ;
}

void	circle(t_mlx *mlx, t_shape s, int color)
{
	int		i;
	int		j;
	double	dist;

	i = s.y;
	while (i < s.y + s.height && i < S_H)
	{
		j = s.x;
		while (j < s.x + s.width && j < S_W)
		{
			dist = sqrt(pow(i - (s.y + s.height / 2), 2)
					+ pow(j - (s.x + s.width / 2), 2));
			if (dist < s.width / 2.0)
				put_px(i, j, color, &mlx->img);
			++j;
		}
		++i;
	}
	return ;
}

void	draw_player_minimap(t_mlx *mlx, t_shape s, int sx, int sy)
{
	s.width = 32;
	s.height = 32;
	s.x = (int)(mlx->player.plyr_y * BLOCK_SIZE + sx - s.width / 2);
	s.y = (int)(mlx->player.plyr_x * BLOCK_SIZE + sy - s.height / 2);
	circle(mlx, s, 0x1630BE);
	draw_arrow(mlx, s);
}

//Could fix floor and walls into one tbh
void	draw_minimap(t_mlx *mlx)
{
	t_shape	shape;
	int		starty;
	int		startx;
	//printf("AAAAAAAAAAAA\n");
	ft_memset(&shape, 0, sizeof(t_shape));
	shape.x = 0;
	shape.width = BLOCK_SIZE;
	shape.height = BLOCK_SIZE;
	starty = 0;
	startx = 0;
	//printf("PLACE: %d\n", mlx->player.plyr_x);
	draw_minimap_floor(mlx, startx, starty, shape);
	//printf("BBBBBBBBBBBB\n");
	draw_walls_minimap(mlx, startx, starty, shape);
	//printf("CCCCCCCCCCCC\n");
	draw_player_minimap(mlx, shape, startx, starty);
	//printf("EEEEEEEEEEEE\n");
}
