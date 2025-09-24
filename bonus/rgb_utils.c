/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:03:18 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 18:04:22 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_previous_check(t_mlx *mlx, char *str)
{
	int	i;
	int	num;
	int	flag;

	flag = 0;
	num = 0;
	i = 0;
	while (i < (int)ft_strlen(str) - 1)
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) && i < (int)ft_strlen(str) - 1)
		{
			num++;
			i++;
		}
		if (flag == 0)
			flag = num;
		if (flag != num)
			ft_print_error(mlx, "there is a space between the numbers");
		i++;
	}
}

void	ft_check_coma(t_mlx *mlx)
{
	int	coma;
	int	i;

	i = 0;
	coma = 0;
	while (mlx->path.f_color[i])
	{
		if (mlx->path.f_color[i] == ',')
			coma++;
		i++;
	}
	if (coma > 2)
		ft_print_error(mlx, "there are too many floor numbers");
	i = 0;
	coma = 0;
	while (mlx->path.c_color[i])
	{
		if (mlx->path.c_color[i] == ',')
			coma++;
		i++;
	}
	if (coma > 2)
		ft_print_error(mlx, "there are too many ceiling numbers");
}
