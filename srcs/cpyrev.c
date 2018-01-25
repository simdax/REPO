/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:46:25 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/25 13:11:29 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_list	*cpyrev(t_list *orig)
{
	t_list *ret;

	ret = 0;
	while (orig)
	{
		ft_lstadd(&ret, ft_lstnew(orig->content, orig->content_size));
		((t_node*)ret->content)->name = ft_strdup(((t_node*)orig->content)->name);
		((t_node*)ret->content)->fullname = ft_strdup(((t_node*)orig->content)->fullname);
		((t_node*)ret->content)->gp = ft_strdup(((t_node*)orig->content)->gp);
		((t_node*)ret->content)->usr = ft_strdup(((t_node*)orig->content)->usr);
		((t_node*)ret->content)->size = ft_strdup(((t_node*)orig->content)->size);
		orig = orig->next;
	}
	return (ret);
}
