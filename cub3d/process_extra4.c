/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_extra4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:34:04 by oel-bour          #+#    #+#             */
/*   Updated: 2019/12/04 12:34:06 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*give(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (s + i);
		i++;
	}
	return (NULL);
}

int			isin(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_strlen2(char *line, t_cube *h, int i, int j)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
	{
		h->flag1 = 1;
		if (h->flag == 0)
			return (-1);
		h->flag = 0;
		h->pos = line[i];
		line[i] = '0';
		h->py = j - 1 + 0.5;
		h->px = h->ly + 1 + 0.5;
	}
	return (1);
}

int			checklinex(char *s, char *set)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!isin(s[i], set))
			return (0);
		if (j == 2 && ((s[i] != ' ' && !(s[i] <= '9' && s[i] >= '0'))
		|| (s[i - 1] == ' ' && (s[i] <= '9' && s[i] >= '0'))))
			return (0);
		if (s[i] == ',')
			j++;
		i++;
	}
	if (j == 0 || j == 1 || j > 2)
		return (0);
	return (1);
}

void		check_info(t_cube *h)
{
	int i;

	i = 1;
	while (i < 8)
	{
		if (h->holder[i - 1] == NULL && h->holder[i] != NULL)
			error(203, h);
		i++;
	}
}
