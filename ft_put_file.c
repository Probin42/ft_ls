/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:16:40 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:07:58 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_get_color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr(RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(BROWN) : NULL;
	S_ISREG(mode) ? ft_putstr(NONE) : NULL;
	S_ISLNK(mode) ? ft_putstr(GREEN) : NULL;
	S_ISSOCK(mode) ? ft_putstr(GREEN) : NULL;
}

void			ft_basic_ls(t_flag flag, t_item *files)
{
	t_item		*cur;

	cur = files;
	while (cur)
	{
		if (!(flag.a == 0 && cur->name[0] == '.'))
		{
			ft_get_color(cur->st_mode);
			ft_putstr(cur->name);
			ft_putstr("  ");
			ft_putstr(NONE);
		}
		cur = cur->next;
	}
	ft_putstr("\n");
}

void			ft_notbasic_ls_file(t_flag flag, t_item *cur, t_len len)
{
	ft_print_rights(cur);
	ft_print_int(cur->st_nlink, len.linkspace);
	if (flag.g == 0)
	{
		if (getpwuid(cur->st_uid))
			ft_print_str(getpwuid(cur->st_uid)->pw_name, len.userspace);
		else
			ft_print_str(ft_itoa(cur->st_uid), len.userspace);
	}
	if (getgrgid(cur->st_gid))
		ft_print_str(getgrgid(cur->st_gid)->gr_name, len.groupspace);
	else
		ft_print_str(ft_itoa(cur->st_gid), len.groupspace);
	if (S_ISCHR(cur->st_mode) || S_ISBLK(cur->st_mode))
		ft_print_majmin(cur, len);
	else
		ft_print_int(cur->st_size, len.len);
	ft_date(cur->date);
	ft_get_color(cur->st_mode);
	ft_putstr(cur->name);
	ft_putstr(NONE);
	if (!S_ISLNK(cur->st_mode))
		ft_putchar('\n');
}

void			ft_notbasic_ls(t_flag flag, t_item *files, int fileordirectory)
{
	t_item		*cur;
	t_len		len;
	char		buf[257];

	cur = files;
	len = ft_get_size(flag, files);
	if (fileordirectory)
	{
		ft_putstr("total ");
		ft_putnbr(len.total);
		ft_putchar('\n');
	}
	while (cur)
	{
		if (!(flag.a == 0 && cur->name[0] == '.'))
			ft_notbasic_ls_file(flag, cur, len);
		ft_lnk(cur, flag, buf);
		cur = cur->next;
	}
}

void			ft_lnk(t_item *cur, t_flag flag, char *buf)
{
	int			x;

	if (S_ISLNK(cur->st_mode) && ((flag.l == 1) || (flag.g == 1)))
	{
		if ((x = readlink(cur->path, buf, sizeof(buf) - 1)) >= 0)
			buf[x] = '\0';
		ft_putstr(" -> ");
		ft_putendl(buf);
	}
}
