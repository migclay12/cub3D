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
# include "../../libft/libft.h"
# include "defines.h"
# include "structs.h"
# include "../../minilibx-linux/mlx.h"

//Previous checks
void	ft_all_map(t_mlx *mlx);
void	check_start_map(t_mlx *mlx);
void	ft_map_size(t_mlx *mlx, char *line);
void	ft_map_lines(t_mlx *mlx, char *line);
void	ft_validate(t_mlx *mlx, t_map *map);

//Inits
char	*init_game(t_mlx mlx);
void	init_graphics(t_mlx *mlx);
void	init_map(t_mlx *mlx);

//Errors
void	ft_print_error(t_mlx *mlx, char *str);
void	ft_texture_error(t_mlx *mlx, int *textures);
void	ft_texture_error_2(t_mlx *mlx, int *textures);

//Utils
void	ft_finish_map(t_mlx *mlx);
void	ft_open_file(t_mlx *mlx);
void	ft_free_matrix(char **matrix);
char	**ft_free_map(char **matrix, int i);
char	*remove_spaces(char *str);
char	*ft_str(const char *s, int c);
void	ft_print_matrix(t_mlx *mlx);

//Keys
int		on_key_press(int key, t_mlx *mlx);
int		on_key_release(int key, t_mlx *mlx);
void	update_player(t_mlx *mlx);
void	player_move(t_mlx *mlx, double speed, double angle);
void	player_rotate(t_mlx *mlx, double angle);

//Free
int		ft_exit(t_mlx *mlx);

//Raycasting
void	draw_walls(t_mlx *mlx);
void	ft_free_rays(t_mlx *mlx);
void	paint_fc(t_mlx *mlx, int i);
void	ft_init_malloc_ray(t_mlx *mlx);
void	get_final_distance(t_mlx *mlx, int rays);
void	calculate_step_x(t_mlx *mlx);
void	calculate_step_y(t_mlx *mlx);

//Images
void	save_xpm(t_mlx *mlx);
void	put_px(int x, int y, int color, t_img *img);
void	ft_save_colors(t_mlx *mlx);
int		create_rgb(int r, int g, int b);
int		get_pixel_img(t_img *img, int x, int y);
int		cardinal_save(t_mlx *mlx, int *textures, int idx, char *line);

//coordenadas_utils
void	save_path(char **cardinal, char *line, int idx, int sum_idx);
int		color_save(t_mlx *mlx, int *textures, int idx, char *line);

//rgb_utils
void	ft_check_coma(t_mlx *mlx);
void	ft_previous_check(t_mlx *mlx, char *str);

//Bonus
void	draw_minimap(t_mlx *mlx);
void	circle(t_mlx *mlx, t_shape s, int color);
void	rect(t_mlx *mlx, t_shape shape, int color);
void	toggle_door(t_mlx *mlx);

#endif