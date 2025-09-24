/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:09 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 14:10:49 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	rect(t_mlx *mlx, t_shape shape, int color)
{
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
