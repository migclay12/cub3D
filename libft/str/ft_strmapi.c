/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:31:51 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:31:54 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		index;

	if (!s || !f)
		return (NULL);
	sptr = malloc(ft_strlen(s) + 1);
	if (!sptr)
		return (NULL);
	index = -1;
	while (s[++index])
		sptr[index] = f(index, s[index]);
	sptr[index] = '\0';
	return (sptr);
}
