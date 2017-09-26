/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_earth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:14:13 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:05:11 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_displayfile(t_flag flag, t_item *files, int fileordir)
{
	t_item	*cur;

	cur = files;
	cur = ft_sort_item(cur, flag);
	(flag.l == 1) || (flag.g == 1) ? ft_notbasic_ls(flag, cur, fileordir)
		: ft_basic_ls(flag, cur);
	flag.upper_r == 1 ? ft_recursion(flag, cur) : NULL;
}

void		ft_ls_dir2(t_flag flag, t_item *list, int multidir, char *tmp)
{
	DIR		*dir;
	t_item	*files;
	int		start;

	start = 0;
	files = NULL;
	while (list)
	{
		dir = opendir(list->name);
		while (ft_get_item(&files, readdir(dir),
					ft_strjoin(list->path, "/"), flag) != 0)
			;
		closedir(dir);
		if (files)
		{
			start == 1 ? ft_putchar('\n') : NULL;
			tmp = ft_strjoin(list->name, ":");
			multidir ? ft_putendl(tmp) : NULL;
			ft_strdel(&tmp);
			start = 1;
			ft_displayfile(flag, files, 1);
		}
		free_files(&files);
		list = list->next;
	}
}

void		ft_ls_dir(t_flag flag, t_lst *path, int multidir)
{
	t_lst	*cur;
	t_item	*list;

	cur = path;
	list = NULL;
	while (cur)
	{
		ft_get_item_file(&list, cur->content, "", flag);
		cur = cur->next;
	}
	list = ft_sort_item(list, flag);
	ft_ls_dir2(flag, list, multidir, "");
}

void		ft_ls_file(t_flag flag, t_lst *path)
{
	t_lst	*cur;
	t_item	*item;

	cur = path;
	item = NULL;
	flag.a = 1;
	while (cur)
	{
		ft_get_item_file(&item, cur->content, "", flag);
		cur = cur->next;
	}
	if (item)
		ft_displayfile(flag, item, 0);
}

void		ft_earth_prog(t_flag flag, t_lst *path, int mdir)
{
	DIR		*dir;
	t_lst	*cur;
	t_lst	*directo;
	t_lst	*file;

	cur = path;
	directo = NULL;
	file = NULL;
	while (cur)
	{
		if ((dir = opendir(cur->content)) == NULL)
			errno != ENOTDIR ? ft_basic_error("ft_ls: ", cur->content, 0) :
				ft_lstpushback(&file, cur->content, cur->content_len);
		else
		{
			ft_lstpushback(&directo, cur->content, cur->content_len);
			if ((closedir(dir)) == -1)
				ft_basic_error("ft_ls: ", cur->content, 0);
		}
		cur = cur->next;
	}
	file ? ft_ls_file(flag, file) : NULL;
	file && directo ? ft_putchar('\n') : NULL;
	directo ? ft_ls_dir(flag, directo, mdir) : NULL;
}
