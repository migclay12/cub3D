/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:20 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 18:08:22 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	save_rgb(t_mlx *mlx, char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = ft_atoi(rgb[i]);
		if (j < 0 || j > 255)
			ft_print_error(mlx, "the rgb number is not between 0 and 255");
		i++;
	}
}

void	check_digit_error(char **rgb, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3 || rgb[i - 1] == NULL)
	{
		ft_free_matrix(rgb);
		ft_print_error(mlx, "there is a color number missing");
	}
}

void	ft_check_digit(t_mlx *mlx, char **rgb)
{
	int	i;
	int	j;

	check_digit_error(rgb, mlx);
	i = 0;
	while (rgb[i])
	{
		j = 0;
		ft_previous_check(mlx, rgb[i]);
		while (j < (int)ft_strlen(rgb[i]) - 1)
		{
			while (rgb[i][j] == ' ')
				j++;
			if (!ft_isdigit(rgb[i][j]) && j < (int)ft_strlen(rgb[i]) - 1)
			{
				ft_free_matrix(rgb);
				ft_print_error(mlx, "there is a character that is not a \
number in the rgb");
			}
			j++;
		}
		i++;
	}
}

void	ft_save_colors(t_mlx *mlx)
{
	ft_check_coma(mlx);
	mlx->colors.rgb = ft_split(mlx->path.f_color, ',');
	ft_check_digit(mlx, mlx->colors.rgb);
	mlx->colors.f_r = ft_atoi(mlx->colors.rgb[0]);
	mlx->colors.f_g = ft_atoi(mlx->colors.rgb[1]);
	mlx->colors.f_b = ft_atoi(mlx->colors.rgb[2]);
	ft_free_matrix(mlx->colors.rgb);
	mlx->colors.rgb = ft_split(mlx->path.c_color, ',');
	ft_check_digit(mlx, mlx->colors.rgb);
	mlx->colors.c_r = ft_atoi(mlx->colors.rgb[0]);
	mlx->colors.c_g = ft_atoi(mlx->colors.rgb[1]);
	mlx->colors.c_b = ft_atoi(mlx->colors.rgb[2]);
	ft_free_matrix(mlx->colors.rgb);
	mlx->colors.flo = create_rgb(mlx->colors.f_r, mlx->colors.f_g,
			mlx->colors.f_b);
	mlx->colors.cei = create_rgb(mlx->colors.c_r, mlx->colors.c_g,
			mlx->colors.c_b);
}
