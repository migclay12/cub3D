#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_shape
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_shape;

typedef struct s_player //the player structure
{
	int		plyr_x; 
	int		plyr_y; 
	char	playr_orient;
	int		l_r;
	int		u_d;
	double		angle;
	int		rot;
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
	int		p_x; 
	int		p_y; 
	char	p_or;
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

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	//mlx_image_t		*img;	
	//mlx_t			*mlx_p;
	t_img			img;
	t_player		player;
	t_map			map;
}	t_mlx;

typedef enum s_wall
{
	NO,
	SO,
	EA,
	WE,
	C,
	F
} t_wall;

#endif