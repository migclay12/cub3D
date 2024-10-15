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

// Bresenham's Line Algorithm
void line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1; // Step in x direction
	int sy = (y0 < y1) ? 1 : -1; // Step in y direction
	int err = dx - dy;

	while (1)
	{
		put_px(x0, y0, color, &mlx->img); // Draw the pixel
		if (x0 == x1 && y0 == y1) break; // Stop if we reach the endpoint
		int err2 = err * 2;
		// Error check for x direction
		if (err2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		// Error check for y direction
		if (err2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void draw_arrow(t_mlx *mlx, t_shape s)
{
	float angle = mlx->player.angle - M_PI_2;
	float dir_x = cos(angle);
	float dir_y = sin(angle);

	float length = 40.0; // Length of the arrow
	int center_x = mlx->player.plyr_x;
	int center_y = mlx->player.plyr_y;

	// Calculate the endpoint of the direction line
	int end_x = (int)(center_x + dir_x * length);
	int end_y = (int)(center_y + dir_y * length);

	// Draw a line indicating the direction
	line(mlx, center_x, center_y, end_x, end_y, 0x1630BE);

	float arrow_size = 8.0; // Size of the arrowhead
	float arrow_angle = M_PI / 8; // Angle for the arrowhead

	// Calculate the left side of the arrowhead
	int arrow_x1 = (int)(end_x - arrow_size * cos(angle - arrow_angle));
	int arrow_y1 = (int)(end_y - arrow_size * sin(angle - arrow_angle));

	// Calculate the right side of the arrowhead
	int arrow_x2 = (int)(end_x - arrow_size * cos(angle + arrow_angle));
	int arrow_y2 = (int)(end_y - arrow_size * sin(angle + arrow_angle));

	// Draw the arrowhead
	line(mlx, end_x, end_y, arrow_x1, arrow_y1, 0x1630BE);
	line(mlx, end_x, end_y, arrow_x2, arrow_y2, 0x1630BE);
}

int	is_wall_ray(t_mlx *mlx, double x, double y)
{
	//printf("IS_RAY START\n");
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK_SIZE);
	map_y = (int)(y / BLOCK_SIZE);
	//printf("IS_RAY BUCLE\n");
	if (map_x < mlx->map.size_x || map_x > 0 || map_y > 0 \
		|| map_y < mlx->map.size_y)
		{
			//printf("IS_RAY %c\n", mlx->map.matrix[map_y][map_x]);
			if (mlx->map.matrix[map_y][map_x] == '1')
				return (1);
			else if (mlx->map.matrix[map_y][map_x] == '0')
				return (0);
		}
	//printf("IS_RAY RETURN\n");
	return (1);
}

void draw_vertical_line(t_mlx *mlx, int x, int start_y, int end_y, int color)
{
/* 	if (start_y > end_y)
	{
		int tmp = start_y;
		start_y = end_y;
		end_y = tmp;
	}

	if (x < 0 || start_y < 0 || end_y >= S_H || x >= S_W)
		return ; */

	for (int y = start_y; y <= end_y; y++)
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
}

double *draw_ray(t_mlx *mlx)
{
	float	ray_step;
	float	angle;
	float	dir_x;
	float	dir_y;
	float	ray_x;
	float	ray_y;
	float	prev_x;
	float	prev_y;
	int		rays;
	double	*distances = (double *)malloc(sizeof(double) * NUM_RAYS_120);

	//printf("WALLLLLLLL0\n");
	ray_step = 0.5;
	//Check te original position so you don't have to subtract M_PI_2 wtf 
	//if you change te OG the it wont appear looking where it has to
	angle = mlx->player.angle - M_PI_2 - HALF_VIEW_60;
	rays = 0;
	while (rays < NUM_RAYS_120)
	{
		dir_x = cos(angle);
		dir_y = sin(angle);
		ray_x = mlx->player.plyr_x;
		ray_y = mlx->player.plyr_y;
		prev_x = ray_x;
		prev_y = ray_y;
		while (is_wall_ray(mlx, ray_x, ray_y) == 0)
		{
			prev_x = ray_x;
			prev_y = ray_y;
			ray_x += dir_x * ray_step;
			ray_y += dir_y * ray_step;
			mlx->ray.x = ray_x;
			mlx->ray.y = ray_y;
			//printf("WALLLLLLLL1\n");
			line(mlx, (int)prev_x, (int)prev_y, (int)ray_x, (int)ray_y, 0xff2955);
			//printf("WALLLLLLLL2\n");
			//printf("Ray possition: (%f, %f)\n", ray_x, ray_y);
		}
		distances[rays] = sqrt(pow(ray_x - mlx->player.plyr_x, 2) + pow(ray_y - mlx->player.plyr_y, 2));
		angle += ONE_DEG;
		rays++;
		//printf("Checking Wall: World Position (%f, %f)\n", ray_x, ray_y);
	}
	return (distances);
	//printf("WALLLLLLLL3\n");
}

//CORREGIR LOS ANGULOS PARA QUE SALGA RECTAAAAAAAA
void draw_walls(t_mlx *mlx)
{
	int j = 0;
	double	*distances;

	distances = draw_ray(mlx);
	while (j < NUM_RAYS_120)
	{
		double dist = distances[j];
		if (dist > 0)
		{
			mlx->ray.wall_height = (BLOCK_SIZE * 1200) / dist;
			if (mlx->ray.wall_height > S_H)
				mlx->ray.wall_height = S_H;
			int wall_start = (S_H / 2) - (mlx->ray.wall_height / 2);
			int wall_end = (S_H / 2) + (mlx->ray.wall_height / 2);
			draw_vertical_line(mlx, j, wall_start, wall_end, 0xff2955);
		}
		j++;
	}
	free (distances);
}
