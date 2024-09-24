/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrrmi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:29:30 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:38 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarrrmi(int index, char **arr)
{
	int		i;
	int		j;
	char	**new_arr;

	i = ft_sarrsize(arr);
	if (index > i || index < 0)
		return (arr);
	new_arr = malloc(sizeof(char *) * (i));
	i = -1;
	j = 0;
	while (arr[++i])
	{
		if (i != index)
			new_arr[j++] = ft_strdup(arr[i]);
	}
	new_arr[j] = NULL;
	ft_sarrfree(&arr);
	return (new_arr);
}
