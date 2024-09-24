/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:52 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:33:05 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *str, char *old, char *new)
{
	char	*found;
	char	*first;
	char	*last;

	if (!str || !old || !new || !ft_strstr(str, old))
		return (ft_strdup(str));
	found = ft_strstr(str, old);
	first = ft_substr(str, 0, found - str);
	last = ft_substr(str, found - str + ft_strlen(old),
			ft_strlen(found) - ft_strlen(old));
	return (ft_strjoinfree(first, ft_strjoinfree(new, last, 1), 2));
}
