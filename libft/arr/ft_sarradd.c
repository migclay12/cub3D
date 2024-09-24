/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:32 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:30:50 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarradd(char **arr, char *string)
{
	int		size;
	char	**new_arr;

	if (!string)
		return (arr);
	size = ft_sarrsize(arr) + 2;
	new_arr = malloc(sizeof(char *) * (size));
	size = 0;
	if (arr)
	{
		while (arr[size])
		{
			new_arr[size] = ft_strdup(arr[size]);
			size++;
		}
		ft_sarrfree(&arr);
	}
	new_arr[size++] = ft_strdup(string);
	new_arr[size] = NULL;
	return (new_arr);
}
