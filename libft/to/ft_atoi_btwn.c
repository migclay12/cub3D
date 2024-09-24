/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_btwn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:40:46 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:40:53 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_btwn(char *str, char ini, char end)
{
	char	*number;
	int		n;

	number = ft_strget_btwn(str, 0, ini, end);
	if (number)
		n = atoi(number);
	else
		n = 0;
	free (number);
	return (n);
}
