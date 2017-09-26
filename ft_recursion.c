/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:16:57 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:08:12 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_recursion2(t_flag flag, char *path)
{
	DIR		*dir;
	t_item	*file;

	file = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (ft_get_item(&file, readdir(dir), ft_strjoin(path, "/"), flag)
				!= 0)
			;
		closedir(dir);
		if (file)
			ft_displayfile(flag, file, 1);
		file = NULL;
	}
	else
		ft_basic_error("ft_ls: ", path, 0);
}

void		ft_recursion(t_flag flag, t_item *file)
{
	t_item *cur;

	cur = file;
	while (cur)
	{
		if (cur->name && cur->path && S_ISDIR(cur->st_mode) &&
				ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name) &&
				!(flag.a == 0 && cur->name[0] == '.'))
			ft_recursion2(flag, cur->path);
		cur = cur->next;
	}
}
