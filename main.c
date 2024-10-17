/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:35 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/17 20:22:21 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Hay un leak al liberar la matriz wtf
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

//Make a lot more of error management
//Errors should liberate the info
//What happens if F o C existe pero no da info?
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
