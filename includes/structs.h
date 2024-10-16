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
} t_wall;

typedef struct s_shape
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_shape;

typedef struct s_player //the player structure
{
	double		plyr_x;
	double		plyr_y;
	char		orient;
	double		angle;
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
	int		fd;
	char	*name;
	int		size_x;
	int		size_y;
	int		start;
	char	**matrix;
	char	*line_start_map;
	int		start_line;
	// int		p_x; 
	// int		p_y; 
	// char	p_or;
	int		flag; //temporal para las coordenadas
	t_player	player;
}	t_map;

typedef struct s_wall_path
{
	char *NO_path;
	char *SO_path;
	char *EA_path;
	char *WE_path;
	char *C_color;
	char *F_color;

} t_wall_path;

typedef struct s_ray
{
	double		x;
	double		y;
	//double		long_ray;
	double		wall_dist;
	int			wall_height;
	void		*wall_no;
	void		*wall_ae;
	void		*wall_so;
	void		*wall_we;
	t_wall		wall_dir;
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
}	t_mlx;

#endif