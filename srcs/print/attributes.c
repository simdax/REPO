/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 attributes.c										:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/01/24 10:35:24 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/25 11:29:53 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "ft_ls.h"

char		get_extended_attributes(char *path)
{
	acl_t		acl;
	int			nbr;
	char		c;
	static char	buffer[64];

	c = ' ';
	nbr = listxattr(path, buffer, 64, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		c = '+';
		acl_free(acl);
	}
	return (nbr > 0 ? '@' : c);
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
