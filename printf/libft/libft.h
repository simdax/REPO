/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:45:30 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 14:41:59 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "array/array.h"
# include "unicode/unicode.h"
# include "list/includes.h"
# include "gnl/get_next_line.h"
# include "list/includes.h"
# include "string/ft_string.h"

int				ft_abs(int value);
int				ft_notneg(int value);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s, const void *s2, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memdel(void **ap);

size_t			ft_nbrsize(int nbr);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_issep(char c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strrm(char const *s, char c, size_t n);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const*s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
 void		 	ft_putstr_utf8(int *str);
int				ft_putchar_utf8(int str);

unsigned int	ft_fact(unsigned int nb);
char			**ft_all_perms(char *s);
char			*ft_swapchar(char *s, int ind1, int ind2);
char			*ft_rotate(const char *s, int rotation);
void			ft_print_2d(char **matrix);
void			ft_print_len(int len, int *data);

int		ft_max(int one, int two);
int		ft_min(int one, int two);

#endif
