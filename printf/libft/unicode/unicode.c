/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:48:48 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 12:13:05 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		code_to_utf8(unsigned char *const buffer,
							const unsigned int code)
{
	if (code <= 0x7F)
	{
		buffer[0] = code;
		return (1);
	}
	else if (code <= 0x7FF)
	{
		buffer[0] = 0xC0 | (code >> 6);
		buffer[1] = 0x80 | (code & 0x3F);
		return (2);
	}
	else if (code <= 0xFFFF)
	{
		buffer[0] = 0xE0 | (code >> 12);
		buffer[1] = 0x80 | ((code >> 6) & 0x3F);
		buffer[2] = 0x80 | (code & 0x3F);
		return (3);
	}
	else if (code <= 0x10FFFF)
	{
		buffer[0] = 0xF0 | (code >> 18);
		buffer[1] = 0x80 | ((code >> 12) & 0x3F);
		buffer[2] = 0x80 | ((code >> 6) & 0x3F);
		buffer[3] = 0x80 | (code & 0x3F);
		return (4);
	}
	return (0);
}

unsigned char	*unicode_to_utf8(int str)
{
	unsigned char	*unicode;

	unicode = malloc(5);
	ft_bzero(unicode, 5);
	code_to_utf8(unicode, str);
	return (unicode);
}

int				ft_putchar_utf8(int str)
{
	unsigned char	*unicode;
	unsigned char	*cpy;

	unicode = unicode_to_utf8(str);
	cpy = unicode;
	while (*unicode)
	{
		write(1, unicode, 1);
		++unicode;
	}
	free(cpy);
	return (0);
}

void			ft_putstr_utf8(int *str)
{
	while (*str)
		ft_putchar_utf8(*str++);
}

char			*transform_utf8(int *str)
{
	int				nb_char;
	int				i;
	unsigned char	*unicode;
	char			*ret;
	char			*cpy;

	nb_char = 0;
	unicode = malloc(5);
	ft_bzero(unicode, 5);
	while (str[nb_char])
		++nb_char;
	if(!(ret = (char*)malloc(sizeof(int) * nb_char + 1 )))
		return (0);
	cpy = ret;
	while(*str)
	{
		i = 0;
		nb_char = code_to_utf8(unicode, *str++);
		while (i < nb_char)
			*ret++ = unicode[i++];
	}
	*ret = 0;
	free(unicode);
	return (cpy);
}
