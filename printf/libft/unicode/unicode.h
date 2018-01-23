/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:46:23 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 12:13:04 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNICODE_H
#define UNICODE_H

unsigned char	*unicode_to_utf8(int str);
char			*transform_utf8(int *str);
void			ft_putstr_utf8(int *str);
int				ft_putchar_utf8(int str);

#endif
