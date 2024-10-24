/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:07 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:11 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*temp;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - 1;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, (char *)str, len + 1);
	return (temp);
}
