/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_immages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:53:00 by ablanco-          #+#    #+#             */
/*   Updated: 2024/10/29 17:34:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_xpm_name(t_mlx *mlx, char *xpm)
{
	int	len;

	len = ft_strlen(xpm);
	if (xpm[len - 1] == 'm' && xpm[len - 2] == 'p'
		&& xpm[len - 3] == 'x' && xpm[len - 4] == '.')
		return ;
	ft_print_error(mlx, "texture path is not .xpm");
}

char	*ft_previous_check_xpm(t_mlx *mlx, char *str)
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
		ft_xpm_name(mlx, str);
		return (str);
	}
	str[len + 1] = '\0';
	ft_xpm_name(mlx, str);
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
	t_colors	colors;

	ft_memset(&colors, 0, sizeof(t_colors));
	mlx->path.no_path = ft_previous_check_xpm(mlx, mlx->path.no_path);
	mlx->path.ea_path = ft_previous_check_xpm(mlx, mlx->path.ea_path);
	mlx->path.so_path = ft_previous_check_xpm(mlx, mlx->path.so_path);
	mlx->path.we_path = ft_previous_check_xpm(mlx, mlx->path.we_path);
	mlx->path.door = ft_previous_check_xpm(mlx, "textures/door.xpm");
	make_image_from_xpm(mlx->ptr, &mlx->colors.wall_no, mlx->path.no_path);
	make_image_from_xpm(mlx->ptr, &mlx->colors.wall_ea, mlx->path.ea_path);
	make_image_from_xpm(mlx->ptr, &mlx->colors.wall_so, mlx->path.so_path);
	make_image_from_xpm(mlx->ptr, &mlx->colors.wall_we, mlx->path.we_path);
	make_image_from_xpm(mlx->ptr, &mlx->colors.door, mlx->path.door);
	if (mlx->colors.wall_no.ptr == NULL)
		ft_print_error(mlx, "image NO not loaded properly");
	if (mlx->colors.wall_ea.ptr == NULL)
		ft_print_error(mlx, "image EA not loaded properly");
	if (mlx->colors.wall_so.ptr == NULL)
		ft_print_error(mlx, "image SO not loaded properly");
	if (mlx->colors.wall_we.ptr == NULL)
		ft_print_error(mlx, "image WE not loaded properly");
	if (mlx->colors.door.ptr == NULL)
		ft_print_error(mlx, "image door not loaded properly");
}
