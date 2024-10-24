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

#include "cub3d.h"

void	ft_print_error(char *str)
{
	printf("Error, %s\n", str);
	//Borrar est \n
	printf("\n");
	exit(0);
}

void	ft_char_error(t_map *map, char c, int i, int error)
{
	if (error == EMPTY_LINE)
		printf("%s: %d:1: there is an empty line in the map\n",
			map->name, map->size_y);
	else if (error == EXTRA_START)
		printf("%s: %d:%d: there is an extra starting point '%c' in the map\n",
			map->name, map->size_y, i, c);
	else if (error == START_MISSING)
		printf("%s: the starting point is missing in the map\n", map->name);
	else
	{
		//printf("Error, invalid char in map '%c' at %d:%d\n",
			//c, map->size_y, i + 1);
		printf("%s: %d:%d: invalid char in map '%c'\n",
			map->name, map->size_y, i + 1, c);
	}
	printf("\n");
	exit(0);
}

void	ft_char_error_wall(t_map *map, int y, int x, char c)
{
	printf("%s: %d:%d: there is an open wall '%c'\n", map->name, y, x, c);
	exit (0);
}
