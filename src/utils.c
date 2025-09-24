/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:36:59 by miggonza          #+#    #+#             */
/*   Updated: 2024/10/29 12:11:13 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	put_px(int x, int y, int color, t_img *img)
{
	char	*dst;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

char	**ft_free_map(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	exit (0);
}

char	*ft_str(const char *s, int c)
{
	unsigned char	l;

	l = (unsigned char)c;
	while (*s != l)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*remove_spaces(char *str)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	if ((int)ft_strlen(str) - 1 == 0)
		return (NULL);
	while (i <= (int)ft_strlen(str))
	{
		if (str[i] == '1')
			start = i + 1;
		i++;
	}
	i = start;
	if (start == 0)
		return (NULL);
	while (i <= (int)ft_strlen(str))
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (str);
		i++;
	}
	return (str);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
