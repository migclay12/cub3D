/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:35 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 17:26:43 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (argc < 2)
		ft_print_error(&mlx, "a map name has not been provided");
	if (argc > 2)
		ft_print_error(&mlx, "too many arguments have been provided");
	if (argc == 2)
		mlx.map.name = argv[1];
	ft_all_map(&mlx);
	init_game(mlx);
}
