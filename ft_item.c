/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:15:18 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:06:16 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_item			*ft_new_item(char *name, char *path, t_flag flag)
{
	t_item		*item;
	struct stat	stats;

	item = malloc(sizeof(t_item));
	item->name = ft_strdup(name);
	item->path = ft_strjoin(path, name);
	if (((flag.l == 1 || flag.g == 1) && lstat(item->path, &stats) == -1) ||
			(((flag.l == 0 && flag.g == 0) && stat(item->path, &stats) == -1)))
	{
		ft_basic_error("ft_ls: ", item->name, 1);
		return (NULL);
	}
	item->st_mode = stats.st_mode;
	item->st_nlink = stats.st_nlink;
	item->st_uid = stats.st_uid;
	item->st_gid = stats.st_gid;
	item->st_size = stats.st_size;
	item->st_rdev = stats.st_rdev;
	item->st_blocks = stats.st_blocks;
	item->date = (flag.u == 1 ? stats.st_atime : stats.st_mtime);
	item->next = NULL;
	return (item);
}

int				ft_get_item(t_item **files, struct dirent *file, char *path,
		t_flag flag)
{
	t_item		*list;

	list = *files;
	if (!file)
	{
		free(path);
		return (0);
	}
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_item(file->d_name, path, flag);
	}
	else
		*files = ft_new_item(file->d_name, path, flag);
	free(path);
	return (1);
}

void			ft_get_item_file(t_item **files, char *name, char *path,
		t_flag flag)
{
	t_item		*list;

	list = *files;
	if (!files)
		return ;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_item(name, path, flag);
	}
	else
		*files = ft_new_item(name, path, flag);
}
