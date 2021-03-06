/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:29:47 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/29 09:39:26 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <string.h>
# include <grp.h>
# include <pwd.h>
# include <ncurses.h>
# include "libft.h"
# include "libft/list/includes.h"
# include "printf.h"

# define FLAGS_LS "lrRatG1"
# define NB_FLAGS 9

enum			e_flags
{
	LONG, REVERSE, RECURSIVE, ALL, TIME_SORT, COLOR, ONE, ALONE, ALL_INVISIBLE
};

typedef struct	s_node
{
	char		*name;
	char		*fullname;
	struct stat	sb;
	char		*size;
	char		*gp;
	char		*usr;
}				t_node;

typedef struct	s_infos
{
	int			max_sizes;
	int			max_inodes;
	int			max_len;
	int			max_usr;
	int			max_gw;
	int			block_size;
	char		**dirs;
	char		**all_files;
	int			*flags;
}				t_infos;

typedef struct	s_padding_args
{
	int max;
	int cols;
	int space;
}				t_padding_args;

char			*get_size(int mode, int size, int dev);
int				get_max_gw(t_list *a, int val, void *flags);
int				get_max_usr(t_list *a, int val, void *flags);
char			get_extended_attributes(char *path);
int				famlen(t_node **str);
void			free_fam(t_node **str);
t_node			**array_from_list(t_list *lst, int all_flag);
char			*print_color(char *name, int mode);
int				get_color(struct stat sb);
size_t			size_of_lst(t_list *lst);
int				print_padded(t_list *list, int *flags);
void			get_blkcnt(void *a, t_list *b, void *opts);
int				sort_f(t_list *el1, t_list *el2);
int				sort_t(t_list *el1, t_list *el2);
int				sort_r(t_list *el1, t_list *el2);
int				get_max_link(t_list *a, int val, void *f);
int				get_max_len(t_list *a, int val, void *f);
int				get_max_size(t_list *a, int val, void *f);
void			process(t_list *list, void *f);
char			*lsperms(int mode);
char			*ft_date(void *time);
int				is_dir(long st_mode);
void			clean(void *el, size_t len);
t_list			*mkl_argv(char **argv);
t_list			*mkl_dir(DIR *dir, char *file);
void			print_stat(t_node *node, t_infos *i);
t_node			return_node(char *parent, char *filename);
int				return_stat(char *file, struct stat *sb, int flag);
int				ft_ls(t_list *lst);
void			print(t_list *el, void *flags);
int				read_dir(char *file, void *flags);
void			print_dirent(struct dirent *infos);
char			*cat_filename(char *file1, char *file2);
t_list			*cpyrev(t_list *orig);
#endif
