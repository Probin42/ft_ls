/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:16:15 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:07:45 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_int(int link, int spacemax)
{
	int		x;

	x = spacemax - ft_strlen(ft_itoa(link));
	while (x-- > 0)
		ft_putchar(' ');
	ft_putnbr(link);
	ft_putstr("  ");
}

void		ft_print_str(char *str, int spacemax)
{
	int		x;

	x = spacemax - ft_strlen(str);
	ft_putstr(str);
	while (x-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void		ft_print_majmin(t_item *file, t_len len)
{
	int		min;
	int		maj;

	min = (int)ft_strlen(ft_itoa(minor(file->st_rdev)));
	maj = (int)ft_strlen(ft_itoa(major(file->st_rdev)));
	ft_putnbr(major(file->st_rdev));
	while (maj < len.maj--)
		ft_putchar(' ');
	ft_putstr(", ");
	ft_putnbr(minor(file->st_rdev));
	while (min < len.min--)
		ft_putchar(' ');
	ft_putchar(' ');
}
