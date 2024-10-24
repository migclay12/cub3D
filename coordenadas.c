/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordenadas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:06:08 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/24 17:08:01 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_coordenadas(int *textures, t_mlx *mlx)
{
	printf("numemro de NO es %d\n", textures[NO]);
	printf("numero de SO es %d\n", textures[SO]);
	printf("numero EA es %d\n", textures[EA]);
	printf("numero WE es %d\n", textures[WE]);
	printf("numero C es %d\n", textures[C]);
	printf("numero F es %d\n", textures[F]);

	printf("PATH de NO es %s\n", mlx->path.NO_path);
	printf("PATH de SO es %s\n", mlx->path.SO_path);
	printf("PATH de EA es %s\n", mlx->path.EA_path);
	printf("PATH de WE es %s\n", mlx->path.WE_path);
	printf("F_COLOR es %s\n", mlx->path.F_color);
	printf("C_COLOR es %s\n", mlx->path.C_color);
}

void	save_path(char **cardinal, char *line, int idx, int sum_idx)
{
	//He cambiado el strlen dentro del strdup restandole uno pq seguia
	//cogiendo algun puto caracter basura y ya me estaba comiendo la cabeza
	//intentando arreglar esa mierda de alguna manera decente
	idx = idx + sum_idx;
	while (line[idx] == ' ')
		idx++;
	*cardinal = ft_strdup(&line[idx]); //FREEEEE CUANDO ACABEMOS DE USARLLO
}

int	color_save(t_mlx *mlx, int *textures, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "C ", 2) == 0)
	{
		textures[C]++;
		save_path(&mlx->path.C_color, line, idx, 2);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "F ", 2) == 0)
	{
		textures[F]++;
		save_path(&mlx->path.F_color, line, idx, 2);
		return (1);
	}
	return (0);
}

int	cardinal_save(t_mlx *mlx, int *textures, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "NO ", 3) == 0)
	{
		textures[NO]++;
		save_path(&mlx->path.NO_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "SO ", 3) == 0)
	{
		textures[SO]++;
		save_path(&mlx->path.SO_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "EA ", 3) == 0)
	{
		textures[EA]++;
		save_path(&mlx->path.EA_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "WE ", 3) == 0)
	{
		textures[WE]++;
		save_path(&mlx->path.WE_path, line, idx, 3);
		return (1);
	}
	return (0);
}

void	cardinal_count(t_mlx *mlx, char *line, int idx, int *textures)
{
	int flag_color;
	int flag_texture;

	flag_texture = cardinal_save(mlx, textures, idx, line);
	flag_color = color_save(mlx, textures, idx, line);
	if ((line[idx] > 32 && line[idx] <= 126 && line[idx] != 49) && (!flag_color && !flag_texture))
		ft_print_error("Caracter no valido identificado");
	if ((textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 || 
			textures[WE] != 1 || textures[C] != 1 || textures[F] != 1) && line[idx] == 49)
		ft_print_error("Falta un color o textura por guardarse o hay de mas");
	if ((textures[NO] == 1 || textures[SO] == 1 || textures[EA] == 1 || 
	textures[WE] == 1 || textures[C]== 1 || textures[F]== 1) && line[idx] == 49 && mlx->map.flag == 0)
	{
		//printf("LINEEEE: %s\n", line);
		ft_map_size_2(mlx, line);
		mlx->map.flag = 1;
	}
}

void	check_start_map(t_mlx *mlx)
{
	t_wall_path	path;
	char		*line;
	int			idx;
	int			*textures = calloc(6, sizeof(int));

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
			ft_map_size_2(mlx, line);
		if (!mlx->map.flag)
			mlx->map.start_line++;
	}
	if (textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 \
		|| textures[WE] != 1 || textures[C] != 1 || textures[F] != 1)
		ft_print_error("falta o sobra info");
	//check_coordenadas(textures, mlx);
	free (textures);
}
