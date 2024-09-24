/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:27:54 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/24 20:12:12 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include <stdio.h>


typedef struct s_map
{
	int		fd;
	char	*name;
	char	**map;
	int		size_x;
	int		size_y;
}	t_map;

void	ft_print_error(char *str);
void	ft_all_map(t_map *map);

#endif