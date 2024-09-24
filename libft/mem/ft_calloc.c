/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:19:19 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:19:22 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	n;

	n = size * count;
	if (n < count || n < size)
		return (NULL);
	temp = malloc(n);
	if (temp == (void *)0)
		return (NULL);
	ft_bzero(temp, n);
	return (temp);
}
