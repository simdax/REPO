/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:24:49 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/25 12:35:04 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_f(t_list *el1, t_list *el2)
{
	t_node *one;
	t_node *two;

	one = el1->content;
	two = el2->content;
	return (ft_strcmp(one->name, two->name) < 0);
}

int		sort_t(t_list *el1, t_list *el2)
{
	t_node *one;
	t_node *two;

	one = el1->content;
	two = el2->content;
	if (one->sb.st_ctime == two->sb.st_ctime)
		return (ft_strcmp(one->name, two->name) < 0);
	return (one->sb.st_ctime > two->sb.st_ctime);
}

int		get_max_usr(t_list *a, int val, void *flags)
{
	t_node			*node;
	int				nb_usr;
	struct passwd	*p;
	
	node = a->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return (val);
	p = getpwuid(node->sb.st_uid);
	node->usr = p ? ft_strdup(p->pw_name) :
				ft_itoa_base(node->sb.st_uid, 10);
	nb_usr = ft_strlen(node->usr);
	return (nb_usr > val ? nb_usr : val);	
}

int		get_max_gw(t_list *a, int val, void *flags)
{
	t_node			*node;
	int				nb_gp;
	struct group	*g;
	
	node = a->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return (val);
	g = getgrgid(node->sb.st_gid);
	node->gp = g ? ft_strdup(g->gr_name) :
				ft_itoa_base(node->sb.st_gid, 10);
	nb_gp = ft_strlen(node->gp);
	return (nb_gp > val ? nb_gp : val);	
}

int		get_max_link(t_list *a, int val, void *flags)
{
	t_node	*node;
	int		nb_link;

	node = a->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return (val);
	nb_link = node->sb.st_nlink;
	return (nb_link > val ? nb_link : val);
}

int		get_max_len(t_list *a, int val, void *flags)
{
	t_node	*node;
	int		len;

	node = a->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return (val);
	len = ft_strlen(node->name);
	return (len > val ? len : val);
}

int		get_max_size(t_list *a, int val, void *flags)
{
	t_node	*node;
	int		size;

	node = a->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return (val);
	node->size = get_size(node->sb.st_mode, node->sb.st_size,
				node->sb.st_rdev);
	size = ft_strlen(node->size);
	return (size > val ? size : val);
}
