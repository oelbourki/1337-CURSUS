/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_extra3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:52:54 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:52:56 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_strlen1(char *line, t_cube *h)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		c = line[i];
		if (c != ' ')
			j++;
		if (ft_strlen2(line, h, i, j) == -1)
			return (-1);
		if (c == '2')
		{
			if (h->flag2 == 1)
				error(166, h);
			h->flag2 = 1;
			h->sy = j - 1 + 0.5;
			h->sx = h->ly + 1 + 0.5;
		}
		i++;
	}
	return (j);
}

int		checkline(char *line, char c, t_cube *h, int j)
{
	char *p;
	char *p1;

	if ((p = ft_strrchr(line, c)))
	{
		if (g_check[j] != 0)
			error(84, h);
		if (!(h->holder[j] = ft_strdup(line)))
			error(10, h);
		p1 = ft_strchr(line, c);
		if (p != p1)
			error(86, h);
		else
			g_check[j]++;
		return (1);
	}
	return (0);
}

int		checkline1(char *line, char *s, t_cube *h, int j)
{
	char *p;
	char *p1;

	if ((p = ft_strnstr(line, s, h->l)))
	{
		if (g_check[j] != 0)
			error(84, h);
		if (!(h->holder[j] = ft_strdup(line)))
			error(10, h);
		p1 = ft_strnstr(p + 2, s, h->l);
		if (p1)
			error(86, h);
		else
			g_check[j]++;
		return (1);
	}
	return (0);
}

int		get_info_help(t_cube *h, char *line)
{
	h->l = ft_strlen(line);
	check_info(h);
	if (checkline(line, 'R', h, 0) || checkline(line, 'F', h, 6)
	|| checkline(line, 'C', h, 7))
		return (0);
	else if (checkline1(line, "NO", h, 1) || checkline1(line, "SO", h, 2))
		return (0);
	else if (checkline1(line, "WE", h, 3) || checkline1(line, "EA", h, 4))
		return (0);
	else if (ft_strnstr(line, ".xpm", h->l) && checkline(line, 'S', h, 5))
		return (0);
	else if (ft_strrchr(line, '1'))
		return (1);
	else if (line[0] == '\0')
		return (0);
	else
		error(95, h);
	return (1);
}

void	fill_line(t_cube *h, char *line, int *i)
{
	int j;

	if (!ft_strchr(line, '1'))
		error(207, h);
	h->lx = ft_strlen1(line, h);
	if (h->lx == -1)
		error(125, h);
	if (h->lx > 1)
	{
		j = 0;
		h->k = 0;
		if (!(h->map1[*i] = malloc(h->lx + 1)))
			error(11, h);
		while (line[j] != '\0')
		{
			if (line[j] != ' ')
			{
				h->map1[*i][h->k] = line[j];
				(h->k)++;
			}
			h->map1[*i][h->k] = '\0';
			j++;
		}
		h->ly = (*i)++;
	}
}
