/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:15:44 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:07:15 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_lsttnew(void const *content, size_t content_len)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_len = 0;
	}
	else
	{
		new->content = malloc(content_len);
		ft_memcpy(new->content, content, content_len);
		new->content_len = content_len;
	}
	new->next = NULL;
	return (new);
}

void		ft_lstpushback(t_lst **lst, const void *content, size_t content_len)
{
	t_lst	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lsttnew(content, content_len);
	}
	else
		*lst = ft_lsttnew(content, content_len);
}
