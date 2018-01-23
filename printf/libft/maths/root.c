/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:27:05 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/21 12:27:09 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

float	ft_root(float nb, float exp)
{
	double	i = 1;
	double	res = 0;
	int		precision = 7;

	if (!exp) //undefined
		return (0);
	while (precision)
	{
		if (ft_pow(res, exp) > nb)
		{
			res -= i;
			i /= 10;
			--precision;
		}
		res += i;
	}
	return (res);  
}

float	ft_sqrt(float nb)
{
	double	i = 1;
	double	res = 0;
	int		precision = 7;

	while (precision)
	{
		if (res * res > nb)
		{
			res -= i;
			i /= 10;
			--precision;
		}
		res += i;
	}
	return (res);  
}


float ft_div(float a, float b)
{
	float tmp = 0;
	float res = 0;
	float i = 1;
	int remainders[(int)b];

	ft_bzero(remainders, (int)b);
	while (tmp <= a)
	{
		if (tmp == a)
			break ;
		if (tmp + b > a)
		{
			remainders[(int)tmp] = 1;
			b /= 10;
			i /= 10;
		}
		tmp += b;
		res += i;
	}
	return (res);
}
