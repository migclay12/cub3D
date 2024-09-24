/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:40:35 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:40:37 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	int		pos;
	int		in;
	double	de;
	int		i;

	de = 0;
	pos = 0;
	in = ft_atoi_pos(str, &pos);
	if (str[pos++] == '.')
	{
		i = 0;
		de = 1;
		while (ft_isdigit(str[pos + i++]))
			de *= 10;
		de = ft_atoi_pos(str, &pos) / de;
	}
	return ((double)in + de);
}
