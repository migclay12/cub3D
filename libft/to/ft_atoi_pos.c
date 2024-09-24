/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:41:00 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:41:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_pos(char *str, int *pos)
{
	unsigned long int	sum;
	int					sign;

	sum = 0;
	sign = 1;
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[*pos] == '-')
			sign *= -1;
		*pos += 1;
	}
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		sum = - '0' + sum * 10 + str[*pos];
		*pos += 1;
	}
	return (sign * sum);
}
