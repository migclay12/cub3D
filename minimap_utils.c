#include "cub3d.h"

//This is usefull because the imaes stop flickering and stay static
/* void put_px(int x, int y, int color, t_img *img)
{
	char *dst;

	// Get the memory address of the pixel at (x, y) in the image
	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	
	// Set the pixel's color
	*(unsigned int*)dst = color;
} */

void put_px(int x, int y, int color, t_img *img)
{
    char *dst;

    // Ensure the coordinates are within the image boundaries
    if (x < 0 || x >= img->w || y < 0 || y >= img->h)
        return;  // Do nothing if out of bounds

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

void draw_arrow(t_mlx *mlx)
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
