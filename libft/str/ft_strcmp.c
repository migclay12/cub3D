/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:02 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:04 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*count1;
	unsigned char	*count2;
	size_t			i;

	count1 = (unsigned char *)s1;
	count2 = (unsigned char *)s2;
	i = 0;
	while (count1[i] != '\0' || count2[i] != '\0')
	{
		if (count1[i] != count2[i])
			return (count1[i] - count2[i]);
		i++;
	}
	return (0);
}
