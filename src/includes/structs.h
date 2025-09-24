/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:08:50 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 12:08:50 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_wall
{
	NO,
	SO,
	EA,
	WE,
	C,
	F
}	t_wall;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	int		move_no;
	int		move_so;
	int		move_we;
	int		move_ea;
	int		rot_l;
	int		rot_r;
}	t_player;

typedef struct s_mlx_img
{
	int		w;
	int		h;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
}	t_img;

typedef struct s_map
{
	int			fd;
	char		*name;
	int			size_x;
	int			size_y;
	int			start;
	char		**matrix;
	int			start_line;
	int			flag;
	int			flag_null;
	int			flag_error;
	char		*error;
}	t_map;

typedef struct s_wall_path
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	*c_color;
	char	*f_color;
}	t_wall_path;

typedef struct s_colors
{
	t_img	wall_no;
	t_img	wall_ea;
	t_img	wall_so;
	t_img	wall_we;
	char	**rgb;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		cei;
	int		flo;
}	t_colors;

typedef struct s_ray
{
	double	*distances;
	double	*ray_x;
	double	*ray_y;
	int		*vertical_hit;
	double	*ray_dir_y;
	double	*ray_dir_x;
	int		wall_h;
	int		draw_h;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
}	t_ray;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_wall_path	path;
	t_colors	colors;
}	t_mlx;

#endif