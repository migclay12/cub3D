/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:35 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/24 17:13:31 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

//Poner los errores in englis
//Comprobar la validacion de muros y cambiar los mensajes pq no coinciden con lo que pasa
//aunq el mensaje viene de coordenadas cuando no encuentra un muro lol

//Fucking remove_spaces has to be remaked
//Check if you put in a solitary line a 1 with nothing else

//maps/bad/forbiden works because the player is protected by walls
//maps/bad/player_on_edge.cub should't work but it fucking does
//maps/bad/wall_hole_north.cub does't see the hole at the top
//maps/bad/wall_hole_south.cub same fucking thing

//Make a lot more of error management
//Errors should liberate the info
//La flecha del minimapa tecncamente no esta en el centro del ugador pero como para darse cuenta
//además igual hay que quitar esa funcion pe es enorme (pero me gusta)

//maps/bad/file_letter_end.cub -- mirar que hacer con eso?
int	main(int argc, char **argv)
{
	t_mlx		mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		ft_print_error("A map name has not been provided");
	if (argc == 2)
		mlx.map.name = argv[1];
	ft_all_map(&mlx);
	init_game(mlx);
	printf("BEFORE FREE\n");
	ft_free_matrix(mlx.map.matrix);
	printf("OFFICIAL END\n");
}