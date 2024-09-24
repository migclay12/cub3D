/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:59:42 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/24 20:26:40 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_map_size(t_map *map)
{
	char	*line;
	int		i;

	map->size_y = 0;
	line = get_next_line(map->fd);
	map->size_x = ft_strlen(line);
	while (line != NULL)
	{
		i = 0;
		free(line);
		map->size_y++;
		line = get_next_line(map->fd);
		if ((int)ft_strlen(line) > map->size_x)
			map->size_x = ft_strlen(line);
		while (line[i] != '\n')
		{
			if (line[i] != ' ' && line[i] != '1' && line[i] != '0'\
				&& line[i] != 'N' && line[i] != 'E' && line[i] != 'S'\
				&& line[i] != 'W')
				{
					printf("%c", line[i]);
					ft_print_error("There is an invalid character in the map.");
				}
			i++;
		}
	}
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

void ft_open_file(t_map *map)
{
	map->fd = open(map->name, O_RDONLY);
	if (!ft_map_name(map->name))
		ft_print_error("The file map is not .cub");
	if (map->fd == -1)
		ft_print_error("The file map does not exist");
}

void	ft_all_map(t_map *map)
{
	ft_open_file(map);
	ft_map_size(map);
}
