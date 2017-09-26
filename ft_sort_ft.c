/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:17:36 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:08:49 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp_alpha(t_item *item1, t_item *item2)
{
	return (ft_strcmp(item1->name, item2->name));
}

int		ft_cmp_time(t_item *item1, t_item *item2)
{
	return (item1->date < item2->date);
}
