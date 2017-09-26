/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:17:09 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:08:23 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_size_swiftly(t_len *len, t_item *cur)
{
	len->linkspace = (int)ft_strlen(ft_itoa(cur->st_nlink)) > len->linkspace ?
		(int)ft_strlen(ft_itoa(cur->st_nlink)) : len->linkspace;
	len->maj = (int)ft_strlen(ft_itoa(major(cur->st_rdev))) > len->maj ?
		(int)ft_strlen(ft_itoa(major(cur->st_rdev))) : len->maj;
	len->min = (int)ft_strlen(ft_itoa(minor(cur->st_rdev))) > len->min ?
		(int)ft_strlen(ft_itoa(minor(cur->st_rdev))) : len->min;
	len->len = (int)ft_strlen(ft_itoa(cur->st_size)) > len->len ?
		(int)ft_strlen(ft_itoa(cur->st_size)) : len->len;
	len->total += cur->st_blocks;
}

t_len		ft_get_size(t_flag flag, t_item *files)
{
	t_len	len;
	t_item	*cur;

	len = (t_len){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(flag.a == 0 && cur->name[0] == '.'))
			ft_get_size_swiftly(&len, cur);
		cur = cur->next;
	}
	return (len);
}
