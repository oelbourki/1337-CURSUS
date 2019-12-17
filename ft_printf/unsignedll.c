/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:32:25 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/08 16:32:27 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		handel_withoutprec(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base10(ele->lu, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (ele->left)
	{
		i += write(1, s, l);
		if (ele->min > l)
			i += printspaces(ele->min - l);
	}
	else
	{
		if (ele->min > l && ele->zero == 0)
			i += printspaces(ele->min - l);
		if (ele->min > l && ele->zero == 1)
			i += printzeros(ele->min - l);
		i += write(1, s, l);
	}
	ft_free(s);
	return (i);
}

static int		handel_withprec_zeros(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base10(ele->lu, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (ele->min > l && ele->zero == 1)
		i += printzeros(ele->min - l);
	i += write(1, s, l);
	ft_free(s);
	return (i);
}

static int		handel_withprec(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base10(ele->lu, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (l >= MAX(ele->prec_val, ele->min))
		return (write(1, s, l) + ft_free(s));
	if (ele->prec_val >= ele->min)
		i += printzeros(ele->prec_val - l) + write(1, s, l);
	else
	{
		if (ele->left)
		{
			i += printzeros(ele->prec_val - l) + write(1, s, l);
			i += printspaces(ele->min - ele->prec_val);
		}
		else
		{
			i += printspaces(ele->min - ele->prec_val);
			i += printzeros(ele->prec_val - l) + write(1, s, l);
		}
	}
	return (i + ft_free(s));
}

int				handeull(t_print *ele)
{
	if (ele->min < 0)
	{
		ele->min = abs(ele->min);
		ele->left = 1;
	}
	if (ele->prec_val < 0)
	{
		ele->prec = 0;
		ele->prec_val = 0;
	}
	if (ele->lu == 0 && ele->prec_val == 0 && ele->precs)
	{
		printspaces(ele->min);
		return ((ele->min));
	}
	if (ele->zero == 1 && ele->prec_val == 0)
		return (handel_withprec_zeros(ele));
	if (ele->prec)
		return (handel_withprec(ele));
	else
		return (handel_withoutprec(ele));
}
