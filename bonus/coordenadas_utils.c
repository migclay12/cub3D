/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordenadas_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:10:36 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 18:20:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	save_path(char **cardinal, char *line, int idx, int sum_idx)
{
	idx = idx + sum_idx;
	while (line[idx] == ' ')
		idx++;
	*cardinal = ft_strdup(&line[idx]);
}

int	color_save(t_mlx *mlx, int *textures, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "C ", 2) == 0)
	{
		textures[C]++;
		if (textures[C] == 1)
			save_path(&mlx->path.c_color, line, idx, 2);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "F ", 2) == 0)
	{
		textures[F]++;
		if (textures[F] == 1)
			save_path(&mlx->path.f_color, line, idx, 2);
		return (1);
	}
	return (0);
}

int	cardinal_save_ew(int *textures, char *line, t_mlx *mlx, int idx)
{
	if (ft_strncmp(&line[idx], "EA ", 3) == 0)
	{
		textures[EA]++;
		if (textures[EA] == 1)
			save_path(&mlx->path.ea_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "WE ", 3) == 0)
	{
		textures[WE]++;
		if (textures[WE] == 1)
			save_path(&mlx->path.we_path, line, idx, 3);
		return (1);
	}
	return (0);
}

int	cardinal_save(t_mlx *mlx, int *textures, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "NO ", 3) == 0)
	{
		textures[NO]++;
		if (textures[NO] == 1)
			save_path(&mlx->path.no_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "SO ", 3) == 0)
	{
		textures[SO]++;
		if (textures[SO] == 1)
			save_path(&mlx->path.so_path, line, idx, 3);
		return (1);
	}
	if (cardinal_save_ew(textures, line, mlx, idx) == 1)
		return (1);
	return (0);
}
