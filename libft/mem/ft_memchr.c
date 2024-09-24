/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:19:30 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:19:33 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	n;

	i = 0;
	aux = (unsigned char *)str;
	n = (unsigned char)c;
	while (size > i)
	{
		if (aux[i] == n)
			return ((void *)aux + i);
		i++;
	}
	return (0);
}
