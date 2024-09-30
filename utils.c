/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:36:59 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/26 14:49:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_free_map(char **matrix, int i)
{
	printf("FT_FREE_MAP\n");
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	exit (0);
}

char	*ft_str(const char *s, int c)
{
	unsigned char	l;

	l = (unsigned char)c;
	while (*s != l)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
// I dont think all of them are being used
char *remove_spaces(char *str)
{
	int start;
	int i;

	i = 0;
	start = 0;
	if ((int)ft_strlen(str) - 2 == 0)
	{
		//printf("RETURN\n");
		return (NULL);
	}
	while (i <= (int)ft_strlen(str) - 2)
	{
		if (str[i] == '1')
			start = i + 1;
		i++;
	}
	i = start;
	while (i <= (int)ft_strlen(str) - 2)
	{
		//printf("STR: %c\n", str[i]);
		if (str[i] != ' ' && str[i + 1] != '\n')
		{
			//printf("RETURN0\n");
			return (str);
		}
		i++;
	}
	if (start == 0 && str[start] != '\n')
	{
		//printf("RETURN1\n");
		return (NULL);
	}
	else if (str[start] == '\n' && start != 0)
	{
		//printf("RETURN2\n");
		return (str);
	}
	else
	{
		//printf("RETURN3\n");
		//str[start] = '\n';
		str[start + 1] = '\0';
	}
	return (str);
}
