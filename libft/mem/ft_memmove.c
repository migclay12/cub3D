/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:20:05 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:20:08 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	j;
	char	*csrc;
	char	*cdest;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (dest == src)
		return (dest);
	else if (dest < src)
	{
		j = 0;
		while (j < n)
		{
			cdest[j] = csrc[j];
			j++;
		}
	}
	else
		while (n--)
			cdest[n] = csrc[n];
	return (dest);
}
