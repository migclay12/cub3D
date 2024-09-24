/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:29:47 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:29:50 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strbrk(char *str, int b_point)
{
	char	**half;
	int		len;

	half = NULL;
	len = ft_strlen(str);
	if (b_point >= len || b_point <= 0)
	{
		half = malloc(sizeof(char *) * 2);
		half[0] = ft_calloc(sizeof(char), len + 1);
		ft_strlcpy(half[0], str, len + 1);
		half[1] = NULL;
	}
	else
	{
		half = malloc(sizeof(char *) * 3);
		half[0] = ft_calloc(sizeof(char), b_point + 1);
		ft_strlcpy(half[0], str, b_point + 1);
		half[1] = ft_substr(str, b_point, len - b_point);
		half[2] = NULL;
	}
	return (half);
}
