/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:07:26 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/25 11:30:49 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_print_stat(char **pw, char **gd, char **smlink,
							t_node *node)
{
	struct passwd	*p;
	struct group	*g;

	*smlink = malloc(1000);
	if (S_ISLNK(node->sb.st_mode))
		readlink(node->fullname, *smlink, 1000);
	else
	{
		free(*smlink);
		*smlink = 0;
	}
	p = getpwuid(node->sb.st_uid);
	g = getgrgid(node->sb.st_gid);
	*pw = p ? p->pw_name : ft_itoa_base(node->sb.st_uid, 10);
	*gd = g ? g->gr_name : ft_itoa_base(node->sb.st_gid, 10);
}

char		*get_size(int mode, int size, int dev)
{
	static char	size_str[33];

	ft_bzero(size_str, 33);
	if (S_ISCHR(mode) || S_ISBLK(mode))
		return (ft_sprintf(size_str, "%ld, %ld",
						   (long) major(dev), (long) minor(dev)));
	else
		return (ft_sprintf(size_str, "%lld", (long long)size));
}

void		print_stat(t_node *node, t_infos *infos)
{
	char *pw;
	char *gd;
	char *smlink;

	init_print_stat(&pw, &gd, &smlink, node);
	ft_printf("\e[37m%s%c%*d %s  %s  %*s%s\e[%dm%s%s%s\e[37m\n",
			lsperms(node->sb.st_mode),
			get_extended_attributes(node->fullname),
			(int)ft_nbrsize(infos->max_inodes) + 1,
			(int)node->sb.st_nlink,
			pw, gd,
			(int)ft_nbrsize(infos->max_sizes),
			get_size(node->sb.st_mode, node->sb.st_size, node->sb.st_rdev),
			ft_date(&(node->sb.st_ctime)),
			infos->flags[COLOR] ? get_color(node->sb) : 37,
			node->name,
			S_ISLNK(node->sb.st_mode) ? " -> " : "",
			smlink ? smlink : "");
	free(smlink);
	if (!(getpwuid(node->sb.st_uid)))
		free(pw);
	if (!(getgrgid(node->sb.st_gid)))
		free(gd);
}
