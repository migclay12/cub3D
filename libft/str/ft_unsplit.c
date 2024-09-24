/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:38:06 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:38:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsplit(char **sarr, char *sep)
{
	int		i;
	char	*unsplit;

	if (!sarr)
		return (NULL);
	unsplit = ft_strdup(sarr[0]);
	i = 0;
	while (sarr[++i])
	{
		if (!sep)
			unsplit = ft_strjoin(unsplit, sarr[i]);
		else
			unsplit = ft_strjoin(unsplit, ft_strjoin(sep, sarr[i]));
	}
	return (unsplit);
}
