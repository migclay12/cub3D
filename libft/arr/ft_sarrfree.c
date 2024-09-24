/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:28:21 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:28:28 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sarrfree(char ***arr)
{
	int	i;

	if (!arr || !arr[0])
		return ;
	i = -1;
	while (arr[0][++i])
	{
		if (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = NULL;
		}
	}
	free (*arr);
	*arr = NULL;
}
