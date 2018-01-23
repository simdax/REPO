/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:12:40 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/17 17:14:10 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreduce(t_list *list, void (*f)(void *a, t_list *b, void *opts),
					void *val, void *opts)
{
	while (list)
	{
		f(val, list, opts);
		list = list->next;
	}
}
