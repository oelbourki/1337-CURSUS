/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:34:54 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/08 16:34:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handelcl(t_print *ele)
{
	int i;

	i = 0;
	if (ele->min > 1)
	{
		if (ele->left)
		{
			i = write(1, &(ele->c1), sizeof(ele->c1)) +
			printspaces(ele->min - 1);
		}
		else
			i = printspaces(ele->min - 1) + write(1, &ele->c1, sizeof(ele->c1));
	}
	else
		i = write(1, &ele->c1, sizeof(ele->c1));
	return (i);
}
