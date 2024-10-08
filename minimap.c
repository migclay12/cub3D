#include "cub3d.h"

//This is usefull because the imaes stop flickering and stay static
void put_px(int x, int y, int color, t_img *img)
{
	char *dst;

	// Get the memory address of the pixel at (x, y) in the image
	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	
	// Set the pixel's color
	*(unsigned int*)dst = color;
}

void	rect(t_mlx *mlx, t_shape shape, int color)
{
	////printf("RECT\n");
	int	i;
	int	j;

	i = shape.y;
	while (i < shape.y + shape.height && i < S_W)
	{
		j = shape.x;
		while (j < shape.x + shape.width && j < S_H)
		{
			//mlx_pixel_put(mlx->ptr, mlx->win, i, j, color);
			put_px(i, j, color, &mlx->img);
			++j;
		}
		++i;
	}
	return ;
}

// Function to draw a 64x64 pixel square based on the value (0 or 1)
static inline void draw_minimap_floor(t_mlx *mlx, int sx, int sy, t_shape shape)
{
	int	y;
	int	x;

	y = 0;
	x = 0; 
	shape.width = BLOCK_SIZE;
	shape.height = BLOCK_SIZE;
	//printf("DRAW_FLOOR: %d\n", mlx->map.size_y);
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (x <= mlx->map.size_x)
		{
			shape.x = y * BLOCK_SIZE + sx;
			shape.y = x * BLOCK_SIZE + sy;
			////printf("FLOOOOOR: %c\n", mlx->map.matrix[y][x]);
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '0')
				rect(mlx, shape, 0xFFFFFFFF);
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == 'N')
				rect(mlx, shape, 0xFFFFFFFF);
			// if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '1')
			// 	rect(mlx, shape, 0xBB4211); //RED
			x++;
		}
		y++;
	}
	return ;
}

static inline void
	draw_walls_minimap(t_mlx *mlx, int sx, int sy, t_shape shape)
{
	//printf("DRAW_WALLS\n");
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < mlx->map.size_y)
	{
		x = 0;
		while (x <= mlx->map.size_x)
		{
			shape.x = y * BLOCK_SIZE + sx;
			shape.y = x * BLOCK_SIZE + sy;
			if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '1')
				rect(mlx, shape, 0xBB4211); //RED
			//shape.x = y * MINISIDE + sx;
			//shape.y = x * MINISIDE + sy;
			//if (mlx->map.matrix[y][x] && mlx->map.matrix[y][x] == '1')
			//	rect(&game->scr, shape, BROWN);
			x++;
		}
		y++;
	}
	return ;
}

void	circle(t_mlx *mlx, t_shape s, int color)
{
	int		i;
	int		j;
	double	dist;

	i = s.y;
	while (i < s.y + s.height && i < S_H)
	{
		j = s.x;
		while (j < s.x + s.width && j < S_W)
		{
			dist = sqrt(pow(i - (s.y + s.height / 2), 2)
					+ pow(j - (s.x + s.width / 2), 2));
			if (dist < s.width / 2.0)
				put_px(i, j, color, &mlx->img);
				//mlx_pixel_put(mlx->ptr, mlx->win, i, j, color);
			++j;
		}
		++i;
	}
	return ;
}

static inline void
	draw_player_minimap(t_mlx *mlx, t_shape s, int sx, int sy)
{
	s.width = 32;
	s.height = 32;
	s.x = (int)(mlx->player.plyr_y * BLOCK_SIZE + sx); // - s.width / 2
	s.y = (int)(mlx->player.plyr_x * BLOCK_SIZE + sy); // - s.height / 2
	circle(mlx, s, 0x1630BE);
	return ;
}

// start the game
void	draw_minimap(t_mlx *mlx)
{
	//printf("AAAAAAAAAAAA\n");

	t_shape	shape;
	int		starty;
	int		startx;

	ft_memset(&shape, 0, sizeof(t_shape));
	shape.x = 0;
	shape.width = BLOCK_SIZE;
	shape.height = BLOCK_SIZE;
	starty = 0;
	startx = 0;
	
	//printf("PLACE: %d\n", mlx->player.plyr_x);
	draw_minimap_floor(mlx, startx, starty, shape);
	//printf("BBBBBBBBBBBB\n");
	draw_walls_minimap(mlx, startx, starty, shape);
	//printf("CCCCCCCCCCCC\n");
	draw_player_minimap(mlx, shape, startx, starty);
	
	//printf("EEEEEEEEEEEE\n");
}

static inline bool	player_moving(t_player *p)
{
	static bool	first_run = true;

	if (first_run)
	{
		first_run = false;
		return (true);
	}
	return (p->move_no || p->move_so || p->move_we || p->move_ea);
}

int	on_loop(t_mlx	*mlx)
{
	//printf("ON_LOOP\n");

	update_player_position(mlx);
	mlx_clear_window(mlx->ptr, mlx->win);
	//printf("SIZEEEE Y: %d - SIZEEEE X: %d\n", mlx->map.size_y, mlx->map.size_x);
	//printf("ON_LOOP1\n");
	draw_minimap(mlx);
	//printf("ON_LOOP2\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	//printf("ON_LOOP3\n");
	return (0);
}

static inline void	hook_events(t_mlx *mlx)
{
	//printf("HOOK_EVENTS\n");
	//printf("SIZEEEE1: %d\n", mlx->map.size_y);
	
	
	mlx_loop_hook(mlx->ptr, on_loop, mlx);
	//printf("HOOK_EVENTS1\n");
	mlx_hook(mlx->win, 17, 0L, ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, on_key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, on_key_release, mlx);
	
	return ;
}

char	*init_graphics(t_mlx *mlx)
{
	//Check if arrow or dot
	//printf("INIT_GRAPHICS\n");
	mlx->ptr = mlx_init();
	//printf("INIT_GRAPHICS1\n");
	mlx->win = mlx_new_window(mlx->ptr, S_W, S_H, "work you little fuck");
	//printf("INIT_GRAPHICS2\n");
	mlx->img.ptr = mlx_new_image(mlx->ptr, S_W, S_H);
	//printf("INIT_GRAPHICS3\n");
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, &mlx->img.line, &mlx->img.end);
	//printf("INIT_GRAPHICS4\n");
	//mlx_loop_hook(mlx->ptr, on_loop, mlx);
	hook_events(mlx);
	//printf("INIT_GRAPHICS5\n");
	mlx_loop(mlx->ptr);
	return (NULL);
}

void init_the_player(t_mlx *mlx)	// init the player structure
{
	mlx->player.plyr_x = (double)mlx->map.p_x + 0.25;
	mlx->player.plyr_y = (double)mlx->map.p_y + 0.25;
	mlx->player.angle = 0; // player angle
	//printf("PLACE MAP: %d - %d\n", mlx->map.p_x, mlx->map.p_y);
	//printf("PLACE PLAYER: %f - %f\n", mlx->player.plyr_x, mlx->player.plyr_y);
}

char	*init_game(t_mlx mlx)
{
	t_img img;
	t_player player;

	ft_memset(&img, 0, sizeof(t_img));
	ft_memset(&player, 0, sizeof(t_player));
	img.h = S_H;
	img.w = S_W;
	mlx.img.h = img.h;
	mlx.img.w = img.w;
	init_the_player(&mlx);
	//printf("INIT_GAME\n");
	////printf("SIZEEEE2: %d\n", mlx->map.size_y);
	init_graphics(&mlx);
	//printf("INIT_GAME1\n");
	//THIS PROBABLY NEEDS A DOT
	
	//printf("INIT_GAME2\n");
	return (NULL);
}
