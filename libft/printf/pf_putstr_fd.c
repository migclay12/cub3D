/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:22:01 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:22:04 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = -1;
	if (s)
		while (s[++i])
			write(fd, &s[i], 1);
	return (i);
}
