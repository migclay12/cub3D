/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:13 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:32:15 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	if (!needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		b = 0;
		while (haystack[i + b] && needle[b] == haystack[i + b] && i + b < len)
		{
			if (needle[b + 1] == '\0')
				return ((char *)&haystack[i]);
			b++;
		}
		i++;
	}
	return (0);
}
