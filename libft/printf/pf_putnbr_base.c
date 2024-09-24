/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:21:46 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:21:49 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	pf_putnbr_base(unsigned long long nbr, char *base, int type)
{
	int					i;
	size_t				b;
	char				c[500];
	int					s;
	unsigned long long	n;

	if (type == 1)
		n = (unsigned int)nbr;
	else
		n = (unsigned long long)nbr;
	b = pf_strlen(base);
	s = 1;
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n && b)
	{
		c[i] = base[n % b];
		n /= b;
		i++;
	}
	s = i;
	while (--i >= 0 && b > 1)
		write(1, &c[i], 1);
	return (s);
}
