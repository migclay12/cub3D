/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:47:34 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/09 17:47:34 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_print_error(t_mlx *mlx, char *str)
{
	printf("Error, %s\n", str);
	printf("\n");
	ft_exit(mlx);
	exit(0);
}

void	ft_texture_higher(t_mlx *mlx, int *textures)
{
	if (textures[NO] > 1)
		mlx->map.error = "there is an extra NO texture";
	if (textures[EA] > 1)
		mlx->map.error = "there is an extra EA texture";
	if (textures[SO] > 1)
		mlx->map.error = "there is an extra SO texture";
	if (textures[WE] > 1)
		mlx->map.error = "there is an extra WE texture";
	if (textures[F] > 1)
		mlx->map.error = "there is an extra F color";
	if (textures[C] > 1)
		mlx->map.error = "there is an extra C color";
	mlx->map.flag_error = 1;
}

void	ft_texture_lower(t_mlx *mlx, int *textures)
{
	if (textures[NO] < 1)
		mlx->map.error = "the NO texture is missing";
	if (textures[EA] < 1)
		mlx->map.error = "the EA texture is missing";
	if (textures[SO] < 1)
		mlx->map.error = "the SO texture is missing";
	if (textures[WE] < 1)
		mlx->map.error = "the WE texture is missing";
	if (textures[F] < 1)
		mlx->map.error = "the F color is missing";
	if (textures[C] < 1)
		mlx->map.error = "the C color is missing";
	mlx->map.flag_error = 1;
}

void	ft_texture_error(t_mlx *mlx, int *textures)
{
	ft_texture_lower(mlx, textures);
	ft_texture_higher(mlx, textures);
}

void	ft_texture_error_2(t_mlx *mlx, int *textures)
{
	if ((textures[NO] == 1 && textures[SO] == 1 && textures[EA] == 1
			&& textures[WE] == 1 && textures[C] == 1 && textures[F] == 1))
		return ;
	else
		mlx->map.error = "invalid character detected";
}
