/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:20:14 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:20:17 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	i = -1;
	while (++i < len)
		cstr[i] = c;
	return (cstr);
}
