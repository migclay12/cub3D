#include "cub3d.h"

//exit the game
void	ft_exit(t_mlx *mlx)
{
	/* int	i = 0;
	while (mlx->map.matrix[i])
		free(mlx->map.matrix[i]); */
	ft_free_matrix(mlx->map.matrix);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	printf("Game closed\n");
	exit(0);
}

// key press
void mlx_key(mlx_key_data_t keydata, void *ml)	
{
	t_mlx	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
		ft_exit(mlx);
}

int	choose_color(char **map, int i, int j)
{
	printf("INNNNNNNNN %s\n", map[i]);
	if (map[i][j] == '0')
	{
		printf("WTF?!\n");
		return (0xFFFFFFFF);
	}
	if (map[i][j] == '1')
	{
		printf("WTF?!2\n");
		return (0x00000000);
	}
	if (map[i][j] == 'P')
	{
		printf("WTF?!3\n");
		return (0xFF0000FF);
	}
	printf("OUUUUUUUUT\n");
	return (0x00000000);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

void	ft_draw_map(t_mlx *mlx, int map_height, int map_widht)
{
	int	i;
	int	j;
	int colour;

	i = 0;
	j = 0;
	while (i < map_height)
	{
		//printf("LOOP I: %d\n", i);
		while (j <= map_widht)
		{
			colour =  choose_color(mlx->map.matrix, i, j);
			printf("LOOP I: %d\nLOOP J: %d\n", i, j);
			my_mlx_pixel_put(mlx, j, i, colour);
			//printf("LOOP J2: %d\n", j);
			j++;
		}
		i++;
		j = 0;
	}
}

/* static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */

#define BLOCK_SIZE 64

// Function to draw a 64x64 pixel square based on the value (0 or 1)
void draw_square(t_mlx *mlx, int x, int y, char value) {
	// Create a 64x64 image
	mlx->img = mlx_new_image(mlx->mlx_p, BLOCK_SIZE, BLOCK_SIZE);

	// Set pixels to black or white based on `is_black`
	//int color = (value == '1') ? 0xFF000000 : 0xFF0000FF;  // Black: 0xFF000000, White: 0xFFFFFFFF
	int color;
	if (value == '1')
		color = 0xFFFF0000;
	else if (value == '0')
		color = 0xFFFFFFFF;
	else if (value == 'N')
		color = 0xFF000000;
	for (int i = 0; i < BLOCK_SIZE * BLOCK_SIZE; i++) {
    	((uint32_t*)mlx->img->pixels)[i] = color;
    }
	// Draw the image at specified coordinates
	mlx_image_to_window(mlx->mlx_p, mlx->img, x, y);
}

// game loop
/* void	game_loop(void *ml)	
{
	t_mlx	*mlx;

	mlx = ml;
	
	//mlx_delete_image(mlx->mlx_p, mlx->img);
	//mlx->img = mlx_new_image(mlx->mlx_p, 64, 64);
	//memset(mlx->img->pixels, 255, mlx->img->width * mlx->img->height * BPP);
	//ft_draw_map(mlx, mlx->map.size_y, mlx->map.size_y);
	for (int row = 0; row < mlx->map.size_y; row++) {
		for (int col = 0; col < mlx->map.size_x; col++) {
			int is_black = mlx->map.matrix[row][col];
			int x = col * BLOCK_SIZE;  // Calculate x position
			int y = row * BLOCK_SIZE;  // Calculate y position
			draw_square(mlx, x, y, is_black);
		}
	}
} */


// start the game
void	start_the_game(t_mlx mlx)
{
	printf("AAAAAAAAAAAA\n");
	mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0);
	for (int row = 0; row < mlx.map.size_y; row++) {
		for (int col = 0; col <= mlx.map.size_x; col++)
		{
			if (col ==0)
				printf("\n");
			printf("%c - ", mlx.map.matrix[row][col]);
			char is_black = mlx.map.matrix[row][col];
			int x = col * BLOCK_SIZE;  // Calculate x position
			int y = row * BLOCK_SIZE;  // Calculate y position
			draw_square(&mlx, x, y, is_black);
		}
	}
	//mlx_loop_hook(mlx.mlx_p, game_loop, &mlx);
	printf("CCCCCCCCCCCC\n");
	mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx);
	printf("DDDDDDDDDDDD\n");
	//mlx_put_pixel(mlx.img, 400, 300, 0xFFFFFFFF);
	//ft_draw_map(&mlx, mlx.map.size_y, mlx.map.size_x);
	//Con flecha peta, understand why

	mlx_loop(mlx.mlx_p);
	printf("EEEEEEEEEEEE\n");
}