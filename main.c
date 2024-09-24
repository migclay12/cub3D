/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:35 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/24 20:05:45 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
	t_map		map;

    ft_memset(&map, 0, sizeof(t_map));
	if (argc != 2)
		ft_print_error("A map name has not been provided");
	if (argc == 2)
		map.name = argv[1];
	ft_all_map(&map);
}