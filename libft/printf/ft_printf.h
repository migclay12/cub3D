/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:21:13 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/15 16:21:16 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		pf_putnbr_base(unsigned long long nbr, char *base, int type);
int		pf_nbrlen(long int n);
int		pf_putnbr_fd(int n, int fd);
int		pf_putunsigned(unsigned long long nbr);
size_t	pf_putptr(unsigned long long ptr);
int		pf_putchar_fd(char c, int fd);
int		pf_putstr_fd(char const *s, int fd);
size_t	pf_strlen(const char *str);

#endif
