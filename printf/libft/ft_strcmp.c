/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 strcmp.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/11/09 10:50:28 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/17 17:11:46 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include <string.h>

char	down_case(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int		ft_strcmpi(const char *s1, const char *s2)
{
	while (*s1 && down_case(*s1) == down_case(*s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)down_case(*s1) - (unsigned char)down_case(*s2));
}
