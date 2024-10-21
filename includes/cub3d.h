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

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h> // For uint32_t
# include "../libft/libft.h"
# include "defines.h"
# include "structs.h"
# include "../minilibx-linux/mlx.h"

//# include <errno.h>

void	ft_all_map(t_mlx *mlx);
void    check_start_map(t_mlx *mlx);
void	start_the_game(t_mlx mlx);
void	ft_map_size_2(t_mlx *mlx, char *line);
void	ft_mlx_lines_2(t_mlx *mlx, char *line);

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

//Keys
int	on_key_press(int key, t_mlx *mlx);
int	on_key_release(int key, t_mlx *mlx);
int	ft_exit(t_mlx *mlx);
void	update_player(t_mlx *mlx);
void update_player_position(t_mlx *mlx);
//void mlx_key(mlx_key_data_t keydata, void *ml);

char	*init_game(t_mlx mlx);
void	draw_minimap(t_mlx *mlx);
void    line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color);
void    put_px(int x, int y, int color, t_img *img);
void    draw_arrow(t_mlx *mlx);

//void draw_ray(t_mlx *mlx);
void draw_walls(t_mlx *mlx);

void	ft_check_rgb(t_mlx *mlx);

//double *draw_ray(t_mlx *mlx);

void	save_xpm(t_mlx *mlx);

#endif