/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:34 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:37:36 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str) || !*str)
		return (ft_strdup(""));
	if (ft_strlen(str) + 1 <= (len + start))
		len = ft_strlen(str) - start;
	temp = ft_calloc(sizeof(char), len + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < len)
		temp[i] = str[start + i];
	return (temp);
}
