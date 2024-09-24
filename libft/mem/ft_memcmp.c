/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:19:40 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:19:43 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	i = 0;
	while ((cs1[i] == cs2[i]) && i < n - 1)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	if (i != n)
		return (cs1[i] - cs2[i]);
	return (0);
}
