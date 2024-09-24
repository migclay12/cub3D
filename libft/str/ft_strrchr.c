/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:33 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:32:36 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (i >= 1)
	{
		i--;
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}
