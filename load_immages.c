/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_immages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:53:00 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/24 19:58:04 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_xpm_name(char *xpm)
{
	int	len;

	len = ft_strlen(xpm);
	if (xpm[len - 1] == 'm' && xpm[len - 2] == 'p'
		&& xpm[len - 3] == 'x' && xpm[len - 4] == '.')
		return ;
	ft_print_error("Archivo de textura no es .xpm");
}

char	*ft_previous_check_xpm(char *str)
{
	int	len;
	int	check;

	len = strlen(str);
	len--;
	check = len;
	while (str[len] == ' ')
		len--;
	if (len == check)
	{
		ft_xpm_name(str);
		return (str);
	}
	str[len + 1] = '\0';
	ft_xpm_name(str);
	return (str);
}

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
	mlx->path.NO_path = ft_previous_check_xpm(mlx->path.NO_path);
	mlx->path.EA_path = ft_previous_check_xpm(mlx->path.EA_path);
	mlx->path.SO_path = ft_previous_check_xpm(mlx->path.SO_path);
	mlx->path.WE_path = ft_previous_check_xpm(mlx->path.WE_path);
/* 	printf("Loading NO texture: %s\n", mlx->path.NO_path);
	printf("Loading EA texture: %s\n", mlx->path.EA_path);
	printf("Loading SO texture: %s\n", mlx->path.SO_path);
	printf("Loading WE texture: %s\n", mlx->path.WE_path); */
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_no, mlx->path.NO_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_ea, mlx->path.EA_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_so, mlx->path.SO_path);
	make_image_from_xpm(mlx->ptr, &mlx->ray.wall_we, mlx->path.WE_path);
	if (mlx->ray.wall_no.ptr == NULL)
		ft_print_error("Image not loaded properly NO");
	if (mlx->ray.wall_ea.ptr == NULL)
		ft_print_error("Image not loaded properly EA");
	if (mlx->ray.wall_so.ptr == NULL)
		ft_print_error("Image not loaded properly SO");
	if (mlx->ray.wall_we.ptr == NULL)
		ft_print_error("Image not loaded properly WE");
}
