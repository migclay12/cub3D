/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:53 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 17:42:53 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_map(t_mlx *mlx)
{
	mlx->map.size_y = 0;
	mlx->map.size_x = 0;
	mlx->map.start = 0;
	mlx->map.start_line = 0;
	mlx->map.flag = 0;
	mlx->map.flag_null = 0;
	mlx->map.flag_error = 0;
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
	mlx->map.fd = open(mlx->map.name, O_RDONLY);
	if (!ft_map_name(mlx->map.name))
		ft_print_error(mlx, "the file map is not .cub");
	if (mlx->map.fd == -1)
		ft_print_error(mlx, "the map file does not exist");
}

void	ft_finish_map(t_mlx *mlx)
{
	char	*temp;

	temp = get_next_line(mlx->map.fd);
	while (temp)
	{
		free (temp);
		temp = get_next_line(mlx->map.fd);
	}
	free(temp);
}
