/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:15:57 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:07:32 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_rights(t_item *item)
{
	ft_putchar((S_ISFIFO(item->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(item->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(item->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(item->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(item->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(item->st_mode)) ? 'l' : '\0');
	ft_putchar((item->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((item->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar(ft_print_special_right_usr(item));
	ft_putchar((item->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((item->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar(ft_print_special_right_grp(item));
	ft_putchar((item->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((item->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((item->st_mode & S_IXOTH)
		? ft_print_special_right_t(item) : '-');
	ft_putstr("  ");
}

char		ft_print_special_right_usr(t_item *item)
{
	if ((item->st_mode & S_ISUID) || (item->st_mode & S_ISGID))
	{
		if (item->st_mode & S_IXUSR)
			return ('s');
		return ('S');
	}
	if (item->st_mode & S_IXUSR)
		return ('x');
	return ('-');
}

char		ft_print_special_right_grp(t_item *item)
{
	if ((item->st_mode & S_ISUID) || (item->st_mode & S_ISGID))
	{
		if (item->st_mode & S_IXGRP)
			return ('s');
		return ('S');
	}
	if (item->st_mode & S_IXGRP)
		return ('x');
	return ('-');
}

char		ft_print_special_right_t(t_item *item)
{
	if ((item->st_mode & S_IXOTH) && (item->st_mode & S_ISVTX))
		return ('t');
	if ((item->st_mode & S_ISVTX) && !(item->st_mode & S_IXOTH))
		return ('T');
	return ('x');
}
