/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:17:21 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:08:39 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_item			*ft_sort_item(t_item *list, t_flag flag)
{
	t_item		*new;

	if (!list)
		return (NULL);
	new = list;
	if (flag.f == 0)
	{
		ft_sort(&new, ft_cmp_alpha);
		(flag.t == 1 || flag.u == 1) ? ft_sort(&new, ft_cmp_time) : NULL;
		flag.r == 1 ? ft_reverse(&new) : NULL;
	}
	return (new);
}

void			ft_copy_item(t_item **src, t_item *cpy)
{
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->date = cpy->date;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_uid = cpy->st_uid;
	(*src)->st_gid = cpy->st_gid;
	(*src)->st_size = cpy->st_size;
	(*src)->st_blocks = cpy->st_blocks;
}

void			ft_swap_item(t_item **x, t_item **y)
{
	t_item		tmp;

	tmp = **x;
	ft_copy_item(x, *y);
	ft_copy_item(y, &tmp);
}

void			ft_sort(t_item **list, int (*cmp)(t_item *item1, t_item *item2))
{
	t_item		*x;
	t_item		*y;

	x = *list;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (cmp(x, y) > 0)
				ft_swap_item(&x, &y);
			y = y->next;
		}
		x = x->next;
	}
}

void			ft_reverse(t_item **list)
{
	t_item		*p;
	t_item		*q;
	t_item		*r;

	p = *list;
	q = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
}
