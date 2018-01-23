/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:26:35 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/21 12:26:38 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

int count;

float	ft_pow(float nb, float pow)
{
	float	res;
	int	integer;
	float floating_part;
	int	int_floating_part;
	float add;

	integer = (int)pow;
	floating_part = pow - integer;
	res = 1;
	add = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	if (integer >= 0)
		while (integer--)
			res *= nb;
	else
		return (1 / ft_pow(nb, -pow));
	if (floating_part > 0)
	{
		//      int_floating_part = (1.0 / floating_part);
		add = ft_root(nb, floating_part);
	}
	return (res * add);
}

float	ft_pow2(float nb, float pow)
{
	float	res;
	int	integer;
	float floating_part;
	int	int_floating_part;
	float add;

	integer = (int)pow;
	floating_part = pow - integer;
	res = 1 + floating_part;
	add = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	if (integer > 0)
		while (integer--)
			res *= nb;
	else
		return (1 / ft_pow(nb, -pow));
	/* if (floating_part > 0) */
	/*   { */
	/*     //      int_floating_part = (1.0 / floating_part); */
	/*     add = ft_root(nb, floating_part); */
	/*   } */
	/* count = 7; */
	return (res * add);
}
