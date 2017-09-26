/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:17:47 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:30:09 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			found_dash(char *str)
{
	if (str == NULL)
		return (0);
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

int			ft_test(char c, char *str)
{
	int		x;

	if (str == NULL || c == '\0')
		return (0);
	x = -1;
	while (str[++x])
		if (c == str[x])
			return (1);
	return (0);
}

void		ft_get_arg(t_flag *flag, char *str)
{
	int		x;

	x = 0;
	if (str == NULL)
		return ;
	while (str[++x])
	{
		if (ft_test(str[x], "latrRugf") || (str[1] == '-' && !str[2]))
		{
			flag->l = (str[x] == 'l' ? 1 : flag->l);
			flag->a = (str[x] == 'a' ? 1 : flag->a);
			flag->r = (str[x] == 'r' ? 1 : flag->r);
			flag->t = (str[x] == 't' ? 1 : flag->t);
			flag->upper_r = (str[x] == 'R' ? 1 : flag->upper_r);
			flag->u = (str[x] == 'u' ? 1 : flag->u);
			flag->f = (str[x] == 'f' ? 1 : flag->f);
			flag->l = (str[x] == 'f' ? 0 : flag->l);
			flag->a = (str[x] == 'f' ? 1 : flag->a);
			flag->g = (str[x] == 'g' ? 1 : flag->g);
		}
		else
			ft_illegal_option(str[x]);
	}
}

void		ft_get_params(int nombre, char **params, t_flag *flag,
		t_lst **path)
{
	int		x;
	int		y;

	x = -1;
	y = 1;
	while (++x < nombre)
	{
		if (found_dash(params[x + 1]) == 0)
			y = 0;
		if (y == 1)
		{
			ft_get_arg(flag, params[x + 1]);
			if (ft_strncmp(params[x + 1], "--", 2) == 0)
				x++;
		}
		else if (y == 0)
			ft_lstpushback(path, params[x + 1], ft_strlen(params[x + 1]) + 1);
	}
}

int			main(int ac, char **av)
{
	t_flag	flag;
	t_lst	*path;

	flag = (t_flag){0, 0, 0, 0, 0, 0, 0, 0};
	path = NULL;
	if (ac > 1)
		ft_get_params(ac - 1, av, &flag, &path);
	if (path == NULL)
		path = ft_lsttnew(".", ft_strlen(".") + 1);
	ft_earth_prog(flag, path, path->next != NULL ? 1 : 0);
	return (0);
}
