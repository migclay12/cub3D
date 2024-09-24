/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:54 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:56 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	st_len;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	st_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(st_len);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, (char *)s1, st_len);
	ft_strlcat(joined, s2, st_len);
	return (joined);
}
