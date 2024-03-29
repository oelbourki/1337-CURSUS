/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:45:56 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/06 23:45:57 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handelper(t_print *ele)
{
	int i;

	i = 0;
	if (ele->min < 0)
	{
		ele->min = abs(ele->min);
		ele->left = 1;
	}
	if (ele->left)
		ele->zero = 0;
	if (ele->min <= 1)
		i = (write(1, "%", 1));
	else if (!ele->zero)
	{
		if (ele->left)
			i = (write(1, "%", 1) + printspaces(ele->min - 1));
		else
			i = (printspaces(ele->min - 1) + write(1, "%", 1));
	}
	else if (ele->zero)
		i = (printzeros(ele->min - 1) + write(1, "%", 1));
	return (i);
}
