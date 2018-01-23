/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:07:26 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/19 17:47:28 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_print_stat(char **pw,	char **gd, char **smlink,
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
	*pw = p ? p->pw_name : ft_itoa(node->sb.st_uid);
	*gd = g ? g->gr_name : ft_itoa(node->sb.st_gid);
}

void		print_stat(t_node *node, t_infos *infos)
{
	char *pw;
	char *gd;
	char *smlink;

	init_print_stat(&pw, &gd, &smlink, node);
	ft_printf("\e[37m%s%c%*d %s  %s  %*lld%s\e[%dm%s%s%s\e[37m\n",
			lsperms(node->sb.st_mode),
			' ',
			(int)ft_nbrsize(infos->max_inodes) + 1,
			(int)node->sb.st_nlink,
			pw, gd,
			(int)ft_nbrsize(infos->max_sizes),
			(long long)node->sb.st_size,
			ft_date(&(node->sb.st_ctime)),
			infos->flags[COLOR] ? get_color(node->sb) : 37,
			node->name,
			S_ISLNK(node->sb.st_mode) ? " -> " : "",
			smlink ? smlink : "");
	free(smlink);
	free(pw);
	free(gd);
}

int			filetypeletter(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

char		*lsperms(int mode)
{
	static const	char *rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	static			char bits[11];

	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return (bits);
}

char		*ft_date(void *time)
{
	static char	ret[14];

	ft_strncpy(ret, ctime(time) + 3, 13);
	ret[13] = ' ';
	return (ret);
}
