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

#include "includes/cub3d.h"

void	ft_map_lines(t_mlx *mlx, char *line)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line) - 1)
	{
		if (!ft_str(VAL_CHAR, line[i]))
		{
			mlx->map.flag_error = 1;
			mlx->map.error = "there is an unidentified char in the map";
		}
		if (ft_str(P_STARTS, line[i]))
			mlx->map.start++;
		if (mlx->map.start > 1)
		{
			mlx->map.flag_error = 1;
			mlx->map.error = "there is an extra start in the map";
		}
		i++;
	}
}

void	ft_map_size(t_mlx *mlx, char *line)
{
	char	*temp;

	if (line != NULL)
	{
		if (line)
			temp = remove_spaces(line);
		if (temp != NULL)
		{
			mlx->map.size_y++;
			if (line && (int)ft_strlen(temp) - 1 > mlx->map.size_x)
				mlx->map.size_x = ft_strlen(temp) - 1;
			if (line)
				ft_map_lines(mlx, temp);
			if (line && (int)ft_strlen(temp) - 1 != 0
				&& mlx->map.flag_null == -1)
			{
				mlx->map.flag_error = 1;
				mlx->map.error = "there is an empty line in the map";
			}
		}
		else
			mlx->map.flag_null = -1;
	}
}

void	ft_iter_map(t_mlx *mlx)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < mlx->map.start_line)
	{
		temp = get_next_line(mlx->map.fd);
		free (temp);
		i++;
	}
}

char	**ft_save_map(t_mlx *mlx)
{
	int		i;
	char	*temp;

	ft_iter_map(mlx);
	mlx->map.matrix = malloc(sizeof(char **) * (mlx->map.size_y + 1));
	if (!mlx->map.matrix)
		return (0);
	i = 0;
	while (i < mlx->map.size_y)
	{
		temp = get_next_line(mlx->map.fd);
		mlx->map.matrix[i] = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (!mlx->map.matrix[i])
		{
			free(temp);
			return (ft_free_map(mlx->map.matrix, i));
		}
		ft_strlcpy(mlx->map.matrix[i], temp, ft_strlen(temp) + 1);
		free (temp);
		i++;
	}
	ft_finish_map(mlx);
	mlx->map.matrix[i] = NULL;
	return (mlx->map.matrix);
}

void	ft_all_map(t_mlx *mlx)
{
	t_map		map;

	ft_memset(&map, 0, sizeof(t_map));
	init_map(mlx);
	ft_open_file(mlx);
	check_start_map(mlx);
	close (mlx->map.fd);
	if (mlx->map.start == 0)
		ft_print_error(mlx, "the start is missing");
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	mlx->map.matrix = ft_save_map(mlx);
	close (mlx->map.fd);
	ft_validate(mlx, &mlx->map);
	ft_free_matrix(mlx->map.matrix);
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	mlx->map.matrix = ft_save_map(mlx);
	close (mlx->map.fd);
}
