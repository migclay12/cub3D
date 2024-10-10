/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordenadas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:06:08 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/09 18:03:32 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_coordenadas(int *textures, t_wall_path *path)
{
	printf("numemro de NO es %d\n", textures[NO]);
	printf("numero de SO es %d\n", textures[SO]);
	printf("numero EA es %d\n", textures[EA]);
	printf("numero WE es %d\n", textures[WE]);
	printf("numero C es %d\n", textures[C]);
	printf("numero F es %d\n", textures[F]);

	printf("PATH de NO es %s", path->NO_path);
	printf("PATH de SO es %s", path->SO_path);
	printf("PATH de EA es %s", path->EA_path);
	printf("PATH de WE es %s", path->WE_path);
	printf("C_COLOR es %s", path->C_color);
	printf("F_COLOR es %s", path->F_color);
}

void	save_path(char **cardinal, char *line, int idx, int sum_idx)
{
	idx = idx + sum_idx;
	while (line[idx] == ' ')
		idx++;
	*cardinal = ft_strdup(&line[idx]); //FREEEEE CUANDO ACABEMOS DE USARLLO
}

int	color_save(int *textures, t_wall_path *path, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "C ", 2) == 0)
	{
		textures[C]++;
		save_path(&path->C_color, line, idx, 2);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "F ", 2) == 0)
	{
		textures[F]++;
		save_path(&path->F_color, line, idx, 2);
		return (1);
	}
	return (0);
}

int	cardinal_save(int *textures, t_wall_path *path, int idx, char *line)
{
	if (ft_strncmp(&line[idx], "NO ", 3) == 0)
	{
		textures[NO]++;
		save_path(&path->NO_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "SO ", 3) == 0)
	{
		textures[SO]++;
		save_path(&path->SO_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "EA ", 3) == 0)
	{
		textures[EA]++;
		save_path(&path->EA_path, line, idx, 3);
		return (1);
	}
	else if (ft_strncmp(&line[idx], "WE ", 3) == 0)
	{
		textures[WE]++;
		save_path(&path->WE_path, line, idx, 3);
		return (1);
	}
	return (0);
}

//Solo puede tener 4 argumentos
int	cardinal_count(char *line, int idx, int *textures, t_wall_path *path, t_map *map)
{
	int flag_color;
	int flag_texture;

	flag_texture = cardinal_save(textures, path, idx, line);
	flag_color = color_save(textures, path, idx, line);
	if ((line[idx] > 32 && line[idx] <= 126 && line[idx] != 49) && (!flag_color && !flag_texture))
		ft_print_error("Caracter no valido identificado");
	if ((textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 || 
			textures[WE] != 1 || textures[C] != 1 || textures[F] != 1) && line[idx] == 49)
		ft_print_error("un uno se ha perdido");
	if ((textures[NO] == 1 || textures[SO] == 1 || textures[EA] == 1 || 
	textures[WE] == 1 || textures[C]== 1 || textures[F]== 1) && line[idx] == 49 && map->flag == 0)
	{
		map->line_start_map = ft_strdup(line); //Free this at some point
		map->flag = 1;
	} 
	return (map->flag);
}

void	check_start_map(t_map *map, t_wall_path *path)
{
	char	*line;
	int		idx;
	int		flag;
	int		*textures = calloc(6, sizeof(int));
	
	map->flag = 0;
	flag = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		idx = 0;
		while (line[idx] == ' ')
			idx++;
		flag = cardinal_count(line, idx, textures, path, map);
		free(line);
		line = get_next_line(map->fd);
		if (flag == 0)
			map->start_line++;
	}
	if (textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 \
		|| textures[WE] != 1 || textures[C] != 1 || textures[F] != 1)
		ft_print_error("falta o sobra info\n");
	//check_coordenadas(textures, path);
	free (textures);
}
