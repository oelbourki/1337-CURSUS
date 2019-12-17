/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:32:44 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/08 16:32:46 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		whath(t_print *ele, va_list ap)
{
	t_print		*tmp;
	char		c;

	tmp = ele;
	c = tmp->type;
	if (c == 'x' || c == 'X')
	{
		tmp->i = va_arg(ap, long int);
		return (handex(ele));
	}
	else if (tmp->type == 'd' || tmp->type == 'i')
	{
		tmp->i = va_arg(ap, int);
		return (handen(ele));
	}
	else
	{
		tmp->i = va_arg(ap, unsigned long int);
		return (handeu(ele));
	}
}
