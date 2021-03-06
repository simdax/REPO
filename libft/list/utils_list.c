/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:04:59 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/17 17:05:01 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes.h"

void	ft_lstprint(t_list *el)
{
	write(1, el->content, ft_strlen(el->content));
	write(1, " ", 1);
}
