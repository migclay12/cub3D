/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:51:35 by ablanco-          #+#    #+#             */
/*   Updated: 2024/05/16 20:58:11 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		set_bit(int *n, int bit, int val);
int		mlx_bit(int n, int bit);
int		not_bit(int *n, int bit);
void	print_bits(int n);
int		mlx_mask_and(int mask, int with);
int		mlx_mask_not(int mask, int with);
int		mlx_mask_or(int mask, int with);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
size_t	ft_strlen(const char *str);
char	*ft_strrep(char *str, char *srch, char *rep);
void	ft_strfreel(char **str);
char	**ft_strbrk(char *str, int b_point);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
int		ft_chr_count(char *str, char c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strrep(char *str, char *old, char *new);
char	*ft_strget_btwn(char *str, int start, char ini, char end);
int		ft_chrpos(char *str, int chr, int start);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char *s1, char *s2, int which);
char	**ft_split(const char *str, char delimiter);
char	*ft_unsplit(char **sarr, char *sep);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstiter_context(t_list *lst,
			void (*f)(void *node, void *context), void *context);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_atoi(const char *str);
int		ft_atoi_pos(char *str, int *pos);
int		ft_atoi_btwn(char *str, char ini, char end);
double	ft_atod(char *str);
char	**ft_sarrcpy(char **arr);
int		ft_sarrsize(char **arr);
char	**ft_sarradd(char **arr, char *string);
void	ft_sarrfree(char ***arr);
char	**ft_sarrrmi(int index, char **arr);
int		ft_sarrprint(char **arr);
int		ft_sarrcmp(char **arr, char *str);
char	**ft_sarrrep(char **arr, int index, char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif
