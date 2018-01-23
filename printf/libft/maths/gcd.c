/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:25:27 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/21 12:25:27 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_maths.h"

int gcd(int a, int b)
{
	int max = ft_max(a, b);
	int min = ft_min(a, b);
	int tmp = 1;
  
	while ((tmp = max % min))
	{
		max = min;
		min = tmp;
	}
	return (min);
}
