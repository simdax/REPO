/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 main.c												:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/01/21 15:12:11 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/22 18:56:37 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void 	code_to_utf8(unsigned char *const buffer, const unsigned int code)
{
	if (code <= 0x7F) {
		buffer[0] = code;
	}
	else if (code <= 0x7FF) {
		buffer[0] = 0xC0 | (code >> 6);
		buffer[1] = 0x80 | (code & 0x3F);
	}
	else if (code <= 0xFFFF) {
		buffer[0] = 0xE0 | (code >> 12);
		buffer[1] = 0x80 | ((code >> 6) & 0x3F);
		buffer[2] = 0x80 | (code & 0x3F);
	}
	else if (code <= 0x10FFFF) {
		buffer[0] = 0xF0 | (code >> 18);
		buffer[1] = 0x80 | ((code >> 12) & 0x3F);
		buffer[2] = 0x80 | ((code >> 6) & 0x3F);
		buffer[3] = 0x80 | (code & 0x3F);
	}
}

static void 	code_to_utf8(unsigned char *const buffer, const unsigned int code)
{
	if (code <= 0x7F) {
		buffer[0] = code;
	}
	else if (code <= 0x7FF) {
		buffer[0] = 0xC0 | (code >> 6);
		buffer[1] = 0x80 | (code & 0x3F);
	}
	else if (code <= 0xFFFF) {
		buffer[0] = 0xE0 | (code >> 12);
		buffer[1] = 0x80 | ((code >> 6) & 0x3F);
		buffer[2] = 0x80 | (code & 0x3F);
	}
	else if (code <= 0x10FFFF) {
		buffer[0] = 0xF0 | (code >> 18);
		buffer[1] = 0x80 | ((code >> 12) & 0x3F);
		buffer[2] = 0x80 | ((code >> 6) & 0x3F);
		buffer[3] = 0x80 | (code & 0x3F);
	}
}

int				ft_putchar_utf8(int str)
{
	unsigned char	*unicode;
	unsigned char	*cpy;

	unicode = malloc(5);
	ft_bzero(unicode, 5);
	cpy = unicode;
	code_to_utf8(unicode, str);
	while (*unicode)
	{
		write(1, unicode, 1);
		++unicode;
	}
	free(cpy);
	return (0);
}

void 			ft_putstr_utf8(int *str)
{
	while (*str)
		ft_putchar_utf8(*str++);
}
