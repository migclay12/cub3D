/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:19:52 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:19:54 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			j;

	if (!src && !dest)
		return (NULL);
	j = 0;
	while (j < n)
	{
		((unsigned char *)dest)[j] = ((unsigned char *)src)[j];
		j++;
	}
	return (dest);
}
