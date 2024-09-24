/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:16 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:37:19 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	b;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		b = 0;
		while (str[i + b] && to_find[b] == str[i + b])
		{
			if (to_find[b + 1] == '\0')
				return (&str[i]);
			b++;
		}
		i++;
	}
	return (0);
}
