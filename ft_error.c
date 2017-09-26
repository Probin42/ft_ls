/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:14:33 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:05:28 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_illegal_option(char flag)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(flag, 2);
	ft_putchar('\n');
	ft_putendl("usage: ls [lraRtufg] [file ...]");
	exit(1);
}

void	ft_basic_error(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(1);
}
