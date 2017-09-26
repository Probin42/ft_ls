/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freefct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:14:47 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:05:44 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_files(t_item **files)
{
	t_item	*list;
	t_item	*tmp;

	list = *files;
	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list->path);
		free(list);
		list = tmp;
	}
	*files = NULL;
}
