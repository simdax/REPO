/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:26:29 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/29 09:39:50 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*mkl_dir(DIR *dir, char *file)
{
	struct dirent	*dir_inf;
	t_list			*list;
	t_node			node;

	list = 0;
	while ((dir_inf = readdir(dir)))
	{
		node.name = ft_strdup(dir_inf->d_name);
		node.fullname = cat_filename(file, node.name);
		if ((return_stat(node.fullname, &node.sb, 0)))
			ft_lstadd(&list, ft_lstnew(&node, sizeof(t_node)));
		else
		{
			free(node.name);
			free(node.fullname);
		}
	}
	return (list);
}

t_list		*mkl_argv(char **argv)
{
	t_node	node;
	t_list	*list;

	list = 0;
	while (*argv)
	{
		node.name = ft_strdup(*argv);
		node.fullname = ft_strdup(*argv);
		if ((return_stat(node.fullname, &node.sb, 0)))
			ft_lstadd(&list, ft_lstnew(&node, sizeof(t_node)));
		else
		{
			free(node.name);
			free(node.fullname);
		}
		++argv;
	}
	return (list);
}

void		clean(void *el, size_t len)
{
	t_node *e;

	(void)len;
	e = el;
	free(e->name);
	free(e->fullname);
	free(e->gp);
	free(e->usr);
	free(e->size);
	free(e);
}
