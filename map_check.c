/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:59:42 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/26 18:51:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//if in last one no \n or spaces after stuff what do we doo?
void	ft_mlx_lines(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line) - 2)
	{
		//printf("%c - ", line[i]);
		if (!ft_str(VAL_CHAR, line[i]))
			ft_char_error(map, line[i], i, WRONG_CHAR);
		if (ft_str(P_STARTS, line[i]))
			map->start++;
		if (map->start > 1)
			ft_char_error(map, line[i], i, EXTRA_START);
		i++;
	}
}

//The flag is to mlx if there is an empty line in the middle of the file
//Si le metes un enter debajo del mapa cuenta bien las lineas
//do I need temp?
//Y si haces un bucle while i < map->start_line
//que valla pasando lineas con el gnl asi no tienes que hacer comprobaciones raras?
void	ft_map_size(t_map *map)
{
	char	*line;
	char	*temp;
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	map->size_y = 0;
	map->size_x = 0;
	line = "start";
	//printf("LAST LINE MAP1: %s\n", map->line_start_map);
	while (line != NULL)
	{
		line = get_next_line(map->fd);
		//printf("LINEEEE: %s", line);
		if (flag2 == 0 && ft_strncmp(line, map->line_start_map,
				ft_strlen(line)) == 0)
		{
			//printf("WTF?!\n");
			flag2 = 1;
		}
		if (flag2 == 1)
		{
			//printf("IIIIIIIIIN: %s", line);
			if (line)
				temp = remove_spaces(line);
			if (temp != NULL)
			{
				map->size_y++;
				if (line && (int)ft_strlen(temp) - 2 > map->size_x)
					map->size_x = ft_strlen(temp) - 2;
				if (line)
					ft_mlx_lines(map, temp);
				if (line && (int)ft_strlen(temp) - 2 != 0 && flag == -1)
					ft_char_error(map, ' ', -1, EMPTY_LINE);
			}
			else
				flag = -1;
		}
		free(line);
	}
	if (temp != NULL)
		map->size_y--;
	//printf("Size y: %d\nSize x: %d\n", map->size_y, map->size_x);
}

int	ft_map_name(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] == 'b' && map[len - 2] == 'u'
		&& map[len - 3] == 'c' && map[len - 4] == '.')
		return (1);
	return (0);
}

void	ft_open_file(t_map *map)
{
	printf("MAP: %s\n", map->name);
	map->fd = open(map->name, O_RDONLY);
	if (!ft_map_name(map->name))
		ft_print_error("The file map is not .cub");
	if (map->fd == -1)
		ft_print_error("The file map does not exist");
}

char	**ft_save_map(t_map *map)
{
	int		i;
	char	*temp;

	//printf("START: %d\n", map->start_line);
	map->matrix = malloc(sizeof(char **) * (map->size_y + 1));
	if (!map->matrix)
		return (0);
	i = 0;
	while (i < map->start_line)
	{
		temp = get_next_line(map->fd);
		//printf("TEMP: %s", temp);
		free (temp);
		i++;
	}
	i = 0;
	//printf("IN?! %d\n", map->size_y);
	while (i < map->size_y)
	{
		temp = get_next_line(map->fd);
		//printf("TEMP2: %s", temp);
		map->matrix[i] = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (!map->matrix[i])
		{
			//printf("ERROR %d\n", i);	
			return (ft_free_map(map->matrix, i));
		}
		ft_strlcpy(map->matrix[i], temp, ft_strlen(temp) + 1);
		free (temp);
		i++;
	}
	map->matrix[i] = NULL;
	//printf("SUCCES\n");
	return (map->matrix);
}

void	ft_print_matrix(t_map *map)
{
	int	i;

	i = 0;
	//printf("IMN GOING INSANE\n");
	while (i < map->size_y)
	{
		//printf("wtf\n");
		printf("%s", map->matrix[i]);
		i++;
	}
}

//GURADAR MAPA, validarlo, limpiarlo y vlverlo a guardar?
//asi no tienes que tener un map a parte del mlx
//could work, quita muchas lineas
//y organizar los fd wtf XD
void	ft_all_map(t_map *map, t_mlx *mlx, t_wall_path *path)
{
	map->start = 0;
	map->fd = open(map->name, O_RDONLY);
	check_start_map(map, path);
	close (map->fd);
	mlx->map.line_start_map = ft_strdup(map->line_start_map); //Free at some point
	mlx->map.start_line = map->start_line;
	ft_open_file(map);
	ft_open_file(&mlx->map);
	ft_map_size(map);
	ft_map_size(&mlx->map);
	close (map->fd);
	close (mlx->map.fd);
	if (map->start == 0)
		ft_char_error(map, ' ', -1, START_MISSING);
	map->fd = open(map->name, O_RDONLY);
	mlx->map.fd = open(map->name, O_RDONLY);
	map->matrix = ft_save_map(map);
	mlx->map.matrix = ft_save_map(&mlx->map);
	//ft_print_matrix(map);
	ft_print_matrix(&mlx->map);
	//printf("END\n");
	ft_validate(map);
	free(mlx->map.line_start_map);
	free(map->line_start_map);
}
