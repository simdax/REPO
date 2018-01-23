/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:07:15 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/17 17:10:14 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_INCLUDES_H
# define MERGE_INCLUDES_H

# include "../libft.h"

int		ft_cmp_rstr(t_list *one, t_list *two);
int		ft_lstgetmax(t_list *list, int val,
					int (*f)(t_list *el, int val, void *opt),
					void *opt);
t_list	*ft_lstsort(t_list *list, int (*cmp)(t_list*, t_list*));
int		ft_cmp_strlen(t_list *one, t_list *two);
int		ft_cmp_str(t_list *one, t_list *two);
int		ft_cmp_size(t_list *one, t_list *two);
void	ft_lstprint(t_list *el);

#endif
