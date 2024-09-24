/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strget_btwn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:35 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:37 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Get the string between the chars given, if chars not found returns NULL.
*/
char	*ft_strget_btwn(char *str, int start, char ini, char end)
{
	char	*group;
	int		left;
	int		right;

	if (!str)
		return (NULL);
	group = NULL;
	left = ft_chrpos(str, ini, start);
	right = ft_chrpos(str, end, left + 1);
	if (left != -1 && right > left)
		group = ft_substr(str, left + 1, right - left - 1);
	return (group);
}
