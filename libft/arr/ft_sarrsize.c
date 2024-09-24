/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:29:50 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:56 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sarrsize(char **arr)
{
	int	size;

	if (!arr)
		return (0);
	size = 0;
	while (arr[size])
		size++;
	return (size);
}
