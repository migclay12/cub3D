/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:29:05 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:20 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarrrep(char **arr, int index, char *str)
{
	int	size;

	size = ft_sarrsize(arr);
	if (size < index || index < 0)
		return (arr);
	free(arr[index]);
	arr[index] = ft_strdup(str);
	return (arr);
}
