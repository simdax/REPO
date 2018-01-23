/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:53:06 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 18:22:30 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ret_f(int neg, int base, int i, char *res)
{
	char	*ret;

	if (neg && base == 10)
		res[--i] = '-';
	ret = ft_strdup(res + i);
	free(res);
	return (ret);
}

char		*ft_itoa_base(int value, int base)
{
	char	*res;
	long	r_val;
	int		i;
	int		neg;

	i = 65;
	neg = 0;
	res = malloc(i);
	r_val = value;
	res[i--] = 0;
	if (value < 0)
	{
		neg = 1;
		r_val *= -1;
	}
	while (r_val >= base)
	{
		res[i] = BASE[r_val % base];
		--i;
		r_val /= base;
	}
	res[i] = BASE[r_val % base];
	return (ret_f(neg, base, i, res));
}
