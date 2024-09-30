/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:54 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/25 21:16:21 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "defines.h"
# include "structs.h"
//# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>

void	ft_all_map(t_map *map, t_mlx *mlx, t_wall_path *path);
void check_start_map(t_map *map, t_wall_path *path);
void	start_the_game(t_mlx mlx);

//Errors
void	ft_print_error(char *str);
void	ft_char_error(t_map *map, char c, int i, int error);
void	ft_char_error_wall(t_map *map, int y, int x, char c);

//Utils
void	ft_free_matrix(char **matrix);
char	**ft_free_map(char **matrix, int i);
char *remove_spaces(char *str);
char	*ft_str(const char *s, int c);

//Validate
void	ft_validate(t_map *map);
#endif