/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:27:11 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:27:19 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sarrcmp(char **arr, char *str)
{
	int	i;

	if (!str || !arr)
		return (-1);
	i = -1;
	while (arr[++i])
	{
		if (!ft_strncmp(arr[i], str, ft_strlen(str)))
			return (i);
	}
	return (-1);
}
