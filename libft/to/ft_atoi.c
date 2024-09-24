/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:41:18 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:41:20 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sc(char c)
{
	int	b;

	b = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		b = 1;
	else if (c == '\r' || c == '\v' || c == '\f')
		b = 1;
	return (b);
}

int	ft_atoi(const char *str)
{
	unsigned long int	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (is_sc(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = - '0' + sum * 10 + *str;
		str++;
	}
	if (sum > 9223372036854775807 && sign == 1)
		return (-1);
	else if (sum > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * sum);
}
