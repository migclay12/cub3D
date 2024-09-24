/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:21:53 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:21:57 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = (long int)n;
	if (nbr < 0)
	{
		pf_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		pf_putnbr_fd(nbr / 10, fd);
	pf_putchar_fd((nbr % 10) + '0', fd);
	if (n < 0)
		return (pf_nbrlen(nbr) + 1);
	else
		return (pf_nbrlen(nbr));
}
