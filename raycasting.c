/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:22 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/24 19:55:08 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	for (int y = start_y; y <= end_y; y++)
		put_px(x, y, color, &mlx->img);
}

/* void draw_ray(t_mlx *mlx)
{
	float ray_step = 0.5;
	float angle = mlx->player.angle - (FOV / 2.0);
	int rays = 0;
	mlx->ray.distances = (double *)malloc(sizeof(double) * 1920);
	mlx->ray.ray_x = (double *)malloc(sizeof(double) * 1920);
	mlx->ray.ray_y = (double *)malloc(sizeof(double) * 1920);

	while (rays < 1920)
	{
		float dir_x = cos(angle);
		float dir_y = sin(angle);
		mlx->ray.ray_x[rays] = mlx->player.plyr_x;
		mlx->ray.ray_y[rays] = mlx->player.plyr_y;
		while (is_wall_ray(mlx, mlx->ray.ray_x[rays], mlx->ray.ray_y[rays]) == 0)
		{
			mlx->ray.ray_x[rays] += dir_x * ray_step;
			mlx->ray.ray_y[rays] += dir_y * ray_step;
		}
		mlx->ray.distances[rays] = sqrt(pow(mlx->ray.ray_x[rays] - mlx->player.plyr_x, 2) + pow(mlx->ray.ray_y[rays] - mlx->player.plyr_y, 2));
		angle += (FOV / 1920);
		rays++;
	}
} */

/* void draw_ray(t_mlx *mlx)
{
	float ray_step = 0.5;
	float angle = mlx->player.angle - (FOV / 2.0);
	int rays = 0;
	mlx->ray.distances = (double *)malloc(sizeof(double) * 1920);
	mlx->ray.ray_x = (double *)malloc(sizeof(double) * 1920);
	mlx->ray.ray_y = (double *)malloc(sizeof(double) * 1920);
	mlx->ray.vertical_hit = (int *)malloc(sizeof(int) * 1920); // Track vertical hits

	while (rays < 1920)
	{
		float dir_x = cos(angle);
		float dir_y = sin(angle);
		mlx->ray.ray_x[rays] = mlx->player.plyr_x;
		mlx->ray.ray_y[rays] = mlx->player.plyr_y;
		
		// Initialize DDA variables
		double delta_dist_x = fabs(1 / dir_x);
		double delta_dist_y = fabs(1 / dir_y);
		double side_dist_x, side_dist_y;
		int step_x, step_y;
		int hit = 0;  // Flag for wall hit
		int side;     // 0 for NS, 1 for EW

		// Calculate step direction and initial side distances
		if (dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (mlx->player.plyr_x - (int)mlx->player.plyr_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = ((int)mlx->player.plyr_x + 1.0 - mlx->player.plyr_x) * delta_dist_x;
		}
		if (dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (mlx->player.plyr_y - (int)mlx->player.plyr_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = ((int)mlx->player.plyr_y + 1.0 - mlx->player.plyr_y) * delta_dist_y;
		}

		// Perform DDA
		while (!hit)
		{
			// Move to next grid square in either x or y direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				mlx->ray.ray_x[rays] += step_x;
				side = 0;  // Vertical hit
			}
			else
			{
				side_dist_y += delta_dist_y;
				mlx->ray.ray_y[rays] += step_y;
				side = 1;  // Horizontal hit
			}

			// Check if we hit a wall
			if (is_wall_ray(mlx, mlx->ray.ray_x[rays], mlx->ray.ray_y[rays]))
				hit = 1;
		}

		// Calculate distance to the wall
		int no_or_we;
		if (side == 0) // NS wall hit
		{
			printf("DIR Y: %d\n", dir_y);
			mlx->ray.distances[rays] = (mlx->ray.ray_x[rays] - mlx->player.plyr_x + (1 - step_x) / 2) / dir_x;
			if (dir_y < 0)
				mlx->ray.vertical_hit[rays] = 0;  //North
			else
				mlx->ray.vertical_hit[rays] = 1;  //south
		}
		else // EW wall hit
		{
			mlx->ray.distances[rays] = (mlx->ray.ray_y[rays] - mlx->player.plyr_y + (1 - step_y) / 2) / dir_y; 
			if (dir_x < 0)
            	mlx->ray.vertical_hit[rays] = 2;  //West
			else
				mlx->ray.vertical_hit[rays] = 3;  //East
		}

		angle += (FOV / 1920);
		rays++;
	}
} */

void draw_ray(t_mlx *mlx)
{
    float ray_step = 0.5;
    float angle = mlx->player.angle - (FOV / 2.0);
    int rays = 0;
    mlx->ray.distances = (double *)malloc(sizeof(double) * 1920);
    mlx->ray.ray_x = (double *)malloc(sizeof(double) * 1920);
    mlx->ray.ray_y = (double *)malloc(sizeof(double) * 1920);
    mlx->ray.vertical_hit = (int *)malloc(sizeof(int) * 1920); // Track vertical hits
    mlx->ray.ray_dir_x = (double *)malloc(sizeof(double) * 1920); // Store ray direction x
    mlx->ray.ray_dir_y = (double *)malloc(sizeof(double) * 1920); // Store ray direction y

    while (rays < 1920)
    {
        float dir_x = cos(angle);
        float dir_y = sin(angle);
        mlx->ray.ray_x[rays] = mlx->player.plyr_x;
        mlx->ray.ray_y[rays] = mlx->player.plyr_y;
        
        mlx->ray.ray_dir_x[rays] = dir_x;  // Save direction for later
        mlx->ray.ray_dir_y[rays] = dir_y;  // Save direction for later

        // Initialize DDA variables
        double delta_dist_x = fabs(1 / dir_x);
        double delta_dist_y = fabs(1 / dir_y);
        double side_dist_x, side_dist_y;
        int step_x, step_y;
        int hit = 0;  // Flag for wall hit
        int side;     // 0 for NS, 1 for EW

        // Calculate step direction and initial side distances
        if (dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (mlx->player.plyr_x - (int)mlx->player.plyr_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = ((int)mlx->player.plyr_x + 1.0 - mlx->player.plyr_x) * delta_dist_x;
        }
        if (dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (mlx->player.plyr_y - (int)mlx->player.plyr_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = ((int)mlx->player.plyr_y + 1.0 - mlx->player.plyr_y) * delta_dist_y;
        }

        // Perform DDA
        while (!hit)
        {
            // Move to next grid square in either x or y direction
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                mlx->ray.ray_x[rays] += step_x;
                side = 0;  // Vertical hit
            }
            else
            {
                side_dist_y += delta_dist_y;
                mlx->ray.ray_y[rays] += step_y;
                side = 1;  // Horizontal hit
            }

            // Check if we hit a wall
            if (is_wall_ray(mlx, mlx->ray.ray_x[rays], mlx->ray.ray_y[rays]))
                hit = 1;
        }

        // Calculate distance to the wall
        if (side == 0)
        {
            mlx->ray.distances[rays] = (mlx->ray.ray_x[rays] - mlx->player.plyr_x + (1 - step_x) / 2) / dir_x;
            mlx->ray.vertical_hit[rays] = 1;  // NS wall hit
        }
        else
        {
            mlx->ray.distances[rays] = (mlx->ray.ray_y[rays] - mlx->player.plyr_y + (1 - step_y) / 2) / dir_y;
            mlx->ray.vertical_hit[rays] = 0;  // EW wall hit
        }

        angle += (FOV / 1920);
        rays++;
    }
}



int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int get_pixel_img(t_img *img, int x, int y)
{
	if (x > 64 || y > 64)
		return (0xFF0000);
	//printf("PIXEL\n");
	return (*(unsigned int *)((img->addr + (y * img->line)
			+ (x * img->bpp / 8))));
}

/* int get_pixel_img(t_img *img, int x, int y)
{
	// Ensure x and y are within bounds
	if (x < 0 || x >= img->w || y < 0 || y >= img->h) 
	{
		//printf("WTF?!\n");
		return (0xFF0000);  // Return a default color (like red) in case of out-of-bounds access
	} 
	
	return (*(unsigned int *)((img->addr + (y * img->line) + (x * img->bpp / 8))));
} */

void draw_wall_ew(t_mlx *mlx, t_ray *ray, int start_x, int wall_start, int wall_end, int num)
{
	t_img *img;
	int dx, dy;
	int tx, ty;
	int pixel;
	int draw_height = wall_end - wall_start;

		img = &mlx->ray.wall_we;
	dx = 0;
	//printf("RAY X: %f\n", ray->ray_dir_x[num]);
	if (ray->ray_dir_x[num] > 0)
		img = &mlx->ray.wall_ea;
	else
		img = &mlx->ray.wall_we;
	while (dx < (S_W / 1920))
	{
		dy = 0;
		while (dy < draw_height)
		{
			tx = (int)((int)ray->ray_y[num] % img->w);
		/* 	if (tx >= img->w)
				tx = img->w - 1;
			if (tx < 0)
				tx = 0; */
			ty = (int)(((double)dy / draw_height) * img->h);
	/* 		if (ty >= img->h)
				ty = img->h - 1;
			if (ty < 0)
				ty = 0; */
			pixel = get_pixel_img(img, tx, ty);
			put_px(start_x + dx, wall_start + dy, pixel, &mlx->img);
			dy++;
		}
		dx++;
	}
}

void draw_wall_ns(t_mlx *mlx, t_ray *ray, int start_x, int wall_start, int wall_end, int num)
{
	t_img *img;
	int dx, dy;
	int tx, ty;
	int pixel;
	int draw_height = wall_end - wall_start;

	dx = 0;
	//printf("RAY Y: %f\n", ray->ray_dir_y[num]);
	if (ray->ray_dir_y[num] > 0)
		img = &mlx->ray.wall_so;
	else
		img = &mlx->ray.wall_no;
	while (dx < (S_W / 1920))
	{
		dy = 0;
		while (dy < draw_height)
		{
			tx = (int)((int)ray->ray_x[num] % img->w);
			if (tx >= img->w)
				tx = img->w - 1;
			if (tx < 0)
				tx = 0;
			ty = (int)(((double)dy / mlx->ray.wall_height) * img->h);
			if (ty >= img->h)
				ty = img->h - 1;
			if (ty < 0)
				ty = 0;
			pixel = get_pixel_img(img, tx, ty);
			put_px(start_x + dx, wall_start + dy, pixel, &mlx->img);
			dy++;
			//dy = ((mlx->ray.wall_height - S_H) / 2) * (64 / mlx->ray.wall_height);
		}
		dx++;
	}
}

//1920 is also the number of rays so put it in the defines
void draw_walls(t_mlx *mlx)
{
	int i = 0;
	int j = 0;
	double ray_angle = mlx->player.angle - (FOV / 2.0);

	draw_ray(mlx);
	mlx->ray.flo = create_rgb(mlx->ray.f_r, mlx->ray.f_g, mlx->ray.f_b);
	mlx->ray.cei = create_rgb(mlx->ray.c_r, mlx->ray.c_g, mlx->ray.c_b);
	
	while (i < S_W)
	{
		double dist = mlx->ray.distances[i];
		if (dist > 0)
		{
			double corrected_dist = dist * cos(ray_angle - mlx->player.angle);
			mlx->ray.wall_height = ((BLOCK_SIZE * (S_H)) / corrected_dist);

			int wall_start = (S_H / 2) - (mlx->ray.wall_height / 2);
			int wall_end = (S_H / 2) + (mlx->ray.wall_height / 2);

		/* 	if (wall_start < 0)
				wall_start = 0;
			if (wall_end > S_H)
				wall_end = S_H; */
			j = 0;
			while (j <= S_H)
			{
				if (j > wall_end)
					put_px(i, j, mlx->ray.flo, &mlx->img);
				else if (j < wall_start)
					put_px(i, j, mlx->ray.cei, &mlx->img);
				j++;
			}
			if (mlx->ray.vertical_hit[i] == 1)
				draw_wall_ew(mlx, &mlx->ray, i * (S_W / 1920), wall_start, wall_end, i);
			else
				draw_wall_ns(mlx, &mlx->ray, i * (S_W / 1920), wall_start, wall_end, i);
			//draw_vertical_line(mlx, i, wall_start, wall_end, 0xff2955);
		}
		i += 1;
		ray_angle += (FOV / 1920);
	}
	free(mlx->ray.distances);
	free(mlx->ray.ray_x);
	free(mlx->ray.ray_y);
	free(mlx->ray.vertical_hit);
	free(mlx->ray.ray_dir_x);
	free(mlx->ray.ray_dir_y);
}

/* void draw_wall(t_mlx *mlx, int x, int wall_start, int wall_end)
{
	double wall_x;
	if (mlx->ray.sides[x] != 0)  // Golpe en una pared vertical (Norte o Sur)
		wall_x = mlx->ray.ray_y[x] - floor(mlx->ray.ray_y[x]);  // Usar la coordenada Y de la intersección
	else            // Golpe en una pared horizontal (Este u Oeste)
		wall_x = mlx->ray.ray_x[x] - floor(mlx->ray.ray_x[x]);  // Usar la coordenada X de la intersección

	// Convertir wall_x en coordenada de la textura (entre 0 y el ancho de la textura)
	int tex_x = (int)(wall_x * (double)mlx->ray.wall_no.w);  

	// Calcular el tamaño de paso para escalar la textura a la altura de la pared en la pantalla
	double tex_step = 1.0 * mlx->ray.wall_no.h / mlx->ray.wall_height;
	double tex_pos = (wall_start - S_H / 2 + mlx->ray.wall_height / 2) * tex_step;

	// Bucle a través de cada píxel de la rebanada de la pared
	for (int y = wall_start; y <= wall_end; y++)
	{
		int tex_y = (int)tex_pos & (mlx->ray.wall_no.h - 1);  // Obtener coordenada Y de la textura
		tex_pos += tex_step;  // Avanzar en la textura

		// Obtener el color del píxel de la textura
		int color = get_pixel_img(&mlx->ray.wall_no, tex_x, tex_y);

		// Dibujar el píxel en la pantalla
		put_px(x, y, color, &mlx->img);
	}
} */

/* void draw_wall(t_mlx *mlx, int x, int wall_start, int wall_end)
{
	int block_size = 64; // Tamaño del bloque en el mapa
	int map_x, map_y;    // Coordenadas del bloque en la cuadrícula del mapa

	if (mlx->ray.sides[x] == 0)  // Pared vertical (Norte o Sur)
	{
		map_x = (int)mlx->ray.ray_x[x]; // Coordenada del bloque en el mapa
		map_y = (int)mlx->player.plyr_y;
	}
	else  // Pared horizontal (Este u Oeste)
	{
		map_x = (int)mlx->player.plyr_x;
		map_y = (int)mlx->ray.ray_y[x]; // Coordenada del bloque en el mapa
	}

	// Calcular la posición de la textura en X basada en la posición dentro del bloque
	int tex_x = (map_x % block_size);

	// Calcular el tamaño de paso para escalar la textura a la altura de la pared en la pantalla
	double tex_step = 1.0 * mlx->ray.wall_no.h / mlx->ray.wall_height;
	double tex_pos = (wall_start - S_H / 2 + mlx->ray.wall_height / 2) * tex_step;

	// Bucle a través de cada píxel de la rebanada de la pared
	for (int y = wall_start; y <= wall_end; y++)
	{
		// Calcular la coordenada Y de la textura, ajustada por la posición en la pantalla
		int tex_y = (int)tex_pos & (mlx->ray.wall_no.h - 1);  
		tex_pos += tex_step;

		// Obtener el color del píxel de la textura
		int color = get_pixel_img(&mlx->ray.wall_no, tex_x, tex_y);

		// Dibujar el píxel en la pantalla
		put_px(x, y, color, &mlx->img);
	}
} */