#include "cub3d.h"

void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm)
{
	if (!mlx_ptr || !img || !xpm)
		return ;
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, xpm, &img->w, &img->h);
	if (img->ptr)
		img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
				&img->line, &img->end);
	return ;
}

void	save_xpm(t_mlx *mlx)
{
	//Hacer esta comprobacion pero donde toca
	if (mlx->ptr == NULL)
		ft_print_error("Failed to initialize MLX");

	printf("Loading NO texture: %s\n", mlx->path.NO_path);
	printf("Loading EA texture: %s\n", mlx->path.EA_path);
	printf("Loading SO texture: %s\n", mlx->path.SO_path);
	printf("Loading WE texture: %s\n", mlx->path.WE_path);

	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_no, mlx->path.NO_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_ea, mlx->path.EA_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_so, mlx->path.SO_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_we, mlx->path.WE_path);

//	if (mlx->ray.wall_no.ptr == NULL || mlx->ray.wall_ea.ptr == NULL || mlx->ray.wall_so.ptr == NULL || mlx->ray.wall_we.ptr == NULL)
//		ft_print_error("Image not loaded properly");
	if (mlx->ray.wall_no.ptr == NULL)
		ft_print_error("Image not loaded properly NO");
	if (mlx->ray.wall_ea.ptr == NULL)
		ft_print_error("Image not loaded properly EA");
	if (mlx->ray.wall_so.ptr == NULL)
		ft_print_error("Image not loaded properly SO");
	if (mlx->ray.wall_we.ptr == NULL)
		ft_print_error("Image not loaded properly WE");
}