#include "cub3d.h"

//Just use a fucking char *colour
void	ft_check_coma(t_mlx *mlx)
{
	int	coma;
	int	i;

	i = 0;
	coma = 0;
	while (mlx->path.F_color[i])
	{
		if (mlx->path.F_color[i] == ',')
			coma++;
		i++;
	}
	//If there is a coma at the end but no other colour does it count?
	if (coma > 2)
		ft_print_error("There are too many floor clours");
	
	i = 0;
	coma = 0;
	while (mlx->path.C_color[i])
	{
		if (mlx->path.C_color[i] == ',')
			coma++;
		i++;
	}
	//If there is a coma at the end but no other colour does it count?
	if (coma > 2)
		ft_print_error("There are too many ceiling clours");
}

void	ft_check_digit(char **rgb)
{
	//Change the error messages
	int i;
	int j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		//while (rgb[i][j] != '\r' && rgb[i][j] != '\n' && rgb[i][j] != '\0')
		//while(rgb[i][j])
		while (j < ft_strlen(rgb[i]) - 1)
		{
			//printf("THE FUCKIG RGBING %c\n", rgb[i][j]);
			if (!ft_isdigit(rgb[i][j]))
			{
				printf("WTF?!: %c", rgb[i][j]);
				ft_print_error("IT'S NOT A FUCKING NUMBEEEEEEEEEEER");
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (rgb[i])
	{
		j = ft_atoi(rgb[i]);
		if (j < 0 || j > 255)
			ft_print_error("THE RGB NUMBER IS OUT OF BOUNDS");
		i++;
	}
}

void	ft_save_colors(t_mlx *mlx)
{
	char **rgb;

	rgb = ft_split(mlx->path.F_color, ',');
	ft_check_digit(rgb);
	mlx->ray.f_r = ft_atoi(rgb[0]);
	mlx->ray.f_g = ft_atoi(rgb[1]);
	mlx->ray.f_b = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	rgb = ft_split(mlx->path.C_color, ',');
	ft_check_digit(rgb);
	mlx->ray.c_r = ft_atoi(rgb[0]);
	mlx->ray.c_g = ft_atoi(rgb[1]);
	mlx->ray.c_b = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	printf("RGB-F: %d\n", mlx->ray.f_r);
	printf("RGB-F: %d\n", mlx->ray.f_g);
	printf("RGB-F: %d\n", mlx->ray.f_b);
	printf("RGB-C: %d\n", mlx->ray.c_r);
	printf("RGB-C: %d\n", mlx->ray.c_g);
	printf("RGB-C: %d\n", mlx->ray.c_b);

}

void	ft_check_rgb(t_mlx *mlx)
{

	ft_check_coma(mlx);
	ft_save_colors(mlx);
}