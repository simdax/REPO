/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_ca.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:40:11 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 14:28:39 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_CA_H
# define PROTOTYPES_CA_H

# include "libft.h"

void	parse_flags(char *str, t_num *a);
int		split_type(char *type, t_num *a);
int		parse_value(void *value, t_num *a);
void	print_alternate(t_num *type, t_array *array);
void	print_arg(t_num *num, t_array *array);
void	print_padding(size_t count, char with, t_array *array);
void	print_sign(int sign, char type, int space, t_array *array);
void	print_value(void *val, char type,
					size_t precision, t_array *array);
void	re_orga(t_num *a);
void	ret_val(t_num *a, void *val);

#endif
