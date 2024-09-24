/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:27:54 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:28:07 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarrcpy(char **arr)
{
	int		i;
	char	**new_arr;

	if (!arr)
		return (NULL);
	new_arr = malloc(sizeof(char *) * (ft_sarrsize(arr) + 1));
	i = -1;
	while (arr[++i])
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i] = NULL;
	return (new_arr);
}
