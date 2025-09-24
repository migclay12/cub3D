/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordenadas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:06:08 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:14 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	cardinal_count(t_mlx *mlx, char *line, int idx, int *textures)
{
	int		flag_color;
	int		flag_texture;

	flag_texture = cardinal_save(mlx, textures, idx, line);
	flag_color = color_save(mlx, textures, idx, line);
	if ((line[idx] > 32 && line[idx] <= 126 && line[idx] != 49)
		&& (!flag_color && !flag_texture))
		ft_texture_error_2(mlx, textures);
	if ((textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1
			|| textures[WE] != 1 || textures[C] != 1 || textures[F] != 1)
		&& line[idx] == 49)
		ft_texture_error(mlx, textures);
	if ((textures[NO] == 1 || textures[SO] == 1 || textures[EA] == 1
			||textures[WE] == 1 || textures[C] == 1 || textures[F] == 1)
		&& line[idx] == 49 && mlx->map.flag == 0)
	{
		ft_map_size(mlx, line);
		mlx->map.flag = 1;
	}
}

void	textures_error(int *textures, t_mlx *mlx)
{
	if (textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 \
		|| textures[WE] != 1 || textures[C] != 1 || textures[F] != 1)
		ft_texture_error(mlx, textures);
	free (textures);
	if (mlx->map.flag_error == 1)
		ft_print_error(mlx, mlx->map.error);
}

void	check_start_map(t_mlx *mlx)
{
	t_wall_path	path;
	char		*line;
	int			idx;
	int			*textures;

	textures = calloc(6, sizeof(int));
	ft_memset(&path, 0, sizeof(t_wall_path));
	line = get_next_line(mlx->map.fd);
	while (line)
	{
		idx = 0;
		while (line[idx] == ' ')
			idx++;
		cardinal_count(mlx, line, idx, textures);
		free(line);
		line = get_next_line(mlx->map.fd);
		if (mlx->map.flag)
			ft_map_size(mlx, line);
		if (!mlx->map.flag)
			mlx->map.start_line++;
	}
	textures_error(textures, mlx);
}
