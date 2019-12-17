/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:53:10 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/06 23:53:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		handel_withoutprec(int min, int left, char *arg)
{
	int			i;
	int			l;

	l = ft_strlen(arg);
	i = 0;
	if (left)
	{
		i += write(1, "0x", 2);
		i += write(1, arg, l);
		if (min > l + 2)
			i += printspaces(min - l - 2);
	}
	else
	{
		if (min > l + 2)
			i += printspaces(min - l - 2);
		i += write(1, "0x", 2);
		i += write(1, arg, l);
	}
	ft_free(arg);
	return (i);
}

int				handep(t_print *tmp, char *arg)
{
	int i;

	i = 0;
	if (tmp->min < 0)
	{
		tmp->min = abs(tmp->min);
		tmp->left = 1;
	}
	if (tmp->u == 0 && tmp->prec_val == 0 && tmp->precs)
	{
		i += printspaces(tmp->min - 2);
		i += write(1, "0x", 2);
		ft_free(arg);
		return ((i));
	}
	return (handel_withoutprec(tmp->min, tmp->left, arg));
}
