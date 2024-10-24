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

//Check the hole fucking thing
//And check the removespaces function because with the changes I think it does't work the same
void	ft_mlx_lines_2(t_mlx *mlx, char *line)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line) - 1)
	{
		//printf("%c - ", line[i]);
		if (!ft_str(VAL_CHAR, line[i]))
			ft_char_error(&mlx->map, line[i], i, WRONG_CHAR);
		if (ft_str(P_STARTS, line[i]))
			mlx->map.start++;
		if (mlx->map.start > 1)
			ft_char_error(&mlx->map, line[i], i, EXTRA_START);
		i++;
	}
}

//The y error message does't work when there are a lot of enters en el
//mapa pq y no cuenta entonces la info es erronea
void	ft_map_size_2(t_mlx *mlx, char *line)
{
	char	*temp;
	//int		flag;

	//flag = 0;
	//printf("LAST LINE MAP1: %s\n", line);
	if (line != NULL)
	{
		//printf("IIIIIIIIIN: %s\n", line);
		if (line)
			temp = remove_spaces(line);
		//printf("IN: %s", temp);
		if (temp != NULL)
		{
			//printf("IM IN TEMP\n");
			mlx->map.size_y++;
			if (line && (int)ft_strlen(temp) - 1 > mlx->map.size_x)
				mlx->map.size_x = ft_strlen(temp) - 1;
			if (line)
				ft_mlx_lines_2(mlx, temp);
			if (line && (int)ft_strlen(temp) - 1 != 0 && mlx->map.flag_null == -1)
				ft_char_error(&mlx->map, ' ', -1, EMPTY_LINE);
		}
		else
			mlx->map.flag_null = -1;
	}
	//printf("Size y: %d\nSize x: %d\n", mlx->map.size_y, mlx->map.size_x);
}

char	**ft_save_map(t_mlx *mlx)
{
	int		i;
	char	*temp;

	//printf("START: %d\n", mlx->map.start_line);
	mlx->map.matrix = malloc(sizeof(char **) * (mlx->map.size_y + 1));
	if (!mlx->map.matrix)
		return (0);
	i = 0;
	while (i < mlx->map.start_line)
	{
		temp = get_next_line(mlx->map.fd);
		//printf("TEMP: %s\n", temp);
		free (temp);
		i++;
	}
	i = 0;
	//printf("IN?! %d\n", mlx->map.size_y);
	while (i < mlx->map.size_y)
	{
		temp = get_next_line(mlx->map.fd);
		if (!temp) //Si quitas esto a veces peta idk why
			printf("ERROR %d\n", i);	
		//printf("TEMP2: %s\n", temp);
		mlx->map.matrix[i] = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (!mlx->map.matrix[i])
		{
			printf("ERROR %d\n", i);	
			return (ft_free_map(mlx->map.matrix, i));
		}
		ft_strlcpy(mlx->map.matrix[i], temp, ft_strlen(temp) + 1);
		free (temp);
		i++;
	}
	mlx->map.matrix[i] = NULL;
	//printf("SUCCES\n");
	return (mlx->map.matrix);
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

void	ft_open_file(t_mlx *mlx)
{
	printf("MAP: %s\n", mlx->map.name);
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	if (!ft_map_name(mlx->map.name))
		ft_print_error("The file map is not .cub");
	if (mlx->map.fd == -1)
		ft_print_error("The file map does not exist");
}

void	ft_print_matrix(t_mlx *mlx)
{
	int	i;

	i = 0;
	//printf("IMN GOING INSANE\n");
	while (i < mlx->map.size_y)
	{
		//printf("wtf\n");
		printf("%s", mlx->map.matrix[i]);
		i++;
	}
}

void init_map(t_mlx *mlx)
{
	mlx->map.size_y = 0;
	mlx->map.size_x = 0;
	mlx->map.start = 0;
	mlx->map.start_line = 0;
	mlx->map.flag = 0;
	mlx->map.flag_null = 0;
}

//save_map coud make it work for mlx->map and map
//so you don't have to open it and close it twice
void	ft_all_map(t_mlx *mlx)
{
	t_map		map;

	ft_memset(&map, 0, sizeof(t_map));
	init_map(mlx);
	ft_open_file(mlx);
	//printf("WTF1\n");
	check_start_map(mlx);
	close (mlx->map.fd);

	//printf("NO MAP: %s\n", mlx->path.NO_path);
	ft_check_rgb(mlx);

	if (mlx->map.start == 0)
		ft_char_error(&mlx->map, ' ', -1, START_MISSING);
	printf("WTF2\n");
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	mlx->map.matrix = ft_save_map(mlx);
	close (mlx->map.fd);
	//printf("WTF3\n");
	ft_validate(&mlx->map);
	//printf("WTF4\n");
	ft_free_matrix(mlx->map.matrix);
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	mlx->map.matrix = ft_save_map(mlx);
	close (mlx->map.fd);
	//ft_print_matrix(mlx);
}
