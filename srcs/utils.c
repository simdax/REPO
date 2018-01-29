/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:06:45 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/29 09:44:12 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_blkcnt(void *a, t_list *b, void *flags)
{
	t_node		*node;

	node = b->content;
	if (!((int*)flags)[ALL] && node->name[0] == '.')
		return ;
	*(blkcnt_t*)a += node->sb.st_blocks;
}

char		*cat_filename(char *file1, char *file2)
{
	char	*ret;
	size_t	size;
	size_t	size1;

	size1 = ft_strlen(file1);
	size = size1 + ft_strlen(file2) + 1;
	ret = (char*)malloc(size + 1);
	ft_strcpy(ret, file1);
	if (file1[size1 - 1] != '/')
		ft_strcat(ret, "/");
	ft_strcat(ret, file2);
	return (ret);
}

char		*basename(char *name)
{
	while (*name)
		++name;
	while (*name != '/')
		--name;
	return (ft_strdup(++name));
}

int			return_stat(char *file, struct stat *sb, int full)
{
	char	*name;
	
	if (lstat(file, sb) != 0)
	{
		name = (full && ft_strchr(file, '/')) ? basename(file) : ft_strdup(file);
		write(2, "ls: ", 4);
		perror(name);
		free(name);
		return (0);
	}
	return (1);
}

int			read_dir(char *file, void *flags)
{
	DIR			*dir;
	char		*name;

	if (!(dir = opendir(file)))
	{
		name = ft_strchr(file, '/') ? basename(file) : ft_strdup(file);
		write(2, "ls: ", 4);
		perror(name);
		free(name);
		return (0);
	}
	else
	{
		process(mkl_dir(dir, file), flags);
		closedir(dir);
		return (1);
	}
}
